//shanlu7.h

//Sample for room: ��ɽɽ·7
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽɽ·7");
	
	add_npc("pub_shennongdizi");          //add by zdn 2001-07-17


	add_door("��ɽĥ��̨", "��ɽĥ��̨", "��ɽɽ·7");
	add_door("��ɽ������", "��ɽ������", "��ɽɽ·7");

    set("long","�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣��������ƣ��������ش�졣ɽ·����ͨ��ĥ��̨�������塣" );
    

/*****************************************************
        set("exits", ([
           "westup"    : __DIR__"tianzhu",
           "eastdown"  : __DIR__"mojingtai",
        ]));
********************************************/
};


ROOM_END;
