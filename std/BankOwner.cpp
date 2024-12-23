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

//��Ǯ deposit 
int CBankOwner::Do_Deposit(CChar * me, LONG amount)
{
	char msg[255];
		
	if( amount <= 0) return 0;

	if(! CMoney::Player_Pay(me, amount))
		return notify_fail("������û�������Ǯ��");
            
	me->add("balance", amount);
	me->Save();
	message_vision(snprintf(msg, 255, "$N�����ֿ�%s��", CMoney::Money_Str(amount)), me);
	
	output_error("%s(%s)�����ֿ�%ld�����ﵽ%ld��", me->name(1), me->id(1), amount, me->query("balance"));

	return 1;
}

//���
int CBankOwner::Do_Withdraw(CChar * me, LONG amount)
{
	char msg[255];
	LONG hamount;

    hamount = me->query("balance");
	
	if(amount <=0 ) return 0;
	if(amount > hamount) 
		return notify_fail("��û��ô���� ����");		
	
	me->add("balance", - amount);
	me->Save();

	CMoney::Pay_Player(me, amount);
	tell_object(me, "�����ϡ�");

	output_error(snprintf(msg, 255, "%s(%s)���%ld�����%ld��From (%s)", me->name(1), me->id(1), amount, me->query("balance"), GetIP(me)) );

	return 1;
}

//����
int CBankOwner::Do_Loan(CChar *me, LONG amount)
{
	LONG hamount;
	char msg[255];
        
	hamount = me->query("balance");
	if(hamount > 0 ) 
		return notify_fail("�㻹�д�");
		
	if(userp(me))
		return notify_fail("����ҵ����ͣ��");
		
	if(me->query("level")>150)
		return notify_fail("��ô���������ﻹ����Ǯ���϶��Ǽ�ð�ģ����裡");
		        
	if(amount <=0 ) return 0;
	if(CChar::Level2Exp(me->query("level")) < amount - hamount)
		return notify_fail("��費����ô��Ǯ������");
		       
	hamount -= amount;
    me->set("balance", hamount);
	me->Save();

	CMoney::Pay_Player(me, amount);
    tell_object(me, "������ϡ�");
	
	output_error(snprintf(msg, 255, "%s(%s)����%ld�����%ld��From (%s)", me->name(1), me->id(1), amount, me->query("balance"), GetIP(me)) );

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
        MessageVision(me, "tell", "������û�д�");
		return 1;
	}

	if(value > 0) 
		snprintf(msg, 255, "�����ڹ��д�%s��", CMoney::Money_Str(value));
	else
		snprintf(msg, 255, "�����ڹ���Ƿ�%s��", CMoney::Money_Str(-value));

	MessageVision(me, "tell", msg);
	return 1;
}
