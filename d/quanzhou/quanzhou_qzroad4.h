//qzroad4.h

//Sample for room: Ȫ��ɽ·4
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_qzroad4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ȫ��ɽ·4");
	
	set("resident", "Ȫ��");

	add_npc("pub_xiaozei");      //add by zdn 2001-07-14


	add_door("Ȫ��ɽ·5", "Ȫ��ɽ·5", "Ȫ��ɽ·4");
	add_door("Ȫ��ɽ·3", "Ȫ��ɽ·3", "Ȫ��ɽ·4");
	add_door("Ȫ������ƽԭ", "Ȫ������ƽԭ", "Ȫ��ɽ·4");


	set("long", "������һ��ɽ·�ϡ�ʱֵ���գ�·�Ե�ɽ���Ͽ����˽��ɫ���Ͳ˻��������ǽ������Ǽ��ˡ���������븣������ɽ����������һ����·����Ϣ��С��ͤ��" );
	
	
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
