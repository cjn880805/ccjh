//zuijing.h

//Sample for room: ������׺��¥
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_zuijing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������׺��¥");
	
	add_npc("murong_gongsun");        //add by zdn 2001-07-20

	add_door("������κϾ�", "������κϾ�", "������׺��¥");
	add_door("������ˮ����", "������ˮ����", "������׺��¥");

    set("long", "�������Ŵ���̺�����в��õ���ⱦ���������鱦������ڷŵ�������Ŀ���㿴����Ϊ�Ķ�������˳�����߼�����������Щ���ҡ���������һ�ܺ�ľ¥�ݡ�" );
    
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