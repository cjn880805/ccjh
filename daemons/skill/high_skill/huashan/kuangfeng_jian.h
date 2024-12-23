//kuangfeng_jian.h ���콣

SKILL_BEGIN(CSkuangfeng_jian);

virtual void create()
{
	set_name( "���콣");
	set("valid_force", "zixia_shengong");

	Magic_t * magic;

	magic = add_magic("feilong", do_feilong);
	magic->name = "�������";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  damage, dodge, force, lvl;
	}action[4] = {
		{ "$N����Ծ������$w��ӣ�ն��$n��",
			150, 10, 0, 0,},
		{ "$N����$w�����������Σ���$n���ұ����ն��",
		170, 35, 20, 20,},
		{ "$N����һ����ˢˢˢˢ�Ľ�����$n�أ������������Ĵ�����",
		190, 25, 25, 40,},
		{"$N����һ����Х��б����ǰ��$w����ֱ����Ѹ���ޱȣ�����$n��$l",
		210, 15, 35, 60,},
	};
 
  	int level = me->query_skill("kuangfeng_jian", 1);
	for(int i = 4; i > 0; i--)
		if( action[i - 1].lvl < level)
		{
			level = random(i);
	
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
			
	return & m_actions;
};

virtual int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
    if( DIFFERSTR(me->querystr("family/master_id"), "feng butan"))
		return notify_fail("���޷������ѧϰ���콣��");
    if (me->query("max_mp") < 300)
        return notify_fail("�������������");
    if (me->query_skill("force", 1) < 60)
        return notify_fail("����ڹ��ķ����̫ǳ��");
    if (me->query_skill("dodge", 1) < 60)
        return notify_fail("����Ṧ���̫ǳ��");
    if (me->query_dex() < 25)
        return notify_fail("�������������");
    return 1;
}


virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

    if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
        return notify_fail("��ʹ�õ��������ԡ�");
    if (me->query("hp") < 30)
        return notify_fail("����������������콣��");
    me->receive_damage("hp", 25);
    return 1;
}

static int do_feilong(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	CContainer * weapon;
	string msg;

	if( !target || !me->is_fighting(target) )
		return notify_fail("�����������ֻ�ܶ�ս���еĶ���ʹ�á�");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("װ��������ʹ�á������������");
		
	if( me->query_skill("kuangfeng_jian", 1) < 100 )
		return notify_fail("����콣������죬ʹ�����������������");
	                        
	if( me->query_skill("zixia_shengong", 1) < 100 )
		return notify_fail("����ϼ�񹦻�򲻹���ʹ�����������������");
			
	if( me->query("max_mp") < 600 )
		return notify_fail("��������Ϊ���㣬�޷�����������");

	if(DIFFERSTR(me->querystr("family/family_name"), "��ɽ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if (me->query("mp") < 400)
        return notify_fail("����������������û�ܽ������������ʹ�꣡");
			
	 msg = "$N���������һ�������������̽����˾��ڱۣ�����һ����$n���˳�ȥ��\n";

	 if(target->query_temp("apply/no_�������")&& (random(2)||target->query("bigboss")))
	 {
		 msg += "����$n����һЦ��������ָ��������$N�Ľ����ϣ���б����ء�";
		 me->start_busy(4);
	 }
	 else
	 {
		 if ( random(me->query_combat_exp()) > target->query_combat_exp()/2 )
		 {
			 me->start_busy(2);
			 target->start_busy(random(3));
			 int damage = target->query("hp");
			 if(damage>30000)damage=29000+random(1000);
			 target->receive_damage("hp", damage - 10);
			 target->receive_wound("hp", damage/2);
			 msg += "$n��æԾ�𣬵����������ֻ��һ���ʹ������������������Ѫ�ɽ���Ƥ�����";
			 me->set("mp", 100);
		 } 
		 else
		 {
			 me->start_busy(2);
			 msg += "����$n����һЦ��������ָ��������$N�Ľ����ϣ���б����ء�";
		 }
	 }
	 weapon->move(me->environment());
     message_vision(msg.c_str(), me, target);
    
     return 1;
}

SKILL_END;

