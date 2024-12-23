//baihe.h

//Sample for room: 泰山白鹤泉
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_baihe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山白鹤泉");

	set("monster_chance", 20);

	add_door("泰山岱宗坊", "泰山岱宗坊", "泰山白鹤泉");
	add_door("泰山一天门", "泰山一天门", "泰山白鹤泉");

	set("long","相传从前这里有一个白鹤泉，它的水清凉甘甜，为泰山之最。这泉水长年涌流不断，喷出的水象仙鹤扑扇着翅膀洗澡一样，因以为名。可惜后来有一个自私自利的小官，独霸了泉水，后来更因迷信风水之说，把泉眼堵塞，白鹤泉从此便干涸了。现在只剩下一座刻着「白鹤泉」三字的石坊以为纪念。从这里继续北上，便是上山之路。");
	set("resource/water",1);
	

/*****************************************************
	set("exits", ([
		"northup"   : __DIR__"yitian",
		"southdown" : __DIR__"daizong",
	]));
*****************************************************/
};


FIELD_END;
