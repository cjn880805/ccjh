//leidongping.h
//Sample for room:  峨嵋雷洞坪
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_leidongping);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋雷洞坪");
	add_npc("animal_dog");           // add by zdn 2001-07-14
	add_npc("pub_puchen");
	add_door("峨嵋凌云梯", "峨嵋凌云梯", "峨嵋雷洞坪");
	add_door("峨嵋八十四盘1", "峨嵋八十四盘1", "峨嵋雷洞坪");
//	add_door("峨嵋冷杉林1", "峨嵋冷杉林1", "峨嵋雷洞坪");

	set("long","雷洞坪一带，道路艰险骇人，路左是蔽日遮天的冷杉林，路右是深不见底的绝壁峡谷。这里长年云遮雾罩，空蒙黑暗。岩上建有雷神殿，旁边竖一铁碑。由此往上是「八十四盘」至接引殿，北下到洗象池。");

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
