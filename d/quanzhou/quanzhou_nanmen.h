//nanmen.h

//Sample for room: Ȫ������
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_nanmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ȫ������");

	set("resident", "Ȫ��");
	
	add_npc("pub_shiwei");      //add by zdn 2001-07-14


	add_door("Ȫ��", "Ȫ��", "Ȫ������");
	add_door("Ȫ������С��", "Ȫ������С��", "Ȫ������");

	set("long", "�������Ϸ���һ��Ȫ�ݵ����š���������һƬ��Ұ��" );
	
	
/*****************************************************
	set("exits", ([
//		"south" : __DIR__"bamboo",
                "north" : __DIR__"zhongxin",
	]));
********************************************/
};


RESIDENT_END;
