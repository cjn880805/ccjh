// MSilver.h: interface for the CMSilver class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MSILVER_H__15904041_9F8C_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_MSILVER_H__15904041_9F8C_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Money.h"

class CMSilver : public CMoney  
{
public:
	virtual void create(int flag = 0);
	CMSilver();
	virtual ~CMSilver();

};

#endif // !defined(AFX_MSILVER_H__15904041_9F8C_11D4_98AB_0050BABC5212__INCLUDED_)
