//jinlongxia.h

//Sample for room: ��ɽ����Ͽ
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_jinlongxia);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ����Ͽ");
	
	add_npc("hengshan_tian");      //add by zdn 2001-07-20


	add_door("��ɽ������1", "��ɽ������1", "��ɽ����Ͽ");

	add_door("���������6", "���������6", "��ɽ����Ͽ");

    set("long","����Ͽ�ֳ��������ǽ����ɽ����ڡ���ɽһ��̫��ɽ������������������еı�����������֮Ϊ '����С����' ������ب���������һ���н��еĶ��У�������Ϊ '��ɽ����' ����� '̩ɽ����' ��'��ɽ����'��'��ɽ����'��'��ɽ���'��" );
	set("outdoors", "hengshan");

/*****************************************************
	set("exits", ([
		"southeast"  : __DIR__"cuipinggu1",
		"northeast"  : "/d/city2/road6",
	]));
	set("objects", ([
		__DIR__"npc/jing" : 1,
	]));
********************************************/
};


ROOM_END;
