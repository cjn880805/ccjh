NPC_BEGIN(CNpub_girl1);

virtual void create()
{
	
	set_name("南国姑娘","girl");
	
	set("icon", young_woman3);
	set("gender", "女性" );
	set("age", 22);
	set("long", "南国的大姑娘颇带有当地优美秀丽山水的风韵，甜甜的笑，又有天真的浪漫。她穿着白色上衣，蓝色的宽裤，外面套着黑丝绒领褂，头上缠着彩色的头巾。");
	set_temp("apply/defense", 7);
	set("combat_exp", 2000);
	set("shen_type", 1);
	set("per", 25);
	set("str", 24);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	
	carry_object("whitecloth1")->wear();
	
	add_money(50);
};



NPC_END;
