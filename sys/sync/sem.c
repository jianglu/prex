/*-
 * Copyright (c) 2005, Kohsuke Ohtani
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the author nor the names of any co-contributors 
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * sem.c - semaphore support
 */

/*
 * All of the the Prex semaphore is un-named semaphore. Instead, the
 * named semaphore is implemented by a file system server.
 * In order to access the other task's semaphore, the task must
 * have CAP_SEMAPHORE capability.
 */

#include <kernel.h>
#include <queue.h>
#include <event.h>
#include <sched.h>
#include <kmem.h>
#include <thread.h>
#include <sync.h>

/*
 * Initialize semaphore.
 *
 * sem_init() creates a new semaphore if the specified semaphore does
 * not exist yet. If the semaphore already exists, it is re-initialized
 * only if nobody is waiting for it. The initial semaphore value is set
 * to the requested value.
 *
 * @sem: ID for new semaphore.
 * @value: Initial value.
 */
__syscall int sem_init(sem_t *sem, u_int value)
{
	struct semaphore *s, *sem_org;
	int err;

	err = 0;
	if (value > SEM_MAX)
		return EINVAL;

	sched_lock();

	if (umem_copyin(sem, &sem_org, sizeof(sem_t)) != 0) {
		err = EFAULT;
		goto out;
	}
	/*
	 * An application can call sem_init() to reset the
	 * value of existing semaphore. So, we have to check
	 * the semaphore is already allocated.
	 */
	if (sem_valid(sem_org)) {
		/* 
		 * Semaphore already exists.
		 */
		if (sem_org->task != cur_task() &&
		    !capable(CAP_SEMAPHORE)) {
			err = EPERM;
			goto out;
		}
		if (event_waiting(&sem_org->event)) {
			err = EBUSY;
			goto out;
		}
		s->value = value;
	} else {
		/*
		 * Create new semaphore.
		 */
		if ((s = kmem_alloc(sizeof(struct semaphore))) == NULL) {
			err = ENOSPC;
			goto out;
		}
		event_init(&s->event, "semaphore");
		s->task = cur_task();
		s->value = value;
		s->magic = SEM_MAGIC;
		if (umem_copyout(&s, sem, sizeof(sem_t)) != 0) {
			kmem_free(s);
			err = EFAULT;
			goto out;
		}
	}
 out:
	sched_unlock();
	return err;
}

/*
 * Destroy semaphore.
 * If some thread is waiting for the specified semaphore, this routine
 * fails with EBUSY.
 */
__syscall int sem_destroy(sem_t *sem)
{
	sem_t s;

	sched_lock();
	if (umem_copyin(sem, &s, sizeof(sem_t)) != 0) {
		sched_unlock();
		return EFAULT;
	}
	if (!sem_valid(s)) {
		sched_unlock();
		return EINVAL;
	}
	if (s->task != cur_task() && !capable(CAP_SEMAPHORE)) {
		sched_unlock();
		return EPERM;
	}
	if (event_waiting(&s->event)) {
		sched_unlock();
		return EBUSY;
	}
	s->magic = 0;
	kmem_free(s);

	sched_unlock();
	return 0;
}

/*
 * Lock a semaphore.
 *
 * @sem: Semaphore ID
 * @timeout: The time out value in msec. Zero for no timeout.
 *
 * sem_wait() locks the semaphore referred by sem only if the semaphore
 * value is currently positive. The thread will sleep while the semaphore
 * value is zero. It decrements the semaphore value in return.
 *
 * If waiting thread receives any exception, this routine returns
 * with EINTR in order to invoke exception handler. But, an application
 * assumes this call does NOT return with error. So, system call stub
 * routine must re-call automatically if it gets EINTR.
 */
__syscall int sem_wait(sem_t *sem, u_long timeout)
{
	sem_t s;
	int err;

	sched_lock();
	if (umem_copyin(sem, &s, sizeof(sem_t)) != 0) {
		sched_unlock();
		return EFAULT;
	}
	if (!sem_valid(s)) {
		sched_unlock();
		return EINVAL;
	}
	if (s->task != cur_task() && !capable(CAP_SEMAPHORE)) {
		sched_unlock();
		return EPERM;
	}
	while (s->value <= 0) {
		err = sched_tsleep(&s->event, timeout);
		if (err == SLP_TIMEOUT) {
			sched_unlock();
			return ETIMEDOUT;
		}
		if (err == SLP_INTR) {
			sched_unlock();
			return EINTR;
		}
		sched_unlock();
		sched_lock();
	}
	s->value--;
	sched_unlock();
	return 0;
}

/*
 * Try to lock a semaphore.
 * If the semaphore is already locked, it just returns EAGAIN.
 */
__syscall int sem_trywait(sem_t *sem)
{
	sem_t s;

	sched_lock();
	if (umem_copyin(sem, &s, sizeof(sem_t)) != 0) {
		sched_unlock();
		return EFAULT;
	}
	if (!sem_valid(s)) {
		sched_unlock();
		return EINVAL;
	}
	if (s->task != cur_task() && !capable(CAP_SEMAPHORE)) {
		sched_unlock();
		return EPERM;
	}
	if (s->value <= 0) {
		sched_unlock();
		return EAGAIN;
	}
	s->value--;
	sched_unlock();
	return 0;
}

/*
 * Unlock a semaphore.
 *
 * If the semaphore value becomes non zero, then one of the threads blocked
 * waiting for the semaphore will be unblocked.
 * This is non-blocking operation.
 */
__syscall int sem_post(sem_t *sem)
{
	sem_t s;

	sched_lock();
	if (umem_copyin(sem, &s, sizeof(sem_t)) != 0) {
		sched_unlock();
		return EFAULT;
	}
	if (!sem_valid(s)) {
		sched_unlock();
		return EINVAL;
	}
	if (s->task != cur_task() && !capable(CAP_SEMAPHORE)) {
		sched_unlock();
		return EPERM;
	}
	if (s->value >= SEM_MAX) {
		sched_unlock();
		return ERANGE;
	}
	s->value++;
	if (s->value == 1)
		sched_wakeone(&s->event);
	sched_unlock();
	return 0;
}

/*
 * Get semaphore value.
 */
__syscall int sem_getvalue(sem_t *sem, u_int *value)
{
	sem_t s;
	int err;

	err = 0;
	sched_lock();
	if (umem_copyin(sem, &s, sizeof(sem_t)) != 0) {
		sched_unlock();
		return EFAULT;
	}
	if (!sem_valid(s)) {
		sched_unlock();
		return EINVAL;
	}
	if (s->task != cur_task() && !capable(CAP_SEMAPHORE)) {
		sched_unlock();
		return EPERM;
	}
	if (umem_copyout(&s->value, value, sizeof(int)) != 0)
		err = EFAULT;
	sched_unlock();
	return err;
}
