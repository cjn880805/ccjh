//junying13.h  ���ȷ�Ӫ��3
//�ز� 2003��6��5

ROOM_BEGIN(CRGuanWai_junying13);

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
	
	add_door("���ȷ�Ӫ��1", "�������ȷ�Ӫ��1", "�������ȷ�Ӫ��3");
	add_door("����Ӫ��1", "��������Ӫ��1", "�������ȷ�Ӫ��3");
	add_door("���ȷ�Ӫ��4", "�������ȷ�Ӫ��4", "�������ȷ�Ӫ��3");

	set("long","�˴������ȷ�Ӫ�ʣ������У������У�������������ɱ����ǹ����ҫ���ɺ��⡣���˵��ˣ��Ȳ���Ҳ�ô�����¡�" );

};

ROOM_END;
