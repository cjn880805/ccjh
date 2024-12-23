//majiu.h

//Sample for room: 马厩
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_majiu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "马厩");

	//add npcs into the room
	add_npc("animal_zaohongma");/////////////////////////
//	add_npc("animal_huangbiaoma");
//	add_npc("animal_ziliuma");
	add_npc("pub_mafu");
				
	//add exits for room
	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("灵州车马店", "灵州车马店", "灵州马厩");

	set("long", "这是车马店边上的马厩，常年供应新鲜草料。据说此地民风淳朴，客人只要住店，马夫们就会把马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干乾净净。一直伺候到客人离店上路。马厩中堆放著几堆草料，正中有一口泔槽。马厩雨檐下的烂木柱上钉着一块破木牌(paizi)。");  
	set("no_fight", "1");
	set("no_beg", "1");
	
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
