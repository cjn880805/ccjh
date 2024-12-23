//tusifu.h

//Sample for room: 土司府
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_tusifu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "土司府");

	//add npcs into the room
	add_npc("dali_datusi");/////////////////////////
	add_npc("pub_shicong");

				

	add_door("大理城西", "大理城西", "大理城土司府");

	add_door("大理城土司府议事厅", "大理城土司府议事厅", "大理城土司府");

	set("long", "土司府是当地傣族世袭土司刀氏的衙门，一座古老的砖木建筑物，门庭居高临下，庄严坚实，门前是宽广的石阶，有点象衙门气势，房屋共三台，占地约八百亩，分作正厅，议事厅，后厅，厢房。" );

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
