//wulin_beiqiouge.h �����
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_beiqiouge);

virtual void create()			
{
	set_name("�����");
	add_npc("monster_4k");
	add_npc("monster_13k");
	add_npc("pub_jiading");
	if (random(2)==0)
	{
		add_npc("pub_girl");
		add_npc("pub_huanu");
	}
	add_door("���괺�����","���괺�����", "���괺�����");
	add_door("���괺����1","���괺����1", "���괺�����");
	add_door("���괺����2","���괺����2", "���괺�����");

	set("yuandan",1);

};

WL_END;
