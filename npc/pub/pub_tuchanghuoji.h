//inherit F_CLEAN_UP;
NPC_BEGIN(CNpub_tuchanghuoji);


virtual void create()
{
	set_name("���׳����","tuchanghuoji");

	set("icon", waiter);
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set("long", "��ʮ��ǿ׳������ȥ�Ἰ���书��");
	set("combat_exp", 10000);
	set_skill("unarmed", 30);
	set_skill("blade", 60);
	set_skill("dodge", 30);
	set_skill("parry", 50);
	set("attitude", "friendly");

    carry_object("tudao")->wield();
	carry_object("cloth")->wear();
	add_money(5);


};


NPC_END;
