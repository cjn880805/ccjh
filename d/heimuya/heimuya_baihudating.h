//baihudating.h

//Sample for room: �׻��ô���
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_baihudating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�׻��ô���");
	
	add_npc("heimuya_shanggy");    //add by zdn 2001-07-20


	add_door("��ľ���ּ�С��", "��ľ���ּ�С��", "��ľ�°׻��ô���");
	add_door("��ľ�³���", "��ľ�³���", "��ľ�°׻��ô���");

	set("long", "���ǡ�������̡��µڶ����ã��׻��õĴ�������Ŀ��ȥ��һ�ض�����Ѫ����Ȼ����ǰ������һ����ս����������һ���ľ��(bian)�����ϱ������м���Ѫ��(zi)��");
    

/*****************************************************
        set("exits", ([
            "west" : __DIR__"baistep1",
            "east" : __DIR__"linjxd6",
        ]));
        set("item_desc", ([
            "bian": "����д�����������գ��׻����죻
                     ǧ�����أ�һͳ���� ��\n",
            "zi" : "����д������ɽ���ӣ���ɱа�̡�\n" 
	]) );
********************************************/
};


ROOM_END;
