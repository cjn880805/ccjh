//huanghe5.h

//Sample for room: �ƺӰ���5
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺӰ���5");
	
	add_npc("pub_liumang");
	add_npc("pub_liumang");         //add by zdn 2001-07-14


	add_door("�ƺӰ���4", "�ƺӰ���4", "�ƺӰ���5");
	add_door("�ƺӰ���6", "�ƺӰ���6", "�ƺӰ���5");
	add_door("̩ɽɽ��", "̩ɽɽ��", "�ƺӰ���5");
	add_door("������", "������", "�ƺӰ���5");	

	set("long","�����ǻƺӰ��ߡ��ƺ����ʵ�����Ӵ���������ɫ�ĺ�ˮ�ھ���������ȥ��ʹ������������ˮʱ�Ŀ�����");
    

/*****************************************************
	set("exits", ([
		"east"      : "/d/taishan/daizong",
		"northeast" : __DIR__"huanghe6",
		"southwest" : __DIR__"huanghe4",
	]));
********************************************/
};


CHANGAN_END;
