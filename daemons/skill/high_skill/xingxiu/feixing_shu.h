//feixing_shu.h ������
SKILL_BEGIN(CSfeixing_shu);

virtual void create()
{
	set_name("������");
	
	Magic_t * magic;
        set("valid_force", "huagong_dafa");
	magic = add_magic("huayu", do_huayu);
	magic->name = "��������";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	static struct {
		char action[255];
		int damage, dodge;
		int lvl;
	}action[13] = {
		{ "$N������ˣ�һ�С���¶��â��������$w����һ�㺮â����$n",
			230, -20, 0,},
		{ "$N����΢��ǰһ�죬ʹ����է���ǳ���������$w��ֱ����$n��˫��",
		240, -95, 9,},
		{ "$Nһ����Х��ʩչ������ҹ���ǡ�������΢��������$w��Ȼ���Ϸ������˸�Ȧ�����Ѹ��Ϯ��$n������",
		250, -90, 18,},
		{ "$Nʹһ�С��ǹ���˸����ͻȻ�������һ�����������ڿ���ص�һ˲�䣬$n��Ȼ���ּ��㺮����˸������Ϯ���Լ�",
		255, -85, 27,},
		{ "$N����һ�ӣ�һ�С���â��������$n��������$N�����$w�������Լ�����ǰ��Ѩ�����˽���ȴͻȻת�����Լ��ĺ���",
		260, -80, 36,},
		{ "$N����������һ����ʹ����׹��֮�ǡ�������$wƽֱ������$n���ʺ�ȴ�ּ��ϰ���ʹ֮��;��������$n������",
		270, -70, 45,},
		{ "$N����һԾ����ʩչ��������֮�ǡ��������$w�������±�ֱ������$n��ͷ��",
		285, -60, 54, },
		{"$Nԭ��һ����ת���漴˫��һ����$w��ƮƮ�����ط���$n��ԭ�������ǡ��ǳ����롻",
		290, -55, 63, },
		{"$Nʹ��һ�С��ǹ���𡻣�ǰ��һ�壬�漴�����������$w����˿������ȴ��Ѹ���ޱȵ�����$n��ǰ��",
		320, -45,72, },
		{"$NͻȻ��������ˣ�ʹ�����ǿ�ը�ס���˫����ǰһ�ƣ�����$w��������������������$n",
		340, -40, 81,},
		{"$Nʩչ�����ǻ����ա���ԭ�ز����������΢΢��ǰһ��������$w����һ�㺮���Բ��������$n",
		360, 30, 90},
		{"$N΢΢����ʹ�����ǹ����ɡ�����ӰƮ��������$n�پ�ʮ�ִ��ۣ�ȴ��$N�����$w��Ю�ŵ��ϵ�ɳʯ�Լ���Χ����ҳ�����Լ�",
		390, -25, 99},
		{"$N��Ȼ��̾һ����ת����У�$n�����ɼ䣬ȴ����ǰ�Ѿ���$w��Ӱ�ӣ��ۿ��޴��ɶ��ˣ�ֻ�����о��ǡ��������꡻�ˣ�$n���ɴ�ʧɫ",
		420, -20, 110,}};
		
		int level = me->query_skill("feixing_shu", 1);
		
		for(int i = 13; i > 0; i--)
			if(level > action[i-1].lvl)
			{
				level = random(i);
				m_actions.set("action", action[level].action);
				m_actions.set("damage", action[level].damage);
				m_actions.set("dodge", action[level].dodge);
				
				break;		
			}
			
			return & m_actions;
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[8][80] = {
		{"$n��һ����һ�Σ��漴�ص�ԭ�أ����ɵض����$N��һ�С�",},
		{"$n����Ծ��һ���շ�����˳������һ�ߡ�",},
		{"$n�������Ա�һ�ݣ�������$N�����൱�ľ��룬$N��һ����ȻʧЧ��",},
		{"$n������ϣ������Ծ��$N��������$N�ı���",},
		{"$n���μ�����б��ǰһ������Ȼ�Ѿ��㿪��$N����һ�С�",},
		{"$N��ǰһ����ȴ��$n��Ȼ�����Լ�������֮Զ��ȴû��$n��ζ���Լ��Ĺ�����",},
		{"$Nһ��������$n��û����Ӱ��$N��ת��ȴ��$n���Ƕ����Լ����֡�",},
		{"$Nһ�й�����$n��Ȼ������$NãȻ�Ĺˣ�ȴ����$n��Ӱ�ӣ�",},
	};
	
	return dodge_msg[random(8)];
}

virtual int practice_skill(CChar * me)
{
	CContainer *  weapon;
    if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "throwing"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
    if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
    if (me->query("mp") < 30)
		return notify_fail("���������������������");
    me->receive_damage("hp", 30);
	
    return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_skill("force", 1) < 20)
		return notify_fail("����ڹ��ķ���򲻹����޷�ѧ��������");
	if (me->query_skill("dodge", 1) < 20)
		return notify_fail("����Ṧ��򲻹����޷������������");
    if (me->query_dex() < 25)
		return notify_fail("������������ɣ��޷������������");
    return 1;
}

virtual int valid_enable(string usage) { return usage=="throwing" ||usage=="dodge"||usage=="parry";}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if( random(me->query_skill("poison",1)) > 100)
    {
		victim->apply_condition("xx_poison", random(50) + 1 +
			victim->query("condition/xx_poison"));
    }
	
	return "";
}

static int do_huayu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
    CContainer * weapon;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
    if( !target || ! me->is_fighting(target) )
        return notify_fail("��������ֻ����ս���жԶ���ʹ�á�");
	
    if (! (weapon = me->query_weapon()) )
		return notify_fail("��û��װ��������");
	
    if( me->query_skill("feixing_shu", 1) < 150 )
        return notify_fail("��ķ�����������죬����ʹ���������졣");
    if( me->query_skill("huagong_dafa", 1) < 100 )
        return notify_fail("��Ļ����󷨲�����죬����ʹ���������졣");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
    if( me->query("mp") < 200 )
        return notify_fail("����������������ʹ���������졣");
	
	if(weapon->query("no_duo"))
		return notify_fail("��˱�����%s��ô����أ�",me->name());
	
    int skill = me->query_skill("feixing_shu", 1);
	
    me->add("mp", -100);
    target->receive_damage("hp", skill/ 3);
	
    msg = "ֻ��һ����Ŀ���̹��$N���Ҳ෢����$N���е�";
	msg += weapon->name();
	msg += "�����ǰ���$n�����ȥ��";
	
    me->start_busy(1);
	if( random( me->query_skill("dodge", 1))
		> random(target->query_skill("dodge") - 1) ) 
	{
		msg += "$HIR���$p��$P�ľ��д�����Ҫ����λ��ʹ�õ��ڵ��ϴ����Һ���";
		target->receive_wound("hp", random(skill) * 3);
		target->start_busy( me->query_skill("feixing_shu", 1) / 20 + 2);
        target->apply_condition("xx_poison", random(me->query_skill("poison",1)/3) + 1 +
			target->query("condition/xx_poison"));
	} 
	else 
	{
		msg += "����$p�����$P�����һ����";
	}
		
	message_vision(msg.c_str(), me, target);
		
	//use out all throwing
	weapon->move(me->environment());
	return 1;
}

SKILL_END;



