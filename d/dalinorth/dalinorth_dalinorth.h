//dalinorth.h

//Sample for room: 大理城北
//coded by zouwenbin
//data: 2000-11-15

RESIDENT_BEGIN(CRDaLiNorth_dalinorth);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城北");

	set("resident", "大理");

	add_npc("pub_shiwei2");
	add_npc("pub_shiwei2");        //add by zdn 2001-07-13

	add_door("太和城", "大理城太和城", "大理城北");
	add_door("洱水桥", "大理城洱水桥", "大理城北");
	add_door("洱水桥", "大理城洱水桥", "大理城北");

	set("long", "这里是个岔路口。南边就是大理城的北门了，道路从这里分岔，北去可到太和城，西北通向下关城，也通苍山，是去游苍山和崇圣寺的必经之路。" );

};


RESIDENT_END;
