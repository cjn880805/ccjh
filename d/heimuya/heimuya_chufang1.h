//chufang1.h

//Sample for room: �����ó���
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_chufang1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ó���");
	
	add_npc("pub_shinu");

	CBox * box = Add_Box();
	box->add_object("tea_leaf", random(7) + 1);	
	box->set_name( "����");
		
	CBox * box1 = Add_Box();
	box1->add_object("sherou",random(6) + 1);	
	box1->set_name( "����");	

	add_door("��ľ�²ݵ�", "��ľ�²ݵ�", "��ľ�·����ó���");

	set("long", "������һ���������ּ�С���ϣ���������ɭɭ�����֡�һ�����Ƿ����õĳ�����һλ������Ů������Ц���������������֬��������ǽ������һ����Ŀ������(note)��");

/*****************************************************
  set("exits",([
      "east" : __DIR__"grass2",
  ]));
  set("item_desc",([
      "note" : "�����������Ǹ֣�һ�ٲ��Զ��ûš�\n",
  ]));

  set("objects",([
      __DIR__"npc/shinu" : 1,
      __DIR__"obj/tea" : random(6),
      __DIR__"obj/sherou"  : random(4),
  ]));
//  
********************************************/
};


ROOM_END;
