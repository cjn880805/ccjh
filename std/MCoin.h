// MCoin.h: interface for the CMCoin class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MCOIN_H__15904040_9F8C_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_MCOIN_H__15904040_9F8C_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Money.h"

class CMCoin : public CMoney  
{
public:
	virtual void create(int flag = 0);
	CMCoin();
	virtual ~CMCoin();

};

#endif // !defined(AFX_MCOIN_H__15904040_9F8C_11D4_98AB_0050BABC5212__INCLUDED_)
