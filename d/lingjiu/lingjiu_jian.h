//jian.h

//Sample for room: ���հ��ɽ�
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_jian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���հ��ɽ�");

	add_npc("lingjiu_liu");

	add_door("����ʧ����", "����ʧ����", "���հ��ɽ�");
	add_door("�����ɳ���", "�����ɳ���", "���հ��ɽ�");


/*****************************************************
  set("outdoors", "lingjiu");
  set("exits",([
      "southdown" : __DIR__"yan",
  ]));
  set("objects",([
      __DIR__"npc/yupopo" : 1,
  ]));
  set("item_desc",([
      "bei" : "�����չ����صأ�����������\n" ,
      "tiesuo" : "����ͨ������ġ������š�����Ҳ������߹�(zou)ȥ��\n" ,
  ]));
********************************************/
};


ROOM_END;
