//duchang3.h

//Sample for room: 长安斗鸡房
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_duchang3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "长安斗鸡房");

	//add npcs into the room
	//add_npc("jixian");
	
	add_door("长安乐坊二楼大厅", "长安乐坊二楼大厅", "长安斗鸡房");

	set("long", " 斗鸡房里一左一右放着两个青竹鸡笼，一个鸡笼里关着一群红冠鸡，另一个鸡笼里关着一群绿尾鸡。屋子正中是七尺见方的斗鸡场，由一圈低低的青玉栏杆围成。一位白髯鸡仙正在张罗着斗鸡。在他的后面墙上有一个牌子(paizi)。" );
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
