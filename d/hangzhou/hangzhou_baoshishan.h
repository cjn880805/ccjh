//baoshishan.h

//Sample for room: ���ݱ�ʯɽ
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_baoshishan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݱ�ʯɽ");

	CBox * box = Add_Box();
	box->add_object("eluanshi", 2);	
	box->set_name( "����");	

	add_door("������ʯ���8", "������ʯ���8", "���ݱ�ʯɽ");
	add_door("���ݱ�����", "���ݱ�����", "���ݱ�ʯɽ");

	set("long"," ��ʯɽ���Ǻܸߣ�ɽ�϶�����ʯ��ɽ·����һ��ͤ�ӡ�����ͤ����ͤǰ�п����δ�ʯ���ٿո�����ɽ�ۣ�������ʯ���ֳ�����ʯ���������Ͼ͵��˱������������±�ص�����ˡ�");

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
