//luorilin1.h

//Sample for room: 灵州落日林1
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_luorilin1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵州落日林1");
	
	add_npc("monster_8k");        //add by zdn 2001-07-14


	add_door("灵州东", "灵州东", "灵州落日林1");
	add_door("灵州林中大路1", "灵州林中大路1", "灵州落日林1");

};


ROOM_END;
