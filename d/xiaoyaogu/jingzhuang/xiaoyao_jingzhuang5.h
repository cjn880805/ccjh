//jingzhuang5.h
//Sample for room: 大理城经幢5

ROOM_BEGIN(CRXiaoYao_jingzhuang5);

virtual void create()
{
	set_name( "大理城经幢5");
	set("no_autosave",1);

	add_door("大理城经幢4", "逍遥谷大理城经幢4", "逍遥谷大理城经幢5");
	add_door("大理城经幢6", "逍遥谷大理城经幢6", "逍遥谷大理城经幢5");

	set("long", "球状，无人像，四角挂有黄铜铸灵鹫。四只灵鹫，口角噙有一枚两头有孔的铜管，管内有金属簧片，鹫口、鹫颈、鹫腹皆是空心。每当劲风吹来，经鹫嘴内铜管，在鹫腹内空气回旋荡扬，便发出悦耳的鸣叫。不但平增灵鹫的神密气氛，亦可想见能工巧匠们的精湛技艺。" );
	
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}


ROOM_END;
