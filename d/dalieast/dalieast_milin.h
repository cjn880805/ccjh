//milin.h

//Sample for room: 大理城密林
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_milin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城密林");

	set("resident", "阳宗镇");

	//add npcs into the room
	add_npc("animal_qingshe");
	
	add_door("大理城阳宗镇", "大理城阳宗镇", "大理城密林");
	add_door("大理城林中山涧", "大理城林中山涧", "大理城密林");

	set("long", "此处山道狭窄，林木特别茂密，山民踏出来的小道被纵横交错的林木遮挡阻碍着，行路者不停地用刀劈砍开路，才能顺利前进。四面青山峭立，丛林中时常有鸟兽惊走，偶尔还能看见美丽的孔雀飞过。" );

};


RESIDENT_END;
