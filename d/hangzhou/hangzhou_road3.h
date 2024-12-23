//road3.h

//Sample for room: 杭州青石大道3
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州青石大道3");
	
	add_npc("pub_jianke");         //add by zdn 2001-07-14
	add_npc("pub_zhangxunqi"); 

	add_door("杭州黄泥岭", "杭州黄泥岭", "杭州青石大道3");
	add_door("杭州洪春桥", "杭州洪春桥", "杭州青石大道3");
	add_door("杭州青石大道2", "杭州青石大道2", "杭州青石大道3");

	set("long","大道两边遍植青松，满目苍翠，偃盖如雪。被称为“九里雪松”。东北边是洪春桥。再向西南便到了灵隐寺。南边是一条土路。" );

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
