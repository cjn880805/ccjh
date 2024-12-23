//qingfengge1.h

//Sample for room: 青凤阁内堂

ROOM_BEGIN(CRLingZhou_qingfengge1);

virtual void create()		
{
	set_name( "青凤阁内堂");

	add_door("灵州皇宫青凤阁", "灵州皇宫青凤阁", "灵州皇宫青凤阁内堂");
	set("no_fight",1);
	set("no_cast",1);

};


ROOM_END;
