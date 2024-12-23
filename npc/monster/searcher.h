//searcher.h
//code by Lanwood
//2001-2-7

//自动搜索地图的NPC
extern void DrawMap();

NPC_BEGIN(CNmonster_searcher);

virtual void create()
{
	set_name( "索路机器人", "searcher");
		
	set("age", 40);
	set("gender", "男性");

	set("max_hp", 20000);
	set("max_mp", 20000);
	set("mp_factor", 15);
	set("combat_exp", 200000);

    set_skill("force",   30);
	set_skill("unarmed", 30);
	set_skill("sword",   30);
	set_skill("changquan",   30);
	set_skill("magic", 30);
	set_skill("jinshe_jian", 30);
	set("nkgain", 100);
		
	map_skill("unarmed", "changquan");
	map_skill("force", "magic");
	map_skill("sword", "jinshe_jian");

	set("chat_chance", 100);

	carry_object("sword_1")->wield();	
};

//他一生所要做的事情就是不停的走路！
virtual char * chat_msg()
{
	for(int i=0; i< 20; i++)
	{
		if(search())
		{
			DrawMap();			//输出地图
			destruct(this);		//搜索完毕，自动毁灭！
			return 0;
		}
	}

	return 0;
}

int search()
{
	char msg[80];

	if(! m_pEnvironment->Query(IS_ROOM)) return 0;

	CRoom * room = (CRoom *)m_pEnvironment;
	DTEXITLIST * list = room->query_exits();
	int idx = room->query("search_id");
		
	int doors = list->GetCount();
	
	if(! querystr("start_point").length())
		set("start_point", room->querystr("base_name"));

	if(room->query("has_search"))
	{
		//判断是否起点
		if(EQUALSTR( room->querystr("base_name"), querystr("start_point")))
		{
			command("chat 0 哇呀呀！我的生命结束了！");
			return 1;
		}

		command("chat 0 已经搜索过了！");
		//找个退路！
		command(snprintf(msg, 80, "go 0 %s", room->querystr("enter_door").c_str()));

		return 0;
	}

	if(doors)
	{
			
		idx++;

		if(idx >= doors)
			idx = 0;

		room->set("search_id", idx);

		POSITION p = list->FindIndex(idx);
		CDoor * dir = list->GetAt(p); 

		if(EQUALSTR(dir->querystr("id"), room->querystr("enter_door")))
		{
			room->set("has_search", 1);
		}

		command(snprintf(msg, 80, "go 0 %s", dir->querystr("id").c_str()));
		
		room = (CRoom *)environment();
		if(! room->querystr("enter_door").length())
		{
			room->set("enter_door", dir->querystr("next_door"));
			list = room->query_exits();
			for(int i=0; i<list->GetCount(); i++)
			{
				p = list->FindIndex(i);
				dir = list->GetAt(p);
				if(EQUALSTR(dir->querystr("id"), room->querystr("enter_door")))
				{
					room->set("search_id", i);
					command(snprintf(msg, 80, "chat 0 我进入了%s", room->querystr("base_name").c_str()));
					return 0;
				}
			}

			command(snprintf(msg, 80, "chat 0 我在%s找不到正确的门%s！", room->querystr("base_name").c_str(), room->querystr("enter_door").c_str()));			
		}
		
		return 0;
	}

	command("chat 0 我进入失败的房间了！");
	return 0;
}

NPC_END;
