//hcaguangchang.h

//Sample for room:  峨嵋华藏庵广场
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_hcaguangchang);

virtual void create()			//Call it when Room Create
{
	set_name( "峨嵋华藏庵广场");

	add_npc("emei_xu");

	add_door("峨嵋华藏庵正殿", "峨嵋华藏庵正殿", "峨嵋华藏庵广场");
	add_door("峨嵋华藏庵东廊1", "峨嵋华藏庵东廊1", "峨嵋华藏庵广场");
	add_door("峨嵋华藏庵西廊1", "峨嵋华藏庵西廊1", "峨嵋华藏庵广场");
	add_door("峨嵋华藏庵大雄宝殿", "峨嵋华藏庵大雄宝殿", "峨嵋华藏庵广场");

	set("long","这里是峨嵋华藏庵的广场，地上铺着青砖。正前方有一道台阶，通往大雄宝殿。殿前有个丈许高的大香炉，香炉前的香台上，红烛高烧，香烟飘绕。广场上有几个小师太正在练功。自此左右各有一条走廊通向后殿。");
    set("valid_startroom","1");

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
