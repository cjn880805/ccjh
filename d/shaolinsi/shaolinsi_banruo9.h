//banruo9.h

//Sample for room: �����þŲ�
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_banruo9);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����þŲ�");

	add_npc("shaolin_cheng_shang");

	add_door("�����·���¥", "�����·���¥", "�����°����þŲ�");
	add_door("�����°����ð˲�", "�����°����ð˲�", "�����°����þŲ�");


/*****************************************************
	set("exits", ([
		"south" : __DIR__"banruo8",
		"north" : __DIR__"fzlou",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/cheng-xin" : 1,
	]));
//	
********************************************/
};


ROOM_END;
