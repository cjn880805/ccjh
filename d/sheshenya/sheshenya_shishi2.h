//shishi2.h

//Sample for room: 石室2
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRSheShenYa_shishi2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "舍身崖石室2");


	add_door("舍身崖石洞", "舍身崖石洞", "舍身崖石室2");
	//add_door("逍遥林工匠屋", "逍遥林工匠屋", "舍身崖石室2");

	set("long","这是一个地下的秘密石室，四面可以感觉得到的只有强烈的杀气，以及处身地底的一些难闻的气味。在微弱的灯光下，你竟然看到有个人站着那里。继续往下好象还有路。");

/*****************************************************
	set("exits", ([
		"up" : __DIR__"fangjian2",
		"down" : __DIR__"shishi5",
	]));
	set("objects",([
		__DIR__"npc/qingyun" : 1,
	]));
*****************************************************/
};

void init(CChar *me)
{
	if(userp(me))
	{
		remove_call_out(do_out);
		call_out(do_out, 10, me->object_id());
	}
}

static void do_out(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob->Present(param1);
	if(! me) return;

	tell_object(me, "一股寒气扑面而来，你仔细观察一下，似乎前方的大石可以推动！");
}

//推开门进入逍遥林
int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(strcmp(comm, "push") == 0)
	{
		message_vision("墙壁突然翻转过来，$N转眼到了山洞外。", me);
		me->move(load_room("逍遥林工匠屋"));
		return 1;
	}

	return 0;
}

ROOM_END;
