//shatulu.h



//Sample for room: �ƺ�ɳ��·

//coded by zouwenbin

//data: 2000-11-27



CHANGAN_BEGIN(CRHuangHe_shatulu);



virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "�ƺ�ɳ��·");
	
	add_npc("monster_28k");      // add by zdn 2001-07-14


	add_door("�ƺ�����", "�ƺ�����", "�ƺ�ɳ��·");

	add_door("�ƺӹ���", "�ƺӹ���", "�ƺ�ɳ��·");


	set("long","������������ľ����������ǡ�һ���³�������ãã��Ұ֮�ϡ��˳ǽ��ں�������䣬���Ŵ󽫾���ȥ�����ڴ��������꣬��һ��ƽ�����������������������ﶼ�о��ӳ�פ��");

	



/*****************************************************

	set("exits", ([

//		"southup" : __DIR__"liupanshan",

		"north"   : __DIR__"gulang",

		"east"    : __DIR__"huanghe_3",

		"west"    : __DIR__"kedian",

	]));

	set("objects", ([

		"/d/city/npc/wujiang" : 1,

		"/d/city/npc/bing" : 4,

	]));

********************************************/

};





CHANGAN_END;
