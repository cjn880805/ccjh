//xingtang.h
//Sample for room: 刑堂
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_xingtang);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "明教刑堂");
	
	add_npc("mingjiao_lengqian");

	add_door("明教广场", "明教广场", "明教刑堂");

	set("long", "整个刑堂门户紧闭，密不透风。即便是在白昼，也犹如黑夜一般，每隔几步的墙上，点燃着几枝牛油巨烛。中间是一个大火盆，烈焰腾腾。下方摆着一排排烙铁、水牛皮鞭、穿孔竹板及狼牙棒等刑具。四周站满了手持兵刃的执法教众。他们正用冷酷的眼神打量着你，令你不禁浑身哆嗦起来。    冷谦执掌明教刑堂。");
	

	set("no_fight", "1");

/*****************************************************



	set("exits", ([

		"west" : __DIR__"square",

	]));

	set("objects",([

		__DIR__"npc/lengqian" : 1

	]));

********************************************/

};


ROOM_END;
