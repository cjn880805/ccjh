//zhenxiong.h

//Sample for room: 镇雄
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiWest_zhenxiong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "镇雄");

	set("resident", "镇雄");

	//add npcs into the room
	add_npc("pub_muyangnu");/////////////////////////
	add_npc("pub_wyshangfan");
	add_npc("baiyang");
	
	add_door("大理城梯田", "大理城梯田", "大理城镇雄");
	add_door("大理城巴的甸", "大理城巴的甸", "大理城镇雄");
	add_door("大理城葛鲁城", "大理城葛鲁城", "大理城镇雄");
	add_door("大理城乌夷民居", "大理城乌夷民居", "大理城镇雄");

	set("long", "这里是乌撒部的聚居中心，乌撒是乌蛮族的大部，属乌夷，领有巴的甸、镇雄、和附近的威宁。这是一座石砌小城，人口不多，居民散居在镇子附近，镇子上主要是一些商铺和祭祀所。" );

};

RESIDENT_END;
