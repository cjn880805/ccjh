//nroad3.h

//Sample for room:  Ѫ����ɽ·3
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_nroad3);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ����ɽ·3");
	
	add_npc("pub_caishiren");            //add by zdn 2001-07-16



				
	add_door("�ƺ�", "�ƺ�", "Ѫ����ɽ·3");
	add_door("�����˺ͱ�", "�����˺ͱ�", "Ѫ����ɽ·3");

	set("long","����ɽ�Ʊȴ�ѩɽ�����Ի���Ҳ����ʮ�ֵ��Ϻ���ɽ�����Գ�����ϡϡ������һЩҰ�ݡ����º����˼���ֻ�м�ֻͺӥ�ڸߴ�������������ããѩɽ��");

/******************************************************************************
        set("exits",([
                "south"     : __DIR__"nroad4",
                "eastdown"  : __DIR__"nroad2",
        ]));
        set("objects",([
                __DIR__"npc/lutianshu" : 1,
                __DIR__"npc/shuidai"   : 1,
                __DIR__"npc/eagle"     : 2,
        ]));
******************************************************************************/
};


ROOM_END;
