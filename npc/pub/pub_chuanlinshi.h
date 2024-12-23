//pub_chuanlinshi.h 传令结束战斗使者

NPC_BEGIN(CNpub_chuanlinshi);

virtual void create()
{
	set_name("传令使", "chuanlin shi");
 	set("gender", "女性");
    set("age", 45);
    set("attitude", "friendly");
	set("icon",old_woman);
	set("chat_chance", 100);
	call_out(do_die, 60);
};

char * chat_msg()
{
	CContainer * env = environment();
	CFightRoom * obj;
	while( (obj = (CFightRoom *)env->present("fight_room")) )
		obj->End_Fight();

	DTItemList * list = env->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * env1 = list->GetNext(p);
		if(! env1->is_character()) continue; 
		CChar * target = (CChar *)env1;  
		if(userp(target))	continue;
		if(!userp(target) && target->query("kill/level"))
		{
			destruct(target);
			continue;
		}
	}
	return "";
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		message_vision("$n向$N斜眼看了看，皱了皱眉，丢了一句“懒的理你”就转过身去。", me, this);
		me->start_busy(2);
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	destruct(me);
}

NPC_END;




