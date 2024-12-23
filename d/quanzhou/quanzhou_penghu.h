//penghu.h

//Sample for room: 澎湖岛
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_penghu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "澎湖岛");

	set("resident", "澎湖");

	//add npcs into the room
	add_npc("pub_qinbing");/////////////////////////
	add_npc("lj_hajuba");

	add_door("泉州海港", "泉州海港", "泉州澎湖岛");
	add_door("台湾鸡笼港", "台湾鸡笼港", "泉州澎湖岛");
	add_door("台湾打狗港", "台湾打狗港", "泉州澎湖岛");

	
/*****************************************************
	set("item_desc", ([
                "chuan" : "一条大海船。出远海没这样的船可不行。\n",
                "zhou"  : "一条水军战舟，前往台湾，还得靠它。\n",
	]));
	set("objects", ([
		__DIR__"npc/liu": 1,
		"/d/city/npc/bing" : 4,
	]));
********************************************/
};


RESIDENT_END;
