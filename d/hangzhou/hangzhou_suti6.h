//suti6.h

//Sample for room: �����յ�6
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_suti6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����յ�6");
	
	add_npc("pub_tufei1");            // add by zdn 2001-07-14


	add_door("�����յ�5", "�����յ�5", "�����յ�6");
	add_door("�����յ�7", "�����յ�7", "�����յ�6");
	add_door("���ݻ��۹���", "���ݻ��۹���", "�����յ�6");

	set("long"," ����֮ҹ�����¹ۺ��������������ԣ�����΢�磬���й���Ʈ�㣬����Ϊ֮�����̱߲���С�������ο�ȥ��̶ӳ�µġ���������ȥ���ۣ�����ɼ���̶ӳ��ң�����У������������ţ�����ӳ���š�");

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
