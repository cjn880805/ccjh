// Corpse.h: interface for the CCorpse class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CORPSE_H__091ECDA0_79A7_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_CORPSE_H__091ECDA0_79A7_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../server/Char.h"

class CCorpse : public CChar  
{
public:
	static CCorpse * MakeCorpse(CChar * victim, CChar * killer);
	virtual void heart_beat();
	virtual LONG Query(int nAttr);
	CCorpse();
	virtual ~CCorpse();

protected:
	void Decay();

	int		m_nDecayed;
	int		m_nDelay;
};

#endif // !defined(AFX_CORPSE_H__091ECDA0_79A7_11D4_98AB_0050BABC5212__INCLUDED_)
