/*****************************************************************************
Copyright (c) 2014, Brave New Software
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

* Redistributions of source code must retain the above
  copyright notice, this list of conditions and the
  following disclaimer.

* Redistributions in binary form must reproduce the
  above copyright notice, this list of conditions
  and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of the University of Illinois
  nor the names of its contributors may be used to
  endorse or promote products derived from this
  software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/

// udt_wrap.h defines wrappers around the udt c++ functions that are callable
// from C

#ifndef __UDT_WRAP_H__
#define __UDT_WRAP_H__

#include "udt_base.h"

// We have to redefine htons for use in Go for some reason
extern "C" uint16_t _htons(uint16_t hostshort);

extern "C" int udt_startup();
extern "C" int udt_cleanup();
extern "C" UDTSOCKET udt_socket(int af, int type, int protocol);
extern "C" int udt_bind(UDTSOCKET u, const struct sockaddr* name, int namelen);
extern "C" int udt_bind2(UDTSOCKET u, UDPSOCKET udpsock);
extern "C" int udt_listen(UDTSOCKET u, int backlog);
extern "C" UDTSOCKET udt_accept(UDTSOCKET u, struct sockaddr* addr, int* addrlen);
extern "C" int udt_connect(UDTSOCKET u, const struct sockaddr* name, int namelen);
extern "C" int udt_close(UDTSOCKET u);
extern "C" int udt_getpeername(UDTSOCKET u, struct sockaddr* name, int* namelen);
extern "C" int udt_getsockname(UDTSOCKET u, struct sockaddr* name, int* namelen);
extern "C" int udt_getsockopt(UDTSOCKET u, int level, SOCKOPT optname, void* optval, int* optlen);
extern "C" int udt_setsockopt(UDTSOCKET u, int level, SOCKOPT optname, const void* optval, int optlen);
extern "C" int udt_send(UDTSOCKET u, const char* buf, int len, int flags);
extern "C" int udt_recv(UDTSOCKET u, char* buf, int len, int flags);
extern "C" int udt_sendmsg(UDTSOCKET u, const char* buf, int len, int ttl, int inorder);
extern "C" int udt_recvmsg(UDTSOCKET u, char* buf, int len);
extern "C" int64_t udt_sendfile2(UDTSOCKET u, const char* path, int64_t* offset, int64_t size, int block);
extern "C" int64_t udt_recvfile2(UDTSOCKET u, const char* path, int64_t* offset, int64_t size, int block);

extern "C" int udt_epoll_create();
extern "C" int udt_epoll_add_usock(int eid, UDTSOCKET u, const int* events);
extern "C" int udt_epoll_add_ssock(int eid, SYSSOCKET s, const int* events);
extern "C" int udt_epoll_remove_usock(int eid, UDTSOCKET u);
extern "C" int udt_epoll_remove_ssock(int eid, SYSSOCKET s);
extern "C" int udt_epoll_wait2(int eid, UDTSOCKET* readfds, int* rnum, UDTSOCKET* writefds, int* wnum, int64_t msTimeOut,
                        SYSSOCKET* lrfds, int* lrnum, SYSSOCKET* lwfds, int* lwnum);
extern "C" int udt_epoll_release(int eid);
extern "C" int udt_getlasterror_code();
extern "C" const char* udt_getlasterror_desc();
extern "C" int udt_perfmon(UDTSOCKET u, TRACEINFO* perf, int clear);
extern "C" enum UDTSTATUS udt_getsockstate(UDTSOCKET u);

#endif