//luohan6.h

//Sample for room: 罗汉堂六部
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_luohan6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "罗汉堂六部");

	add_npc("shaolin_cheng_xing");

	add_door("少林寺罗汉堂五部", "少林寺罗汉堂五部", "少林寺罗汉堂六部");
	add_door("少林寺罗汉堂七部", "少林寺罗汉堂七部", "少林寺罗汉堂六部");

	set("long", "这是一间极为简陋的禅房。环视四周，除了几幅佛竭外，室内空荡荡地别无他物。地上整齐的摆放着几个破烂且发黑的黄布蒲团，几位须发花白的老僧正在坐在上面闭目入定。这里是本寺十八罗汉参禅修行的地方，不少绝世武功便是在此悟出。" );

/*****************************************************
	set("exits", ([
		"south" : __DIR__"luohan5",
		"north" : __DIR__"luohan7",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/cheng-xin" : 1,
	]));
	//	
********************************************/
};


ROOM_END;
