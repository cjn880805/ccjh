//yingbin.h

//Sample for room: ���͵�ӭ����
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRXiaKeDao_yingbin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵�ӭ����");
	
	add_npc("pub_lady3");         //add by zdn 2001-07-16


	add_door("���͵�����", "���͵�����", "���͵�ӭ����");
	add_door("���͵�С�Ե�", "���͵�С�Ե�", "���͵�ӭ����");
	add_door("���͵���Ϣ��", "���͵���Ϣ��", "���͵�ӭ����");
	add_door("���͵�ʯ��2", "���͵�ʯ��2", "���͵�ӭ����");

	

/*****************************************************
    set("exits", ([
    "east" : __DIR__"xiaodian",
    "west" : __DIR__"xiuxis",
	"south" : __DIR__"shidong2",
    "out" : __DIR__"dongmen",
	]));
********************************************/
};


ROOM_END;
