//junying21.h  �о��ȷ�Ӫ��1
//�ز� 2003��6��5

ROOM_BEGIN(CRGuanWai_junying21);

virtual void create()			
{
	set_name("�о��ȷ�Ӫ��");

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
	
	add_door("��Ӫ", "�����Ӫ", "�����о��ȷ�Ӫ��1");
	add_door("���ȷ�Ӫ��2", "�������ȷ�Ӫ��2", "�����о��ȷ�Ӫ��1");
	add_door("�о��ȷ�Ӫ��2", "�����о��ȷ�Ӫ��2", "�����о��ȷ�Ӫ��1");
	add_door("�о��ȷ�Ӫ��3", "�����о��ȷ�Ӫ��3", "�����о��ȷ�Ӫ��1");

	set("long","�˴����о��ȷ�Ӫ�ʣ������ϵ������ʿ�ȷ�ٺ���������˾�����ʲ��½���ͬ��׳�У�ֻ���������ڲ�����ʿ��������Ϳ��Ѫ���������������������������ư׻�����ţ�����䣬��ͷ���ؿڡ��˵�ɱ�ˣ���ɱ��ɷ�ǿ��¡�" );

};

ROOM_END;
