//changlang2.h

//Sample for room: ���ջ���2
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changlang2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ջ���2");


	add_door("���ջ���3", "���ջ���3", "���ջ���2");
	add_door("���ջ�԰", "���ջ�԰", "���ջ���2");


	

/*****************************************************
  set("exits",([
      "east" : __DIR__"changl3",
      "west" : __DIR__"huayuan",
  ]));
********************************************/
};


ROOM_END;
