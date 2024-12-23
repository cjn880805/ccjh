//tianwangdian.h

//Sample for room: 杭州天王殿
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_tianwangdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州天王殿");
	
	add_npc("pub_youke");       /// add by zdn 2001-07-14


	add_door("杭州灵隐寺", "杭州灵隐寺", "杭州天王殿");
	add_door("杭州大雄宝殿1", "杭州大雄宝殿1", "杭州天王殿");

	set("long","走进大殿，只见正面坐着袒胸露腹的弭勒佛，两旁是四大天王，後面是神态威严的韦驮菩萨。天王殿後面便是大雄宝殿。" );
	

/*****************************************************
        set("exits", ([
                "out"       : __DIR__"lingyinsi",
                "north"     : __DIR__"dxbaodian1",
        ]));
 ********************************************/

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
