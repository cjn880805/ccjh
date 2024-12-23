//suti4.h

//Sample for room: 杭州苏堤4
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_suti4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州苏堤4");

	//add npcs into the room
	add_npc("wudang_liyuanzhi");

	add_door("杭州苏堤3", "杭州苏堤3", "杭州苏堤4");
	add_door("杭州苏堤5", "杭州苏堤5", "杭州苏堤4");

	set("long"," 春晓，漫步林荫道上，烟柳笼纱，雀鸟欢鸣，一片生机。苏堤春晓被列为西湖十景之首，果然名不虚传。北边是压堤桥，南面是望山桥。东面一片梅林，林后似乎有座院落，但看不真切。");

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
