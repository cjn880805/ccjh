//kedian2.h

//Sample for room: �͵�
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_kedian2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�͵�2");


	add_door("��������", "��������", "�����͵�2");

	set("long", "����һ�Ҽ�Ǯ�����Ŀ͵꣬��Ϊ�ط�ƫƧ�����ͺ��١���ʱ�д�֮���Ӷ��ϱߴ������ƹ��粻֪���Ķ�ȥ�ˣ����������һ���ˡ��ϱ��Ǻ�Ժ��ͨ�����᷿��" );
    set("sleep_room",1);

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
