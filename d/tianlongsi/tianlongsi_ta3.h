//ta3.h

//Sample for room:  ������������3
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_ta3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������������3");

	add_npc("pub_guest");
				
	add_door("����������", "����������", "������������3");

	set("long","������������֮һ�������Ƴ��������Զ����˵��Բ֮ҹ���ڴ���֮��Ĭ����Ը�����������ʥ��ָ���Խ���������Ը��");

/******************************************************************************
        set("outdoors", "tianlongsi");
        set("exits", ([
                "west" : __DIR__"talin",
        ]));
	set("objects",([
                "/d/wudang/npc/guest" : 2,
        ]));
******************************************************************************/
};


ROOM_END;
