//xiuxishi.h

//Sample for room: �һ���
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_xiuxishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�һ���");
	
	add_npc("pub_puren");         //add by zdn 2001-07-16
        add_npc("taohua_shagu");        //add by zdn 2001-07-20


	add_door("�һ���˼����", "�һ���˼����", "�һ����һ���");

	set("long", "���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵������������ֻ���м����һ����ʰ����������Ĵ󴲣����ž�������˯����");
    set("sleep_room", 1);
    set("no_fight", 1);
    

/*****************************************************
********************************************/
};


ROOM_END;
