//dmyuan2.h

//Sample for room: ��ĦԺ��¥")
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_dmyuan2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ĦԺ��¥");

	add_npc("shaolin_xuan_bei");

	CBox * box = Add_Box();
	box->add_object("xisuijing", 1);	
	box->set_name( "���");
	
	add_door("�����´�ĦԺ", "�����´�ĦԺ", "�����´�ĦԺ��¥");


/*****************************************************
	set("exits", ([
		"down" : __DIR__"dmyuan",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/xuan-bei" : 1,
		"/clone/book/xisuijing" : 1,
		__DIR__"npc/xiao-bei" : 1,
	]));
********************************************/
};


ROOM_END;
