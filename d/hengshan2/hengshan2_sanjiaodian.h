//sanjiaodian.h

//Sample for room: ��ɽ���̵�
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_sanjiaodian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ���̵�");
	
	add_npc("hengshan_xian");       //add by zdn 2001-07-20

	add_door("��ɽ������", "��ɽ������", "��ɽ���̵�");

    set("long","������ȫ����ߴ������̵Ҳ�����������ĵ������ż���ȫ����ÿ��������ʯ��ľ�����ܣ����� '��������'�� �Ž��漣�� " );
    

/*****************************************************
        set("exits", ([ 
           "down"   : __DIR__"xuankong1",
        ]));
********************************************/
};


ROOM_END;
