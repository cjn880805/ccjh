//tufei1.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_tufei1);

virtual void create()
{
	set_name("���˼�","tufei");

	set("icon", banditi);
	set("gender", "����");
	set("age", 30);
	set("long","��һ��������⪬һ�������ɷ��ģ��������������η��\n");
	set("combat_exp", 10000);
    set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack", 20);
	set("apply/defense", 20);

//	set("chat_chance", 30);
//	set("chat_msg", ({
//		"����һ����: ��ɽ���ҿ������������ԣ���Ҫ�Ӵ˹���������·�� !\n",
//	}) );

	set_skill("unarmed", 40);
	set_skill("sword", 20);
	set_skill("parry", 40);
	set_skill("dodge", 40);

    carry_object("duanjian")->wield();
    carry_object("cloth")->wear();
	add_money(1);

};


NPC_END;