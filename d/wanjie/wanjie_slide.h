//slide.h

//Sample for room: 山坡
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_slide);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "山坡");
	
	add_npc("wanjie_gan");        //add by zdn 2001-07-20



	add_door("万劫谷澜沧江畔", "万劫谷澜沧江畔", "万劫谷山坡");
	add_door("万劫谷山路1", "万劫谷山路1", "万劫谷山坡");

	set("long","山坡之上张着一些不知名的杂草，以及三三两两分布其间的灌木丛，这里很少有大树，几朵野花在路边悄悄开放，偶尔有几只蝴蝶飞来飞去。");
    
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
