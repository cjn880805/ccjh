//junying51.h  ����Ӫ��1
//�ز� 2003��6��5

ROOM_BEGIN(CRGuanWai_junying51);

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
	
	add_door("����Ӫ��2", "��������Ӫ��2", "��������Ӫ��1");
	add_door("����Ӫ��3", "��������Ӫ��3", "��������Ӫ��1");

	set("long","����Ӫ�����ڹ�ĦӪ�����䱸�ķ��ʻ��������ǹ��������ݡ�����¡¡��ǹ�����󣬼�Ъ�������׵�������" );

};

ROOM_END;
