//jujingyuan.h

//Sample for room: ���ݾ۾�԰
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_jujingyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݾ۾�԰");

	//add npcs into the room
	add_npc("pub_jianke");/////////////////////////
	add_npc("honghua_honghua1");

	add_door("�����岨��", "�����岨��", "���ݾ۾�԰");
	add_door("����������", "����������", "���ݾ۾�԰");

	set("long"," ����԰�У�ֻ���������ô������������У����˲��ٱ��ҡ�������ů֮ʱ���������ǧ������˿�����̽��벻ʤ������ʫ���������ġ��Һ���׽Կ�ã���ô����෢�ӡ����ݵ�ǡ���ô����������岨�ţ����������������š�    ���������߱��ǰ׵��ˡ������߿�ͨ����ʯ���");
    

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
