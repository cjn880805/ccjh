//junying1.h  ��Ӫ1
//�ز� 2002��12��9

ROOM_BEGIN(CRGuanWai_junying1);

virtual void create()			
{
	set_name("�о��ȷ�Ӫ��");

	set("renwu", 1);

	add_npc("pub_songbing1");
	add_npc("pub_songbing1");
	add_npc("pub_songbing1");
	if(random(2))
	{
		add_npc("pub_songbing1");
		add_npc("pub_songjiang1");
	}

	add_npc("pub_songjiang1");
	add_npc("pub_songjiang1");
	
	add_door("��������ͷ", "��������ͷ", "�����о��ȷ�Ӫ��");
	add_door("�����о��ȷ�Ӫ��", "�����о��ȷ�Ӫ��21", "�����о��ȷ�Ӫ��");
	add_door("�����о��ȷ�Ӫ��", "�����о��ȷ�Ӫ��22", "�����о��ȷ�Ӫ��");

	set("long","�˴����о��ȷ�Ӫ�ʣ������ϵ������ʿ�ȷ�ٺ���������˾�����ʲ��½���ͬ��׳�У�ֻ���������ڲ�����ʿ��������Ϳ��Ѫ���������������������������ư׻�����ţ�����䣬��ͷ���ؿڡ��˵�ɱ�ˣ���ɱ��ɷ�ǿ��¡�" );

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
