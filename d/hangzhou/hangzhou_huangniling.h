//huangniling.h

//Sample for room: 杭州黄泥岭
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_huangniling);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州黄泥岭");
	
	add_npc("pub_jianke");
	add_npc("pub_poorman");                   // add by zdn 2001-07-14

	add_door("杭州青石大道3", "杭州青石大道3", "杭州黄泥岭");
	add_door("杭州茅家埠", "杭州茅家埠", "杭州黄泥岭");

	set("long","一条黄土路弯弯曲曲，四周非常的安静。偶而才看见些游人匆匆而过。南北分别是下山的路。" );

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
