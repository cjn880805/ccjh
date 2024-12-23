// smithsword.h �����ؽ�ʽ
//code by Teapot @ 2001-03-19
// CCJH����Ӽ���,grin

SKILL_BEGIN(CSsmithsword);

virtual void create()
{
	set_name( "�����ؽ�ʽ");
	
	Magic_t * magic;
	
	magic = add_magic("flood", do_flood);
	magic->name = "������";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "yunv_xinfa") || EQUALSTR(arg, "seaforce"))
		return 1;
	
	return notify_fail("�����ؽ�ʽ�������Ĺ�����ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,parry,damage,lvl;
		char damage_type[5];
	}action[6] = {
		{"$N����$w���д�����֮��ѹ��$n��", 380, 35, 30,175 , 139, },
		{"$N����$w�������������ش�$n��", 380, 35, 30,175 , 149, },
		{"$N����$w���Գ�ˮ��ӿ֮������$n��", 380, 35, 30,175 , 159, },
		{"$N����$w���д�����֮��ѹ��$n��", 380, 35, 30,175 , 169, },
		{"$N����$w���Ծ���ʮ�ص����ƶ�$n��ȥ��", 380, 35, 30,175 , 179,},
		{"$N����$w����������������$n��", 380, 35, 30,175 , 189,},
	};
	
	int level = 0;
	
	int ml;
	ml=me->query_skill("smithsword",1);
	
	for(int i=6; i > 0; i--)
	{
		if(action[i - 1].lvl < ml)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("parry", action[level].parry);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	
	if (ml<140)	// 0~10
		m_actions.set("action", "$N����$w,��ϸ΢�Ʒ�֮������$n��");
	if (ml<130)	// 10~20
		m_actions.set("action", "$N����$w,������֮������$n��");
	if (ml<120)	// 0~10
		m_actions.set("action", "$N����$w,��ϸ΢�Ʒ�֮������$n��");
	if (ml<110)	// 10~20
		m_actions.set("action", "$N����$w,������֮������$n��");
	if (ml<100)	// 0~10
		m_actions.set("action", "$N����$w,��ϸ΢�Ʒ�֮������$n��");
	if (ml<90)	// 10~20
		m_actions.set("action", "$N����$w,������֮������$n��");
	if (ml<80)	// 0~10
		m_actions.set("action", "$N����$w,��ϸ΢�Ʒ�֮������$n��");
	if (ml<70)	// 10~20
		m_actions.set("action", "$N����$w,������֮������$n��");
	if (ml<60)	// 0~10
		m_actions.set("action", "$N����$w,��ϸ΢�Ʒ�֮������$n��");
	if (ml<50)	// 10~20
		m_actions.set("action", "$N����$w,������֮������$n��");
	if (ml<40)	// 0~10
		m_actions.set("action", "$N����$w,��ϸ΢�Ʒ�֮������$n��");
	if (ml<30)	// 10~20
		m_actions.set("action", "$N����$w,������֮������$n��");
	if (ml<20)	// 0~10
		m_actions.set("action", "$N����$w,��ϸ΢�Ʒ�֮������$n��");
	if (ml<10)	// 10~20
		m_actions.set("action", "$N����$w,������֮������$n��");
//	�����޶��죬�����췵�ޣ������ߴζ���������������죬�������ޡ�
	
	CContainer * weapon;
	weapon = me->query_weapon();
	if (! weapon || weapon->Query_Weight()<80000 || ml<80)
	{
		if(userp(me))
		{
			m_actions.set("action", "$N����$w����$n��ȴ�·�������֮������Ȼ$w̫���ˡ�����");
			m_actions.set("force", 0l);
			m_actions.set("dodge", 0l);
			m_actions.set("parry", 0l);
			m_actions.set("damage",0l);
		}
	}
	
	if (me->query_temp("teapot/smithwave"))
		m_actions.set("action", "$HIB$Nʹ�������ؽ�ʽ�С������������������������\n����$w��������������������$n��$COM");
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query_skill("seaforce", 1) < 30)
		return notify_fail("��Ŀ��ķ���򲻵����޷�ѧϰ�����ؽ�ʽ��");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon()) 
        || DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if (me->query("hp") < 30)
		return notify_fail("������������������ؽ�ʽ��");
	if (me->query("mp") < 30)
		return notify_fail("��������������������ؽ�ʽ��");
	if (DIFFERSTR( ( me->environment())->querystr("base_name"), "�ƺ��뺣��" ))
	{
//		me->receive_wound("hp", 30);
		me->add("hp",-30);
		me->add("mp",-30);
	}
	else
	{
		me->receive_wound("hp", 3);
		me->add("mp",-1);
	}
	
	return 1;
}

//perform 
static int do_flood(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
    if( !target || !me->is_fighting(target) )
		return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�");
	
    if( me->query_skill("smithsword", 1) < 200 )
		return notify_fail("��������ؽ�ʽ������죬����ʹ�ñ�������");

	if(DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
    if( me->query("mp") < 1300 )
		return notify_fail("����������̫��������ʹ�ñ�������");
	
	me->add("mp",-1300);
	
	int extra;
	extra = me->query_skill("sword");
	
//	me->add_temp("apply/damage",extra*2);
	me->add_temp("apply/damage",extra/2);
	me->add_temp("apply/attack",extra);
	me->set_temp("teapot/smithwave",1);
//	g_Combatd.Do_Attack(me,target, CCombatd::TYPE_REGULAR);
	message_vision("\n$MAG��һ�����ƺ�֮ˮ��������$COM\n" ,me,target);
	if(target->query_temp("apply/no_������") && !random(2))
	{
		message_vision("����$n������$N����ͼ����û���ϵ���\n" ,me,target); 
	}
	else
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_REGULAR);

	if (me->query("combat_exp")> target->query("combat_exp")/2 )
	{                
		message_vision("\n$RED�ڶ����������ԹŲ�������$COM\n" ,me,target);
		if(target->query_temp("apply/no_������") && !random(2))
		{
			message_vision("����$n������$N����ͼ����û���ϵ���\n" ,me,target); 
		}
		else
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_REGULAR);
	}

	if(EQUALSTR(me->querystr("family/family_name"), "��Ĺ��"))
	{
		if (me->query("combat_exp")> target->query("combat_exp") )
		{                
			message_vision("\n$HIY����������Ը����Ը�ѣ�$COM\n" ,me,target);
			if(target->query_temp("apply/no_������") &&  (!random(2)||target->query("bigboss")))
			{
				message_vision("����$n������$N����ͼ����û���ϵ���\n" ,me,target); 
			}
			else
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_REGULAR);
		}
		
		if (me->query("combat_exp")> target->query("combat_exp")*3 )
		{                
			message_vision("\n$HIR���Ľ������ͬ����ų$COM\n" ,me,target);
			if(target->query_temp("apply/no_������") && (!random(2)||target->query("bigboss")))
			{
				message_vision("����$n������$N����ͼ����û���ϵ���\n" ,me,target); 
			}
			else
				g_Combatd.Do_Attack(me, target, CCombatd::TYPE_REGULAR);
		}
	}

	me->delete_temp("teapot/smithwave");
	me->add_temp("apply/damage",-extra/2);
//	me->add_temp("apply/damage",-extra*2);
	me->add_temp("apply/attack",-extra);
	me->start_busy(3);

	
	return 1;
}

SKILL_END;
