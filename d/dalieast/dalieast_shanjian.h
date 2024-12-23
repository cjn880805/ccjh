//shanjian.h

//Sample for room: ���������ɽ��
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_shanjian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���������ɽ��");

	add_npc("pub_youke"); //add by zdn 2001-07-12

	add_door("���������", "���������", "���������ɽ��");
	add_door("����ǰ�ɽ����", "����ǰ�ɽ����", "���������ɽ��");

	set("long", "�������Ȼ���ʣ�һ�����������Ϸɽ�������ɽ����������̸��������˾���ͽ��ͨ������ˮ�����ɾ���·������ͣ��������Ͳװˮ��ʡ�������������֣���Ҷ��ɽ��ɳɳ���졣��Щ���Ĵ���Զ������ɽ������������Ϊʳ��" );

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
