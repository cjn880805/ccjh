//rjqmen.h
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_rjqmen);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "��������");

	add_door("��΢��", "������΢��", "��������");
	add_door("��΢��", "������΢��", "��������");

    

/*****************************************************
	set("exits", ([
		"enter" : __DIR__"rjqyuan",
		"east" : __DIR__"torjq3",
	]));
********************************************/

};



ROOM_END;
