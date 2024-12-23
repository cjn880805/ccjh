// huifeng_jian.h �ط������
//code by Fisho
//date : 2000-12-02

SKILL_BEGIN(CShuifeng_jian);

virtual void create()
{
	set_name( "�ط������");
	set("valid_force", "linji_zhuang");

	Magic_t * magic;

	magic = add_magic("mie", do_mie);
	magic->name = "��";
	magic->mp = 200;
	magic->valid_cast = CAST_IN_COMBAT;

}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[8];
	}action[] = {
		{"$N���⽣â������һ�С����Ϯ�¡�������$w�����´󿪴��أ�һ����������$n��$l", 120, 20, 300,0 ,"����",},
		{"$N����Ȧת��һ�С�Ʈѩ���ơ�������$wƽչ�´̣�һ�����Ữ��$n��$l", 120, 20, 280, 0,"����",},
		{"$N��������������������������$wʹ��һʽ��ǧ�徺�㡹����$n��$l",140 , 15, 350, 0,"����",},
		{"$N������ָ��������ת��һ�С��������ڡ�ֱȡ$n��$l", 150, 15, 280, 0,"����",},
		{"$N��â���£��������ߣ�����$wʹ��һʽ�������������������������$n��$l", 130, 25,300 ,0 ,"����",},
		{"$N�����ƽ���������ʵ��׷ɣ��ó�����ǹ⣬����$wʹ��һʽ��������ɳ��ԾԾ����Ʈ��$n��$l", 120, 25,320 , 0,"����",},
		{"$N�ӽ��ֻ�����������ǰԾ��������$wһʽ���������Ρ�����������֮�ƣ�����$n��$l", 110, 15,0 ,400 ,"����",},
		{"$N�˲������ֽ�ָ��ת������һŤ������$wһ�ǡ���غ��衹���¶��ϴ���$n��$l", 150,35 , 400, 0,"����",},
	};
	
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("huifeng_jian", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
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

	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("���ʦ����ʱû��ָ�����书����");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("����ʱ�޷�ָ������µ��书����");

	if (me->query("max_mp") < 50)
		return notify_fail("�������������");
	if (me->query_skill("linji_zhuang", 1) < 20)
		return notify_fail("����ټ�ʮ��ׯ���̫ǳ��");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())
        || DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if (me->query("hp") < 50)
		return notify_fail("��������������ط��������");
	me->receive_damage("hp", 10);
	return 1;
}

//perform 
static int do_mie(CChar * me, CContainer * ob)
{
	string msg;
	CContainer * weapon;
	int damage;
	CChar * target= NULL;
	
	if (ob && ob->Query(IS_CHAR))
		target=(CChar *) ob;

	if (!(weapon = me->query_weapon())
        || DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʲô��Ц��ûװ��������ʹ���𽣡���");
	
	if (!target || !me->is_fighting(target) )
		return notify_fail("���𽣡�ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if (me->query_skill("huifeng_jian", 1) < 60 )
		return notify_fail("��Ļط��������������죬��ʹ�������𽣡���");
	
	if (me->query_skill("linji_zhuang", 1) < 60 )
		return notify_fail("����ټ�ʮ��ׯ��򲻹������𽣡�������ʽ��");

	if (me->query("max_mp")<400)
		return notify_fail("���������Ϊ���㣬�޷����㡸�𽣡���������");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if (me->query("mp")<200)
	{
		return notify_fail("����������������û�ܽ����𽣡�ʹ�꣡");
	}
	msg =  "$N���г�����âԾ�������Ⱪ�����ó�������ɫ�ʣ����⽥";
	msg += "���ƽ�$n��$n�������콣�⣬�����Ծ��ֻ��һɲ�����콣";
	msg += "Ӱ��Ϊһ��ֱ��$nǰ�أ�������ף�ֻ��һ����";
	if (random(me->query_skill("force") + 1)>target->query_skill("force")/2 || 
		random(me->query_combat_exp() + 1)>target->query_combat_exp()/3)
	{
		me->start_busy(2);
		target->start_busy(random(3));
		damage = me->query_skill("huifeng_jian", 1);
		if(damage > 0)
			damage = damage + random(damage);
		target->receive_damage("hp", damage/2);
		target->receive_wound("hp", damage);
        msg += "$n����û����ܣ�һʽ���ط���������ľ��С��𽣡��˶���";
        msg += "��������$n�ؿڣ�$nһ��ͷ�����������ؿڰγ���";
		me->add("mp", -200);
	} 
	else
	{
		me->start_busy(2);
        msg += "����$p����һЦ��������ת�������ָ��������$P�Ľ��ϣ���";
        msg += "����$p��໮�����������ˡ�";
		me->add("mp", -200);
	}
	message_vision(msg.c_str(), me, target);
	//if(!target->is_fighting(me)) target->kill_ob(me);
	return 1;
}

SKILL_END;




