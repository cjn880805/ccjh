//hcaxiuxishi.h
//Sample for room:  ���һ�������Ϣ��
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_hcaxiuxishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���һ�������Ϣ��");
	add_door("���һ����ֶ���1", "���һ����ֶ���1", "���һ�������Ϣ��");
	add_door("����������", "����������", "���һ�������Ϣ��");

	set("long","�����Ƕ��һ����ֵ���Ϣ�ҡ���������������������������˺ܶ�ľ�����м���ҹ�����ֵ�Сʦ̫����˯������Ϣ�������������");
    set("sleep_room", 1);

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
