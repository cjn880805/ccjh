//zhengting.h

//Sample for room: 古墓正厅
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_zhengting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "古墓正厅");

	//add npcs into the room
	add_npc("gumu_longnv");
	
	add_door("古墓小厅", "古墓小厅", "古墓正厅");
	add_door("古墓后厅", "古墓后厅", "古墓正厅");
	add_door("古墓练功室", "古墓练功室", "古墓正厅");

    set("long","这里是古墓的正厅，本来应该停放灵柩棺木之类的东西，却不知道被人般到哪里去了。厅正中端坐着一位白衣少女，厅角上摆放着一张石头做成的大床(chuang)，厅中横系着一条绳子，不知道做什么用的，除此之外，别无摆设。" );
	
	set("valid_startroom",1);
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
