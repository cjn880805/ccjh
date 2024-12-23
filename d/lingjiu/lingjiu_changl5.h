//changl5.h

//Sample for room: 灵鹫画廊5
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changl5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵鹫画廊5");


	add_door("灵鹫画廊6", "灵鹫画廊6", "灵鹫画廊5");
	add_door("灵鹫画廊1", "灵鹫画廊1", "灵鹫画廊5");
	add_door("灵鹫蓼风轩", "灵鹫蓼风轩", "灵鹫画廊5");
	add_door("灵鹫画廊9", "灵鹫画廊9", "灵鹫画廊5");

	set("long", "这是一条非常精美的长廊，柱子和栏杆是用华贵的紫檀木制成，上面雕饰着美丽的图画，画工精巧，美不胜收。地板不知是用什么材料做的，走在上面毫无声息，你只感到脚下软软的，非常舒服。走廊西面是兵器库。" );
	

/*****************************************************
  set("exits",([
      "east" : __DIR__"changl1",
      "west" : __DIR__"wuqiku",
      "north" : __DIR__"changl9",
      "south" : __DIR__"changl6",
  ]));
********************************************/
};


ROOM_END;
