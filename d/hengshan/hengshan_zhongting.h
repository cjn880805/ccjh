//zhongting.h

//Sample for room: ��ɽ��ͤ
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_zhongting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ��ͤ");
	
	add_npc("pub_daoke");           //add by zdn 2001-07-16


	add_door("��ɽ���Ǹ�", "��ɽ���Ǹ�", "��ɽ��ͤ");

    set("long","��ͤ��������һ�ڣ��ؾ�ǧ�ÿ��ɽ�鱩����������飬����ʾ�������Ŷ�ʮ���⡣  " );
    

/*****************************************************
        set("exits", ([  
           "west"   : __DIR__"kuixingge",
        ]));
********************************************/
};


ROOM_END;
