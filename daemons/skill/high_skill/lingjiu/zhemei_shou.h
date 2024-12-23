// zhemei_shou.h ��÷��
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CSzhemei_shou);

virtual void create()
{
	set_name( "��÷��");

	Magic_t * magic;
	set("diff",150);

	magic = add_magic("duo", do_duo);
	magic->name = "���������";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "bahuang_gong") || EQUALSTR(arg, "beiming_shengong"))
		return 1;

	return notify_fail("��÷�ֱ�����ר�ŵ��ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$Nһ�С���÷��Թ����˫�ֺ�ӣ�ץ��$n", 130, 20, 0, 0,"����",},
		{"$Nһ�С��ƻ���Գ������ԾȻ����ץ��$n��ͷ��", 150, 20, 20, 10,"����",},
		{"$Nһ�С���ɽһ�����ı̡���˫�ַ׷ɣ�$nֻ���ۻ�����", 150, 30, 30, 30,"����",},
		{"$Nһ�С�÷��ѩ�串��ƻ����˫�ֺϻ���$nֻ���޴��ɱ�", 150, 30, 45, 40,"����",},
		{"$Nһ�С�������÷��ѩ�ҡ���˫��ƮȻץ��$n", 250, 30, 50, 50,"����",},
		{"$N˫��ƽ�٣�һ�С�����������ŪӰ������$n", 300, 35, 80, 60,"����",},
		{"$Nһ�С���������ֱ���ۡ�������$n���ƺ�$n��ȫ��������", 350, 30, 100, 70,"����",},
		{"$N������Σ�����һ�ǡ�����δ�϶��Ⱦ�������$n��ͷ��", 350, 30, 150, 80,"����",},
		{"$Nʩ��������Ц�졹�����ֺ�ɨ$n��$l�����ֹ���$n���ؿ�", 400, -10,150 ,90 ,"����",},
		{"$Nʩ������ʯ��١�������һ������$n", 450, -20, 150, 100,"����",},
	};
	int level = 0;
	
	for(int i=10; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("zhemei_shou", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", (me->query("skill_pro/���չ�/��÷��/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/���չ�/��÷��/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/���չ�/��÷��/damage")+100) * action[level].damage/100);
			break;
		}
	}
	
	return & m_actions;
};


virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/���չ�/��÷��/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/���չ�/��÷��/force"));
			if(me->query("skill_pro/���չ�/��÷��/force_point")>=level_point)
			{
				me->add("skill_pro/���չ�/��÷��/force",1);
				me->set("skill_pro/���չ�/��÷��/force_point",1);
				tell_object(me,"\n$HIR�����÷������ڹ������ڻ��ͨ�ˡ�\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/���չ�/��÷��/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/���չ�/��÷��/dodge"));
			if(me->query("skill_pro/���չ�/��÷��/dodge_point")>=level_point)
			{
				me->add("skill_pro/���չ�/��÷��/dodge",1);
				me->set("skill_pro/���չ�/��÷��/dodge_point",1);
				tell_object(me,"\n$HIR�����÷��ʹ�õø��ӵ���Ӧ���ˡ�\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/���չ�/��÷��/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/���չ�/��÷��/damage"));
			if(me->query("skill_pro/���չ�/��÷��/damage_point")>=level_point)
			{
				me->add("skill_pro/���չ�/��÷��/damage",1);
				me->set("skill_pro/���չ�/��÷��/damage_point",1);
				tell_object(me,"\n$HIR�����÷�����������ˡ�\n");
			}
		}
	}
	return "";
}

virtual int valid_enable(string usage) 
{ 
	return usage == "unarmed" || usage == "hand" || usage == "parry"; 
}

virtual int valid_combine(string combo) { return combo=="liuyang_zhang"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("����ɽ��÷�ֱ�����֡�");
	if ( me->query("max_mp") < 50)
		return notify_fail("�������̫�����޷�����ɽ��÷�֡�");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if ( me->query("mp") < 20)
		return notify_fail("���������������ɽ��÷�֡�");
	me->receive_damage("hp", 25);
	me->add("mp", -10);
	return 1;
}
//perform 
static int do_duo(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(  me->query_temp("duo") )
		return notify_fail("���Ѿ��ڶ���˵ı����ˡ�");
	
	int skill = me->query_skill("zhemei_shou",1);
	
	if( !target || ! me->is_fighting(target))
		return notify_fail("���������ֻ�ܶ�ս���еĶ���ʹ�á�");

	if(DIFFERSTR(me->querystr("family/family_name"), "���չ�") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if ( me->query_weapon())
		return notify_fail("�������֡�");
	
	if (! (weapon = target->query_weapon()))
		return notify_fail("�Է�û�б��У��㲻�õ��ġ�");
	
	if( skill < 50)
		return notify_fail("�����ɽ��÷�ֵȼ�����, ���ܿ�������У�");
	
	if( me->query("mp") < 50 )
		return notify_fail("��������������޷���������У�");
	
	msg =   "$N�����Ϣ������ʩչ��������еľ���. \n";
	
	int dp = target->query_skill("parry") * 2 / 3;
	if( dp < 1 )
		dp = 1;
	if( random(skill) > dp )
	{
		me->add("mp",-50);
		if(weapon->query("no_duo") && !random(3))
			msg += "����$n������$N����ͼ����û���ϵ�";
		else
		{
			msg += "$Nʹ����������еľ���, $n��ʱ������ǰһ��������һ�飬���б������ֶ�����"  ;
			if(weapon->query("no_duo") )//�Ƿ��Ǳ���
			{
				char msg1[40];
				target->command(snprintf(msg1, 40, "unwield %ld", weapon->object_id()));
			}
			else
			{
				target->start_busy(2);
				//�ж��Ƿ����Ʊ������� lanwood 2001-04-04
				if(weapon->querystr("owner")[0])
					weapon->move(me->environment());
				else
					weapon->move(me);
			}
		}

		me->start_busy(random(2));
	}
	else
	{
		msg += "����$n�Ŀ�����$N����ͼ�����̲�ȡ���ƣ�ʹ$Nû�ܶ��±��С�" ;
		me->start_busy(random(2));
	}
	message_vision(msg.c_str(), me, target);
 	return 1;
}

SKILL_END;




