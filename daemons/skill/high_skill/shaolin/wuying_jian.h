SKILL_BEGIN(CSwuying_jian);

virtual void create()
{
	set_name( "��Ӱ��");

	Magic_t * magic;

	magic = add_magic("wuying", do_wuying);
	magic->name = "������Ӱ";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("��Ӱ�����������ֶ����ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[9] = {
		{"$N�ս�����$wһ�С���ȥ���硹����$n��$l",
			50, 80, 20, 0,},
		{ "$Nһ�С������޹⡹������$w���´̳���ֱ��$n��ȥ",
        70, 20, 30, 20,},
		{ "$N��ǰ����һ��������$wʹ�����������ֱ��$n�ĺ�",
		90, 80, 50, 40,},
		{"$N���һ����ʹ�����ľ���ˮ������$wֱ��$n��Ҫ��",
		90, 60, 80, 60,},
		{ "ֻ��$N�������е�$w��ʹ����������ա������ֱ��$n",
        90, 50, 110, 80,},
		{"$N�������е�$w��ʹ��������Ҷ�䡹��������ֱ��$n",
        120, 100, 120, 100,},
		{ "$Nʹ��������������������$w�������һ����˸����������$n",
        200, 120, 140, 120,},
		{ "$N����ʹ������֮���塸��Ӱ���١�������$w�����һ������ǵصĴ���$n",
		300, 150, 250, 150,},
		{"$HIY$Nʹ����Ӱ����֮���վ���$HIC��������ˮ��$HIY����$w��������һ�����$n.$COM",
		400, 250, 700, 220,},
	};

	int level = me->query_skill("wuying_jian", 1);
	for(int i = 9; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);		
			
			if (DIFFERSTR(me->querystr("family/family_name"), "������"))
			{
				m_actions.set("action", "$N�ս�����$w�����һ����ŵ���$n��$l");
				m_actions.set("dodge", 1);
				m_actions.set("damage", 1);
				m_actions.set("force", 1);
			}
			else
			{
				m_actions.set("action", action[level].action);
				if(! me->query_temp("pfm_wuying"))
				{
					m_actions.set("force", action[level].force);
					m_actions.set("damage", action[level].damage);
				}
				else
				{
					m_actions.set("force", action[level].force);
					m_actions.set("damage", action[level].damage*3/2);
				}
				m_actions.set("dodge", action[level].dodge);
			}
			
			break;
		}
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("�������������ɮ���!");

	 CContainer * weapon;

     if (! (weapon = me->query_weapon())
        || DIFFERSTR(weapon->querystr("skill_type"), "sword"))
            return notify_fail("��ʹ�õ��������ԡ�");
     if (me->query("hp") < 50)
            return notify_fail("�����������������Ӱ��������");
     if ((int)me->query("mp") < 50)
            return notify_fail("�����������������Ӱ��������");
     me->receive_damage("hp", 40);
     me->add("mp",-15);
     return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_skill("hunyuan_yiqi", 1) < 150)
           return notify_fail("��ġ���Ԫһ������򲻹����޷�ѧ����Ӱ��������");
    if (me->query("max_mp") < 300)
           return notify_fail("�������̫�����޷�������Ӱ��������");
    return 1;
}

virtual int valid_enable(string usage) {return (usage == "sword") || (usage == "parry");}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if( damage <= 100 ) return 0;

    if( random(damage/3) > victim->query_str() ) 
	{
//                victim->add("hp", 1 - damage_bonus - 100 * 3 );
		victim->receive_wound("hp", (damage - 100) / 2);
		return "$HIR���������꡹һ������һ�����������������Ȼ��$nѪð���ɣ���$N�������ˣ�$COM";		
    }

	return 0;
}

static int do_wuying(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if (DIFFERSTR(me->querystr("family/family_name"), "������"))
		return notify_fail("����ôҲ�벻������ô��");

    if( !target ||! me->is_fighting(target) )
          return notify_fail("��������Ӱ��ֻ����ս����ʹ�á�");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
          return notify_fail("��������Ӱ�������ý�����ʩչ��");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if( DIFFERSTR(me->query_skill_mapped("sword"), "wuying_jian"))
		return notify_fail("���������Ӱ��ʹ�á�");

    if( me->query_skill("wuying_jian", 1) < 150 )
          return notify_fail("��ġ�������Ӱ����������죬����ʹ�á�������Ӱ����");

    if( me->query("mp") < 300  ) 
          return notify_fail("�������������");

    //int skill = me->query_skill("wuying_jian");
    message_vision("$HIG$N����ͻ�䣬˲������ֳ�������Ӱ��������$n��ȥ��$COM", me, target);
    me->add("mp", -200);

    //me->clean_up_enemy();
    //ob = me->select_opponent();
	me->set_temp("pfm_wuying", 1);

    message_vision("\n$HIR���־���", me, target);
    g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
    
	message_vision("\n$HIYȥ�־���", me, target);
    g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
        
	message_vision("\n$HIG���־���", me, target);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
        
	message_vision("\n$HIB���־���", me, target);
    g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
        
	message_vision("\n$HIW���־���", me, target);
    g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

	me->delete_temp("pfm_wuying");

    if( me->is_fighting() ) me->start_busy(5);

	return 1;
}

SKILL_END;