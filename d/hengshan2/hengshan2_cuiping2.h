//cuiping2.h

//Sample for room: ��ɽ����ɽ��2
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_cuiping2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ����ɽ��2");
	
	add_npc("pub_punk");      //add by zdn 2001-07-20


	add_door("��ɽ����ɽ��1", "��ɽ����ɽ��1", "��ɽ����ɽ��2");
	add_door("��ɽ������", "��ɽ������", "��ɽ����ɽ��2");

    set("long","�����ڴ���ɽ���ϣ���ľ���죬�Ѽ����ա�ɽ�־��ף������������ã�һ�г��׾���ϴ����ɽ���о�������ɽ��ɫ�� " );
    

/*****************************************************
	set("exits", ([
		"eastup"   : __DIR__"xuankong1",
		"eastdown" : __DIR__"cuiping1",
	]));
********************************************/
};


ROOM_END;
