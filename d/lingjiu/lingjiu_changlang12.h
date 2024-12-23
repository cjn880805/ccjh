//changlang12.h

//Sample for room: 灵鹫画廊12
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changlang12);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵鹫画廊12");


	add_door("灵鹫画廊9", "灵鹫画廊9", "灵鹫画廊12");
	add_door("灵鹫书房大门", "灵鹫书房大门", "灵鹫画廊12");

	set("long", "这是一条非常精美的长廊，柱子和栏杆是用华贵的紫檀木制成，上面雕饰着美丽的图画，画工精巧，美不胜收。地板不知是用什么材料做的，走在上面毫无声息，你只感到脚下软软的，非常舒服。走廊东面通往书房。" );
	

/*****************************************************
  set("exits",([
      "east" : __DIR__"men2",
      "west" : __DIR__"changl9",
  ]));
********************************************/
};


ROOM_END;
