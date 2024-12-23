//zhulin.h

//Sample for room: 白驼山竹林
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_zhulin);

virtual void create()			//Call it when Room Create
{
	set_name( "白驼山竹林");

	add_npc("animal_qingshe");/////////////////////////
	add_npc("animal_mangshe");


	add_door("白驼山草丛2", "白驼山草丛2", "白驼山竹林");
	add_door("白驼山岩洞", "白驼山岩洞", "白驼山竹林");

	set("long", "这里是青竹林，常有蛇出没。南边是蒿草丛。北边有一个大岩洞。");

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
