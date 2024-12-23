//yingxionglou.h

//Sample for room: 英雄楼
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRFoShan_yingxionglou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "英雄楼");

	//add npcs into the room
	add_npc("pub_fengqi");
	
	add_door("佛山", "佛山", "佛山英雄楼");
	add_door("佛山英雄楼二楼", "佛山英雄楼二楼", "佛山英雄楼");

	set("no_fight", 1);

	set("long", "酒楼里桌椅洁净。座中客人衣饰豪奢，十九是富商大贾。佛山地处交通要地，来这吃饭的人还真不少。 " );
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
