//xianchou.h

//Sample for room: �����ɳ���
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_xianchou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ɳ���");

	add_npc("lingjiu_feng");
	add_npc("helpnpc015");

	add_door("���հ��ɽ�", "���հ��ɽ�", "�����ɳ���");
	add_door("������ʯ���1", "������ʯ���1", "�����ɳ���");

	set("long", "����Ϳ쵽��翷�����ˣ�Խ�����ߣ�ɽ��Խ�ߣ�����������ߵİ���������Ũ������������ɽ��·������ɽ��û�߼�����������ǰ����һ��ʯ�������顺�ɳ��š��������֣�������ɽ֮�����ɡ�" );
	

/*****************************************************
  set("outdoors", "lingjiu");
  set("exits",([
      "eastup" : __DIR__"dadao1",
      "southdown" : __DIR__"jian",
  ]));
********************************************/
};


ROOM_END;
