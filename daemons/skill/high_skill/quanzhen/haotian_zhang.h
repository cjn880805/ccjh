
// haotian_zhang.h ������
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CShaotian_zhang);

virtual void create()
{
	set_name( "�����");

	set("diff",100);

	Magic_t * magic;

	magic = add_magic("ju", do_ju);
	magic->name = "�����۶�";
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
		{"$Nʹһ�С�������ˮ����˫�ֻ��˸���Ȧ������$n��$l", 100, 50, 5, 0,"����",},
		{"$Nʹһ�С��������¡�����������һ�ӣ�����$n��$l", 120, 48, 10,5 ,"����",},
		{"$N�����������⣬��������ʹһ�С������沨������$n��$l��ȥ", 140, 46, 15, 10,"����",},
		{"$Nʹһ�С�������ת�����ֻ�$n���ؿں�$l", 160, 44, 20,15 ,"����",},
		{"$Nʹһ�С����ջ��֡���������ͬʱ�������ڿ���ͻȻ�����Ʒ��򻥱�", 180, 42, 25, 20,"����",},
		{"$N���ֲ�ס�ζ�������һ�С�������˪������$n��$l��ȥ", 200, 40, 30, 25,"����",},
		{"$N���ֱ���Ϊ�ģ����������絶��һ�С�͡�ϰ�ɳ��������$n��$l", 220, 38, 35, 30,"����",},
		{"$N����˺�벽������ʹһ�С�����һɫ���������$n", 240, 36, 40,35 ,"����",},
		{"$Nһ�С�����¡��������ȷ������������ƺ󷢶�����", 260, 34, 45, 40,"����",},
		{"$N˫���������У�˫�����ɨ��$n��$l��ȴ��һ�С�������ˮ������̬����", 280, 32, 50, 45,"����",},
		{"$N�����鰴�����ֻ�������ʹһ�С��������ơ�����$n��$l��ȥ", 300, 30, 56, 50,"����",},
		{"$N˫�ֱ�����ȭ����ǰ��󻮻���һ�С�������ϡ�����$n��$l", 320, 28, 62,55 ,"����",},
		{"$N�����黮�����ֱ���Ϊ��һ�ǡ�¥����ء�����$n��$l", 340, 26, 68, 60,"����",},
		{"$Nʩ���������С�����������ӳ�������ͬʱ����$n",360 , 24, 74, 65,"����",},
		{"$N�ɱ۴��֣�����ǰ����������ʹһ�С����㳤�ɡ�������$n��$l", 380, 22, 81, 70,"����",},
		{"$N����͵أ�����ʹһ�С�����ǱԾ�������¶�����$n��$l��ȥ", 400, 20, 88, 75,"����",},
		{"$N�����ɹ����ƣ�˫���������ϣ�������ǰ�Ƴ�һ�С��»����ա�", 420, 18, 98, 80,"����",},
		{"$N���Ʋ�ס����ɨ������һʽ����̶�仨����������ת����$n��ȥ", 440, 16, 110, 85,"����",},
		{"$N���־���ǰ��������ǰƲ����ʹһ�С���ˮ����������$n��$l��ȥ", 460, 14, 120, 90,"����",},
		{"$Nʹһ�С�б�³���������������������Ȧ�����ƴ�Ȧ�д�������$n", 480, 12, 130, 95,"����",},
		{"$N�������ϻ�������������ʹһ�С���ʯ���桹�����Ʋ�ס�ζ�������$nͷ������֮��", 500, 10, 150, 100,"����",},
	};
	
	int level = 0;
	
	for(int i=21; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("haotian_zhang", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
*/
			m_actions.set("force", (me->query("skill_pro/ȫ����/�����/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/ȫ����/�����/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/ȫ����/�����/damage")+100) * action[level].damage/100);
			
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
			me->add("skill_pro/ȫ����/�����/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/ȫ����/�����/force"));
			if(me->query("skill_pro/ȫ����/�����/force_point")>=level_point)
			{
				me->add("skill_pro/ȫ����/�����/force",1);
				me->set("skill_pro/ȫ����/�����/force_point",1);
				tell_object(me,"\n$HIR������������ڹ������ڻ��ͨ�ˡ�\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/ȫ����/�����/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/ȫ����/�����/dodge"));
			if(me->query("skill_pro/ȫ����/�����/dodge_point")>=level_point)
			{
				me->add("skill_pro/ȫ����/�����/dodge",1);
				me->set("skill_pro/ȫ����/�����/dodge_point",1);
				tell_object(me,"\n$HIR��������ʹ�õø��ӵ���Ӧ���ˡ�\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/ȫ����/�����/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/ȫ����/�����/damage"));
			if(me->query("skill_pro/ȫ����/�����/damage_point")>=level_point)
			{
				me->add("skill_pro/ȫ����/�����/damage",1);
				me->set("skill_pro/ȫ����/�����/damage_point",1);
				tell_object(me,"\n$HIR�����������������ˡ�\n");
			}
		}
	}
	return "";
}

virtual int valid_combine(string combo) { return combo=="sun_finger"; }

virtual int valid_enable(string usage) 
{ 
	return (usage == "strike") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon()  )
		return notify_fail("������Ʊ�����֡�");
	if ( me->query_skill("xiantian_qigong", 1) < 10)
		return notify_fail("�������������򲻹����޷�ѧ����ơ�");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if ( me->query("mp") < 20)
		return notify_fail("�����������������ơ�");
	me->receive_damage("hp", 25);
	me->add("mp", -10);
	return 1;
	
}

//perform 
static int do_ju(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("�����۶�ֻ�ܶ�ս���еĶ���ʹ�á�");
	
    if(  me->query_skill("haotian_zhang", 1) < 50 )
		return notify_fail("�������Ʋ�����죬����ʹ�������۶���");

	if(DIFFERSTR(me->querystr("family/family_name"), "ȫ���") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if (me->query_weapon()  )
		return notify_fail("�������֡�");	

    if(  me->query_skill("xiantian_qigong", 1) < 50 )
		return notify_fail("������칦������죬����ʹ�������۶���");
	
    if(  me->query("mp") < 150 )
		return notify_fail("����������̫��������ʹ�������۶���");
	
    msg =   "$N���һ����������$n���ϣ�˫��ͬʱ��������һ�С������۶�����" ;
	
   // if( !target->is_fighting(me) ) target->kill_ob(me);
	
    if (random(me->query_skill("force")) > target->query_skill("force")/2 )
    {
		me->start_busy(1);
		
		int damage =  me->query_skill("haotian_zhang", 1) +  me->query_skill("force",1);
		//(����Ƽ���+�����ڹ�)
		
		damage = damage/2 + random(damage/2) ;
		target->receive_damage("hp", damage);
		target->start_busy(3);
		me->add("mp", -100);
		msg +=  "���$n��$N���������㣬һ��֮�£���Ȼ���˵ֵ���" ;
    }
    else
    {
		me->start_busy(3);
		msg +=  "����$pʶ����$P��һ�У�ббһԾ�ܿ���" ;
    }
    message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;
