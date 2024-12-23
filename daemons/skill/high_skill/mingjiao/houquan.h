//houquan.h ��ȭ

SKILL_BEGIN(CShouquan);

virtual void create()
{
	set_name( "��ȭ");

	Magic_t * magic;

	magic = add_magic("zhen", do_zhen);
	magic->name = "���־�";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  force, dodge,  damage, lvl;
	}action[6] = {
		{"$N����΢����������ǰ�˳���һʽ���ɺ�ժ�ҡ�����צֱ����ץ��$n��˫��",
			180, 5, 10, 0,},
		{"$N������Σ�һʽ�������֦��������ֱ��������$n�ļ羮��Ѩ",
		200, 10, 20, 8,},
		{"$Nһ��ǰ�죬һ�ۺ�ָ��һʽ��Գ�����桹������$n������",
		230, 10, 25, 15,},
		{"$N��Ȼ����һ�ţ�ʹһʽ���˷���Ӱ����˫�������޶���һצץ��$n���ؿ�",
		230, 25, 20, 15,},
		{"$N����һ������һ������ʹһʽ��ˮ�����¡���˫צ������$n��С��",
		220, 15, 10, 20,},
		{"$N�͵����ϸ߸�Ծ��һʽ�����ժ�ǡ����Ӹ����£�һצ����$n��ͷ��",
		240, 20, 20, 30,},
	};

  	int level = me->query_skill("houquan", 1);
	for(int i = 6; i > 0; i--)
		if( action[i - 1].lvl < level)
		{
			level = random(i);
	
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
			
	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"|| usage=="hand"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon() )
		return notify_fail("����ȭ������֡�");
	if (me->query_skill("force", 1) < 30)
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ��ȭ��");
	if (me->query("max_mp") < 200)
		return notify_fail("�������̫�����޷�����ȭ��");

	return 1;
}


virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if (me->query("mp") < 10)
		return notify_fail("���������������ȭ��");
	me->receive_damage("hp", 15);
	me->add("mp", -5);

	return 1;
}

static int do_zhen(CChar * me, CContainer * ob)
{
	int damage;
	string msg;
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||  ! me->is_fighting(target) )
		return notify_fail("�����ֻ�ܶ�ս���еĶ���ʹ�á�");

	if( me->query_weapon())
		return notify_fail("�������ֲ���ʹ�á����־���");

	if(DIFFERSTR(me->querystr("family/family_name"), "����") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");		
		
    if( me->query_skill("houquan", 1) < 40 )
		return notify_fail("��ĺ�ȭ������죬����ʹ�á����־���");
	                        
    if( me->query("mp") < 100 )
		return notify_fail("����������̫��������ʹ�á����־���");
			
	msg = "$NĬ���񹦣�ʹ����ȭ�����־�����ͼ����������$n��";
	
	me->add("mp", -50);

    //if( !target->is_killing(me) ) target->kill_ob(me);

	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{
		me->start_busy(3);
		target->start_busy(random(3));
		
		damage = me->query_skill("force", 1);
		
        damage = damage/2 + random(damage/2);
		
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/3);
        me->add("mp", -damage/3);
		
		if( damage < 20 ) msg += "���$n�ܵ�$N�����������ƺ�һ����";
		else if( damage < 40 ) msg += "���$n��$N���������𣬡��١���һ������������";
        else if( damage < 80 ) msg += "���$n��$N������һ���ؿ������ܵ�һ���ش�����������������";
        else msg += "���$n��$N������һ����ǰһ�ڣ��������ɳ�������";
		
	} 
	else 
	{
        me->start_busy(3);
		msg += "����$p������$P����ͼ����û���ϵ���";
	}

	message_vision(msg.c_str(), me, target);

	return 1;
}

SKILL_END;

