//bashisipan3.h
//Sample for room:  峨嵋八十四盘3
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_bashisipan3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋八十四盘3");

	add_npc("pub_youke");
	add_npc("pub_jianke");     // add by zdn 2001-07-14

	add_door("峨嵋八十四盘2", "峨嵋八十四盘2", "峨嵋八十四盘3");
	add_door("峨嵋接引殿", "峨嵋接引殿", "峨嵋八十四盘3");
//	add_door("峨嵋冷杉林4", "峨嵋冷杉林4", "峨嵋八十四盘3");

	set("long","八十四盘，道路艰险陡峭，迂回盘折，令人不能喘息。路左是蔽日遮天的冷杉林，路右是深不见底的绝壁峡谷。由此往上至接引殿，北下到洗象池。");

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
