//shanzhuang.h

//Sample for room: �һ���ɽׯ����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_shanzhuang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�һ���ɽׯ����");

	//add npcs into the room
	add_npc("pub_shitong");/////////////////////////

	add_door("�һ���", "�һ���", "�һ���ɽׯ����");
	add_door("�һ�������", "�һ�������", "�һ���ɽׯ����");
	add_door("�һ���������", "�һ���������", "�һ���ɽׯ����");
	add_door("�һ���ɽׯ����", "�һ���ɽׯ����", "�һ���ɽׯ����");


/*****************************************************
 	set("outdoors", "taohua");
	set("exits", ([
		"south" : __DIR__"qianyuan",
		"north" : __DIR__"tingzi",
		"east"  : __DIR__"road1" ,       
	]));
	set("item_desc", ([
		"diao" : "һ�԰׵���չ�����ɡ�������һ����ĵ��ӣ�\n"
		"����(ride)�Ϳ��Էɵ���ԭ��\n",
	]));
        set("objects", ([
                __DIR__"npc/shitong" : 2,
        ]));
//	
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp