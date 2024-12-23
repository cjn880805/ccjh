//buxiongbu.h

//Sample for room: 大理城步雄部
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_buxiongbu);

virtual void create()			//Call it when Room Create
{
	set_name( "大理城步雄部");

	set("resident", "步雄部");

	add_npc("pub_bshangfan");
	
	add_door("大理城养蚕房", "大理城养蚕房", "大理城步雄部");
	add_door("大理城农田5", "大理城农田5", "大理城步雄部");
	add_door("大理城半山竹林", "大理城半山竹林", "大理城步雄部");
	add_door("大理城星云湖畔", "大理城星云湖畔", "大理城步雄部");
	add_door("大理城杆栏3", "大理城杆栏3", "大理城步雄部");

};


RESIDENT_END;
