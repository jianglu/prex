/*-
 * Copyright (c) 2005-2007, Kohsuke Ohtani
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

#ifndef _TIMER_H
#define _TIMER_H

#include <list.h>
#include <event.h>
#include <hook.h>

struct thread;

/*
 * Callout timer
 */
struct timer {
	struct list	link;		/* Linkage on timer chain */
	int		active;		/* True if active */
	u_long		expire;		/* Expire time (ticks) */
	u_long		interval;	/* Time interval */
	void		(*func)(void *); /* Function to call */
	void		*arg;		/* Function argument */
	struct event	event;		/* Event for this timer */
};
typedef struct timer *timer_t;

/*
 * Macro to compare two timer counts.
 * time_after() returns true if a is after b.
 */
#define time_after(a,b)		(((long)(b) - (long)(a)) < 0)
#define time_before(a,b)	time_after(b,a)

#define time_after_eq(a,b)	(((long)(a) - (long)(b)) >= 0)
#define time_before_eq(a,b)	time_after_eq(b,a)

/*
 * Macro to convert milliseconds and tick.
 */
#define msec_to_tick(ms) (((ms) >= 0x20000) ? \
	    ((ms) / 1000UL) * HZ : \
	    ((ms) * HZ) / 1000UL)

#define tick_to_msec(tick) (((tick) * 1000) / HZ)

extern void timer_init(void);
extern void timer_tick(void);
extern void timer_stop(timer_t tmr);
extern void timer_timeout(timer_t tmr, void (*func)(void *),
			  void *arg, u_long msec);
extern u_long timer_delay(u_long msec);
extern void timer_cleanup(struct thread *th);
extern void timer_hook(hook_t hook, void (*func)(void *));
extern void timer_unhook(hook_t hook);
extern u_long timer_count(void);

extern int timer_sleep(u_long delay, u_long *remain);
extern int timer_alarm(u_long delay, u_long *remain);
extern int timer_periodic(struct thread *th, u_long start, u_long period);
extern int timer_waitperiod(void);

#endif /* !_TIMER_H */