//changl10.h

//Sample for room: ���ջ���10
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changl10);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ջ���10");

	add_npc("pub_yejun");
	add_door("���ջ���3", "���ջ���3", "���ջ���10");
	add_door("���ջ���13", "���ջ���13", "���ջ���10");
	add_door("���������", "���������", "���ջ���10");
	add_door("���ջ���14", "���ջ���14", "���ջ���10");


	

/*****************************************************
  set("exits",([
      "east" : __DIR__"changl14",
      "west" : __DIR__"changl13",
      "south" : __DIR__"changl3",
      "north" : __DIR__"caifeng",
  ]));
********************************************/
};


ROOM_END;
