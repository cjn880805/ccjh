VENDOR_BEGIN(CNpub_xiaohuoji);

virtual void create()
{
	set_name("药铺小伙计","xiaohuoji");

	set("icon", waiter);
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他是苏州乡下小伙子。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");

	carry_good("yuchandan", 10);

	carry_object("cloth")->wear();

};


VENDOR_END;
