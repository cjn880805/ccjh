//yuhuangsd.h

//Sample for room: 杭州玉皇山顶
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_yuhuangsd);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州玉皇山顶");
	
	add_npc("pub_youke");      // add by zdn 2001-07-14


	add_door("杭州山路6", "杭州山路6", "杭州玉皇山顶");
	add_door("杭州山路7", "杭州山路7", "杭州玉皇山顶");

	set("long"," 登上玉皇山，俯瞰山下，可以看到“八卦田”。据说这是皇帝祭先农时亲耕的籍田。山顶有福星观，建於唐朝。廊宇旁有天一池和白石井，并建有望湖亭。东西两边各有一条下山的路。");

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
