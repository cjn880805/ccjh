//wulin_muyunge.h ĺ�Ƹ�
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_muyunge);

virtual void create()			
{
	set_name("ĺ�Ƹ�");
	add_npc("pub_playboy");
	add_npc("pub_playboy");
	add_npc("pub_girl1");
	add_door("���괺�۽��","���괺�۽��", "���괺ĺ�Ƹ�");
	add_door("���괺�ϱ�ɽׯ����","���괺�ϱ�ɽׯ����", "���괺ĺ�Ƹ�");

	set("yuandan",1);

};

WL_END;
