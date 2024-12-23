// BankOwner.h: interface for the CBankOwner class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BANKOWNER_H__0B9652A0_9398_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_BANKOWNER_H__0B9652A0_9398_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//ÒøÐÐ³öÄÉ

#include "../server/Npc.h"

#define BANKOWNER_BEGIN(npc_name) class npc_name : public CBankOwner {	public:	npc_name(){};	virtual ~npc_name(){};	
#define BANKOWNER_END		};	

class CBankOwner : public CNpc  
{
public:
	virtual LONG Query(int nAttr);
	virtual int handle_action(char * comm, CChar * me, char * arg);
	int Do_Loan(CChar * me, LONG amount);
	int Do_Withdraw(CChar * me, LONG amount);
	int Do_Deposit(CChar * me, LONG nAmount);
	CBankOwner();
	virtual ~CBankOwner();

protected:
	int Do_Balance(CChar * me);
};

#endif // !defined(AFX_BANKOWNER_H__0B9652A0_9398_11D4_98AB_0050BABC5212__INCLUDED_)
