//xilingqiao.h

//Sample for room: 杭州西泠桥
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_xilingqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州西泠桥");
	
	add_npc("pub_girl1");        //add by zdn 2001-07-14


	add_door("杭州孤山", "杭州孤山", "杭州西泠桥");
	add_door("杭州青石大道7", "杭州青石大道7", "杭州西泠桥");

	set("long"," 西泠桥衔结孤山，跨过里西湖。桥的东南边是孤山。北边则是一条青石大道。");

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
