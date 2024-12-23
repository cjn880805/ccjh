//yipinzhang.h

//Sample for room: 一品堂帐房
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_yipinzhang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "一品堂帐房");
	
	add_npc("lingzhou_zhangfang");        //add by zdn 2001-07-20


	add_door("灵州一品堂大厅", "灵州一品堂大厅", "灵州一品堂帐房");

//	add_npc("pub_zhangfang");	//这里应该有个一品堂的帐房。lanwood
  
};


ROOM_END;
