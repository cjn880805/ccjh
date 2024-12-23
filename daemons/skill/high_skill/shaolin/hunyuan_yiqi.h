FORCE_BEGIN(CShunyuan_yiqi);

virtual void create()
{
	CForce::create();

	set_name( "混元一气功");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "自疗术";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("life_heal", do_life_heal);
	magic->name = "医疗术";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("roar", do_roar);
	magic->name = "佛门狮子吼";
	magic->mp = 800;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual int valid_learn(CChar * me)
{
	int nb, nf, nh, ns;
	nb = me->query_skill("buddhism", 1);
	nf = me->query_skill("force", 1);
	nh = me->query_skill("hunyuan_yiqi", 1);
	ns = me->query("guilty");

    if ( me->querymap("couple") || me->query("max_atman") )
		return notify_fail("你已经破了色戒，无法再学习混元一气功！");

	if ( DIFFERSTR(me->querystr("gender"), "男性") )
		return notify_fail("你非童男之体，不能练习混元一气功。");

	if ( nb < 100 && nb <= nh )
		return notify_fail("你的禅宗心法修为不够，无法领会更高深的混元一气功。");

	if ( nf < 10)
		return notify_fail("你的基本内功火候还不够，无法领会混元一气功。");

	if ( ns > 0 ) 
		return notify_fail("你屡犯僧家数戒，无法领会更高深的混元一气功。");

	if ( me->query_skill("bibo_shengong",1)
		|| me->query_skill("beiming_shengong",1)
		|| me->query_skill("bahuang_gong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1)
		|| me->query_skill("huntian_qigong",1)
	//	|| me->query_skill("hunyuan_yiqi",1)
		|| me->query_skill("longxiang",1)
	//	|| me->query_skill("jiuyang_shengong",1)
	//	|| me->query_skill("taiji_shengong",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("shenlong_xinfa",1)
		|| me->query_skill("seaforce",1)
		|| me->query_skill("yunlong_shengong",1)
		|| me->query_skill("zixia_shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学混元一气功？！");

	return 1;
}

virtual int valid_enable(string usage) { return usage == "force"; }

virtual int practice_skill(CChar * me)
{
	return notify_fail("混元一气功只能用学的来增加熟练度。");
}

static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？");

	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("你的混元一气功修为还不够。");
	if( me->query("mp") < 50 )
		return notify_fail("你的真气不够。");

	if( me->query("eff_hp") < me->query("max_hp") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！");

	tell_object(me, "你全身放松，坐下来开始运功疗伤。");
	tell_room(me->environment(), snprintf(msg, 255, "%s吐出一口瘀血，脸色看起来好多了。", me->name()), me);

	me->receive_curing("hp", 10 + me->query_skill("force") / 5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
    me->start_busy(4);

	return 1;
}

static int do_life_heal(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar * )ob;

	if( ! target )
		return notify_fail("你要用真气为谁疗伤？");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！");

	if(target == me)
		return notify_fail("你没有为自己疗伤的能力！");

	if( me->query("max_mp") < 300 )
		return notify_fail("你的内力修为不够。");

	if( me->query("mp") < 150 )
		return notify_fail("你的真气不够。");

	if( target->query("eff_hp") < target->query("max_hp") / 5 )
		return notify_fail( "%s已经受伤过重，经受不起你的真气震荡！", target->name());

	if( target->query("eff_hp") >= target->query("max_hp"))
		return notify_fail("%s没有受伤。", target->name());

	message_vision(
		"$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n",
			me, target );

	target->receive_curing("hp", 10 + me->query_skill("force") / 3 );
	target->add("hp", 10 + me->query_skill("force") / 3 );
	if( target->query("hp") > target->query("eff_hp") ) target->set("hp", target->query("eff_hp"));

	me->add("mp", -150);
	me->set("mp_factor", 0l);
	//疗伤经验奖励    秦波 2002、7、18
	char expmsg[80];
	int addexp = me->query("level") / 4 + 1;
	int addrpt = 10 - target->query("level");

	addexp=1;
	addrpt=1;
	addexp = int(((addexp + random(addexp)) / 2) *0.5);
	if(addrpt < 1) addrpt = 1;
	addrpt = (addrpt + random(addrpt)) / 2;

	me->add("combat_exp", addexp);
	me->add("repute", addrpt);
	
	tell_object(me, snprintf(expmsg, 80, "你的修行提高了%ld点！声望提高了%ld点！", addexp, addrpt));
	//疗伤经验奖励
    me->start_busy(5);
    target->start_busy(5);
	return 1;
}

static int do_roar(CChar * me, CContainer * ob)
{
	if((me->environment())->query("no_fight"))
		return notify_fail("这里禁止战斗！无法用内功伤人！");
	if( (me->query("mp") < 800 ) || ( me->query_skill("hunyuan_yiqi",1) < 50) )
		return notify_fail("你鼓足真气“喵”的吼了一声, 结果吓走了几只老鼠。");
	if(DIFFERSTR(me->querystr("family/family_name"), "少林派") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	int skill = me->query_skill("force");

	me->add("mp", -600);
	me->receive_damage("hp", 10);

	me->start_busy(5);
	message_vision(
		"$N深深地吸一囗气，真力迸发，发出一声惊天动地的巨吼。", me);

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
		//反馈效果
		if(who->query_temp("apply/反_佛门狮子吼")&& (!random(3)||wizardp(me)))
		{
			message_vision("\n$HIY$n不为佛门怒吼所动，反而吹出一段小曲，曲中处处是春情、段段是相思。",me, who);
			message_vision("$HIY$N心中微漾，再也不能保持灵台空明的心态，内息紊乱，哇的一声喷出一口鲜血，已是走火入魔的先兆。\n",me, who);
			int damage = skill - (who->query("max_mp") / 10);
			if( damage > 0 ) 
			{
				me->receive_damage("hp", damage * 2, me);
				if( me->query("mp") < skill * 2)
					me->receive_wound("hp", damage, me);
			}
			break;
		}
		else
		{
			if( skill/2 + random(skill/2) < who->query("con") * 2  )
				continue;
			
			who->set_killer(me);
			me->set_killer(who);
			
			int damage = skill - (who->query("max_mp") / 10);
			if( damage > 0 ) 
			{
				who->receive_damage("hp", damage * 2, me);
				if( who->query("mp") < skill * 2)
					who->receive_wound("hp", damage, me);
				tell_object(who, "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样！");
			}
		}
	}

	if(who && !who->query("no_huan"))
		who->fight_ob(me);

	return 1;
}

FORCE_END;