//qingyinge.h

//Sample for room:  ����������
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CREMei_qingyinge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");

	add_npc("pub_girldizi");
	add_npc("emei_xian");
				
	add_door("�����з���", "�����з���", "����������");
	add_door("���Ұ�����", "���Ұ�����", "����������");
	add_door("���Һ�����ջ��", "���Һ�����ջ��", "����������");

	set("long","�����Ƕ���ɽ�������󡣴˸�λ��ţ�����£����а����������к�����������֮ˮ�������������¡������й����������ֿ�������������������˫���š���������������һ���׸ߵĺں�ɫ��ʯ��Ȼͦ��������ţ�ģ���֮Ϊ��ţ��ʯ�����ű�����һʯ��(shibei)���ɴ������ϣ������Ǻ�����ջ������·������������ȥ�з��¡�");

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
