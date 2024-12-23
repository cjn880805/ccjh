//xiaolu1.h

//Sample for room: 白驼山小路1
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_xiaolu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山小路1");
	
	set("monster_chance", 1);

	add_door("白驼山坟地", "白驼山坟地", "白驼山小路1");
	add_door("白驼山东街", "白驼山东街", "白驼山小路1");
	add_door("白驼山小路2", "白驼山小路2", "白驼山小路1");

	set("long", "这里是一条上山的小路。");
    
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
