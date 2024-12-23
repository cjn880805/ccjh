//hanshansi.h

//Sample for room: ��ɽ��
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_hanshansi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ��");
	
	add_npc("pub_guest");       //add by zdn 2001-07-16

	add_door("������", "������", "���ݺ�ɽ��");
	add_door("���ݷ���", "���ݷ���", "���ݺ�ɽ��");

	set("long", "���߳�����Լ��ʮ��أ��͵��˷���������Ԫ����䣬�и�ɮ��ɽ�������˾�ס����ϣǨ��ʦ�ڴ˽���Ժʱ��������ɽ�¡��ƿ�Ԫ��䣬ʫ���ż̸���Ӧ����ڣ���;�۴�ͣ�����ţ���ʫһ�ף�����������˪���죬�������Գ��ߣ����ճ��⺮ɽ�£�ҹ��������ʹ������Ӵˣ�ʫ�������������˿ڣ�����ʫ���������¡�" );
	

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
