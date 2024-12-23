//gushan.h

//Sample for room: 杭州孤山
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_gushan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州孤山");
	
	add_npc("pub_poorman");                   // add by zdn 2001-07-14
	add_npc("pub_zaochunv");

	add_door("杭州西泠桥", "杭州西泠桥", "杭州孤山");
	add_door("杭州放鹤亭", "杭州放鹤亭", "杭州孤山");
	add_door("杭州平湖秋月", "杭州平湖秋月", "杭州孤山");
	add_door("杭州孤山平台", "杭州孤山平台", "杭州孤山");
	add_door("梅庄孤山石级", "梅庄孤山石级", "杭州孤山");

	set("long"," 通过林荫道向前，迎面石壁上刻有“孤山”两个丹红大字。朝南拾级登山便是平台。东北边便是发鹤亭。东南边则是平湖秋月。西北边通往西泠桥。");
    

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
