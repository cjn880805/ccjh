//bashisipan2.h
//Sample for room:  ���Ұ�ʮ����2
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_bashisipan2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���Ұ�ʮ����2");
	add_npc("pub_girldizi");        // add by zdn 2001-07-14

	add_door("���Ұ�ʮ����1", "���Ұ�ʮ����1", "���Ұ�ʮ����2");
	add_door("���Ұ�ʮ����3", "���Ұ�ʮ����3", "���Ұ�ʮ����2");
//	add_door("������ɼ��3", "������ɼ��3", "���Ұ�ʮ����2");

	set("long","��ʮ���̣���·���ն��ͣ��ػ����ۣ����˲��ܴ�Ϣ��·���Ǳ����������ɼ�֣�·��������׵ľ���Ͽ�ȡ��ɴ���������������µ�ϴ��ء�");

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
