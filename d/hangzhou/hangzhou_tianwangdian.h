//tianwangdian.h

//Sample for room: ����������
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_tianwangdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");
	
	add_npc("pub_youke");       /// add by zdn 2001-07-14


	add_door("����������", "����������", "����������");
	add_door("���ݴ��۱���1", "���ݴ��۱���1", "����������");

	set("long","�߽���ֻ����������̻��¶�������շ��������Ĵ���������������̬���ϵ�Τ��������������������Ǵ��۱��" );
	

/*****************************************************
        set("exits", ([
                "out"       : __DIR__"lingyinsi",
                "north"     : __DIR__"dxbaodian1",
        ]));
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
