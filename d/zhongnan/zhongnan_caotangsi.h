//caotangsi.h

//Sample for room: ����ɽ������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_caotangsi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ������");

	add_npc("pub_xiangke");   //2001-07-10 zdn add

	add_door("����ɽɽ·7", "����ɽɽ·7", "����ɽ������");

	set("long","����һ��λ�����ɽ��´��С�¡���Ժ�е�һ�ڹž�����Ϊ��������Ϊÿ���峿������һ�ɾ޴�������Ծ����������𣬲����ο����ˣ�����Ϊ��һ�۴��澰����������һ����᫵�ɽ����������һ����ɭɭ��С����" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "southup"     : __DIR__"shanlu7",
//                "north"       : __DIR__"",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
