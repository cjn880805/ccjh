//yangzhou_dongbei.h

//Sample for room:  扬州东北
//coded by Fisho
//data: 2000-11-2

RESIDENT_BEGIN(CRyangzhou_dongbei);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州东北");

	set("resident", "扬州");
	set("capacity", 25);

	//add npcs into the room
	add_npc("pub_boy");
	add_npc("pub_bing");
	add_npc("pub_playboy");
	add_npc("guiyun_zhangasheng");             //zdd by zdn 2001-07-20
	add_npc("helpnpc_jhlz");
	add_npc("pub_xiaoqiang");

	add_door("扬州客店", "扬州客店", "扬州东北");
	add_door("扬州书院", "扬州书院", "扬州东北");
	add_door("扬州药铺", "扬州药铺", "扬州东北");
	add_door("扬州醉仙楼", "扬州醉仙楼", "扬州东北");
	
	add_door("扬州东南", "扬州东南", "扬州东北");
	add_door("扬州西北", "扬州西北", "扬州东北");

};


RESIDENT_END;




