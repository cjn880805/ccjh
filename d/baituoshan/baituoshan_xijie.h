//xijie.h

//Sample for room: 白驼山西街
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_xijie);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山西街");

	//add npcs into the room
	add_npc("pub_man");
	add_npc("pub_snaker");

				

	add_door("白驼山东街", "白驼山东街", "白驼山西街");
	add_door("白驼山酒店", "白驼山酒店", "白驼山西街");
	add_door("白驼山小桥", "白驼山小桥", "白驼山西街");

	set("long", "这里是小镇的西街。北边有个酒店，门前树立着高高的旗杆，一块青布幌子迎风飘扬，上面印着朱红色的大字‘酒’");

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
