//guangchang.h

//Sample for room: 武当广场
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_guangchang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当广场");

	add_npc("wudang_yin");

	add_door("武当石阶", "武当石阶", "武当广场");
	add_door("武当三清殿", "武当三清殿", "武当广场");
	add_door("武当太子岩", "武当太子岩", "武当广场");
	add_door("武当紫霄宫大门", "武当紫霄宫大门", "武当广场");

	set("long","这是一个由大石板铺成的广场，是武当弟子学习武功和互相切磋的地点。周围种满了梧桐树，一到秋天就是满地的落叶。一个年纪轻轻的道童正在打扫。南边是灵霄宫三清殿。");
    

/*****************************************************
      set("objects", ([
           CLASS_D("wudang") +"/daotong": 2,
      ]));
      set("exits",([  
          "northdown"  : __DIR__"zixiaogate",
          "south"      : __DIR__"sanqingdian",
          "eastdown"   : __DIR__"tyroad1",
          "east"       : __DIR__"shanlu2",
      ]));
*****************************************************/
};


ROOM_END;
