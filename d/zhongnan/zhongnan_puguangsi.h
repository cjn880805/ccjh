//puguangsi.h

//Sample for room: ����ɽ�չ���
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_puguangsi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ�չ���");

	//add npcs into the room  2001-07-10 zdn add
	add_npc("pub_playboy");
	add_npc("pub_liumang");

	add_door("����ɽ��·13", "����ɽ��·13", "����ɽ�չ���");

	set("long","����һ��λ�����ɽ�µ�С�������ź��д�� ���չ��¡� �������֡���춴�����������ɽ�ıؾ�֮·����������οͶ����ڴ������Ϣ��Ҳ��˴˴����Ҳ��Ϊ��ʢ����ǰ�ļ��������£�����һ��ʯ��(shibei)�������챻��Χ�ĳ��ݸ������ˡ���������һ��С·." );

/*****************************************************
        set("exits", ([
                "west" : __DIR__"shanlu13",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
