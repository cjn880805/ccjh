//wulin_diyuange.h ��Թ��
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_diyuange);

virtual void create()			
{
	set_name("��Թ��");
	add_npc("monster_16k");
	add_npc("monster_8k");

	CContainer * env = load_room("jy");
	if(env->query("�"))
		add_npc("pub_hanxiangzi");//������
	set("yuandan",1);

	add_door("���괺��÷̨","���괺��÷̨", "���괺��Թ��");

};

WL_END;
