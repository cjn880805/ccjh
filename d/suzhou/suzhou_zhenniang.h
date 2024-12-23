//zhenniang.h

//Sample for room: ����Ĺ
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_zhenniang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ĺ");

	//add npcs into the room
	add_npc("pub_jianke");/////////////////////////

	add_door("�����Խ�ʯ", "�����Խ�ʯ", "��������Ĺ");
	add_door("��������ͤ", "��������ͤ", "��������Ĺ");

	set("long", "��ɽ���������Խ�ʯ������Բ�Σ���������������ѵ��ѷ죬�ഫ�����á��ɽ�������Īа������Ϊ�����������ʯ������ʯ�Կ���Ԫ��������ʫ�䡰����һ�������ˮ��������ΰ���󣬲�ն�Ը�ͷ������ʫ�䡣" );

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
