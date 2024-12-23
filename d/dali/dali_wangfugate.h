//wangfugate.h

//Sample for room: 王府大门
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_wangfugate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "王府大门");

	//add npcs into the room
	add_npc("pub_weishi2");/////////////////////////
	add_npc("pub_weishi1");

	add_npc("pub_xiangke");
	add_npc("dali_fusigui");
	add_npc("dali_jiading");
	add_npc("dali_bing");      //add by zdn 2001-07-20
				

	add_door("大理城东", "大理城东", "大理城王府大门");
	add_door("大理城王府大厅", "大理城王府大厅", "大理城王府大门");

	set("long", "你正站在一座豪华的府门前，门前有两只极大的石狮子，门上高悬一块横匾，上书「镇南王府」四个金字。门口站着两排侍卫，身着锦衣，手执钢刀，气宇轩昂。" );
	set("valid_startroom", 1);

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
ROOM_END;




