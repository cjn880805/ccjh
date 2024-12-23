//jisi.h

//Sample for room: 祭祀屋
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDaLisouth_jisi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "祭祀屋");

	//add npcs into the room
	add_npc("pub_jisi");
	
	add_door("大理城南议事堂", "大理城南议事堂", "大理城南祭祀屋");

	set("long", "此间乃竹楼顶层，是一间宽敞的大屋，正中一座祭台上十二白石围成一圈，当中立有一面竹牌，上绘本族的蛇神图画；圈内另有几面稍小的竹牌，上书族内祖先姓名尊号；祭台前香火贡品整齐放置，时有族人前来顶礼膜拜。" );

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
