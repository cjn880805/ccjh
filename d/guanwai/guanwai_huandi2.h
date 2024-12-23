//huandi2.h

//Sample for room: ��·2
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_huandi2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��·2");
	
	add_npc("pub_liumangtou");
	add_npc("pub_liumang");            // add by zdn 2001-07-13 

	set("monster_chance", 50);

	add_door("�����·1", "�����·1", "�����·2");
	add_door("����ɽ����", "����ɽ����", "�����·2");

    set("long","���ǳǶ���һ����·��·�����ҵĳ�����ϥ�ĻĲݣ�Զ������һ�ˡ����Ըɿݵ������������˳�Ⱥ����ѻ���������������ڻ�Ұ��ԶԶ��ȥ��һ�������ľ���" );
	

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
