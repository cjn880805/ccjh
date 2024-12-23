//haigang.h

//Sample for room: 海港
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_haigang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "海港");

	set("resident", "澎湖");

	//add npcs into the room
	add_npc("pub_boy");/////////////////////////
	add_npc("pub_girl");
	add_npc("pub_jinshisanniang");
	add_npc("mingjiao_changjinpeng");


	add_door("泉州", "泉州", "泉州海港");
	add_door("泉州澎湖岛", "泉州澎湖岛", "泉州海港");

	set("outdoors", "quanzhou");
/*****************************************************
	set("exits", ([
                "west" : __DIR__"zhongxin",
	]));
	set("item_desc", ([
                "chuan" : "一条大海船。出远海没这样的船可不行。\n",
	]));
	set("objects", ([
		__DIR__"npc/boy": 2,
		__DIR__"npc/girl": 1,
		"/d/mingjiao/npc/changjinpeng": 1,
	]));
//	

********************************************/
};


RESIDENT_END;
