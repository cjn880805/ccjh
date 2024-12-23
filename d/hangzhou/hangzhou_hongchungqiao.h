//hongchungqiao.h

//Sample for room: 杭州洪春桥
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_hongchungqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州洪春桥");
	
	add_npc("pub_jianke");
	add_npc("pub_oldwoman");    //add by zdn 2001-07-14


	add_door("杭州青石大道4", "杭州青石大道4", "杭州洪春桥");
	add_door("杭州青石大道3", "杭州青石大道3", "杭州洪春桥");

	set("long","从这里可以看到西湖十景之一的双峰插云(scenery)。大道通向北边，再向西南是通往灵隐寺的路。" );
    

/*****************************************************
        set("exits", ([
            "southwest"     : __DIR__"road3",
            "north"         : __DIR__"road4",
        ]));
        set("item_desc", ([
        "scenery" : 
"双峰，南高峰在西湖之西南，北高峰在西湖之西北。南北遥遥相对，
只见宿雨初收，双峰隐现在轻风薄雾之中，或浓或淡，时有时无；雾
层飘移，卷舒断续，变幻无穹。\n",
        ]));
        set("outdoors", "hangzhou");
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
