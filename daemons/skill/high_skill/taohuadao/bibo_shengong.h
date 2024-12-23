
// bibo_shengong.h 碧波神功
//code by Fisho
//date : 2000-12-08

FORCE_BEGIN(CSbibo_shengong);

virtual void create()
{
	CForce::create();

	set_name( "碧波神功");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "自疗术";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("lifeheal", do_life_heal);
	magic->name = "医疗术";
	magic->mp = 120;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("powerup", do_powerup);
	magic->name = "激励术";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("roar", do_roar);
	magic->name = "碧海生潮";
	magic->mp = 500;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("cuidu", do_cui);
	magic->name = "附骨催毒";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force")  ;
}

virtual int valid_learn(CChar * me)
{
	int lvl =  me->query_skill("bibo_shengong", 1);
	
	if ( EQUALSTR(me->querystr("gender"), "无性") && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的碧波神功。");
	
	if ( me->query_skill("beiming_shengong",1)
		|| me->query_skill("bahuang_gong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1)
		|| me->query_skill("huntian_qigong",1)
		|| me->query_skill("hunyuan_yiqi",1)
		|| me->query_skill("longxiang",1)
		|| me->query_skill("jiuyang_shengong",1)
		|| me->query_skill("taiji_shengong",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("yunlong_shengong",1)
		|| me->query_skill("shenlong_xinfa",1)
		|| me->query_skill("seaforce",1)
		|| me->query_skill("zixia_shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学碧波神功？！");
	
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
    return notify_fail("碧波神功只能用学的，或是从运用(exert)中增加熟练度。");
}


//perform 
static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？");
	
	if ( me->query_skill("bibo_shengong", 1) < 20)
		return notify_fail("你的碧波神功修为还不够。");
	if(  me->query("mp") < 50 ) 
		return notify_fail("你的真气不够。");
	
	if(  me->query("eff_hp") <  me->query("max_hp") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！");
	
	tell_object(me,   "你全身放松，坐下来开始运功疗伤。"  );
	tell_room(me->environment(),snprintf(msg,255,"%s吐出一口瘀血，脸色看起来好多了。"  ,me->name() ),me);
	
	me->receive_curing("hp", 10 +  me->query_skill("force")/5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	me->start_busy(4);
	return 1;
}

static int do_powerup(CChar * me, CContainer * ob)
{
	if( ob != me ) return notify_fail("你只能用碧波神功提升自己的战斗力。");
	
	if(  me->query("mp") < 100)
		return notify_fail("你的内力不够!");
	if(  me->querymap_temp("powerup") ) return notify_fail("你已经在运功中了。");
	if(DIFFERSTR(me->querystr("family/family_name"), "桃花岛") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	int skill = me->query_skill("force");
	
	me->add("mp", -100);
	me->receive_damage("hp", 0);
	message_vision("$N舌尖一咬，喷出一口鲜血，运起碧波神功已将全身潜力尽数提起！"  , me);
	
	start_powerup(me, skill, skill/3, skill/3, "你的碧波神功运行完毕，将内力收回丹田。");

	if( me->is_fighting() ) me->start_busy(3);
	return 1;
}

static int do_roar(CChar * me, CContainer * ob)
{
	if((me->environment())->query("no_fight"))
		return notify_fail("这里禁止战斗！无法用内功伤人！");
	if(  me->query("mp") < 500 )
		return notify_fail("你的内力不够。");
	if(DIFFERSTR(me->querystr("family/family_name"), "桃花岛") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	int skill = me->query_skill("force");
	
	me->add("mp", -400);
	me->receive_damage("hp", 10);
	
	me->start_busy(5);
	message_vision("$N气凝丹田，运集全身内力吟出一曲「碧海生潮」！"  , me);
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
		
		if( skill/2 + random(skill/2) < obj->query("con") * 2  )
			continue;
		
	//	if(! ((CChar *)obj)->is_killing(me) )
//			 ((CChar *)obj)->kill_ob(me);
		
		//if( !me->is_killing((CChar *)obj) )
		//	me->kill_ob((CChar *)obj);

		who = (CChar *)obj;
		if(who->query_temp("apply/反_碧海生潮")&& (!random(3)||wizardp(me)))
		{
			int damage = skill * 2 - (obj->query("max_mp") / 10);
			if( damage > 0 )
			{
				me->receive_damage("hp", damage * 2, me );
				if( me->query("mp") < skill * 2 )
					me->receive_wound("hp", damage, me);
				message_vision("$HIY\n$n含箫一吹，竟然同样是一曲“碧海生潮”，只是每个音都较$N慢少少许。",me, who);
				message_vision("$HIY$N只觉对方的音律处处压制着自己，不由得跟随着$n的节奏唱了下去。",me, who);
				message_vision("$HIY突然间$n的箫音一个拔高，$N的歌声再也无力为继，只觉得眼前金星乱冒，气血上涌，难受之极。\n",me, who);
			}
			break;
		}
		else
		{
			who->set_killer(me);
			me->set_killer(who);
			
			int damage = skill * 2 - (obj->query("max_mp") / 10);
			if( damage > 0 )
			{
				who->receive_damage("hp", damage * 2, me );
				if( who->query("mp") < skill * 2 )
					who->receive_wound("hp", damage, me);
				tell_object(who, "你只觉得眼前一片模糊，朦胧中似乎无数排山巨浪向你打来......");
			}
		}
	}

	if(who && !who->query("no_huan"))
		who->fight_ob(me);

	return 1;
}

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
		return notify_fail("你不可以为自己疗伤。");
	
	if ( me->query_skill("bibo_shengong", 1) < 50)
		return notify_fail("你的碧波神功修为还不够。");
	
	if(  me->query("max_mp") < 300 )
		return notify_fail("你的内力修为不够。");
	
	if(  me->query("mp") < 120 )
		return notify_fail("你的真气不够。");

	if( me->query_skill("medicine", 1) < 80 )
           return notify_fail("你的基本医术等级不够，无法为他人疗伤。\n");	
	
	if(target->query("eff_hp") <  target->query("max_hp") / 5 )
		return notify_fail("%s已经受伤过重，经受不起你的真气震荡！",target->name());

	if(target->query("eff_hp") >= target->query("max_hp"))
		return notify_fail("%s没有受伤。", target->name());
	
	message_vision("$HIY$N坐了下来运起碧波神功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n$n只觉一股暧阳阳的真气源源不绝的输入体内，瞬间流遍全身各大穴位。\n$n吐出一口瘀血，脸色看起来红润多了，伤势有了很大的好转，并觉全身真气无比充沛！！！\n" ,	me, target );
	
	target->receive_curing("hp", 10 +  me->query_skill("force")/3 );
	target->add("hp", 10 +  me->query_skill("force")/3 );
	if(  target->query("hp") >  target->query("eff_hp") ) target->set("hp",  target->query("eff_hp"));
	
	me->add("mp", -120);
	me->set("mp_factor", 0l);

	me->start_busy(5);
	target->start_busy(5);

	return 1;
}

static int do_cui(CChar * me, CContainer * ob)
{
	if((me->environment())->query("no_fight"))
		return notify_fail("这里禁止战斗！无法用内功伤人！");

	int level = me->query_skill("bibo_shengong",1);
	int num;

	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target ||!userp(target))
		return notify_fail("你要催动谁的毒性？\n");
	
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中催毒？找死啊？\n");
	
	if (me->query_skill("bibo_shengong", 1) < 180)
		return notify_fail("你的碧波神功修为还不够。\n");
	
	if( me->query("max_mp") < 1000 )
		return notify_fail("你的内力修为不够。\n");
	
	if(me->query("mp") < 1000 )
		return notify_fail("你的真气不够。\n");
	
	if( me == target ) 
		return notify_fail("你要催动自己的毒性？\n");
	
	if(!target->query("门派/thd/fugu"))
		return notify_fail("此人没有中附骨钉。\n");

	if(DIFFERSTR(me->querystr("family/family_name"), "桃花岛") )
		return notify_fail("你虽然听说过「附骨催毒」这一招，可是却未获传授。\n");
	
	num = target->query("门派/thd/fugu");        
	me->add("mp", -300);

	target->receive_wound("hp",random(level/5)*num);
	target->add("mp",-random(level));

	message_vision("$HIW$N运起碧波神功，催动$n的「附骨钉」之毒！",me,target);
	message_vision("$HIW$n的$HIR「附骨钉」$HIW之毒发作了！\n",me,target);
	target->apply_condition("fugu_poison", 20 + random(20));

	me->start_busy(3);
	return 1;
}

FORCE_END;
