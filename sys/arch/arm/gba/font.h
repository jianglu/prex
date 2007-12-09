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
 * font.h - minimum font for GBA
 */

const unsigned char font_bitmap[][8] = {
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x18, 0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x00,},
	{0x6C, 0x6C, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x6C, 0x6C, 0xFE, 0x6C, 0xFE, 0x6C, 0x6C, 0x00,},
	{0x10, 0x7C, 0xD0, 0x7C, 0x16, 0x7C, 0x10, 0x00,},
	{0x62, 0x66, 0x0C, 0x18, 0x30, 0x66, 0x46, 0x00,},
	{0x38, 0x6C, 0x68, 0x76, 0xDC, 0xCC, 0x76, 0x00,},
	{0x18, 0x18, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x0C, 0x18, 0x30, 0x30, 0x30, 0x18, 0x0C, 0x00,},
	{0x30, 0x18, 0x0C, 0x0C, 0x0C, 0x18, 0x30, 0x00,},
	{0x00, 0x6C, 0x38, 0xFE, 0x38, 0x6C, 0x00, 0x00,},
	{0x00, 0x18, 0x18, 0x7E, 0x18, 0x18, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x10,},
	{0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00,},
	{0x02, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x40, 0x00,},
	{0x3C, 0x66, 0x6E, 0x76, 0x66, 0x66, 0x3C, 0x00,},
	{0x18, 0x18, 0x38, 0x18, 0x18, 0x18, 0x3C, 0x00,},
	{0x7C, 0x06, 0x06, 0x3C, 0x60, 0x60, 0x7E, 0x00,},
	{0x7C, 0x06, 0x06, 0x1C, 0x06, 0x06, 0x7C, 0x00,},
	{0x66, 0x66, 0x66, 0x7E, 0x06, 0x06, 0x06, 0x00,},
	{0x7E, 0x60, 0x60, 0x7C, 0x06, 0x06, 0x7C, 0x00,},
	{0x3E, 0x60, 0x60, 0x7C, 0x66, 0x66, 0x3C, 0x00,},
	{0x7E, 0x06, 0x0C, 0x18, 0x18, 0x18, 0x18, 0x00,},
	{0x3C, 0x66, 0x66, 0x3C, 0x66, 0x66, 0x3C, 0x00,},
	{0x3C, 0x66, 0x66, 0x3E, 0x06, 0x06, 0x7C, 0x00,},
	{0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x00, 0x00,},
	{0x00, 0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x10,},
	{0x0C, 0x18, 0x30, 0x60, 0x30, 0x18, 0x0C, 0x00,},
	{0x00, 0x00, 0x7E, 0x00, 0x7E, 0x00, 0x00, 0x00,},
	{0x30, 0x18, 0x0C, 0x06, 0x0C, 0x18, 0x30, 0x00,},
	{0x3C, 0x66, 0x06, 0x1C, 0x18, 0x00, 0x18, 0x00,},
	{0x3C, 0x66, 0x6E, 0x6E, 0x6E, 0x60, 0x3E, 0x00,},
	{0x3C, 0x66, 0x66, 0x7E, 0x66, 0x66, 0x66, 0x00,},
	{0x7C, 0x66, 0x66, 0x7C, 0x66, 0x66, 0x7C, 0x00,},
	{0x3C, 0x66, 0x60, 0x60, 0x60, 0x66, 0x3C, 0x00,},
	{0x7C, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7C, 0x00,},
	{0x7E, 0x60, 0x60, 0x78, 0x60, 0x60, 0x7E, 0x00,},
	{0x7E, 0x60, 0x60, 0x78, 0x60, 0x60, 0x60, 0x00,},
	{0x3C, 0x66, 0x60, 0x6E, 0x66, 0x66, 0x3C, 0x00,},
	{0x66, 0x66, 0x66, 0x7E, 0x66, 0x66, 0x66, 0x00,},
	{0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7E, 0x00,},
	{0x0E, 0x06, 0x06, 0x06, 0x06, 0x66, 0x3C, 0x00,},
	{0x66, 0x6C, 0x78, 0x70, 0x78, 0x6C, 0x66, 0x00,},
	{0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7E, 0x00,},
	{0xC6, 0xEE, 0xFE, 0xD6, 0xC6, 0xC6, 0xC6, 0x00,},
	{0x66, 0x76, 0x7E, 0x6E, 0x66, 0x66, 0x66, 0x00,},
	{0x3C, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x00,},
	{0x7C, 0x66, 0x66, 0x7C, 0x60, 0x60, 0x60, 0x00,},
	{0x3C, 0x66, 0x66, 0x66, 0x6E, 0x6E, 0x3E, 0x00,},
	{0x7C, 0x66, 0x66, 0x7C, 0x66, 0x66, 0x66, 0x00,},
	{0x3E, 0x60, 0x60, 0x3C, 0x06, 0x06, 0x7C, 0x00,},
	{0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00,},
	{0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x00,},
	{0x66, 0x66, 0x66, 0x66, 0x3C, 0x3C, 0x18, 0x00,},
	{0xC6, 0xC6, 0xC6, 0xD6, 0xFE, 0xEE, 0xC6, 0x00,},
	{0x66, 0x66, 0x3C, 0x18, 0x3C, 0x66, 0x66, 0x00,},
	{0x66, 0x66, 0x66, 0x3C, 0x18, 0x18, 0x18, 0x00,},
	{0x7E, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x7E, 0x00,},
	{0x3C, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3C, 0x00,},
	{0x40, 0x60, 0x30, 0x18, 0x0C, 0x06, 0x02, 0x00,},
	{0x3C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x3C, 0x00,},
	{0x10, 0x38, 0x6C, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,},
	{0x18, 0x18, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0x00, 0x00, 0x3C, 0x06, 0x3E, 0x66, 0x3E, 0x00,},
	{0x60, 0x60, 0x7C, 0x66, 0x66, 0x66, 0x7C, 0x00,},
	{0x00, 0x00, 0x3C, 0x66, 0x60, 0x66, 0x3C, 0x00,},
	{0x06, 0x06, 0x3E, 0x66, 0x66, 0x66, 0x3E, 0x00,},
	{0x00, 0x00, 0x3C, 0x66, 0x7C, 0x60, 0x3E, 0x00,},
	{0x0E, 0x18, 0x18, 0x3C, 0x18, 0x18, 0x3C, 0x00,},
	{0x00, 0x00, 0x3E, 0x66, 0x66, 0x3E, 0x06, 0x7C,},
	{0x60, 0x60, 0x7C, 0x66, 0x66, 0x66, 0x66, 0x00,},
	{0x18, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00,},
	{0x18, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x70,},
	{0x60, 0x60, 0x66, 0x6C, 0x78, 0x6C, 0x66, 0x00,},
	{0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x1C, 0x00,},
	{0x00, 0x00, 0xCC, 0xFE, 0xD6, 0xC6, 0xC6, 0x00,},
	{0x00, 0x00, 0x7C, 0x66, 0x66, 0x66, 0x66, 0x00,},
	{0x00, 0x00, 0x3C, 0x66, 0x66, 0x66, 0x3C, 0x00,},
	{0x00, 0x00, 0x7C, 0x66, 0x66, 0x7C, 0x60, 0x60,},
	{0x00, 0x00, 0x3E, 0x66, 0x66, 0x3E, 0x06, 0x06,},
	{0x00, 0x00, 0x36, 0x38, 0x30, 0x30, 0x30, 0x00,},
	{0x00, 0x00, 0x3E, 0x60, 0x3C, 0x06, 0x7C, 0x00,},
	{0x18, 0x18, 0x18, 0x3C, 0x18, 0x18, 0x0C, 0x00,},
	{0x00, 0x00, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x00,},
	{0x00, 0x00, 0x66, 0x66, 0x3C, 0x3C, 0x18, 0x00,},
	{0x00, 0x00, 0xC6, 0xC6, 0xD6, 0xFE, 0xEC, 0x00,},
	{0x00, 0x00, 0x66, 0x3C, 0x18, 0x3C, 0x66, 0x00,},
	{0x00, 0x00, 0x66, 0x66, 0x66, 0x3E, 0x06, 0x7C,},
	{0x00, 0x00, 0x7E, 0x0C, 0x18, 0x30, 0x7E, 0x00,},
	{0x1C, 0x30, 0x30, 0x60, 0x30, 0x30, 0x1C, 0x00,},
	{0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00,},
	{0x38, 0x0C, 0x0C, 0x06, 0x0C, 0x0C, 0x38, 0x00,},
	{0x32, 0x4C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,},
};
