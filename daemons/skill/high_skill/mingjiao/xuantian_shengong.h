
// xuantian_shengong.h 玄天神功
//code by Fisho
//date : 2000-12-07

FORCE_BEGIN(CSxuantian_shengong);

virtual void create()
{
	CForce::create();

	set_name( "玄天神功");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "自疗术";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("roar", do_roar);
	magic->name = "长啸";
	magic->mp = 400;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMMON;
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force")  ;
}

virtual int valid_learn(CChar * me)
{
    int lvl =  me->query_skill("xuantian_shengong", 1);
    int t = 1, j;
    for (j = 1; j < lvl / 10; j++) t *= 2;
	
    if ( EQUALSTR(me->querystr("class"), "bonze") )
		return notify_fail("阳立地双眉紧锁，不发一声，看来是不想教你。");
	
	if (  me->query_skill("force",1) < 100 )
		return notify_fail("你的基本内功火候还不够。");
	
	if (lvl > 10 &&  me->query("repute") < t * 100)
		return notify_fail("你的侠义正气太低了。");
	
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
    return notify_fail("玄天神功只能用请教的来增加熟练度。");
}

//perform 
static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？");
	
	if ( me->query_skill("xuantian_shengong", 1) < 20)
		return notify_fail("你的玄天神功修为还不够。");
	if(  me->query("mp") < 50 ) 
		return notify_fail("你的真气不够。");
	
	if(  me->query("eff_hp") <  me->query("max_hp") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！");
	
	tell_object(me,  "你全身放松，坐下来开始运功疗伤。"  );
	tell_room(me->environment(),snprintf(msg,255,"%s吐出一口瘀血，脸色看起来好多了。",me->name()),me);
 	me->receive_curing("hp", 10 +  me->query_skill("force")/5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
 	return 1;
}

static int do_roar(CChar * me, CContainer * ob)
{
	if(  me->query("mp") < 400 )
		return notify_fail("你的内力不够。");
	
	if( me->environment()->query("no_fight") )
		return notify_fail("在这里不能攻击他人。");

	if(DIFFERSTR(me->querystr("family/family_name"), "明教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	int skill = me->query_skill("force");
	
	me->add("mp", -150);
	me->receive_damage("hp", 10);
	
	me->start_busy(5);
	message_vision("$N深深地吸一囗气，发出一声惊天动地的长啸 "  , me);
	
	DTItemList search;
	POSITION p;
	CContainer * obj;
	CChar * who = NULL;

	CopyList(&search, (me->environment())->Get_ItemList());
	p = search.GetHeadPosition();

	while(p)
	{
		obj = search.GetNext(p);

		if( ! obj->Query(IS_LIVING) || obj == me ) 
			continue;

		who = (CChar *)obj;
		//反馈效果
		if(who->query_temp("apply/反_长啸")&& (!random(3)||wizardp(me)))
		{
			message_vision("\n$HIY$n亦吹出一段尖锐的箫音，在$N的长啸下如怒涛中的一叶小舟随波起伏，但却总也不会翻覆。",me, who);
			message_vision("$HIY待$n啸声不断减弱时，箫音却不断拔高，$N啸声终于一哑，身躯微晃，面如金纸。",me, who);
			message_vision("$HIY但谁都知道他为了面子硬吞下了一口鲜血，但却已受了内伤。\n",me, who);
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
			if( skill/2 + random(skill/2) <  obj->query("con") * 2 ) 
				continue;
			
			LONG damage = skill - ( who->query("max_mp") / 10);
			if( damage > 0 ) 
			{
				who->receive_damage("hp", damage * 2, me );
				if(  who->query("mp") < skill * 2 )
					who->receive_wound("hp", damage, me);
				tell_object(who, "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样");
			}
			
			who->set_killer(me);
		}
	}

	if(who && !who->query("no_huan")) who->fight_ob(me);

	return 1;
}

FORCE_END;
