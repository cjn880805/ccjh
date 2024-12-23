//huanyuanlu.h

//Sample for room: 皇宫花园小路


ROOM_BEGIN(CRLingZhou_huanyuanlu);

virtual void create()		
{
	set_name( "皇宫花园小路");
	add_door("灵州皇宫后厅", "灵州皇宫后厅", "灵州皇宫花园小路");
	add_door("灵州皇宫花园", "灵州皇宫花园", "灵州皇宫花园小路");
};


ROOM_END;
