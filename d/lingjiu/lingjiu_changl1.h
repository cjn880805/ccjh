//changl1.h

//Sample for room: ���ջ���1
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changl1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ջ���1");


	add_door("���ջ���5", "���ջ���5", "���ջ���1");
	add_door("���ջ�԰", "���ջ�԰", "���ջ���1");


	

/*****************************************************
  set("exits",([
      "west" : __DIR__"changl5",
      "east" : __DIR__"huayuan",
     ]));
********************************************/
};


ROOM_END;
