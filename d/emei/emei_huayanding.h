//huayanding.h

//Sample for room:  ���һ��϶�
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_huayanding);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���һ��϶�");

	add_npc("pub_girldizi");
	add_npc("emei_li");
				
	add_door("����ʮ����4", "����ʮ����4", "���һ��϶�");
	add_door("��������ʯ", "��������ʯ", "���һ��϶�");

	set("long","���϶�ͦ�θ��ͣ���ɲ���������ʣ��羰���ա�������Ұ���������ɼ���ΡΡ��������Ⱥ�����У����׷�ɽ�����ԺҲ���۵ס��ɴ����������£���������ʯ�����¹�ʮ���̿ɵ������¡�������һ����ǡ�");

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
