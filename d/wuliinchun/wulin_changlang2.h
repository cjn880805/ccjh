//wulin_changlang2.h ����2
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_changlang2);

virtual void create()			
{
	set_name("����2");
	add_npc("pub_boy");
	add_npc("pub_cunfu");
	add_door("���괺�����","���괺�����", "���괺����2");
	add_door("���괺���Ҹ�","���괺���Ҹ�", "���괺����2");
	add_door("���괺�³��","���괺�³��", "���괺����2");

	set("yuandan",1);

};

WL_END;
