//wulin_yannongge.h ��Ũ��
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_yannongge);

virtual void create()			
{
	set_name("��Ũ��");
	add_npc("wudang_laodaoshi");
	add_door("���괺����","���괺����", "���괺��Ũ��");
    set("sleep_room",1);

	set("yuandan",1);

};

WL_END;
