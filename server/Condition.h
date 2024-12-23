// Condition.h: interface for the CCondition class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONDITION_H__28D41561_A5AD_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_CONDITION_H__28D41561_A5AD_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Char.h"

#define CONDITION_BEGIN(cnd_name)	class cnd_name : public CCondition	{	public:	cnd_name(){};	virtual ~cnd_name(){};
#define CONDITION_END	};

//持续作用之效果
class CCondition : public CMudObject  
{
public:
	virtual void init(CChar * me);
	virtual int update_condition(CChar * me, LONG & duration);
	CCondition();
	virtual ~CCondition();

};

#endif // !defined(AFX_CONDITION_H__28D41561_A5AD_11D4_98AB_0050BABC5212__INCLUDED_)
