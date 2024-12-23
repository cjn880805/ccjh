//northgate.h

//Sample for room: 大理城北门
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_northgate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城北门");

	set("resident", "大理");

	add_npc("pub_playboy");  // add by zdn 2001-07-12

	add_door("大理城东", "大理城东", "大理城北门");

	set("long", "阳苜咩城，或简称苜咩城，是大理国的都城。自南诏于初创，历经陈氏“长大和国”、赵氏“大天兴国”、杨氏“大义宁国”诸代而至当今的段氏的“大理国”，均以此城为都。此处乃是北城门，以梅溪为护河，城墙建在溪南，由石块和土垒成，高二丈五，厚达二丈，门上有重楼，驻有了哨。青石官道从城里直向北延伸，另有一条黄土大路向西通去。" );

};


RESIDENT_END;
