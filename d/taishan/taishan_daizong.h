//daizong.h

//Sample for room: 泰山岱宗坊
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_daizong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山岱宗坊");

	set("monster_chance", 40);

	add_door("泰山白鹤泉", "泰山白鹤泉", "泰山岱宗坊");
	add_door("泰山山脚", "泰山山脚", "泰山岱宗坊");

	set("long","位于泰安县城以北约一里，此处是登泰山的入口。相传当年碧霞元君被姜子牙戏弄，诱她投掷绣花鞋以定泰山地界，结果碧霞元君只能把绣花鞋从山顶掷到此处。从此泰山便以此为起点。");

/*****************************************************
	set("exits", ([
		"northup" : __DIR__"baihe",
		"south"   : __DIR__"taishanjiao",
		"west"    : "/d/huanghe/huanghe5",
	]));
	set("objects", ([
		"/quest/shan" :1,
	]));
*****************************************************/
};


FIELD_END;
