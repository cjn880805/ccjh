//changsanmei.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHongHua_changsanmei);

virtual void create()
{

	set_name("常三眉","chang san mei");

	set("title", "红花会六当家" );
	set("nickname",  "三眉道长");;
	set("long","他身材又高又瘦，脸色蜡黄，眼睛凹进，在两条眉毛当中竟然还有一条，看上去有点象自己画的。");
	set("gender", "男性");
	set("class", "fighter");
	set("age", 42);
	set("attitude", "aggressive");
	set("shen_type", 1);
	set("per", 14);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",old_man2);
	
	set("max_hp", 7500);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 100);
	set("combat_exp", 500000);

	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("hand", 120);
	set_skill("claw", 120);
	set_skill("yunlong_shengong", 120);
	set_skill("yunlong_shenfa", 120);
	set_skill("yunlong_shou", 120);
	set_skill("yunlong_zhua", 120);

	map_skill("dodge", "yunlong_shenfa");
	map_skill("force", "yunlong_shengong");
	map_skill("hand", "yunlong_shou");
	map_skill("parry", "yunlong_shou");
	map_skill("claw", "yunlong_zhua");

	prepare_skill("hand","yunlong_shou");
	prepare_skill("claw","yunlong_zhua");
	set("env/wimpy", 20);
	create_family("青城派",21, "弟子");

	carry_object("cloth")->wear();
}


NPC_END;