//dating.h

//Sample for room: ���ն�����
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_dating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ն�����");

	add_npc("lingjiu_xuzhu");
	add_npc("zm_lingjiu");
	add_npc("pub_xiangke");

	add_door("���ջ���15", "���ջ���15", "���ն�����");
	add_door("���ն���������", "���ն���������", "���ն�����");

	set("long", "����ǡ����չ���������������ȫ���Ծ�ʯ���ɣ�ʯ��֮�侹�ް���϶�����˳��档���ڴ������ĸ�ʯ������Ϊ��Ӳ�Ļ���ʯ���ơ�" );
	set("valid_startroom", 1);

/*****************************************************
        set("exits", ([
		"north" : __DIR__"changl15",
		"south" : __DIR__"damen",
        ]));
	set("objects",([
		CLASS_D("lingjiu")+"/xuzhu" : 1,
	]));
********************************************/
};


ROOM_END;




