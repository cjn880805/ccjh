//changlang12.h

//Sample for room: ���ջ���12
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changlang12);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ջ���12");


	add_door("���ջ���9", "���ջ���9", "���ջ���12");
	add_door("�����鷿����", "�����鷿����", "���ջ���12");

	set("long", "����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ����������������ͼ�����������ɣ�����ʤ�ա��ذ岻֪����ʲô�������ģ��������������Ϣ����ֻ�е���������ģ��ǳ���������ȶ���ͨ���鷿��" );
	

/*****************************************************
  set("exits",([
      "east" : __DIR__"men2",
      "west" : __DIR__"changl9",
  ]));
********************************************/
};


ROOM_END;
