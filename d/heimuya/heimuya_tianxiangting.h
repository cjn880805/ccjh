//tianxiangting.h

//Sample for room: �����ô���
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_tianxiangting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ô���");

        add_npc("heimuya_xiang");              // add by zdn 2001-07-20


	add_door("��ľ��", "��ľ��", "��ľ�������ô���");
	add_door("��ľ��������", "��ľ��������", "��ľ�������ô���");

	set("long", "���ǡ�������̡��µ��Ĵ��ã������õĴ�����ԶԶ��ȥ�������죬���Ʋ�ʳ�˼��̻���������һ����(bian)��");
    

/*****************************************************
        set("exits", ([
                "west" : __DIR__"road1",
                "southup" : __DIR__"tian1",
        ]));
        set("item_desc", ([
            "bian": "����д����������---�������ʥ��ס�ء�\n",
       	]) );
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp