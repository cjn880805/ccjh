//qzroad5.h

//Sample for room: Ȫ��ɽ·5
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_qzroad5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ȫ��ɽ·5");

	set("resident", "Ȫ��");
	
	add_npc("pub_daoke");        //add by zdn 2001-07-14


	add_door("Ȫ�ݱ���", "Ȫ�ݱ���", "Ȫ��ɽ·5");
	add_door("Ȫ��ɽ·4", "Ȫ��ɽ·4", "Ȫ��ɽ·5");

	
	
	
/*****************************************************
	set("exits", ([
                "north"   : __DIR__"jxnanmen",
                "west"    : __DIR__"qzroad3",
//		"southup" : __DIR__"qzroad5",
		"southup" : "/d/fuzhou/fzroad1",
		"east"    : __DIR__"chating",
	]));
********************************************/
};


RESIDENT_END;
