//jingzhuang6.h

//Sample for room: 大理城经幢6
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_jingzhuang6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城经幢6");


//	add_door("大理城经幢5", "大理城经幢5", "大理城经幢6");
//	add_door("大理城经幢7", "大理城经幢7", "大理城经幢6");

	set("long", "有神龛五座，内中雕有佛像浮雕二百余座。布局严密，层次分明；表情各异，比例协条；刀痕尤劲，备极精巧；线条流畅，栩栩如生；不愧是滇南石雕艺术的珍品。世代金文家皆赞 滇中艺术，此及品也 。" );
	
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
