//wulin_ningmouge.h ������
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_ningmouge);

virtual void create()			
{
	set_name("������");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
		add_npc("pub_girl");
		add_npc("dali_guigongzi");
	}
	CContainer * env = load_room("jy");
	if(env->query("�"))
		add_npc("pub_hexiangu");//���ɹ�

	add_door("���괺����1","���괺����1", "���괺������");
	add_door("���괺����ɽׯ��Ժ","���괺����ɽׯ��Ժ", "���괺������");

	set("yuandan",1);
};

WL_END;
