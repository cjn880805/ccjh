//guofugate.h

//Sample for room: ��������
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_guofugate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	//add npcs into the room
	add_npc("pub_jiading");
	add_npc("quanzhen_yelvqi");
	add_npc("pub_tuolei");        //add by zdn 2001-07-20

				

	add_door("��������", "��������", "������������");

/*****************************************************
        set("outdoors", "xiangyang");
	set("exits", ([
		"south" : __DIR__"westjie1",
		"north" : __DIR__"guofuyuan",
	]));
	set("objects", ([
		__DIR__"npc/yelvqi" : 1,
		__DIR__"npc/jiading" : 2,
	]));
********************************************/
};


ROOM_END;
