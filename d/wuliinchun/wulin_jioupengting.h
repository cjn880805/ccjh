//wulin_jioupengting.h ������
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_jioupengting);

virtual void create()			
{
	set_name("������");
	add_npc("pub_gongzi");
	add_npc("monster_16k");
	add_npc("monster_13k");
	add_npc("monster_28k");
	if (random(2)==0)
	{
		add_npc("monster_10k");
		add_npc("pub_playboy");
	}

	CContainer * env = load_room("jy");
	if(env->query("�"))
		add_npc("pub_hanzhongli"); //������

	add_door("���괺��÷̨","���괺��÷̨", "���괺������");
	add_door("���괺����¥","���괺����¥", "���괺������");

	set("yuandan",1);

};

WL_END;
