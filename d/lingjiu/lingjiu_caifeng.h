//caifeng.h

//Sample for room: �����
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_caifeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����");

	add_npc("lingjiu_fu");

	add_door("���ջ���10", "���ջ���10", "���������");

	

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
