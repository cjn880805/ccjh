//qzroad1.h

//Sample for room: Ȫ��ɽ·1
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_qzroad1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ȫ��ɽ·1");

	set("resident", "Ȫ��");
	
	add_npc("pub_flowerg");     //add by zdn 2001-07-14


	add_door("Ȫ��ɽ·2", "Ȫ��ɽ·2", "Ȫ��ɽ·1");
	add_door("̩ɽ�����", "̩ɽ�����", "Ȫ��ɽ·1");

	
	
/*****************************************************
	set("exits", ([
		"northwest" : "/d/taishan/yidao1",
                "south" : __DIR__"qzroad2",
	]));
********************************************/
};


RESIDENT_END;
