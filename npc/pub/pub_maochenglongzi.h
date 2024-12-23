//pub_maochenglongzi.h
//毛成龙幼子
//2002-11-23

NPC_BEGIN(CNpub_maochenglongzi);

virtual void create()
{
	set_name("毛成龙幼子", "baby");
    set("gender", "男性");
	set("icon", girl1);

    set("age", 1);
    set("attitude", "friendly");
    set("combat_exp", 1);
	set("str", 3);

	set("max_hp",100);
	set("eff_hp",100);
	set("hp",100);
	
	set("chat_chance", 20);
	set("is_baby",1);	
	set("no_kill",1);
	set("zhang",1);
}

char * chat_msg()
{	
	static char desc1[5][80] = {
		"$N哭了起来：妈妈～～～～～～～～～",
		"$N哭了起来：我要妈妈～～～～～～～",
		"$N拼命哭道：爸～～妈～～你们在哪里啊～～～～～～～～",
		"$N哭叫道：妈妈～～我要妈妈～～",
		"$N大哭道：爸～～妈～～快来呀～～～～～～",
	};
	
	static char desc2[5][80] = {
		"$N擦了擦鼻涕．",
		"$N咿咿呀呀的哼哼着．",
		"$N挖了挖鼻孔．",
		"$N嘴里发出哼哼呜呜的声音．",
		"$N拍着嘴巴，啊啊的叫着．",
	};
	
	static char desc3[5][80] = {
		"$N快乐的唱起了歌谣：你拍一～我拍一～",
		"$N擦擦鼻涕，哈哈的笑起来．",
		"$N咯咯咯的笑起来．"
		"$N一蹦一跳的拍手唱：你拍二～我拍二～",
		"$N咯咯的笑着，不知看到什么好玩的东西．"
	};
	
	if(environment()->query("nursery"))	//在儿童乐园里
	{
		int happy = random(50)+50;
		
		if(happy < 80 )
		{
			message_vision(desc2[random(5)], this);
		}
		else
		{
			message_vision(desc3[random(5)], this);
		}
	}
	else
	{
		message_vision(desc1[random(5)], this);
	}
	
	return 0;
}


virtual int handle_action(char *comm, CChar *me, char *arg)
{
	if(!strcmp(comm, "kill") || !strcmp(comm, "fight") || !strcmp(comm, "cast")  )
	{
		return do_kill(me);
	}
	else if( strcmp(comm, "drop") == 0)
		return do_drop(me);

	return CNpc::handle_action(comm, me, arg);
}

int do_drop(CChar * me)
{
     if(move(me->environment())) 
	 {
		message_vision("$N把$n从怀里放了下来。", me, this);
		return 1;
     }   
	 return 0;
}

int do_kill(CChar * me)
{       
	char msg[255];
	tell_room(environment(), snprintf(msg, 255, "%s拼命地哭了起来：爹～～，娘～～，%s要杀我．．．快回来呀！", name(1), me->name(1)));  

	if(me->query("zhang/renwu5")==3)
	{
		CFightRoom * obj;
		CChar * baobiao;
		CContainer * env = environment();

		obj = (CFightRoom *)load_item("fight_room");		
		
		obj->set_name( "绑架毛成龙幼子的战斗", "fight_room");		
		obj->move(env);
		
		me->move(obj);
		obj->Join_Team(me, CFightRoom::FIGHT_TEAM_A);

		for(int i=0;i<3;i++)
		{
			baobiao = load_npc("pub_mao_huyuan3");
			baobiao->move(obj);
			obj->Join_Team(baobiao, CFightRoom::FIGHT_TEAM_B);				
		}
		move(obj);
		obj->Join_Team(this, CFightRoom::FIGHT_TEAM_B);
		obj->Begin_Fight(0);
	}
	return 0;
}

NPC_END;
