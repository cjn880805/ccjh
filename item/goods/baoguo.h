ITEM_BEGIN(CIbaoguo);

virtual void create(int nFlag = 0)		
{
	set_name("神秘的包裹","bao guo");	
	set_weight(20000);
	call_out(do_baoguo, 1);	
};

virtual int do_look(CChar * me)
{
	say("这是一个神秘的包裹，鼓鼓囊囊的不知道装着些什么。", me);
	SendMenu(me);
	return 1;
}

static void do_baoguo(CContainer * ob, LONG param1, LONG param2)
{
	if(ob->querystr("owner1")[0])
	{
		char msg[255];
		CUser * player;
		snprintf(msg,255,"%s",ob->querystr("owner1"));
		player=find_online(msg);
		if(!player)
		{
			destruct(ob);
		}
		else
		{
			ob->call_out(do_jiebiao, 1);
		}
	}
	else
		destruct(ob);
}


static void do_jiebiao(CContainer * ob, LONG param1, LONG param2)
{
	if(ob->querystr("owner1")[0])
	{
		char msg[255];
		CUser * player;
		snprintf(msg,255,"%s",ob->querystr("owner1"));
		player=find_online(msg);
		if(!player)
			destruct(ob);
		else
		{
			CContainer * env=player->environment();
			ob->call_out(do_jiebiao, random(8)+5);
			if(!player->query_temp("fight/is_fighting")&& DIFFERSTR(env->querystr("area"), "house"))
			{
				DTItemList * list = player->Get_ItemList();  
				POSITION p = list->GetHeadPosition(); 
				while(p) 
				{
					CContainer * obj = list->GetNext(p);
					if(obj->is_character()) continue; 
					if(userp(obj))	continue;
					if(EQUALSTR(obj->querystr("id"), "bao guo") && EQUALSTR(obj->querystr("owner1"),player->id(1)) )
					{
						player->set_temp("no_fei",1);
						message_vision("突然窜出了几条黑影！为首者大喝道：",player);
						message_vision("$HIR        此山是我开，",player);
						message_vision("$HIR        此树是我栽;",player);
						message_vision("$HIR        要想从此过，",player);
						message_vision("$HIR        留下包裹来！",player);
						
						CFightRoom * obj=(CFightRoom *)load_item("fight_room");
						obj->set("room_locked", FIGHT_LOCKED);
						obj->set_name( "劫镖战斗", "fight_room_jiebiao");		
						obj->move(env);
						
						player->move(obj);
						obj->Join_Team(player, CFightRoom::FIGHT_TEAM_B);
						
						int flag = 8 + random(3);
						CNnpcmirror * robber = (CNnpcmirror *)load_npc("monster_anbiao");
						robber->make_mirror(player, flag);
						robber->set_name("蒙面独行盗","mengmian dao");
						if(player->query("level")<80)robber->set("flag",flag);
						robber->move(obj);
						obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);	
						
						obj->Begin_Fight(0);
						break;
					}
				}
			}
		}
	}
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(!strcmp(comm, "drop") )
	{
		if(EQUALSTR(querystr("owner1"),me->id(1)))
		{
			if(me->query_temp("no_fei"))
				me->delete_temp("no_fei");
			if(me->query_temp("lin/baoguo/start"))
				me->delete_temp("lin/baoguo/start");
			me->add_temp("lin/baoguo/count",-3);
			if(me->query_temp("lin/baoguo/count")<=0)
				me->delete_temp("lin/baoguo/count");
//			if(me->query_temp("fight/is_fighting"))
//			{
//				CFightRoom * obj=(CFightRoom *)me->environment();
//				obj->End_Fight();
//			}
		}
		this->remove_call_out(do_jiebiao);
		destruct(this);
		return 1;
	}
	else if(!strcmp(comm, "give") )
	{
		CContainer * obj = Present(atol(arg));
		if(userp(obj))
		{
			this->remove_call_out(do_jiebiao);
			destruct(this);
			return 1;
		}
	}
	return 0;
}

virtual void owner_is_killed(CChar *me)
{
	if(me)
		tell_object(me,"只见眼前金光一闪...好象是.....");

	destruct(this);
} 

ITEM_END;

