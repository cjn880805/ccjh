// beiming_shengong.h ��ڤ��

void beiming_remove_effect(CContainer * ob, LONG amount, LONG param)
{
	CChar * me = (CChar *)ob;

	me->add_temp("apply/armor", - amount);
	me->delete_temp("shield");

	me->SendState(me);

	tell_object(me, "��ı�ڤ��������ϣ��������ջص��");
}

void del_sucked(CContainer * ob, LONG amount, LONG param)
{
	CChar * me = (CChar *) ob;
	me->delete_temp("sucked");
}

FORCE_BEGIN(CSbeiming_shengong);

virtual void create()
{
	CForce::create();

	set_name( "��ڤ��");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "������";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("shield", do_shield);
	magic->name = "������";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("maxsuck", do_maxsuck);
	magic->name = "������";
	magic->mp = 20;
	magic->ap = 35;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("neilisuck", do_neilisuck);
	magic->name = "������";
	magic->mp = 20;
	magic->ap = 35;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;
}


int valid_enable(string usage) { return usage == "force"; }

virtual int valid_learn(CChar * me)
{
	int lvl = me->query_skill("beiming_shengong", 1);
	if ( EQUALSTR(me->querystr("gender"), "����") && lvl > 49)
		return notify_fail("���޸����ԣ���������������������ı�ڤ�񹦡�");

	if ( me->query_skill("bibo_shengong",1)
//	|| me->query_skill("beiming_shengong",1)
//	|| me->query_skill("bahuang_gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong_dafa",1)
	|| me->query_skill("huntian_qigong",1)
	|| me->query_skill("hunyuan_yiqi",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("shenghuo_shengong",1)
	|| me->query_skill("xiantian_shengong",1)
	|| me->query_skill("yunv_xinjing",1)
	|| me->query_skill("tianlong_shengong",1)
	|| me->query_skill("wuzheng_xinfa",1)
	|| me->query_skill("jiuyang_shengong",1)
	|| me->query_skill("taiji_shengong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong_shengong",1)
	|| me->query_skill("zixia_shengong",1) 
	|| me->query_skill("jiuyang_shengong",1) 
	|| me->query_skill("kurong_changong",1) ) 
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��ڤ�񹦣�");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("��ڤ��ֻ������̵������������ȡ�");
}

//exert heal
static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������");

	if (me->query_skill("beiming_shengong", 1) < 20)
		return notify_fail("��ı�ڤ����Ϊ��������");
	
	if( me->query("mp") < 50 )
		return notify_fail("�������������");

	if( me->query("eff_hp") < me->query("max_hp") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�");

	tell_object(me, "��ȫ����ɣ���������ʼ�˹����ˡ�");
	tell_room(me->environment(), snprintf(msg, 255, "%s�³�һ����Ѫ����ɫ�������ö��ˡ�", me->name()), me);
	
	me->receive_curing("hp", 10 + me->query_skill("force") / 5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	return 1;
}

static int do_shield(CChar * me, CContainer * ob)
{
	if( ob != me ) 
		return notify_fail("��ֻ���ñ�ڤ���������Լ��ķ�������");

	if( me->query("mp") < 100  ) 
		return notify_fail("�������������");

	if(DIFFERSTR(me->querystr("family/family_name"), "��ң��") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if( me->query_skill("beiming_shengong",1) < 40 ) 
		return notify_fail("��ı�ڤ����Ϊ������");

	if( me->query_temp("shield") ) 
		return notify_fail("���Ѿ����˹����ˡ�");

	int skill = me->query_skill("force");
	me->add("mp", -100);
	me->receive_damage("hp", 0);
	message_vision("$N˫��ƽ�ٹ���������ڤ�񹦣�ȫ�������ھ���֮�У�", me);
	me->set_temp("shield", 1);
	
	me->add_temp("apply/armor", skill * 2);
	me->call_out(beiming_remove_effect, skill, skill * 2);
	
	if( me->is_fighting() ) me->start_busy(2);
	return 1;
	
}

static int do_maxsuck(CChar * me, CContainer * ob)
{
	int sp, dp;
	int my_max, tg_max;
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( (me->environment())->query("no_fight") )
		return notify_fail("�����ﲻ�ܹ������ˡ�");


	if(DIFFERSTR(me->querystr("family/family_name"), "��ң��") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if( ! target || target == me || EQUALSTR(target->querystr("id"), "mu ren") )
		return notify_fail("��Ҫ��ȡ˭�ĵ�Ԫ��");

    if (DIFFERSTR(target->querystr("race"), "����"))
		return notify_fail("����ˣ�ֻ���˲����е�Ԫ��");
	
    my_max = me->query("max_mp");
    tg_max = target->query("max_hp");
	if ( me->query_temp("sucked") )
		return notify_fail("��ո���ȡ����Ԫ��");
	
	if (me->query_weapon())
		return notify_fail("�������ֲ���ʩ�ñ�ڤ�����˵�Ԫ��");
	
    if( ! me->is_fighting(target) )
		return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�");

	if( me->query_skill("beiming_shengong",1) < 90 )
		return notify_fail("��ı�ڤ�񹦹���������������ȡ�Է��ĵ�Ԫ��");
	
	if( me->query("mp") < 20 )
		return notify_fail("�����������������ʹ�û����󷨡�");

	if( me->query_skill("force") < me->query("max_mp") /10 )
		return notify_fail("����ڹ�̫���ˣ�����ȡҲ��ͽ�͡�");

	if( target->query("max_mp") < 100 )
		return notify_fail( "%s��Ԫ��ɢ������δ�ۣ����޷�����������ȡ�κζ�����", target->name());

	if( target->query("max_mp") < me->query("max_mp")/10 )
		return notify_fail( "%s���ڹ���ΪԶ�����㣬���޷�����������ȡ��Ԫ��", target->name());

	message_vision("$Nȫ��һ��������֣���������$n���ֱ��ϡ�", me, target );
	
	if ( living(target))
	{
		target->kill_ob(me);		
	}

	sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("lingboweibu",1)/2 + 1;
	dp = target->query_skill("force") + target->query_skill("dodge") + 1;
	me->set_temp("sucked", 1);
		
	if (( random(sp) > random(dp) ) || ! living(target) )
	{
		tell_object(target, "��ֻ��ȫ������ȫ��������ѩ����ʧ����Ӱ���٣�");
		tell_object(me, snprintf(msg, 255, "�����%s�ĵ�Ԫ������ԴԴ���������˽�����", target->name()));
		
		int idx;
		if(me->query_temp("taozhuang/g_3"))//װ��׺���ۺ�Ч���ӱ�
			idx=2;
		else
			idx=1;
			
		target->add("max_mp",  -idx*(1+(me->query_skill("beiming_shengong", 1)-90)/5) );
		me->add("max_mp",       idx*(1+(me->query_skill("beiming_shengong", 1)-90)/5) );
		if ( target->query("max_mp") <1) target->set("max_mp",0l);
		
		me->start_busy(7);
		target->start_busy(random(7));
		me->add("mp", -10);

		me->call_out(del_sucked, 10);
	}
	else
	{	
		message_vision("����$p������$P����ͼ����������˿�ȥ��", me, target);
		me->start_busy(7);
		me->call_out(del_sucked, 20);
	}

	return 1;
}

static int do_neilisuck(CChar * me, CContainer * ob)
{
	int sp, dp;
	char msg[255];
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if(me->environment()->query("no_fight"))
		return notify_fail("�㲻���ڽ�ֹս���ĵط�ʹ���ڹ����������!");


	if(DIFFERSTR(me->querystr("family/family_name"), "��ң��") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( !target || target == me || EQUALSTR(target->querystr("id"), "mu ren") )
		return notify_fail("��Ҫ��ȡ˭��������");
	
	if ( me->query_temp("sucked") )
		return notify_fail("��ո���ȡ��������");
	
	if( me->query_skill("beiming_shengong",1) < 50 )
		return notify_fail("��ı�ڤ�񹦹���������������ȡ�Է���������");
	
	//46 �޸ģ���ң������������������
	//if (me->query_weapon())
	//	return notify_fail("�������ֲ���ʩ�ñ�ڤ������������");
		
	if( me->query("mp") < 20 )
		return notify_fail("�����������������ʹ�ñ�ڤ�񹦡�");
	
	if( target->query("max_mp") <= 0 )
		return notify_fail( "%sû���κ�������",target->name());
	
	if( target->query("mp") < 60 )
		return notify_fail( "%s�Ѿ�������ɢ�����Ѿ��޷�����������ȡ�κ������ˣ�",target->name());
	
	message_vision("$N����Ȼ�ӿ죬����ֱ�����͵ض�׼$n�����д�Ѩ������ȥ��" ,	me, target );
	
	if ( living(target) )
	{
		target->kill_ob(me);
	}
	
	sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("lingboweibu",1)/2 + 1;
	dp = target->query_skill("force") + target->query_skill("dodge") + 1;
	
	me->set_temp("sucked", 1);		
	
	if (( random(sp) > random(dp) ) || !target->Query(IS_LIVING) )
	{
		tell_object(target,  "��پ�ȫ��������ˮ����ѭ�׷�й������" );
		tell_object(me, snprintf(msg, 255, "�����%s������������ԴԴ���������˽�����" ,target->name()));
		
		int idx;
		if(me->query_temp("taozhuang/g_3"))//װ��׺���ۺ�Ч���ӱ�
			idx=2;
		else
			idx=1;

		target->add("mp", -idx*(me->query_skill("beiming_shengong", 1) + target->query("mp_factor")) );
		if ( target->query("mp") <1 )
			target->set("mp",0l);
		me->add("mp", idx*(me->query_skill("beiming_shengong", 1) + target->query("mp_factor")) );
		
		//ֻ������Ч�ȼ����ı�
		int limit_force = me->query_skill("force") * 40;

		if (me->query("mp") > limit_force)
			me->set("mp", limit_force);
				
		me->start_busy(random(5));
		target->start_busy(random(4));
		
		me->call_out(del_sucked, 2);
	}
	else
	{	
		message_vision( "����$p������$P����ͼ����������˿�ȥ��" , me, target);
		me->start_busy(4);
		me->call_out(del_sucked, 4);
	}

	return 1;
}

FORCE_END;
