//leidongping.h
//Sample for room:  �����׶�ƺ
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_leidongping);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����׶�ƺ");
	add_npc("animal_dog");           // add by zdn 2001-07-14
	add_npc("pub_puchen");
	add_door("����������", "����������", "�����׶�ƺ");
	add_door("���Ұ�ʮ����1", "���Ұ�ʮ����1", "�����׶�ƺ");
//	add_door("������ɼ��1", "������ɼ��1", "�����׶�ƺ");

	set("long","�׶�ƺһ������·���պ��ˣ�·���Ǳ����������ɼ�֣�·��������׵ľ���Ͽ�ȡ����ﳤ���������֣����ɺڰ������Ͻ��������Ա���һ�������ɴ������ǡ���ʮ���̡�����������µ�ϴ��ء�");

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
