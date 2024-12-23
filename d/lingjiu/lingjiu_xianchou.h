//xianchou.h

//Sample for room: 灵鹫仙愁门
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_xianchou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵鹫仙愁门");

	add_npc("lingjiu_feng");
	add_npc("helpnpc015");

	add_door("灵鹫百丈涧", "灵鹫百丈涧", "灵鹫仙愁门");
	add_door("灵鹫青石大道1", "灵鹫青石大道1", "灵鹫仙愁门");

	set("long", "这里就快到缥缈峰绝顶了，越往上走，山势越高，缭绕在你身边的白雾愈来愈浓，往南则是下山的路。沿着山道没走几步，在你眼前出现一个石坊，上书『仙愁门』三个大字，盖因上山之艰辛吧。" );
	

/*****************************************************
  set("outdoors", "lingjiu");
  set("exits",([
      "eastup" : __DIR__"dadao1",
      "southdown" : __DIR__"jian",
  ]));
********************************************/
};


ROOM_END;
