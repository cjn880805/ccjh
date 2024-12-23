//yangzhou_dongnan.h

//Sample for room:  扬州东南
//coded by Fisho
//data: 2000-11-2


RESIDENT_BEGIN(CRyangzhou_dongnan);



virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州东南");

	set("resident", "扬州");

	//add npcs into the room
	add_npc("pub_boy");
	add_npc("pub_bing");
	add_npc("guiyun_hanxiaoyin");
	add_npc("guiyun_zhucong");               //zdd by zdn 2001-07-20


	add_door("扬州当铺", "扬州当铺", "扬州东南");
	add_door("扬州丽春院", "扬州丽春院", "扬州东南");

	add_door("扬州西南", "扬州西南", "扬州东南");
	add_door("扬州东门", "扬州东门", "扬州东南");
	add_door("扬州东北", "扬州东北", "扬州东南");

};


RESIDENT_END;
