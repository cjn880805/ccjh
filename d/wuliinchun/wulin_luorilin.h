//wulin_luorilin.h ������
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_luorilin);

virtual void create()			
{
	set_name("������");
	add_npc("pub_xianren");
	add_npc("pub_playboy");
	add_npc("pub_playboy");
	add_npc("pub_dibao");
	add_npc("pub_girl");
	add_npc("pub_boy");
	add_npc("pub_laocunzhang");

	CContainer * env = load_room("jy");
	if(env->query("�"))
		add_npc("pub_caoguojiou"); //�ܹ���

	add_door("���괺�̴��","���괺�̴��", "���괺������");
	add_door("���괺�۽��","���괺�۽��", "���괺������");
	add_door("���괺��ͷϪ","���괺��ͷϪ", "���괺������");
	add_door("��ɽ������","��ɽ������", "���괺������");

};

WL_END;
