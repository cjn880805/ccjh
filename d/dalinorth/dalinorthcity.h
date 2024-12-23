//dalinorth.h

//Sample for room:  大理城北门
//coded by zouwenbin
//data: 2000-11-15

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRDaLiNorthcity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城北门");

	//add npcs into the room
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("pub_wujiang");
	add_npc("dali_guigongzi");           //add by zdn 2001-07-20 

	add_door("大理城西", "大理城西", "大理城北门");
	add_door("大理城山路3", "大理城山路3", "大理城北门");
	add_door("大理城太和城", "大理城太和城", "大理城北门");
	add_door("大理城洱水桥", "大理城洱水桥", "大理城北门");
	add_door("大理城茶花山1", "大理城茶花山1", "大理城北门");

	set("long","阳苜咩城，或简称苜咩城，是大理国的都城。自南诏于初创，历经陈氏“长大和国”、赵氏“大天兴国”、杨氏“大义宁国”诸代而至当今的段氏的“大理国”，均以此城为都。此处乃是北城门，以梅溪为护河，城墙建在溪南，由石块和土垒成，高二丈五，厚达二丈，门上有重楼，驻有了哨。青石官道从城里直向北延伸，另有一条黄土大路向西通去。");
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
