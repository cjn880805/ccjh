//nanmen.h

//Sample for room: ��������
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRJiaXing_nanmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");
	
	add_npc("pub_playboy");  // add by zdn 2001-07-14
	add_npc("pub_liufeiyan");

	set("resident", "����");

	add_door("���˳�", "���˳�", "��������");
	add_door("Ȫ��ɽ·2", "Ȫ��ɽ·2", "��������");
	add_door("�һ���", "�һ���", "��������");


	

/*****************************************************
	set("long", @LONG
�����Ǽ��˵����š���Χ����ï�ܵ����֡������������
���Ͽ��븣�������Ͼ��Ǻų����õĺ��ݳ��ˡ�
LONG );
	set("exits", ([
                "north" : __DIR__"jiaxing",
                "east" : __DIR__"tieqiang",
		"south" : __DIR__"qzroad4",
		"southeast": "/d/hangzhou/road1",
	]));
 ********************************************/
};


RESIDENT_END;




