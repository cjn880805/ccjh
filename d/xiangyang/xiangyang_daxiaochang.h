//daxiaochang.h

//Sample for room: ��У��
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_daxiaochang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��У��");


//	add_door("��������", "��������", "������У��");

	set("outdoors", "xiangyang");
	
/*****************************************************
	set("exits", ([
		"north" : __DIR__"westjie3",
	]));
********************************************/
};


ROOM_END;
