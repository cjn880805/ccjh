//changl9.h

//Sample for room: ���ջ���9
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changl9);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ջ���9");


	add_door("���ջ���5", "���ջ���5", "���ջ���9");
	add_door("���ջ���11", "���ջ���11", "���ջ���9");
	add_door("���ջ���12", "���ջ���12", "���ջ���9");

	set("long", "����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ����������������ͼ�����������ɣ�����ʤ�ա��ذ岻֪����ʲô�������ģ��������������Ϣ����ֻ�е���������ģ��ǳ������" );
	

/*****************************************************
  set("exits",([
      "east" : __DIR__"changl12",
      "west" : __DIR__"changl11",
      "south" : __DIR__"changl5",
  ]));
********************************************/
};


ROOM_END;
