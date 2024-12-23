//cangshanlu1.h

//Sample for room: 苍山山路
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiNorth_cangshanlu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "苍山山路");

	//add npcs into the room
	add_npc("pub_lieren");
	
	add_door("大理城苍山中部", "大理城苍山中部", "大理城苍山山路");
	add_door("大理城河上", "大理城河上", "大理城苍山山路");

	set("long", "此处正当河边，两侧山壁几乎是直上直下，面前是一条大河自北滔滔而来，在此折向东咆哮而去，河水奔腾汹涌，拍击河岸，发出一阵阵骇人的轰响。这里恰缝河湾，河床较窄，河谷上并无桥梁，只有三根粗藤条横跨两岸，这端绑在一棵大树上，似可攀援而过。" );

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
