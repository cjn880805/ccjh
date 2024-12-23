
// lanhua_shou.h ������Ѩ��
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CSlanhua_shou);

virtual void create()
{
	set_name( "������Ѩ��");
	set("valid_force", "bibo_shengong");

	set("diff",110);

	Magic_t * magic;

	magic = add_magic("fuxue", do_fuxue);
	magic->name = "�黨��Ѩ";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,lvl;
		char damage_type[5];
	}action[] = {
		{"$N������ָ�ֿ���΢΢һ�����ٲ�£����һ����һʽ�������Ƶ���������$n������ҪѨ",150 , 5, 0,"����",},
		{"$N��������$n��һʽ�����Ʊ��¡���������ָ������������$n����ǰ��Ѩ", 160, 5, 10,"����",},
		{"$Nʹһʽ�������������������鹥�����ֲ�ָбǰ����������$n�ļ羮Ѩ", 170, 15, 20,"����",},
		{"$N���ƻ��أ�΢΢�������ƹ��ϣ�һʽ������ŪӰ������������$n����ͻѨ", 190, -5, 30,"����",},
		{"$Nʹһʽ���������塹����Ӱ����������$n����͵�����$n�Ĵ�׵Ѩ", 210, 10, 42,"����",},
		{"$N���������������ϵ�����ǰ������ָ�η��ϣ�΢��һ������һʽ�������뷼����˫���������һ��������������������$n�Ļ��ǡ���ᡢ�Ϲ�������Ѩ", 240, 5, 54,"����",},
		{"$N����ƮƮ������Ծ��һʽ����Ӱ���㡹���Ӹ����£�����һ����������$n�İٻ��Ѩ", 270, 20, 66,"����",},
		{"$N����ʩչ����������Բ����˫�ּ�����һ�����ľ�������$n�������¸���ҪѨ", 300,25 , 80,"����",},
	};

	int level = me->query_skill("lanhua_shou", 1);
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level )
		{
			level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
*/
			m_actions.set("force", (me->query("skill_pro/�һ���/������Ѩ��/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/�һ���/������Ѩ��/dodge")+100) * action[level].dodge/100);

			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "hand") || (usage == "parry");
}

virtual int valid_combine(string combo) { return combo=="tanzhi_shentong"; }


virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/�һ���/������Ѩ��/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/�һ���/������Ѩ��/force"));
			if(me->query("skill_pro/�һ���/������Ѩ��/force_point")>=level_point)
			{
				me->add("skill_pro/�һ���/������Ѩ��/force",1);
				me->set("skill_pro/�һ���/������Ѩ��/force_point",1);
				tell_object(me,"\n$HIR���������Ѩ������ڹ������ڻ��ͨ�ˡ�\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/�һ���/������Ѩ��/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/�һ���/������Ѩ��/dodge"));
			if(me->query("skill_pro/�һ���/������Ѩ��/dodge_point")>=level_point)
			{
				me->add("skill_pro/�һ���/������Ѩ��/dodge",1);
				me->set("skill_pro/�һ���/������Ѩ��/dodge_point",1);
				tell_object(me,"\n$HIR���������Ѩ��ʹ�õø��ӵ���Ӧ���ˡ�\n");
			}
		}
	}
	return "";
}


virtual int valid_learn(CChar * me)
{
    if (me->query_weapon()  )
		return notify_fail( "��������Ѩ�ֱ�����֡�" );
    if ( me->query_skill("bibo_shengong", 1) < 20)
		return notify_fail("��ı̲��񹦻�򲻹����޷�ѧ������Ѩ�֡�");
    if ( me->query("max_mp") < 200)
		return notify_fail("�������̫�����޷���������Ѩ�֡�");
    return 1;
	
}

virtual int practice_skill(CChar * me)
{
    if ( me->query("hp") < 30)
		return notify_fail("�������̫���ˣ��޷���������Ѩ�֡�");
    me->receive_damage("hp", 25);
    return 1;
}

//perform 
static int do_fuxue(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || !me->is_fighting(target))		//add by Lanwood 2000-12-26
		return notify_fail("ֻ�ܶ�ս���еĵ���ʹ�á�");

	if( me->query_str() < 25)
		return notify_fail("���������,����ʹ����һ����!");

	if(DIFFERSTR(me->querystr("family/family_name"), "�һ���") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( me->query_weapon() )
		return notify_fail("�㻹���ű����أ���ʹ��������һ���ָ���ġ�");	

	if( me->query_skill("bibo_shengong",1) < 100)
		return notify_fail("��̲��񹦵Ĺ�����������ʹ��������Ѩ!");
	
	if( me->query_skill("hand") < 120)
		return notify_fail("����ַ���Ϊ����,Ŀǰ������ʹ��������Ѩ����!");
	
	if( me->query("mp") < 500)
		return notify_fail("���������ڲ���, ����ʹ���黨��Ѩ! ");
	
	if( target->is_busy() )
		return notify_fail("%sĿǰ���Թ˲�Ͼ���ŵ������� ",target->name() );
	
	msg =   "$HIY$N���ַ������������ָͷ��ת��һ��ʢ������������ӯ������$n��в��ҪѨ, ʹ$n�������á�\n";
	
	if( random(me->query_combat_exp()) >  target->query_combat_exp() / 3 )
	{
		if(target->query_temp("apply/no_�黨��Ѩ")&& !random(2))
		{
			msg += "$HIC����$p������$P����ͼ������һԾ�����˿�ȥ��";
		}
		else
		{
			msg +=    "$HIM���$p��$P������ţ���ʱ�����޴룬��������! "  ;
			target->start_busy(  me->query_skill("lanhua_shou",1) / 20 );
			me->add("mp", -100);
		}
	}
	else
	{
		msg +=   "$HIC����$p������$P����ͼ������һԾ�����˿�ȥ��"  ;
		me->start_busy(4);
		me->add("mp", -50);		// add by lanwood 2000-12-26
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;




