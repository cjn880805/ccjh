//huanyuan.h

//Sample for room: 皇宫花园

ROOM_BEGIN(CRLingZhou_huanyuan);

virtual void create()		
{
	set_name( "皇宫花园");
	add_door("灵州皇宫花园小路", "灵州皇宫花园小路", "灵州皇宫花园");
	add_door("灵州皇宫幽兰涧", "灵州皇宫幽兰涧", "灵州皇宫花园");
};


ROOM_END;
