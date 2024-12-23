// dashou_yin.c ���ڴ���ӡ
SKILL_BEGIN(CSdashou_yin);

virtual void create()
{
	set_name( "���ڴ���ӡ");

	Magic_t * magic;

	magic = add_magic("tianyin", do_tianyin);
	magic->name = "��������ӡ";
	magic->mp = 250;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "xiaowuxiang") || EQUALSTR(arg, "longxiang"))
		return 1;

	return notify_fail("���ڴ���ӡ������ѩɽ�ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, lvl;
	}action[] = {
		{"$Nʹ��һ�С���������ӡ����˫�ƺ�ʮ��ֱֱײ��$n��ǰ��", 150, 0, 0,},
		{"$Nʹ��һ�С����ƹ���ӡ��������Ծ��˫���繴��ץ��$n��$l", 200, 10, 8,},
		{"$Nʹ��һ�С�׼���ĸӡ����������ָ��ֱȡ$n��$l", 250, 5, 16,},
		{"$Nʹ��һ�С���������ӡ����ŭ��һ����һ�Ƶ�ͷ����$n��$l", 300, 5, 24,},

		{"$Nʹ��һ�С�ҩʦ�����ӡ�����ͳ���ǰ�����������㹥��$n", 350, 5, 32,},
		{"$Nʹ��һ�С����½��ӡ������������˫������ɨ��$n��$l", 400, 5, 40,},
		{"$Nʹ��һ�С����ֽ��ӡ���������Ծ��˫��ǰ�������ץ��$n���ʺ�", 450, 10, 48,},
		{"$Nʹ��һ�С������ǻ�ӡ������ʱ��������������г���������Ӱ����$n��$l", 500, 5, 56,},
	};
	int level = me->query_skill("dashou_yin", 1);
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("damage", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="hand" ||  usage=="parry"; }
virtual int valid_combine(string combo) { return combo=="yujiamu_quan"; }
virtual int valid_learn(CChar * me)
{

	if (me->query_weapon())
		return notify_fail("�����ڴ���ӡ������֡�");
	
	if( me->query("max_mp") < 200 )
		return notify_fail("�������������");

	if (me->query_skill("longxiang", 1) >= 20 ||
	    me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	if (me->query_skill("longxiang", 1) < 20)
		return notify_fail("���������������̫ǳ��");
	if (me->query_skill("xiaowuxiang", 1) < 20)
		return notify_fail("���С���๦���̫ǳ��");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("�����ڴ���ӡ������֡�");
	
	if (me->query("hp") < 40)
		return notify_fail("����������������������ڴ���ӡ��");
	me->receive_damage("hp", 20);
	return 1;
}

static int do_tianyin(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	int damage;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||	! me->is_fighting(target) )
		return notify_fail("����������ӡ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if ( me->query_weapon() )
		return notify_fail("�������ֲ���ʹ�á���������ӡ������\n");

	if(DIFFERSTR(me->querystr("family/family_name"), "ѩɽ��") )
		return notify_fail("����Ȼ��˵������������ӡ����һ�У�����ȴδ���ڡ�\n");

	if(me->query_skill("longxiang",1)<120)
		return notify_fail("��������������Ϊ������\n");	

	if(me->query_skill("dashou_yin", 1) < 120 )
		return notify_fail("������ڴ���ӡ��Ϊ����������ʹ�á���������ӡ������\n");

	if(me->query("max_mp")<1000)
		return notify_fail("���������Ϊ̫���޷�ʹ�á���������ӡ������\n");   
	
	if(me->query("mp") < 500 )
		return notify_fail("����������̫��������ʹ�á���������ӡ������\n");
	
	if(me->query_skill("poison",1)<80)
		return notify_fail("��Ķ����������޷�����ͳ��ƶ���\n");

	msg = "$HIY$NĬ���ŭ�䣬������������񹦣����ֶ�Ȼ��������������һ���Ϻ�֮������$n��\n";
	
	if(target->query_temp("apply/��_��������ӡ")&& (!random(3)||wizardp(me)))
	{
		msg+="$HIY$n������������$Nһ�ƻ����ؿ�֮�ϣ�ֻ�����һ����$N�����������������ء�\n$Nʧ�����У�����ղ������񹦡���\n";
		me->start_busy(2);
		damage = 100+random(me->query_skill("dashou_yin",1)+me->query_skill("longxiang",1)+me->query_skill("poison",1));
		damage = damage + random(damage/2);
		me->receive_damage("hp", damage);
		me->receive_wound("hp", damage/3);
		me->add("mp", -damage/3);
		if(me->query("mp")<0)
			me->set("mp",0l);
		me->apply_condition("dsy_poison", random(me->query_skill("poison")/10) + 1 +target->query_condition("dsy_poison"));
		message_vision(msg.c_str(), me, target);
		return 1;
	}	      
	
	if (random(me->query("combat_exp")) > target->query("combat_exp")/2 )
	{
		me->start_busy(3);
		target->start_busy(random(3));
		damage = 100+random(me->query_skill("dashou_yin",1)+me->query_skill("longxiang",1)+me->query_skill("poison",1));
		if (me->query_str() > target->query_con())
			damage = random( (damage*me->query_str())/5 )+100;
		else
			damage = damage + random(damage/2);
		
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/3);
		me->add("mp", -damage/3);
		if(me->query("mp")<0)
			me->set("mp",0l);

		if ( me->query_skill("poison",1) > target->query_skill("poison",1) )
			target->apply_condition("dsy_poison", random(me->query_skill("poison")/10) + 1 +target->query_condition("dsy_poison"));
		else
			target->apply_condition("dsy_poison", random(me->query_skill("poison")/5) + 1 +	target->query_condition("dsy_poison"));
		
		if( damage < 100 )
			msg += "$HIY$n�������֣����Ƶ���������������Ϥ�����⡣\n";
		else if( damage < 300 ) 
			msg += "$HIY$n������������$NӲƴ��һ�ƣ��䲻�Կ������ظ�֮����Ѫ��ӿ�Ѽ��ǲ������\n";
		else if( damage < 500 )
			msg += "$RED$n��ǿ��˫�ֻ�����У�����$N������ŭ������ԴԴ������Ю��һ������ֱ͸$n���ܣ�\n";
		else 
			msg += "$HIR$n�������ܣ���$N����һ����ӡ���ؿ�����������$nֻ��������ɢ����һ����Ѫ���������\n";
	}
	else 
	{
		me->start_busy(3);
		
		msg += "$CYN����$p�������أ����������罫$P��������Ϊ���Ρ�\n";
	}
	message_vision(msg.c_str(), me, target);

	return 1;
}

SKILL_END;
