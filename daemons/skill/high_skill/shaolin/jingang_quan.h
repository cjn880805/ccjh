SKILL_BEGIN(CSjingang_quan);

virtual void create()
{
	set_name( "����ȭ");

	Magic_t * magic;

	magic = add_magic("jingang", do_jingang);
	magic->name = "������ͨ";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[8] = {
		{ "$N��ϥ���������ֺ�ʮ��һʽ������������˫ȭ���ƶ���������$n��$l",
			180, -5, 0, 0,},
		{"$Nһʽ���һ�׶����˫�������»���ȭ�����棬��ž����",
		200, 5, 10, 10,},
		{ "$N�ڿշ���һʽ���˷��꡹��˫��˫���������$n�޿ɶ��",
		230, 15, 10, 20,},
		{"$N˫���麬����Ե�³���һʽ�������ס���������$n�Ƴ�",
		270, 5, 20, 30,},
		{ "$Nһ��ǰ�죬һ�ۺ�ָ��һʽ����ָɽ��������$n����ǰ���",
		320, 10, 15, 40,},
		{ "$Nһʽ�������ɡ�������ʮָ���$n��ȫ����ʮ����ҪѨ",
		380, 25, 25, 48,},
		{ "$N��Ŀ���ӣ�˫��������һʽ����������������˷������������ǵ�����",
		450, 15, 35, 54,},
		{ "$N��Ц��Ц��˫ȭ�����޶���һʽ������Ц������Ȼ����$n��ǰ��",
		530, 20, 50, 60,},
		};

	int level = me->query_skill("jingang_quan", 1);
	for(int i = 8; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	
	return & m_actions;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("����ȭ���������ֶ����ڹ����ʹ�á�");
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if (me->query("mp") < 20)
		return notify_fail("�����������������ȭ��");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("������ȭ������֡�");
	if (me->query_skill("hunyuan_yiqi", 1) < 10)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ����ȭ��");
	if (me->query("max_mp") < 50)
		return notify_fail("�������̫�����޷�������ȭ��");
	return 1;
}

virtual int valid_enable(string usage) { return  usage=="cuff" || usage=="parry";}

static int do_jingang(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	int d_count, count, qi, maxqi, skill;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( me->query_temp("jingang") ) 
		return notify_fail("���Ѿ����˹����ˡ�");

	if(!target || !me->is_fighting(target) )
    	return notify_fail("��������ͨ��ֻ����ս����ʹ�á�");

    if( me->query("mp") < 500 )
		return notify_fail("��������������ߣ�");

	if( me->query_skill("hunyuan_yiqi", 1) < 60)
		return notify_fail("��Ļ�Ԫһ��������Ϊ����������ʹ�ô�����ͨ! ");

	if( me->query_skill("cuff") < 150 )
		return notify_fail("���ȭ���������ң��޷�ʹ�ô�����ͨ��");

	if( DIFFERSTR(me->query_skill_mapped("cuff"), "jingang_quan") )
		return notify_fail("��û�м������ȭ���޷�ʹ�ô�����ͨ��");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
		
    qi = me->query("hp");
	maxqi = me->query("max_hp");
	skill = me->query_skill("jingang_quan", 1) / 3;
	count = me->query_str();
	d_count = me->query_dex() / 2;

	if(qi > (maxqi * 0.4))
	{	
    	message_vision("$Nʹ������ȭ�ľ�����������ͨ����������Ȼ���ӣ�", me);
		
		me->add_temp("str", count * 2);	
		me->add_temp("dex", 0 - d_count);
		me->set_temp("jingang", 1);
		me->call_out(remove_effect, skill, count * 2, d_count);
		me->add("mp", -150);
	}
	else
	{
		message_vision("$Nƴ����������ʹ���˴���ȭ���ռ�����, ȫ�����һ����, �������ͬ���ھ�!", me, target);
		me->add_temp("str", count * 9);
		me->set_temp("jingang", 1);

		me->call_out(remove_effect, 2, count * 9, 0);

//		me->add_temp("str",  -(count * 29));		
//		me->delete_temp("jingang");
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		me->set("mp",0l);
		me->add("max_mp",-10);

		message_vision("$N�þ������һ������, ���һ����Ѫ, һͷ�Ե��ڵ�!", me, target);

		me->set("hp",0l);
//		me->unconcious();
	}
	return 1;
}

static void remove_effect(CContainer * ob, LONG aamount, LONG damount)
{
	CChar * me = (CChar *) ob;

	if ( me->query_temp("jingang") ) 
	{
		me->add_temp("str", -aamount);
		me->add_temp("dex", damount);
		me->delete_temp("jingang");
		me->SendState(me);
		tell_object(me, "��Ĵ�����ͨ������ϣ��������ջص��");
		me->start_busy(random(4));
	}
}

SKILL_END;