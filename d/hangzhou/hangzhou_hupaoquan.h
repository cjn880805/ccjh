//hupaoquan.h

//Sample for room: 杭州虎跑泉
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_hupaoquan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州虎跑泉");
	
	add_npc("pub_playboy");       // add by zdn 2001-07-14


	add_door("杭州青石大道17", "杭州青石大道17", "杭州虎跑泉");

	set("long"," 只见泉水从沙岩中渗流而出，清澈见底。相传有位名叫性空的和尚深爱此山风景灵秀，便住了下来。後因水源奇缺，准备迁走。一夜，梦神告诉他说“南岳衡山童子泉，当遣二虎移来。”第二天，果然看见两只老虎跑地作穴，涌出泉水，所以定名为“虎跑泉”");

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
