
// xianglong_zhang.c ����ʮ����
//code by Fisho
//date : 2000-12-05


SKILL_BEGIN(CSxianglong_zhang);

virtual void create()
{
	set_name("����ʮ����");

	Magic_t * magic;

	magic = add_magic("leiting", do_leiting);
	magic->name = "����һ��";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("xianglong", do_xianglong);
	magic->name = "������";
	magic->mp = 300;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  dodge,parry,force;
		char damage_type[5];
	}action[] = {
		{"$Nʹ����ͻ�������������ƴӲ����ܵĽǶ���$n��$l�Ƴ�",0 ,10 , 130,"����",},
		{"$N����һ�С����������Ѹ���ޱȵ�����$n��$l", -10, -10, 150,"����",},
		{"$N˫��ʩ��һ�С��轥��½�����������ŷ�������$n��$l", -15, -10,170 ,"����",},
		{"$N���λ�����˫��ʹһ�С�˫��ȡˮ��һǰһ����$n��$l", -10,20 , 190,"����",},
		{"$NͻȻ���η���˫�ƾӸ�����һ�С��������졹����$n��$l", -15,-20 , 210,"����",},
		{"$N���ƾ۳�ȭ״������һ�С�Ǳ�����á���������$n��$l", -10, 10, 220,"����",},
		{"$Nʹ��������ެ����˫���������ϻ���$n��$l", -15, 40, 230,"����",},
		{"$Nʹ�������Ʋ��꡹�����Ʒ�ס$n����·������бб������$l", -15,20 , 240,"����",},
		{"$N���ƻ��أ�����ʹһ�С�������β�����»ζ��Ż���$n��$l", -10, 40, 250,"����",},
		{"$Nʹ������Ծ��Ԩ������$n��$l��������", -20, -20, 260,"����",},
		{"$Nʩ��һ�С�����󴨡������Ʋ�������������$n��$l", -10, 20, 270,"����",},
		{"$Nʹ������Ծ��Ԩ�������η���˫�Ʋ���һ����$n��$l����", -20, 30,280 ,"����",},
		{"$N˫������ʹ����ʱ����������$n��������", -20, 20, 300,"����",},
		{"$N���һ����˫��ʹ�����𾪰��������һ�а����$n", -25, -10, 330,"����",},
		{"$N�Ż��󿪣�һ�С���˪��������$n��$l��ȥ", -25, 1,350 ,"����",},
		{"$N����һת��ͻȻ�۵�$n��ǰ��һ�С���ս��Ұ������$n��$l", -20, 40, 360,"����",},
		{"$Nʹ�����������ڡ���˫�������������$n��$l", -25, 10, 380,"����",},
		{"$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ���������лڡ�����$n��$l", -30, 10, 450,"����",},
	};
	
	int level = 0;
	
	if( me->query_temp("xianglong") 
		&& ( me->query("mp") > 20 ) )
	{
		me->add_temp("apply/str", me->query_temp("str_count"));
		me->add("mp", -20);
		me->add_temp("str_no", 1);
		me->add_temp("display_no", 1);
		if( me->query_temp("display_no") == 2 )
		{
			message_vision( "$HIY$N������һ������ԽսԽ�£�", me);
			me->set_temp("display_no", 0);
		}
	}
	
	level = random(18);
	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
	
	return &m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "strike") || usage == "unarmed" || (usage == "parry");

}

//virtual int valid_combine(string combo) { return combo=="jiuyin_baiguzhao"; }	

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("������ʮ���Ʊ�����֡�");
	if (me->query_skill("huntian_qigong", 1) < 20)
		return notify_fail("��Ļ���������򲻹����޷�������ʮ���ơ�");
	if (me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷�������ʮ���ơ�");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 40)
		return notify_fail("�������̫���ˡ�");
	if (me->query("mp") < 10)
		return notify_fail("�����������������ʮ���ơ�");
	me->receive_damage("hp", 30);
	me->add("mp", -5);
	return 1;
}

//perform 
static int do_leiting(CChar * me, CContainer * ob)
{
	int damage;
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("������һ����ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if( me->query_skill("huntian_qigong", 1) < 100 )
		return notify_fail("��Ļ���������򲻹���ʹ����������һ������");
	
	if( me->query_skill("xianglong_zhang", 1) < 100 )
		return notify_fail("��Ľ���ʮ���Ʋ�������������ʹ�á�����һ������");
	
	if( me->query("mp") < 500 )
		return notify_fail("���������Ϊ�������ߡ�");
	
	msg =  "$NĬ�˻���������ʩչ��������һ������ȫ����ת��������Խ��Խ�죬������һ�����磬��Ȼ�䣬$N�Ѿ��������÷�����$n��\n";  
	
	if(random(me->query_combat_exp()) > target->query_combat_exp()/3) 
	{ 
		me->start_busy(3);
		target->start_busy(random(3));
		me->add("mp", -500);
		damage = me->query_skill("xianglong_zhang", 1)*4+me->query_skill("huntian_qigong",1);
		
		damage = damage + random(damage);
		
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/2);
		msg += "$nֻ��һ������Ӱ�ж�Ȼ�ֳ�$N��˫ȭ��������������ܣ������ػ��У������������ڲ��ݣ�������Ѫ��������������";
	}
	else
	{
		me->add("mp", -50);
		me->start_busy(1);
		msg += "����$p������$P����ͼ��������һ�ߡ�";
	}

	
	message_vision(msg.c_str(), me, target);
	
	if(!target->is_fighting(me)) target->kill_ob(me);
	return 1;
	
}

static int do_xianglong(CChar * me, CContainer * ob)
{
	int skill, count;
	
	if( me->query_temp("xianglong") ) 
		return notify_fail("���Ѿ����˹����ˡ�");
	if( !me->is_fighting() )
		return notify_fail("������ֻ����ս����ʹ�á�");
	if( me->query("mp") < 300  ) 
		return notify_fail("�������������");
	
	count = me->query_str();
	skill = me->query_skill("xianglong_zhang",1);
	me->add("mp", -100);
	message_vision(  "$N����һ�������������󷨣����ԽսԽ�£�" , me);
	me->set_temp("xianglong", 1);
	me->set_temp("str_count", count/5);
	me->set_temp("str_no", 0);
	me->set_temp("display_no", 0);
	me->call_out(remove_effect, skill / 2 );
	return 1;
}

static void remove_effect(CContainer *ob, LONG amount, LONG param)
{
	CChar *me =(CChar *) ob;
	
	LONG dmount = me->query_temp("str_no") * me->query_temp("str_count");
	me->add_temp("apply/str", - dmount );
	me->delete_temp("xianglong");
	me->delete_temp("str_count");
	me->delete_temp("str_no");
	me->delete_temp("display_no");

	tell_object(me, "��Ľ�����������ϣ��������ջص��");
}

SKILL_END;
