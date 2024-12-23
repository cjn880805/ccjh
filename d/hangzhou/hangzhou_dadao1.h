//dadao1.h

//Sample for room: 杭州沿湖大道1
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_dadao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州沿湖大道1");
	
	add_npc("pub_oldwoman");          // add by zdn 2001-07-14

	add_door("杭州郭庄", "杭州郭庄", "杭州沿湖大道1");
	add_door("杭州沿湖大道2", "杭州沿湖大道2", "杭州沿湖大道1");
	add_door("杭州青石大道5", "杭州青石大道5", "杭州沿湖大道1");

	set("long","一条宽敞的大道上却游人稀少。原来这里沿路住着的都是达官贵人。本来风景秀丽之处，却显的一片萧瑟。路的西边是一座庄园，大道向南北延伸。");

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
