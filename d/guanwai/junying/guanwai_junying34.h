//junying34.h  ���ȷ�Ӫ��4
//�ز� 2003��6��5

ROOM_BEGIN(CRGuanWai_junying34);

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
	
	add_door("���ȷ�Ӫ��2", "�������ȷ�Ӫ��2", "�������ȷ�Ӫ��4");
	add_door("����Ӫ��2", "��������Ӫ��2", "�������ȷ�Ӫ��4");
	add_door("���ȷ�Ӫ��3", "�������ȷ�Ӫ��3", "�������ȷ�Ӫ��4");

	set("long","�˴������ȷ�Ӫ�ʣ����½�����ɽ��·֮��������ˮ���ŵ���ʿ������ʱ��ҡ���죬�������ء����Ǿ��ݶ�ʢ��" );

};

ROOM_END;
