/* tinyproxy - A fast light-weight HTTP proxy
 * Copyright (C) 2005 Robert James Kaes <rjkaes@users.sourceforge.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/* See 'reverse-proxy.c' for detailed information. */

#ifndef TINYPROXY_REVERSE_PROXY_H
#define TINYPROXY_REVERSE_PROXY_H

#include "conns.h"

typedef struct reverse_s {
        struct reverse_s *next;
        char *path;
        char *host;
        char *url;
} reverse_t;

#define REVERSE_COOKIE "yummy_magical_cookie"

extern void reversepath_add (const char *path, const char *url,
                             struct reverse_s **reverse_list);
extern void reversehost_add (const char *path, const char *url,
                             struct reverse_s **reverse_list);
extern struct reverse_s *reversepath_get (char *url,
                                            struct reverse_s *reverse);
extern struct reverse_s *reversehost_get (char *host,
                                            struct reverse_s *reverse);
void free_reverse_list (struct reverse_s *reverse);
extern char *reverse_rewrite_url (struct conn_s *connptr,
                                  hashmap_t hashofheaders, char *url);

#endif
