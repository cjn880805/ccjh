//lengsl3.h

//Sample for room:  ������ɼ��3
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_lengsl3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ɼ��3");

         add_npc("pub_cunfu");       // add by zdn 2001-07-14

	add_door("������ɼ��2", "������ɼ��2", "������ɼ��3");
	add_door("������ɼ��4", "������ɼ��4", "������ɼ��3");
	add_door("���Ұ�ʮ����2", "���Ұ�ʮ����2", "������ɼ��3");

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
