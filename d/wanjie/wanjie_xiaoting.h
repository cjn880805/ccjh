//xiaoting.h

//Sample for room: С��
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWanJie_xiaoting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "С��");

	add_npc("pub_xier");	//add by lanwood 2001-03-18

	add_door("��ٹȲݵ�", "��ٹȲݵ�", "��ٹ�С��");

	add_door("��ٹ�����", "��ٹ�����", "��ٹ�С��");
	add_door("��ٹ�ʯ��", "��ٹ�ʯ��", "��ٹ�С��");
	add_door("��ٹ�ҩ��", "��ٹ�ҩ��", "��ٹ�С��");


/*****************************************************
        set("exits", ([ 
            "south" : __DIR__"grassland",
            "north" : __DIR__"hall",
        ]));
        set("objects", ([
            __DIR__"npc/gan" : 1,
        ]));
*****************************************************/
};


ROOM_END;
