//lengsl2.h
//Sample for room:  ������ɼ��2
//coded by zouwenbin
//data: 2000-11-30
ROOM_BEGIN(CREMei_lengsl2);
virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ɼ��2");
	add_npc("pub_flowerg");               // add by zdn 2001-07-14
	add_door("���Ұ�ʮ����1", "���Ұ�ʮ����1", "������ɼ��2");
	add_door("������ɼ��3", "������ɼ��3", "������ɼ��2");
	set("long","����һƬ������յ���ɼ�֡�����Ҳ�ϱ�����������ɼ������һ�飬�ÿ�֦��Ҷï����һ�����ɡ��������գ��������ڵ�˿��Ҳ�ޡ������Ϻ��Ŀ�֦��Ҷ����Ȼ�οͺ���̤��˴���");

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
