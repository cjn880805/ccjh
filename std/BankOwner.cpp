// BankOwner.cpp: implementation of the CBankOwner class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BankOwner.h"
#include "../std/Money.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBankOwner::CBankOwner()
{

}

CBankOwner::~CBankOwner()
{

}

//存钱 deposit 
int CBankOwner::Do_Deposit(CChar * me, LONG amount)
{
	char msg[255];
		
	if( amount <= 0) return 0;

	if(! CMoney::Player_Pay(me, amount))
		return notify_fail("你身上没有那麽多钱。");
            
	me->add("balance", amount);
	me->Save();
	message_vision(snprintf(msg, 255, "$N存入现款%s。", CMoney::Money_Str(amount)), me);
	
	output_error("%s(%s)存入现款%ld，存款达到%ld。", me->name(1), me->id(1), amount, me->query("balance"));

	return 1;
}

//提款
int CBankOwner::Do_Withdraw(CChar * me, LONG amount)
{
	char msg[255];
	LONG hamount;

    hamount = me->query("balance");
	
	if(amount <=0 ) return 0;
	if(amount > hamount) 
		return notify_fail("你没这么多存款 ！！");		
	
	me->add("balance", - amount);
	me->Save();

	CMoney::Pay_Player(me, amount);
	tell_object(me, "提款完毕。");

	output_error(snprintf(msg, 255, "%s(%s)提款%ld，余额%ld。From (%s)", me->name(1), me->id(1), amount, me->query("balance"), GetIP(me)) );

	return 1;
}

//贷款
int CBankOwner::Do_Loan(CChar *me, LONG amount)
{
	LONG hamount;
	char msg[255];
        
	hamount = me->query("balance");
	if(hamount > 0 ) 
		return notify_fail("你还有存款！");
		
	if(userp(me))
		return notify_fail("贷款业务暂停！");
		
	if(me->query("level")>150)
		return notify_fail("这么有名的人物还来借钱？肯定是假冒的，不借！");
		        
	if(amount <=0 ) return 0;
	if(CChar::Level2Exp(me->query("level")) < amount - hamount)
		return notify_fail("你借不到这么多钱．．．");
		       
	hamount -= amount;
    me->set("balance", hamount);
	me->Save();

	CMoney::Pay_Player(me, amount);
    tell_object(me, "贷款完毕。");
	
	output_error(snprintf(msg, 255, "%s(%s)贷款%ld，余额%ld。From (%s)", me->name(1), me->id(1), amount, me->query("balance"), GetIP(me)) );

    return 1;
}

int CBankOwner::handle_action(char *comm, CChar *me, char * arg)
{
	if(is_fighting()) return 0;

	me = FindMaster(me);
	if(strcmp(comm, "deposit") == 0) return Do_Deposit(me, atol(arg));
	if(strcmp(comm, "withdraw") == 0) return Do_Withdraw(me, atol(arg));
	if(strcmp(comm, "loan") == 0) return Do_Loan(me, atol(arg));
	if(strcmp(comm, "balance") == 0) return Do_Balance(me);

	return 0;
}

LONG CBankOwner::Query(int nAttr)
{
	if(nAttr == IS_BANKER)
		return 1;

	return CNpc::Query(nAttr);
}

int CBankOwner::Do_Balance(CChar *me)
{
	char msg[255];
	LONG value = me->query("balance");
    
	if(value == 0)
	{
        MessageVision(me, "tell", "你现在没有存款。");
		return 1;
	}

	if(value > 0) 
		snprintf(msg, 255, "你现在共有存款：%s。", CMoney::Money_Str(value));
	else
		snprintf(msg, 255, "你现在共有欠款：%s。", CMoney::Money_Str(-value));

	MessageVision(me, "tell", msg);
	return 1;
}
