//banshan.h

//Sample for room: ��ɽ��ɽͤ
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_banshan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ��ɽͤ");
	
	add_npc("pub_guest");        //add by zdn 2001-07-14

	add_door("��ɽɽ·4", "��ɽɽ·4", "��ɽ��ɽͤ");
	add_door("��ɽɽ·5", "��ɽɽ·5", "��ɽ��ɽͤ");

    set("long","���ڵ��˰�ɽͤ�������뵽ף�ڷ����۸̻߳����г̣���ǡ����һ��֮����·��Сͤ��Ȼ�Ѽ��žã�����Ϊ���������ڷ���ꡣ" );
    

/*****************************************************
        set("exits", ([ 
           "southdown"  : __DIR__"shanlu4",
           "northup"    : __DIR__"shanlu5",
        ]));
********************************************/
};


ROOM_END;
