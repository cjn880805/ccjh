//wulin_zhongzhouxiaodao.h ����С��
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_zhongzhouxiaodao);

virtual void create()			
{
	set_name("����С��");
	add_npc("monster_1632k");
	add_npc("monster_3248k");
	add_npc("pub_menmian");
	add_npc("pub_xiaozei");
	add_npc("pub_thief");
	
	CContainer * env = load_room("jy");
	if(env->query("�"))
		add_npc("pub_tieguaili");//������

	add_door("���괺�ϱ�ɽׯ����","���괺�ϱ�ɽׯ����", "���괺����С��");
	add_door("���괺Ц���","���괺Ц���", "���괺����С��");
	add_door("���괺����ɽׯ��Ժ����","���괺����ɽׯ��Ժ����", "���괺����С��");


};

WL_END;
