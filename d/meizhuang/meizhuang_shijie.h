//shijie.h

//Sample for room:  ÷ׯ��ɽʯ��
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_shijie);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "÷ׯ��ɽʯ��");
	
	add_npc("pub_jianke");       //add by zdn 2001-07-14

	add_door("���ݹ�ɽ", "���ݹ�ɽ", "÷ׯ��ɽʯ��");

	add_door("÷ׯ����С��", "÷ׯ����С��", "÷ׯ��ɽʯ��");
	

    

/******************************************************************************
        set("exits", ([  
            "eastdown" : "/d/hangzhou/gushan",
            "north"    : __DIR__"xiaolu.c",
        ]));
******************************************************************************/
};


ROOM_END;
