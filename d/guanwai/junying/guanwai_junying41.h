//junying41.h  ����Ӫ��1
//�ز� 2003��6��5

ROOM_BEGIN(CRGuanWai_junying41);

virtual void create()			
{
	set_name("����Ӫ��");

	set("renwu", 1);

	add_npc("pub_songbing1");
	add_npc("pub_songbing1");
	if(random(2))
	{
		add_npc("pub_songbing1");
		add_npc("pub_songjiang1");
	}
	add_npc("pub_songjiang1");
	add_npc("pub_songjiang1");
	
	add_door("���ȷ�Ӫ��3", "�������ȷ�Ӫ��3", "��������Ӫ��1");
	add_door("����Ӫ��2", "��������Ӫ��2", "��������Ӫ��1");
	add_door("����Ӫ��3", "��������Ӫ��3", "��������Ӫ��1");

	set("long","����ʿ�����ڱ��������������ڳ����Ϸ�۵糸�����·��ڣ����ܱ�ʿ�к���һƬ��" );

};

ROOM_END;
