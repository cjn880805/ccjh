//biguan.h

//Sample for room: �չ���
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_biguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�չ���");

	add_npc("lingjiu_tonglao");

	add_door("���ձչ��Ҵ���", "���ձչ��Ҵ���", "���ձչ���");


    set("sleep_room", 1);   

/*****************************************************
  set("exits",([
      "south" : __DIR__"men3",
  ]));
  set("objects",([
      CLASS_D("lingjiu")+"/tonglao" : 1,
  ]));
********************************************/
};


ROOM_END;
