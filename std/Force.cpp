// Force.cpp: implementation of the CForce class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Force.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CForce::CForce()
{

}

CForce::~CForce()
{

}

void CForce::create()
{
	set_name("�����ڹ�");

	Magic_t * magic;

	magic = add_magic("recover", do_recover);
	magic->name = "��Ԫ��";
	magic->mp = 20;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
}

char * CForce::hit_ob(CChar * me, CChar * victim, LONG & damage_bonus)
{
	LONG damage, factor = me->query("mp_factor");
	int desc = 0;
	static char chat[][80]={
		"$HIY$N�ܵ�$n�����������ƺ�һ����",
		"$HIR$N��$n���������𣬡��١���һ������������",
		"$HIR$N��$n������һ���ؿ������ܵ�һ���ػ�����������������",
		"$RED$N��$n������һ����ǰһ�ڣ��������ɳ�������",
	};

	if(userp(me)) me->add("mp", - factor );

	//��������
	//int mp_limit = me->query_skill("force") * 20;
	int mp = me->query("mp");
	//int mp_limit_you = victim->query_skill("force") * 20;
	int mp_you = victim->query("mp");

	//if(userp(me) && mp > mp_limit) mp = mp_limit;
	//if(userp(victim) && mp_you > mp_limit_you) mp_you = mp_limit_you;

	damage =  mp / 30 + factor - mp_you / 50;

	if( damage < 0 ) {
		 if( !me->query_weapon()
				&&   random(victim->query_skill("force") + 1) > me->query_skill("force")/2 ) 
		 {
			damage = - damage;
			me->receive_damage("hp", damage * 2 );
			me->receive_wound( "hp", damage );
			
			if( damage < 10 ) desc = 0;
			else if( damage < 20 ) desc = 1;
			else if( damage < 40 ) desc = 2 ;
			else desc = 3;
			return chat[desc];
		}

		damage_bonus += damage;
		if(damage_bonus < 0) damage_bonus = 0;
		return 0;
	}

	damage -= victim->query_temp("apply/armor_vs_force");

	if(damage_bonus + damage < 0)
		damage_bonus = 0;
	else if(random(me->query_skill("force") ) < damage )
		damage_bonus += damage;
	
	return 0;
}

int CForce::do_recover(CChar * me, CContainer * target)
{
	int n, q;
	if (me->query("mp") < 20)
		return notify_fail("�������������");

	q = me->query("eff_hp") - me->query("hp");
	if (q < 10)
		return notify_fail("�������������档");
	
	n = 100 * q / me->query_skill("force");
	if (n < 20)
		n = 20;
	if (me->query("mp") < n) 
	{
		q = q * me->query("mp") / n;
		n = me->query("mp");
	}

	me->add("mp", -n);
	me->receive_healing("hp", q);
	
    message_vision("$N�������˼���������ɫ�������ö��ˡ�", me);

    if( me->is_fighting() ) me->start_busy(1);
	
	return 1;
}
