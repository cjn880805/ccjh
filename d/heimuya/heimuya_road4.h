//road4.h

//Sample for room: ����·4
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_road4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����·4");
	
        add_npc("pub_punk");       //add by zdn 2001-07-20

	add_door("��ľ����ʯ��", "��ľ����ʯ��", "��ľ�»���·4");
	add_door("��ľ�����Ŷɿ�", "��ľ�����Ŷɿ�", "��ľ�»���·4");

	set("long", "������һ������·�ϡ�������ɽ���ؽ磬�����ͽ���ӱ��ˡ��������ﲻ��̫ƽʱ�ڣ����ǿ���߰ɡ�");
    

/*****************************************************
        set("outdoors", "heimuya");
        set("exits", ([
                "northeast" : __DIR__"road1",
                "southwest" : __DIR__"dukou1",
        ]));
********************************************/
};


ROOM_END;
