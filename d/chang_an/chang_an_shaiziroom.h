//shaiziroom.h

//Sample for room: 长安骰子房
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_shaiziroom);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "长安骰子房");

	//add npcs into the room  2001-07-12 zdn add
	add_npc("pub_punk");   //小流氓

	add_door("长安乐府诗社", "长安乐府诗社", "长安骰子房");

	set("long", " 屋中间摆着一张看起来相当结实的大长条桌(table)，四周围了十几把靠背木椅。北面墙上有一块牌子(paizi)。" );
	set("no_fight",  1);
	set("no_cast",  1);

	set("no_caishen",  1);

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

CHANGAN_END;
