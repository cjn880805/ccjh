#ifndef	__genconifg_h
#define	__genconifg_h

#include	"config.h"		//configuration options for current OS

#include	<sys/types.h>	// basic system data types 
#include	<sys/socket.h>	// basic socket definitions 
#include	<sys/time.h>	// timeval{} for select() 
#include	<time.h>		// timespec{} for pselect() 
#include	<netinet/in.h>	// sockaddr_in{} and other Internet defns 
#include	<arpa/inet.h>	// inet(3) functions 
#include	<errno.h>
#include	<fcntl.h>		// for nonblocking 
#include	<netdb.h>
#include	<signal.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/stat.h>	// for S_xxx file mode constants 
#include	<sys/uio.h>		// for iovec{} and readv/writev 
#include	<unistd.h>
#include	<sys/wait.h>
#include	<sys/un.h>		// for Unix domain sockets 


#define	SA	struct sockaddr

// Following could be derived from SOMAXCONN in <sys/socket.h>, but many
// kernels still #define it as 5, while actually supporting many more */
#define	LISTENQ		5	// 2nd argument to listen()

// Miscellaneous constants 
#define	MAXLINE		4096	// max text line length 
#define	MAXSOCKADDR  128	// max socket address structure size 
#define	BUFFSIZE	8192	// buffer size for reads and writes 
#define ERRORMSG	128		// buffer size for error msg

#define	min(a,b)	((a) < (b) ? (a) : (b))
#define	max(a,b)	((a) > (b) ? (a) : (b))

// error.c
void	 err_dump(const char *, ...);
void	 err_msg(const char *, ...);
void	 err_quit(const char *, ...);
void	 err_ret(const char *, ...);
void	 err_sys(const char *, ...);

#endif//__genconifg_h
