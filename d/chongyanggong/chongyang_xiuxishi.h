//xiuxishi.h

//Sample for room:  ��������Ϣ��
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_xiuxishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������Ϣ��");

	add_door("������", "������", "��������Ϣ��");
	add_npc("quanzhen_daotong1");

	set("long", "���Ǽ�ܴ�ķ��䣬���߷ǳ��谵������û��ʲô��Ķ�����ֻ���м����һ����ʰ����������Ĵ󴲣����ϵı���Ҳ�����������࣬���ž�������˯����");
    
    set("sleep_room",1);
    set("no_beg",1);
    set("no_fight",1);
    set("no_steal",1);

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