//chuantang.h

//Sample for room: �����봩��
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_chuantang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����봩��");

	add_door("����������Է", "����������Է", "�����봩��");
	add_door("�������ϼ��", "�������ϼ��", "�����봩��");

    set("long", "��֪��ʲô�ܹ��ɽ�������������ã��������ۣ����������������Ͼ��Ǻ�Ժ�ˣ�������һ�������á�" );
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