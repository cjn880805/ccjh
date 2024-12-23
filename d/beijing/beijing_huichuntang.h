//huichuntang.h

//Sample for room: 回春堂药店
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_huichuntang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "回春堂药店");

	//add npcs into the room
	add_npc("shaolin_xutianch");
	add_npc("pub_huoji");
	
	add_door("北京西南", "北京西南", "北京回春堂药店");

	set("long", "这是一家药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几百个小抽屉里散发出来的。一位老者在柜台后站着。柜台上贴着一张发黄的广告(guanggao)。柜台后面往西是一间内室(neishi)。" );

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
