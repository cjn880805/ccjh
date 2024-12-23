//chufang.h

//Sample for room: 灵鹫藕香榭
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵鹫藕香榭");
	add_npc("lingjiu_lu");
	
	CBox * box = Add_Box();
	box->add_object("suanmei", 1);	
	box->set_name( "铁柜");		

	add_door("灵鹫画廊6", "灵鹫画廊6", "灵鹫藕香榭");

	set("long", "这是间厨房，浓郁的饭菜香味一个劲地钻进你的鼻子， 你仿佛听到“咕咕”的响声，环顾四周不知来源。原来是你的肚子作怪。" );

/*****************************************************
  set("exits",([
      "east" : __DIR__"changl6",
  ]));
  set("objects",([
      __DIR__"npc/lisao" : 1,
      __DIR__"obj/suanmei" : 2,
      __DIR__"obj/gao" : 2,  
  ]));
********************************************/
};


ROOM_END;
