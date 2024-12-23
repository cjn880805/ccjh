//ruzhou.h

//Sample for room: ���ݳ�
//coded by zwb
//data: 2000-12-1

ROOM_BEGIN(CRBeiJing_ruzhou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݳ�");

	//add npcs into the room
	add_npc("pub_wujiang");
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("pub_ruzhousen");
	add_npc("pub_dongmengqin");
	
	add_door("���������9", "���������9", "�������ݳ�");
	add_door("��ɽ̫����", "��ɽ̫����", "�������ݳ�");
	add_door("������", "������", "�������ݳ�");

	set("long", "���ݳ��Ǳ����Ĵ�ǣ������Ǳ��ұ���֮�ء��������ڴ�פ���ر����̲��������������ˣ����������𸽽�ɽ�ϵĲݿܡ�����һ�Ӷӹٱ�����ȥȥ��һ��ɭ������������������������֮һ����ɽ��" );
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
