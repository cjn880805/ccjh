//datiewu.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXiaoYao_datiewu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ң�ִ�����");

	CBox * box = Add_Box();
	box->add_object("blade_book", 1);	
	box->set_name( "����");	

	add_item("xiaohuolu");

	add_door("��ң��С��3", "��ң��С��3", "��ң�ִ�����");

	set("long", "�������������һ��Сʯ�ݣ������Ǵ�������ģ��������и����¯���̵��أ����л���һ��ʯ�����������һЩ�Ѿ�����õı�����");
	

/*****************************************************
	set("exits", ([
		"south" : __DIR__"xiaodao2",
	]));
	set("objects", ([
	       __DIR__"obj/blade": 2,
	]));
********************************************/
};


ROOM_END;
