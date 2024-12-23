//ztpo1.h

//Sample for room:  峨嵋钻天坡1
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_ztpo1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋钻天坡1");

	add_npc("pub_youke");      // add by zdn 2001-07-14
	
	add_door("峨嵋钻天坡2", "峨嵋钻天坡2", "峨嵋钻天坡1");
	add_door("峨嵋莲花石", "峨嵋莲花石", "峨嵋钻天坡1");

	set("long","莲花石与洗象池之间，道路陡绝，石栈若齿，直上蓝天，石蹬达一千三百多级，是在陡峭山壁上开凿出来的坡道。人行其上，前后顶踵相接，一如登天。这段路叫「鹁鸽钻天」，这段陡坡也因此而叫「钻天坡」。这里西上坡顶便到洗象池，东下可达莲花石。");

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
