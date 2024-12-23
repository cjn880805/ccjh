//yihongyuan2.h

//Sample for room: 怡红院
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRBeiJing_yihongyuan2);

virtual void create()			//Call it when Room Create
{
	set_name( "怡红院");
	set("no_fight", 1);
	set("sleep_room",1);
	set("valid_startroom", 1);
	add_npc("pub_xiangke");
	add_door("北京怡红院", "北京怡红院", "北京怡红院二楼");

};


ROOM_END;




