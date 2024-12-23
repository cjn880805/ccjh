//quyuanbei.h

//Sample for room: 杭州曲院风荷
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_quyuanbei);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州曲院风荷");
	
	add_npc("pub_youke");          //add by zdn 2001-07-14
	add_npc("pub_gongzijun");

	add_door("杭州苏堤2", "杭州苏堤2", "杭州曲院风荷");

	set("long"," 跨过小拱桥，迎面有一亭院，旁边立着石碑，上题“曲院风荷。”往东是回苏堤。");

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
