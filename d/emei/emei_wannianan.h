//wannianan.h

//Sample for room:  峨嵋万年庵
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_wannianan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋万年庵");

	add_npc("pub_nigu1");          //add by zdn 2001-07-14
				
	add_door("峨嵋白龙洞", "峨嵋白龙洞", "峨嵋万年庵");
	add_door("峨嵋十二盘1", "峨嵋十二盘1", "峨嵋万年庵");

	set("long","万年庵建在一座突起的山峰上，周围古木森森，清泉淙淙，闲步无坎，吟游无坷，景色非常迷人。由此西上过十二盘可达华严顶，南下至白龙洞。");
    

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
