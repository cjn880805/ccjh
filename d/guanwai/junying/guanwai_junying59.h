//junying59.h  �о��ȷ�Ӫ��59
//�ز� 2002��12��9

ROOM_BEGIN(CRGuanWai_junying59);

virtual void create()			
{
	set_name("���ȷ�Ӫ��");

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
	
	add_door("�����о��ȷ�Ӫ��", "�����о��ȷ�Ӫ��44", "�������ȷ�Ӫ��59");
	add_door("�����о��ȷ�Ӫ��", "�����о��ȷ�Ӫ��58", "�������ȷ�Ӫ��59");
	add_door("�������ȷ�Ӫ��", "�������ȷ�Ӫ��510", "�������ȷ�Ӫ��59");
	add_door("�����о���կ", "�����о���կ68", "�������ȷ�Ӫ��59");
	add_door("�������ȷ�Ӫ��", "�������ȷ�Ӫ��69", "�������ȷ�Ӫ��59");


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
