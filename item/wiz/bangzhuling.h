// 教主令
// Lanwood 2001-06-04
char * check_legal_name(const char * name);

ITEM_BEGIN(CIbangzhuling);

void create(int nFlag = 0)
{
    set_name("开除令", "kaichu ling");
    set_weight(100);
    
	set("long", "这是用来开除帮众的令牌。");
}

void init()
{
	CContainer * me = environment();

	if(userp(me) && _M.undefinedp("owner"))
	{
		set("owner", me->id(1));		
	}
}

int query_autoload()
{
	return 1;
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
//	if(! CMoney::Player_Pay(me, 200000))
//		return notify_fail("开除帮众开支20万。请备足现金。");
	if( lv >= who->query("corps/level"))
		return notify_fail("你没资格开除对方。");

//	CMoney::Pay_Player(who, 100000);

	CRoom * r = load_room(corps_id);

	g_Channel.do_channel(me, NULL, "corps", 
		snprintf(msg, 255, "%s听令，今日起与你我%s不再相干！", who->name(), r->name()));		
	who->del("corps");
	who->set("start_city", START_ROOM);

	if(who->environment() == r)
		who->move(load_room(r->querystr("belong")));

	who->setup();
	who->UpdateMe();
	tell_object(who, snprintf(msg, 255, "你被开除出%s。", load_room(corps_id)->name()));

	return 1;
}


ITEM_END;