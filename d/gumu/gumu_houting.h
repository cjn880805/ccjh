//houting.h

//Sample for room: ��Ĺ����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_houting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ĺ����");

	add_npc("zm_gumu");

	add_door("��Ĺ����", "��Ĺ����", "��Ĺ����");

    set("long","�����ǹ�Ĺ�ĺ������ܷ������ʵʵ��û��һ˿�ķ�϶���ڻ谵�ĵƹ��£��㷢��ǽ��������һ���� (picture)���ƺ���һ�������Ф�����������룬�ڷ��ż��߹ײ�(coffin)������ֻ��һ�߹ײĵĹװ�û�к��ϣ��ײ��к���տ���Ҳ��" );
    set("getbook",1);

/*****************************************************
        set("exits", ([
                "north" : __DIR__"zhengting",
        ]));

        set("item_desc", ([
        "picture": "������һ�������ʿ�ı�Ӱ��������ʲô��ò��������һ��ָ�죬��
�����š�"+MAG"��������"NOR+"���������֡�\n",
        "coffin": "�ú���ʯ�����ɵĹײģ��װ���Ϻ󣬾�û��һ˿�ķ�϶�ˡ�\n"
        ]) );
********************************************/
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
