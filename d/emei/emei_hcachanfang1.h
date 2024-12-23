//hcachanfang.h

//Sample for room:  峨嵋华藏庵禅房
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_hcachanfang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋华藏庵禅房");

	add_npc("pub_boydizi");
	add_npc("pub_girldizi");            // add by zdn 2001-07-14

	add_door("峨嵋华藏庵西廊2", "峨嵋华藏庵西廊2", "峨嵋华藏庵禅房");
	add_door("峨嵋华藏庵大雄宝殿", "峨嵋华藏庵大雄宝殿", "峨嵋华藏庵禅房");

	set("long","这里便是峨嵋华藏庵的禅房。地下散乱地放着许多蒲团，木鱼等，此处正是本派弟子打坐修行之所。几位年轻师太和俗家女弟子正肃容入定。　　禅房后面有一道门通往华藏庵休息室，北边的走廊通向广场。");
    
    set("sleep_room", 1);
    set("no_fight", 1);
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
