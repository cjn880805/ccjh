//chufang.h

//Sample for room: ����ź���
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ź���");
	add_npc("lingjiu_lu");
	
	CBox * box = Add_Box();
	box->add_object("suanmei", 1);	
	box->set_name( "����");		

	add_door("���ջ���6", "���ջ���6", "����ź���");

	set("long", "���Ǽ������Ũ���ķ�����ζһ�����������ı��ӣ� ��·����������������������������ܲ�֪��Դ��ԭ������Ķ������֡�" );

/*****************************************************
  set("exits",([
      "east" : __DIR__"changl6",
  ]));
  set("objects",([
      __DIR__"npc/lisao" : 1,
      __DIR__"obj/suanmei" : 2,
      __DIR__"obj/gao" : 2,  
  ]));
********************************************/
};


ROOM_END;
