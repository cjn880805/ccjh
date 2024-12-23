// 教主令
// Lanwood 2001-06-04
char * check_legal_name(const char * name);

ITEM_BEGIN(CIbangzhuling1);

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
	if( lv >= who->query("corps/level"))
		return notify_fail("你没资格开除对方。");

	CRoom * r = load_room(corps_id);
	r->add("corps/member_count",-1);
	if(who->query("corps/level")<7)
		r->add(snprintf(msg, 255, "corps/rank%ld", who->query("corps/level")),-1);
	r->del(snprintf(msg, 255,"repute/%s",who->id(1)));
	r->del(snprintf(msg, 255,"money/%s",who->id(1)));
	r->del(snprintf(msg, 255,"list/%s",who->id(1)));

	g_Channel.do_channel(me, NULL, "corps", 
		snprintf(msg, 255, "%s听令，今日起你与我%s不再相干！", who->name(), r->name()));		

	if(who->query("corps/quest_exp")>0)
		who->add("combat_exp",-who->query("corps/quest_exp"));
	who->del("corps");
	who->set("start_city", START_ROOM);
	
	if(EQUALSTR((who->environment())->querystr("area"),r->querystr("area")))
		who->move(load_room(r->querystr("door")));

	who->setup();
	who->UpdateMe();
	tell_object(who, snprintf(msg, 255, "你被开除出%s。", load_room(corps_id)->name()));

	return 1;
}

int do_look(CChar * me)
{
	CItem::do_look(me);
	if(me->query("corps/level")<3)
	{
		char msg[255];
		CRoom * r = load_room(me->querystr("corps/id"));
		
		AddMenuItem(snprintf(msg, 255,"查看%s成员名单", r->name()),"$0list $1", me);
		AddMenuItem(snprintf(msg, 255,"开除%s成员", r->name()),"$2kick_out $1 $2", me);
		SendMenu(me);
	}
	return 1;
}


int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "list") == 0 && me->query("corps/level") < 3)
		return do_list(me);
	else if(strcmp(comm, "kick_out") == 0 && me->query("corps/level") < 3)
		return do_kick_out(me,arg);
	return 0;
}

int do_list(CChar * me)
{
	if(me->query("corps/level")<3)
	{
		char msg[255];
		CContainer * r = load_room(me->querystr("corps/id"));
		CMapping * enemy = r->querymap("list");
		
		if(! enemy) return notify_fail("目前帮派还没有招收任何人。");	
		
		CVector v;
		enemy->keys(v);
		
		for(int i=0; i<v.count(); i++)
			AddMenuItem(snprintf(msg, 255, "%s：%s", v[i], enemy->querystr(v[i])), "", me);
		
		SendMenu(me);
	}
	return 1;
}

int do_kick_out(CChar * me, char * arg)
{
	if(me->query("corps/level")<3)
	{
		char msg[255];
		int len = strlen(arg);
		if(len < 1 || len > 10)
		{
			say("你想开除谁呢？", me);
			SendMenu(me);
			return 1;
		}
		int user_id=atoi(arg);
		if(DIFFERSTR(arg, snprintf(msg, 255,"%d",user_id)) )
		{
			say("你想开除谁呢？", me);
			SendMenu(me);
			return 1;
		}
		if(EQUALSTR(arg, me->id()) )
		{
			say("不能对自己使用。", me);
			SendMenu(me);
			return 1;
		}
		
		const char * corps_id = me->querystr("corps/id");
		int lv = me->query("corps/level");
		CRoom * r = load_room(corps_id);
		
		CUser * targetx;
		targetx=find_online(arg);
		if (targetx)
		{
			if( DIFFERSTR(corps_id, targetx->querystr("corps/id")) )
				return notify_fail("对方不属于你的帮会。");
			if( lv >= targetx->query("corps/level"))
				return notify_fail("你没资格开除对方。");
			
			r->add("corps/member_count",-1);
			if(targetx->query("corps/level")<7)
				r->add(snprintf(msg, 255, "corps/rank%ld", targetx->query("corps/level")),-1);
			r->del(snprintf(msg, 255,"repute/%s",targetx->id(1)));
			r->del(snprintf(msg, 255,"money/%s",targetx->id(1)));
			r->del(snprintf(msg, 255,"list/%s",targetx->id(1)));
			
			g_Channel.do_channel(me, NULL, "corps", 
				snprintf(msg, 255, "%s听令，今日起你与我%s不再相干！", targetx->name(), r->name()));		
			
			if(targetx->query("corps/quest_exp")>0)
				targetx->add("combat_exp",-targetx->query("corps/quest_exp"));
			targetx->del("corps");
			targetx->set("start_city", START_ROOM);
			
			if(EQUALSTR((targetx->environment())->querystr("area"),r->querystr("area")))
				targetx->move(load_room(r->querystr("door")));
			
			targetx->setup();
			targetx->UpdateMe();
			tell_object(targetx, snprintf(msg, 255, "你被开除出%s。", load_room(corps_id)->name()));
			
			return 1;
		}
		else
		{
			targetx = add_user();
			targetx->set("id", arg);
			targetx->LoadFromServer();

			if( DIFFERSTR(corps_id, targetx->querystr("corps/id")) )
			{
				destruct(targetx);
				return notify_fail("对方不属于你的帮会。");
			}
			if( lv >= targetx->query("corps/level"))
			{
				destruct(targetx);
				return notify_fail("你没资格开除对方。");
			}

			r->add("corps/member_count",-1);

			if(targetx->query("corps/level")<7)
				r->add(snprintf(msg, 255, "corps/rank%ld", targetx->query("corps/level")),-1);
			r->del(snprintf(msg, 255,"repute/%s",targetx->id(1)));
			r->del(snprintf(msg, 255,"money/%s",targetx->id(1)));
			r->del(snprintf(msg, 255,"list/%s",targetx->id(1)));

			if(targetx->query("corps/quest_exp")>0)
				(CChar *)targetx->add("combat_exp",-targetx->query("corps/quest_exp"));
			targetx->del("corps");
			targetx->set("start_city", START_ROOM);
			
			targetx->Save();
			
			g_Channel.do_channel(me, NULL, "corps", 
				snprintf(msg, 255, "%s听令，今日起你与我%s不再相干！", targetx->name(), r->name()));
			destruct(targetx);
		}
	}
	return 1;
}

ITEM_END;