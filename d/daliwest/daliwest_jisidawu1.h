//jisidawu1.h

//Sample for room: 祭祀大屋
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_jisidawu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "祭祀大屋");

	//add npcs into the room
	add_npc("pub_laojisi");
	
	add_door("大理城乌夷民居", "大理城乌夷民居", "大理城祭祀大屋");

	set("long", "这是乌撒部的祭祀大屋，颇为宽敞。屋子正中一张竹台，台上摆放着一排竹制牌位，上书乌蛮族祖先之名。牌位后的墙上挂有大幅兽皮，上绘龙形花纹，似是该族的图腾。一位老祭司常年守在祭台前，负责全族的祭司活动。" );

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
