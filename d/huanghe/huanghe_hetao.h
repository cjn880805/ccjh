//hetao.h

//Sample for room: �ƺӺ���
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_hetao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺӺ���");
	
	add_npc("monster_8k");     //add by zdn 2001-07-14

	add_door("�ƺ�1", "�ƺ�1", "�ƺӺ���");
	add_door("�ƺ����", "�ƺ����", "�ƺӺ���");
	add_door("�ƺӻ�����ԭ", "�ƺӻ�����ԭ", "�ƺӺ���");

	set("long","���Ե����ƺӾź�������һ�ס������׵������ϵͳ������ط��֣�����ׯ�ڵĺõط���");
	

/*****************************************************
	set("exits", ([
		"southwest" : __DIR__"huangtu",
		"east"      : __DIR__"huanghe_1",
		"west"      : __DIR__"qingcheng",
	]));
********************************************/
};


CHANGAN_END;
