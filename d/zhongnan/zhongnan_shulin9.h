//shulin9.h

//Sample for room: ����ɽ����9
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shulin9);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ����9");

	//add npcx into the room    2001-07-10 zdn add
	add_npc("pub_playboy");
	add_npc("pub_daoke");

	add_door("����ɽɽ��9", "����ɽɽ��9", "����ɽ����9");
	add_door("����ɽ������", "����ɽ������", "����ɽ����9");

	set("long","��λ�����ɽ���һ��Ƭ���֣�������Ϊï�ܡ�������䣬ֻ���ý���ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩��Ũ�ܵ�֦ͷ��Ͷ����¡�ż��Զ�������޺�����������һ�����ܸС����������ϸ���һ��С����" );

/*****************************************************
        set("exits", ([
                "north"      : __DIR__"baoziyan",
                "southdown"  : __DIR__"shanlu9",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
