//xiaolu.h

//Sample for room:  ������С·
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_xiaolu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������С·");

	add_npc("quanzhen_sun");
	add_npc("quanzhen_tan");

	add_door("������������", "������������", "������С·");
	add_door("��������ɽ", "��������ɽ", "������С·");

	set("long", "�����Ǻ�ɽ�ϵ�С·������С·�������˹������޳����ģ�Ҳ��ֻ����ǰ�Ĳ�ҩ�˲ȶ��ˣ��ֳ�����һ��С·����");
    
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