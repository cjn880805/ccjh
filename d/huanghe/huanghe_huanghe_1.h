//huanghe_1.h

//Sample for room: �ƺ�1
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe_1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�1");
	
	add_npc("huanghe_shen");      //add by zdn 2001-07-14


	add_door("�ƺӺ���", "�ƺӺ���", "�ƺ�1");
	add_door("�ƺ�μ������", "�ƺ�μ������", "�ƺ�1");

	set("long","�ƺ����ɹŸ�ԭ�ϱ������ʣ���̫��ɽ������������תͷ���£��γɽ��µķֽ硣������������и��ɿڡ�");
    

/*****************************************************
	set("exits", ([
		"south"     : __DIR__"weifen",
		"west"      : __DIR__"hetao",
	]));
********************************************/
};


CHANGAN_END;
