//nanxiangfang.h

//Sample for room: ���᷿
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGueiYun_nanxiangfang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���᷿");
	
	add_npc("pub_puren");         //add by zdn 2001-07-13
	add_npc("pub_liufuming"); 

	add_door("����ׯ", "����ׯ", "����ׯ���᷿");

	set("long","�����ǹ���ׯ�е��ӵ���Ϣ�ң����ż���ľ�������Զ���һ֧�߽ż��ӣ��������������һ��С���������ǻ�԰��" );
	set("sleep_room",1);
	

/*****************************************************
	set("exits", ([
		"west" : __DIR__"huating",
	]));
********************************************/
};


ROOM_END;
