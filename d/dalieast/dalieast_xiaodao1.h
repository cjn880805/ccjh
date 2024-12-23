//xiaodao1.h

//Sample for room: 大理城林间小道1
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_xiaodao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城林间小道1");

	set("resident", "黑龙岭");

	add_npc("pub_biaotou");   //add by zdn 2001-07-12

	add_door("大理城蝴蝶泉", "大理城蝴蝶泉", "大理城林间小道1");
	add_door("大理城黑龙岭", "大理城黑龙岭", "大理城林间小道1");
	add_door("大理城清溪三潭", "大理城清溪三潭", "大理城林间小道1");

	set("long", "沿林荫小道曲折前行约四十公尺，只见古树林立，浓荫蔽天，一方清泉嵌于其间，底铺青石，泉水明澈，常有人掷钱币于池中，观其缓缓旋落，阳光从树顶筛下，池底银光闪烁，倍感泉水清冽。池边距地面约二三尺的地方有一粗可合抱的树干，伸过泉上，池旁建有小亭，小坐生凉，十分清幽。 " );

};

RESIDENT_END;
