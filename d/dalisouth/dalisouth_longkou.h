//longkou.h

//Sample for room: 龙口城
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaLisouth_longkou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "龙口城");

	set("resident", "喜州");

	//add npcs into the room
	add_npc("pub_bing");
	add_npc("pub_bing");
	
	add_door("大理城妃丽湖东", "大理城妃丽湖东", "大理城龙口城");

	set("long", "这里已到大理南疆了，龙口城南临元江，属临江路。大理国南部虽广有千多里，但大城镇较稀少，此地虽离大理中心不远，却也算南部的重要关口之一了，是和南方临国通商的口岸。由此北去二十五里即是喜州城，南边沿元江有不少台夷村庄。大理官府在此有些驻军。" );
	
};


RESIDENT_END;
