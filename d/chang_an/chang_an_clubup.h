//clubup.h

//Sample for room: �����ַ���¥����
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_clubup);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ַ���¥����");

	add_npc("pub_xiaoer1");  // zdn 2001-07-12 add
	add_npc("pub_yicimengzi");

	add_door("�����ַ�", "�����ַ�", "�����ַ���¥����");
	add_door("�����ָ�ʫ��", "�����ָ�ʫ��", "�����ַ���¥����");
	add_door("����Ѻǩ��", "����Ѻǩ��", "�����ַ���¥����");
	add_door("����������", "����������", "�����ַ���¥����");
	add_door("����������", "����������", "�����ַ���¥����");
	add_door("�������귿", "�������귿", "�����ַ���¥����");

	set("long", "�ַ�¥���Եø������֣����������������������������������ӣ���ǩ����Ǯ�����̵����������������ӣ������Ƕĵ������ء�" );
	
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




