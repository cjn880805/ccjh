//sun_finger.h  һ��ָ��

SKILL_BEGIN(CSsun_finger);

virtual void create()
{
	set_name("��Ʒһ��ָ");

	Magic_t * magic;

	magic = add_magic("qiankun", do_qiankun);
	magic->name = "һָǬ��";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "kurong_changong") || EQUALSTR(arg, "xiantian_gong"))
		return 1;

	return notify_fail("��Ʒһ��ָ��Ҫ�����ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge,  damage, lvl;
		char damage_type[5];
	}action[] = {
		{"$Nһʽ��������������������ָ���籡������������ָ���������������$n��$l", 100, 25, 10,0 ,"����",},
		{"$N����һת��һ���絽$n���$n��æת��$N���������Ծ�أ�һʽ��³�����ա�������ʳָ������ָ��$n��$l", 120, 25, 20, 20,"����",},
		{"$N����̤��һ���������������ʳָЮ���ۻ���������$n��$l����ʽ����̹��������һʽ��������ѩ��", 160, 20,40 , 40,"����",},
		{"$N��ӰƮ��һʽ���������졹�����϶��£���������繳������$n���Ҽ磬$n������ܣ�$N���ֳ��Ƶ���$n��$l", 190,30 , 50, 60,"����",},
		{"ֻ��$N���Ϻ���һ�죬����һ�գ�һʽ�����ս�����������ʳָбָ����$n��$l��ȥ", 220, 30, 70, 70,"����",},
		{"$N����б����ͻȻ�����Ϊָ���͵�һ���죬һʽ�����ﳯ������ʹ��һ��ָ��������$n��$l", 250, 20, 80, 90,"����",},
		{"$N����һԾ������$n������ϥһ��������ʳָ����һʽ����������������$n�ĺ���", 280, 25, 100, 100,"����",},
		{"$Nһ�����, һʽ��������̩�����þ�ȫ����$n��$l��ȥ", 300, 10, 120,130 ,"����",},
	};

	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("sun_finger", 1))
		{
			int level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

virtual int valid_combine(string combo) { return combo=="haotian_zhang"; }

virtual int valid_learn(CChar * me)
{
	if ( me->query_weapon() )
		return notify_fail("��һ��ָ������֡�");
	
	if (DIFFERSTR(me->querystr("gender"), "����"))
		return notify_fail("���������㣬�޷�ѧһ��ָ��");
	
	if (me->query("max_mp") < 700)
		return notify_fail("�������̫�����޷���һ��ָ��");

	//һ��ָӦ����ȫ��ľ�ѧ�ɡ�

	//������һ�������˾Ͳ���ѧ��ʲôѽ��
	/*if (me->query_skill("kurong_changong", 1) < 80 ||
		me->query_skill("tianlong_shengong", 1) < 80)
		return notify_fail("��ı����ڹ���򲻹����޷�ѧһ��ָ��");
	else
	*/

	return 1;
}

virtual int practice_skill(CChar * me)
{
	
	if (me->query("hp") < 50)
		return notify_fail("�������̫���ˡ�");
	
	if (me->query("mp") < 30)
		return notify_fail("�������������һ��ָ");
	
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

//exert heal
static int do_qiankun(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || ! me->is_fighting(target) )
		return notify_fail("��һָǬ����ֻ����ս���жԶ���ʹ�á�");

	if(me->query_str() < 28)
		return notify_fail("���������,����ʹ����һ����!");
	
	if (me->query_skill("kurong_changong", 1) < 90)
		return notify_fail("����������Ĺ�����������ʹ��һָǬ��");

	if (me->query_skill("sun_finger", 1) < 90)
		return notify_fail("���һ��ָ��Ϊ����,Ŀǰ������ʹ��һָǬ������!");

	if( me->query("max_mp") < 850 ) 
		return notify_fail("��������Ϊ����, ����ʹ��һָǬ��!");
	
	if( me->query("mp") < 200 ) 
		return notify_fail("��������Ϊ����, ����ʹ��һָǬ��!");

	if(DIFFERSTR(me->querystr("family/family_name"), "����μ�") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( target->is_busy() )
		return notify_fail("%sĿǰ���Թ˲�Ͼ���ŵ������� ",target->name());

	msg = "$Nʹ��һ��ָ������һָǬ��������ס��$n��ȫ��ҪѨ, ʹ$n�������á�\n";
	
	if( random(me->query_combat_exp()) > target->query_combat_exp() / 3 )
	{
		msg += "���$n��$N���˸����ֲ���! һʱ���ܶ���! " ;
		target->start_busy( me->query_skill("sun_finger",1) / 20 );
	}
	else
	{
		msg += "����$n������$N����ͼ����û���ϵ���";
		me->start_busy(4);
	}

	me->add("mp", -200);
	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;

