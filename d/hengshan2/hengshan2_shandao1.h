//shandao1.h

//Sample for room: ��ɽ���Է�ɽ��1
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_shandao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ���Է�ɽ��1");
	
	add_npc("pub_jianke");      //add by zdn 2001-07-17


	add_door("��ɽ������", "��ɽ������", "��ɽ���Է�ɽ��1");
	add_door("��ɽ���Է�ɽ��2", "��ɽ���Է�ɽ��2", "��ɽ���Է�ɽ��1");

    set("long","�����ڼ��Է�ɽ��С·�ϣ�����ɽ��������ӹģ���ǰ����Ư�����о����ݼ��ˡ� " );
     

/*****************************************************
        set("exits", ([ 
           "southdown"  : __DIR__"beiyuedian",
           "northup"    : __DIR__"shandao2",
        ]));
********************************************/
};


ROOM_END;
