//junying64.h  ���Ӫ��4
//�ز� 2003��6��5

ROOM_BEGIN(CRGuanWai_junying64);

virtual void create()			
{
	set_name("���Ӫ��");

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
	
	add_door("���Ӫ��2", "������Ӫ��2", "������Ӫ��4");
	add_door("���Ӫ��3", "������Ӫ��3", "������Ӫ��4");

	set("long","�������������ͷ�֮�صأ�����ɭ�ϡ����ó�ͳ˧��ñ���Ҫּ��" );

};

ROOM_END;
