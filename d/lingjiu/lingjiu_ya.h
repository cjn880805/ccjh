//ya.h

//Sample for room: ���նϻ���
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_ya);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���նϻ���");

	add_npc("pub_qixianglian");
	add_door("����ʧ����", "����ʧ����", "���նϻ���");
	add_door("������翷�ɽ��", "������翷�ɽ��", "���նϻ���");

	set("long", "����ͨ��[���չ�]�ıؾ�֮·��һ��С���������۵�ͨ����翷嶥��·���Ҳ���һ�����͵�ɽ�£�һ��ɽ�紵�������ƺ����������洫�������Һţ�������һ�ݣ������ӿ�Ų��Ͻ��뿪���" );
	

/*****************************************************
  set("outdoors", "lingjiu");
  set("exits",([
      "westup"   : __DIR__"yan",
      "eastdown" : __DIR__"shanjiao",
  ]));
********************************************/
};


ROOM_END;
