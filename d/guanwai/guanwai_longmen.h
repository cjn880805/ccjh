//longmen.h

//Sample for room: 龙门峰
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_longmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "龙门峰");
	
	add_npc("pub_old");     // add by zdn 2001-07-13

	set("monster_chance", 50);

	add_door("关外达门", "关外达门", "关外龙门峰");
	add_door("关外鹿鸣峰", "关外鹿鸣峰", "关外龙门峰");
	add_door("关外天豁峰", "关外天豁峰", "关外龙门峰");
	add_door("关外白头山天池1", "关外白头山天池1", "关外龙门峰");

    set("long","龙门峰在乘槎河西岸，因状如门形，故名龙门。崇崖峻壁，形态奇特，宛如卧龙吸水，传说大禹治水曾到此峰，旁有蝌蚪形石柱。" );
    

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
