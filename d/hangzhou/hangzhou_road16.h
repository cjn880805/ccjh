//road16.h

//Sample for room: ������ʯ���16
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road16);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ���16");

	//add npcs into the room
	//add_npc("baizhen");
	add_npc("pub_playboy");
	
	add_door("������ʯ���15", "������ʯ���15", "������ʯ���16");
	add_door("������ʯ���20", "������ʯ���20", "������ʯ���16");
	add_door("���ݾ�����", "���ݾ�����", "������ʯ���16");
	add_door("����Ϧ��ɽ", "����Ϧ��ɽ", "������ʯ���16");
		
	set("long"," �����£�ԭ����������Ժ���ֽ��˽��¡�������������������ӵ��Ȼͦ�������ɽ�������ͻص�����ϡ�");

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
