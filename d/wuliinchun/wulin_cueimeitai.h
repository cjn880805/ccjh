//wulin_cueimeitai.h ��÷̨
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_cueimeitai);

virtual void create()			
{
	set_name("��÷̨");
	add_npc("pub_playboy");
	add_npc("pub_playboy");
	add_npc("pub_enu");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
		add_npc("pub_girl");
		add_npc("monster_6k");
	}
	add_door("���괺����","���괺����", "���괺��÷̨");
	add_door("���괺��Թ��","���괺��Թ��", "���괺��÷̨");
	add_door("���괺������","���괺������", "���괺��÷̨");
	add_door("���괺����¥","���괺����¥", "���괺��÷̨");

	set("yuandan",1);

};

WL_END;
