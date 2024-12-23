//wunong.h

//Sample for room: 大理城乌弄城
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_wunong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城乌弄城");

	set("resident", "乌弄城");

	//add npcs into the room
	add_npc("pub_wyshangfan");
	
	add_door("大理城川西山路", "大理城川西山路", "大理城乌弄城");
	add_door("大理城大渡河边", "大理城大渡河边", "大理城乌弄城");
	add_door("大理城乌蒙村落", "大理城乌蒙村落", "大理城乌弄城");

	set("long", "此处已到大理的北疆，是乌蒙的珙部的治府，乌蒙属乌夷，居民多居于高山上。这里正处高山之腰，北临波涛汹涌的大渡河。巷陌皆用山石垒成，高丈余，延绵全城。此城不大，四面山上分布着些乌蒙民居，有牧人赶着牛羊穿镇而过。");

};


RESIDENT_END;
