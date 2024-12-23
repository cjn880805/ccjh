// liuyang_zhang.h ������
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CSliuyang_zhang);

virtual void create()
{
	set_name( "������");
	set("valid_force", "bahuang_gong");
	
	Magic_t * magic;
	set("diff",150);
	
	magic = add_magic("jie", do_jie);
	magic->name = "��������";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;
	
	magic = add_magic("zhong", do_zhong);
	magic->name = "��������";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "bahuang_gong") || EQUALSTR(arg, "beiming_shengong"))
		return 1;
	
	return notify_fail("�����Ʊ�����ר�ŵ��ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$Nһ�С������۽𡹣����Ƶ�������֮�ϣ�����$n", 130, 20,0 , 0,"����",},
		{"$Nһ�С������ƶ���������ɫ���أ�˫����ƮƮ������$n", 150, 10, 30, 20,"����",},
		{"$Nһ�С���б��·��ϼ������˫�ƻû�һƬ��Ӱ����$n�������ڡ�", 150, 30, 35,30 ,"����",},
		{"$Nһ�С���������������$n��$l��������", 200, 25, 50, 40,"����",},
		{"$Nһ�С�����һ���ͽ��ѡ���ֻ��һƬ��Ӱ����$n", 250, 20, 10, 40,"����",},
		{"$N˫��ƽ�ӣ�һ�С���ϼ���������$n", 300, 25, 50, 60,"����",},
		{"$Nһ�С����ղγ��֡���ֻ��һƬ��Ӱ����$n",350 , 30,80 , 70,"����",},
		{"$N������Σ�����һ�ǡ���ϼ��Ѧᡡ�����$n��ͷ��", 350, 30, 90, 80,"����",},
		{"$Nʩ��������������������ֺ�ɨ$n��$l�����ֹ���$n���ؿ�", 400, -10, 90, 90,"����",},
		{"$Nʩ���������������˫��ͬʱ����$n��$l", 450, -10, 120,100 ,"����",},
	};
	
	int level = 0;
	
	for(int i=10; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("liuyang_zhang", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", (me->query("skill_pro/���չ�/������/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/���չ�/������/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/���չ�/������/damage")+100) * action[level].damage/100);
			
			break;
		}
	}
	
	return & m_actions;
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/���չ�/������/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/���չ�/������/force"));
			if(me->query("skill_pro/���չ�/������/force_point")>=level_point)
			{
				me->add("skill_pro/���չ�/������/force",1);
				me->set("skill_pro/���չ�/������/force_point",1);
				tell_object(me,"\n$HIR�������������ڹ������ڻ��ͨ�ˡ�\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/���չ�/������/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/���չ�/������/dodge"));
			if(me->query("skill_pro/���չ�/������/dodge_point")>=level_point)
			{
				me->add("skill_pro/���չ�/������/dodge",1);
				me->set("skill_pro/���չ�/������/dodge_point",1);
				tell_object(me,"\n$HIR���������ʹ�õø��ӵ���Ӧ���ˡ�\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/���չ�/������/damage_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/���չ�/������/damage"));
			if(me->query("skill_pro/���չ�/������/damage_point")>=level_point)
			{
				me->add("skill_pro/���չ�/������/damage",1);
				me->set("skill_pro/���չ�/������/damage_point",1);
				tell_object(me,"\n$HIR������������������ˡ�\n");
			}
		}
	}
	if( damage < 100 ) return 0;
	
	if( random(damage/2) > victim->query_con() )
	{
		victim->receive_wound("hp", (damage - 100) / 2 );
		return   "$N˫�ƻӶ����ҡ���һ����$n������Ѫ��һ�����ݷ��˳�ȥ��"  ;
	}
	return "";
}

virtual int valid_enable(string usage) 
{ 
	return usage == "unarmed" || usage == "parry" || usage == "strike"; 
}

virtual int valid_combine(string combo) { return combo=="zhemei_shou"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon() )
		return notify_fail("����ɽ�����Ʊ�����֡�");
	if ( me->query("max_mp") < 50)
		return notify_fail("�������̫�����޷��������ơ�");
	
	
	
	CChar * who = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who && me->query_skill("liuyang_zhang", 1)>=350)
		return notify_fail("�������Ŀǰ�Ĺ�������ɽ�������Ѿ��޷�����ָ���ˡ�");
	
	if(me->query_skill("liuyang_zhang", 1)>=350)
		return notify_fail("����Ŀǰ�Ĺ�������ɽ�������Ѿ��޷���������ˡ�");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if ( me->query("mp") < 20)
		return notify_fail("���������������ɽ�����ơ�");
	me->receive_damage("hp", 25);
	me->add("mp", -10);
	return 1;
}



//perform 
static int do_jie(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target)
		return notify_fail("��Ҫ��˭����������");
	
	if(target == me)
		return notify_fail("���޷����Լ�����������");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "���չ�") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if(  me->query_skill("bahuang_gong", 1) < 40 )
		return notify_fail("��İ˻����Ϲ�������죬���ܽ���������");
	
	if(  me->query_skill("liuyang_zhang", 1) < 40 )
		return notify_fail("�����ɽ�����Ʋ�����죬���ܽ���������");
	
	if(  me->query("mp" ) < 200 )
		return notify_fail("����������̫�������ܽ���������");
	
	me->add("mp", -200);
	target->apply_condition("ss_poison", 0);
	
	message_vision("$Nʹ����ɽ�����ƣ��������������ַ������ٵ�����$n�������Ѩ��", me, target);
	return 1;
	
}

static int do_zhong(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if(!target || !me->is_fighting(target) )
		return notify_fail("������ֻ�����ڶ������ϡ�");
	
	if(  me->query_skill("bahuang_gong", 1) < 60 )
		return notify_fail("��İ˻����Ϲ�������죬��������������");
	
	if(  me->query_skill("liuyang_zhang", 1) < 60 )
		return notify_fail("�����ɽ�����Ʋ�����죬��������������");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "���չ�") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if(  me->query("mp" ) < 100 )
		return notify_fail("����������̫������������������");
	
	//	if (! me->present("jiudai") )
	//        return notify_fail("������û�оƴ������ܻ�ˮΪ����");
	
	me->add("mp", -100);
	
	msg =   "$N��ˮΪ�����������У���ƮƮ������$n��\n";
	
	me->start_busy(1);
	if( random(  me->query_skill("liuyang_zhang",1))
		> random(target->query_skill("dodge") ) ) 
	{
		if(target->query_temp("apply/no_��������")&& !random(2))
			msg += "����$p��æ����һ�ԣ����˿�ȥ��";
		else
		{
			msg += " ���$P��$p������������������"  ;
			target->receive_damage("hp", me->query_skill("bahuang_gong",1));
			target->receive_wound("hp",15 + random(10));
			target->receive_wound("hp", 10);
			target->apply_condition("ss_poison", random(me->query_skill("liuyang_zhang",1)*3) +
				target->query("condition/ss_poison"));
			me->start_busy(random(2));
		}
	}
	else 
	{
		msg += "����$p��æ����һ�ԣ����˿�ȥ��"  ;
		me->start_busy(4);
	}
	message_vision(msg.c_str(), me, target);
	target->start_busy(1 + random(2));
	return 1;
}

SKILL_END;




