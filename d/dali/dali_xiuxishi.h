//xiuxishi.h

//Sample for room: 下人居室
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_xiuxishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "下人居室");

	//add npcs into the room
	add_npc("pub_weishi2");/////////////////////////
	add_npc("pub_weishi1");
	add_npc("pub_xiangke");
	//add_npc("zhuwanli");
	add_door("大理城王府大厅", "大理城王府大厅", "大理城王府下人居室");

	set("long", "你正站在一座豪华的府门前，门前有两只极大的石狮子，门上高悬一块横匾，上书「镇南王府」四个金字。门口站着两排侍卫，身着锦衣，手执钢刀，气宇轩昂。" );
	set("valid_startroom", 1);
    set("sleep_room",1);

};

ROOM_END;




