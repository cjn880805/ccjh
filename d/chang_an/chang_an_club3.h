//club3.h

//Sample for room: ����������
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_club3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");

	add_npc("pub_xiaoer1");  // zdn 2001-07-12 add

	add_door("�����ָ�ʫ��", "�����ָ�ʫ��", "����������");
	add_door("������¥����", "������¥����", "����������");
	add_door("��������������", "��������������", "����������");

	set("long", "����һ��������Ĵ������������м���һ��Բ�ε����ӡ������������˸��ֹ�棺�л����ģ������Ҿߵģ����������Ļ����Ҵ��ƴ�Ĺ�档���Ķ����������и��ţ����洫�����������������ˣ����ȵĽ�����" );
    set("light_up",  1);
    set("no_magic",  1);
    set("no_fight",  1);  

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
