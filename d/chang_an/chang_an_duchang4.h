//duchang4.h

//Sample for room: 长安赛龟房
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_duchang4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "长安赛龟房");

	add_npc("pub_shinu1");   //zdn 2001-07-12 add

	add_door("长安乐坊二楼大厅", "长安乐坊二楼大厅", "长安赛龟房");

	set("long", "一排紫色的镂空檀香靠背椅沿着屋子四周放了一圈，坐着聚精会神的客人。中间是一雕花石座，上面放着一个长长的紫檀龟台。一位扎着青鬏的龟童正围着龟台转来转去。龟房南面的墙上挂着牌子(paizi)。 " );
	set("light_up",  1);
	set("no_fight",  1);
	set("no_magic",  1);

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
CHANGAN_END;
