//qinfang.h

//Sample for room: �������߷���
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_qinfang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������߷���");
	
	add_npc("murong_abi");        //add by zdn 2001-07-20
	

	add_door("����������", "����������", "�������߷���");

    set("long", "�����ǹ�Ľ�����ҵ�����С�ĵط���������ˮ��΢��������������Ƶĺɻ�Ҷ�㣬������Ƣ���߷�����˶�����һ��ī��ɫ������ͨ��¥�ϵ���Ϣ�ҡ�" );
	
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