//huashancuen.h

//Sample for room  ��ɽ��
//coded by zwb
//data: 2000-11-18
RESIDENT_BEGIN(CRHuaShancuen);

virtual void create()		
{
	set_name( "��ɽ��");

	set("resident", "��ɽ��");
				
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
	add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}
	add_door("��ɽ����ʯ���", "��ɽ����ʯ���", "��ɽ��");
	add_door("��ɽ����", "��ɽ����", "��ɽ��");

	add_door("��ɽ�����", "��ɽ�����", "��ɽ��");
	add_door("��ɽ����", "��ɽ����", "��ɽ��");
	add_door("��ɽ����լ", "��ɽ����լ", "��ɽ��");
	add_door("��ɽ����̳��", "��ɽ����̳��", "��ɽ��");
	add_door("��ɽ��������", "��ɽ��������", "��ɽ��");
	add_door("��ɽ���ӻ���", "��ɽ���ӻ���", "��ɽ��");
	//add_door("��ɽ�������ǰ��", "��ɽ�������ǰ��", "��ɽ��");

};


RESIDENT_END;
