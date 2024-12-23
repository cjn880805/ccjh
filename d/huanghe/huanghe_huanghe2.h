//huanghe2.h

//Sample for room: 黄河岸边2
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河岸边2");
	
	add_npc("monster_24k");        //add by zdn 2001-07-14
	add_npc("pub_ruanjiao"); 

	add_door("黄河岸边1", "黄河岸边1", "黄河岸边2");
	add_door("黄河岸边3", "黄河岸边3", "黄河岸边2");

	set("long","这里是黄河岸边。黄河流淌到这里，已经泥沙浑浊了。黄色的河水在河床里翻滚着，咆哮着，卷起一个个巨大的漩窝。");
    

/*****************************************************
	set("exits", ([
		"east"  : __DIR__"huanghe3",
		"west"  : __DIR__"huanghe1",
	]));
********************************************/
};


CHANGAN_END;
