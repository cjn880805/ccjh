//xiaoneishi.h

//Sample for room: С������
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_xiaoneishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "С������");

	//add npcs into the room
	add_npc("heimuya_dongfang");

	add_door("��ľ��С��", "��ľ��С��", "��ľ��С������");

	set("long", "������С�����ҡ���ʰ�þ�ϸ�쳣����һ��ȥ���ͷ��ִ�������һ��������޵��ˡ�����Ҳ�����̧ͷ���㷢������Ȼ�Ǹ����ˣ�����ִ��һö�廨�룡");

/*****************************************************
        set("exits", ([
             "west" : __DIR__"xiaoshe",
        ]));
        set("objects", ([
             __DIR__"npc/dongfang": 1,
        ]));
//                              
********************************************/
};


ROOM_END;
