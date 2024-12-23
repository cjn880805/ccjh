//pub_wokou.h
//lanwood 2001-11-04

NPC_BEGIN(CNpub_wokou1);

typedef struct{
	int	search_id;
	int has_search;
	string enter_door;		
}path_t;

typedef map<string, path_t *, less<string> > MAP2PATH;
typedef MAP2PATH::iterator iterator_path;

MAP2PATH m_search;

void create()
{
	set_name("倭寇", "wo kou");

	set("title", "东洋死士");

	set("icon", masked_man);
	set("gender", "男性");
	set("level", 157);
	set("shen_type", -1);

	set("max_hp", 20000);
	set("max_mp", 6000);
	set("mp_factor", 80);

	set("combat_exp", 50000000);
	set("score", 6000);

	set("chat_chance", 30);

	set("str", 30);
	set("con", 30);
	set("int", 15);
	set("dex", 30);

	set_skill("dongyangdaofa", 300+random(51));
	set_skill("blade", 300+random(51));
	set_skill("wudu_zhang", 300+random(51));
	set_skill("strike", 300+random(51));
	set_skill("guimei_shenfa", 300+random(51));
	set_skill("dodge", 300+random(51));
	set_skill("yunlong_shengong", 300+random(51));
	set_skill("force", 300+random(51));

	map_skill("blade", "dongyangdaofa");
	map_skill("strike", "wudu_zhang");
	map_skill("dodge", "guimei_shenfa");
	map_skill("force", "yunlong_shengong");

	prepare_skill("strike", "wudu_zhang");

	set("apply/armor", 160);
	set("apply/damage", 60+random(50));

	create_family("柳生流", 4, "弟子");

	carry_object("blade_1")->wield();

}

virtual char * chat_msg()
{
	if(!random(3))
	{
		CContainer * env = environment();
		CChar * target;
		DTItemList * list = env->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		while(p) 
		{ 
			if(env->query("no_fight")) break;
			CContainer * obj = list->GetNext(p);
			if(! obj->is_character()) continue; 
			target = (CChar *)obj;  
			if(!userp(target))	continue;
			if(!living(target))	continue;
			if(EQUALSTR(target->querystr("gender"), "女性") && target->query("age")<30 )
			{
				message_vision("\n$N色咪咪的朝$n凑了过去：お姊ちゃん，一绪に 行きますが？", this,target);
				break;
			}
			else if( target->query("combat_exp")>10000000 )
			{
				message_vision("\n$N面露凶相，恶狠狠的对$n喝道：马鹿野狼，なにをみて？死ぬ！！", this,target);
				break;
			}
		}
	}
	else if(search())
	{
		do_die();		//搜索完毕，自动毁灭！
		return 0;
	}
	
	
	return 0;
}

int search()
{
	char msg[80];
	
	if(! m_pEnvironment->Query(IS_ROOM)) return 0;
	
	CRoom * room = (CRoom *)m_pEnvironment;
	DTEXITLIST * list = room->query_exits();
	
	path_t * node;
	
	node = get_path(room->querystr("base_name"));
	
	int doors = list->GetCount();
	
	if(! querystr("start_point")[0])
		set("start_point", room->querystr("base_name"));
	
	if(node->has_search)
	{
		//判断是否起点
		if(EQUALSTR(room->querystr("base_name"), querystr("start_point")))
		{
			return 1;
		}
		
		//找个退路！
		command(snprintf(msg, 80, "go 0 %s", node->enter_door.c_str()));
		
		return 0;
	}
	
	if(doors)
	{
		
		node->search_id++;
		
		if(node->search_id >= doors)
			node->search_id = 0;
		
		POSITION p = list->FindIndex(node->search_id);
		CDoor * dir = list->GetAt(p); 
		
		if(dir->querystr("id") == node->enter_door)
		{
			node->has_search = 1;
		}
		
		command(snprintf(msg, 80, "go 0 %s", dir->querystr("id")));
		
		room = (CRoom *)environment();
		
		node = get_path(room->querystr("base_name"));
		
		if(! node->enter_door.length())
		{
			node->enter_door = dir->querystr("next_door");
			list = room->query_exits();
			for(int i=0; i<list->GetCount(); i++)
			{
				p = list->FindIndex(i);
				dir = list->GetAt(p);
				if(dir->querystr("id") == node->enter_door)
				{
					node->search_id = i;
					return 0;
				}
				
			}
		}
		
		return 0;
	}
	return 0;
}

path_t * get_path(string room_name)
{
	if(m_search.find(room_name) == m_search.end())
	{
		path_t * node = new path_t;
		
		node->search_id = 0;
		node->has_search = 0;
		node->enter_door = "";
		
		m_search[room_name] = node;
		return node;
	}
	
	return m_search[room_name];
}

void clear_path()
{
	iterator_path p;
	
	for(p = m_search.begin(); p!=m_search.end(); p++)
		delete p->second;
	
	m_search.clear();
}

virtual void do_die()
{
	clear_path();
	CNpc::die();
}


virtual void die()
{
	CContainer * obj = environment();
	CContainer * bot= load_item("jinggang");
	bot->move(obj);
	CNpc::die();
}

NPC_END;