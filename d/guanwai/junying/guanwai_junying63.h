//junying63.h  ���Ӫ��3
//�ز� 2003��6��5

ROOM_BEGIN(CRGuanWai_junying63);

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
	
	add_door("���Ӫ��1", "������Ӫ��1", "������Ӫ��3");
	add_door("���Ӫ��4", "������Ӫ��4", "������Ӫ��3");

	set("long","�������������ͷ�֮�صأ�����ɭ�ϡ����ó�ͳ˧��ñ���Ҫּ��" );

};

ROOM_END;
