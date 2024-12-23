//fengchan.h

//Sample for room: 嵩山封禅台
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRSongShan_fengchan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "嵩山封禅台");

	add_door("嵩山峻极禅院山门", "嵩山峻极禅院山门", "嵩山封禅台");

};


ROOM_END;
