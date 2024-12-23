//qianzhuang.h

//Sample for room: 钱庄
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRBeiJing_qianzhuang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "钱庄");

	add_npc("pub_zaochongzha");
	add_door("北京东南", "北京东南", "北京钱庄");

	set("long", "这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。它发行的银票信誉非常好，通行全国。不管你走到哪里，在任何一个本庄分店都可以任意存取。墙上挂着一个牌子(paizi)。" );
	
	set("no_fight", 1);
	set("no_beg", 1);
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
