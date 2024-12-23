//pindi.h

//Sample for room: ������Ʒ��ͥ
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_pindi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������Ʒ��ͥ");

	add_door("�����벴����", "�����벴����", "������Ʒ��ͥ");
	add_door("������������", "������������", "������Ʒ��ͥ");

    set("long", "ֻ��ǽ�Ϲ�������֮������������Ϸ���һ����ף�����Ľ���������������������ˡ��������͵���̫�����ߣ�������Ľ�����ҽӴ����͵��������ˡ�" );
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