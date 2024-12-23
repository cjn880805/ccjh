// kurong_changong.c ��������

FORCE_BEGIN(CSkurong_changong);

virtual void create()
{
	CForce::create();

	set_name( "��������");

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
	if ( EQUALSTR(me->querystr("gender"), "����"))
		return notify_fail("���޸����ԣ���������������������Ŀ���������");
	
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
		//	|| me->query_skill("kurong_changong",1)
		|| me->query_skill("linji_zhuang",1)
		|| me->query_skill("longxiang",1)
		|| me->query_skill("mizong_xinfa",1)
		|| me->query_skill("shenlong_xinfa",1)
		|| me->query_skill("xiantian_qigong",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("yijinjing",1)
		|| me->query_skill("yunlong_shengong",1)
		|| me->query_skill("yunv_xinfa",1)
		|| me->query_skill("zixia_shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ������������");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("��������ֻ������̵������������ȡ�");
}

//exert heal
static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������");
	
	if (me->query_skill("kurong_changong", 1) < 20)
		return notify_fail("��Ŀ���������Ϊ��������");

	if( me->query("mp") < 50 ) 
		return notify_fail("�������������");
	
	if( me->query("eff_hp") < me->query("max_hp") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�");
	
	tell_object( me, "��ȫ����ɣ���������ʼ�˹����ˡ�" );
	tell_room(me->environment(), snprintf(msg, 255, "%s�³�һ����Ѫ����ɫ�������ö��ˡ�", me->name()), me);
	
	me->receive_curing("hp", 10 + me->query_skill("force")/5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	
	return 1;
}

static int do_powerup(CChar * me, CContainer * ob)
{
	int skill;

	if( ob != me )
		return notify_fail("��ֻ���ÿ��������������Լ���ս������");

	if( me->query("mp") < 150  )
		return notify_fail("�������������");
	if( me->querymap_temp("powerup") )
		return notify_fail("���Ѿ����˹����ˡ�");

	if(DIFFERSTR(me->querystr("family/family_name"), "����μ�") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	skill = me->query_skill("force");
	me->add("mp", -50);
	me->receive_damage("hp", 0);
	message_vision( "$N��������������������������α�ȫ��" ,me);
	
	start_powerup(me, skill, skill/3, skill/3, "��Ŀ�������������ϣ��������ջص��");

	if( me->is_fighting() ) me->start_busy(3);
	return 1;
}

FORCE_END;
