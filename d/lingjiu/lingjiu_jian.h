//jian.h

//Sample for room: 灵鹫百丈涧
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_jian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵鹫百丈涧");

	add_npc("lingjiu_liu");

	add_door("灵鹫失足岩", "灵鹫失足岩", "灵鹫百丈涧");
	add_door("灵鹫仙愁门", "灵鹫仙愁门", "灵鹫百丈涧");


/*****************************************************
  set("outdoors", "lingjiu");
  set("exits",([
      "southdown" : __DIR__"yan",
  ]));
  set("objects",([
      __DIR__"npc/yupopo" : 1,
  ]));
  set("item_desc",([
      "bei" : "『灵鹫宫』重地，擅入者死！\n" ,
      "tiesuo" : "这是通往对面的“接天桥”，你也许可以走过(zou)去。\n" ,
  ]));
********************************************/
};


ROOM_END;
