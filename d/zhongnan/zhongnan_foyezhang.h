//foyezhang.h

//Sample for room: ����ɽ��ү��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_foyezhang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ��ү��");

	//add npcs into the room 2001-07-10  zdn add
	add_npc("pub_huanu");
	add_npc("pub_youke");

	add_door("����ɽ���ԭ", "����ɽ���ԭ", "����ɽ��ү��");

	set("long","ֻ���˴���Ϊ��������һ����Ժ����ַ���������ɴ�ػ��ƣ���Ժ�Ķ�ԫ�����ϡ�ɼ����ƺ�����һ����С����Ժ��������һƬƽԭ" );

/*****************************************************
        set("exits", ([
                "east"  : __DIR__"shenheyuan",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
