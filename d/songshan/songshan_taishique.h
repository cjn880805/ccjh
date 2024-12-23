//taishique.h

//Sample for room: 太室阙
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_taishique);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "太室阙");
	
	add_npc("songshan_ding");         //add by zdn 2001-07-20


	add_door("北京汝州城", "北京汝州城", "嵩山太室阙");
	add_door("嵩山天中阁", "嵩山天中阁", "嵩山太室阙");
	add_door("少林寺石阶", "少林寺石阶", "嵩山太室阙");

	set("long", "嵩山古称方外，又称崇山，为五岳中的中岳，由太室少室二山沿绵而成。汉武帝时称 '嵩高' ，取自诗经 '嵩岳维高，峻极于天' ，道教以之为第六小洞天。阕高丈余，南面刻 '中岳太室阳城' 六字，篆文古朴，苍劲有力。向西就是去少室山少林寺的路。向北一里许便是中岳庙了。 ");
	

/*****************************************************
	set("exits", ([
		"north" : __DIR__"tianzhongge",
		"east"  : "/d/shaolin/ruzhou",
		"west"  : "/d/shaolin/shijie1",
	]));
	set("outdoors", "songshan");
	set("objects", ([
		__DIR__"npc/yao" : 1,
	]));
********************************************/
};


ROOM_END;
