//houting.h

//Sample for room: 灵州皇宫后厅


ROOM_BEGIN(CRLingZhou_houting);

virtual void create()		
{
	set_name( "皇宫后厅");
	add_door("灵州皇宫大厅", "灵州皇宫大厅", "灵州皇宫后厅");
	add_door("灵州皇宫花园小路", "灵州皇宫花园小路", "灵州皇宫后厅");
};


ROOM_END;
