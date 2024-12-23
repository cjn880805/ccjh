//changl11.h

//Sample for room: 灵鹫画廊11
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changl11);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵鹫画廊11");


	add_door("灵鹫画廊9", "灵鹫画廊9", "灵鹫画廊11");
	add_door("灵鹫囚室大门", "灵鹫囚室大门", "灵鹫画廊11");

	set("long", "这是一条非常精美的长廊，柱子和栏杆是用华贵的紫檀木制成，上面雕饰着美丽的图画，画工精巧，美不胜收。地板不知是用什么材料做的，走在上面毫无声息，你只感到脚下软软的，非常舒服。西面是天山童姥关押犯人的地方，那里是本派禁地，没有童姥的许可，谁也不能进去。" );
	

/*****************************************************
  set("exits",([
      "east" : __DIR__"changl9",
      "west" : __DIR__"men1",
  ]));
********************************************/
};


ROOM_END;
