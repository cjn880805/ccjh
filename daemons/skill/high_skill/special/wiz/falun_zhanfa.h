// hualun_zhanfa.h ת�����Ʒ�
//code by Teapot
//date : 2001-02-06

SKILL_BEGIN(CSfalun_zhanfa);

virtual void create()
{
	set_name( "ת�����Ʒ�");

	Magic_t * magic;

	magic = add_magic("zhen", do_zhen);
	magic->name = "��";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("shan", do_shan);
	magic->name = "��";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("ren", do_ren);
	magic->name = "��";
	magic->mp = 600;
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
		{"$N˫��һ��һ�С�������תʽ���ó�������Ӱ£��$n��$l", 200, 10, 0, "����",},
		{"$N˫�Ʒ׷ɣ�һ�С����ַ���ʽ��ֱȡ$n��$l", 210, 15, 10, "����",},
		{"$N����һ����˫�������Ƴ���һ�С���������ʽ��ǿ�����Ʒ�ֱ��$n��$l", 220, 20, 20, "����",},
		{"$Nʹ��ת�����Ʒ��еġ������ޱ�ʽ������ȫ��$n��$l������˫��֮��", 235, 35, 30, "����",},
		{"$N����Ϊ����һ�С�����Ǭ��ʽ���������Ʒֿ�$n������Ҫ��", 250,30 , 40, "����",},
		{"$N�������ᣬȫ�����һ�С���������ʽ����˫���������", 325,35 , 50, "����",},
		{"$N�������ߣ�һ�С����ֺ�־ʽ����ɭɭ�Ʒ��޿ײ����ػ���$n��$l", 375, 20, 60, "����",},
		{"$Nʹ��ת�����Ʒ��еġ��������ʽ��˫��Я��س���֮������$n��$l", 400, 35, 70, "����",},
	};

	int level = me->query_skill("falun_zhanfa", 1);
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "strike") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
    if (me->query_weapon()  )
		return notify_fail("��ת�����Ʒ�������֡�");
    if ( me->query_skill("falun_gong", 1) < 10)
		return notify_fail("��ĳ��ִ󷨻�򲻹����޷�ѧת�����Ʒ���");
    if ( me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷���ת�����Ʒ���");
    return 1;
	
}

virtual int practice_skill(CChar * me)
{
    if ( me->query("mp") < 4)
		return notify_fail("�������������ת�����Ʒ���");
    me->add("mp", -4);
	return 1;
	
}


//perform 
static int do_zhen(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("���־�ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if( !me->query("falun/know") || me->query("falun/know")<30)
		return notify_fail("����δ������ִ󷨵ġ��桹�֡�");
	
	if(  me->query_skill("falun_gong", 1) < 30 )
		return notify_fail("��ĳ��ִ󷨲�����죬����ʹ�á��桹�־���");
	
	if(  me->query_skill("falun_zhanfa", 1) < 30 )
		return notify_fail("���ת�����Ʒ������ߣ�����ʹ�����桹�־���");

	if( me->query("mp") < 200)	
		return notify_fail("����������㡣");
	
	msg =   "$NĬ��ת�����ķ���ʹ�����֡��桹�־������������˵��һ��ƪ����\n" ;
	
	if (random(me->query_skill("strike")) > random(target->query_skill("force")) )
	{
		
		int damage =  me->query_skill("falun_zhanfa", 1); 
		damage = damage/2 + random(damage);
		
		target->receive_wound("hp", damage);
		me->add("mp", -200);

		msg +=  "$n����$N˵��˵��һͷ��ˮ��Խ��Խ�Σ����մ��һ�����һ����Ѫ��" ;
	} 
	else
	{
		me->add("mp", -200);
		msg +=  "����$p��Цһ������$P��֮�����Թ˽�����" ;
	}
	message_vision(msg.c_str(), me, target);
	me->start_busy(2);
	return 1;
}

static int do_shan(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("���־�ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if( !me->query("falun/know") || me->query("falun/know")<60)
		return notify_fail("����δ������ִ󷨵ġ��ơ��֡�");
	
	if(  me->query_skill("falun_gong", 1) < 60 )
		return notify_fail("��ĳ��ִ󷨲�����죬����ʹ�á��ơ��־���");
	
	if(  me->query_skill("falun_zhanfa", 1) < 60 )
		return notify_fail("���ת�����Ʒ������ߣ�����ʹ�����ơ��־���");

	if( me->query("mp") < 400)	
		return notify_fail("����������㡣");
	
	msg =   "$NĬ��ת�����ķ���ʹ�����֡��ơ��־���һ������㡰�ơ���$n��\n" ;
	
	if (random(me->query_skill("strike")) > random(target->query_skill("force")) )
	{
		
		int damage =  me->query_skill("falun_zhanfa", 1); 
		damage = damage/2 + random(damage);
		
//		target->apply_condition("sanxiao_poison", 20);
		target->apply_condition("bingpo_poison", 20);
		target->receive_wound("hp", damage);
		me->add("mp", -400);

		msg +=  "$nһ��С�ı�$N���У�ֻ��������һ���ʹ���ֽ���ת�飬ԭ�����д���һ���ж����룡" ;
	} 
	else
	{
		me->add("mp", -400);
		msg +=  "����$p����Ʈ����$Pһ�ƴ����Լ����ϣ��ҽ�һ����ԭ�����м���һ�����룡" ;
		me->receive_wound("hp", random(200));
		me->apply_condition("bingpo_poison", 20);
	}
	message_vision(msg.c_str(), me, target);
	me->start_busy(2);
	return 1;
}


static int do_ren(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("���־�ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if( !me->query("falun/know") || me->query("falun/know")<90)
		return notify_fail("����δ������ִ󷨵ġ��̡��֡�");
	
	if(  me->query_skill("falun_gong", 1) < 90 )
		return notify_fail("��ĳ��ִ󷨲�����죬����ʹ�á��̡��־���");
	
	if(  me->query_skill("falun_zhanfa", 1) < 90 )
		return notify_fail("���ת�����Ʒ������ߣ�����ʹ�����̡��־���");

	if( me->query("mp") < 600)	
		return notify_fail("����������㡣");
	
	msg =   "$NĬ��ת�����ķ���ʹ�����֡��̡��־�������ĳ�$nһЦ��\n" ;
	
	if (random(me->query_skill("strike")) > random(target->query_skill("force")) )
	{
	me->start_busy(2);
		
		int damage =  me->query_skill("falun_zhanfa", 1); 
		damage += me->query_skill("strike");
		damage = damage/2 + random(damage);
		
		target->apply_condition("sanxiao_poison", 10);
		target->receive_wound("hp", damage);
		me->add("mp", -600);

		msg +=  "$nĪ�����ͻȻ��Ȼ����������Ҳ����һЦ��Ȼ���ʱ���ø�������һ�������ڽʣ�" ;
	} 
	else
	{
	me->start_busy(3);
		me->add("mp", -600);
		msg +=  "����$p�����ϵ������ɶ㿪���ֵ�$P�Լ���æ���ҡ�" ;
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}


SKILL_END;


