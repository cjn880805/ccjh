//shanlu8.h

//Sample for room: ��ɽɽ·8
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽɽ·8");
	
	add_npc("pub_daoke");            //add by zdn 2001-07-17


	add_door("��ɽĥ��̨", "��ɽĥ��̨", "��ɽɽ·8");
	add_door("��ɽ������", "��ɽ������", "��ɽɽ·8");

    set("long","���ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣��������ƣ��������ش�졣�ϱ߾��Ǹ����¡�" );
    

/*****************************************************
        set("exits", ([  
           "southup"  : __DIR__"fuyansi",
           "northup"  : __DIR__"mojingtai",
        ]));
********************************************/
};


ROOM_END;
