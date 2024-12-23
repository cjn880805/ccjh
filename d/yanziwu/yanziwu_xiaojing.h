//xiaojing.h

//Sample for room: ������С��
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_xiaojing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������С��");
	
	add_npc("pub_lady3");      //add by zdn 2001-07-16

	add_door("������������", "������������", "������С��");
	add_door("�����������", "�����������", "������С��");

    set("long", "���Ǹ�һ�����ߵ�С�����������һ��С�š���Χ����Ӱ�죬�㲻��������һ�����˵Ŀ�����������ɽˮ�С�" );
    
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