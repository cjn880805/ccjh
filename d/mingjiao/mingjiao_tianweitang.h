//tianweitang.h



//Sample for room: 天微堂

//coded by zouwenbin

//data: 2000-11-16



ROOM_BEGIN(CRMingJiao_tianweitang);



virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "明教天微堂");

	add_npc("mingjiao_yinyewang");
	add_npc("mingjiao_yinwufu");
	add_npc("mingjiao_yinwushou");
	add_npc("mingjiao_yinwulu");
	add_npc("mingjiao_litianyuan");

	add_door("明教烈火旗大厅", "明教烈火旗大厅", "明教天微堂");
	add_door("明教广场", "明教广场", "明教天微堂");



	set("long", "这里就是明教的天微堂，堂主就是威名远波的殷野王。他是白眉鹰王的独子和教主张无忌的舅舅。堂内陈设鲜丽奢华，显然甚是兴旺，往来教众进进出出，看他们各执兵刃，似乎是守总舵的卫士。");
	
	set("xin_count", 1);


/*****************************************************
        set("exits", ([
                "east"      : __DIR__"tianshitang",
                "west"      : __DIR__"ziweitang",
                "southdown" : __DIR__"zhandao2",
              "north"     : __DIR__"square",
        ]));
        set("objects",([
             __DIR__"npc/yinyewang":1,
             __DIR__"npc/yinwufu":1,
        ]));
********************************************/

};
/*
int valid_leave(CChar * player, string dir)
{

        if ((player->querystr("party/party_name")!="明教") && (dir=="north") &&
            (objectp(present("yin yewang", environment(me)))))
        return notify_fail("殷野王拦住你说：此处乃明教重地，请止步。\n");
        return CRoom::valid_leave(me, dir);
}

*/

ROOM_END;
