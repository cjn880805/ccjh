//maofuneitang.h
//Sample for room: 毛府内堂

ROOM_BEGIN(CRBeiJing_maofuneitang);

virtual void create()			
{
	set_name( "毛府内堂");

	add_door("北京毛府大厅", "北京毛府大厅", "北京毛府内堂");
	add_door("北京毛府书房", "北京毛府书房", "北京毛府内堂");
	add_door("北京毛府后院", "北京毛府后院", "北京毛府内堂");

};


ROOM_END;
