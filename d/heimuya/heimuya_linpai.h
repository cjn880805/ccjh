//linpai.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_linpai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");
	
	add_npc("heimuya_heiyiren");    //add by zdn 2001-07-20


	add_door("��ľ�������ô���", "��ľ�������ô���", "��ľ��������");

	set("long", "�����Ǻ�ľ�µĵڶ����ð׻��õ������ҡ�������ש�̵ء�������һ����(box1).");
    

/*****************************************************
        set("exits", ([	
	    "west"      : __DIR__"qing",
	]));
	set("item_desc", ([
            "box1": "���Ǹ������Ƶĺ��ӣ������Ա��˴򿪣��տ���Ҳ ��\n",
       	]) );
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp