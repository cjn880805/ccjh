//qinglong2.h

//Sample for room: Ȫ���������ͥ2
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRQuanZhou_qinglong2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ȫ���������ͥ2");
		
	add_door("Ȫ��������ǰͥ", "Ȫ��������ǰͥ", "Ȫ���������ͥ2");
	add_npc("quanzhou_lse");
	add_npc("quanzhou_shuimm");
	
	set("no_fight", 1);
/*****************************************************
	set("exits", ([
		"north" : __DIR__"qinglong",
	]));
********************************************/
};


ROOM_END;
