//hongchungqiao.h

//Sample for room: ���ݺ鴺��
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_hongchungqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݺ鴺��");
	
	add_npc("pub_jianke");
	add_npc("pub_oldwoman");    //add by zdn 2001-07-14


	add_door("������ʯ���4", "������ʯ���4", "���ݺ鴺��");
	add_door("������ʯ���3", "������ʯ���3", "���ݺ鴺��");

	set("long","��������Կ�������ʮ��֮һ��˫�����(scenery)�����ͨ�򱱱ߣ�����������ͨ�������µ�·��" );
    

/*****************************************************
        set("exits", ([
            "southwest"     : __DIR__"road3",
            "north"         : __DIR__"road4",
        ]));
        set("item_desc", ([
        "scenery" : 
"˫�壬�ϸ߷�������֮���ϣ����߷�������֮�������ϱ�ңң��ԣ�
ֻ��������գ�˫����������籡��֮�У���Ũ�򵭣�ʱ��ʱ�ޣ���
��Ʈ�ƣ���������������񷡣\n",
        ]));
        set("outdoors", "hangzhou");
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
