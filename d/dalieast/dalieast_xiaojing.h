//xiaojing.h

//Sample for room: 大理城山区小径
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_xiaojing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城山区小径");

	add_npc("pub_playboy");    //add by zdn 2001-07-12

	add_door("大理城大叠水瀑布", "大理城大叠水瀑布", "大理城山区小径");
	add_door("大理城金汁河畔", "大理城金汁河畔", "大理城山区小径");

	set("long", "这是清源山区的碎石小径，曲折蜿蜒，两旁林木茂盛，遮天蔽日。满径落叶，柔软稀松。虫鸟啾啾。凉风习习。" );
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
