//club.h

//Sample for room: �����ַ�
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_club);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ַ�");

	add_npc("pub_xiaoer1");
	add_npc("pub_shinu1");       //zdn 2001-07-12  add

	add_door("����", "����", "�����ַ�");
	add_door("�����ַ���¥����", "�����ַ���¥����", "�����ַ�");

	set("long", "�����ǳ�����һ�����������ֳ�������ҹĻ���ٺ�����͸������֡����������Ŀ����д�ٹ��ˣ��������������ã��˼����ĵ����ӣ������Ⱥ�ı�ʿ����ʱҲ�ܿ���һЩ���׿ʹ���ɮ�˻��ʿ��" );
	
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
