// Force.h: interface for the CForce class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FORCE_H__7E70E361_BD39_11D4_98AC_0050BABC5212__INCLUDED_)
#define AFX_FORCE_H__7E70E361_BD39_11D4_98AC_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../server/Skill.h"

#define FORCE_BEGIN(item_name)	class item_name : public CForce	{	public:	item_name(){};	virtual ~item_name(){};
#define FORCE_END		};	

class CForce : public CSkill  
{
public:
	static int do_recover(CChar * me, CContainer * target);
	
	virtual void create();
	virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage_bonus);

	CForce();
	virtual ~CForce();

};

#endif // !defined(AFX_FORCE_H__7E70E361_BD39_11D4_98AC_0050BABC5212__INCLUDED_)
