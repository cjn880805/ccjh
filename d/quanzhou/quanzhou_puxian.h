//puxian.h

//Sample for room: Ȫ������ƽԭ
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_puxian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ȫ������ƽԭ");

	set("resident", "Ȫ��");
	
	add_npc("pub_xixiabing");         //add by zdn 2001-07-14

	add_door("Ȫ��ɽ·4", "Ȫ��ɽ·4", "Ȫ������ƽԭ");
	add_door("Ȫ��������", "Ȫ��������", "Ȫ������ƽԭ");

	
	
/*****************************************************
	set("exits", ([
		"north" : __DIR__"zhongzhou",
                "south" : "/d/quanzhou/beimen",
	]));
********************************************/
};


RESIDENT_END;
