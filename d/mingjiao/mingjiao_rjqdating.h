//rjqdating.h



//Sample for room: 锐金旗大厅

//coded by zouwenbin

//data: 2000-11-16



ROOM_BEGIN(CRMingJiao_rjqdating);



virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "明教锐金旗大厅");

	add_npc("pub_liuyun");

	add_npc("mingjiao_zhuangzheng");

	add_door("明教青石大道5", "明教青石大道5", "明教锐金旗大厅");

	set("long", "这是锐金旗的大厅，虽然都是练武之人，这里却布置得古色古香，显出锐金旗的与众不同。大厅正面高悬一块牌匾，上书四个烫金大字“锐气金风”，一百二十年前，明教与来犯的蒙古军队一场鏖战，锐金旗力守玄天崖，死者八、九，教主亲书此匾以励教众，锐金旗以此为五旗之首。厅中央摆有茶几，锐金旗掌旗使庄铮正襟而坐，正在读一本书卷。" );

/*****************************************************

	set("exits", ([

		"south" : __DIR__"rjqyuan",

	]));

//	set("outdoors", "mingjiao");

        set("objects",([

                __DIR__"npc/zhuangzheng":1,

//              "/kungfu/class/mingjiao/zhuangzheng":1,

//		"/kungfu/class/mingjiao/yangxiao":1,

//	        "/kungfu/class/mingjiao/fanyao":1,

//	        "/kungfu/class/mingjiao/yintianzheng":1,

//              "/kungfu/class/mingjiao/xiexun":1,

//	        "/kungfu/class/mingjiao/xuan-nan":1,

//              "/kungfu/class/mingjiao/weiyixiao":1,

	]));

********************************************/

};





ROOM_END;
