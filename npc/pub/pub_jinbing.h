NPC_BEGIN(CNpub_jinbing);

virtual void create()
{
	set_name("����","jinbing");

	set("icon", general);
	set("gender", "����");
	set("age", 25);
	set("long", "��Щ�󺺸������������������⽡��");
	set("combat_exp", 40000);
    set_skill("dodge", 50);
    set_skill("unarmed", 50);
    set_temp("apply/attack",  50);
    set_temp("apply/defense", 50);
	set("shen_type", 1);

	add_money(3);
	carry_object("cloth")->wear();



};

NPC_END;
