//wulin_houyuandamen.h ����ɽׯ��Ժ����
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_houyuandamen);

virtual void create()			
{
	set_name("����ɽׯ��Ժ����");
	add_npc("monster_40k");
	add_npc("monster_32k");
	add_npc("monster_10k");
	add_door("���괺����ɽׯ��Ժ","���괺����ɽׯ��Ժ", "���괺����ɽׯ��Ժ����");
	add_door("���괺����С��","���괺����С��", "���괺����ɽׯ��Ժ����");
};

WL_END;
