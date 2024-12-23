
// qishang_quan.h ����ȭ
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSqishang_quan);

virtual void create()
{
	set_name( "����ȭ");

	set("valid_force", "jiuyang_shengong");

	Magic_t * magic;

	magic = add_magic("cangli", do_cangli);
	magic->name = "�����";
	magic->mp = 800;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("sunxin", do_sunxin);
	magic->name = "���ľ�";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("shangfei", do_shangfei);
	magic->name = "�˷ξ�";
	magic->mp = 600;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("sanjiao", do_sanjiao);
	magic->name = "���������";
	magic->mp = 2000;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("jingshi", do_jingshi);
	magic->name = "��ʧ��";
	magic->mp = 900;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("hunpo", do_hunpo);
	magic->name = "���Ƿ���";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("cuiganchang", do_cuiganchang);
	magic->name = "�ݸγ���";
	magic->mp = 700;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("yihuanghu", do_yihuanghu);
	magic->name = "���㱾�";
	magic->mp = 1000;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N������ɽ��һʽ�����������˫ȭ���ƶ���������$n��$l",180 , 5, 0, 0,"����",},
		{"$N�������أ�����������һʽ��ľ�ѳ��ۡ���������$n�Ƴ�", 200, 5, 10, 10,"����",},
		{"$N�������飬����������ޣ�һʽ��ˮ�����¡�����$n�޿ɶ���", 230, 15, 10, 20,"����",},
		{"$N����Ծ��һʽ���𺣵�ɽ����˫ȭ���ջ��£��Ʋ��ɵ�", 270, 5, 20, 30,"����",},
		{"$N����һ����һʽ�������������ȭ���¶��ϣ�����$n", 320,10 , 15, 40,"����",},
		{"$N����һת��һʽ������Ҳҡ�������$n����ǰ���", 380, 25, 25, 48,"����",},
		{"$N���λ�λ������ȭ����һʽ���������ա�������˷�����ȭӰ", 450, 15, 35, 54,"����",},
		{"$N��Хһ������ǰ̤��һ����˫ȭ�й�ֱ����һʽ�����߽��ˡ�����Ȼ����$n��ǰ��", 530, 20, 50, 60,"����",},
	};
 		
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("qishang_quan", 1))
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
	return (usage == "cuff") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon()  )
		return notify_fail("������ȭ������֡�");
	if ( me->query_skill("jiuyang_shengong", 1) < 10)
		return notify_fail("��ľ����񹦻�򲻹����޷�ѧ����ȭ��");
	if ( me->query("max_mp") < 50)
		return notify_fail("�������̫�����޷�������ȭ��");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if ( me->query("mp") < 20)
		return notify_fail("�����������������ȭ��");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
	
}

//perform 
static int do_cangli(CChar * me, CContainer * ob)
{
	string msg;
	CChar * target= NULL;
	
	if (ob && ob->is_character())
		target=(CChar *) ob;
	
    int skill = me->query_skill("qishang_quan",1) + me->query_skill("jiuyang_shengong",1);
	
    if( !target || !me->is_fighting(target) )
		return notify_fail("���������ֻ����ս����ʹ�á�");
	
    if(  me->query("mp") < 800 )
		return notify_fail("��������������ߣ�");
	
    if(  me->query_skill("cuff") < 120 )
		return notify_fail("���ȭ���������ң��޷���������ȭ�ĸ����ܾ���");
	
    if(  me->query_skill("qishang_quan", 1) < 120)
		return notify_fail("������ȭ����Ϊ���������ܹ��������! ");

	if(DIFFERSTR(me->querystr("family/family_name"), "����") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
    if(  me->query_skill("jiuyang_shengong", 1) < 120)
		return notify_fail( "��ľ�������Ϊ���㣬�������ʹ�ò����! "  );
	
    if( DIFFERSTR(me->query_skill_mapped("cuff"), "qishang_quan"))
		return notify_fail("��û�м�������ȭ���޷����ò������");
	
    msg =   "$N��������ʹ������ȭ�ܾ��еġ����������˫ȭ������������$n��ȥ��\n" ;
    	
    LONG ap = me->query_combat_exp() + skill * 500;
    LONG dp = target->query_combat_exp() / 4;
    if( dp < 1 )
		dp = 1;
    if( random(ap) > dp )
    {
		me->add("mp",-200);
		msg +=  "$n��$Nȭ��ɨ�У�ֻ��ȫ������ʧȴ��Ԧ�����⼱к��" ;
		int neili_wound = random(skill * 2);
		if(neili_wound > target->query("mp"))
			neili_wound = target->query("mp");
		target->add("mp", -neili_wound);
		target->receive_wound("hp", neili_wound);
		target->start_busy(2);
		me->start_busy(random(3));
    }
    else
    {
		msg +=   "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����" ;
		me->add("mp",-100);
		me->start_busy(2);
    }

    message_vision(msg.c_str(), me, target);
	
    return 1;
}

static int do_sunxin(CChar * me, CContainer * ob)
{
	string msg;
	CChar * target= NULL;
	
	if (ob && ob->is_character())
		target=(CChar *) ob;

    int skill = me->query_skill("qishang_quan",1) + me->query_skill("jiuyang_shengong",1);
	
    if( !target || !me->is_fighting(target) )
		return notify_fail("�����ľ���ֻ����ս����ʹ�á�");
	
    if(  me->query("mp") < 500 )
		return notify_fail("��������������ߣ�");
	
    if(  me->query_skill("cuff") < 60 )
		return notify_fail("���ȭ���������ң��޷���������ȭ�ĸ����ܾ���");
	
    if(  me->query_skill("qishang_quan", 1) < 60)
		return notify_fail("������ȭ����Ϊ���������ܹ�������ľ�! ");
	
    if(  me->query_skill("jiuyang_shengong", 1) < 60)
		return notify_fail( "��ľ�������Ϊ���㣬�������ʹ�����ľ�! "  );

	if(DIFFERSTR(me->querystr("family/family_name"), "����") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
    if( DIFFERSTR(me->query_skill_mapped("cuff"), "qishang_quan"))
		return notify_fail("��û�м�������ȭ���޷��������ľ���");
	
    msg =   "$N��������ʹ������ȭ�ܾ��еġ����ľ�����˫ȭ������������$n��ȥ��\n" ;
    	
    LONG ap = me->query_combat_exp() + skill * 500;
    LONG dp = target->query_combat_exp() / 4;
    if( dp < 1 )
		dp = 1;
    if( random(ap) > dp )
    {
		me->add("mp",-100);
		msg +=   "$N����ȭ������ף�$n����$N��ɽ��ʯ��һȭ����ʱ������𣬲���������У�" ;
		LONG attack_decrease =  target->query("apply/attack") / 10;
		target->add_temp("apply/attack", -attack_decrease);
		target->start_busy(2);
		me->start_busy(random(3));
    }
    else
    {
		msg +=   "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����" ;
		me->add("mp",-100);
		me->start_busy(2);
    }

    message_vision(msg.c_str(), me, target);
	
    return 1;
}

static int do_shangfei(CChar * me, CContainer * ob)
{
	string msg;
	CChar * target= NULL;
	
	if (ob && ob->is_character())
		target=(CChar *) ob;

    int skill = me->query_skill("qishang_quan",1) + me->query_skill("jiuyang_shengong",1);
	
    if( !target || !me->is_fighting(target) )
		return notify_fail("���˷ξ���ֻ����ս����ʹ�á�");
	
    if(  me->query("mp") < 600 )
		return notify_fail("��������������ߣ�");
	
    if(  me->query_skill("cuff") < 60 )
		return notify_fail("���ȭ���������ң��޷���������ȭ�ĸ����ܾ���");
	
    if(  me->query_skill("qishang_quan", 1) < 60)
		return notify_fail("������ȭ����Ϊ���������ܹ�����˷ξ�! ");
	
    if(  me->query_skill("jiuyang_shengong", 1) < 60)
		return notify_fail( "��ľ�������Ϊ���㣬�������ʹ���˷ξ�! "  );

	if(DIFFERSTR(me->querystr("family/family_name"), "����") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
    if( DIFFERSTR(me->query_skill_mapped("cuff"), "qishang_quan"))
		return notify_fail("��û�м�������ȭ���޷������˷ξ���");
	
    msg =   "$N��������ʹ������ȭ�ܾ��еġ��˷ξ�����˫ȭ������������$n��ȥ��\n" ;
    	
    LONG ap = me->query_combat_exp() + skill * 500;
    LONG dp = target->query_combat_exp() / 4;
    if( dp < 1 )
		dp = 1;
    if( random(ap) > dp )
    {
		me->add("mp",-100);
		
		msg +=   "$N��ȭ���������ף����족��һ������$n���ϣ�$nֻ���ú�����˳����ʱ�Ų�������࣡" ;
		LONG dodge_decrease =  target->query("apply/dodge") / 10;
		target->add_temp("apply/dodge", -dodge_decrease);
		target->start_busy(2);
		me->start_busy(random(3));
    }
    else
    {
		msg +=   "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����" ;
		me->add("mp",-100);
		me->start_busy(2);
    }

    message_vision(msg.c_str(), me, target);
    return 1;
}

static int do_sanjiao(CChar * me, CContainer * ob)
{
	string msg;
	CChar * target= NULL;
	
	if (ob && ob->is_character())
		target=(CChar *) ob;

	int skill = me->query_skill("qishang_quan",1) + me->query_skill("jiuyang_shengong",1);
	
    if( !target || !me->is_fighting(target) )
		return notify_fail("�������������ֻ����ս����ʹ�á�");
	
    if(  me->query("mp") < 2000 )
		return notify_fail("��������������ߣ�");
	
    if(  me->query_skill("cuff") < 200 )
		return notify_fail("���ȭ���������ң��޷���������ȭ�ĸ����ܾ���");
	
    if(  me->query_skill("qishang_quan", 1) < 200)
		return notify_fail("������ȭ����Ϊ���������ܹ�������������! ");
	
    if(  me->query_skill("jiuyang_shengong", 1) < 200)
		return notify_fail( "��ľ�������Ϊ���㣬�������ʹ�����������! "  );

	if(DIFFERSTR(me->querystr("family/family_name"), "����") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
    if( DIFFERSTR(me->query_skill_mapped("cuff"), "qishang_quan"))
		return notify_fail("��û�м�������ȭ���޷����������������");
	
    msg =   "$N����������ͼʹ������ȭ�ܾ��еġ�����������������з�����������\n" ;
	
	LONG ap = me->query_combat_exp() + skill * 400;
	LONG dp = target->query_combat_exp() / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		me->add("mp",-100);
		
		msg +=   "$nֻ������ǰһ���ʹ�����ۡ���һ�����һ����Ѫ��" ;
		int neili_wound = 100 + random(skill);
		if(neili_wound > target->query("mp"))
			neili_wound = target->query("mp");
		
		int qi_wound = neili_wound / 5;
		if(qi_wound > target->query("hp"))
			qi_wound = target->query("hp");
		
		target->add("mp", -neili_wound);
		target->receive_wound("hp", qi_wound);
		target->start_busy(2);
		me->start_busy(random(3));
	}
	else
	{
		msg +=   "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����" ;
		me->add("mp",-100);
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);
	//if(!target->is_fighting(me)) target->kill_ob(me);
	return 1;
}

static int do_jingshi(CChar * me, CContainer * ob)
{
	string msg;
	CChar * target= NULL;
	
	if (ob && ob->is_character())
		target=(CChar *) ob;

    int skill = me->query_skill("qishang_quan",1) + me->query_skill("jiuyang_shengong",1);
	
    if( !target || !me->is_fighting(target) )
		return notify_fail("����ʧ����ֻ����ս����ʹ�á�");
	
    if(  me->query("mp") < 900 )
		return notify_fail("��������������ߣ�");
	
    if(  me->query_skill("cuff") < 150 )
		return notify_fail("���ȭ���������ң��޷���������ȭ�ĸ����ܾ���");
	
    if(  me->query_skill("qishang_quan", 1) < 150)
		return notify_fail("������ȭ����Ϊ���������ܹ���ᾫʧ��! ");
	
    if(  me->query_skill("jiuyang_shengong", 1) < 150)
		return notify_fail( "��ľ�������Ϊ���㣬�������ʹ�þ�ʧ��! "  );

	if(DIFFERSTR(me->querystr("family/family_name"), "����") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
    if( DIFFERSTR(me->query_skill_mapped("cuff"), "qishang_quan"))
		return notify_fail("��û�м�������ȭ���޷����þ�ʧ����");
	
    msg =   "$N��������ʹ������ȭ�ܾ��еġ���ʧ������˫ȭ������������$n��ȥ��\n" ;
    	
    LONG ap = me->query_combat_exp() + skill * 500;
    LONG dp = target->query_combat_exp() / 4;
    if( dp < 1 )
		dp = 1;
    if( random(ap) > dp )
    {
		me->add("mp",-300);
		
		msg +=   "$N��ȭֻ�������������$n����$N����������һ˲����������$n���ڣ�$nֻ�����е�ƣ��������" ;
		int neili_wound = 100 + random(skill);
		if(neili_wound > target->query("mp"))
			neili_wound = target->query("mp");
		
		int jing_wound = random( skill);
		int eff_jing_wound = random( skill / 3);
		target->receive_wound("hp", jing_wound);
		target->receive_damage("hp", eff_jing_wound);
		me->start_busy(2);
    }
    else
    {
		msg +=   "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����" ;
		me->add("mp",-100);
		me->start_busy(3);
    }

    message_vision(msg.c_str(), me, target);
	
    return 1;
	
}

static int do_hunpo(CChar * me, CContainer * ob)
{
	string msg;
	CChar * target= NULL;
	
	if (ob && ob->is_character())
		target=(CChar *) ob;

    int skill = me->query_skill("qishang_quan",1) + me->query_skill("jiuyang_shengong",1);

	if( !target || !me->is_fighting(target) )
		return notify_fail("�����Ƿ��ֻ����ս����ʹ�á�");
	
	if(  me->query("mp") < 500 )
		return notify_fail("��������������ߣ�");
	
	if(  me->query_skill("cuff") < 150 )
		return notify_fail("���ȭ���������ң��޷�ʹ�û��Ƿ��");
	
	if(  me->query_skill("qishang_quan", 1) < 60)
		return notify_fail("������ȭ����Ϊ����������ʹ�û��Ƿ���! ");

	if(DIFFERSTR(me->querystr("family/family_name"), "����") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( DIFFERSTR(me->query_skill_mapped("cuff"), "qishang_quan") )
		return notify_fail("��û�м�������ȭ���޷�ʹ�û��Ƿ��");
	
	msg =   "$N���һ����ʹ������ȭ�ľ��������Ƿ����˫ȭ������������$n��ȥ��\n" ;
		
	LONG ap = me->query_combat_exp() + skill * 400;
	LONG dp = target->query_combat_exp() / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		me->add("mp",-100);
		
		msg +=   "$nֻ������ǰһ���ʹ�����ۡ���һ�����һ����Ѫ��" ;
		int neili_wound = 100 + random(skill);
		if(neili_wound > target->query("mp"))
			neili_wound = target->query("mp");
		
		int qi_wound = neili_wound / 5;
		if(qi_wound > target->query("hp"))
			qi_wound = target->query("hp");
		
		target->add("mp", -neili_wound);
		target->add("hp", -qi_wound);
		target->start_busy(2);
		me->start_busy(random(2));
	}
	else
	{
		msg +=   "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����" ;
		me->add("mp",-100);
		me->start_busy(4);
	}
	message_vision(msg.c_str(), me, target);
	
	return 1;
	
}

static int do_cuiganchang(CChar * me, CContainer * ob)
{
	string msg;
	CChar * target= NULL;
	
	if (ob && ob->is_character())
		target=(CChar *) ob;

    int skill = me->query_skill("qishang_quan",1) + me->query_skill("jiuyang_shengong",1);
	
    if(!target || !me->is_fighting(target) )
		return notify_fail("���ݸγ�����ֻ����ս����ʹ�á�");
	
    if(  me->query("mp") < 700 )
		return notify_fail("��������������ߣ�");
	
    if(  me->query_skill("cuff") < 120 )
		return notify_fail("���ȭ���������ң��޷���������ȭ�ĸ����ܾ���");
	
    if(  me->query_skill("qishang_quan", 1) < 90)
		return notify_fail("������ȭ����Ϊ���������ܹ����ݸγ���! ");

	if(DIFFERSTR(me->querystr("family/family_name"), "����") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
    if(  me->query_skill("jiuyang_shengong", 1) < 90)
		return notify_fail( "��ľ�������Ϊ���㣬�������ʹ�ôݸγ���! "  );
	
    if( DIFFERSTR(me->query_skill_mapped("cuff"), "qishang_quan"))
		return notify_fail("��û�м�������ȭ���޷����ôݸγ�����");
	
    msg =   "$N��������ʹ������ȭ�ܾ��еġ��ݸγ�������˫ȭ������������$n��ȥ��\n" ;
    	
    LONG ap = me->query_combat_exp() + skill * 500;
    LONG dp = target->query_combat_exp() / 4;
    if( dp < 1 )
		dp = 1;
    if( random(ap) > dp )
    {
		me->add("mp",-200);
		
		msg +=   "$nǰ������$Nȫ��һ����ֻ��һ���ʹ�����ۡ���һ�����һ����Ѫ��" ;
		int qi_wound = 250 + random(skill);
		if(qi_wound > target->query("hp"))
			qi_wound = target->query("hp");
		
		target->receive_wound("hp", qi_wound);
		target->start_busy(2);
		me->start_busy(random(3));
    }
    else
    {
		msg +=   "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����" ;
		me->add("mp",-100);
		me->start_busy(2);
    }

    message_vision(msg.c_str(), me, target);
	
    return 1;
	
}

static int do_yihuanghu(CChar * me, CContainer * ob)
{
	string msg;
	CChar * target= NULL;
	
	if (ob && ob->is_character())
		target=(CChar *) ob;

    int skill = me->query_skill("qishang_quan",1) + me->query_skill("jiuyang_shengong",1);
	
    if( !target || !me->is_fighting(target) )
		return notify_fail("�����㱾���ֻ����ս����ʹ�á�");
	
    if(  me->query("mp") < 1000 )
		return notify_fail("��������������ߣ�");
	
    if(  me->query_skill("cuff") < 150 )
		return notify_fail("���ȭ���������ң��޷���������ȭ�ĸ����ܾ���");
	
    if(  me->query_skill("qishang_quan", 1) < 150)
		return notify_fail("������ȭ����Ϊ���������ܹ�������㱾�! ");

	if(DIFFERSTR(me->querystr("family/family_name"), "����") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
    if(  me->query_skill("jiuyang_shengong", 1) < 150)
		return notify_fail( "��ľ�������Ϊ���㣬�������ʹ�����㱾�! "  );
	
    if( DIFFERSTR(me->query_skill_mapped("cuff"), "qishang_quan"))
		return notify_fail("��û�м�������ȭ���޷��������㱾���");
	
    msg =   "$N��������ʹ������ȭ�ܾ��еġ����㱾�����˫ȭ������������$n��ȥ��\n" ;
    	
    LONG ap = me->query_combat_exp() + skill * 500;
    LONG dp = target->query_combat_exp() / 4;
    if( dp < 1 )
		dp = 1;
    if( random(ap) > dp )
    {
		me->add("mp",-300);
		msg +=  "���$N˫ȭ����ʱ��ȴ���������ޡ�\n$n������ּ䣬�ѱ�$N��������ס������лк����ģ�" ;
		target->start_busy( skill/20);
		me->start_busy(2);
    }
    else
    {
		msg +=   "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����" ;
		me->add("mp",-100);
		me->start_busy(4);
    }
    message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;
