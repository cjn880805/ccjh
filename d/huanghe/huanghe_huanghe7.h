//huanghe7.h

//Sample for room: �ƺӰ���7
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺӰ���7");
	
	add_npc("monster_8k");        //add by zdn 2001-07-14


	add_door("�ƺӰ���6", "�ƺӰ���6", "�ƺӰ���7");
	add_door("�ƺ��뺣��", "�ƺ��뺣��", "�ƺӰ���7");

	set("long","�����ǻƺӰ��ߡ��ƺ����ʵ�����Ӵ���������ɫ�ĺ�ˮ�ھ���������ȥ��ʹ������������ˮʱ�Ŀ�����");
    

/*****************************************************
	set("exits", ([
		"northeast" : __DIR__"huanghe8",
		"southwest" : __DIR__"huanghe6",
	]));
********************************************/
};


CHANGAN_END;
