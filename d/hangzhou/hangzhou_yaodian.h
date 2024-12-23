//yaodian.h

//Sample for room: ��������
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRhangzhou_yaodian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	//add npcs into the room
	add_npc("pub_huqingyu");

	add_door("������ʯ���14", "������ʯ���14", "���ݺ�������");

	set("long","����һ����������ҩ�ã���ǽ����һ����ҩ�񡣼��������æ���������µش�С������ץҩ��ҩ��ǰ����һ�����ӣ�����һλ��������Ϊ�˰�������������ҽ�����ࡣ    ��̨�Ϸ��߹�һ��������(paizi)." );
	
	set("no_fight", 1);
	set("no_beg","1");

/*****************************************************
         set("exits", ([
            "west"      : __DIR__"road14",
        ]));
        set("objects", ([
            __DIR__"npc/huqingyu" : 1,
        ]));
        set("item_desc", ([
            "paizi" :
	@TEXT
        �����ṩ���з���:
    �ȸ������һ�ٻƽ�, Ȼ��:
    ����:          name ����
    ��ʦ:          betrayer
	TEXT]));
//    �ָ��ഺ:      age
     
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
