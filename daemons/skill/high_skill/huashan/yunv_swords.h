
// yunv_swords.h ��Ů����
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSyunv_swords);

virtual void create()
{
	set_name( "��Ů����ʮ����");
	set("valid_force", "zixia_shengong");

	Magic_t * magic;

	magic = add_magic("wushuang", do_wushuang);
	magic->name = "��˫�޶�";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$Nʹһ�С��������ߡ�����̤�й�������$wֱָ$n$l", -50, 170,0,"����",},
		{"$N������ת��һ�С������޷졹������һƬ��Ӱ������$n��$l",-30 , 180,1,"����",},
		{"$N�趯$w��ʹ��һ�С�ҹ��ԧ�졹���������ң���˸������ֱ��$n��$l", -40, 190,2,"����",},
		{"$Nһ�����ȣ�������֯Ů���󡹣�����$w��Ϊһ�����⣬����$n��$l", -40, 160,3,"����",},
		{"$N��Ȼ����ֱ�ϣ�һ�С�С�����ˡ�������$w�������ϴ���$n��$l",-50 , 190,4,"����",},
	};
	
	int level = 0;
	
	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("yunv_swords", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
    CContainer * ob;
	if( DIFFERSTR(me->querystr("gender"), "Ů��") )
		return notify_fail("��Ů����ʮ������ֻ��Ů�Ӳ��������书��");
    if( me->query("max_mp") < 50 )
		return notify_fail("�������������û�а취����Ů����ʮ������") ;
	if( DIFFERSTR(me->query_skill_mapped("force"), "zixia_shengong"))
		return notify_fail("��Ů����ʮ�������������ϼ�񹦲�������");
	if( !(ob = me->query_weapon())
		|| DIFFERSTR(ob->querystr("skill_type"), "sword") )
		return notify_fail("���������һ�ѽ�������������");
	
    return 1;
}

virtual int practice_skill(CChar * me)
{
    if( me->query("hp") < 30
		||  me->query("mp") < 5 )
		return notify_fail("�����������������û�а취��ϰ��Ů����ʮ������");
    me->receive_damage("hp", 30);
    me->add("mp", -5);
    tell_object(me,"�㰴����ѧ����һ����Ů����ʮ������", "practice");
    return 1;
}

//perform 
static int do_wushuang(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target	||	!me->is_fighting(target) )
		return notify_fail("��˫�޶�ֻ�ܶ�ս���еĶ���ʹ�á�");

	if(DIFFERSTR(me->querystr("family/family_name"), "��ɽ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if( me->query_skill("yunv_swords", 1) < 40 )
		return notify_fail("�����Ů����ʮ����������죬����ʹ�á���˫�޶ԡ���");
	
	if( me->query_skill("zixia_shengong", 1) < 40 )
		return notify_fail("�����ϼ�񹦲�����죬����ʹ�á���˫�޶ԡ���");
	
	if( me->query("mp") < 300  ) 
		return notify_fail("�������������");
	
	if( me->query_temp("hsj_wu") ) 
		return notify_fail("���Ѿ����˹����ˡ�");
	
	msg = "$N˫������";
	msg += weapon->name();
	msg += "����â������һʽ����˫�޶ԡ���Ԧ�����Ҿ��׵���$n��̣�\n";

	message_vision(msg.c_str(), me, target);
	
	int skill = me->query_skill("yunv_swords",1);
	if(!me->query_temp("tjj_sui") && !me->query_temp("qzj_tong") && !me->query_temp("hsj_wu") && !me->query_temp("hmg_dzjm"))
	{
		me->add_temp("apply/attack", skill/3);
		me->add_temp("apply/dodge", -skill/4);
		me->set_temp("hsj_wu", 1);
		
		me->call_out( remove_effect, 2, skill/3, skill/4);
	}
	me->add("mp", -100);
	return 1;
}

static void remove_effect(CContainer *ob,LONG amount,LONG amount2)
{
	CChar *me = (CChar *) ob;

	me->add_temp("apply/attack", -amount);
	me->add_temp("apply/dodge", amount2);
	me->delete_temp("hsj_wu");

	me->SendState();
	me->start_busy(4);
}

SKILL_END;
