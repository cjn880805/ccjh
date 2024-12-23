//habagou.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_habagou);

virtual void create()
{
	set_name("哈巴狗","ha ba gou");
	
	set("icon", dog);
	set("title", "博饼屋宠物");
	set("race", "野兽");
	set("gender", "雄性" );
	set("age", 15);
	set("str", 22);
	set("int", 30);
	set("dex", 30);
	set("con", 30);
	
	set("long","你看到的是博饼屋里的小哈巴狗。");
	set("combat_exp", 2000000);
	set("attitude", "friendly");
	
	set("max_hp", 30000);
	set_inquiry("博饼屋","这儿就是，你要玩吗？");
	set_inquiry("博饼会",ask_me );
};

static char * ask_me(CNpc * npc , CChar * player)
{
	iterator_user p;
	CUser * user;
	
	if ( !wizardp(player) ) return "你无权召开博饼会！";
	
	for( p = g_UserList.begin(); p!= g_UserList.end(); p++)
	{
		user = p->second;
		user->move(load_room("bobing"));
	}
	
	npc->command("chat 博饼屋要聚会了！大家快来！");
	return "好，现在博饼会正式开始，全体集合！";
}

virtual int handle_action(char * comm , CChar * player ,char * arg)
{
	if(strcmp(comm, "save") == 0)
		return do_save(player);
	else if(strcmp(comm, "smash") == 0)
		return do_smash(player);
	else if(strcmp(comm, "cast") == 0)
		return do_exert(player);
	
	return 0;
}

int do_save(CChar * player)
{
	char msg[255];
	
	say(snprintf(msg,255, "%s,这儿不许存盘的。",player->query("name")),player);
	SendMenu(player);
	return 1;
}

int do_smash(CChar * player)
{
	char msg[255];
	
	say(snprintf(msg,255, "%s，巫师在这儿也不许杀人的。",player->query("name")),player);
	SendMenu(player);
	return 1;
}

int do_exert(CChar * player)
{
	char msg[255];
	
	say(snprintf(msg,255, "%s，专心博饼吧！",player->query("name")),player);
	SendMenu(player);
	return 1;
}

NPC_END;
