FORCE_BEGIN(CSxiaowuxiang);

virtual void create()
{
	CForce::create();

	set_name( "С���๦");

	Magic_t * magic;

	magic = add_magic("life_heal", do_life_heal);
	magic->name = "ҽ����";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("shield", do_shield);
	magic->name = "������";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual int valid_learn(CChar * me)
{
	int i = me->query_skill("xiaowuxiang", 1);
	int t = 1, j;

	for (j = 1; j < i / 10; j++) t*= 2;

	if ((DIFFERSTR(me->querystr("class"), "bonze")) && i > 29)
		return notify_fail("�㲻��ɮ�ˣ�ѧ���˸����С���๦��");

	if (me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ�����㣬����ѧС���๦��");

	if ( EQUALSTR(me->querystr("gender"), "����") && i > 49)
		return notify_fail("���޸����ԣ����������������������С���๦��");

	if (i > 10 && me->query("repute") > t * 100)
		return notify_fail("ҪѧС���๦����ı��ֻ������ɣ� ");

	if ( me->query_skill("bibo_shengong",1)
	|| me->query_skill("beiming_shengong",1)
	|| me->query_skill("bahuang_gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong_dafa",1)
	|| me->query_skill("huntian_qigong",1)
	|| me->query_skill("hunyuan_yiqi",1)
//	|| me->query_skill("longxiang",1)
	|| me->query_skill("jiuyang_shengong",1)
	|| me->query_skill("taiji_shengong",1)
//	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong_shengong",1)
	|| me->query_skill("zixia_shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧС���๦��");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("С���๦ֻ����ѧ�������������ȡ�");
}

virtual int valid_enable(string usage) { return usage == "force"; }

static int do_life_heal(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target )
		return notify_fail("��Ҫ������Ϊ˭���ˣ�");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�");

	if(target == me)
		return notify_fail("��û��Ϊ�Լ����˵�������");

	if( me->query("max_mp") < 300 )
		return notify_fail("���������Ϊ������");

	if( me->query("mp") < 150 )
		return notify_fail("�������������");

	if( target->query("eff_hp") < target->query("max_hp") / 5 )
		return notify_fail( "%s�Ѿ����˹��أ����ܲ�����������𵴣�", target->name());

	if( target->query("eff_hp") >= target->query("max_hp"))
		return notify_fail("%sû�����ˡ�", target->name());

	message_vision("$HIY$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�$COM", 	me, target );
	target->receive_curing("hp", 10 + me->query_skill("force")/3 );
	target->add("hp", 10 + me->query_skill("force")/3 );
	if( target->query("hp") > target->query("eff_hp") ) 
		target->set("hp", target->query("eff_qi"));

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

static int do_shield(CChar * me, CContainer * ob)
{
	int skill;

	if( ob != me ) 
		return notify_fail("��ֻ����С���๦�������Լ��ķ�������\n");

	if( me->query("mp") < 100  ) 
		return notify_fail("�������������");

	if( me->query_temp("shield") ) 
		return notify_fail("���Ѿ����˹����ˡ�");

	skill = me->query_skill("force");
	me->add("mp", -100);
	me->receive_damage("hp", 0);

	message_vision("$HIW$N˫��ƽ�ٹ���������С���๦��ȫ�������ھ���֮�У�$COM", me);

	me->add_temp("apply/armor", skill*2);
	me->set_temp("shield", 1);

	me->call_out(remove_effect, skill, skill*2);

	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

static void remove_effect(CContainer * ob, LONG amount, LONG param2)
{
	CChar * me = (CChar *)ob;

	me->add_temp("apply/armor", - amount);
	me->delete_temp("shield");
	me->SendState(me);
	tell_object(me, "���С���๦������ϣ��������ջص��");
}

FORCE_END;