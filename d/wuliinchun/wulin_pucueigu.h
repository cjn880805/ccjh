//wulin_pucueigu.h �̴��
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_pucueigu);

virtual void create()			
{
	set_name("�̴��");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_kid");
	if (random(2)==0)
	{
		add_npc("pub_yufu");
		add_npc("pub_youke");
	}
	add_door("���괺����","���괺����", "���괺�̴��");
	add_door("���괺������","���괺������", "���괺�̴��");

};

WL_END;
