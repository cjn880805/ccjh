// longxiang.c 龙象般若功
FORCE_BEGIN(CSlongxiang);

virtual void create()
{
	CForce::create();

	set_name( "龙象般若功");

	Magic_t * magic;

	magic = add_magic("life_heal", do_life_heal);
	magic->name = "医疗术";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("powerup", do_powerup);
	magic->name = "激励术";
	magic->mp = 200;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("fanchang", do_fanchang);
	magic->name = "梵唱";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("chuan", do_chuan);
	magic->name = "灌顶";
	magic->mp = 2500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual int valid_enable(string usage) { return usage == "force"; }

virtual int valid_learn(CChar * me)
{
	int i = me->query_skill("longxiang", 1);
	int t = 1, j;
	for (j = 1; j < i / 12; j++) t*= 2;

	if ((DIFFERSTR(me->querystr("class"), "bonze")) && i > 29)
		return notify_fail("你不是僧人，学不了高深的龙象般若功。");
	if (me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候不足，不能学龙象般若功。");
	if ( EQUALSTR(me->querystr("gender"), "无性") && i > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的龙象般若功。");
	if (i > 10 && me->query("repute") > t * 100)
		return notify_fail("要学龙象般若功，你的表现还不够吧！ ");

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
		return notify_fail("你不先散了别派内功，怎能学龙象般若功？");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("龙象般若功只能用请教的来增加熟练度。");
}

//exert heal
static int do_life_heal(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target )
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
		return notify_fail( "%s已经受伤过重，经受不起你的真气震荡！",target->name());

	if( target->query("eff_hp") >= target->query("max_hp"))
		return notify_fail("%s没有受伤。", target->name());

	message_vision("$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。", me, target );
	
	target->receive_curing("hp", 10 + me->query_skill("force")/3 );
	target->add("hp", 10 + me->query_skill("force")/3 );
	if( target->query("hp") > target->query("eff_hp") ) target->set("hp", target->query("eff_hp"));
	me->add("mp", -150);
	me->set("mp_factor", 0l);
	//疗伤经验奖励    秦波 2002、7、18
	char expmsg[80];
	int addexp = me->query("level") / 4 + 1;
	int addrpt = 10 - target->query("level");

	addexp = int(((addexp + random(addexp)) / 2) *0.5);
	if(addrpt < 1) addrpt = 1;
	addrpt = (addrpt + random(addrpt)) / 2;

	addexp=1;
	me->add("combat_exp", addexp);
	me->add("repute", addrpt);
	
	tell_object(me, snprintf(expmsg, 80, "你的修行提高了%ld点！声望提高了0点！", addexp));
	//疗伤经验奖励
	me->start_busy(5);
	target->start_busy(5);
	return 1;
}

static int do_fanchang(CChar * me, CContainer * ob)
{
	int sp, dp;
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( (me->environment())->query("no_fight") )
		return notify_fail("你不能在禁止战斗的地方使用内功的这个功能");

	if( ! target || target == me || EQUALSTR(target->querystr("id"), "mu ren") )
		return notify_fail("你要攻击谁？");
	
	if( me->query_skill("longxiang",1) < 50 )
		return notify_fail("你的龙象般若功功力不够，不能凝神攻击对方！");

	if(DIFFERSTR(me->querystr("family/family_name"), "雪山寺") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if( me->query("mp") < 50 )
		return notify_fail("你的内力不够，不能使用龙象般若功。");

	if( target->is_busy() )
		return notify_fail("对方目前正自顾不暇，放胆攻击吧。");

	msg = "\n$N面无表情，歌声如梵唱般贯入$n耳中！\n";

	sp = me->query_skill("force",1) + me->query_skill("mizongxinfa",1) + me->query_skill("longxiang",1)/2;
	dp = target->query_skill("force",1);

	me->add("mp", -40);

	if(target->query_temp("apply/反_梵唱")&& (!random(3)||wizardp(me)))
	{
		msg += "$HIY一缕幽怨哀婉的箫声自$n口中吹出，曲声极为低沉，如情人诉哀肠，游子望故乡，令人伤感忧郁。\n";
		msg += "转折处更加凄凉哀怨，似坟场上的呜咽，黄泉途中的悲鸣，愁苦哀痛在$N心中集结。\n梵唱渐渐低落，$N面上竟划下两道泪痕，再无战意。";
				
		me->receive_damage("hp", 10 + random(me->query_skill("longxiang", 1)) );
		me->start_busy(random(3));
	}
	else if (( random(sp) > random(dp) ) || !target->Query(IS_LIVING) )
	{
		msg += "$n忽然觉得脑中一片空白，不由自主地随歌声舞蹈起来！";
				
		target->receive_damage("hp", 10 + random(me->query_skill("longxiang", 1)) );
		if( target->query_combat_exp() >= me->query_combat_exp() )
			if( me->query("potential") - me->query("learned_points") < 100 )
				me->add("potential", 1);
		me->start_busy(2);
		target->start_busy(me->query_skill("longxiang",1)/80);
	}
	else
	{
		msg += "可是$p不为$P歌声所动，定力果然不同凡响！";
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);

	if ( target->Query(IS_LIVING) )
	{
		if( ! target->is_fighting(me) ) 
			target->kill_ob(me);
	}

	return 1;
}

static int do_powerup(CChar * me, CContainer * ob)
{
	int skill;
	
	if( ob != me )
		return notify_fail("你只能提升自己的战斗力。");

	if( me->query("mp")<200)
		return notify_fail("你的内力不够。");

	if( me->querymap_temp("powerup"))
		return notify_fail("你已经在运功中了。");

	if(DIFFERSTR(me->querystr("family/family_name"), "雪山寺") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	
	skill = me->query_skill("force");
	me->add("mp", -100);
	message_vision("$N大喝一声，全身骨骼节节暴响，一股迅猛的罡气向四周扩散开来！", me);
	
	start_powerup(me, skill, skill/3, skill/3, "你的龙象般若功运行完毕，将内力收回丹田。");

	if( me->is_fighting() ) me->start_busy(3);
	
	return 1;
}

static int do_chuan(CChar * me, CContainer * ob)
{
	int skill,skill2;
	skill = me->query_skill("longxiang");
	skill2 = me->query_skill("force");

	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target )
		return notify_fail("你要把真力传送给谁？\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("在战斗中无法送出真力给他人！\n");

	if(target == me)
		return notify_fail("只能把真力传给别人。\n");

	if( me->query("max_mp") < 2500 )
		return notify_fail("你的内力修为不够。");

	if( me->query("mp") < 1500 )
		return notify_fail("你的真气不够。");
	
	if (me->query_skill("longxiang",1)<200)
		return notify_fail("你的龙象般若功修为不够，无法传出内力给别人。\n");

	if (target->query_skill("longxiang",1)<100)
		return notify_fail("对方龙象般若功修为不够，内力无法和你融合为一。\n");

	if (target->query_temp("trans") >= 1)
		return notify_fail("对方已经受过功了，再传他的身体就吃不消了。\n");

	if (target->query("combat_exp") >= me->query("combat_exp"))
		return notify_fail("对方武学造诣比你还要高深，你似乎需要再做修炼才是。\n");
	
	if( target->query("eff_hp") < target->query("max_hp") / 5 )
		return notify_fail("%s已经受伤过重，经受不起你的真气震荡！\n",target->name());

	if(DIFFERSTR(me->querystr("family/family_name"), "雪山寺") )
		return notify_fail("你虽然听说过「灌顶」这一招，可是却未获传授。\n");

	message_vision("$HIC$N运起内功，将手掌贴在$n背心，一股真气在两人体内盘旋流动，将两人内力串为一体。\n\n过了不久，$N一声长啸向后跃开，部分真力却早已留在$n体内，和$n内力融为一体，再也无法分离。\n" ,me, target );
	
	target->add("mp",skill+random(skill2*4));
	if(target->query("mp")>target->query("max_mp")*4)
		target->set("mp",target->query("max_mp")*4);

	me->add("mp", -(skill+skill2)*2);
	if(me->query("mp")<0)
		me->set("mp",0l);
	me->add("max_mp",-10);
	me->UpdateMe();

	target->set_temp("trans",1);
	target->add_temp("apply/damage", skill/5);
	target->set_temp("trans_1",skill /5);
	target->add_temp("apply/attack", skill2 /5); 
	target->set_temp("trans_2",skill2 /5);
	target->UpdateMe();

	target->call_out(remove_effect, random((skill+skill2)/10)+10);
	me->start_busy(5);
	target->start_busy(1);
	
	return 1;
}

static void remove_effect(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	
	me->delete_temp("trans");
	me->add_temp("apply/damage", -me->query_temp("trans_1"));
	me->delete_temp("trans_1");
	me->add_temp("apply/attack", -me->query_temp("trans_2")); 
	me->delete_temp("trans_2");
	me->UpdateMe();

	message_vision("\n$WHT$N脸色通红，额头渗出一层汗珠。\n", me);
    tell_object(me, "$BLU你感到全身似乎有丝丝热气冒出，传功的功力消耗完了。\n");

}
FORCE_END;
