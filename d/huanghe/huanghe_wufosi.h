//wufosi.h

//Sample for room: 黄河五佛寺
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_wufosi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河五佛寺");
	
	add_npc("pub_dibao");          //add by zdn 2001-07-14

	add_door("黄河石门", "黄河石门", "黄河五佛寺");

	set("long","这里是一个被废弃的破庙，周围全是沙丘，破庙的寺门已经倒塌，地上有块半埋在沙里的匾，从剥落的金字上你依稀可以辨别出“五佛寺”三个字，唯一尚算完整的建筑是大殿，但屋顶上全是窟窿，强劲的西北风吹过发出难听的“呜---呜---”声。");
	

/*****************************************************
	set("exits", ([
		"south"     : __DIR__"shimen",
	]));
********************************************/
};


CHANGAN_END;
