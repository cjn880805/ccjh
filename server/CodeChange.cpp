// CodeChange.cpp: implementation of the CCodeChange class.
//
//////////////////////////////////////////////////////////////////////
#include <cstring> 
#include "stdafx.h"
#include "CodeChange.h"
#include "Globle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// Big5 code to Gb code
static unsigned char gb[34100];

//GB code to Big5 code
static unsigned char big5[17000];

int init_code()
{
	FILE* pf;
	char szTmp[64];
	int len;
	
	strncpy(szTmp,"data/big2gb.o", 64);
	pf = fopen(szTmp, "rb");
	if(pf == NULL)
	{
		//AfxMessageBox("不能找到big5到GB码的文件表。[Big2Gb.Dat]");
		return 0;
	}
	fseek(pf, 0, SEEK_END);
	len = ftell(pf);
	rewind(pf);
	fread(gb, len, 1, pf);
	fclose(pf);

	strncpy(szTmp,"data/gb2big.o", 64);
	pf = fopen(szTmp, "rb");
	if(pf == NULL)
	{
		//AfxMessageBox("不能找到Gb到big5码的文件表。[Gb2Big.Dat]");
		return 0;
	}

	fseek(pf, 0, SEEK_END);
	len = ftell(pf);
	rewind(pf);
	fread(big5, len, 1, pf);
	fclose(pf);
	return 1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char * gb2big(char * szMessage)
{
	unsigned char * buf = (unsigned char*)szMessage;
	while(*buf)
	{
		if(*buf > 160)
		{
			int pos = ((*buf - 161)*94 + buf[1]-161)<<1;
			*buf = big5[pos];
			buf[1] = big5[pos+1];
			buf++;
		}
		buf++;
	}

	return szMessage;	
}

char * big2gb(char* szMessage)
{
	unsigned char * buf = (unsigned char*)szMessage;
	while(*buf)
	{
		if(*buf > 160)
		{
			int pos = ((*buf - 161)*191 + buf[1] - 64)<<1;
			*buf = gb[pos];
			buf[1] = gb[pos+1];
			buf++;
		}
		buf++;
	}

	return szMessage;
}
