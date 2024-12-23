//shuyuan.h

//Sample for room: 凤池书院
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRhangzhou_shuyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "凤池书院");
	
	add_npc("pub_shutong");    // add by zdn 2001-07-14


	add_door("杭州青石大道12", "杭州青石大道12", "杭州凤池书院");

	set("long","书院正中有一匾“凤池书院”。书院里坐着两位老者，他们正在吟诗作对。他们身旁的桌上铺着宣纸和笔墨。" );

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
