//changl6.h

//Sample for room: ���ջ���6
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changl6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ջ���6");


	add_door("���ջ���7", "���ջ���7", "���ջ���6");
	add_door("���ջ���5", "���ջ���5", "���ջ���6");
	add_door("����ź���", "����ź���", "���ջ���6");


	

/*****************************************************
  set("exits",([
      "north" : __DIR__"changl5",
      "west" : __DIR__"chufang",
      "east" : __DIR__"changl7",
  ]));
********************************************/
};


ROOM_END;
