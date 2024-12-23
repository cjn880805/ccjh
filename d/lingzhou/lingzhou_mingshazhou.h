//mingshazhou.h

//Sample for room: 灵州鸣沙洲
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_mingshazhou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵州鸣沙洲");
	
	add_npc("monster_28k");   //add by zdn 2001-07-14


	add_door("灵州青铜峡", "灵州青铜峡", "灵州鸣沙洲");
	add_door("灵州宣和堡", "灵州宣和堡", "灵州鸣沙洲");

};


ROOM_END;
