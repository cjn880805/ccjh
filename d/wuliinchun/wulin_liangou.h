//wulin_liangou.h ����
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_liangou);

virtual void create()			
{
	set_name("����");
	add_npc("pub_shaonu");
	add_npc("pub_lady3");
	add_npc("pub_girl1");
	add_door("���괺����1","���괺����1", "���괺����");

	set("yuandan",1);
};

WL_END;
