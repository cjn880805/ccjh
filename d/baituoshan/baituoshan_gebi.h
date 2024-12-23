//gebi.h

//Sample for room: ����ɽ���
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_gebi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ���");

	set("monster_chance", 20);
	add_npc("pub_dinping");

	add_door("����ɽ����", "����ɽ����", "����ɽ���");
	add_door("�����Į", "�����Į", "����ɽ���");

	set("long", "�������ٽ�ɳĮ�ĸ��̲���������̡�������һ���޼ʵĴ�ɳĮ,���������Կ���һ��С��");
    
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
