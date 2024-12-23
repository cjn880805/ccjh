#ifndef	__datastruct_h
#define	__datastruct_h

#define NUM_CLIENT  FD_SETSIZE

typedef struct tagClientInfo
{
	bool	bLogin;
	int		sockfd;
	long	lObjectID;
 	int		nBufferPtr;
 	char	szBuf[4096];

	char	*sendmsg;
	char	szIPaddress[16];
	tagClientInfo()
	{
		sockfd = -1;
		bLogin = false;
	};
}TClientInfo;

#endif
