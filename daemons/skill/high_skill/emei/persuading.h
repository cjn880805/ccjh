
// persuading.h 渡世济人
//code by Fisho
//date : 2000-12-02

SKILL_BEGIN(CSpersuading);

virtual void create()
{
	set_name( "渡世济人");
	set("special", 1);

	Magic_t * magic;

	magic = add_magic("quanjia", do_quanjia);
	magic->name = "劝架";
	magic->mp = 30;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual const char * type() { return "knowledge"; }

//可以学1级，然后使用法术
virtual int valid_learn(CChar * me)
{
	if(me->query_skill("persuading", 1) > 1)
		return notify_fail("渡世济人要在实践中提高。");

	return 1;
}

//perform 
static int do_quanjia(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if ( DIFFERSTR(me->querystr("family/family_name"), "峨嵋派") )
        return notify_fail("只有峨嵋派才能用渡世济人！");

	if( me->query_temp("dushi") )
		return notify_fail("你已经在劝人家罢斗了！");
	
	if(!target || !living(target))
		return notify_fail("你要劝谁罢斗？");

    if ( EQUALSTR(target->querystr("family/family_name"), "峨嵋派") )
        return notify_fail("你不能向本派的使用渡世济人！");

	if( !wizardp(me) && wizardp(target) )
		return notify_fail("玩家不能劝巫师罢斗。");

	if( me->is_fighting() )
        return notify_fail("一边打架一边劝别人罢斗？你真是虚伪到家了！");

	if(! target->is_fighting() )
		return notify_fail("对方没在战斗。");

	if( me->query("mp") < 30)
		return notify_fail("你的法力不足！");

	me->add("mp", -30);

	int sp = 2 + me->query_skill("persuading", 1) / 5;

	message_vision(snprintf(msg, 255, "$N摇摇了头向$n慢慢走过来，双手合十，说道：我佛慈悲普度渡众生, 还请%s罢斗, 免增罪孽吧 ...！",	query_respect(target)), me, target);
	me->set_temp("dushi", 1);
	
	me->call_out(compelete_dushi, 3, target->object_id(), sp);

	return 1;
	
}

static void compelete_dushi(CContainer * ob, LONG param1, LONG sp)
{
	CChar * me = (CChar *)ob;
	CContainer * where = me->environment();
	CChar * who = (CChar *)where->Present(param1);
	
	me->delete_temp("dushi");
	
	if(! where->Query(IS_FIGHTROOM))
		return;

	if(! who )
	{
		tell_object(me, "太可惜了，你要找的人已经走了。");
		return;
	}

	int dp = who->query("level");

	if( living(who) && (random(sp + dp) > dp) ) 
	{
		message_vision("$n低头想了一会，又看了看$N，摇摇头，叹了口气，停止了打斗。", me, who);
		
		((CFightRoom *)where)->Leave_Team(who);
		
		me->improve_skill("persuading", dp + random(dp));
		me->add("combat_exp", 1 );
		me->start_busy(3);
	} 
	else 
	{
		if( random(sp) > dp/2 ) 
		{
			message_vision("$n狠狠地瞪了$N一眼，喝道：我都快让人给打死了，能罢斗吗! \n$N叹了口气转身走开了。", me, who);
			return;
		}
	
		message_vision("$n扭过头去，对$N理都不理。", me, who);
	}
}

SKILL_END;
