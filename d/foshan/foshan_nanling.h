//nanling.h
//Sample for room: ����ɽ��
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_nanling);
virtual void create()			//Call it when Room Create
{
	set_name( "����ɽ��");

	add_npc("animal_huananhu");
	add_npc("pub_bixuan");

	add_door("��ɽ����", "��ɽ����", "��ɽ����ɽ��");
	add_door("��ɽ����·", "��ɽ����·", "��ɽ����ɽ��");
	add_door("�䵱����·2", "�䵱����·2", "��ɽ����ɽ��");

	set("long", "�����������һ��ɽ�ڡ�������Ƿ�ɽ�ˣ������Ǻ�ب���Ϲ㶫�����롣����������ȣ����������쳤������ҲԶ����ԭ�ˡ�" );

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
