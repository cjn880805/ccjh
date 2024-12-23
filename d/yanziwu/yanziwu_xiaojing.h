//xiaojing.h

//Sample for room: 燕子坞小径
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_xiaojing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞小径");
	
	add_npc("pub_lady3");      //add by zdn 2001-07-16

	add_door("燕子坞晓寒厅", "燕子坞晓寒厅", "燕子坞小径");
	add_door("燕子坞听雨居", "燕子坞听雨居", "燕子坞小径");

    set("long", "这是个一条湖边的小径，西面就是一座小桥。周围湖光影天，你不禁深吸了一口醉人的空气，陶醉于山水中。" );
    
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