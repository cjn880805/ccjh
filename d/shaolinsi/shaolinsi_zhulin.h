//zhulin.h

//Sample for room: 竹林
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_zhulin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "少林寺竹林");

	add_npc("shaolin_du_nan");
	add_npc("shaolin_du_e");
	add_npc("shaolin_du_jie");

	add_door("少林寺达摩洞", "少林寺达摩洞", "少林寺竹林");
	add_door("少林寺千佛殿", "少林寺千佛殿", "少林寺竹林");

	set("long", "这里是达摩古洞。五百年前南天竺僧人菩提达摩来到少林寺，见此风水宝地，就住下来广罗弟子，传授禅宗，开创少林寺佛教禅宗千年不败之基。达摩祖师常在此面壁悟道，一坐十年，壁间隐隐似仍可看到他面壁时的打坐姿态。除地上的几块竹片外，洞中空无一物。" );

/*****************************************************
	set("exits", ([
		"out" : __DIR__"bamboo1",
	]));
	set("objects",([
		"/clone/book/book-bamboo" : 1,
		CLASS_D("shaolin")+"/da-mo" : 1,
	]));
//	
********************************************/
};


ROOM_END;
