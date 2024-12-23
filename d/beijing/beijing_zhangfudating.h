//zhangfudating.h
//Sample for room: 张府大厅


ROOM_BEGIN(CRBeiJing_zhangfudating);

virtual void create()			
{
	set_name( "张府大厅");

	add_npc("pub_binv");//婢女
	add_npc("pub_binv");
	add_npc("bj_zhangfang");//帐房先生
		
	add_door("北京张府", "北京张府", "北京张府大厅");
	add_door("北京张府内堂", "北京张府内堂", "北京张府大厅");

};


ROOM_END;
