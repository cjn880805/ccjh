//dangpu.h

//Sample for room: ����
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_dangpu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	//add npcs into the room
	add_npc("pub_huangyu");/////////////////////////
	add_npc("xiangyang_qiuhang");        //add by zdn 2001-07-20
			

	add_door("��������", "��������", "��������");

	set("long", "���Ǽ�Զ�������ĵ��̣�����������棬һ��д�š��񺽵��̡��ĸ����ֵĺ��ң������߳߸ߵ���̴ľ�Ĺ�̨��ĥ�ù�����ˣ���һ��ȥ����һ��ѹ�ֺͱ���ĸо�����̨����ϰ���ͷҲ��̧��ֻ�˲��������̣���̨�Ϸ�����һ�黨ľ����(paizi) ���ݽַ���˵���浱�̸��ļۻ�����������ҴӲ��ʻ������������˻���ʲô���գ���������ܲ���" );
	set("no_fight", 1);
	set("no_beg", 1);
/*****************************************************
	set("item_desc", ([
		"paizi" : "������Ը���Ų���Ƿ��\n",
	]));
	set("exits", ([
		"north" : __DIR__"westjie1",
	]));
	set("objects", ([
		__DIR__"npc/qiuhang" : 1,
	]));
********************************************/
};


ROOM_END;
