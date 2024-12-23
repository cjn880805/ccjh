//dongjie.h

//Sample for room: ����ɽ����
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_dongjie);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ����");

	//add npcs into the room
	add_npc("pub_playboy");
	add_npc("helpnpc005");

	add_door("����ɽ���", "����ɽ���", "����ɽ����");
	add_door("����ɽ����", "����ɽ����", "����ɽ����");
	add_door("����ɽС·1", "����ɽС·1", "����ɽ����");
	add_door("����ɽ������", "����ɽ������", "����ɽ����");

	set("long", "������С��Ķ��֡��ϱ��и������̣����洫���������������������Ϸ��ǻ����ĸ�ڣ�����������С·����ɽ��");

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
