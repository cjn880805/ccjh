//duchang2.h

//Sample for room: 长安骨骰房
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_duchang2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "长安骨骰房");

	add_npc("pub_shinu1");  //2001-07-12 zdn add
	add_npc("pub_xuanyuanguang");  //21点游戏 2002、3、22

	add_door("长安乐坊二楼大厅", "长安乐坊二楼大厅", "长安骨骰房");

	set("long", " 这里摆着一个八仙桌，中间摆着一个银盘。赌客们正聚精会神地下赌。正席是一位胖子，手里不断玩弄着一对玉骰，他就是这里的庄东。墙上挂有一个匾，上面写着：        头彩（骰数由每次开盘前确定）            ：一赢三十六        双对（两骰号相同，且为偶数）            ：一赢十二        七星（两骰之和为七）                    ：一赢六        散星（两骰之和为三，五，九，十一）      ：一赢三匾角有一个牌子(paizi)。 " );
	set("light_up",  1);
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




