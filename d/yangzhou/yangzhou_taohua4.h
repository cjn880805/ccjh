//taohua4.h

//Sample for room: 桃花村
//coded by zwb
//data: 2000-12-1

RESIDENT_BEGIN(CRYangZhou_taohua4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "桃花村");

	set("resident", "桃花村");

	//add npcs into the room
	add_npc("pub_cunzhang");/////////////////////////
	add_npc("animal_diablo2");			
	
	add_door("扬州桃花谷", "扬州桃花谷", "扬州桃花村");
	add_door("扬州桃花坪", "扬州桃花坪", "扬州桃花村");

	set("long", "进了桃花谷便是桃花村。世外的感受，让你陶醉这山野的风、山间的春泥味、山村的直朴、村民的宽容、山里的桃花、桃花溪的少女，让你不会再去想尘世的名利、江湖的血腥、人心的险恶。你尽可忘了一切，来凝望桃花村碧蓝的瓦、彤红的墙。 " );

/*****************************************************
	set("objects", ([
		__DIR__"npc/cunzhang" : 1,
	]));
	set("exits", ([
		"southdown" : __DIR__"taohua3",
		"north"     : __DIR__"taohua5",
	]));
********************************************/
};


RESIDENT_END;
