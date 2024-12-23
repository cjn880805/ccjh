//xiwuchang.h

//Sample for room: 福威镖局习武场
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_xiwuchang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "福威镖局习武场");

	add_npc("fuzhou_cui");     //add by zdn 2001-07-20
	add_npc("fuzhou_shi");      

	add_door("福威镖局", "福州福威镖局", "福州福威镖局习武场");
	add_door("福威镖局正厅", "福州福威镖局正厅", "福州福威镖局习武场");

	set("long", "...哈...哈...哈哈...一阵充满洋刚之气的喊声从习武场传来。" );

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
