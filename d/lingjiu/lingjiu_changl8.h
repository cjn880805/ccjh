//changl8.h

//Sample for room: 灵鹫画廊8
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changl8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵鹫画廊8");


	add_door("灵鹫画廊15", "灵鹫画廊15", "灵鹫画廊8");
	add_door("灵鹫画廊4", "灵鹫画廊4", "灵鹫画廊8");

	set("long", "这是一条非常精美的长廊，柱子和栏杆是用华贵的紫檀木制成，上面雕饰着美丽的图画，画工精巧，美不胜收。地板不知是用什么材料做的，走在上面毫无声息，你只感到脚下软软的，非常舒服。西边通向大厅。" );
	

/*****************************************************
  set("exits",([
      "west" : __DIR__"changl15",
      "east" : __DIR__"changl4",
  ]));
********************************************/
};


ROOM_END;
