//maofuhouyuan.h
//Sample for room: 毛府后院


ROOM_BEGIN(CRBeiJing_maofuhouyuan);

virtual void create()			
{
	set_name( "毛府后院");
	set("nursery",1);//儿童乐园

	add_door("北京毛府内堂", "北京毛府内堂", "北京毛府后院");

};


ROOM_END;
