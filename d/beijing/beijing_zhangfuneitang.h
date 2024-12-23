//zhangfuneitang.h
//Sample for room: 张府内堂


ROOM_BEGIN(CRBeiJing_zhangfuneitang);

virtual void create()			
{
	set_name( "张府内堂");

	add_npc("pub_binv");//婢女
	add_npc("pub_binv");
	
	add_door("北京张府大厅", "北京张府大厅", "北京张府内堂");
	add_door("北京张府书房", "北京张府书房", "北京张府内堂");
	add_door("北京张府后院", "北京张府后院", "北京张府内堂");

};


ROOM_END;
