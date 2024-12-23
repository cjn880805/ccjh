//tongdao4.h

//Sample for room: 黑木崖顶通道4层
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_tongdao4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黑木崖顶通道4层");
	
	add_npc("heimuya_jiaotu4");
	add_npc("heimuya_jiaotu4");
	if(random(2))
		add_npc("heimuya_jiaotu4");

	add_door("黑木崖顶通道3层", "黑木崖顶通道3层", "黑木崖顶通道4层");
	add_door("黑木崖顶通道5层", "黑木崖顶通道5层", "黑木崖顶通道4层");


	set("long", "这里是通向黑木崖顶的一层通道，通道两旁站着几个日月神教的教徒，从他们的神色看来武功好象不错。");
    
};

int valid_leave(CChar * me, const char * dir)
{
	if(userp(me))
	{
		if(!me->query_temp("ry/renwu4_1"))
		{
			me->move(load_room("佛山北帝庙"));
			return 0;
		}
		CContainer * ShouWei=present("jiao tu");
		if(ShouWei)
		{
			char msg[255];
			CFightRoom * obj;
			CContainer * env = me->environment();
			obj = (CFightRoom *)load_item("fight_room");		
			
			obj->set("room_locked", FIGHT_LOCKED);
			obj->set_name(snprintf(msg, 255,"%s的战斗", ShouWei->name(1)),"fight_room");		
			obj->move(env);
			
			me->move(obj);
			obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
			
			ShouWei->move(obj);
			obj->Join_Team((CChar * )ShouWei, CFightRoom::FIGHT_TEAM_A);
			obj->Begin_Fight(0);
			return notify_fail(" ");
		}
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp