//cjlou1.h

//Sample for room: 藏经阁二楼
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_cjlou1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "藏经阁二楼");

	CBox * box = Add_Box();
	box->add_object("wuji1", 1);	
	box->set_name( "铁柜");
		
	CBox * box1 = Add_Box();
	box1->add_object("wuji2", 1);	
	box1->set_name( "铁柜");
		
	CBox * box2 = Add_Box();
	box2->add_object("wuji3", 1);	
	box2->set_name( "铁柜");
		
	CBox * box3 = Add_Box();
	box3->add_object("yijinjing", 1);	
	box3->set_name( "铁柜");	

	add_door("少林寺藏经阁一楼", "少林寺藏经阁一楼", "少林寺藏经阁二楼");

	set("long", "千余年来少林寺执中原武林之牛耳，自达摩老祖以下，历代人材辈出。其中有不少高僧遗著留存，汇集至今，终成名震天下的少林七十二绝艺。少林精华，尽集于此。二楼四面开窗，确保通风。中间排列着五排大书架。四周则陈列矮几，以供阅读。几位老僧手执经卷，正在闭目凝思。" );

/*****************************************************
	set("exits", ([
		"down" : __DIR__"cjlou",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/hui-zhen" : 1,
		"/clone/book/yijinjing" : 1,
		"/clone/book/wuji1" : 1,
		"/clone/book/wuji2" : 1,
		"/clone/book/wuji3" : 1,
	]));
//	
********************************************/
};


ROOM_END;
