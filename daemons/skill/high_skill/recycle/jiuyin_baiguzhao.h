// jiuyin_baiguzhao.h �����׹�צ
//code by Fisho
//date : 2000-12-02

SKILL_BEGIN(CSjiuyin_baiguzhao);

virtual void create()
{
	set_name( "�����׹�צ");

	Magic_t * magic;

	magic = add_magic("du", do_du);
	magic->name = "ʩ����";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N��צ��Σ���צ������һ�С�������ǡ�ֱ����$n��$l", 320,10 ,30 ,0 ,"ץ��",},
		{"$N˫��������צ��צצ����$n������������������$n��$lץ��", 380, 20, 45, 20,"ץ��",},
		{"$N����Χ$nһת��ʹ�������޵�������$n��$l����ȫ������צӰ��", 440, 30, 55,40 ,"ץ��",},
		{"$Nʹһ�С������ơ���˫צ�ó�����צӰץ��$nȫ��", 520, 40, 70, 60,"ץ��",},
		{"$N����������һ�С�Ψ�Ҷ���˫צ������$n�������", 620, 50,100 ,100 ,"ץ��",},
	};
	
	int level = 0;
	
	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("jiuyin_baiguzhao", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return usage == "claw" || usage == "unarmed" || usage == "parry";
}

virtual int valid_learn(CChar * me)
{
	if ( me->query_weapon())
		return notify_fail("�������׹�צ������֡�");
	
	if (me->query("max_mp") < 200)
		return notify_fail("�������̫�����޷��������׹�צ��");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if (me->query("mp") < 20)
		return notify_fail("������������������׹�צ��");
	me->receive_damage("hp", 30);
	me->add("mp", -20);
	return 1;
}

virtual void skill_improved(CChar * me)
{
	tell_object(me,  "���Ȼ���ĵ�����һ�ɶ��ɱ��ɱ��ɱ����Ҫɱ�������ˣ�"  );
	me->add("repute", -200);
}

virtual char * hit_ob(CChar *me, CChar *victim, LONG &damage)
{
	if( damage< 100 ) return 0;
	
	if( random(damage/2) > victim->query_str() )
	{
		victim->receive_wound("hp", (damage - 100) / 2 );
		return  "��������������һ�����죬�����ǹ����������" ;
	}
	return 0;
}

//perform 
static int do_du(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || ! me->is_fighting(target) )
		return notify_fail("ʩ��ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if( me->query_skill("bibo_shengong", 1) < 40 )
		return notify_fail("��ı̲��񹦲�����죬����ʩ����");
	
	if( me->query_skill("jiuyin_baiguzhao", 1) < 40 )
		return notify_fail("��ľ����׹�צ������죬����ʩ����");
	
	if( me->query("mp") < 20)		//add By Lanwood 2000-12-25
		return notify_fail("����������㣡");

	msg = "$N����������ָ�ϣ�˫����ָ΢΢�������⣬ץ��$n��\n";
	
	me->start_busy(1);
	if( random( me->query_skill("jiuyin_baiguzhao",1) + 1)  >  random(target->query_skill("dodge") + 1 ) )
	{
		msg +=  " ���$p��$Nץ��һ��������Ѫ�ۣ�" ;
		target->receive_damage("hp",me->query_skill("jiuyin_baiguzhao",1));
		target->receive_wound("hp",15 + random(10));
		target->apply_condition("jy_poison", random(me->query_skill("jiuyin_baiguzhao",1)/5 + 1) + 1 +
			target->query("condition/jy_poison"));
		target->start_busy(random(2));
	} 
	else
	{
		msg += "����$p��æ����һ�ԣ����˿�ȥ��" ;
		me->start_busy(random(4));
	}

	me->add("mp", -20);

	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;
