//buwei1.h

//Sample for room: ��ɽ������Ϊ��
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_buwei1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ������Ϊ��");
	
	add_npc("huashan_doctor");        //add by zdn 2001-07-20


	add_door("��ɽȺ�ɹ�", "��ɽȺ�ɹ�", "��ɽ������Ϊ��");
	add_door("��ɽ����", "��ɽ����", "��ɽ������Ϊ��");
	add_door("��ɽƫ��", "��ɽƫ��", "��ɽ������Ϊ��");
	add_door("��ɽ��԰", "��ɽ��԰", "��ɽ������Ϊ��");

	set("long", "���ǻ�ɽ��������Ⱥ�ľ�����������Ϊ�������˴���ǰ�������Ϲ��š������á������Ҷ���кܿ���ȴûʲô���裬��ǽ�������ѽ��Σ�����������Ⱥ���¡���ͽ�ĵط������������ҡ�.");  
 
/*****************************************************
         set("exits", ([  
            "north" : __DIR__"buwei2",
            "south" : __DIR__"qunxianguan",
            "west"  : __DIR__"garden",
            "east"  : __DIR__"buwei3",
	]));
        set("objects", ([
             __DIR__"npc/dayou": 1,
             __DIR__"npc/little_monkey": 1,
        ]) );
********************************************/
};


ROOM_END;
