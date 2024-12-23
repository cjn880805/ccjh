
// count.h 阴阳八卦
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CScount);

virtual void create()
{
	set_name( "阴阳八卦");
	set("special", 1);

	Magic_t * magic;

	magic = add_magic("zhanbu", do_zhanbu);
	magic->name = "占卜";
	magic->mp = 200;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual const char * type() { return "knowledge"; }

virtual int valid_learn(CChar * me)
{
	if(DIFFERSTR(me->querystr("family/family_name"), "桃花岛")
		|| DIFFERSTR(me->querystr("family/master_id"), "huang laoguai"))
		return notify_fail("只有桃花黄岛主的弟子才能学阴阳八卦。");
	
	if( me->query_skill("literate",1) < 50 )
		return notify_fail("你的读书写字太低，没有办法学阴阳八卦。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("阴阳八卦只能用请教的来增加熟练度。");
}

//奇门卜算
static int do_zhanbu(CChar * me, CContainer * ob)
{
	int i, l, skill;
	i = me->query_skill("bibo_shengong", 1); 
	l = me->query_skill("qimen_wuxing", 1);
	skill = (i + l);
	
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ) target = me;
	
	if(me->is_fighting())
		return notify_fail("你正在战斗中，找死啊？\n");

	if(me->query_skill("bibo_shengong",1) < 60 )
		return notify_fail("你的碧波神功不够娴熟！\n");

	if(DIFFERSTR(me->querystr("family/family_name"), "桃花岛"))
		return notify_fail("只有桃花岛的弟子才能学阴阳八卦。");

	if(me->query_skill("count",1) < 100 )
		return notify_fail("你的阴阳八卦不够娴熟！\n");     
	
	if(me->query("mp") < 300  ) 
		return notify_fail("你的内力不够。\n");

	if(me->query_temp("thd/qimenbg"))
		return notify_fail("你正在「占卜」。\n");
	
	me->add("mp", -200);
	
	message_vision("\n$GRN$N指一算，只觉心中豁然开朗。\n", me);
	
	me->start_busy(2);
	me->add_temp("apply/int", me->query("int")*skill/500);
	me->set_temp("thd/qimenbg",me->query("int")*skill/500);  
	me->UpdateMe();
	me->call_out(remove_effect, skill);

	return 1;
}

static void remove_effect(CContainer * ob, LONG param1, LONG count)
{
	CChar * me = (CChar *)ob;
	me->add_temp("apply/int", -me->query_temp("thd/qimenbg"));
    me->delete_temp("thd/qimenbg");
    tell_object(me, "$HIY你觉得累了，脑筋也不好使了。\n");
}

SKILL_END;
