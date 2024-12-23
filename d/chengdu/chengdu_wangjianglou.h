//wangjianglou.h

//Sample for room: 望江楼
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_wangjianglou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "望江楼");

	add_npc("pub_shinu1");   //zdn 2001-07-12 add
	add_npc("pub_duguqiu");

	add_door("成都东", "成都东", "成都望江楼");

	set("long",	"望江楼又名崇丽阁。下两层四角，上两层八角，朱柱琉瓦，翘角飞甍，雕梁画栋，登临其上，远眺府南河，清风扑面，舟火穿梭，实为胜景。楼的周遭，翠竹千茎朝天，每当雨雾氤氲，轻烟笼翠，竹籁鸟音，动人心魄。楼前薛涛井，传说因为薛涛漂洗一种红色诗笺而流芳千古: 无波古井因涛重，有色遗笺举世珍。这也是这一才女的传世的唯一遗泽。"	);

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




