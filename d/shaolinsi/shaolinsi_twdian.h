//twdian.h

//Sample for room: 天王殿
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_twdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天王殿");

	add_npc("pub_xiangke");
	add_npc("shaolin_dao_guo");


	add_door("少林寺精进场", "少林寺精进场", "少林寺天王殿");
	add_door("少林寺台阶", "少林寺台阶", "少林寺天王殿");

	set("long", "这里是少林寺的中殿天王殿。殿内香烟燎绕，幔角叮咚。香火比前殿要旺盛的多。正前方供着个大肚子，似乎永远都笑咪咪的弥勒佛。四大天王分列两旁，分执“风调雨顺”。两侧香桌上摆满了四季果蔬，弥勒的身后站立的是韦驮。只见他金盔金甲，年轻英俊，威风凛凛，双手合十，金刚杵横放腕上。左右两边各有一间偏殿。" );

/*****************************************************
	set("exits", ([
		"east" : __DIR__"twdian1",
		"west" : __DIR__"twdian2",
		"southdown" : __DIR__"taijie",
		"north" : __DIR__"guangchang2",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/dao-guo" : 1,
		__DIR__"npc/xiang-ke" : 1,
	]));
//	
********************************************/
};


ROOM_END;
