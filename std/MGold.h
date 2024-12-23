// MGold.h: interface for the CMGold class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MGOLD_H__15904042_9F8C_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_MGOLD_H__15904042_9F8C_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Money.h"

class CMGold : public CMoney  
{
public:
	virtual void create(int flag = 0);
	CMGold();
	virtual ~CMGold();

};

#endif // !defined(AFX_MGOLD_H__15904042_9F8C_11D4_98AB_0050BABC5212__INCLUDED_)
