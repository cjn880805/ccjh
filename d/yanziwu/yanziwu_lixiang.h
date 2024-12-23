//lixiang.h

//Sample for room: ����������Է
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_lixiang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������Է");

	add_door("������������", "������������", "����������Է");
	add_door("�����볤��", "�����볤��", "����������Է");
	add_door("�����봩��", "�����봩��", "����������Է");

    set("long", "Ľ�ݼҵĺ�ԺҲ���ڲ�ͬ��Բ��Ժ���Ͽ�������Է���֣�Ժ��ѩ�׵��滨������֦ͷ��������ǽӴ�������������ˣ�������һ�������ĳ��ȡ�" );
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