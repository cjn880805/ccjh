//baichi.h

//Sample for room: ��ɽ�ٳ�Ͽ
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_baichi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�ٳ�Ͽ");


	add_door("��ɽǧ�ߴ�", "��ɽǧ�ߴ�", "��ɽ�ٳ�Ͽ");
	add_door("��ɽƽ��ʯ", "��ɽƽ��ʯ", "��ɽ�ٳ�Ͽ");

	set("long", "�߹�ǧ�ߴ���ǰ���ּ���һҪ���İٳ�Ͽ���ٳ�Ͽ����ǧ�ߴ����վ�������ʮ�ֶ��ͣ��ұ������������������������ٳ�Ͽ�ֳư����£���һ������ǧ������¡��µ׵��������͵���ڴ�Լ�ٳߣ�����������");  
    
 
/*****************************************************
        set("exits", ([  
            "northdown" : __DIR__"qianchi",
            "eastup"    : __DIR__"pingxinshi",
        ]));

********************************************/
};


ROOM_END;
