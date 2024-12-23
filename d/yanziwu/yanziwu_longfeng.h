//longfeng.h

//Sample for room: ������������
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_longfeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������������");

	add_door("������Ʒ��ͥ", "������Ʒ��ͥ", "������������");
	add_door("����������", "����������", "������������");
	add_door("����������Է", "����������Է", "������������");

    set("long", "����һ������Ρ�룬������Ĵ����ã�����ǰһ�Դ�ʯʨ��������צ�������� '������' ���������پ����������Ȳ���������ǽ�Ϲ��������ֻ���һ�Ŵ�������ϲ������������Χ��һȦ̴��ľ���Ρ�" );
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