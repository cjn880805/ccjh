//lengsl1.h
//Sample for room:  ������ɼ��1
//coded by zouwenbin
//data: 2000-11-30
ROOM_BEGIN(CREMei_lengsl1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ɼ��1");
	add_npc("pub_jianke");        // add by zdn 2001-07-14
	add_door("�����׶�ƺ", "�����׶�ƺ", "������ɼ��1");
	add_door("������ɼ��2", "������ɼ��2", "������ɼ��1");

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
