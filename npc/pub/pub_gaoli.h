// pub_gaoli.c
//code by Fisho
//date : 2000-12-14
//inherit F_VENDOR;
//inherit F_DEALER;

VENDOR_BEGIN(CNpub_gaoli);

virtual void create()
{
	set_name("高丽商","gaoli shang" );

	set("icon", pawnshop_boss);
	set("title", "新罗坊老板");
	set("shen_type", 1);
	
	set("gender", "男性");
	set("age", 45);
	set("long",		"这是个高丽商人，长得和中国人没啥区别。连卖的东西也差不多。");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);
	
	set("combat_exp", 40000);
	set("attitude", "friendly");
	
	carry_object("cloth")->wear();
//	carry_good("mabudai",500);
	carry_good("beixin",500);
	carry_good("toukui",500);
	carry_good("cycle",500);
	carry_good("surcoat",500);
	carry_good("shield",500);
	carry_good("huwan",500);
	carry_good("zhitao",500);
	carry_good("huyao",500);
	carry_good("caoxie",500);
	carry_good("pixue",500);
	carry_good("shoutao",500);
	carry_good("tieshou",500);
	carry_good("jinsijia",500);
//	carry_good("fire",500);
}

VENDOR_END;