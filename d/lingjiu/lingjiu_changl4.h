//changl4.h

//Sample for room: ���ջ���4
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changl4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ջ���4");


	add_door("���ջ���8", "���ջ���8", "���ջ���4");
	add_door("���ջ���3", "���ջ���3", "���ջ���4");
	add_door("����Ϸ���", "����Ϸ���", "���ջ���4");


	

/*****************************************************
  set("exits",([
      "north" : __DIR__"changl3",
      "east" : __DIR__"liangong",
      "west" : __DIR__"changl8",
  ]));
********************************************/
};


ROOM_END;
