//shanjian.h

//Sample for room: 大理城林中山涧
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_shanjian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城林中山涧");

	add_npc("pub_youke"); //add by zdn 2001-07-12

	add_door("大理城密林", "大理城密林", "大理城林中山涧");
	add_door("大理城半山竹林", "大理城半山竹林", "大理城林中山涧");

	set("long", "密林深处豁然开朗，一道激流从上上飞溅下来，山涧并不宽，更谈不上深，行人尽可徒步通过。涧水清凉干净，路人往往停下来用竹筒装水解渴。四面皆是青竹林，竹叶随山风沙沙作响。有些摆夷村民不远数里上山来采新鲜竹笋为食。" );

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
