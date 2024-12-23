//zuijing.h

//Sample for room: 燕子坞缀锦楼
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_zuijing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞缀锦楼");
	
	add_npc("murong_gongsun");        //add by zdn 2001-07-20

	add_door("燕子坞参合居", "燕子坞参合居", "燕子坞缀锦楼");
	add_door("燕子坞水云轩", "燕子坞水云轩", "燕子坞缀锦楼");

    set("long", "地面铺着大红地毯，房中布置得珠光宝气，各种珠宝，古玩摆放得琳琅满目，你看了颇为心动，很想顺手拿走几件，但又有些不敢。角落里有一架红木楼梯。" );
    
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
//last, register the room into ../server/RoomSetup.cpp