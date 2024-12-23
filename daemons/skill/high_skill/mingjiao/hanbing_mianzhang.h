
// hanbing_mianzhang.h ��������
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CShanbing_mianzhang);

virtual void create()
{
	set_name( "��������");

	set("valid_force", "shenghuo_shengong");

	Magic_t * magic;

	magic = add_magic("xixue", do_xixue);
	magic->name = "��Ѫ����";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  dodge,force,lvl;
		char damage_type[5];
	}action[] = {
		{"$N˫�Ƽ��ף�һʽ�����ֺ�˪�����ֱ�ͻȻ����һ����£�����$n��ȫ��", 10, 150,0,"����",},
		{"$N˫�Ⱥϲ���������������һʽ���纮��ͷ��������ֱ�£�����$n��ͷ����", 5, 160,10,"����",},
		{"$N���ƻ��أ�һʽ����¶Ϊ˪��������ֱ�߻���������$n����ǰ��Ѩ��",5 , 170,20,"����",},
		{"$Nʹһʽ����÷�׷ɡ���˫�����಻�����ĳ����ƶ��ѩ�к�÷����$n��", -5, 185,50,"����",},
		{"$N����һ��������ȭ�����󷢣�һʽ���캮�ض�����һ�ɺ�����������$n��$l��", 10, 200,100,"����",},
		{"$Nʹһʽ������ѩ�ء���˫��ͻ�ı��ѩ�ף�һǰһ���͵�����$n��$l��", 5, 220,200,"����",},
		{"$N˫Ŀ΢�ţ�һʽ��ѩ���׷ɡ���˫�ƻ���ƬƬѩ��������$n��$l��", 5, 220,250,"����",},
		{"$N���ϸ߸�Ծ��һʽ��������꡹���Ӹ����£������Ʊ���������$n��ȫ��", 20, 240,300,"����",},
	};
	
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("hanbing_mianzhang", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("force", action[level].force);
			m_actions.set("damage", action[level].force);
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
		return notify_fail("���������Ʊ�����֡�");
	if ( me->query_skill("shenghuo_shengong", 1) < 50)
		return notify_fail("���ʥ���񹦻�򲻹����޷����������ơ�");
	if ( me->query("max_mp") < 300)
		return notify_fail("�������̫�����޷�����������");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if ( me->query("mp") < 8)
		return notify_fail("��������������������ơ�");
	if (me->query_skill("hanbing_mianzhang", 1) < 50)
		me->receive_damage("hp", 20);
	else
		me->receive_damage("hp", 30);
	me->add("mp", -5);
	return 1;
	
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage )
{
	if( random(me->query_skill("shenghuo_shengong")) > 10 ) 
	{
		victim->apply_condition("ice_poison", random(me->query_skill("shenghuo_shengong")/10) + 1 +
			victim->query("condition/ice_poison"));
	}
	return "";
}

//perform 
static int do_xixue(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	int skill = me->query_skill("hanbing_mianzhang",1);

	if(ob && ob->is_character())
		target = (CChar *) ob;
	
	if(!target || ! me->is_fighting(target))
		return notify_fail("����Ѫ����ֻ�ܶ�ս���еĶ���ʹ�á�");

	if(DIFFERSTR(me->querystr("family/family_name"), "����") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if ( me->query_weapon())
		return notify_fail("��ʹ����������");
	
	if( skill < 60)
		return notify_fail("��ġ��������ơ��ȼ�����, ����ʹ�á���Ѫ���𡹣�");

	if(me->query("mp") < 100)		//add by Lanwood 2000-12-26
		return notify_fail("����������㡣");
	
	if( me->query_skill("dodge",1) < 150 )
		return notify_fail("����Ṧ�������޷����á���Ѫ���𡹣�");
	
	msg =  "\n$HIR$NͻȻ��ͬ����Ѫ���𡹣��۽�$n����ǰ���������$n���ʺ�ҧȥ��\n";
		
	LONG ap = me->query_combat_exp() + skill * 400;
	LONG dp = target->query_combat_exp() / 2;
	if( dp < 1 )
		dp = 1;		
	if( random(ap) > dp )
	{
		me->add("mp",-100);
		
		msg +=  "$HIR$nֻ�����ʺ�һ���ʹ��$N���ڿ���$n����Ѫ��";
		int neili_wound = 100 + random(skill);
		if(neili_wound > target->query("mp"))
			neili_wound = target->query("mp");
		
		int qi_wound = neili_wound * 5;
		if(qi_wound > target->query("hp"))
			qi_wound = target->query("hp");
		
		target->add("mp", -neili_wound);
		target->add("hp", -qi_wound);
		target->start_busy(2);
		me->start_busy(random(2));
	}
	else
	{
		msg +=  "ֻ��$n���Ų�æ������һ���������$N�����ݣ�";
		me->add("mp",-100);
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);
 	return 1;
}

SKILL_END;
