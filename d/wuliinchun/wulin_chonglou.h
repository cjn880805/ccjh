//wulin_chonglou.h ��¥
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_chonglou);

virtual void create()			
{
	set_name("��¥");
	add_npc("pub_shinu1");
	add_npc("monster_8k");
	add_npc("pub_girl1");
	add_door("���괺�����","���괺�����", "���괺��¥");
	set("sleep_room",1);

	set("yuandan",1);
};

WL_END;
