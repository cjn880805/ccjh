//shuiledong.h

//Sample for room: 杭州水乐洞
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shuiledong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州水乐洞");
	
	add_npc("pub_playboy");
	add_npc("pub_girl1");                  //add by zdn 2001-07-14

	add_door("杭州烟霞洞", "杭州烟霞洞", "杭州水乐洞");
	add_door("杭州满觉陇", "杭州满觉陇", "杭州水乐洞");

	set("long","水乐洞有两个洞口，洞的左口有股山泉从石缝中涌出。泉水声如金石，和谐悦耳。旁有“天然琴声”，“听无弦琴”等石刻字句。洞内两壁有很多钟乳石。往东是下山的路，西上便到了烟霞洞。" );
    
    set("resource/water", 1);

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
