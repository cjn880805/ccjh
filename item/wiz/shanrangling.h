// 教主令
// Lanwood 2001-06-04
char * check_legal_name(const char * name);

ITEM_BEGIN(CIshanrangling);

void create(int nFlag = 0)
{
    set_name("禅让令", "shanrang ling");
    set_weight(100);
    
	set("long", "这是用来禅让帮主地位的令牌。");
}

void init()
{
	CContainer * me = environment();

	if(userp(me) && _M.undefinedp("owner"))
	{
		set("owner", me->id(1));		
	}
}

int Can_Use()
{
	return 1;
}

int do_use(CChar * me, CContainer * target)
{
	char msg[255];

	if(target == me)
		return notify_fail("不能对自己使用。");
	
	if(! target->is_character()) return notify_fail("你要对谁使用？");
	CChar * who = (CChar *)target;

	int lv = me->query("corps/level");
	
	const char * corps_id = me->querystr("corps/id");

	if( DIFFERSTR(corps_id, who->querystr("corps/id")) )
		return notify_fail("对方不属于你的帮会。");

	if(who->query("level") < 80)
		return notify_fail("对方没有足够的威信出任帮主一职！");
	
	if( lv != 1 )
		return notify_fail("你没资格。");
	
	CRoom * r = load_room(corps_id);

	g_Channel.do_channel(me, NULL, "corps", 
		snprintf(msg, 255, "我决定今日起由%s接替我%s主人之位！", who->name(), r->name()));		

	who->set("corps/level", 1);
	who->set("corps/rank", "少主");

	me->set("corps/level", 2);
	me->set("corps/rank", "前任主人");
		
	who->setup();
	who->UpdateMe();

	me->setup();
	me->UpdateMe();
	
	return 1;
}


ITEM_END;