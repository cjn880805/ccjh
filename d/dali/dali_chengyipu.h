//chengyipu.h

//Sample for room: 薛记成衣铺
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_chengyipu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "薛记成衣铺");

	add_npc("pub_xueboss");		//add by lanwood 2001-03-18

	add_door("大理城东", "大理城东", "大理城薛记成衣铺");

	set("long", "这是一家老字号的估衣庄，里面摆满了各式各样的衣物。绸、绢、丝、布、皮袄、大红斗蓬、葱黄绫子棉裙、水绿色棉袄，秋香色团花。。。不一而足。" );

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
