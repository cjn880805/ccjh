//yuetai.h

//Sample for room: 月台
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_yuetai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "月台");
	
	add_npc("songshan_tang");         //add by zdn 2001-07-20


	add_door("嵩山法王寺", "嵩山法王寺", "嵩山月台");

	set("long", "这里是法王寺的月台。从月台东望，太室山峦高耸入云，寺东有双峰插云，中间阙如。因名 '嵩门' 。中秋佳节，明月自峰中升起，正当嵩门之中，银光洒满山谷，这就是登封八景之一的 '嵩门待月' 。    瀑布一侧有一小小芦岩寺，瀑布斜过就是胜观峰。瀑布之侧有路可上。" );

/*****************************************************
	set("exits", ([
		"east" : __DIR__"fawangsi",
	]));
	set("objects", ([
		__DIR__"npc/fei" : 1,
	]));
********************************************/
};


ROOM_END;
