//zhengting.h

//Sample for room: 福威镖局正厅
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_zhengting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "福威镖局正厅");

	//add npcs into the room
	add_npc("pub_chengqi");
	add_npc("pub_baier");
	add_npc("fuzhou_linzhennan");      // add by zdn 2001-07-20
	
	add_door("福州西", "福州西", "福州福威镖局正厅");
	add_door("福州福威镖局内宅", "福州福威镖局内宅", "福州福威镖局正厅");
	add_door("福州福威镖局后院", "福州福威镖局后院", "福州福威镖局正厅");
	set("no_fight",1);
 

};


ROOM_END;




