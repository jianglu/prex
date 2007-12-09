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
 * putc.c - putc
 */
#include <config.h>

#ifdef CONFIG_DIAG_BOCHS
static void outb(unsigned char value, int port)
{
	__asm__ __volatile__("outb %b0, %w1" :: "a"(value), "Nd"(port));

}

static unsigned char inb(int port)
{
	unsigned char value;

	__asm__ __volatile__("inb %w1, %b0" : "=a"(value): "Nd"(port));
	return value;
}
#endif /* CONFIG_DIAG_BOCHS */

/*
 * Put one charactor to bochs console
 */
void putc(int c)
{
#ifdef CONFIG_DIAG_BOCHS
	/* Running on Bochs? */
	if (inb(0xe9) != 0xe9)	
		return;

	if (c == 0x0a)
		outb((int)0x0d, 0xe9);
	outb(c, 0xe9);
#endif /* CONFIG_DIAG_BOCHS */
}
