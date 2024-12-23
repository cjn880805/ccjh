//beimen.h

//Sample for room:  扬州北门
//coded by zwb
//data: 2000-11-22

ROOM_BEGIN(CRYZJW_beimen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州北门");

	add_npc("pub_wujiang");
	add_npc("pub_bing");
	add_npc("pub_beibeibei");

	add_door("扬州北驿道","扬州北驿道","扬州北门");
	add_door("扬州西北","扬州西北","扬州北门");

    set("long","这是北城门，因为曾经失火，到现在城墙还是黑乎乎的，因此白纸黑字的官府告示(gaoshi)就显得特别现眼。北方是一片崇山峻岭，一条黄土小径在山里蜿蜒而上。");

};


ROOM_END;
