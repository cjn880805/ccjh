//xiaodao.h

//Sample for room: 黑木崖林间小道
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_xiaodao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黑木崖林间小道");

       add_npc("pub_menmian");         //add by zdn 2001-07-14


	add_door("黑木崖乱石坡", "黑木崖乱石坡", "黑木崖林间小道");
	add_door("黑木崖山谷", "黑木崖山谷", "黑木崖林间小道");
	add_door("黑木崖白虎堂大厅", "黑木崖白虎堂大厅", "黑木崖林间小道");

};


ROOM_END;
