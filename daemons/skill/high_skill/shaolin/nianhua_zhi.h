SKILL_BEGIN(CSnianhua_zhi);

virtual void create()
{
	set_name( "�黨ָ");

	Magic_t * magic;

	magic = add_magic("foxue", do_foxue);
	magic->name = "�黨��Ѩ";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("�黨ָ���������ֶ����ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[10] = {
		{"$N����̧�ۣ���ָ���˸���Ȧ��һʽ��ƿ�����⡹����$n��$l",
			60, -5, 10, 0},
		{"$N�������У�һʽ����÷�������ָ��Ҹ������ָ��$n����ǰ",
		70, -5, 15, 0},
		{"$N����б�У����ְ��ƣ�����һʽ�������ʾơ�����$n��$l����",
		90, 5, 30, 0},
		{ "$N˫Ŀ΢����һʽ��¶��б������˫�ֻû���ǧ�ٸ�ָӰ������$n��$l",
		120, 5, 40, 9,},
		{"$Nһʽ�����³��ء������ƻ�ס�������бָ���죬���Ƶ���$n��$l",
		160, 15, 80, 18,},
		{ "$N˫��ƽ����ǰ��ʮָ�濪��һʽ��Ҷ����������ָ��$n�������Ѩ",
		210, 20, 120, 27,},
		{ "$N˫�Ʒ��ɣ�һʽ�������𡹣�ָ�˱ų�����������������$n��ȫ��",
		270, 25, 160, 36,},
		{ "$Nһʽ��������˪������ָ���У�һ����������ٱ�ĵ�����������$n��$l��ȥ",
		340, 30, 200, 45,},
		{ "$Nһʽ��٤Ҷ΢Ц����˫��ʳָ���棬ָ�����һ�����������$n��$l",
		420, 35, 240, 55,},
		{ "$N����������ǰ��һʽ�������黨��������ʳָ��סĴָ���������$nһ��",
		510, 50, 450, 62,},
	};

	int level = me->query_skill("nianhua_zhi", 1);
	for(int i = 10; i > 0; i--)
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

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if ((int)me->query("mp") < 20)
		return notify_fail("��������������黨ָ��");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("���黨ָ������֡�");
	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ�黨ָ��");
	if (me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷����黨ָ��");
	return 1;
}

virtual int valid_enable(string usage) { return usage=="finger" || usage=="parry";  }
virtual int valid_combine(string combo) {return combo=="sanhua_zhang";  }

static int do_foxue(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || ! me->is_fighting(target))		//add by lanwood 2000-12-26
		return notify_fail("ֻ�ܶ�ս���еĵ���ʹ�ã�");

	if(me->query_str() < 25)
		return notify_fail("���������,����ʹ����һ����!");

	if(me->query_skill("hunyuan_yiqi",1) < 100)
		return notify_fail("���Ԫһ�����Ĺ�����������ʹ���黨��Ѩ!");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if (me->query_weapon())
			return notify_fail("�㲻��ʹ��������");

	if(me->query_skill("finger") < 120)
		return notify_fail("���ָ����Ϊ����,Ŀǰ������ʹ���黨��Ѩ����!");

	if(me->query("mp") < 300)
		return notify_fail("���������ڲ���, ����ʹ���黨��Ѩ! ");

	if( target->is_busy() )
		return notify_fail("%sĿǰ���Թ˲�Ͼ���ŵ������ɣ�", target->name());

	msg = "$HIY$Nʹ���黨ָ�������黨��Ѩ������ס��$n��ȫ��ҪѨ, ʹ$n�������á�\n";

	if( random(me->query_combat_exp()) > target->query_combat_exp() / 3 )
	{
		msg +=  "$HIG���$p��$P���˸����ֲ���! $COM";
		target->start_busy( me->query_skill("nianhua_zhi",1) / 20);
		me->add("mp", -100);
	}
	else
	{
		msg += "$HIM����$p������$P����ͼ����û���ϵ���$COM";
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;