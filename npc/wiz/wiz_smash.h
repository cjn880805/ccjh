//wiz_smash.h
//NPC �Զ��������ս��������
//Lanwood 2001-02-08

NPC_BEGIN(CNwiz_smash);

typedef struct{
		int	search_id;
		int has_search;
		string enter_door;		
	}path_t;

typedef map<string, path_t *, less<string> > MAP2PATH;
typedef MAP2PATH::iterator iterator_path;

MAP2PATH m_search;

virtual void create()
{
	set_name( "�ķ�Ѳ��ʹ", "xunhun shi");
		
	set("age", 40);
	set("gender", "����");

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
	set_temp("fight/is_fighting",1);
};

//��һ����Ҫ����������ǲ�ͣ����·��
virtual char * chat_msg()
{
	if(search())
	{
		do_die();		//������ϣ��Զ�����
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
		//�ж��Ƿ����
		if(EQUALSTR(room->querystr("base_name"), querystr("start_point")))
		{
			del("start_point");
			add("count",1);
			return 0;
		}
		//�Ҹ���·��
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
					
					CContainer * env = environment();
					CFightRoom * obj_fight;
		
					//��鵱ǰ�������Ƿ���ս��
					while( (obj_fight = (CFightRoom *)env->present("fight_room")) && !obj_fight->query("ok") )
					{
						DTItemList * list = obj_fight->Get_ItemList();  
						POSITION p = list->GetHeadPosition(); 
						while(p) 
						{ 
							CContainer * obj_smash = list->GetNext(p);
							if(! obj_smash->is_character()) continue; 
							CChar * target = (CChar *)obj_smash;  
							if(!userp(target))	continue;
							if(target->query_temp("fight/is_fighting") && target->query_temp("net_dead"))
							{
								obj_fight->set("smash",1);
								break;
							}
						}
						if(obj_fight->query("smash"))
						{
							obj_fight->End_Fight();
						}
						else
						{
							obj_fight->set("ok",1);
						}
					}
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


int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		me->start_busy(2);
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}

NPC_END;