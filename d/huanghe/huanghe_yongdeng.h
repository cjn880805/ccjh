//yongdeng.h



//Sample for room: �ƺ�����

//coded by zouwenbin

//data: 2000-11-27



CHANGAN_BEGIN(CRHuangHe_yongdeng);



virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "�ƺ�����");



	//add npcs into the room

	add_npc("pub_wujiang");/////////////////////////

	add_npc("pub_bing");


	add_door("�ƺ�3", "�ƺ�3", "�ƺ�����");

	add_door("�ƺӿ͵�", "�ƺӿ͵�", "�ƺ�����");

	add_door("�ƺ�ɳ��·", "�ƺ�ɳ��·", "�ƺ�����");



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
