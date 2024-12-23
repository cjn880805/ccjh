//dahai.h

//Sample for room: 台湾大海
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRTaiWan_dahai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "台湾大海");

	set("monster_chance", 20);

	add_door("台湾鸡笼港", "台湾鸡笼港", "台湾大海");
	add_door("台湾打狗港", "台湾打狗港", "台湾大海");
	add_door("澎湖岛", "澎湖岛", "台湾大海");

	set("long", "你正处在茫茫大海之中。你极目远望，只见海天一线，周围连个黑点都没有。耳边只有海浪的拍打声。" );
	
	
/*****************************************************

********************************************/
};


ROOM_END;
