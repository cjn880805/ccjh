NPC_BEGIN(CNPub_chengqi);

virtual void create()
{
	set_name("����","chengqi");

	set("icon", young_man4);
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

    carry_object("tiehuyao")->wear();
    carry_object("tiehuwan")->wear();
    carry_object("male3_cloth")->wear();

	add_money(100);

};

NPC_END;
