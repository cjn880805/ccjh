//tumenzi.h

//Sample for room: �ƺ�������
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_tumenzi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�������");
	
	add_npc("monster_32k");       // add by zdn 2001-07-14


	add_door("�ƺ�����", "�ƺ�����", "�ƺ�������");
	add_door("�ƺ�ʯϿ��", "�ƺ�ʯϿ��", "�ƺ�������");

	set("long","������Ҳ����ǰפ���ĵط�����Χȫ��ɳĮ���м�һ��СС�����ޣ����������е��ص������ס������ǰ��������һ������ռ��������������Ϊ��Ӫ�ĳ����ӣ��޶�����");
	

/*****************************************************
	set("exits", ([
		"south"     : __DIR__"wuwei",
		"northeast" : __DIR__"shixiazi",
	]));
********************************************/
};


CHANGAN_END;
