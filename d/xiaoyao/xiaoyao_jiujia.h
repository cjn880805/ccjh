//jiujia.h

//Sample for room: 酒家
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXiaoYao_jiujia);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "逍遥林酒家");

	add_npc("pub_xiaoer2");
	add_item("shaguan");
	add_item("ciwan");

	add_door("逍遥林小道3", "逍遥林小道3", "逍遥林酒家");

	set("long", "这里是树林中的一间小小的酒家，地方虽然不大，但是也有不少逍遥派的弟子光顾这里。你终于找到香味的来源了，看着可口的饭菜，你忍不住也想叫 (order)一份了。");
	
	set("ricewater", 5);

/*****************************************************
	set("exits",([
		"north" : __DIR__"xiaodao2",
	]));
********************************************/
};


ROOM_END;
