//yunmen.h

//Sample for room: ��ɽ����
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_yunmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ����");

	add_npc("zm_huashan");

	add_door("��ɽɯ��ƺ", "��ɽɯ��ƺ", "��ɽ����");
	add_door("��ɽ���ƺ", "��ɽ���ƺ", "��ɽ����");

	set("long", "��ɯ��ƺ���ǻ�ɽʮ���̡�ʮ���̵ľ������ǡ����š��ˡ�������š��ɾ����������µ�һ��ɽ����ʯ�̡�����֮�ڵ�С��ؾ������ƺ��");  
    
 
/*****************************************************
        set("exits", ([  
            "northdown" : __DIR__"shaluo",
            "southup" : __DIR__"qingke",
        ]));
********************************************/
};


ROOM_END;
