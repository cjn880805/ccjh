//zhandao.h

//Sample for room: ��ɽ��ʽջ��
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_zhandao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ��ʽջ��");
	
	add_npc("pub_youke");       //add by zdn 20017-07-17


	add_door("��ɽ������", "��ɽ������", "��ɽ��ʽջ��");
	add_door("��ɽ�Ƹ����", "��ɽ�Ƹ����", "��ɽ��ʽջ��");

    set("long","ջ�����ڱڣ������������̳ɣ�ÿ���������Žڲ�����һ��ÿ��������ұڣ�����ľ�壬��Լʮ�ɣ�������Ԩ���˱���̤�����յ�ľ�壬������������Ϣ����������Ų�������ܹ�ȥ��"   );
    

/*****************************************************
        set("exits", ([ 
           "southup"   : __DIR__"yunge",
           "northdown" : __DIR__"xuankong2",
        ]));
********************************************/
};


ROOM_END;
