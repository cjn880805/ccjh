//motianya.h

//Sample for room: ���͵�Ħ����
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_motianya);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵�Ħ����");
	
	add_npc("xiakedao_daoseng");        //add by zdn 2001-07-20

	add_door("���͵��µ�", "���͵��µ�", "���͵�Ħ����");
	add_door("���͵�ľ��", "���͵�ľ��", "���͵�Ħ����");

/*****************************************************
        set("outdoors", "xiakedao");
        set("exits",([
                "east" : __DIR__"mtxiaowu",
                "down" : __DIR__"mtyadi",
        ]));
        set("item_desc",([
                "bei" : "   ��Ħ���¡�  \n�ޡ�������߽��룡\n",
        ]));
        set("objects",([
                __DIR__"npc/xieyan" : 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp