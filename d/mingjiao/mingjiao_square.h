//square.h
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_square);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "明教广场");
	
	add_npc("mingjiao_shuobude");
	add_npc("mingjiao_zhangzhong");
	add_npc("mingjiao_pengyingyu");
	add_npc("mingjiao_zhoudian");
	add_npc("pub_xiangke");

	add_door("明教天微堂", "明教天微堂", "明教广场");
	add_door("明教饭堂", "明教饭堂", "明教广场");
	add_door("明教刑堂", "明教刑堂", "明教广场");
	add_door("明教大殿", "明教大殿", "明教广场");

	set("long", "你走进了明教总舵广场，却发现这里人声鼎沸，五散人群聚于此，看来有要事发生了。来往教众匆匆忙忙。广场左首是教众饭堂；右首就是教众闻之变色的刑堂。向上走就是光明顶明教总舵了。");
    
	set("valid_startroom", 1);
/*****************************************************
        set("exits", ([
                "west"    : __DIR__"fangtang",
                "northup" : __DIR__"qiandian",
                "east"    : __DIR__"xingtang",
                "south"   : __DIR__"tianweitang",
        ]));
        set("objects",([
             __DIR__"npc/shuobude":1,
             __DIR__"npc/zhangzhong":1,
             __DIR__"npc/pengyingyu":1,
             __DIR__"npc/zhoudian":1,
        ]));
        
        set("outdoors", "mingjiao");
********************************************/

};
/*
int valid_leave(object me, string dir)
{
        mapping mypar;
        me = this_player();
        mypar=(mapping)me->query("party");
        if ((!mypar || mypar["party_name"]!=HIG "明教" NOR) &&
            (dir!="south") &&
            ((objectp(present("peng yinyu", environment(me)))) ||
             (objectp(present("zhang zhong", environment(me)))) ||
             (objectp(present("shuo bude", environment(me)))) ||
             (objectp(present("zhou dian", environment(me))))))
         return notify_fail("明教五散人拦住你说：此处乃明教重地，请止步。\n");
        return ::valid_leave(me, dir);
}*/



ROOM_END;




