//liangong.h

//Sample for room: 练功房
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGueiYun_liangong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "练功房");
	
	add_npc("guiyun_duantiande");
	add_npc("guiyun_xiaolu");
	add_npc("guiyun_qiuqianzhang");        //add by zdn 2001-07-20


	add_door("归云庄", "归云庄", "归云庄练功房");

    set("long"," 这里是归云庄陆少庄主的练功房。由与陆少庄主乃少林旁支仙霞派出身，所以房中布置尽是为习练外门硬功之用，竖立着不少木桩和草靶。西边角上还有两个大沙坑，天花板上吊着一支大沙袋。" );

/*****************************************************
	set("exits", ([
		"west"  : __DIR__"huayuan",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 3,
	]));
********************************************/
};


ROOM_END;
