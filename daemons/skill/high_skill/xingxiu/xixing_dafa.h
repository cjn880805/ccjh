//oho��Ʒ����������֤

// xixing_dafa.h ���Ǵ�
FORCE_BEGIN(CSxixing_dafa);

virtual void create()
{
	CForce::create();

	set_name( "���Ǵ�");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "������";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("mpsuck", do_mpsuck);
	magic->name = "��������";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("maxsuck", do_maxsuck);
	magic->name = "��������";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;
	
	magic = add_magic("mpsucks", do_mpsucks);
	magic->name = "�������";
	magic->mp = 5;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;


	magic = add_magic("suck", do_suck);
	magic->name = "��������";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;
	
	magic = add_magic("roar", do_roar);
	magic->name = "��������";
	magic->mp = 1000;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("���Ǵ�ֻ������̵������������ȡ�");
}

virtual int valid_learn(CChar * me)
{
	int i = me->query_skill("xixing_dafa", 1);
	int t = 1, j;

	if(i <= 100)
		for (j = 1; j < i / 10; j++)
			t*= 2;

	if ( EQUALSTR(me->querystr("gender"), "����") && i > 49)
		return notify_fail("���޸����ԣ�������������������������Ǵ󷨡�");

	if (me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ�����㣬����ѧ���Ǵ󷨡�");


	if ( me->query_skill("bibo_shengong",1)
		|| me->query_skill("beiming_shengong",1)
		|| me->query_skill("bahuang_gong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huntian_qigong",1)
		|| me->query_skill("hunyuan_yiqi",1)
		|| me->query_skill("longxiang",1)
		|| me->query_skill("jiuyang_shengong",1)
		|| me->query_skill("taiji_shengong",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("yunlong_shengong",1)
		|| me->query_skill("zixia_shengong",1) 
		|| me->query_skill("huagong_dafa",1) 	
		|| me->query_skill("kurong_changong",1) )				
		
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ���Ǵ󷨣���");

	return 1;
}

int valid_enable(string usage) { return usage == "force"; }

static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������");

    if (me->query_skill("xixing_dafa", 1)<20)
		return notify_fail("������Ǵ���Ϊ��������");
	if( me->query("mp") < 50 )
		return notify_fail("�������������");

	if( me->query("eff_hp") < me->query("max_hp") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�");

	tell_object(me, "��ȫ����ɣ���������ʼ�˹����ˡ�");
	tell_room(me->environment(), snprintf(msg, 255, "%s�³�һ����Ѫ����ɫ�������ö��ˡ�", me->name()), me);

	me->receive_curing("hp", 10 + me->query_skill("force")/5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
    me->start_busy(4);
	return 1;
}

static int do_mpsuck(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];	
	int sp, dp;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if ( target == me ) return notify_fail("�������Լ���������");

	if( ! target || EQUALSTR(target->querystr("id"), "mu ren") )
		return notify_fail("��Ҫ��ȡ˭��������");

	if( me->environment()->query("no_fight"))
		return notify_fail("�㲻���ڽ�ֹս���ĵط�ʹ���ڹ����������!");

	if ( me->query_temp("sucked") )
		return notify_fail("��ո���ȡ��������");

	if( me->query_weapon() )
		return notify_fail("�������ֲ���ʩ�����Ǵ�����������");

	if( me->query_skill("xixing_dafa",1) < 60 )
		return notify_fail("������Ǵ󷨹���������������ȡ�Է���������");

	if( me->query("mp") < 20 )
		return notify_fail("�����������������ʹ�����Ǵ󷨡�");

	if( target->query("max_mp") <= 0 )
		return notify_fail( "%sû���κ�������", target->name());

    if( target->query("mp") < 60 )
		return notify_fail("%s�Ѿ�������ɢ�����Ѿ��޷�����������ȡ�κ������ˣ�", target->name());

	message_vision("$Nһ����ͻȻ��òҰף�����ֱ�����͵ض�׼$n�����д�Ѩ������ȥ��", me, target );

    if ( target->Query(IS_LIVING))
    { 
		if( !target->is_killing(me) ) target->kill_ob(me); 
	}

    sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("zhaixinggong",1)/2;
    dp = target->query_skill("force") + target->query_skill("dodge") + 1;

	me->set_temp("sucked", 1);		

    if (( random(sp) > random(dp) ) || ! target->Query(IS_LIVING) )
	{
		tell_object(target, "��پ�����΢ʹ����ͬ��������˸�С�ף�ȫ��������ˮ����ѭ�׷�й������");
		tell_object(me, snprintf(msg, 255, "�����%s������������ԴԴ���������˽�����", target->name()));

		target->add("mp", -1*(me->query_skill("xixing_dafa", 1) + target->query("mp_factor")) );
        if ( target->query("mp") <1 ) target->set("mp",0l);
//		me->add("mp", me->query_skill("xixing_dafa", 1) + target->query("mp_factor") );

		//ֻ������Ч�ȼ����ı�
//		int limit_force = me->query_skill("force") * 40;

//		if (me->query("mp") > limit_force)
//			me->set("mp", limit_force);

        me->start_busy(4);
		target->start_busy(random(4));
        me->add("mp", -7);

		me->call_out(del_sucked, 2);
	}
	else
	{	
		message_vision("����$p������$P����ͼ����������˿�ȥ��", me, target);
		me->start_busy(4);
		me->call_out(del_sucked, 4);
	}

	return 1;
}

static int do_maxsuck(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];
	int sp, dp;
	int my_max, tg_max;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if ( target == me ) return notify_fail("���ܶ��Լ�ʹ�á�");

	if( me->environment()->query("no_fight") )
		return notify_fail("�����ﲻ�ܹ������ˡ�");

	if( ! target || EQUALSTR(target->querystr("id"), "mu ren" ))
		return notify_fail("��Ҫ��ȡ˭�ĵ�Ԫ��");
	if (DIFFERSTR(target->querystr("race"), "����"))
		return notify_fail("����ˣ�ֻ���˲����е�Ԫ��");

    my_max = me->query("max_mp");
    tg_max = target->query("max_mp");

	if ( me->query_temp("sucked") )
		return notify_fail("��ո���ȡ����Ԫ��");

	if( me->query_weapon() )
		return notify_fail("�������ֲ���ʩ�����Ǵ����˵�Ԫ��");

    if( me->query_skill("xixing_dafa",1) < 90 )
		return notify_fail("������Ǵ󷨹���������������ȡ�Է��ĵ�Ԫ��");

	if( me->query("mp") < 20 )
		return notify_fail("�����������������ʹ�����Ǵ󷨡�");

	if( me->query_skill("force") < me->query("max_mp") /10 )
		return notify_fail("����ڹ�̫���ˣ�����ȡҲ��ͽ�͡�");

	if( target->query("max_mp") < 100 )
		return notify_fail(	"%s��Ԫ��ɢ������δ�ۣ����޷�����������ȡ�κζ�����",  target->name());

    if( target->query("max_mp") < me->query("max_mp")/10 )
		return notify_fail( "%s���ڹ���ΪԶ�����㣬���޷�����������ȡ��Ԫ��",  target->name());

	message_vision("$Nȫ��ǽڱ��죬˫�۱������ߣ���Ե�͵���$n������������ȥ��", me, target );

	if ( target->Query(IS_LIVING) )
	{
		if( !target->is_killing(me) ) target->kill_ob(me);
	}

    sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("xixing_dafa",1)/2;
    dp = target->query_skill("force") + target->query_skill("dodge") + 1;

	me->set_temp("sucked", 1);		

    if (( random(sp) > random(dp) ) || ! target->Query(IS_LIVING) )
	{
		tell_object(target, "��ֻ���춥���ѣ�ȫ�������Զ���������ѩ����ʧ����Ӱ���٣�");
		tell_object(me, snprintf(msg, 255, "�����%s�ĵ�Ԫ������ԴԴ���������˽�����",  target->name()));

        target->add("max_mp",  -1*(1+(me->query_skill("xixing_dafa", 1)-90)/5) );
//        me->add("max_mp",       1*(1+(me->query_skill("xixing_dafa", 1)-90)/5) );
        if ( target->query("max_mp") <1) target->set("max_mp",0l);

        me->start_busy(7);
        target->start_busy(random(7));
        me->add("mp", -10);

		me->call_out(del_sucked, 10);
	}
	else
	{	
		message_vision("����$p������$P����ͼ�������͵�һ�𣬽������˿�ȥ��", me, target);
        me->start_busy(7);
		me->call_out(del_sucked, 20);
	}

	return 1;
}





static int do_suck(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];
	int sp, dp;
	CContainer * tar;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if ( target == me ) return notify_fail("�㲻�����Լ���������");
	if( ! target || EQUALSTR(target->querystr("id"), "mu ren" ))
		return notify_fail("��Ҫ��ȡ˭��������");
	if( (me->environment())->query("no_fight"))
		return notify_fail("�㲻���ڽ�ֹս���ĵط�ʹ���ڹ����������!");

	if ( me->query_temp("sucked") )
		return notify_fail("��ո���ȡ��������");

	if( ! (ob = me->query_weapon()) )
		return notify_fail("��û���ñ�����");

	if( ! (tar = target->query_weapon()) )
		return notify_fail("��Ķ���û���ñ�����");

	if( me->query_skill("xixing_dafa",1) < 60 )
		return notify_fail("������Ǵ󷨹���������������ȡ�Է���������");

	if( me->query("mp") < 20 )
		return notify_fail("�����������������ʹ�����Ǵ󷨡�");

	if( target->query("max_mp") <= 0 )
		return notify_fail( "%sû���κ�������", target->name());

    if( target->query("mp") < 60 )
		return notify_fail( "%s�Ѿ�������ɢ�����Ѿ��޷�����������ȡ�κ������ˣ�", target->name());

	message_vision(snprintf(msg, 255, "$NͻȻ��%s��$n��%sѹ��ȥ��", ob->name(), tar->name()), me, target);
	
	if( !target->is_killing(me) ) target->kill_ob(me);

    sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("xixing_dafa",1)/2;
    dp = target->query_skill("force") + target->query_skill("dodge") + 1;

	me->set_temp("sucked", 1);		

    if (( random(sp) > random(dp) ) || ! target->Query(IS_LIVING) )
	{
		tell_object(target, "��ȫ��������ˮ����ѭ�״����Ʒ�й������");
		tell_object(me, snprintf(msg, 255, "�����%s������������ԴԴ���������˽�����", target->name()));

		target->add("mp", -1*(me->query_skill("xixing_dafa", 1) + target->query("mp_factor")) );
        if ( target->query("mp") <1 ) target->set("mp",0l);
//		me->add("mp", me->query_skill("xixing_dafa", 1) + target->query("mp_factor") );

	    me->start_busy(3);
		target->start_busy(random(3));
        me->add("mp", -7);

		me->call_out(del_sucked, 2);
	}
	else
	{	
		message_vision("����$p������$P����ͼ����������˿�ȥ��", me, target);
		me->start_busy(3);
		me->call_out(del_sucked, 4);
	}

	return 1;
}

static void del_sucked(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;

	if ( me->query_temp("sucked") )
		me->delete_temp("sucked");
}

static int do_mpsucks(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];	
	int sp, dp;

	if(ob && ob->is_character())
		target = (CChar *)ob;



	if( ! target || EQUALSTR(target->querystr("id"), "mu ren" ))
		return notify_fail("��Ҫ����˭��������");

	if( me->environment()->query("no_fight"))
		return notify_fail("�㲻���ڽ�ֹս���ĵط�ʹ���ڹ����������!");

	if ( me->query_temp("sucked") )
		return notify_fail("��ո���ȡ��������");

	if( me->query_weapon() )
		return notify_fail("�������ֲ���ʩ�����Ǵ���������������");

	if( me->query_skill("xixing_dafa",1) < 10 )
		return notify_fail("������Ǵ󷨹��������������������ֵ�������");

	if( me->query("mp") < 5 )
		return notify_fail("�����������������ʹ�����Ǵ󷨡�");

	if( target->query("max_mp") <= 0 )
		return notify_fail( "%sû���κ�������", target->name());

    if( target->query("mp") < 10 )
		return notify_fail("%s�Ѿ�������ɢ�����Ѿ��޷�����������ȡ�κ������ˣ�", target->name());

	message_vision("$N��ȻһЦ������ֱ�����͵ض�׼$n�����д�Ѩ������ȥ��", me, target );

    if ( target->Query(IS_LIVING))
    { 
		if( !target->is_killing(me) ) target->kill_ob(me); 
	}

    sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("xixing_dafa",1)/2;
    dp = target->query_skill("force") + target->query_skill("dodge") + 1;

	me->set_temp("sucked", 1);		

    if (( random(sp) > random(dp) ) || ! target->Query(IS_LIVING) )
	{
		tell_object(target, "��پ����ȫ�������·�����ʧ��");
		tell_object(me, snprintf(msg, 255, "�����%s������������ԴԴ�����ش�����¡�", target->name()));

		target->add("mp", -1*(me->query_skill("xixing_dafa", 3) + target->query("mp_factor")) );
        if ( target->query("mp") <1 ) target->set("mp",0l);


        me->start_busy(4);
		target->start_busy(random(4));
        me->add("mp", -7);

		me->call_out(del_sucked, 2);
	}
	else
	{	
		message_vision("����$p������$P����ͼ����������˿�ȥ��", me, target);
		me->start_busy(4);
		me->call_out(del_sucked, 4);
	}

	return 1;
}

static int do_roar(CChar * me, CContainer * ob)
{
	if( me->query("mp") < 1000 )
       return notify_fail("�������������");

    if( (me->environment())->query("no_fight") )
       return notify_fail("�����ﲻ�ܹ������ˡ�");

    int skill = me->query_skill("force");

    me->add("mp", -800);
    me->receive_damage("hp", 10);

    me->start_busy(5);
    message_vision("$HIY$N�������һ��������ȫ��������ۣ�����һ�����춯�صľ޺�\n$COM", me);

    DTItemList search;
	POSITION p;
	CContainer * obj;
	CChar * who = NULL;
	
	CopyList(&search, (me->environment())->Get_ItemList());
	
	p = search.GetHeadPosition();
	while(p)
	{
		obj = search.GetNext(p);
		if( ! obj->Query(IS_LIVING) || obj==me )
			continue;
		
		who = (CChar *)obj;
		if( skill/2 + random(skill/2) < who->query("con") * 2 )
			continue;
					
		((CChar *)obj)->set_killer(me);
		me->set_killer((CChar *)obj);
		
		int damage = skill - (who->query("max_mp") / 10);
		if( damage > 0 )
		{
			who->receive_damage("hp", damage * 2, me);
			if( who->query("mp") < skill * 2 )
            who->receive_wound("hp", damage, me);
			tell_object(who, "�������ǰһ�������ð������ʹ������Ҫ�ѿ�һ����");
       }
	}

	if(who && !who->query("no_huan"))
		who->fight_ob(me);	//�����������˶�kill���ˡ�
      
	return 1;
}

virtual void skill_improved(CChar * me)
{
    if ((me->query_skill("xixing_dafa",1) == 100) ||
        (me->query_skill("xixing_dafa",1) == 110) ||
        (me->query_skill("xixing_dafa",1) == 120) ||
        (me->query_skill("xixing_dafa",1) == 130) ||
        (me->query_skill("xixing_dafa",1) >= 140))
    {
        tell_object(me, "�����ڵ�����������ʼ�����ͻ�ˡ�");
        me->apply_condition("congtu",1000);
    }
}

FORCE_END;