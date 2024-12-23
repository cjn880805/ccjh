//storeroom.h

//Sample for room: 储藏室
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_storeroom);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "储藏室");


	add_door("白驼山院子", "白驼山院子", "白驼山储藏室");

	set("long", "这是一个储藏室，四周密不透风。只有关闭着的大门(door)。");  
    
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
