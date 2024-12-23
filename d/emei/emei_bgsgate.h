//bgsgate.h

//Sample for room:  ���ұ�����ɽ��
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_bgsgate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ұ�����ɽ��");

	add_npc("pub_guest");
				
	add_door("������ʯ��", "������ʯ��", "���ұ�����ɽ��");
	add_door("���ұ�����", "���ұ�����", "���ұ�����ɽ��");

	set("long","������Ϊ���ҳ���֮�Ż���ɽ��(gate)����һ����ҡ������骻����������ӳ���ɴ�һ·�����Ͽ�ʼ�Ƕ���ɽ��������ɽ��һ�������ʯ��·��");
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
