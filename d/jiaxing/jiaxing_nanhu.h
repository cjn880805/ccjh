//nanhu.h

//Sample for room: 嘉兴南湖
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRJiaXing_nanhu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "嘉兴南湖");
	add_npc("gumu_liqingzhao");

	set("resident", "嘉兴");

	add_door("嘉兴城", "嘉兴城", "嘉兴南湖");
	add_door("归云庄", "归云庄", "嘉兴南湖");

	

/*****************************************************
	set("long", @LONG
这里是烟波浩淼的南湖。湖上几只画舫在游荡，船上的游客和
青楼女子在嘻笑。湖水很深，没有船是渡不过去的。但不知是谁在
湖底钉了一些木桩。桩顶潜在水面之下一两寸的地方。即使是不懂
轻功的人走上去也像是水上漂的样子。似乎水下有了些什么. 近来
有人潜(out)下湖去搜寻什么, 总也不知道结果如何. 只是有人传
闻在湖底找到了什么宝贝.
LONG );
	set("exits", ([
		"south"     : __DIR__"yanyu",
                "northwest" : __DIR__ "nanhu",
	]));
	set("outdoors", "quanzhou");
 ********************************************/
};


RESIDENT_END;
