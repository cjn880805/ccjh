//zhangfuhouyuan.h
//Sample for room: 张府后院


ROOM_BEGIN(CRBeiJing_zhangfuhouyuan);

virtual void create()			
{
	set_name( "张府后院");

	add_npc("pub_binv");//婢女
	add_npc("pub_binv");
	
	add_door("北京张府内堂", "北京张府内堂", "北京张府后院");

};


ROOM_END;
