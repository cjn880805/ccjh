//caoguduo.h

//Sample for room: 谷草垛
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_caoguduo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "谷草垛");

	set("resident", "白河");
	
	add_npc("pub_nongfu2");      // add by zdn 2001-07-13

	set("monster_chance", 50);

	add_door("关外满天星", "关外满天星", "关外谷草垛");
	add_door("关外白河", "关外白河", "关外谷草垛");

	set("long","经过一番艰苦的跋涉，你的眼前出现了一片低矮的丘陵。远远看去象秋收后堆成的谷草垛，密密麻麻，数不清有多少个。翻过这片丘陵再向东行，就可进入长白大山了。东面的天边有一缕炊烟，看来似乎有人。" );
    

/*****************************************************
	set("exits", ([
		"northwest" : __DIR__"mantianxing",
		"east"      : __DIR__"baihe",
	]));
********************************************/
};


RESIDENT_END;
