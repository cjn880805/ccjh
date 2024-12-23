//qingbomen.h

//Sample for room: �����岨��
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_qingbomen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����岨��");

	//add npcs into the room
	add_npc("pub_girl");
	
	add_door("���ݾ۾�԰", "���ݾ۾�԰", "�����岨��");
	add_door("������ʯ���14", "������ʯ���14", "�����岨��");

	set("long"," ԰�ſ���һ����¥�������Ͽ��š��岨�š�����¥��վ�ż������ҹ�������Ů������׹����ۡ��������ͽ��˾۾���������ص���·��    ���������߱��ǰ׵��ˡ������߿�ͨ����ʯ���");

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
