//dangpu.h

//Sample for room: ����
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRYangZhou_dangpu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");


	add_door("���ݶ���", "���ݶ���", "���ݵ���");

	set("long", "����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������ǰ����̨�ϰ���һ������(paizi)����̨���������ϰ壬һ˫�������������´������㡣�ݽַ���˵���浱�̸��ļۻ�����������ҴӲ��ʻ������������˻���ʲô���գ���������ܲ���" );
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
/*****************************************************
	set("item_desc", ([
		"paizi" : "��ƽ����\n
sell        �� 
buy         ��
redeem      ��
value       ����
",
	]));
	set("objects", ([
		__DIR__"npc/tang" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"nandajie1",
		"up"   : __DIR__"xiaobaozhai",
	]));
********************************************/
};


ROOM_END;
