//shoushe.h

//Sample for room: 兽舍
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_shoushe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "兽舍");

	//add npcs into the room
//	add_npc("animal_fox");/////////////////////////
//	add_npc("animal_wolf2");
//	add_npc("animal_lion");


	add_door("白驼山兔苑", "白驼山兔苑", "白驼山兽舍");

	set("long", "这里是白驼山庄的兽舍。白驼山驭兽术天下知名，这里也豢养了各种猛兽，以供下山的白驼弟子使用。兽舍里猛兽长声嘶嚎，老远都听得见。尤其是夜晚听来，更有是撕心裂肺的惨烈。");  

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
