//changlang.h

//Sample for room: ����ɽ����
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_changlang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ����");


	add_door("����ɽҩ��", "����ɽҩ��", "����ɽ����");
	add_door("����ɽ����", "����ɽ����", "����ɽ����");
	add_door("����ɽ������", "����ɽ������", "����ɽ����");
	add_door("����ɽ��Ϣ��", "����ɽ��Ϣ��", "����ɽ����");

	set("long", "�����Ƿǳ����ɵĳ��ȡ������Ǽ���Ϣ�ҡ��ϱ��м�ҩ�������洫��һ�������������������������ȹ�����С���š�������������.");

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
