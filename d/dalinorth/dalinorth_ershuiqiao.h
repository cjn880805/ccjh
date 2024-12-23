//ershuiqiao.h

//Sample for room: 大理城洱水桥
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_ershuiqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城洱水桥");

	set("resident", "下关城");

	add_npc("pub_girl1");
	add_npc("pub_boy");    // add by zdn 2001-07-13

	add_door("大理城北门", "大理城北门", "大理城洱水桥");
	add_door("大理城下关城", "大理城下关城", "大理城洱水桥");

	set("long", "一座长百余步的青石桥。此桥横跨洱水，连接下关城和大理城，桥下清澈的洱水滚滚东去。桥北正是下关城的城门，桥南一路南行十数里即可到大理城。");
	
};

RESIDENT_END;
