//pub_chuanlinshi.h �������ս��ʹ��

NPC_BEGIN(CNpub_chuanlinshi);

virtual void create()
{
	set_name("����ʹ", "chuanlin shi");
 	set("gender", "Ů��");
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
		message_vision("$n��$Nб�ۿ��˿���������ü������һ�䡰�������㡱��ת����ȥ��", me, this);
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




