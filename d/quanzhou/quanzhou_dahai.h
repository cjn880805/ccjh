//dahai.h

//Sample for room: 泉州大海
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_dahai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泉州大海");
	add_item("baiguo");

	set("resident", "澎湖");


	add_door("泉州海港", "泉州海港", "泉州大海");
	add_door("泉州澎湖岛", "泉州澎湖岛", "泉州大海");

	set("long", "你正处在茫茫大海之中。你极目远望，只见海天一线，周围连个黑点都没有。耳边只有海浪的拍打声。" );
	
	
/*****************************************************

********************************************/
};


RESIDENT_END;
