//baby.h
//С����
//2001-03-11

NPC_BEGIN(CNmonster_baby);

virtual void create()
{
	set_name("����", "baby");
    set("gender", "Ů��");
	set("icon", girl1);

    set("age", 1);
    set("attitude", "friendly");
    set("long","�Ա�����");
    set("combat_exp", 1);
	set("str", 3);

	//set("parents",({"dad","mom"}));
	
	set("chat_chance", 2);
	set("is_baby",1);		
}

char * chat_msg()
{	
	static char desc1[5][80] = {
		"$N�������������衫����������������",
		"$N������������Ҫ���衫������������",
		"$Nƴ���޵����֡����衫�����������ﰡ����������������",
		"$N�޽е������衫����Ҫ���衫��",
		"$N��޵����֡����衫������ѽ������������",
	};

	static char desc2[5][80] = {
		"$N���˲����飮",
		"$N����ѽѽ�ĺߺ��ţ�",
		"$N�����ڱǿף�",
		"$N���﷢���ߺ����ص�������",
		"$N������ͣ������Ľ��ţ�",
	};
	
	static char desc3[5][80] = {
		"$N���ֵĳ����˸�ҥ������һ������һ��",
		"$N�������飬������Ц������",
		"$N��������Ц������"
		"$Nһ��һ�������ֳ������Ķ������Ķ���",
		"$N������Ц�ţ���֪����ʲô����Ķ�����"
	};

	if(environment()->query_temp("nursery"))	
	{
		//���ж�����
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
		message_vision("$N��$n�ӻ������������", me, this);
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
			message_vision("$N��������$n����������§�ڻ��", me, this);
		} 
		else 
		{
			message_vision("$N������һ��ȴû��$n��������С�һ�ó��ģ�", me, this);
		}
    } 
	else 
	{
		message_vision("$N������$n�쿪˫�֣�$nȴһ���������ˣ�����", me, this);
	}
     
	return 1;
}

int do_kill(CChar * me, string verb)
{       
	char msg[255];

	  if(verb == "kill")
	      tell_room(environment(), snprintf(msg, 255, "%sƴ���ؿ����������������������%sҪɱ�ң����������ѽ��", name(1), me->name(1)));
	  else if(verb == "fight")
	      tell_room(environment(), snprintf(msg, 255, "%s�����������������������%sҪ���ҵ��ǳԣ����������ѽ��", name(1), me->name(1)));
      else if(verb == "cast")
	      tell_room(environment(), snprintf(msg, 255, "%s�����������������������%sҪ͵���ҵ��ǣ�", name(1), me->name(1)));        
      
	  return 0;
}

virtual void relay_emote(CChar *me, string verb)
{
	char msg[255];

    if( !userp(me) ) return;

    if( verb == "kick")
	{
         say(snprintf(msg, 255, "�������������%s����Ү��", me->name(1)));
		 command(snprintf(msg, 255, "kick %ld", me->object_id()));
	}
	else if( verb == "slap")
	{
         say(snprintf(msg, 255, "�������������%s����Ү����ʹ����������", me->name(1)));
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
        message_vision("$n�ɻ�ؿ���$N��", me, this);
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
