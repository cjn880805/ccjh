//qingtang.h

//Sample for room: ��ľ��������
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_qingtang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ľ��������");
	
	add_npc("heimuya_jiabaoyu");    //add by zdn 2001-07-20


	add_door("��ľ��ɽ��", "��ľ��ɽ��", "��ľ��������");
	add_door("��ľ�³���2", "��ľ�³���2", "��ľ��������");

	set("long", "���ǡ�������̡��µ������ã������õĴ�����ʮ�����ɣ��ֻ���һ������ʱ��ʱ�֡���������һ����(bian)��");
    

/*****************************************************
         set("exits", ([
            "south"      : __DIR__"chlang1",
            "northdown" : __DIR__"guang",
        ]));
        set("item_desc", ([
            "bian": "����д����������գ��������졣ǧ�����أ�һͳ���� ��\n",
        ]) );
********************************************/
};


ROOM_END;
