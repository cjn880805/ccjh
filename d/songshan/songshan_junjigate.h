//junjigate.h

//Sample for room: ������Ժɽ��
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRSongShan_junjigate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������Ժɽ��");
	
	add_npc("songshan_fei");         //add by zdn 2001-07-20


	add_door("��ɽɽ��6", "��ɽɽ��6", "��ɽ������Ժɽ��");
	add_door("��ɽ����̨", "��ɽ����̨", "��ɽ������Ժɽ��");

	set("long", "��ɽ�������ų� '����' �������Ǳ��Ƿ�̴��£���������ȴ�ѳ�Ϊ��ɽ�������˵�ס�������Ͽ��Ե������̨��" );
	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"shandao6",
		"northup"   : __DIR__"chanyuan",
		"westup"    : __DIR__"fengchantai",
	]));
	set("objects", ([
		__DIR__"npc/tang" : 1,
		__DIR__"npc/wan" : 1,
	]));
//	set("outdoors", "songshan");

********************************************/
};


ROOM_END;
