//pingdingzhou.h

//Sample for room: ƽ����
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_pingdingzhou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ƽ����");
	
	add_npc("heimuya_heiyiren");       //add by zdn 2001-07-20


	add_door("��ľ�»���·2", "��ľ�»���·2", "��ľ��ƽ����");
	add_door("��ľ�»���·3", "��ľ�»���·3", "��ľ��ƽ����");

	set("long", "ƽ�����ںӱ����ڣ��ݸ����󣬵��ش�Ҫ�壬ʮ����Ҫ���������ǵĿ��̴���Ƶ��������������½�ͽ���ֱײ������ץ�ˣ�����ھ��ܣ�ȴ˿��û���ٸ��������");
    

/*****************************************************
    set("exits", ([
        "east" : __DIR__"road3",
        "west" : __DIR__"road2",
    ]));
********************************************/
};


ROOM_END;
