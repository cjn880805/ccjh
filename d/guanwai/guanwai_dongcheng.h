//dongcheng.h

//Sample for room: 东城
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_dongcheng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "东城");

	set("resident", "关外宁远");

	set("monster_chance", 50);

	add_npc("pub_yangzong");      // add by zdn 2001-07-13 
	add_npc("guanwai_xiaoyuanshan");       //add by zdn 2001-07-20

	add_door("关外宁远", "关外宁远", "关外宁远东城");
	add_door("关外荒路1", "关外荒路1", "关外宁远东城");
	add_door("关外雪地1", "关外雪地1", "关外宁远东城");

    set("long","这里是用黄土铺就的街道，街上的行人不多，看起来很冷清。偶尔有几个身着异域服饰的行人走过，看起来是满族，鲜祖的居民。西面传来嘈杂的叫卖声。南面是一排黄泥垒成的土房，里面有嬉笑的声音。" );
	

/*****************************************************
	set("exits", ([
		"west"      : __DIR__"jishi",
		"south"     : __DIR__"tuyaoguan",
		"east"      : __DIR__"xuedi1",
		"northeast" : __DIR__"huandi1",
	]));
********************************************/
};


RESIDENT_END;
