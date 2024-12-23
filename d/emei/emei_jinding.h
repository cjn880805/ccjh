//jinding.h

//Sample for room:  峨嵋金顶
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_jinding);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋金顶");

	add_npc("pub_nigu2");            // add by zdn  2001-07-14

	add_door("峨嵋万行庵", "峨嵋万行庵", "峨嵋金顶");
	add_door("峨嵋华藏庵", "峨嵋华藏庵", "峨嵋金顶");
	add_door("峨嵋卧云庵", "峨嵋卧云庵", "峨嵋金顶");

	set("long","这就是峨嵋山的主峰金顶了。此峰耸立大地，高入云表，秀丽而又壮美，李白赞颂它：『青冥倚天开，彩错疑画出。』登上金顶，视野豁然开朗，鸟看脚下，但见群峰涌绿叠翠，三江如丝如带；回首远眺，则见大雪山横亘天际，贡嘎山直插苍穹。");

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
