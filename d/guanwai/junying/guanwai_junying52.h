//junying52.h  ����Ӫ��2
//�ز� 2003��6��5

ROOM_BEGIN(CRGuanWai_junying52);

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
	
	add_door("����Ӫ��1", "��������Ӫ��1", "��������Ӫ��2");
	add_door("���ȷ�Ӫ��4", "�������ȷ�Ӫ��4", "��������Ӫ��2");
	add_door("����Ӫ��4", "��������Ӫ��4", "��������Ӫ��2");

	set("long","����Ӫ�����ڹ�ĦӪ�����䱸�ķ��ʻ��������ǹ��������ݡ�����¡¡��ǹ�����󣬼�Ъ�������׵�������" );

};

ROOM_END;
