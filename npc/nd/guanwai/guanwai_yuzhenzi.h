// yuzhenzi.c
//sound 2001-07-18

NPC_BEGIN(CNguanwai_yuzhenzi);

virtual void create()
{
	set_name("������", "yuzhen zi");
	set("gender", "����");
	set("title", "������������");
	set("nickname", "��������");
	set("age", 44);
	set("str", 25);
	set("dex", 20);
	set("icon",taoist_with_sword);	
	set("long", 
		"����һλ�����ɷ���ǵ�����ȫ�棬���ճ�����Ŀ��ǰ����\n"
		"������ľ�ٵ��˵�ʦ�ܣ�������Ѱ�ñ�����������Ϊ�������ţ�"
		"������ˣ�������ֹȷʮ�ֲ��ˡ�\n");
	set("combat_exp", 900000);
	set("score", 10000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	set("hp", 1000);
	set("max_hp", 1000);
	set("hp", 3000);
	set("max_hp", 3000);

	set_skill("sword", 150);
	set_skill("force", 90);
	set_skill("unarmed", 90);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("huashan_sword", 150);
	set_skill("shenxing_baibian", 150);
	map_skill("sword",  "huashan_sword");
	map_skill("parry", "huashan_sword");
	map_skill("dodge", "shenxing_baibian");

	set("mp", 1500); 
	set("max_mp", 1500);
	set("mp_factor", 100);

	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	add_money(2000);
}

NPC_END;
