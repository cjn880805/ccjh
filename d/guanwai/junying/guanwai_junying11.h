//junying11.h  ���ȷ�Ӫ��1
//�ز� 2003��6��5

ROOM_BEGIN(CRGuanWai_junying11);

virtual void create()			
{
	set_name("���ȷ�Ӫ��");

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
	
	add_door("��Ӫ", "�����Ӫ", "�������ȷ�Ӫ��1");
	add_door("���ȷ�Ӫ��2", "�������ȷ�Ӫ��2", "�������ȷ�Ӫ��1");
	add_door("���ȷ�Ӫ��3", "�������ȷ�Ӫ��3", "�������ȷ�Ӫ��1");

	set("long","�˴������ȷ�Ӫ�ʣ������У������У�������������ɱ����ǹ����ҫ���ɺ��⡣���˵��ˣ��Ȳ���Ҳ�ô�����¡�" );

};

ROOM_END;
