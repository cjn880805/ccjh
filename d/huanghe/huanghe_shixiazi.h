//shixiazi.h

//Sample for room: 黄河石峡子
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_shixiazi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河石峡子");

	CBox * box = Add_Box();
	box->add_object("eluanshi", 1);	
	box->set_name( "铁柜");	
	
	add_npc("pub_poorman");
	add_npc("pub_punk");         //add by zdn 2001-07-14

	add_door("黄河土门子", "黄河土门子", "黄河石峡子");
	add_door("黄河冰草湾", "黄河冰草湾", "黄河石峡子");

	set("long","石峡子是以前的黄河故道，现在遍地是大大小小的鹅卵石，两边是数丈高的高坡，千沟万壑，向你诉说着世事的沧桑。要是运气好的话你可以在这里拣到非常漂亮、非常珍贵的雨花石。");

/*****************************************************
	set("exits", ([
		"southwest" : __DIR__"tumenzi",
		"northeast" : __DIR__"bingcao",
	]));
	set("objects", ([
		"/d/city/obj/shitou" : 1,
		"/d/hangzhou/obj/eluanshi" :1,
	]));
********************************************/
};


CHANGAN_END;
