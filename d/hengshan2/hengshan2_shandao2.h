//shandao2.h

//Sample for room: ��ɽ���Է�ɽ��2
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_shandao2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ���Է�ɽ��2");
	
	add_npc("pub_tiaofu");           //add by zdn 2001-07-17


	add_door("��ɽ���Է�ɽ��1", "��ɽ���Է�ɽ��1", "��ɽ���Է�ɽ��2");
	add_door("��ɽ���Է�㳡", "��ɽ���Է�㳡", "��ɽ���Է�ɽ��2");

    set("long","�����ڼ��Է�ɽ��С·�ϣ�����ɽ��������ӹģ���ǰ����Ư����ԶԶ����ǰ����Ƿ嶥�ˡ� " );
    

/*****************************************************
        set("exits", ([ 
           "southdown"  : __DIR__"beiyuedian",
           "eastup"     : __DIR__"square",
        ]));
********************************************/
};


ROOM_END;
