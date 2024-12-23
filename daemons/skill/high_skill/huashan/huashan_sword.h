// huashan_sword.h ��ɽ����
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CShuashan_sword);

virtual void create()
{
	set_name( "��ɽ����");
	set("valid_force", "zixia_shengong");

	
	Magic_t * magic;
/*
	magic = add_magic("feilong", do_feilong);
	magic->name = "�������";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
*/
	magic = add_magic("jianzhang", do_jianzhang);
	magic->name = "����������";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$Nʹһ�С��з����ǡ�������$w���Ⱪ������$n��$l��ȥ", 100, 170,0,"����",},
		{"$N������ת��һ�С��ޱ���ľ������$n��$l", -70, 40,20,"����",},
		{"$N�趯$w��һ�С����ڤڤ��Ю�������������$n��$l", -40, 180,40,"����",},
		{"$N����$w����һ����������ƽɳ���㡹��$n��$l�̳�����", -40, 80,60,"����",},
		{"$N����$w���Ⱪ����һ�С��������á���$n$l��ȥ", 60, 240, 80,"����",},
		{"$N����$w����һ���⻡��ֱָ$n$l��һ�С��׺���ա���������������ȥ", -60, 300, 100,"����",},
	};
 	
	for(int i=6; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("huashan_sword", 1))
		{
			int level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
    CContainer * ob;
    if(  me->query("max_mp") < 50 )
        return notify_fail("�������������û�а취����ɽ������");
	if(  DIFFERSTR(me->query_skill_mapped("force"), "zixia_shengong"))
        return notify_fail("��ɽ�������������ϼ�񹦲�������");
    if( !(ob = me->query_weapon())
		||  DIFFERSTR(ob->querystr("skill_type"), "sword") )
        return notify_fail("��ȷ�����õ��ǽ������õ��ѵ�����ǽ���");
	
    return 1;
	
}

virtual int practice_skill(CChar * me)
{
    if(  me->query("hp") < 30  ||  me->query("mp") < 5 )
        return notify_fail("�����������������û�а취��ϰ��ɽ������");
    me->receive_damage("hp", 30);
    me->add("mp", -5);
    tell_object(me,"�㰴����ѧ����һ�黪ɽ������", "practice");
    return 1;
}

//perform 
/*
static int do_feilong(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("װ��������ʹ�á������������" );

	if (!target || !me->is_fighting(target) )
		return notify_fail("�����������ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if ( me->query_skill("huashan_sword", 1) < 150 )
		return notify_fail("�㻪ɽ����������죬ʹ�����������������" );
	
	if ( me->query_skill("huashan_neigong", 1) < 100 )
		return notify_fail("�㻪ɽ�ڹ���򲻹���ʹ�����������������" );
	
	if ( me->query_skill("zixia_shengong", 1) < 100 )
		return notify_fail("����ϼ�񹦻�򲻹���ʹ�����������������" );

	if(DIFFERSTR(me->querystr("family/family_name"), "��ɽ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if ( me->query("max_mp") < 600)
		return notify_fail("��������Ϊ���㣬�޷�����������" );
	
	if ( me->query("mp") < 400)
	{
		return notify_fail( "����������������û�ܽ������������ʹ�꣡" );
	}
	msg =  "$N���������һ�������������̽����˾��ڱۣ�����һ����$n���˳�ȥ��\n" ;
	if ( random(me->query_combat_exp()) >  target->query_combat_exp()/3 )
	{
		me->start_busy(2);
		target->start_busy(random(3));
		int damage = target->query("hp");
		target->receive_damage("hp", damage-10);
		target->receive_wound("hp", damage/2);
		msg +=  "$n��æԾ�𣬵����������ֻ��һ���ʹ������������������Ѫ�ɽ���Ƥ�����" ;
		me->set("mp", 100);
	} else
	{
		me->start_busy(2);
		msg += "����$n����һЦ��������ָ��������$N�Ľ����ϣ���б����ء�" ;
		me->add("mp", -200);
	}
	weapon->move(me->environment());
	message_vision(msg.c_str(), me, target);
//	if(!target->is_fighting(me)) target->kill_ob(me);
	return 1;
	
}*/

static int do_jianzhang(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;
	char msg1[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(!target || !me->is_fighting(target) )
		return notify_fail("��������������ֻ����ս����ʹ�á�");
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("���õ��ǽ�����ȷ�����õ��ǽ����ѵ����õ�����ǽ���");

	if( DIFFERSTR(me->query_skill_mapped("sword"), "huashan_sword"))
		return notify_fail("������ϻ�ɽ����ʹ�á�");
	
	if(  me->query("mp") < 150 )
		return notify_fail("�������������");

	if(DIFFERSTR(me->querystr("family/family_name"), "��ɽ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if(  me->query_skill("zixia_shengong",1) < 50 )
		return notify_fail("�����ϼ�񹦲�����");
	
	if(  me->query_skill("sword",1) < 50 ||
		DIFFERSTR(me->query_skill_mapped("sword"), "huashan_sword"))
		return notify_fail("��Ļ�ɽ�����������ң��޷�ʹ�ý�����������");
	
	me->add("mp", -150);

	message_vision("\n\n$HIY$Nʹ����ɽ�ɾ�����������������������Ȼ�ӿ죡", me);

	if(target->query_temp("apply/no_����������")&& !random(2))
	{
		return notify_fail(snprintf(msg1, 255,"����%s������%s����ͼ������������ס��%s���������С�\n",target->name(),me->name(),me->name()));
	}
	else
	{
		me->call_out(lianhuan, 1, target->object_id(), 1);
	}
		return 10;

}

static void lianhuan(CContainer * ob, LONG param1, LONG time)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(! target || ! me->is_fighting(target)) return;
	
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_REGULAR);
	
	if(time < 5) 
		me->call_out(lianhuan, 1, param1, time + 1);
	else
		me->start_busy(3 + random(3));
}

SKILL_END;




