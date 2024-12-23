//chenjuyang.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHongHua_chenjuyang);

virtual void create()
{

	set_name("陈居阳","chen ju yang");

	set("title", "红花会总舵主" );
	set("long","他一副模样直是个富贵人家的纨裤子弟，丰姿如玉，目朗似星，轻袍缓带，手中摇着一柄折扇，神采飞扬，气度闲雅，吐属斯文。服饰俨然是个贵介公子。");
	set("nickname", "玉面神龙");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 22);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 30);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",young_man3);
	
	set("max_hp", 9000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 100);
	set("combat_exp", 1000000);
	set("score", 500000);

	set_skill("literate", 100);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("whip", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);
	set_skill("yunlong_xinfa", 200);
	set_skill("yunlong_shengong", 200);
	set_skill("wuhuduanmendao", 150);
	set_skill("yunlong_jian", 200);
	set_skill("yunlong_shenfa", 150);
	set_skill("yunlong_bian", 150);
	set_skill("yunlong_shou", 150);
	set_skill("yunlong_zhua", 150);

	map_skill("dodge", "yunlong_shenfa");
	map_skill("force", "yunlong_shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhuduanmendao");
	map_skill("hand", "yunlong_shou");
	map_skill("parry", "yunlong_shou");
	map_skill("claw", "yunlong_zhua");
	map_skill("sword", "yunlong_jian");
	map_skill("whip", "yunlong_bian");

	prepare_skill("hand","yunlong_shou");
	prepare_skill("claw","yunlong_zhua");
	set("env/wimpy", 60);

	carry_object("jinduan")->wear();
	carry_object("yaodai")->wear();
	carry_object("changjian")->wield();
}


NPC_END;