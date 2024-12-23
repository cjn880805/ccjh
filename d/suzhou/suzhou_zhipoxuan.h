//zhipoxuan.h

//Sample for room: 揖峰指柏轩
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_zhipoxuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "揖峰指柏轩");
	
	add_npc("pub_lady3");       //add by zdn 2001-07-16


	add_door("苏州狮子林", "苏州狮子林", "苏州揖峰指柏轩");

	
	set("long", "这里曾是为园主接待宾客和亲友的地方，有时也作为演戏说书或写诗做画之处。轩名取朱熹“前揖庐山，一峰独绣”和高启的“笑指庭前柏”句诗意。轩内摆设古香古色。凭轩眺望，满目石峰嶙峋，古柏虬枝盘绕，旧有桃源“十八景”之称。" );
	
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
