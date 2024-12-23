//damen.h

//Sample for room:  ����������
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_damen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");

	add_npc("quanzhen_zhike");
	add_npc("zm_quanzhen");

	add_door("������", "������", "����������");
	add_door("����ɽ�̱�", "����ɽ�̱�", "����������");

	set("long", "�����ߵ�������ɽ��ɽ����ǰ�����ȫ��̵��ܲ��������ˡ�������ɽ�������ߵʹ������¡���Χ��ľɭɭ��������֣���ɫ���ġ���ǰ����ǽ���ߣ��������ݣ�����һ�����������������ߵ����ɼľ��ͭ����(gate)�����Ʋ��������Ϲ���һ����(bian)����ǰ��ʯ���Ϲ���һ������(duilian)��");

/******************************************************************************
        set("exits", ([
//                "east" : __DIR__"datang1",
                "westdown" : __DIR__"jiaobei",
        ]));
        set("outdoors", "quanzhen");
        set("item_desc", ([
            "gate":
"һ���������ߵ�"HIR"���ɼľ"HIY"��ͭ"NOR"���š�\n",
            "bian": HIG"
��������������������������
��������������������������
������ȫ���桡�š���  ����
��������������������������
��������������������������
\n"NOR,
            "duilian": BLINK+HIW"
һ������������������\n
�ط����취��������Ȼ
\n"NOR
        ]) );
        set("objects",([
                __DIR__"npc/zhike" : 1,
        ]));
******************************************************************************/

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp