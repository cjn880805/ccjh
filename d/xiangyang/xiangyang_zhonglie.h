//zhonglie.h

//Sample for room: ������
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_zhonglie);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");
	
	add_npc("xiangyang_ya");        //add by zdn 2001-07-20

	add_door("��������", "��������", "����������");

	set("long", "�����������ǵ���������ʮ������Ϊ������������������ʿ�ŹǶ����������ÿ���а����ĵĺú����ⶼ��������һ���һꡣ" );
	set("no_fight", 1);
	set("no_beg", 1);
	
/*****************************************************
	set("exits", ([
		"west" : __DIR__"eastroad2",
	]));
********************************************/
};


ROOM_END;
