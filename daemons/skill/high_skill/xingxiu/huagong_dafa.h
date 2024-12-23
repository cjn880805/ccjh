// huagong_dafa.h ������
FORCE_BEGIN(CShuagong_dafa);

virtual void create()
{
	CForce::create();

	set_name( "������");

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

	magic = add_magic("mpsuck", do_mpsuck);
	magic->name = "��������";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("maxsuck", do_maxsuck);
	magic->name = "����";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("hpsuck", do_hpsuck);
	magic->name = "��Ѫ����";
	magic->mp = 10;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("suck", do_suck);
	magic->name = "��������";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("huo", do_huo);
	magic->name = "������ȼ";
	magic->mp = 120;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("������ֻ������̵������������ȡ�");
}

virtual int valid_learn(CChar * me)
{
	int i = me->query_skill("huagong_dafa", 1);
	int t = 1, j;

	if(i <= 100)
		for (j = 1; j < i / 10; j++)
			t*= 2;

	if (me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ�����㣬����ѧ�����󷨡�");

	if(i<=100)
	{
		if (i > 10 && - me->query("repute") < t * 100) 
			return notify_fail("ѧ�����󷨣�Ҫ�ĺ���������������������ò���ѽ��");
	}
	else
	{
		if (- me->query("repute") < (51200 + (i - 100) * 1000)) 
			return notify_fail("ѧ�����󷨣�Ҫ�ĺ���������������������ò���ѽ��");
	}

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
		|| me->query_skill("shenghuo_shengong",1)
		|| me->query_skill("kurong_changong",1)
		|| me->query_skill("bibo_shengong",1)
		|| me->query_skill("xiantian_gong",1)
		|| me->query_skill("xuantian_shengong",1) )
		
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����󷨣���");

	return 1;
}

virtual int valid_enable(string usage) { return usage == "force"; }

static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������");

    if (me->query_skill("huagong_dafa", 1)<20)
		return notify_fail("��Ļ�������Ϊ��������");
	if( me->query("mp") < 50 )
		return notify_fail("�������������");

	if( me->query("eff_hp") < me->query("max_hp") / 2 )
		return notify_fail("���Ѿ����˹��أ�һ�������϶���������������");

	tell_object(me, "��ȫ����ɣ���������ʼ�˶����ˡ�");
	tell_room(me->environment(), snprintf(msg, 255, "$HIR%s�³�һ��ð���̵Ķ�Ѫ����ɫ�������ö��ˡ�", me->name()), me);

	me->receive_curing("hp", 10 + me->query_skill("force")/6 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
    me->start_busy(5);
	return 1;
}

static int do_mpsuck(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];	
	int sp, dp;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
    if ( target == me ) return notify_fail("�������Լ���������Ҳ����Ҫ���Լ���������");
	
	if( ! target || EQUALSTR(target->querystr("id"), "mu ren") )
		return notify_fail("$HIR�ף����������˶�ȥ�������ˣ�");
	
	if( me->environment()->query("no_fight"))
		return notify_fail("�㲻���ڽ�ֹս���ĵط�ʹ���ڹ����������!");
	
	if ( me->query_temp("sucked") )
		return notify_fail("$HIR��ո���ȡ�����������뵤�ﱬը��");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( me->query_weapon() )
		return notify_fail("�������ֲ���ʩ�û���������������");
	
	if( me->query_skill("huagong_dafa",1) < 60 )
		return notify_fail("��Ļ����󷨹���������������ȡ�Է���������");
	
	if( me->query("mp") < 20 )
		return notify_fail("�����������������ʹ�û����󷨡�");
	
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
    dp = target->query_skill("force") + target->query_skill("dodge");
	
	me->set_temp("sucked", 1);		
	
    if (( random(sp) > random(dp) ) || ! target->Query(IS_LIVING) )
	{
		tell_object(target, "��پ�����΢ʹ����ͬ��������˸�С�ף�ȫ��������ˮ����ѭ�׷�й������");
		tell_object(me, snprintf(msg, 255, "�����%s������������ԴԴ���������˽�����", target->name()));
		
		target->add("mp", -1*(me->query_skill("huagong_dafa", 1) + target->query("mp_factor")) );
        if ( target->query("mp") <1 ) target->set("mp",0l);
		me->add("mp", me->query_skill("huagong_dafa", 1) + target->query("mp_factor") );
		
		//ֻ������Ч�ȼ����ı�
		int limit_force = me->query_skill("force") * 40;
		
		if (me->query("mp") > limit_force)
			me->set("mp", limit_force);
		
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
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	
	
	if( ! target || EQUALSTR(target->querystr("id"), "mu ren" ))
		return notify_fail("��Ҫ����˭�ĵ�Ԫ��");
	
	if( me->environment()->query("no_fight"))
		return notify_fail("�㲻���ڽ�ֹս���ĵط�ʹ���ڹ����������!");
	
	if ( me->query_temp("sucked") )
		return notify_fail("��ոջ������Ԫ��");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( me->query_weapon() )
		return notify_fail("�������ֲ���ʩ�û����󷨻��˵�Ԫ��");
	
	if( me->query_skill("huagong_dafa",1) < 90 )
		return notify_fail("��Ļ����󷨹������������ܻ���Է���Ԫ��");
	
	if( me->query("mp") < 500 )
		return notify_fail("�����������������ʹ�û����󷨡�");
	
	if( target->query("max_mp") <= 0 )
		return notify_fail( "%s�Ѿ�û���κ�����������һ������������", target->name());
	
    if( target->query("max_mp") < 10 )
		return notify_fail("%s�Ѿ�������ʧ������һ���ˣ���������", target->name());
	
	message_vision("$HIR$N����һЦ������ͻȻȼ���̻�һ�ѿ�ס$n�����ţ�", me, target );
	
	sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("zhaixinggong",1)/2;
    dp = target->query_skill("force") + target->query_skill("dodge");
	
    if (( random(sp) > random(dp) ) || ! target->Query(IS_LIVING) )
	{
		tell_object(target, "$HIR�����о�����Է����ϵľ綾�Ѿ�ֱ���˹�����");
		tell_object(me, snprintf(msg, 255, "$HIR���˹��ѱ��������ľ綾��%s���ϱ�ȥ��", target->name()));
		
		if ( target->Query(IS_LIVING) )
		{
			if( !target->is_killing(me) ) target->kill_ob(me);
		}
		
		sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("huagong_dafa",1)/2;
		dp = target->query_skill("force") + target->query_skill("dodge") + 1;
		
		me->set_temp("sucked", 1);		
		
		if (( random(sp) > random(dp) ) || ! target->Query(IS_LIVING) )
		{
			tell_object(target, "$HIR��ֻ���綾���뾭�����Լ����������������ڹ���Ԫ��Ȼ�ʹ�ɢȥ�������־���ŭ����");
			tell_object(me, snprintf(msg, 255, "$HIR�����%s�ĵ�Ԫ����Ķ��Ի�����Ӱ���٣��������Ĵ��ǳ��졣",  target->name()));
			
			int addmp = 1 + (me->query_skill("poison", 1) - 20) / 2;
			if(addmp < 0) addmp = 0;

			target->add("max_mp", - addmp);
			if ( target->query("max_mp") <1) target->set("max_mp",0l);
			
			me->start_busy(3);
			target->start_busy(random(3));
			me->add("mp", -50);
			
			me->call_out(del_sucked, 4);
		}
		else
		{	
			message_vision("����$p������$P����ͼ�������͵�һ�𣬽������˿�ȥ��", me, target);
			me->start_busy(3);
			me->call_out(del_sucked, 10);
		}
	}

	return 1;
}

static int do_powerup(CChar * me, CContainer * ob)
{
	int skill;

	if( me->query("mp") < 100)
		return notify_fail("�������������");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if( me->querymap_temp("powerup"))
		return notify_fail("���Ѿ����˹����ˡ�");

	skill = me->query_skill("force");

	message_vision("$N���һҧ�����һ�ڶ�Ѫ�����𻯹����ѽ�ȫ��Ǳ����������", me);

	start_powerup(me, skill, skill/3, skill/3, "��Ļ�����������ϣ��������ջص��");

	me->add("mp", -100);		//add by Lanwood 2000-12-25
	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

static int do_hpsuck(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];
	int sp, dp;

	if(ob && ob->is_character())
		target = (CChar *) ob;

	if ( target == me ) return notify_fail("��������ͼ���Լ���Ѫ�������ǲ��Ƕ��������ˣ���");

	if( (me->environment())->query("no_fight") )
		return notify_fail("�����ﲻ�ܹ������ˡ�");

	if( ! target || EQUALSTR(target->querystr("id"), "mu ren") )
		return notify_fail("$HIR��֣���ѪҺ���˶�ȥ�������ˣ���");

	if ( me->query_temp("sucked") )
		return notify_fail("��ո�����Ѫ��");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if( me->query_weapon() )
		return notify_fail("�������ֲ���ץס������Ѫ��");

	if( me->query_skill("huagong_dafa",1) < 30 )
		return notify_fail("��Ļ����󷨹��������������ܰ�����ѪΪ�����á�");

	if( me->query("mp") < 10 )
		return notify_fail("�����������������ʹ�û����󷨡�");

    if( target->query("hp") < 30 )
		return notify_fail( "%s�Ѿ�ʧѪ���࣬���Ѿ��޷�����������ѪҺ�ˣ�", target->name());

	message_vision("$HIR$NͻȻ����������˫��һ��������������ݳ�$n�Ĳ���ҧ�˹�����", me, target );

	if ( target->Query(IS_LIVING) )
	{
		if( !target->is_killing(me) ) target->kill_ob(me);
	}

	int lvl1 = me->query_skill("zhaixinggong", 1);
	int lvl2 = me->query_skill("feixing_shu", 1);

    sp = me->query_skill("force") + me->query_skill("dodge") + (lvl1 > lvl2 ? lvl1 : lvl2) /2;
    dp = target->query_skill("force") + target->query_skill("dodge");

	me->set_temp("sucked", 1);		

    if (( random(sp) > random(dp) ) || ! target->Query(IS_LIVING) )
	{
		tell_object(target, "$HIR��ȫ��ѪҺ�Ծ����˿ڱ�ӿ����������һ�Σ�ֻ��������ת��");
		tell_object(me, snprintf(msg, 255, "����õĶԷ���Ѫ�Կ���ԴԴ�����������˶��������һ��ů����", target->name()));
		target->apply_condition("xx_poison", random(me->query_skill("poison",1)/20) + 1 +
			target->query("condition/xx_poison"));
		target->receive_damage("hp", me->query_skill("huagong_dafa", 3) );
		me->add("hp", me->query_skill("huagong_dafa", 3) );
		me->add("eff_hp", me->query_skill("huagong_dafa", 3)*2/3 );
		if ( me->query("eff_hp") > me->query("max_hp") ) me->set("eff_hp", me->query("max_hp"));

		if( target->query_combat_exp() >= me->query_combat_exp() )
			me->add("combat_exp",4);

        me->start_busy(2);
        target->start_busy(random(3));
		me->add("mp", -5);

		me->call_out(del_sucked, 1);
	}
	else
	{	
		message_vision("����$p������$P����ͼ�������͵�һ�𣬽������˿�ȥ��", me, target);
        me->start_busy(2);
		me->call_out(del_sucked, 2);
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

    if ( target == me ) return notify_fail("�Լ�����������Ҳ�������㲻�᲻֪���ɣ�");
	if( ! target || EQUALSTR(target->querystr("id"), "mu ren") )
		return notify_fail("$HIR�ף����������˶�ȥ�������ˣ�");
	if( (me->environment())->query("no_fight"))
		return notify_fail("�㲻���ڽ�ֹս���ĵط�ʹ���ڹ����������!");

	if ( me->query_temp("sucked") )
		return notify_fail("��ո���ȡ��������");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if( ! (ob = me->query_weapon()) )
		return notify_fail("��û���ñ�����");

	if( ! (tar = target->query_weapon()) )
		return notify_fail("��Ķ���û���ñ�����");

	if( me->query_skill("huagong_dafa",1) < 60 )
		return notify_fail("��Ļ����󷨹���������������ȡ�Է���������");

	if( me->query("mp") < 20 )
		return notify_fail("�����������������ʹ�û����󷨡�");

	if( target->query("max_mp") <= 0 )
		return notify_fail( "%sû���κ�������", target->name());

    if( target->query("mp") < 60 )
		return notify_fail( "%s�Ѿ�������ɢ�����Ѿ��޷�����������ȡ�κ������ˣ�", target->name());

	message_vision(snprintf(msg, 255, "$NͻȻ��%s��$n��%sѹ��ȥ��", ob->name(), tar->name()), me, target);
	
	if( !target->is_killing(me) ) target->kill_ob(me);

	int lvl1 = me->query_skill("zhaixinggong", 1);
	int lvl2 = me->query_skill("feixing_shu",1);

    sp = me->query_skill("force") + me->query_skill("dodge") + (lvl1 > lvl2 ? lvl1 : lvl2) /2;
    dp = target->query_skill("force") + target->query_skill("dodge");

	me->set_temp("sucked", 1);		

    if (( random(sp) > random(dp) ) || ! target->Query(IS_LIVING) )
	{
		tell_object(target, "���ʱ����ȫ��������ˮ����ѭ�ű�����й��ȥ��");
		tell_object(me, snprintf(msg, 255, "�����%s������������ԴԴ���������˽�����", target->name()));

		target->add("mp", -1*(me->query_skill("huagong_dafa", 1) + target->query("mp_factor")) );
        if ( target->query("mp") <1 ) target->set("mp",0l);
		me->add("mp", me->query_skill("huagong_dafa", 1) + target->query("mp_factor") );
		
		//ֻ������Ч�ȼ����ı�
		int limit_force = me->query_skill("force") * 40;

		if (me->query("mp") > limit_force)
			me->set("mp", limit_force);

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

static int do_huo(CChar * me, CContainer * ob)
{
	if( me->query("mp") < 150)
		return notify_fail("�������������");

	if(me->environment()->query("no_fight"))
		return notify_fail("�㲻���ڽ�ֹս���ĵط�ʩ�š�������ȼ��!");

	if(!me->is_fighting())
		return notify_fail("ֻ����ս����ʩ�š�������ȼ����");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") )
		return notify_fail("����ϡ���ǵá�������ȼ����һ�У�����ȴ������ȴ�����ʹ�á�");

	if(me->query_temp("huagong/huo"))
		return notify_fail("�����Ϣ������ͬʱ֧����������");

	if(me->query_skill("huagong_dafa",1) < 180 )
		return notify_fail("��Ļ����󷨹�����������Ϣ�޷�ʩ�ų���������ȼ����");

	message_vision("\n$HIR$N���һҧ�����һ�ڶ�Ѫ�����𻯹����ѽ�ȫ��Ǳ����������\nһ�ػ���������˫�����𣬸�Լ����ɫ�����̣�����ɭɭ����Ѱ��������죡", me);

	int skill = me->query_skill("huagong_dafa", 1);

	me->add("mp", -120);
	me->set_temp("huagong/huo",1);
	me->call_out(remove_effect, skill/2);
	me->start_busy(2);

	return 1;
}

static void remove_effect(CContainer * ob, LONG param1, LONG param2)
{
    char msg[255];
	CChar * me = (CChar *)ob;  
	me->delete_temp("huagong/huo");
	tell_room(me->environment(), snprintf(msg, 255,"\n$HIW%s���Ե�һ������ͻȻ��������𻨣���������ɢ����������Ϩ���ˡ�\n" ,me->name()));
}
FORCE_END;