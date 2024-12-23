//ximen.h

//Sample for room: 白驼山西门
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_ximen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山西门");

	//add npcs into the room
	add_npc("pub_menwei");
	add_npc("zm_btshan");

	add_door("白驼山长廊", "白驼山长廊", "白驼山西门");
	add_door("白驼山草丛1", "白驼山草丛1", "白驼山西门");

	set("long", "这是个山庄的西门。拱月形的竹门分外雅致，门上挂着一块竹牌(pai)。西门外面杂草丛生。");

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
