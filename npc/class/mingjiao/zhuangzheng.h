//zhuangzheng
//Lanwood
//2001-01-09

MINGJIAOZHANGQISHI_BEGIN(CNmingjiao_zhuangzheng);

virtual void create()
{
	set_name("庄锵","zhuang qiang");
	set("long","他是一位高大魁伟的中年男子，身穿一件白布长袍。他天生神力，手中的两头狼牙棒有万夫不当之勇，真是一条威风凛凛的汉子。");
	
	set("title",  "锐金旗掌旗使");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "fighter");
	set("icon",young_man1);
	create_family("明教",37, "掌旗使");
	set_weight(50000000);
	
	CMapping par;

	par.set("level", 3);
	set("party", par);

	set("age", 42);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_hp", 3000);
	set("hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 200000);
	set("score", 5000);
	
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
    set_skill("unarmed", 80);
	set_skill("sword", 120);
	set_skill("mingwang_jian", 120);
	set_skill("literate", 80);
	set_skill("shenghuo_shengong", 80);
	set_skill("shenghuo_xinfa", 80);
	set_skill("piaoyibu", 80);
	
    map_skill("force", "shenghuo_shengong");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "mingwang_jian");
	map_skill("sword", "mingwang_jian");

 	carry_object("changjian")->wield();
	carry_object("baipao")->wear();
}

MINGJIAOZHANGQISHI_END;



