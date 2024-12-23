//yunufeng.h

//Sample for room:  峨嵋玉女峰
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_yunufeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋玉女峰");

	add_npc("emei_fang");
		
	add_door("峨嵋归云阁", "峨嵋归云阁", "峨嵋玉女峰");

	set("long","这是归云阁边的玉女峰，峰顶有一个四尺见方的小池，深亦四尺，四季不枯，传为天女沐浴之器。古时州刺史冯楫，曾在此结茅而居，发奋诵读《华严经》，不食人间烟火，于是玉女下凡，为他馈赠食物。");

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
