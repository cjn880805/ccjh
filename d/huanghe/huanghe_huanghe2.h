//huanghe2.h

//Sample for room: �ƺӰ���2
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺӰ���2");
	
	add_npc("monster_24k");        //add by zdn 2001-07-14
	add_npc("pub_ruanjiao"); 

	add_door("�ƺӰ���1", "�ƺӰ���1", "�ƺӰ���2");
	add_door("�ƺӰ���3", "�ƺӰ���3", "�ƺӰ���2");

	set("long","�����ǻƺӰ��ߡ��ƺ����ʵ�����Ѿ���ɳ�����ˡ���ɫ�ĺ�ˮ�ںӴ��﷭���ţ������ţ�����һ�����޴�����ѡ�");
    

/*****************************************************
	set("exits", ([
		"east"  : __DIR__"huanghe3",
		"west"  : __DIR__"huanghe1",
	]));
********************************************/
};


CHANGAN_END;
