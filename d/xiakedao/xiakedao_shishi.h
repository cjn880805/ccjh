//shishi.h

//Sample for room: ���͵�ʯ��
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_shishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵�ʯ��");
	
	add_npc("wudang_zhangsan");        //add by zdn 2001-07-20



	add_door("���͵�ӭ����", "���͵�ӭ����", "���͵�ʯ��");
	add_door("���͵�������", "���͵�������", "���͵�ʯ��");
	add_door("���͵��鷿", "���͵��鷿", "���͵�ʯ��");

    set("long", "����һ��ʯ�����˶�˶���������ܵ����˻�ѣ�������������ҫ��ʮ���������м���źܶ�ʯ����ʯ�ʣ��кܶ�Ľ���������ʯ���ڲ����书֮�࣬��������Ϣһ�ᡣ" );

/*****************************************************
         set("exits", ([
                "west" : __DIR__"dating"
        ]));
        set("objects", ([
                books[random(sizeof(books))] : 1,
        ]));
********************************************/
};


ROOM_END;
