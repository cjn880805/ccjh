//haitan.h

//Sample for room: ���͵���̲
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_haitan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵���̲");
	
	add_npc("pub_yufu");        //add by zdn 2001-07-20


	add_door("��ɽ����", "��ɽ����", "���͵���̲");
	add_door("���͵�ɽ��", "���͵�ɽ��", "���͵���̲");

    

/*****************************************************
    set("item_desc", ([
        "boat" : "�������͵�������ϵ�Ĵ󴬡����ϵĿ��˻����ֻҪ\n"
                  "�ϴ�(enter)�Ϳ��Ի���ԭ��\n",
    ]));
    set("exits",([
        "south" :__DIR__"lin1",
    ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp