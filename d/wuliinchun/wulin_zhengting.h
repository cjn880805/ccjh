//wulin_zhengting.h ����
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_zhengting);

virtual void create()			
{
	set_name("����");
	add_npc("pub_pian");
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("monster_8k");
	add_door("���괺�ϱ�ɽׯ����","���괺�ϱ�ɽׯ����", "���괺����");
	add_door("���괺Ⱦ����","���괺Ⱦ����", "���괺����");
	add_door("���괺��Ũ��","���괺��Ũ��", "���괺����");
	add_door("���괺��÷̨","���괺��÷̨", "���괺����");

	set("yuandan",1);

};

WL_END;
