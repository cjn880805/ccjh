//xiuxishi.h

//Sample for room: ��ɽС��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_xiuxishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽС��");


	add_door("��ɽСɽ·", "��ɽСɽ·", "��ɽС��");

	set("long", "���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵������������ֻ���м����һ����ʰ����������Ĵ󴲣����ž�������˯����");  
    set("sleep_room", 1);
    
    set("no_fight", 1);

/*****************************************************

********************************************/
};


ROOM_END;
