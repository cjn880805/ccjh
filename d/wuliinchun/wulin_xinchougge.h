//wulin_xinchougge.h �³��
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_xinchougge);

virtual void create()			
{
	set_name("�³��");
	add_npc("pub_youngwoman");
	add_npc("pub_lady3");
	add_door("���괺����1","���괺����1", "���괺�³��");
	add_door("���괺����2","���괺����2", "���괺�³��");

	set("yuandan",1);
};

WL_END;
