//damen.h

//Sample for room:  �����´���
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_damen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����´���");



	add_door("����Ǻ�ʥ����", "����Ǻ�ʥ����", "�����´���");
				
	add_door("����������", "����������", "�����´���");

	set("long","�������������´���ǰ��ֻ�����ƻֺ�������������Ͽ���һ������( duilian )�����Ḳ�֣����е㲦����֮�⡣̧ͷ�����������һ���ľ���ң����⡰��ʥ�¡��������֣�������ɡ�������ʽ��������������Խй��ˣ�����֮Ϊ�������¡���");

/******************************************************************************
        set("outdoors", "tianlongsi");
        set("exits", ([
                "south" : __DIR__"talin",
                "north" : "/d/dali/hongsheng",
        ]));
	set("item_desc",([
		"duilian" : "\n    ������Ⱦ����Բ�ɡ�������Ե�������\n\n",
	]));	
        set("objects",([
                "/d/wudang/npc/guest" : 1,
        ]));
******************************************************************************/
};


ROOM_END;