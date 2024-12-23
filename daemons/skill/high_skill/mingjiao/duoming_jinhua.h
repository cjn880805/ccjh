
// duoming_jinhua.h ������
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSduoming_jinhua);

virtual void create()
{
	set_name( "��������");

	Magic_t * magic;

	magic = add_magic("huayu", do_muye);
	magic->name = "���컨��";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenghuo_shengong") || EQUALSTR(arg, "jiuyang_shengong"))
		return 1;

	return notify_fail("��������������ʥ�������ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,parry,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N�鲽������һ�С�������á�������$w����$n��$l", 60, 20, 10, 45, 0, "����",},
		{"$N��ǰ����һ����������Σ�����$wʹ��һʽ�����컨�꡹ֱ��$n��$l", 70, 25, 20, 60, 10, "����",},
		{"$N��������һ�죬������Ȼ����һ��$w��ʹ��һʽ�������ǡ�����$n��$l", 80, 30, 30,70 , 20, "����",},
		{"$N˫ϥ�³�������$wʹ��һʽ���绨ѩ�¡������¶��ϼ���$n��$l", 90, 45, 40, 80, 30, "����",},
		{"$Nһ�С���Ʈ�����$w�Կ��л���һ���󻡣�ƽƽ����$n��$lֱ���ȥ", 100, 55, 55, 90, 40, "����",},
		{"$N����һԾ��������ɣ�һ�С���Ůɢ����������$w������㺮��$n��$l�����ȥ", 110, 65, 75,100 ,50 , "����",},
		{"$N����ת������$wһ����һ�С��ϳ���������$n��$l", 130, 100, 100, 120,80 , "����",},
		{"$Nһ�С�������������$w����������꣬�ֵػ���$n��ȫ��", 200, 200, 200,150 ,100 , "����",},
	};
  		
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("duoming_jinhua", 1))
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
	return (usage == "throwing") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if ( me->query("max_mp") < 200)
		return notify_fail("�������������");
	if ( me->query_skill("throwing", 1) < 20)
		return notify_fail("��İ���������̫ǳ��");
	if ( me->query_skill("shenghuo_shengong", 1) < 50)
		return notify_fail("���ʥ���񹦻��̫ǳ��");
	return 1;

}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
	||  DIFFERSTR(weapon->querystr("skill_type"), "throwing"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if ( me->query("hp") < 50)
		return notify_fail("�����������������������");
	me->receive_damage("hp", 30);
	return 1;

}
//perform 
static int do_muye(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if( me->query_skill("throwing",1) < 100)
		return notify_fail("��İ�������̫��޷�ͬʱ�ų����������");

	if( !( weapon = me->query_weapon()) || DIFFERSTR(weapon->querystr("skill_type"), "throwing") )
		return notify_fail("û�а�������ôʹ�ó����컨�ꡣ");

	if( me->query_skill("duoming_jinhua",1) < 120)
		return notify_fail("��Ķ�����������Ϊ����,Ŀǰ������ʹ�����컨�꣡");

	if(DIFFERSTR(me->querystr("family/family_name"), "����") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( me->query("mp") < 500)
		return notify_fail("���������ڲ���, ����ʹ�����컨�꣡");
	
	if( target->is_busy() )
		return notify_fail( "%sĿǰ���Թ˲�Ͼ���ŵ������� ",target->name());
	
	msg =  "$Nʹ�������������������컨�꡹��$nֻ����ǰ������ã���$n���˸�����ʵʵ��\n";

	me->add("mp", -150);

	if( random(me->query_combat_exp()) >  target->query_combat_exp() / 4 ) 
	{
		msg += "���$p��$P���˸����ֲ�������ʱ�������ã�"  ;
		if(EQUALSTR(weapon->querystr("name"), "��������"))
			target->start_busy(  me->query_skill("duoming_jinhua",1) / 30 + 2);
		else
			target->start_busy(  me->query_skill("duoming_jinhua",1) / 40 + 2);
	} 
	else 
	{
		msg +=   "����$p������$P����ͼ����û���ϵ���"  ;
		me->start_busy(4);
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;
