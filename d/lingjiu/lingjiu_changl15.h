//changl15.h

//Sample for room: ���ջ���15
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changl15);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ջ���15");


	add_door("���ջ�԰", "���ջ�԰", "���ջ���15");
	add_door("���ն�����", "���ն�����", "���ջ���15");
	add_door("���ջ���7", "���ջ���7", "���ջ���15");
	add_door("���ջ���8", "���ջ���8", "���ջ���15");

	

/*****************************************************
  set("exits",([
      "west" : __DIR__"changl7",
      "east" : __DIR__"changl8",
      "south" : __DIR__"dating",
      "north" : __DIR__"huayuan",
  ]));
********************************************/
};


ROOM_END;
