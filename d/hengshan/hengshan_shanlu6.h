//shanlu6.h

//Sample for room: ��ɽɽ·6
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽɽ·6");
	
	add_npc("pub_daoke");           //add by zdn 2001-07-17


	add_door("��ɽɽ·5", "��ɽɽ·5", "��ɽɽ·6");
	add_door("��ɽĥ��̨", "��ɽĥ��̨", "��ɽɽ·6");

    set("long","�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣��������ƣ��������ش�졣�ϱ�ɽ·����ĥ��̨�������塣" );
    

/*****************************************************
        set("exits", ([ 
           "southdown"  : __DIR__"mojingtai",
           "east"       : __DIR__"shanlu5",
        ]));
********************************************/
};


ROOM_END;
