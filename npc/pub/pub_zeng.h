// pub_zeng.c
//code by Fisho
//date : 2000-12-14
//inherit F_DEALER;

VENDOR_BEGIN(CNpub_zeng);

virtual void create()
{
	set_name("����", "zeng ru" );
	set("shen_type", 1);

	set("icon", young_woman12);
	set("gender", "Ů��");
	set("age", 16);
	set("per", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);
	set("str", 25);
	set("long","���Ǻξ�ү��֪���ڼ�����С檣������￪�������̣���Щ��֪���������·�������˵�Ƕ��Ǻξ�ү�ӹ���Ū�����Ľ�Ʒ������ô˵������������");
	set_skill("unarmed", 60);
	set_skill("changquan", 60);
	map_skill("unarmed", "changquan");
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");

	carry_good("belt",500);
	carry_good("boots",500);
	carry_good("bu_shoes",500);
	carry_good("cloth",500);
	carry_good("color_dress",500);
	carry_good("feather",500);
	carry_good("fu_cloth",500);
	carry_good("gui_dress",500);
	carry_good("hat",500);
	carry_good("jade_belt",500);
	carry_good("liu_dress",500);
	carry_good("marry_dress",500);
	carry_good("mini_dress",500);
	carry_good("moon_dress",500);
	carry_good("pink_dress",500);
	carry_good("qi_dress",500);
	carry_good("red_dress",500);
	carry_good("scarf",500);
	carry_good("sha_dress",500);
	carry_good("shoes",500);
	carry_good("xian_cloth",500);
	carry_good("xiu_cloth",500);
	carry_good("xiu_scarf",500);
	carry_good("yan_dress",500);
	carry_good("zi_dress",500);
 	
	carry_object("feather")->wear();
}

VENDOR_END;