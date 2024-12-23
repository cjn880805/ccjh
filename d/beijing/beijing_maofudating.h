//maofudating.h
//Sample for room: 毛府大厅


ROOM_BEGIN(CRBeiJing_maofudating);

virtual void create()			
{
	set_name( "毛府大厅");
	
	add_door("北京毛府", "北京毛府", "北京毛府大厅");
	add_door("北京毛府内堂", "北京毛府内堂", "北京毛府大厅");

};


ROOM_END;
