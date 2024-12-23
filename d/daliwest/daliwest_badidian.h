//badidian.h

//Sample for room: 巴的甸
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiWest_badidian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "巴的甸");

	set("resident", "镇雄");
	
	add_npc("pub_shaonu");  //add by zdn 2001-07-13

	add_door("大理城镇雄", "大理城镇雄", "大理城巴的甸");
	add_door("大理城泸水沿岸", "大理城泸水沿岸", "大理城巴的甸");
	add_door("大理城东泸水河谷", "大理城东泸水河谷", "大理城巴的甸");

	set("long", "这里就是大理西部要镇巴的甸，是乌夷的重要治府，多个乌夷部落分布在附近。坐于东泸水谷地正中，巴的甸四周多农田，以此为中心，道路四通八达连接各方的部落。" );
	
};


RESIDENT_END;
