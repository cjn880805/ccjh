// wudang_yuhuan.c ���� 

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNwudang_yuhuan);

virtual void create()
{
	set_name("��С��",  "cheng yuhuan");
	set("long", "�����ǳ�֪���Ķ���Ů���������绨����ò�����ɡ���˵���������䵱����ѧ�������� ");
	
	set("title", "֪��ǧ��");
	set("nickname", "��֮��");
	set("gender", "Ů��");
	set("age", 18);
        set("icon",girl2);

	set("shen_type", 1);
	
	set("mp", 400);
	set("max_mp", 400);
	set("max_hp", 1200);
	set("mp_factor", 10);
	
	set_skill("force", 50);
	set_skill("unarmed", 40);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("taiji_jian", 40);
	map_skill("sword", "taiji_jian");
	map_skill("parry", "taiji_jian");
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 15);
	
	set("combat_exp", 50000);
	
	carry_object("goldring")->wear();
	carry_object("necklace")->wear();
	carry_object("changjian")->wield();
	carry_object("pink_cloth")->wear();
	carry_object("flower_shoe")->wear();
}
NPC_END;