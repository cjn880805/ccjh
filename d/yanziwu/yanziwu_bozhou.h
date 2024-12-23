//bozhou.h

//Sample for room: 燕子坞泊舟坞
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_bozhou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞泊舟坞");

	add_door("燕子坞太湖", "燕子坞太湖", "燕子坞泊舟坞");
	add_door("燕子坞品笛庭", "燕子坞品笛庭", "燕子坞泊舟坞");

    set("long", "一片芦苇，茭白丛中现出一座船坞，大小船只依次排开。菱花荷叶丛中条条水道四通八达，由此可乘船离开燕子坞。湖面正系着一尾小舟(zhou)。" );
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