
// sougu.h �ѹ�ӥצ��
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSsougu);

virtual void create()
{
	set_name( "�ѹ�ӥצ��");

	Magic_t * magic;

	magic = add_magic("muye", do_muye);
	magic->name = "��Ұӥ��";
	magic->mp = 800;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenghuo_shengong") || EQUALSTR(arg, "jiuyang_shengong"))
		return 1;

	return notify_fail("�ѹ�ӥצ��������ʥ�������ʹ�á�");
}


virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge;
		char damage_type[5];
		int lvl,damage;
	}action[] = {
		{"$N˫��һ£����צֱ��$n���̣���צȴЮ����֮������$n���䣬һ��һʵ������һ�С���צʽ��", 170, 5,"ץ��", 0, 15,},
		{"$N���ζ�������ӥ���հ㡰ٿ���ش�$nͷ��Խ����ʹһ�С���צʽ��˫צ����$n�Ժ����", 190, 20,"ץ��", 25, 5,},
		{"$N�͵�һ����ͻȻ����$n��ǰ��ʹһ�С���צʽ������צֱ��$nС��", 215, 20,"ץ��", 35, 10,},
		{"$N��צ���أ���צ�����󷢣�һ�С���צʽ������������$n��$l", 245, 5,"ץ��", 45, 20,},
		{"$N���ι��죬����ǰ�ˣ�ʹһ�С���צʽ����ֱ��$n�ɲ�", 280, 25,"ץ��", 55, 35,},
		{"$N����Ʈ������Ȼת��$n���һ�С���צʽ����˫צֱ��$n�ʺ����", 320, 35,"ץ��", 65, 60,},
		{"$Nһ����Х�����ΰ���ʹ����ǧצʽ�����ɰ�������»���$n�پ�����צӰ������ȫ����Ѩ", 365, 40,"ץ��", 95, 85,},
	};
  		
	int level = 0;
	
	for(int i=7; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("sougu", 1))
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
	return (usage == "claw") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon()  )
		return notify_fail("���ѹ�ӥצ��������֡�");
 	if ( me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷�ѧ�ѹ�ӥצ����");
	if ( me->query_str() < 27)
		return notify_fail("��ı���̫��޷�ѧ�ѹ�ӥצ����");
	if ( me->query_skill("claw", 1) < 50)
		return notify_fail("���צ���������ȣ��޷�ѧ�ѹ�ӥצ����");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if ( me->query("mp") < 20)
		return notify_fail("�������������ӥצ����");
	me->receive_damage("hp", 25);
	me->add("mp", -5);
	return 1;
}

//perform 
static int do_muye(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if( me->query_str() < 30)
		return notify_fail("���������,����ʹ����Ұӥ�");

	if( me->query_weapon())		//add by lanwood 2000-12-26
		return notify_fail("�㲻�ǿ��֡�");

	if( me->query_skill("sougu",1) < 150)
		return notify_fail("����ѹ�ӥצ����Ϊ����,Ŀǰ������ʹ����Ұӥ�");

	if(DIFFERSTR(me->querystr("family/family_name"), "����") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( me->query("mp") < 800)
		return notify_fail("���������ڲ���, ����ʹ����Ұӥ�");
	
	if( target->is_busy() )
		return notify_fail( "%sĿǰ���Թ˲�Ͼ���ŵ������� ",target->name());
	
	msg =  "$Nʹ���ѹ�ӥצ����������Ұӥ���˫צ���ץ��$n��ȫ��ҪѨ��\n";

	me->add("mp", -150);

	if( random(me->query_combat_exp()) >  target->query_combat_exp() / 2 ) 
	{
		msg += "���$p��$P���˸����ֲ�������ʱ�������ã�"  ;
		target->start_busy(  me->query_skill("sougu",1) / 20 + 1);
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
