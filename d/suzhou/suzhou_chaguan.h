//chaguan.h

//Sample for room: 茶馆
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_chaguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "茶馆");

	//add npcs into the room
	add_npc("pub_lady1");/////////////////////////

	add_door("苏州南", "苏州南", "苏州茶馆");

	set("long", "你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几张八仙桌一字排开，坐满了客人，或高声谈笑，或交头接耳。几个店伙计在一旁伺候着客人们，在台后坐着一位老板娘，正在弹着算盘。" );
 	set("resource/water", 1);
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
