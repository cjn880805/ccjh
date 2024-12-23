//yuhuangshan.h

//Sample for room: 杭州玉皇山
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_yuhuangshan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州玉皇山");
	
	add_npc("pub_punk");           // add by zdn 2001-07-14


	add_door("杭州青石大道17", "杭州青石大道17", "杭州玉皇山");
	add_door("杭州山路6", "杭州山路6", "杭州玉皇山");

	set("long"," 山脚有一座小亭，德意亭。不少游客登山前或下山後都在此小歇。山路蜿延往东向上。西边有一条大路。");
    

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
