// tuolei.c
//sound 2001-07-11

NPC_BEGIN(CNxiangyang_tuolei);

virtual void create()
{
	set_name("����", "tuo lei");
	set("long", "�����ǳɼ�˼�����ӣ����̹������˴δ����������������񣬱����¶��");
	set("gender", "����");
	set("age", 18);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 24);
	set("str", 20);
	set("int", 40);
	set("con", 20);
	set("dex", 20);
	set("attitude", "young_man5");
	
	set("max_hp", 800);
	set("hp", 800);
	set("mp", 100);
	set("max_mp", 100);
	set("combat_exp", 60000);

	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("unarmed", 40);

//	set("env/wimpy", 60);
//	set_temp("is_riding", "������");
//	set("env/wimpy", 40);

 	carry_object("tiejia")->wear();
}

NPC_END;
