//xian.h
//code by zwb
//12-15

VENDOR_BEGIN(CNPub_xian);

virtual void create()
{
	set_name("冼老板","xian");
	
	set("icon", pub_boss);
	set("title", "醉仙楼老板");
	set("shen_type", 1);
	
	set("str", 20);
	set("gender", "男性");
	set("age", 45);
	set("long", "洗老板经营祖传下来的醉仙楼已有多年。");
	
	set("combat_exp", 50000);
    set("hp", 300);
    set("max_hp", 900);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
    set_skill("dodge", 60);
    set_temp("apply/attack", 30);
    set_temp("apply/defense", 30);
	
	carry_good("hdjiudai",20);
	carry_good("kaoya",20);
	
    add_money(100);
	carry_object("cloth")->wear();
};

VENDOR_END;
