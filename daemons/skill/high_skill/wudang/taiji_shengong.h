// taiji_shengong.c ̫����

FORCE_BEGIN(CStaiji_shengong);

virtual void create()
{
	CForce::create();

	set_name( "̫����");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "������";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("powerup", do_powerup);
	magic->name = "������";
	magic->mp = 150;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
}


int valid_enable(string usage) { return usage == "force"; }

virtual int valid_learn(CChar * me)
{
	int lvl = me->query_skill("taiji_shengong", 1);
	int t = 1, j;
	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;

	if ( EQUALSTR(me->querystr("gender"), "����") && lvl > 49)
		return notify_fail("���޸����ԣ����������������������̫���񹦡�");

	if ( EQUALSTR(me->querystr("class"), "bonze") )
		return notify_fail("̫���񹦽����������ϣ���Υ��������徻֮��");

	if (me->query_skill("force", 1) < 10)
			return notify_fail("��Ļ����ڹ���򻹲�����");
	
	if(lvl<=100)
	{
		if (lvl > 10 && me->query("repute") < t * 100) 
			return notify_fail("�����������̫����");
	}
	else
	{
		if (me->query("repute") < (51200 + (lvl - 100) * 1000)) 
			return notify_fail("�����������̫���ˡ�");
	}
	
	if ( me->query_skill("bibo_shengong",1)
	|| me->query_skill("beimin_shengong",1)
	|| me->query_skill("bahuang_gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong_dafa",1)
	|| me->query_skill("huntian_qigong",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong_shengong",1)
	|| me->query_skill("seaforce",1)
	|| me->query_skill("shenlong_xinfa",1)
	|| me->query_skill("kuihua_xinfa",1)
	|| me->query_skill("zixia_shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ̫���񹦣�");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("̫����ֻ������̵������������ȡ�");
}

//exert heal
static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������");

	if (me->query_skill("taiji_shengong", 1) < 30)
		return notify_fail("���̫������Ϊ��������");
	
	if( me->query("mp") < 50 )
		return notify_fail("�������������");

	if( me->query("eff_hp") < me->query("max_hp") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�");

	tell_object(me, "���Ϣ������Ĭ���ڹ���ʼ�˹����ˡ�");
	tell_room(me->environment(), snprintf(msg, 255, "%s�³�һ����Ѫ����ɫ�������ö��ˡ�", me->name()), me);
	
	me->receive_curing("hp", 10 + me->query_skill("force") / 4 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	me->start_busy(4);
	return 1;
}
	
static int do_powerup(CChar * me, CContainer * ob)
{
	int skill;

	if( ob != me )
		return notify_fail("��ֻ����̫�����������Լ���ս������");

	if( me->query("mp") < 150  )
		return notify_fail("�������������");
		
	if(DIFFERSTR(me->querystr("family/family_name"), "�䵱��") && me->querymap_temp("biwu"))
	        return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if( me->querymap_temp("powerup") )
		return notify_fail("���Ѿ����˹����ˡ�");

	skill = me->query_skill("force");
	me->add("mp", -100);
	me->receive_damage("hp", 0);
	message_vision("$N΢һ��������̫���񹦣�ȫ����������������޷����裬�������ˡ�", me);

	start_powerup(me, skill, skill / 3, skill * 3 / 5, "���̫����������ϣ��������ջص��");
	if( me->is_fighting() ) me->start_busy(3);
	return 1;
}

FORCE_END;
