//wuqiao.h

//Sample for room: �ƺ�������
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_wuqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�������");
	
	add_npc("pub_liumang");    // add by zdn 2001-07-14


	add_door("�ƺӴ��", "�ƺӴ��", "�ƺ�������");
	add_door("�ƺ�����", "�ƺ�����", "�ƺ�������");

	set("long","���������������ϵ�һ����Ҫ�ضΣ���ʯɽ���������أ�ʱ����Ұ�޳�û��һ���ٵ���ɽ�����Ѷ�����");
	

/*****************************************************
	set("exits", ([
		"south"     : __DIR__"dacaigou",
		"northwest" : __DIR__"wuwei",
	]));
********************************************/
};


CHANGAN_END;
