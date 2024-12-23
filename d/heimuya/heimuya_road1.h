//road1.h

//Sample for room: ��ʯ��
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_road1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ʯ��");

	//add npcs into the room
	add_npc("animal_dushe");
	add_npc("pub_haoren");

	add_door("��ľ���ּ�С��", "��ľ���ּ�С��", "��ľ����ʯ��");

	add_door("��ľ�»���·2", "��ľ�»���·2", "��ľ����ʯ��");
	add_door("��ľ�»���·4", "��ľ�»���·4", "��ľ����ʯ��");

	set("long", "����һ����ʯ�����Сɽ�ڣ��򶫱���ͨ��ƽ���ݵ�С·����˵ǰ��������Ұ�޳�û�����ɾ�����");
    

/*****************************************************
        set("outdoors", "heimuya");
        set("exits", ([
            "northeast" : __DIR__"road2",
            "southwest" : __DIR__"road4",
            "west"  : __DIR__"linjxd1",
            "east"  : __DIR__"dating4",
        ]));
********************************************/
};


ROOM_END;
