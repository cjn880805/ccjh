
//anranxiaohun_zhang.c ��Ȼ������
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSanranxiaohun_zhang);

virtual void create()
{
	set_name( "��Ȼ������");

	Magic_t * magic;

	magic = add_magic("xiaohun", do_xiaohun);
	magic->name = "��Ȼ����";
	magic->mp = 1000;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "yunv_xinfa") || EQUALSTR(arg, "seaforce"))
		return 1;

	return notify_fail("��Ȼ�����Ʊ������Ĺ�����ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$Nһ�� ������� ̧ͷ���죬��������������һ�����Լ�ͷ���տ��ĳ�������б�£��������ɻ��Σ���ɢ��������$n��$l��", 250,1, 2, 0, "����", },
		{"$Nһ�� �������� �ֱ��´������ް�������ʽ��ͻȻ�������붯���������䡢˫��ͷ���������ر�������������ʽ����ײ��$n.", 250, 1, 3, 10, "����", },
		{"$Nһ�� �����ˮ ��������Ʈ����������ˮ������ȴ����֮�������ƴ��ż�ǧ����ɳһ�㣬�����빥$n��", 250, 1, 4, 20, "����", },
		{"$Nһ�� �������� �����ո���ͷ�������£��Ų����ص�����$n,���������������$n��$l��", 250,1, 5, 30, "����", },
		{"$Nһ�� ��ʬ���� �߳�һ�š���һ�ŷ���ʱ�л��㱣�����ԼԼ���������޵�����$n", 250, 1, 6, 40, "����", },
		{"$N˫��ƽ�У�һ�� ӹ������ û����ɵ�����$n��$l.", 250,1, 7, 50, "����", },
		{"$Nһ�� ������ʩ ͻȻ�������࣬ͷ�½��ϣ��������ӣ�һ������$n��$l", 300, 1, 8, 60, "����", },
		{"$Nһ�� �ľ����� ��ĿԶ���������鸡����ǰ�Ż�������ȫ����ʽ����ѧ�и������޲��Ǻϡ�", 300, 1, 9, 70, "����", },
		{"$Nһ�� ������ʳ �����鸡�����缸�첻�Բ�˯��ĽŲ��ʲյ�Ϯ��$n�����ԣ�������ȭ����$n��$l��", 300, 1, 10, 80, "����", },
		{"$Nһ�� �ǻ��չ� ���Ҵ�����ʵʵ�Ĺ���$n��$l��", 300,1, 11, 90, "����", },
		{"$Nһ�� �������� ����������״������бб����$n��$l��", 350, 1, 12, 100, "����", },
		{"$Nһ�� ���񲻰� �������ݼ�ת��չ���ṦΧ��$n�������ߣ���Ȼ�����������$n��$l��", 400, 1, 13,110 , "����", },
		{"$Nһ�� ��;ĩ· ����$n���ԣ����ƾٵ���ǰƽ�ƶ�������������бб����$n��$l��", 450,1, 14, 120, "����", },
		{"$Nһ�� ����ľ�� ˫Ŀֱֱ�Ķ���$n�����嶯Ҳ����һ�µķ���$n", 500 ,1, 15, 130, "����", },
		{"$N��ͷڤ�룬һ�� ������ʧ ��������ƽƽ����$n��$l��", 550,1, 16, 140, "����", },
		{"$Nһ�� ��ͨ�˴� ˫�ƻγ�ǧ����Ӱ��$n����������֮�¡�", 600, 1, 17, 150, "����", },
		{"$N����ǰ��һ�� ¹��˭�� �������ȣ��Կ������һ��ת���Ѿ�ת����$n�������ָ������$n�Ĵ�׵Ѩ��", 800, 1, 18, 160, "��Ѩ", },
	};
	
	int level = 0;
	
	for(int i=17; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("anranxiaohun_zhang", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", me->query_skill("dodge") / 2);
			if(me->query("age")<200)
				m_actions.set("damage", me->query("age") * action[level].damage);
			else
				m_actions.set("damage", 200 * action[level].damage);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "unarmed") || (usage == "parry");
}

virtual int valid_combine(string combo) { return combo=="anranxiaohun_zhang"; }

virtual int valid_learn(CChar * me)
{
	if (!me->query("couple_betray"))
		return notify_fail("��û��ɥʧ�����£�����������еľ�Ҫ��");

	if (me->querymap("couple"))
		return notify_fail("��������������������������еľ�Ҫ��");

	if (DIFFERSTR(me->querystr("gender"), "����")) 
		return notify_fail("����᲻������˼��һ���˵����顣");
		
	if (me->query_weapon() )
		return notify_fail("����Ȼ�����Ʊ�����֡�");

	if (me->query("max_mp") < 2000)
		return notify_fail("�������̫�����޷�����Ȼ�����ơ�");

	if (me->query_str()< 40)
		return notify_fail("��ı���̫�����޷�����Ȼ�����ơ�");
	
	if (me->query_skill("seaforce", 1) < 30 || me->query_skill("yunv_xinfa", 1) < 30)
		return notify_fail("��ı����ķ���򲻵����޷�����Ȼ�����ơ�");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");

	if (me->query("mp") < 20)
		return notify_fail("���������������Ȼ�����ơ�");

	if (DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��"))
		return notify_fail("�㲻�ǹ�Ĺ�ɵĵ���,�޷���ϰ��Ȼ�����ơ�");

	if (me->query_skill("seaforce", 1) < 50|| me->query_skill("yunv_xinfa", 1) < 50)
		return notify_fail("��ı����ķ���򲻵����޷�����Ȼ�����ơ�");

	me->receive_damage("hp", 25);
	me->add("mp", -30);
	return 1;
}

//perform 
static int do_xiaohun(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(!target || !me->is_fighting(target) )
		return notify_fail("����Ȼ���꡹ֻ����ս����ʹ�á�");

	if (DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��"))
		return notify_fail("�㲻�ǹ�Ĺ�ɵĵ���,�޷���ᡸ��Ȼ���꡹�еļ�į��");

	if (!me->query("couple_betray"))
		return notify_fail("��û��ɥʧ�����£�����������еľ�Ҫ��");

	if (me->query_weapon())
		return notify_fail("������֡�");
	
	if( me->query("mp") < 1000 )
		return notify_fail("�������������");
	
	if( me->query_skill("anranxiaohun_zhang",1) < 170 )
		return notify_fail("�����Ȼ�����ƻ�򲻹����޷�ʹ�á���Ȼ���꡹��");
	
	if( me->query_skill("force") < 300 )
		return notify_fail("����ڹ���Ϊ�������޷�ʹ�á���Ȼ���꡹��");
	
	message_vision("$N����ֹˮ������˼����$N�����ӣ�����֮��ʹ���ˡ���Ȼ���ꡱ��", me);
	
	if(target->query_temp("apply/no_��Ȼ����") && (random(me->query_combat_exp()) < target->query_combat_exp()/3 ||target->query("bigboss")))
	{
		message_vision("����$n������$N����ͼ����û���ϵ���\n" ,me,target); 
	}
	else
	{
    	if (me->querymap("couple"))
		{
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		}
		else
		{
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
			g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		}
		me->add("mp", -500);
		me->start_busy(random(4));
	}
	return 1;
}

SKILL_END;
