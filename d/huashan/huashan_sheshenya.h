//sheshenya.h

//Sample for room: ��ɽ������
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_sheshenya);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ������");

	//add npcs into the room
	add_npc("pub3_gongpingziw");
	add_npc("huashan_mei");

	add_door("��ɽ������", "��ɽ������", "��ɽ������");

	set("long", "����һ�μ�խ���յ�ɽ�£�����������ƣ�����Ԩ���޵ס��粻С�ģ�һʧ�����ȥ��ֻ������ͷ���Ҳ����������и�Сɽ��(dong)��");  
    
 
/*****************************************************
        set("exits", ([  
            "eastdown" : __DIR__"canglong",
            "west"     : "/d/xiaoyao/pubu",
        ]));
        set("item_desc", ([
            "dong" : "����������ʯ�ڵ�С�����ں����Ĳ�֪�ж��\n",
        ]));
        set("objects",([
                __DIR__"npc/referee" : 1,
        ]));
********************************************/
};


ROOM_END;
