//wulin_nianwoge.h ���Ҹ�
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_nianwoge);

virtual void create()			
{
	set_name("���Ҹ�");
	add_npc("pub_lady3");
	add_npc("pub_lady2");
	add_npc("pub_lady1");
	add_door("���괺����2","���괺����2", "���괺���Ҹ�");

	set("yuandan",1);
};

WL_END;
