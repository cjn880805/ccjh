//changl3.h

//Sample for room: ���ջ���3
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changl3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ջ���3");


	add_door("���ջ���2", "���ջ���2", "���ջ���3");
	add_door("���ջ���4", "���ջ���4", "���ջ���3");
	add_door("�������", "�������", "���ջ���3");
	add_door("���ջ���10", "���ջ���10", "���ջ���3");


	

/*****************************************************
   set("exits",([
      "east" : __DIR__"restroom",
      "west" : __DIR__"changl2",
      "north" : __DIR__"changl10",
      "south" : __DIR__"changl4",
  ]));
********************************************/
};


ROOM_END;
