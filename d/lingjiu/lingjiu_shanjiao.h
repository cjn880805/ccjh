//shanjiao.h

//Sample for room: ������翷�ɽ��
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_shanjiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������翷�ɽ��");
	
	add_npc("pub_guest");           //add by zdn 201-07-17


	add_door("���նϻ���", "���նϻ���", "������翷�ɽ��");
	add_door("������ɽɽ·2", "������ɽɽ·2", "������翷�ɽ��");

/*****************************************************
    set("outdoors", "lingjiu");
	set("exits", ([
		"westup" : __DIR__"ya",
		"southdown" : "/d/xingxiu/tianroad2"
        ]));
	set("objects",([
		__DIR__"npc/jiuyi" : 1,
       	]));
********************************************/
};


ROOM_END;
