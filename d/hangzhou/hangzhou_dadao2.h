//dadao2.h

//Sample for room: 杭州沿湖大道2
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_dadao2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州沿湖大道2");
	
	add_npc("pub_xiaozei");           // add by zdn 2001-07-14
	add_npc("pub_jiangbiehe"); 

	add_door("杭州大路1", "杭州大路1", "杭州沿湖大道2");
	add_door("杭州沿湖大道1", "杭州沿湖大道1", "杭州沿湖大道2");

	set("long","一条宽敞的大道上却游人稀少。原来这里沿路住着的都是达官贵人。本来风景秀丽之处，却显的一片萧瑟。大道向西南和北延伸。");

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
