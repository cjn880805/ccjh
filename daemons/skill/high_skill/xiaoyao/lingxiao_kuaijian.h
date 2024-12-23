// lingxiao_kuaijian.h �����콣
//code by Teapot
//date : 2001-02-10

SKILL_BEGIN(CSlingxiao_kuaijian);

void create()
{
	set_name( "�����콣");

	set("diff",150);
	Magic_t * magic;

	magic = add_magic("mixhit", do_mixhit);
	magic->name = "����ʮ����";
	magic->mp = 2500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  damage,dodge,lvl;
	}action[8] = {
		{"$N����$wһ�񣬻���һ����â����$n��", 50, 0 , 0,},
		{"$N����$wһ�񣬻���һ����â����$n��", 100, 5 , 40,},
		{"$N����$wһ�񣬻���һ����â����$n��", 150, 10 , 80,},
		{"$N����$wһ�񣬻���һ����â����$n��", 200, 15 , 120,},
		{"$N����$wһ�񣬻���һ����â����$n��", 250, 20 , 160,},
		{"$N����$wһ�񣬻���һ����â����$n��", 300, 30 , 200,},
		{"$N����$wһ�񣬻���һ����â����$n��", 400, 40 , 240,},
		{"$N����$wһ�񣬻���һ����â����$n��", 500, 50 , 255,},	//Learn Level Max:250.
	};
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("lingxiao_kuaijian", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("damage", action[level].damage);
			m_actions.set("dodge", action[level].dodge);
*/
			m_actions.set("dodge", (me->query("skill_pro/��ң��/�����콣/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/��ң��/�����콣/damage")+100) * action[level].damage/100);
	
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
		if(victim->query("dodge")) 
		{
			me->add("skill_pro/��ң��/�����콣/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/��ң��/�����콣/dodge"));
			if(me->query("skill_pro/��ң��/�����콣/dodge_point")>=level_point)
			{
				me->add("skill_pro/��ң��/�����콣/dodge",1);
				me->set("skill_pro/��ң��/�����콣/dodge_point",1);
				tell_object(me,"\n$HIR��������콣ʹ�õø��ӵ���Ӧ���ˡ�\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/��ң��/�����콣/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/��ң��/�����콣/damage"));
			if(me->query("skill_pro/��ң��/�����콣/damage_point")>=level_point)
			{
				me->add("skill_pro/��ң��/�����콣/damage",1);
				me->set("skill_pro/��ң��/�����콣/damage_point",1);
				tell_object(me,"\n$HIR��������콣���������ˡ�\n");
			}
		}
	}
	return "";
}


int valid_enable(string usage) 
{ 
	return (usage == "sword") ;
}

int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 2500)
		return notify_fail("�������������");
	if (DIFFERSTR(me->querystr("family/master_id"), "qingyun"))
		return notify_fail("�����콣ֻ�����ľ����ѧϰ��");
	//if (me->query_skill("beiming_shengong", 1) < 130)
	//	return notify_fail("��ı�ڤ�񹦻��̫ǳ��");
	//if (me->query_skill("beiming_shengong", 1) >= 140)
	//	return notify_fail("��ı�ڤ�񹦻��̫�");
	return 1;
}

int practice_skill(CChar * me)
{
	return notify_fail("�����콣����������Ѹ�죬ֻ���ڶ�����������");
	// Disable Practice.
}

//perform 

static int do_mixhit(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("����ʮ�����޷�ʹ�á�");
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("����ʮ�����޷�ʹ�á�");

	if( DIFFERSTR(me->query_skill_mapped("sword"), "lingxiao_kuaijian"))
		return notify_fail("���������������ʹ�á�");

	if (me->query_skill("beiming_shengong", 1) < 130)
		return notify_fail("��ı�ڤ�񹦻��̫ǳ��");
	if (me->query_skill("beiming_shengong", 1) >= 140)
		return notify_fail("��ı�ڤ�񹦻��̫�");

	if(DIFFERSTR(me->querystr("family/family_name"), "��ң��") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	int i;

	i=me->query_skill("lingxiao_kuaijian",1);
	i=i/10;		// 250:25 pfm casts i/2 
	if (i<12)
	{
		return notify_fail("�������ʮ�����ȼ�������");
	}

	if( me->query("mp") < i*125 )		// ��һ����Ҫ250mp.������Ҫ1500mp,ʮ������Ҫ3250mp?ok...
		return notify_fail("�������������ʹ������ȼ�������ʮ������");

	if(DIFFERSTR(me->querystr("family/family_name"), "��ң��"))
		me->add("mp",-i*125);
	else
		me->add("mp",-i*125*(100-me->query_temp("apply/sub_mp"))/100);

	snprintf(msg ,255,"$N����һ����������������������ͨ���������Ķ��������߾��磬���г���΢΢�ζ�����"  );
	message_vision(msg, me);

	i = (32 - i);
	if(i < 1) i = 1;

	me->call_out(remove_effect, i, target->object_id(), (30-i));
		
	me->start_busy(3);

	return 1;
}

static void remove_effect(CContainer *ob1, LONG  param1, LONG amount1)
{
	CChar * me = (CChar *)ob1;
	CChar * target = (CChar *)(me->environment())->Present(param1);
	CContainer * weapon;
	char msg[255];

	me->start_busy(1);

	if( !target || !me->is_fighting(target) )
		return ;
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return ;

	if(! living(me))
		return ;

	snprintf(msg ,255,"$Nһ�٣�ֻ������һ��������ʮ���������������"  );
	message_vision(msg, me);

	int i = amount1 * 5 / 2;
	if (i>13)
		i=13;	// Max: 13.
	
	for(int n = 0; n < i; n++)
	{
		if(EQUALSTR(me->query_skill_mapped("sword"), "lingxiao_kuaijian"))
		{
			snprintf(msg ,255,"ֻ��$N�����糱����ӿ������"  );
			message_vision(msg, me);
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		}
		else
			break;
	}	
		
	me->start_busy(i-2);
	
	return;	
}

SKILL_END;
