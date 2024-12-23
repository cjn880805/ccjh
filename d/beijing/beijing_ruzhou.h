//ruzhou.h

//Sample for room: 汝州城
//coded by zwb
//data: 2000-12-1

ROOM_BEGIN(CRBeiJing_ruzhou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "汝州城");

	//add npcs into the room
	add_npc("pub_wujiang");
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("pub_ruzhousen");
	add_npc("pub_dongmengqin");
	
	add_door("北京大驿道9", "北京大驿道9", "北京汝州城");
	add_door("嵩山太室阙", "嵩山太室阙", "北京汝州城");
	add_door("南阳城", "南阳城", "北京汝州城");

	set("long", "汝州城是本府的大城，立来是兵家必争之地。故州治在此驻扎重兵，盘查南来北往的行人，并负责翦灭附近山上的草寇。城内一队队官兵来来去去，一派森严气象。再折向西，就是五岳之一的嵩山。" );
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
