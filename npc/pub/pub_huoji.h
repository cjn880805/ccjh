VENDOR_BEGIN(CNpub_huoji);

virtual void create()
{
	set_name("药铺伙计","huoji");

	set("icon", waiter);
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他十分强壮，看上去会几分武功，对药铺生意似乎并不在乎。");
	set("combat_exp", 15000);
	set("attitude", "friendly");

	carry_good("jinchuang",500);
	carry_good("yangjing",500);
	carry_good("gaoyao",500);
	carry_good("yuchandan", 10);
	carry_good("hongzao", 1);
	carry_good("xinren", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);

	carry_object("cloth")->wear();

	add_money(5);


};


VENDOR_END;
