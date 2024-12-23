// zixia_shengong.h ��ϼ��
//code by Fisho
//date : 2000-12-06

FORCE_BEGIN(CSzixia_shengong);

virtual void create()
{
	CForce::create();

	set_name( "��ϼ��");

	
	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "������";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("powerup", do_powerup);
	magic->name = "������";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("life_heal", do_life_heal);
	magic->name = "ҽ����";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force") ;
}

virtual int valid_learn(CChar * me)
{
	int i =  me->query_skill("zixia_shengong", 1);
	int t = 1, j;
	
	if(i <= 100)
		for (j = 1; j < i / 10; j++)
			t *= 2;
		
	if ( EQUALSTR(me->querystr("gender"), "����") && i > 49)
		return notify_fail("���޸����ԣ������������������������ϼ�񹦡�");
	
	if ( me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����������ѧϰ��ϼ�񹦡�");
	
	if(i<=100)
	{
		if (i > 10 &&  me->query("repute") < t * 100) 
			return notify_fail("�����������̫���ˣ��޷������������ϼ�񹦡�");
	}
	else
	{
		if ( me->query("repute") < (51200 + (i - 100) * 1000)) 
			return notify_fail("�����������̫���ˣ��޷������������ϼ�񹦡�");
	}
	
	if ( me->query_skill("bibo_shengong",1)
		|| me->query_skill("beiming_shengong",1)
		|| me->query_skill("bahuang_gong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1)
		|| me->query_skill("huntian_qigong",1)
		|| me->query_skill("hunyuan_yiqi",1)
		|| me->query_skill("longxiang",1)
		|| me->query_skill("jiuyang_shengong",1)
		|| me->query_skill("taiji_shengong",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("shenlong_xinfa",1)
		|| me->query_skill("seaforce",1)
	//	|| me->query_skill("zixia_shengong",1) 
		|| me->query_skill("yunlong_shengong",1))
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��ϼ�񹦣���");
	
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("��ϼ��ֻ������̵������������ȡ�");
}

//perform 
static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������");
	
	if ( me->query_skill("zixia_shengong", 1) < 20)
		return notify_fail("�����ϼ����Ϊ��������");
	if(  me->query("mp") < 50 ) 
		return notify_fail("�������������");
	
	if(  me->query("eff_hp") <  me->query("max_hp") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�");
	
	tell_object( me, "��ȫ����ɣ���������ʼ�˹����ˡ�" );
	tell_room(me->environment(), snprintf(msg,255, "%s�³�һ����Ѫ����ɫ�������ö��ˡ�" , me->name() ),me);
	
	me->receive_curing("hp", 10 +  me->query_skill("force")/5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	me->start_busy(4);
	
	return 1;
	
}

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
	
	if(  me->query("max_mp") < 300 )
		return notify_fail("���������Ϊ������");
	
	if(  me->query("mp") < 150 )
		return notify_fail("�������������");
	
	if(  target->query("eff_hp") <  target->query("max_hp") / 5 )
		return notify_fail("%s�Ѿ����˹��أ����ܲ������������", target->name());

	if( target->query("eff_hp") >= target->query("max_hp"))
		return notify_fail("%sû�����ˡ�", target->name());
	
	message_vision("$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�" , me, target );
	
	target->receive_curing("hp", 10 +  me->query_skill("force")/3 );
	target->add("hp", 10 +  me->query_skill("force")/3 );
	if(  target->query("hp") >  target->query("eff_hp") ) target->set("hp",  target->query("eff_hp"));
	
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
		return  notify_fail("��ֻ������ϼ�������Լ���ս������");
    if(  me->query("mp") < 100 )
		return  notify_fail("�������������");
    if(  me->querymap_temp("powerup") )
		return  notify_fail("���Ѿ����˹����ˡ�");
	if(DIFFERSTR(me->querystr("family/family_name"), "��ɽ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
    skill = me->query_skill("force");
	
    me->add("mp", -100);
    me->receive_damage("hp",0);
	
    message_vision("$N΢һ����������ϼ�񹦣���ת��ȥ������ͻȻ������ʢ��ֻ��������һ�ּ�����ת�������������ֻظ��糣��" , me);
		
	start_powerup(me, skill, skill/3, skill/3, "�����ϼ��������ϣ��������ջص��");
    if( me->is_fighting() ) me->start_busy(3);
    return 1;
	
}

FORCE_END;
