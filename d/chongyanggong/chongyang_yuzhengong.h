//yuzhengong.h

//Sample for room:  ���������湬
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_yuzhengong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���������湬");

	add_npc("quanzhen_ma");
	add_npc("quanzhen_qi");
	add_npc("quanzhen_shen");

	add_door("������", "������", "���������湬");

	set("long", "��������������ǰ�ľ�ַ���������������˲�����֮ǰ���޵ĵط��������ִ�ȫ��̺󣬴˵صĲ���ʵ��̫С���ͽ�������Ǩ������ɽ�ϣ����˵����¸���Ϊ���湬���Լ���õ�֮�⡣����ܾ�û���������ˣ������϶������˻ҳ���");

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
//last, register the room into ../server/RoomSetup.cpp