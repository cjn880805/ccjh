NPC_BEGIN(CNpub_guanzho2);

virtual void create()
{

	set_name("������","guanzho");

	set("icon", smith_boss);
	set("gender", "����");
	set("age", 30);
	set("long","��һ��������⣬һ�������ɷ��ģ��������������η��");
	set("combat_exp", 10000);
    set("shen_type", -1);
	set("attitude", "friendly");

	set("apply/attack", 20);
	set("apply/defense", 20);


	set_skill("unarmed", 40);
	set_skill("sword", 20);
	set_skill("parry", 40);
	set_skill("dodge", 40);

    carry_object("duanjian")->wield();
    carry_object("cloth")->wear();
	add_money(10);



};


NPC_END;
