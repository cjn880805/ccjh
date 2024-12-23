//shulin1.h

//Sample for room: 白驼山树林1
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_shulin1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山树林1");

	set("monster_chance", 1);

	add_door("白驼山树林", "白驼山树林", "白驼山树林1");
	add_door("白驼山草莓地", "白驼山草莓地", "白驼山树林1");

	set("long", "这里是一片茂密的树林(wood)。旁边立着一张木牌(pai)。");

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
