//changl5.h

//Sample for room: ���ջ���5
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changl5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ջ���5");


	add_door("���ջ���6", "���ջ���6", "���ջ���5");
	add_door("���ջ���1", "���ջ���1", "���ջ���5");
	add_door("����ޤ����", "����ޤ����", "���ջ���5");
	add_door("���ջ���9", "���ջ���9", "���ջ���5");

	set("long", "����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ����������������ͼ�����������ɣ�����ʤ�ա��ذ岻֪����ʲô�������ģ��������������Ϣ����ֻ�е���������ģ��ǳ���������������Ǳ����⡣" );
	

/*****************************************************
  set("exits",([
      "east" : __DIR__"changl1",
      "west" : __DIR__"wuqiku",
      "north" : __DIR__"changl9",
      "south" : __DIR__"changl6",
  ]));
********************************************/
};


ROOM_END;
