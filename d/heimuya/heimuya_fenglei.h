//fenglei.h

//Sample for room: �����ô���
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_fenglei);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ô���");
	
	add_npc("heimuya_wangcheng");      //add by zdn 2001-07-20



	add_door("��ľ��ɽ��", "��ľ��ɽ��", "��ľ�·����ô���");
	add_door("��ľ�²ݵ�", "��ľ�²ݵ�", "��ľ�·����ô���");

	set("long", "���ǡ�������̡��µ�һ���ã������õĴ�������Ŀ��ȥ�������صģ���������һ������(vote)��");

/*****************************************************
        set("exits", ([
            "south" : __DIR__"grass2",
            "northdown" : __DIR__"linjxd5",
        ]));
 
        set("objects",([
            __DIR__"npc/jiaotu" : 2,
        ]));
        set("item_desc", ([
            "vote": "������̣��ĳ���£��󱻲�����\n"
        ]) );
//        
********************************************/
};


ROOM_END;
