//zhongzhou.h

//Sample for room: Ȫ��������
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_zhongzhou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ȫ��������");

	set("resident", "Ȫ��");
	
	add_npc("pub_yinjiuyou");
	add_npc("pub_cunfu");
	add_npc("pub_daoke");         //add by zdn 2001-07-14


	add_door("Ȫ������ƽԭ", "Ȫ������ƽԭ", "Ȫ��������");
	add_door("��������", "��������", "Ȫ��������");


	
	
/*****************************************************
	set("exits", ([
		"north" : __DIR__"nanmen",
                "south" : __DIR__"puxian",
	]));
********************************************/
};


RESIDENT_END;
