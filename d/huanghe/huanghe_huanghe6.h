//huanghe6.h

//Sample for room: �ƺӰ���6
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺӰ���6");
	
	add_npc("pub_tufei1");       //add by zdn 2001-07-14


	add_door("�ƺӰ���5", "�ƺӰ���5", "�ƺӰ���6");
	add_door("�ƺӰ���7", "�ƺӰ���7", "�ƺӰ���6");

	set("long","�����ǻƺӰ��ߡ��ƺ����ʵ�����Ӵ���������ɫ�ĺ�ˮ�ھ���������ȥ��ʹ������������ˮʱ�Ŀ�����");

/*****************************************************
	set("exits", ([
		"northeast" : __DIR__"huanghe7",
		"southwest" : __DIR__"huanghe5",
	]));
	set("objects", ([
		__DIR__"npc/zu" : 1,
	]));
********************************************/
};


CHANGAN_END;
