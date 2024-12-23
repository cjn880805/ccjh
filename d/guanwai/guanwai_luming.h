//luming.h

//Sample for room: 鹿鸣峰
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_luming);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "鹿鸣峰");

	set("monster_chance", 5);
	//add npcs into the room
//	add_npc("animal_buck");/////////////////////////
//	add_npc("animal_doe");
	add_npc("pub_diaoyu");

	add_door("关外龙门峰", "关外龙门峰", "关外鹿鸣峰");
	add_door("关外白云峰", "关外白云峰", "关外鹿鸣峰");

    set("long","龙门峰西侧就是鹿鸣峰。鹿鸣峰又称芝盘峰，因峰上有一草甸子，形圆如盖，有热气从地下冒出，每到严冬，其它峰均积雪甚厚，唯鹿鸣峰依然植物茂盛，且盛产芝草，鹿多居之。常有鹤、雀、雕、燕飞落其上，有“鹿鸣翠谷，雕飞芝盖”之称。" );
    

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
