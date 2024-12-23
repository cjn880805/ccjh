//chuantang.h

//Sample for room: 燕子坞穿堂
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_chuantang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞穿堂");

	add_door("燕子坞梨香苑", "燕子坞梨香苑", "燕子坞穿堂");
	add_door("燕子坞翠霞堂", "燕子坞翠霞堂", "燕子坞穿堂");

    set("long", "不知是什么能工巧匠设计了这条穿堂，九曲回折，雕梁画栋。再望南就是后院了，向北则是一座大厅堂。" );
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