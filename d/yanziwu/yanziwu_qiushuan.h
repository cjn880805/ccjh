//qiushuan.h

//Sample for room: ��������ˬի
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_qiushuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������ˬի");

	add_door("������κϾ�", "������κϾ�", "��������ˬի");

    set("long", "��ᣵʹ����豸���أ��ٴ������϶������ᣬһ��Ͱë����ʾ������ѧʶԨ����һֻ���λ�ƿ���ż����绨�������������µ���Ϣ��" );
	
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp