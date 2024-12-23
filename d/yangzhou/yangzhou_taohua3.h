//taohua3.h

//Sample for room: 桃花谷
//coded by zwb
//data: 2000-12-1

RESIDENT_BEGIN(CRYangZhou_taohua3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "桃花谷");

	set("resident", "桃花村");

	add_npc("yunlong_xuanzhen");
	add_npc("pub_baihuanxi");
	add_npc("helpnpc006");

	add_door("扬州桃花溪", "扬州桃花溪", "扬州桃花谷");
	add_door("扬州桃花村", "扬州桃花村", "扬州桃花谷");

	set("long", "顺溪流而上，两边山势渐高，流水渐急，桃林也愈见密集，层层桃花拥攒成一片晚霞，留心处，时时可见悬泉飞瀑，倒挂崖间。桃花溪水跳荡起伏，青鳞赤鲤隐隐相戏。这里就是桃花谷了。谷口一个尺许高的小纂石碑(shibei)斜侧路旁。 " );
	

/*****************************************************
	set("outdoors", "city");
	set("item_desc", ([
		"shibei" : (: look_shibei :),
	]));
	set("exits", ([
		"eastdown" : __DIR__"taohua2",
		"northup"  : __DIR__"taohua4",
	]));
********************************************/
};


RESIDENT_END;
