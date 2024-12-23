//piggy.h

//Sample for room: 长安拱猪房
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_piggy);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "长安拱猪房");


	add_door("长安聚义厅", "长安聚义厅", "长安三楼拱猪房");

	set("long", "这间房子是专门为了拱猪用而设的，整间屋子都是用不去皮的松树搭成。一张石桌 (table)周围摆着四个石礅，桌面镶了一块大理石，摸上去极为光滑。四壁挂着长明灯，把屋子照得有如白昼。墙角里烧了一炉不知名的香，似乎颇有提神之效。香炉旁边挂着张告示(gaoshi)，上面写着这里的规矩；桌上有张小纸条(note)，上面草草的记着拱猪成绩。 " );

    set("no_fight",  1);
    set("no_magic",  1);

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
