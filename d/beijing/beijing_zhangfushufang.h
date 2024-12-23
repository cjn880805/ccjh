//zhangfushufang.h
//Sample for room: 张府书房

ROOM_BEGIN(CRBeiJing_zhangfushufang);

virtual void create()			
{
	set_name( "张府书房");

	set("no_fight",1);
	set("no_cast",1);

	add_npc("zaixiang_zhang");//张居正
	
	add_door("北京张府内堂", "北京张府内堂", "北京张府书房");
};


ROOM_END;
