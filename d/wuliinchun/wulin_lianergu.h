//wulin_lianergu.h ������
//�ز� 2002.5.31

WL_BEGIN(CRWuLin_lianergu);

virtual void create()			
{
	set_name("������");
	add_npc("pub_jianke");
	add_npc("pub_daoke");
	add_npc("monster_40k");
	if (random(2)==0)
	{
		add_npc("pub_liumangtou");
		add_npc("pub_tiaofu");
	}
	add_door("���괺Ц���","���괺Ц���", "���괺������");
	add_door("���괺ѩ�޷�","���괺ѩ�޷�", "���괺������");

};

WL_END;
