//xinluofang.h

//Sample for room: ���޷�
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRXiangYang_xinluofang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���޷�");

	//add npcs into the room
	add_npc("pub_gaoli");/////////////////////////////
				

	add_door("��������", "��������", "�������޷�");

	set("long", "���޷�������˼���Ǹ�������ס�ĵط���������ʵ���������Ѿ������������������Ӧ�ý����������ġ����Ǵ���Ѿ�ϰ���ˣ����Ǳ㻹��ô�С�����ס�����������ˣ�Ҳ��Щ������ʹ����������·����������Ҳס���������ĸ����������кܶ�ܺõĻ����Ҷ�ϲ��������������ͷǳ��������ˡ�" );
/*****************************************************
	set("exits", ([
		"south" : __DIR__"northroad1",
	]));
	set("objects", ([
		__DIR__"npc/gaoli" : 1,
	]));
********************************************/
};


ROOM_END;
