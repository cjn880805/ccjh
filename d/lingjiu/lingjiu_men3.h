//men3.h

//Sample for room: ���ձչ��Ҵ���
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_men3);

virtual void create()			
{

	set_name( "���ձչ��Ҵ���");


	add_npc("lingjiu_shi");/////////////////////////

	add_door("����С��2", "����С��2", "���ձչ��Ҵ���");
	add_door("���ձչ���", "���ձչ���", "���ձչ��Ҵ���");


	

/*****************************************************
        set("exits", ([
		"north" : __DIR__"biguan",
		"south" : __DIR__"xiaodao2",
        ]));
    	set("objects",([
                __DIR__"npc/shisao" : 1,
        ]));
********************************************/
};


ROOM_END;
