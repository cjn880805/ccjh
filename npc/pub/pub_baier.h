NPC_BEGIN(CNPub_baier);

virtual void create()
{
	set_name("�׶�","baier");

	set("icon", banditi);
	set("gender", "����");
	set("title", "������");
	set("age", 30);
	set("long","���Ǹ��ھ������֣����û���������һ���������");
	set("combat_exp", 10000);
    set("shen_type", -1);
	set("attitude", "peaceful");

	set("apply/attack", 20);
	set("apply/defense", 20);

	set_skill("unarmed", 40);
	set_skill("sword", 20);
	set_skill("parry", 40);
	set_skill("dodge", 40);

    carry_object("cloth")->wear();

	add_money(1000);


};

NPC_END;
