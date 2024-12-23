//baby.h
//小宝贝
//2001-03-11

NPC_BEGIN(CNmonster_baby);

virtual void create()
{
	set_name("宝宝", "baby");
    set("gender", "女性");
	set("icon", girl1);

    set("age", 1);
    set("attitude", "friendly");
    set("long","乖宝宝。");
    set("combat_exp", 1);
	set("str", 3);

	//set("parents",({"dad","mom"}));
	
	set("chat_chance", 2);
	set("is_baby",1);		
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

	if(environment()->query_temp("nursery"))	
	{
		//在托儿所里
		int happy = query("happy");
		if(happy < 50)
		{
			message_vision(desc1[random(5)], this);
		}
		else if(happy < 80)
		{
			message_vision(desc2[random(5)], this);
		}
		else
		{
			if(! random(10) )
				message_vision(desc3[random(5)], this);
		}
	}
	else
		random_move();

	return 0;
}

virtual LONG Query(int nAttr)
{
	if(nAttr == CAN_GET)
		return 1;

	return CNpc::Query(nAttr);
}

virtual int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0
		|| (strcmp(comm, "cast") == 0 && strcmp(arg, "stealing steal") == 0) )
	{
		return do_kill(me, comm);
	}
	else if(strcmp(comm, "get") == 0 )
		return do_get(me);
	else if( strcmp(comm, "drop") == 0)
		return do_drop(me);
	else if( strcmp(comm, "tell") == 0)
		return do_whisper(me, arg);

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

int do_get(CChar * me)
{   
	if(is_parent(me))
	{
		if(move(me)) 
		{
			message_vision("$N弯下腰把$n抱了起来，搂在怀里。", me, this);
		} 
		else 
		{
			message_vision("$N弯下腰一抱却没把$n抱起来，小家伙好沉哪！", me, this);
		}
    } 
	else 
	{
		message_vision("$N蹲下身朝$n伸开双手，$n却一下子闪开了．．．", me, this);
	}
     
	return 1;
}

int do_kill(CChar * me, string verb)
{       
	char msg[255];

	  if(verb == "kill")
	      tell_room(environment(), snprintf(msg, 255, "%s拼命地哭了起来：爹～～，娘～～，%s要杀我．．．快回来呀！", name(1), me->name(1)));
	  else if(verb == "fight")
	      tell_room(environment(), snprintf(msg, 255, "%s哭了起来：爹～～，娘～～，%s要抢我的糖吃．．．快回来呀！", name(1), me->name(1)));
      else if(verb == "cast")
	      tell_room(environment(), snprintf(msg, 255, "%s哭了起来：爹～～，娘～～，%s要偷吃我的糖！", name(1), me->name(1)));        
      
	  return 0;
}

virtual void relay_emote(CChar *me, string verb)
{
	char msg[255];

    if( !userp(me) ) return;

    if( verb == "kick")
	{
         say(snprintf(msg, 255, "爹～～，娘～～，%s踢我耶！", me->name(1)));
		 command(snprintf(msg, 255, "kick %ld", me->object_id()));
	}
	else if( verb == "slap")
	{
         say(snprintf(msg, 255, "爹～～，娘～～，%s打我耶，好痛啊～～～～", me->name(1)));
         command(snprintf(msg, 255, "slap %ld", me->object_id()));
    }
	else if(verb == "hit")
	{        
		command(snprintf(msg, 255, "pain %ld", me->object_id()));
    }
	else if(verb == "bite")
	{
		command(snprintf(msg, 255, "face %ld", me->object_id()));
	}
	else if(verb == "papaya")
	{
        command("pout");
	}
}

int is_parent(CChar * me)
{
	if(EQUALSTR(querystr("father"), me->querystr("id"))
		|| EQUALSTR(querystr("mother"), me->querystr("id")) )
		return 1;

	return 0;
}

int do_whisper(CChar * me, string verb)
{
    if(! is_parent(me))
    {
        message_vision("$n疑惑地看着$N。", me, this);
        return 1;
    }

    //note, do not allow the order contain "chat", "tell"...
    //may need disable more later...
        
	if( verb == "chat" 
		|| verb == "rumor"
		|| verb == "tell"
		|| verb == "follow"
		|| verb == "apprentice"
		|| verb == "recruit")
                return 0;
   if (verb.length())
   {
	   set_temp("wanttodo", verb.c_str());
       remove_call_out(do_relaying);
       call_out(do_relaying, 1 + random(3));
   }

   return 1;
}

static void do_relaying(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	char msg[255];

	snprintf(msg, 255, "%s", me->querystr_temp("wanttodo"));
	me->command(msg);
}

NPC_END;
