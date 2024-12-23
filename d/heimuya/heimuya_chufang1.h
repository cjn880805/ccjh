//chufang1.h

//Sample for room: 风雷堂厨房
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_chufang1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "风雷堂厨房");
	
	add_npc("pub_shinu");

	CBox * box = Add_Box();
	box->add_object("tea_leaf", random(7) + 1);	
	box->set_name( "铁柜");
		
	CBox * box1 = Add_Box();
	box1->add_object("sherou",random(6) + 1);	
	box1->set_name( "铁柜");	

	add_door("黑木崖草地", "黑木崖草地", "黑木崖风雷堂厨房");

	set("long", "你走在一条阴暗的林间小道上，两旁是阴森森的树林。一阵这是风雷堂的厨房，一位美丽侍女满脸堆笑。整个房间菜香胭脂香迷漫。墙上贴着一张醒目的启事(note)。");

/*****************************************************
  set("exits",([
      "east" : __DIR__"grass2",
  ]));
  set("item_desc",([
      "note" : "人是铁，饭是钢，一顿不吃饿得慌。\n",
  ]));

  set("objects",([
      __DIR__"npc/shinu" : 1,
      __DIR__"obj/tea" : random(6),
      __DIR__"obj/sherou"  : random(4),
  ]));
//  
********************************************/
};


ROOM_END;
