//yangzong.h

//Sample for room: 大理城阳宗镇
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_yangzong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城阳宗镇");

	set("resident", "阳宗镇");

	//add npcs into the room
	add_npc("pub_bshangfan");
	add_npc("dali_jianghuyiren");     //add by zdn 2001-07-20
	
	add_door("大理城山路8", "大理城山路8", "大理城阳宗镇");
	add_door("大理城农田4", "大理城农田4", "大理城阳宗镇");
	add_door("大理城桑林", "大理城桑林", "大理城阳宗镇");
	add_door("大理城密林", "大理城密林", "大理城阳宗镇");

	set("long", "这里是强宗部的村镇，是么些蛮族的聚居区域，么些蛮族是摆夷的一支。此处也是山间的小型平原，北面临着一片绿水，叫做明湖，这地方略微偏远些，但有相当不少的摆夷人生活在附近。西南方有道路通向其它村镇。" );
	
};

RESIDENT_END;
