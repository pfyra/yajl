/*
 * Copyright (c) 2007-2014, Lloyd Hilaiel <me@lloyd.io>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef __YAJL_BUF_H__
#define __YAJL_BUF_H__

#include "yajl/yajl_common.h"
#include "yajl_alloc.h"

/*
 * Implementation/performance notes.  If this were moved to a header
 * only implementation using #define's where possible we might be
 * able to sqeeze a little performance out of the guy by killing function
 * call overhead.  YMMV.
 */

/*+
 * yajl_buf is a buffer with exponential growth.  the buffer ensures that
 * you are always null padded.
 +*/
typedef struct yajl_buf_t * yajl_buf;

yajl_buf yajl_buf_alloc(yajl_alloc_funcs * alloc);
void yajl_buf_free(yajl_buf buf);
void yajl_buf_append(yajl_buf buf, const void * data, size_t len);
void yajl_buf_clear(yajl_buf buf);
const unsigned char * yajl_buf_data(yajl_buf buf);
size_t yajl_buf_len(yajl_buf buf);
void yajl_buf_truncate(yajl_buf buf, size_t len);

#endif
