//restroom.h

//Sample for room: �������
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_restroom);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������");


	add_door("���ջ���3", "���ջ���3", "�������");
	add_npc("lingjiu_cheng");

	
	set("sleep_room", 1);
	set("no_fight",1);
	set("no_steal",1);

/*****************************************************
   set("exits",([
      "west" : __DIR__"changl3",
  ]));
********************************************/
};


ROOM_END;
