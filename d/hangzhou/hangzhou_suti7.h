//suti7.h

//Sample for room: �����յ�7
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_suti7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����յ�7");
	
	add_npc("pub_playboy");   // add by zdn 2001-07-14


	add_door("�����յ�6", "�����յ�6", "�����յ�7");
	add_door("������ʯ���20", "������ʯ���20", "�����յ�7");

	set("long"," �յ���ʫ���ն��������ֿ�������ʱ�ú���Ͳ����ɵġ��ն�������ʫ�������£�������Ǯ���غ��ˣ����ʿŮ�����ᡣ���ź���캺�ϣ���ɽʼ������ͨ��������ʮ�����ɣ�����ϯ����̿ա������ϱ��Ǵ����������ӳ���š�ӳ�������յ������������ϵĵ�һ����");

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
