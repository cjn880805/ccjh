//yan.h

//Sample for room: ����ʧ����
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_yan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ʧ����");

	add_npc("lingjiu_zhou");
	
	add_door("���նϻ���", "���նϻ���", "����ʧ����");
	add_door("���հ��ɽ�", "���հ��ɽ�", "����ʧ����");

	set("long", "����ͨ�����չ����ıؾ�֮·��ɽ����һ����ӥ�ͻ���ľ��ҽضϣ����ҹ�ɼ��ˣ�ֻ���м������һ��խխ��ʯ��ͨ��ɽ������һͷ����С�����������̤����ȥ�����룺���ܹ�ȥ�ɡ�" );
	

/*****************************************************
  set("outdoors", "lingjiu");
  set("exits",([
      "northup"  : __DIR__"jian",
      "eastdown" : __DIR__"ya",
  ]));
********************************************/
};


ROOM_END;
