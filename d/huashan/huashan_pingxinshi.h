//pingxinshi.h

//Sample for room: ��ɽƽ��ʯ
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_pingxinshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽƽ��ʯ");

	add_npc("huashan_cheng_buyou");

	add_door("��ɽ�ٳ�Ͽ", "��ɽ�ٳ�Ͽ", "��ɽƽ��ʯ");
	add_door("��ɽ�Ͼ���", "��ɽ�Ͼ���", "��ɽƽ��ʯ");

	set("long", "�ٳ�Ͽ��ͷ����������������ϣ��м������ʯ��ǰ��һ����С�����ʯ�����֡����˻�����ʯ�Ͽ��С�ƽ��ʯ�����֣�ʾ�������վ��Ѿ���ȥ���ѽ���ƽ��֮;�ˡ���ʱ��������һ�档");  
    
 
/*****************************************************
        set("exits", ([ 
            "westdown" : __DIR__"baichi",
            "eastup"   : __DIR__"laojun",
        ]));
********************************************/
};


ROOM_END;
