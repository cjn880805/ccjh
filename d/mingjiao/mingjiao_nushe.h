//nushe.h

//Sample for room: ����Ů��
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_nushe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���̵���Ů��");


	add_door("�������Ź㳡", "�������Ź㳡", "���̵���Ů��");
	add_npc("mingjiao_dimen");

	set("long", "�߽����Ů�ᣬһ��֬�۵������棬�������ޣ��������ƶ��㣬��õ�壬��ҹ���㣬��������������λ����б����������ʫ������ȫ�����������ˣ�˭���뵽�����Ƕ���߳�彭���Ľ���Ů���أ�");
    
    set("sleep_room", 1);
    set("no_fight", 1);

/*****************************************************
    set("exits", ([
        "out" : __DIR__"mjdimen1",
    ]));
    set("item_desc",(["dui lian" : (: look_dui :),]));
********************************************/
};


ROOM_END;
