//bingying.h

//Sample for room: ��Ӫ
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRYangZhou_bingying);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ӫ");

	//add npcs into the room
	add_npc("pub_shi");
	add_npc("pub_wujiang");
	add_npc("pub_bing");
	
	add_door("��������", "��������", "���ݱ�Ӫ");

	set("long", "�����Ǳ�Ӫ���������鵽�����ǹٱ����е����佫��ָ�����жӲ������еĶ������������е����š�����������Ϣ����ǽ��������˧��������ɫ��Ѱ�������ܡ����������������ȫ�������Χ�˹��������ƿ�����̫��ϱ���һ����(men)��" );
/*****************************************************
	set("item_desc", ([
		"men" : "����һ�ȼ�������š�\n",
	]));
	set("exits", ([
		"south" : __DIR__"bingqiku",
		"north" : __DIR__"bingyindamen",
	]));
	set("objects", ([
		__DIR__"npc/shi" : 1,
		__DIR__"npc/wujiang" : 2,
		__DIR__"npc/bing" : 2,
	]));
//	
	create_door("south", "����", "north", DOOR_CLOSED);
********************************************/
};


ROOM_END;
