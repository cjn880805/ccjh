//jinliange.h

//Sample for room: ����ɽ������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_jinliange);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ������");
	
	add_npc("pub_daoke"); 
	add_npc("pub_huanu");   //2001-07-10 zdn add

	add_door("����ɽ��·11", "����ɽ��·11", "����ɽ������");
	add_door("����ɽɽ·10", "����ɽɽ·10", "����ɽ������");

	set("long","�������λ�����ɽɽ���䣬������Ϊ��Ҫ������������һ����ڴֵ�ӿȪ��Ȫˮ����͸�����������ˣ��ڵ�����Ϊ�������������ر����ˣ�ֻΪ��ȡ����ˮ���ݲ衣����ǰ��һ��ʯ��(shibei)������һ������ά��ʫ�����Ͽ�ȥ��һ��ɽ·����������һ�����ѵ�ɽ·��" );

/*****************************************************
        set("item_desc", ([
                "shibei"  : 
"

                �� �� �� ̫
                Ͷ Ұ �� ��
                �� �� �� ��  ��
                �� �� �� ��  ��
                �� �� �� ��  ɽ
                �� �� �� ��
                �� �� �� ��
                ˮ �� �� ɽ  ��
                �� �� �� ��  ά
                �� �� �� ��
                �� �� �� ��
                �� �� �� ��

",
        ]));

        set("outdoors", "gumu");
        set("exits", ([
                "westup"     : __DIR__"shanlu10",
                "southdown"  : __DIR__"shanlu11",
        ]));
********************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
