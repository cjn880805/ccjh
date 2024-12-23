//baiyunan.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHengShan2_baiyunan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	//add npcs into the room

	add_npc("hengshan_zhengyue");
	add_npc("hengshan_yiqing");

				
	//add exits for room
	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("��ɽ���Է�㳡", "��ɽ���Է�㳡", "��ɽ������");

    set("long","������Ǻ�ɽ�������˵ľ��������ڹ�����¹�������������һ�����ţ��ı���Ȼ����ɽ�����𽭺���û�뵽���־�Ȼ����һ����˹��" );

/*****************************************************
        set("exits", ([  
           "south"  : __DIR__"square",
        ]));
	set("objects", ([
		__DIR__"npc/xian" : 1,
		__DIR__"npc/zheng" : 1,
		__DIR__"npc/qin" : 1,
	]));
********************************************/
};


ROOM_END;
