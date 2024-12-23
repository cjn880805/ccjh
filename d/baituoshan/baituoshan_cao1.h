//cao1.h

//Sample for room: 白驼山草丛1
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_cao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山草丛1");

	set("monster_chance", 1);

	//add npcs into the room
	add_npc("animal_jinshe");/////////////////////////
	add_npc("animal_snake");

	add_door("白驼山西门", "白驼山西门", "白驼山草丛1");
	add_door("白驼山草丛2", "白驼山草丛2", "白驼山草丛1");

	set("long", "这里是乱草丛。东边是扇拱月形小敞门。其余三面都是齐腰高的蒿草，常有蛇出没");

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
