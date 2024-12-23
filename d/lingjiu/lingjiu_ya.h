//ya.h

//Sample for room: 灵鹫断魂崖
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_ya);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵鹫断魂崖");

	add_npc("pub_qixianglian");
	add_door("灵鹫失足岩", "灵鹫失足岩", "灵鹫断魂崖");
	add_door("灵鹫缥缈峰山脚", "灵鹫缥缈峰山脚", "灵鹫断魂崖");

	set("long", "这是通向[灵鹫宫]的必经之路，一条小道蜿蜒曲折地通向缥缈峰顶。路的右侧是一条陡峭的山崖，一阵山风吹过，你似乎听见从下面传来几声惨号，你心中一凛，不禁加快脚步赶紧离开这里。" );
	

/*****************************************************
  set("outdoors", "lingjiu");
  set("exits",([
      "westup"   : __DIR__"yan",
      "eastdown" : __DIR__"shanjiao",
  ]));
********************************************/
};


ROOM_END;
