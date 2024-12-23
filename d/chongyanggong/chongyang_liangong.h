//liangong.h

//Sample for room:  ������������
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_liangong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������������");

	add_npc("quanzhen_li");

	add_door("������", "������", "������������");
	add_door("����������", "����������", "������������");

	set("long", "������ȫ��̵��������ķ��䡣����������״�������أ�ǰխ�����Ϊ���Σ����߰�Բ������ȴ��������״��ԭ������ȫ��̶��е������ң�ǰխ���ƣ����ʹָ����Բ�н������Ƿ��ڡ������������ż��������õ�ľ�ˣ����ż���ɳ��(bag)��ֽ��(paper)��");

/******************************************************************************
         set("exits", ([
                "south" : __DIR__"houtang2",
                "north" : __DIR__"chanfang2",
        ]));
        set("item_desc", ([
                "paper" : "����һ������ţƤֽ�ᣬ����������ǽ�ϡ��������
�������Ʒ��ģ����(da paper)���Կ���\n",
                "bag"   : "����һ����ɳ�����������ǳ���ʵ��������������ָ��
�ģ�����Դ��(chi bag)����\n",
        ]));
        set("objects", ([
                __DIR__"npc/mu-ren" : 5,
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