//wulin_changlang1.h ����1
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_changlang1);

virtual void create()			
{
	set_name("����1");
	add_npc("pub_lady3");
	add_npc("pub_shicong");
	add_npc("pub_shaonu");
	add_npc("pub_jiading");
	if (random(2)==0)
	{
		add_npc("pub_girl");
		add_npc("pub_boy");
	}
	add_door("���괺�����","���괺�����", "���괺����1");
	add_door("���괺����","���괺����", "���괺����1");
	add_door("���괺������","���괺������", "���괺����1");
	add_door("���괺�³��","���괺�³��", "���괺����1");

	set("yuandan",1);
};

WL_END;
