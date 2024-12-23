//majiu.h

//Sample for room: 马厩
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuanWai_majiu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "马厩");


	//add npcs into the room
//	add_npc("animal_zaohongma");/////////////////////////
//	add_npc("animal_ziliuma");
//	add_npc("animal_huangbiaoma");
//	add_npc("pub_mafu");


	add_door("关外宁远", "关外宁远", "关外宁远马厩");

    set("long","这是关外的马厩，关外苦寒之地，颇乏新鲜草料。但东北大汉惯能吃苦，马夫们会把马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干乾净净，一直伺候到客人上路。马厩雪披下的木柱上钉着一块破木牌(paizi)。" );
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
