//dalixi.h

//Sample for room:  大理城西
//coded by zouwenbin
//data: 2000-11-15

RESIDENT_BEGIN(CRDaLixi);

virtual void create()			
{
	set_name( "大理城西");

	set("resident", "大理");
	set("capacity", 30);
	set("price", 120);

	add_npc("pub_playboy");
	add_npc("pub_flowerg");
	add_npc("dali_guigongzi");        //add by zdn 2001-07-20

	add_door("大理城南门", "大理城南门", "大理城西");
	add_door("大理城北门", "大理城北门", "大理城西");
	add_door("大理城东", "大理城东", "大理城西");

	add_door("大理城皇宫前殿", "大理城皇宫前殿", "大理城西");
//	add_door("大理城太和居", "大理城太和居", "大理城西");
	add_door("大理城兵营", "大理城兵营", "大理城西");
};


RESIDENT_END;
