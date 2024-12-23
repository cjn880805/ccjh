//hcawest2.h
//Sample for room:  ���һ���������2
//coded by zouwenbin
//data: 2000-11-30
ROOM_BEGIN(CREMei_hcawest2);
virtual void create()			//Call it when Room Create
{
	set_name( "���һ���������2");
	add_npc("emei_kong");	
	add_npc("emei_wenfang");	

	add_door("���һ���������1", "���һ���������1", "���һ���������2");
	add_door("���һ���������", "���һ���������", "���һ���������2");

	set("long","�����Ƕ��һ��������ȡ�������������������ͨ���㳡��");
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
