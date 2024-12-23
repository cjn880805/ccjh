//jinding.h

//Sample for room:  ���ҽ�
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_jinding);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ҽ�");

	add_npc("pub_nigu2");            // add by zdn  2001-07-14

	add_door("����������", "����������", "���ҽ�");
	add_door("���һ�����", "���һ�����", "���ҽ�");
	add_door("����������", "����������", "���ҽ�");

	set("long","����Ƕ���ɽ��������ˡ��˷�������أ������Ʊ���������׳�������������������ڤ���쿪���ʴ��ɻ����������Ͻ𶥣���Ұ��Ȼ���ʣ��񿴽��£�����Ⱥ��ӿ�̵��䣬������˿���������Զ���������ѩɽ��ب��ʣ�����ɽֱ���񷡣");

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
