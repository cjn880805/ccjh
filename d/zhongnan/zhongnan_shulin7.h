//shulin7.h

//Sample for room: ����ɽ����7
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shulin7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ����7");

	//add npcs into the room  2001-07-10 zdn add
	add_npc("animal_dog");

	add_door("����ɽ���ԭ", "����ɽ���ԭ", "����ɽ����7");
	add_door("����ɽ������", "����ɽ������", "����ɽ����7");
	add_door("����ɽ�ڷﶴ", "����ɽ�ڷﶴ", "����ɽ����7");

	set("long","��λ�����ɽ���һ��Ƭ���֣�������Ϊï�ܡ�������䣬ֻ���ý���ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩��Ũ�ܵ�֦ͷ��Ͷ����¡�ż��Զ�������޺�����������һ�����ܸС��������ϡ��Ͷ�����һ��С����" );

/*****************************************************
        set("exits", ([
                "south"    : __DIR__"shenheyuan",
                "northup"  : __DIR__"juyan",
                "eastdown" : __DIR__"heifengdong",
        ]));
*******************************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
