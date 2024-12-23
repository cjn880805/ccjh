// linji_zhuang.h �ټ�ʮ��ׯ//

FORCE_BEGIN(CSlinji_zhuang);

virtual void create()
{
	CForce::create();

	set_name( "�ټ�ʮ��ׯ");

	Magic_t * magic;

	magic = add_magic("life_heal", do_life_heal);
	magic->name = "������";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("powerup", do_powerup);
	magic->name = "������";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
}


virtual int valid_enable(string usage) { return usage == "force"; }

virtual int valid_learn(CChar * me)
{
	int np, nf, nh, ns ;
	nf = me->query_skill("force", 1);
	nh = me->query_skill("linji_zhuang", 1);
	np = me->query_skill("mahayana", 1);
	ns = me->query("guilty");
	
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("���ʦ����ʱû��ָ�����书����");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("����ʱ�޷�ָ������µ��书����");

	if ( me->querymap("couple") || me->query("max_atman"))
		return notify_fail("���Ѿ�����ɫ�䣬�޷���ѧϰ�ټ�ʮ��ׯ��");
	
	if ( DIFFERSTR(me->querystr("gender"), "Ů��") )
		return notify_fail("��Ǵ�Ů֮�壬������ϰ�ټ�ʮ��ׯ��");
	
	
	if ( DIFFERSTR(me->querystr("class"), "bonze"))
		return notify_fail("�㲻����ã�ѧ���˸�����ټ�ʮ��ׯ��");
	
	if ( np <= nh && nh <= 150)
		return notify_fail("��Ĵ�����͹���Ϊ�������޷�����������ټ�ʮ��ׯ��");
	
	if ( nf < 10)
		return notify_fail("��Ļ����ڹ���򻹲������޷�����ټ�ʮ��ׯ��");
	
	if ( ns > 0 ) 
		return notify_fail("���ŷ�ɮ�����䣬�޷�����������ټ�ʮ��ׯ��");
	
	if (
		me->query_skill("bahuang_gong",1)
		|| me->query_skill("beiming_shengong",1)
		|| me->query_skill("bibo_shengong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1)
		|| me->query_skill("huntian_qigong",1)
		|| me->query_skill("hunyuan_yiqi",1)
		|| me->query_skill("jiuyang_shengong",1)
		|| me->query_skill("kuihua_xinfa",1)
		|| me->query_skill("kurong_changong",1)
		|| me->query_skill("longxiang",1)
	//	|| me->query_skill("mizong_xinfa",1)
		|| me->query_skill("shenlong_xinfa",1)
		|| me->query_skill("taiji_shengong",1)
		|| me->query_skill("xiantian_qigong",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("yijinjing",1)
		|| me->query_skill("yunlong_shengong",1)
		|| me->query_skill("yunv_xinfa",1)
		|| me->query_skill("zixia_shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�ټ�ʮ��ׯ����");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("�ټ�ʮ��ׯֻ������̵������������ȡ�");
}

virtual void skill_improved(CChar* me)
{
	switch (me->query_skill("linji_zhuang",1))
	{
	case 30:
		tell_object(me,  "�����ׯ������! "  );
		break;
	case 60:
		tell_object(me,  "��֮��ׯ������! "  );
		break;
	case 90:
		tell_object(me,  "������ׯ������! "  );
		break;
	case 120:
		tell_object(me,  "�����ׯ������! "  );
		break;
	case 150:
		tell_object(me,  "���Сׯ������! "  );
		break;
	case 180:
		tell_object(me,  "����ڤׯ������! "  );
		break;
		
	}
	return;
}

//Ϊ������
static int do_life_heal(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if ( ! target || target == me)
		return notify_fail("��Ҫ������Ϊ˭���ˣ�");
    
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�");
	
    if( me->query_skill("linji_zhuang",1) < 20 )
		return notify_fail("���������Ϊ������");
	
    if( me->query("max_mp") < 300 )
		return notify_fail("���������Ϊ������");
	
    if( me->query("mp") < 150)
		return notify_fail("�������������");
	
    if( target->query("eff_hp") < target->query("max_hp") / 5 )
		return notify_fail(  "%s�Ѿ����˹��أ����ܲ�����������𵴣�",target->name());

	if( target->query("eff_hp") >= target->query("max_hp"))
		return notify_fail("%sû�����ˡ�", target->name());
	
    message_vision( "$N�������������ڹ�������������$n���ģ������ؽ���������$n����...."
		"���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�" ,
		me, target );
	
	target->receive_curing("hp", 10 + me->query_skill("force")/2 );
	target->add("hp", 10 + me->query_skill("force")/3 );
	if( target->query("hp") > target->query("eff_hp") ) target->set("hp", target->query("eff_hp"));
		
	me->add("mp", -150);
	me->set("mp_factor", 0l);

	//���˾��齱��    �ز� 2002��7��18
	char expmsg[80];
	int addexp = me->query("level") / 4 + 1;
	int addrpt = 10 - target->query("level");

	addexp = int(((addexp + random(addexp)) / 2) *0.5);
	if(addrpt < 1) addrpt = 1;
	addrpt = (addrpt + random(addrpt)) / 2;

	addexp=1;
	addrpt=1;
	me->add("combat_exp", addexp);
	me->add("repute", addrpt);
	
	tell_object(me, snprintf(expmsg, 80, "������������%ld�㣡���������%ld�㣡", addexp, addrpt));
	//���˾��齱��

	me->start_busy(5);
	target->start_busy(5);

	return 1;
	
}
	
static int do_powerup(CChar * me, CContainer * ob)
{
	int skill;

    if( ob != me )
		return notify_fail("��ֻ�����ټ�ׯ�������Լ���ս������");

    if( me->query("mp") < 100 ) 
		return notify_fail("�������������");

    if( me->querymap_temp("powerup") )
		return notify_fail("���Ѿ����˹����ˡ�");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
    skill = me->query_skill("force");
	
    me->add("mp", -100);
    me->receive_damage("hp",0);
	
    message_vision("$N΢һ���������ټ�ׯ��һ�����ȣ�" , me);
	    
	start_powerup(me, skill, skill/3, skill/3, "����ټ�ׯ������ϣ��������ջص��");
    if( me->is_fighting() ) me->start_busy(3);
    return 1;
}

FORCE_END;



