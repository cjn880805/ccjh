//wulin_jingniting.h �����
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_jingniting);

virtual void create()			
{
	set_name("�����");
	add_npc("helpnpc_jhlz");
	add_npc("wudang_laodaoshi");
	add_npc("pub_youngwoman");
	add_npc("pub_jiading");
	add_door("���괺���˸�","���괺���˸�", "���괺�����");
	add_door("���괺�����","���괺�����", "���괺�����");
	add_door("���괺��¥","���괺��¥", "���괺�����");
	add_door("���괺����ɽׯ����","���괺����ɽׯ����", "���괺�����");

	set("yuandan",1);

};

WL_END;
