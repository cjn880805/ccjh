// lingjiu_jiuyi.c

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNlingjiu_jiuyi);

virtual void create()
{
	set_name("九头道人","jiuyi daoren");
	set("long","他是西夏一品堂礼聘的高手,身材高瘦,脸上总是阴沉沉的,他轻功极高,擅使雷公挡,凭一手雷公挡功夫,成为江湖的一流高手.");
	set("title", "西夏一品堂高手");
	set("gender", "男性");
	set("nickname",  "霸王长吼" );
	set("age", 40);
	set("shen_type",-1);
	set("attitude", "peaceful");
 	set("icon",young_man3);

	set("str", 27);
	set("int", 23);
	set("con", 24);
	set("dex", 30);
        set("icon",old_man1);

	
	set("max_hp", 3000);
 	set("hp", 1000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 0l);

	set("combat_exp", 1000000);
	set("score", 100000);
	
}

NPC_END;