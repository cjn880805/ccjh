
// yunv_xinjing.h 玉女心经
//code by Fisho
//date : 2000-12-05

FORCE_BEGIN(CSyunv_xinjing);

virtual void create()
{
	CForce::create();

	set_name( "玉女心经");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "自疗术";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("powerup", do_powerup);
	magic->name = "激励术";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("roar", do_roar);
	magic->name = "摄心术";
	magic->mp = 800;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMMON;
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force");
}

virtual int valid_learn(CChar * me)
{
	char msg[255];
	if (DIFFERSTR(me->querystr("family/family_name"), "古墓派")) 
		return notify_fail("你不是古墓派的弟子,不能学习玉女心经?");
	
	if ( EQUALSTR(me->querystr("class"), "taoist") )
		return notify_fail(snprintf(msg, 255, "玉女心经是古墓派的决学,%s已是李莫愁的弟子,就不可再学此功了。",query_respect(me)));
	
	if (me->query_skill("yunv_xinfa", 1) < 10)
		return notify_fail("你的玉女心法火候还不够,不能修练玉女心经。");
	
	if ( me->query_skill("bibo_shengong",1)
		|| me->query_skill("beiming_shengong",1)
		|| me->query_skill("biyun_xinfa",1)
		|| me->query_skill("xuedao_xinfa",1)
		|| me->query_skill("shenzhao_shengong",1)
		|| me->query_skill("tianlong_shengong",1)
		|| me->query_skill("bahuang_gong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1)
		|| me->query_skill("huntian_qigong",1)
		|| me->query_skill("jiuyang_shengong",1)
		|| me->query_skill("xiantian_gong",1)
		|| me->query_skill("wudu_xinfa",1)
		|| me->query_skill("hunyuan_yiqi",1)
		|| me->query_skill("longxiang",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("yunlong_shengong",1)
		|| me->query_skill("zixia_shengong",1)
		|| me->query_skill("shenlong_xinfa",1)
		|| me->query_skill("taiji_shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学玉女心经？！");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("玉女心经只能用请教的来增加熟练度。");
}

//perform 
static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？");
	
	if (me->query_skill("yunv_xinjing", 1) < 20)
		return notify_fail("你的玉女心经修为还不够。");
	if( me->query("mp") < 50 ) 
		return notify_fail("你的真气不够。");
	
	if( me->query("eff_hp") < me->query("max_hp") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！");
	
	tell_object( me, "你全身放松，坐下来开始运功疗伤。" );
	tell_room( me->environment(),snprintf(msg,255,"%s吐出一口瘀血，脸色看起来好多了。" ,me->name()), me);
	me->receive_curing("hp", 10 + me->query_skill("force")/5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	me->start_busy(4);
	return 1;
}

static int do_powerup(CChar * me, CContainer * ob)
{
	int skill;
	
	if( me->query_skill("yunv_xinjing",1)< 10)
		return notify_fail("你的玉女心经修为不够.");
	
	if( ob != me ) return notify_fail("你只能用玉女心经提升自己的战斗力。");

	if(DIFFERSTR(me->querystr("family/family_name"), "古墓派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( me->query("mp") < 100)
		return notify_fail("你的内力不够!");
	if( me->querymap_temp("powerup") ) return notify_fail("你已经在运功中了。");
	
	skill = me->query_skill("force");
	
	me->add("mp", -100);
	me->receive_damage("hp", 0);
	
	message_vision("$N微微低下头必除杂念潜心默念玉女心经，牢记心经总决後微一抬头眼中透出冷漠的目光射向在场的所有人，根本没人注意到$N已有了微妙的变化。" , me);
	
	start_powerup(me, skill, skill/3, skill/3, "你运行完毕，将内力收回丹田，俏丽的脸蛋上又露出了迷人的微笑。");
	
	if( me->is_fighting() ) me->start_busy(3);
	
	return 1;
	
}

static int do_roar(CChar * me, CContainer * ob)
{
	int skill;
	
	if((me->environment())->query("no_fight"))
		return notify_fail("这里禁止战斗！无法用内功伤人！");
	if( me->query("mp") < 800 )
		return notify_fail("你的内力不够。");

	if(DIFFERSTR(me->querystr("family/family_name"), "古墓派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	skill = me->query_skill("force");
	
	me->add("mp", -500);
	me->receive_damage("hp", 10);
	
	me->start_busy(5);
	message_vision("$N必除杂念，心神合一，嫣然一笑，$N靓丽四射，所有人都为之一振,顿时全场春意黯然！" , me);
	DTItemList search;
	POSITION p;
	CContainer * obj = NULL;
	CChar * who = NULL;
	
	CopyList(&search, (me->environment())->Get_ItemList());
	
	p = search.GetHeadPosition();
	while(p)
	{
		obj = search.GetNext(p);
		if( ! obj->Query(IS_LIVING) || obj==me )
			continue;
		
		who = (CChar *)obj;

		if( skill/2 + random(skill/2) < who->query("con") * 2  )
			continue;
		
			
		who->set_killer(me);
		me->set_killer(who);
		
		int damage = skill - (obj->query("max_mp") / 10);
		if( damage > 0 )
		{
			who->receive_damage("hp", damage * 2, me );
			if( who->query("mp") < skill * 2 )
				who->receive_wound("hp", damage, me);
			tell_object(who, "你只觉得眼前一片模糊，朦胧中似乎有无数的美女在对你甜甜的笑,让你魂飞九霄");
		}
	}

	if(who && !who->query("no_huan"))
		who->fight_ob(me);	//场景内所有人都kill本人。

	return 1;
}

FORCE_END;
