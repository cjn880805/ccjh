// xue-dao.c Ѫ��
SKILL_BEGIN(CSxue_dao);

virtual void create()
{
	set_name( "Ѫ��");
	set("valid_force", "longxiang");

	Magic_t * magic;

	magic = add_magic("jixue", do_jixue);
	magic->name = "��Ѫ��";
	magic->mp = 600;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, lvl, damage;
	}action[] = {
		{"$N�߾�����$w,ʹ��һ�С�ĥ��˱Ѫ����һ��б��$n��$l", 200, -5, 5, 0, 20,},
		{"$N�͵�һ����ʹһ�С���Ѫ���ء�������$w����$n�Ĵ���", 240, 5, 5, 8, 25,},
		{"$N���һ�㣬ʹ����Ѫ��ãã�����������϶���ֱ��$n��$l", 280, 10, 5, 16, 30,},
		{"$Nʹ��һ�С�Ż����Ѫ������$w��������һ��ѹ��$n", 320, 5, 5, 24, 40,},
		{"$N�ͺ�һ����ʹ����Ѫ�����ˡ�����$wֱ��$n��$l", 350, -5, 5, 48, 50,},
		
		{"$Nʹ����Ѫ���߰ߡ�������б�̣���Ȼ����һ����ն$n������", 380, 10, 5, 60, 60,},
		{"$Nʹһʽ����Ѫ��Ѫ�����ӵ�ֱָ$n���ؿ�", 400, 5, 10, 80, 80,},
		{"$N������㣬ʹ��һ�С�Ѫ�����桹��ת���$w����$n������", 400, 10, 20, 100, 100,},
	};

	int level = me->query_skill("xue_dao", 1);
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="blade" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 50)
		return notify_fail("�������������");
	
	if (me->query_skill("longxiang", 1) < 20)	//�˴�ԭ����Ѫ���ķ�����ΪûNPC�ᣬ���ˡ�lanwood 2001-03-11
		return notify_fail("���������������̫ǳ��");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if (me->query("hp") < 50)
		return notify_fail("�������������Ѫ����");
	me->receive_damage("hp", 30);
	return 1;
}


//exert heal
static int do_jixue(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || ! me->is_fighting(target))
		return notify_fail("����Ѫ�񵶡�ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("װ��������ʹ�á���Ѫ�񵶡���");

	if(DIFFERSTR(me->querystr("family/family_name"), "ѩɽ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( me->query_skill("xue_dao", 1) < 40 )
		return notify_fail("��Ѫ������������죬ʹ��������Ѫ�񵶡���");
	
	if (me->query_skill("longxiang", 1) < 60 )
		return notify_fail("�������������򲻹���ʹ��������Ѫ�񵶡���");
	if (me->query("max_mp") < 600)
		return notify_fail("��������Ϊ���㣬�޷�����������");
	if (me->query("mp") < 600)
		return notify_fail("����������������û�ܽ�����Ѫ�񵶡�ʹ�꣡");

	msg = "$N���ֳֵ������һ�գ�һ��Ѫ�齦�����棬�������ұ��ճ���һƬѪ���ס��Ӱ��$n��ͷ���䣬\n";
	if(target->query_temp("apply/no_��Ѫ��")&& (random(2)||target->query("bigboss")))
	{
		msg += "����$n������ã����Ų�æ�������$N��Ѫ����";
		me->start_busy(4);
	}
	else
	{
		if ( random(me->query_combat_exp()) > target->query_combat_exp()/2 )
		{
			int repute=me->query("repute");
			if(repute<-60000000)
				repute=-60000000;
			int damage = random(repute/-1000)+(repute/-4000);
			if(damage>10000)
			{
				if( random(100)<40)
					damage=random(5000)+5000;
				//else if(damage>15000)
				//	damage=15000;
			}
			me->add("mp", -600);
			me->receive_wound("hp", me->query("hp")/20);
			me->start_busy(1);
			target->start_busy(random(3));
			target->receive_damage("hp", damage);
			target->receive_wound("hp", damage/2);
			msg += "$n��æ������ã���Ѫ��������ֻ����ǰһ��Ѫ�죬����������£���Ѫ�ɽ��������󺿣�\n";
			message_vision(msg.c_str(), me, target);
			char msg1[255];
			message_vision(snprintf(msg1,255,"$HIR��������%d����˺���$COM\n",damage), me, target);
		} 
		else
		{
			me->start_busy(2);
			me->receive_wound("hp", me->query("hp")/20);
			msg += "����$n������ã����Ų�æ�������$N��Ѫ����";
			me->add("mp", -200);
			message_vision(msg.c_str(), me, target);
		}
	}
	if(!target->is_killing(me)) target->kill_ob(me);
	return 1;
}

SKILL_END;
