//wulin_shilvge.h ʫ�¸�
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_shilvge);

virtual void create()			
{
	set_name("ʫ�¸�");
	add_npc("dali_guigongzi");
	add_npc("pub_lady2");
	add_door("���괺����¥","���괺����¥", "���괺ʫ�¸�");

	set("yuandan",1);
};

WL_END;
