//changl7.h

//Sample for room: ���ջ���7
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_changl7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ջ���7");


	add_door("���ջ���15", "���ջ���15", "���ջ���7");
	add_door("���ջ���6", "���ջ���6", "���ջ���7");

	set("long", " ����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ����������������ͼ�����������ɣ�����ʤ�ա��ذ岻֪����ʲô�������ģ��������������Ϣ����ֻ�е���������ģ��ǳ����������ͨ�������" );
	

/*****************************************************
  set("exits",([
      "east" : __DIR__"changl15",
      "west" : __DIR__"changl6",
  ]));
********************************************/
};


ROOM_END;
