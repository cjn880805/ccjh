//wulin_ranliouchi.h Ⱦ����
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_ranliouchi);

virtual void create()			
{
	set_name("Ⱦ����");
	add_npc("pub_youke");
	add_npc("pub_youke");
	add_npc("dali_guigongzi");
	if (random(2)==0)
	{
		add_npc("pub_shinu1");
		add_npc("monster_28k");
	}

	CContainer * env = load_room("jy");
	if(env->query("�"))
		add_npc("pub_zhangguolao");//�Ź���

	add_door("���괺����","���괺����", "���괺Ⱦ����");

	set("yuandan",1);

};

WL_END;
