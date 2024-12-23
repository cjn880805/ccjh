//shaiziroom.h

//Sample for room: �������ӷ�
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_shaiziroom);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������ӷ�");

	//add npcs into the room  2001-07-12 zdn add
	add_npc("pub_punk");   //С��å

	add_door("�����ָ�ʫ��", "�����ָ�ʫ��", "�������ӷ�");

	set("long", " ���м����һ�ſ������൱��ʵ�Ĵ�����(table)������Χ��ʮ���ѿ���ľ�Ρ�����ǽ����һ������(paizi)��" );
	set("no_fight",  1);
	set("no_cast",  1);

	set("no_caishen",  1);

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

CHANGAN_END;
