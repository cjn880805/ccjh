// jinding_zhang.h ������
//code by Fisho
//date : 2000-12-02

SKILL_BEGIN(CSjinding_zhang);

virtual void create()
{
	set_name( "������");
	set("valid_force", "linji_zhuang");

	
	Magic_t * magic;

	magic = add_magic("bashi", do_bashi);
	magic->name = "��ʽ��һ";
	magic->mp = 200;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge;
		char damage_type[5];
		int lvl;
	}action[] = {
		{"$N����΢�Σ�һ�С�������̩�������������$nֻ����һ��ů��Ϯ��$l", 100, 10,"����", 0,},
		{"$N˫�ֱ�ã���ָ�ᵯ��һ�С��������项��������·������ʮ����ץ��$n��$l", 120, 10,"����",11 ,},
		{"$N����ǰ��������ٿ��������ͷ�һ�С�����ơ�����ץ��$n��$l", 150,15 ,"����", 22,},
		{"$N����Ȧת�����$n�����֣������Ƴ������������Ļ���һ�С�������ɳ�����͵ػ���$n���°�", 200, 25,"����", 33,},
		{"$N�������ף�һ�����ȣ���$nһ㶼䣬����һ�С��׶���������ֱ��$n��$l", 100, 10,"����", 44,},
		{"$N˫��ƽ����ȭ����¶΢Ц��$n��㱼俴��$N����Ϊ�������$N���������һ�С��𶥷�⡹��֪��������ʵ���Ʒ��Ѿ�Ϯ��", 200,15 ,"����", 55,},
		{"$Nһ������ׯ�ϣ�ʹ�������Ľ�ħ����������磬����$nƯ�Ʋ���",230, 20 ,"����", 66,},
		{"$Nȫ�����ߣ�˫�ۼ��裬��Ϊ�����Ӱ��һ�С�����˻ġ�����ǵ�Ϯ��$nȫ�������Ѩ", 300, 30,"����", 77,},
	};
	
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("jinding_zhang", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "strike") || (usage == "parry");
}

virtual int valid_combine(string combo) { return combo=="tiangang_zhi"; }

virtual int valid_learn(CChar * me)
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("���ʦ����ʱû��ָ�����书����");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("����ʱ�޷�ָ������µ��书����");

	if ( me->query_weapon() )
		return notify_fail("�������Ʊ�����֡�");
	
	if (me->query_skill("linji_zhuang", 1) < 10)
		return notify_fail("����ټ�ׯ�ķ���򲻹��������������ơ�");
	if (me->query("max_mp") < 30)
		return notify_fail("�������̫�����޷��������ơ�");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if (me->query_skill("jinding_zhang", 1) < 100)
		me->receive_damage("hp", 10);
	else
        me->receive_damage("hp", 20);
	return 1;
}

//perform 
static int do_bashi(CChar * me, CContainer * ob)
{
	string msg;
	int damage;
	CChar * target = NULL;
	
	if(! ob || !ob->is_character())
		return notify_fail("����ʽ��һ��Ҫ��˭ʹ�ã�");

	target = (CChar *)ob;

	if( !me->is_fighting(target) )
		return notify_fail("����ʽ��һ��ֻ����ս����ʹ�á�");
	
	if( target->query_temp("bashi") )
		return notify_fail("���Ѿ����˹����ˡ�");
	
	if( me->query("mp") < 200 )
		return notify_fail("��������������ߣ�");
	
	if( me->query_skill("linji_zhuang", 1) < 40)
		return notify_fail("����ټ�ʹ��ׯ����Ϊ����������ʹ�ð�ʽ��һ!");
	
	if( me->query_skill("jinding_zhang",1) <100)
		return notify_fail("��Ľ����Ƶİ�ʽ��ϰ��ȫ���޷�ʹ�ð�ʽ��һ��");
	
	if( DIFFERSTR(me->query_skill_mapped("strike"), "jinding_zhang"))
		return notify_fail("��û�м��������ƣ��޷�ʹ�ð�ʽ��һ��");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( !target->is_killing(me) ) target->kill_ob(me);
	
	msg =  "$N��������һ����������ȫ��Ĺ�����˫�ƣ�ֻ����$N����һ���죡" ;
	if( random(me->query_combat_exp() + 1) > target->query_combat_exp()/2)
	{
		damage = me->query_skill("linji_zhuang", 1)/2;
		damage = damage +  me->query_skill("jinding_zhang", 1);
		target->set_temp("bashi", 1);
		target->add_temp("apply/attack", -damage/3);
		target->add_temp("apply/dodge", -damage/3);
		msg +=  "$N�ڿն���ʹ���ˡ���ʽ��һ�����������Ӱ��Ʈ������������$nȫ�������λ��" ;
		target->call_out( remove_effect, damage/3, damage/3);
		me->add("mp",-100);
		target->start_busy(3);
		target->SendState(target);
	}
	else 
	{
		msg += "����$p�͵���ǰһԾ,������$P�Ĺ�����Χ��";
		me->start_busy(1);
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

static void remove_effect(CContainer *ob,LONG amount,LONG param)
{
	CChar * target=(CChar *)ob;
	target->add_temp("apply/attack", amount);
	target->add_temp("apply/dodge", amount);
	target->delete_temp("bashi");
	target->SendState(target);
	message_vision("$HIR$N�����ҵĹ����а����˳�������������,��ס�˽Ų�", target);

}

SKILL_END;




