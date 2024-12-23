//jingxiushi.h

//Sample for room:  ������������
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_jingxiushi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������������");

	add_npc("quanzhen_liu");

	add_door("������", "������", "������������");
	add_door("������С·", "������С·", "������������");
	add_door("���������Ӿ�", "���������Ӿ�", "������������");

	set("long", "������ȫ��̵��Ӿ��޲������ķ��䣬�����С������ʰ�ĸɸɾ��������ζ��ڷŵ��������룬����һ�����������");
    

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