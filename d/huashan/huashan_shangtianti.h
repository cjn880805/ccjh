//shangtianti.h

//Sample for room: ��ɽ������
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_shangtianti);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ������");
	
	add_npc("huashan_linghu");      //add by zdn 2001-07-20


	add_door("��ɽ�����", "��ɽ�����", "��ɽ������");
	add_door("��ɽ������", "��ɽ������", "��ɽ������");
	add_door("��ɽ������", "��ɽ������", "��ɽ������");

	set("long", "������ɽ������һ������������һƬ�����أ������Ǹ������Ƶ��ͱڣ��м�һ����С��������һ�򵱹أ����Ī����");  
    
 
/*****************************************************
        set("exits", ([  
           "southup"   : __DIR__"jinsuo",
           "northdown" : __DIR__"husun",
           "westup"    : __DIR__"canglong",
        ]));
********************************************/
};


ROOM_END;
