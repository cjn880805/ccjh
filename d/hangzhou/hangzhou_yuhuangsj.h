//yuhuangsj.h

//Sample for room: �������ɽ��
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_yuhuangsj);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������ɽ��");

	//add npcs into the room
	add_npc("honghua_honghua1");
	add_npc("honghua_honghua1");

	add_door("����ɽ·7", "����ɽ·7", "�������ɽ��");
	add_door("������ʯ���15", "������ʯ���15", "�������ɽ��");

	set("long"," ֻ�����ϵ�ɽ·�������ӡ�ɽ·����һ��С����ͤ��������������ͤ��Ъ�š���������һ����ʯ�������������ɽ��·��");
    

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
