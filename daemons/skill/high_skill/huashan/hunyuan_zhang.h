// hunyuan_zhang.h ��Ԫ��
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CShunyuan_zhang);

virtual void create()
{
	set_name( "��Ԫ��");
	set("valid_force", "zixia_shengong");

	
	Magic_t * magic;

	magic = add_magic("wuji", do_wuji);
	magic->name = "��Ԫ�޼�";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,parry,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$Nһʽ�����Ƴ�ᶡ���˫�Ƽ�����һ�ŵ����İ�����������$n��$l", 180,5 , 20, 10, 0,"����",},
		{"$N��ָ�罣��һʽ���׺���ա�������$n��$l��ȥ", 220, 10,15 , 20, 10,"����",},
		{"$Nʹһʽ���ƶ����롹������΢��������է��է�ϣ��͵ز���$n��$l", 260, 15, 20, 30, 20,"����",},
		{"$N˫����������������һʽ�����ɴ�䡹���ó�������̵����룬������$n��ȥ", 300, 20,30 , 40,30 ,"����",},
		{"$N��������һ�ݣ�ʹ��һʽ������������˫�Ʋ�£����ֱ����$n��$l��ȥ", 340, 25, 20,50 , 40,"����",},
		{"$N����һ�䣬ʹһʽ���ޱ���ľ����˫�ƴ�����ɲ�ľ������͵ػ���$n��$l",380 , 25, 25, 60, 50,"����",},
		{"$Nʹһʽ����ɽ��ˮ�����������أ�������ӯ��ͬʱ��$n��$l��ȥ", 420, 30, 30, 70, 60,"����",},
		{"$Nͻ��һ�С��������á���˫��Ю��һ�����֮�ƣ��͵�����$n��$l",460 ,30 , 35,80 ,70 ,"����",},
		{"$Nһʽ��������ơ���˫�������һ����裬�����ѻ���$n��$l��", 500, 40, 45, 90, 80,"����",},
		{"$Nһʽ������Ʈ�졹����������������˫��һ��һ�ͣ����Ƽ򵥣�ȴ��$n�޷�����", 540,45 , 50, 110,90 ,"����",},
	};
 		
	int level = 0;
	
	for(int i=10; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("hunyuan_zhang", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "unarmed") || (usage == "parry")|| (usage=="strike");
}

virtual int valid_combine(string combo) { return combo=="poyu_quan"; }


virtual int valid_learn(CChar * me)
{
	if (me->query_weapon() )
		return notify_fail("����Ԫ�Ʊ�����֡�");
	if ( me->query_skill("zixia_shengong", 1) < 20)
		return notify_fail("�����ϼ�񹦻�򲻹����޷�ѧ��Ԫ�ơ�");
	if ( me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷�����Ԫ�ơ�");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if ( me->query("mp") < 40)
		return notify_fail("���������������Ԫ�ơ�");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

//perform 
static int do_wuji(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	int skill = me->query_skill("hunyuan_zhang",1);
	
	if( !target || ! me->is_fighting(target))
		return notify_fail("����Ԫ�޼���ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if ( me->query_weapon())
		return notify_fail("��ʹ����������");

	if(DIFFERSTR(me->querystr("family/family_name"), "��ɽ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( skill < 60)
		return notify_fail("��ġ���Ԫ�ơ��ȼ�����, ����ʹ�á���Ԫ�޼�����");
	
	if( me->query("mp") < 150 )
		return notify_fail("��������������޷����á���Ԫ�޼�����");
	
	msg =   "$NǱ�ˡ���Ԫ�޼�����˫ȭЮ�������ķ���֮����$n��ȥ��\n" ;
		
	LONG ap = me->query_combat_exp() + skill * 400;
	LONG dp = target->query_combat_exp() / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		me->add("mp",-100);
		
		msg +=  "$nֻ������ǰһ���ʹ�����ۡ���һ�����һ����Ѫ��" ;
		int neili_wound = 100 + random(skill);
		if(neili_wound > target->query("mp"))
			neili_wound = target->query("mp");
		
		int qi_wound = neili_wound * 5;
		if(qi_wound > target->query("hp"))
			qi_wound = target->query("hp");
		
		target->add("mp", -neili_wound);
		target->add("hp", -qi_wound);
		target->start_busy(2);
		target->UpdateMe();
		me->start_busy(random(2));
	}
	else
	{
		msg +=  "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����" ;
		me->add("mp",-100);
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);
 	return 1;
}

SKILL_END;
