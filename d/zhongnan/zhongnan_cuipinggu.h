//cuipinggu.h

//Sample for room: ����ɽ������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_cuipinggu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ������");
	
	add_npc("pub_man");
	add_npc("pub_daoke");   //2001-07-10  zdn add

	add_door("����ɽɽ·3", "����ɽɽ·3", "����ɽ������");
	add_door("����ɽ������", "����ɽ������", "����ɽ������");

    set("long","�����ǰ��һ����������Ĵ�ɽ�ڣ�ɽ���������дж�������һ�ۿ���ȥ��ȫ��һƬ����ɫ������Ǵ˵����д����ȵ�������������������ϣ��͵�������ɽ�ϵİ������ˡ�" );
    

/*****************************************************
        set("exits", ([
                "southdown" : __DIR__"shanlu3",
                "northup" : __DIR__"baishulin1",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
