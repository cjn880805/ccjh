//beimen.h

//Sample for room: Ȫ�ݱ���
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_beimen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ȫ�ݱ���");

	set("resident", "Ȫ��");

	add_npc("pub_playboy");

	add_door("Ȫ��ɽ·5", "Ȫ��ɽ·5", "Ȫ�ݱ���");
	add_door("Ȫ��", "Ȫ��", "Ȫ�ݱ���");

	set("long", "�������Ϸ���һ��Ȫ�ݵı��š��������򱱿ɵ���ԭ��" );
	
	
/*****************************************************
	set("exits", ([
                "north" : "/d/fuzhou/puxian",
                "south" : __DIR__"zhongxin",
	]));
********************************************/
};


RESIDENT_END;
