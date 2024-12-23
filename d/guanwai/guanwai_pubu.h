//pubu.h

//Sample for room: �����ٲ�
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_pubu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ٲ�");
	
	add_npc("pub_bing");     // add by zdn 2001-07-13

	set("monster_chance", 50);

	add_door("����С���", "����С���", "���ⳤ���ٲ�");
	add_door("�������", "�������", "���ⳤ���ٲ�");

    set("long","���ˮ��������߸߷������䣬����֮��Զ�����ˮ��ֱ����ֹȣ�����Ȼ������ڡ������ӳ��ǡ�ư������գ�ˮ����������Ĺȵף������ɸߵķ��ˣ�������Ůɢ�������������£�����Ծ��譲�׳��֮����" );

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
