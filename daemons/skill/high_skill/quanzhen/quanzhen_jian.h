
// quanzhen_jian.h ȫ�潣��
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSquanzhen_jian);

virtual void create()
{
	set_name( "ȫ�潣");
	
	set("diff",120);
	Magic_t * magic;

	magic = add_magic("ding", do_ding);
	magic->name = "������";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("flood", do_flood);
	magic->name = "����һ��";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "xiantian_gong") || EQUALSTR(arg, "xiantian_qigong"))
		return 1;

	return notify_fail("ȫ�潣���������칦���ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$Nʹһʽ��̽��������������$w�������Һ�ɨ����$n��$l",120 , 0, 30, 0,"����",},
		{"$N̤��һ�������ɨҶ��������$w���������һ����������$n��$l", 140, 10, 40, 9,"����",},
		{"$N����$wһ����һ�С�˳ˮ���ۡ���ббһ�������ó�������$n��$l", 160, 5, 50, 18,"����",},
		{"$N����$w����������Ȧ��һʽ���ǳڵ�������һ���������$n��$l", 180, 10, 65,27 ,"����",},
		{"$Nһʽ���׺����᡹��������չ������$w����$n��$l", 220, 15, 80, 36,"����",},
		{"$N����$wбָ���죬һʽ������Į��������׼$n��$lбб����", 260, 5, 100, 44,"����",},
		{"$Nһʽ�������仨�������󼱶�������������⣬����$n��$l", 320, 5, 105, 52,"����",},
		{"$Nһʽ����Ʒ��̨����$w��ն�������缲�������$n���ؿ�", 380, 5, 125, 60,"����",},
		{"$Nʹһʽ��������ء�������$w������$n���ؿڣ������ɵ�", 380, 5, 125, 70,"����",},
		{"$N����$w����һ�������Ļ��ߣ�����$n��$l��ȴ��һ�С���ʷ������", 380, 5, 140, 80,"����",},
		{"$N�ؽ����أ�ʹһʽ��������项���������$w��$n����", 380, 5, 140, 90,"����",},
		{"$N��������һʽ�������߶�����$w�Ӳ���˼��ĽǶȴ���$n", 380, 5, 140, 114,"����",},
		{"$Nһʽ���ϵ紩�ơ���$wͻȻ���������һƬ���Χ��$nȫ��", 380, 5, 155, 129,"����",},
	};
	
	int level = 0;
	
	for(int i=13; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("quanzhen_jian", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
*/			m_actions.set("force", (me->query("skill_pro/ȫ����/ȫ�潣/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/ȫ����/ȫ�潣/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/ȫ����/ȫ�潣/damage")+100) * action[level].damage/100);

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
			me->add("skill_pro/ȫ����/ȫ�潣/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/ȫ����/ȫ�潣/force"));
			if(me->query("skill_pro/ȫ����/ȫ�潣/force_point")>=level_point)
			{
				me->add("skill_pro/ȫ����/ȫ�潣/force",1);
				me->set("skill_pro/ȫ����/ȫ�潣/force_point",1);
				tell_object(me,"\n$HIR���ȫ�潣����ڹ������ڻ��ͨ�ˡ�\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/ȫ����/ȫ�潣/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/ȫ����/ȫ�潣/dodge"));
			if(me->query("skill_pro/ȫ����/ȫ�潣/dodge_point")>=level_point)
			{
				me->add("skill_pro/ȫ����/ȫ�潣/dodge",1);
				me->set("skill_pro/ȫ����/ȫ�潣/dodge_point",1);
				tell_object(me,"\n$HIR���ȫ�潣ʹ�õø��ӵ���Ӧ���ˡ�\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/ȫ����/ȫ�潣/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/ȫ����/ȫ�潣/damage"));
			if(me->query("skill_pro/ȫ����/ȫ�潣/damage_point")>=level_point)
			{
				me->add("skill_pro/ȫ����/ȫ�潣/damage",1);
				me->set("skill_pro/ȫ����/ȫ�潣/damage_point",1);
				tell_object(me,"\n$HIR���ȫ�潣���������ˡ�\n");
			}
		}
	}
	return "";
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if ( me->query_skill("yunv_xinfa", 1) < 15 &&
		me->query_skill("xiantian_qigong", 1) < 15)
		return notify_fail("����ڹ��ķ���򲻵����޷�ѧϰȫ�潣����");
	
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (! (weapon = me->query_weapon())
        ||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if ( me->query("hp") < 50)
		return notify_fail("�������������ȫ�潣����");
	me->receive_damage("hp", 25);
	return 1;
	
}

//perform 
static int do_ding(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if( !target || !me->is_fighting(target) )
		return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
    if(  me->query_skill("quanzhen_jian", 1) < 40 )
		return notify_fail("���ȫ�潣��������죬����ʹ�ö����롣");
	
    if(  me->query_skill("xiantian_qigong", 1) < 40 &&
		me->query_skill("yunv_xinfa", 1) < 40 )
		return notify_fail("��ı����ڹ�������죬����ʹ�ö����롣");

	if(DIFFERSTR(me->querystr("family/family_name"), "ȫ���") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
    if(  me->query("mp" ) < 150 )
		return notify_fail("����������̫��������ʹ�ö����롣");
	
    msg =   "$N�������Ҽ�����������������������һʽ�������롹бб�̳���\n" ;
	
    if (random(me->query_skill("force")) > target->query_skill("force")/2 )
    {
		me->start_busy(2);
		
		int damage =  me->query_skill("quanzhen_jian", 1) +  me->query_skill("force",1);
		//(ȫ�潣������+�����ڹ�)
		
		damage = damage/2 + random(damage/2);
		
		target->receive_damage("hp", damage);
		if(EQUALSTR(me->querystr("family/family_name"), "ȫ���") && !target->query_temp("ding"))
		{
			target->set_temp("ding", 1);
			target->add_temp("apply/attack", -damage/3);
			target->add_temp("apply/dodge", -damage/3);
			target->call_out( remove_effect, damage/3, damage/3);
			target->SendState(target);
		}
		target->start_busy(4+me->query_skill("quanzhen_jian", 1)/100);
		me->add("mp", -100);
		
		msg +=  "$n����$N������ǧ����һ��������֪����мܣ�" ;
    }
    else
    {
		me->start_busy(3);
		msg +=  "����$p������$P����ͼ��бԾ�ܿ���" ;
    }

    message_vision(msg.c_str(), me, target);
    return 1;
}

static void remove_effect(CContainer *ob,LONG amount,LONG param)
{
	CChar * target=(CChar *)ob;
	target->add_temp("apply/attack", amount);
	target->add_temp("apply/dodge", amount);
	target->delete_temp("ding");
	target->SendState(target);
	message_vision("$HIR$N�����ҵĹ����а����˳�������������,��ס�˽Ų�", target);

}

static int do_flood(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !me->query("teapot/canglang") )
		return notify_fail("����δ����ȫ�潣�����Ͼ�ѧ������ܻ�����Ԫ��ʹ������һ����");

    if( !target || !me->is_fighting(target) )
		return notify_fail("����һ��ֻ�ܶ�ս���еĶ���ʹ�á�");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
    if(  me->query_skill("quanzhen_jian", 1) < 200 )
		return notify_fail("���ȫ�潣��������죬����ʹ�ò���һ����");

	if(DIFFERSTR(me->querystr("family/family_name"), "ȫ���") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
    if(  me->query_skill("xiantian_qigong", 1) < 200 )
		return notify_fail("��ı����ڹ�������죬����ʹ�ò���һ����");
	
    if(  me->query("mp" ) < 3500 )
		return notify_fail("����������̫��������ʹ�ò���һ����");

	if(  me->query("repute" ) < 1000000 )
		return notify_fail("����������̫��������ʹ�ò���һ����");
	
	me->add("mp", -3500);
	
    if (random(me->query("repute")) > target->query("repute"))
    {
		int damage =  me->query_skill("sword") +  me->query_skill("force");
		damage=damage*4;
		damage = damage + random(damage);
		damage=damage*2/3;
		target->receive_damage("hp", damage);
		snprintf(msg, 255, "$N�������ģ����յ���ζ���ɽ�����������ͻ�Ŀ���������һ����������ϵ�����������Ȼ������\n����һ�����������������к��ȫ������$n���ϣ� \n ������%d���˺���",damage);
    }
    else
    {
		snprintf(msg, 255, "$N�������ģ����յ���ζ���ɽ�����������ͻ�Ŀ���������һ����������ϵ�����������Ȼ������\n ���$n��Ȼ��ȣ�����˫������Ϊ��ǽ����ס����һ����");
    }
	me->start_busy(6);
    message_vision(msg, me, target);
    return 1;
}


SKILL_END;
//ɽˮ֮��Ī�˿ɵֵ�
//�۲׺� 
//�ܲ�
//������ʯ���Թ۲׺���ˮ���壣�ɽ����š���ľ�������ٲݷ�ï�������ɪ���鲨ӿ��
//����֮�У��������С��Ǻ����ã���������������գ�����ӽ־