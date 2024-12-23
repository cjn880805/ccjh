//luwang.h

//Sample for room: 鲁望镇
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaLisouth_luwang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "鲁望镇");

	set("resident", "喜州");

	//add npcs into the room
	add_npc("pub_tshangfan");
	
	add_door("大理城水田", "大理城水田", "大理城鲁望镇");
	add_door("大理城大竹楼", "大理城大竹楼", "大理城鲁望镇");
	add_door("大理城妃丽湖畔", "大理城妃丽湖畔", "大理城鲁望镇");
	add_door("大理城榕树雨林", "大理城榕树雨林", "大理城鲁望镇");

	set("long", "这里是普麽部的鲁望镇，普麽部属台夷，领属还有附近的越州。这是一座建在山坡上的小镇，东面和北面是高耸的群山，向西和南眺望均可见村庄和城镇。" );
	
};


RESIDENT_END;
