//yan.h

//Sample for room: 灵鹫失足岩
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_yan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵鹫失足岩");

	add_npc("lingjiu_zhou");
	
	add_door("灵鹫断魂崖", "灵鹫断魂崖", "灵鹫失足岩");
	add_door("灵鹫百丈涧", "灵鹫百丈涧", "灵鹫失足岩");

	set("long", "这是通向『灵鹫宫』的必经之路，山道被一块如鹰喙突出的巨岩截断，巨岩光可鉴人，只有中间凿出了一条窄窄的石阶通向山道的那一头。你小心翼翼地试着踏了上去，心想：我能过去吧。" );
	

/*****************************************************
  set("outdoors", "lingjiu");
  set("exits",([
      "northup"  : __DIR__"jian",
      "eastdown" : __DIR__"ya",
  ]));
********************************************/
};


ROOM_END;
