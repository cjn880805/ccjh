//yaofang.h

//Sample for room: ҩ��
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWanJie_yaofang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ҩ��");

	CBox * box = Add_Box();
	box->add_object("coin", 100);	
	box->set_name( "����");	

	add_door("��ٹ�С��", "��ٹ�С��", "��ٹ�ҩ��");


/*****************************************************
        set("exits", ([ 
            "south" : __DIR__"right_room",
        ]));
        set("item_desc", ([ 
            "����" : "�����ϰ�����ҩƿ��\n",
        ]));
        set("objects", ([
            __DIR__"obj/mortar" : 1,
        ]));
*****************************************************/
};


ROOM_END;
