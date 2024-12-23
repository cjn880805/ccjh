//huanghe_3.h

//Sample for room: 黄河3
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe_3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河3");
	
	add_npc("pub_daoke");       //add by zdn 2001-07-14

	add_door("黄河2", "黄河2", "黄河3");
	add_door("黄河永登", "黄河永登", "黄河3");

	set("long","葛水过了古浪，和源于酒泉西北的洪水河于新城合流。到了这里，河水的去势逐渐加强，挟带着千万吨的高原泥沙，势不可挡地向西南奔去。由于此处水流湍急，这里的鱼大多肉厚脂丰。名扬天下的黄河大鲤鱼即产于此。");
    

/*****************************************************
	set("exits", ([
		"east" : __DIR__"huanghe_2",
		"west" : __DIR__"yongdeng",
	]));
********************************************/
};


CHANGAN_END;
