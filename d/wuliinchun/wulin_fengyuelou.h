//wulin_fengyuelou.h ����¥
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_fengyuelou);

virtual void create()			
{
	set_name("����¥");
	add_door("���괺��÷̨","���괺��÷̨", "���괺����¥");
	add_door("���괺������","���괺������", "���괺����¥");
	add_door("���괺ʫ�¸�","���괺ʫ�¸�", "���괺����¥");
	add_door("���괺�ϱ�ɽׯ����","���괺�ϱ�ɽׯ����", "���괺����¥");

	CContainer * env = load_room("jy");
	if(env->query("�"))
		add_npc("pub_lvdongbing"); //������
		
	set("yuandan",1);

};

WL_END;
