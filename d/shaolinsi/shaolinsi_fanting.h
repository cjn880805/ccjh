//fanting.h

//Sample for room: ի��
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_fanting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ի��");

	CBox * box = Add_Box();
	box->add_object("qingshui_hulu", 1);	
	box->set_name( "����");	

	add_door("�����³���", "�����³���", "������ի��");
	add_door("���������޳�", "���������޳�", "������ի��");




/*****************************************************
	set("exits", ([
		"east" : __DIR__"guangchang3",
		"north" : __DIR__"fanting1",
	]));
	set("objects",([
		__DIR__"obj/qingshui-hulu" : 1,
		names[random(sizeof(names))]: 1,
		names[random(sizeof(names))]: 1,		
	]));
//	
********************************************/
};


ROOM_END;
