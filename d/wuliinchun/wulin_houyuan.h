//wulin_houyuan.h ����ɽׯ��Ժ
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_houyuan);

virtual void create()			
{
	set_name("����ɽׯ��Ժ");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	add_npc("monster_4k");
	if (random(2)==0)
	{
		add_npc("pub_lady1");
		add_npc("pub_lady2");
	}
	add_door("���괺������","���괺������", "���괺����ɽׯ��Ժ");
	add_door("���괺����ɽׯ��Ժ����","���괺����ɽׯ��Ժ����", "���괺����ɽׯ��Ժ");

	set("yuandan",1);
};

WL_END;
