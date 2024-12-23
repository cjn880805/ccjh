//hcazhengdian.h

//Sample for room:  峨嵋华藏庵正殿
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_hcazhengdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋华藏庵正殿");

	add_npc("pub_guest");
	add_npc("emei_xin");

	add_door("峨嵋华藏庵", "峨嵋华藏庵", "峨嵋华藏庵正殿");
	add_door("峨嵋华藏庵西侧殿", "峨嵋华藏庵西侧殿", "峨嵋华藏庵正殿");
	add_door("峨嵋华藏庵东侧殿", "峨嵋华藏庵东侧殿", "峨嵋华藏庵正殿");
	add_door("峨嵋华藏庵广场", "峨嵋华藏庵广场", "峨嵋华藏庵正殿");

	set("long","这里是峨嵋山金顶华藏庵的正殿。华藏庵规模宏大，殿内青砖铺地，中间有普贤菩萨像，两旁列有万佛。正前方放一红木供桌，陈列香烛，以供叩拜。自此左右各有一间侧殿，是接待香客的地方。南面是通往一个大广场，只有峨嵋弟子才能过去。");
    
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
