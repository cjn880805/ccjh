//duchang3.h

//Sample for room: ����������
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_duchang3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");

	//add npcs into the room
	//add_npc("jixian");
	
	add_door("�����ַ���¥����", "�����ַ���¥����", "����������");

	set("long", " ��������һ��һ�ҷ���������������һ�����������һȺ��ڼ�����һ�����������һȺ��β���������������߳߼����Ķ���������һȦ�͵͵���������Χ�ɡ�һλ���׼������������Ŷ����������ĺ���ǽ����һ������(paizi)��" );
    set("light_up",  1);
    set("no_fight",  1);
    set("no_magic",  1);

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
