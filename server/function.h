// CodeChange.h: interface for the CCodeChange class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FUNCTION_H__)
#define AFX_FUNCTION_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

	CVector * explode(CVector &v, const char * msg, const char split);
	char * implode(char * msg, int len, CVector &v, const char split);

#endif // !defined(AFX_FUNCTION_H__)