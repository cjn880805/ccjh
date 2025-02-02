//cheng_xing.h
//Lanwood 2000-01-09

SHAOLINCHENG_BEGIN(CNshaolin_cheng_xing);

virtual void create()
{	
	set_name("澄行", "chengxing luohan");
	set("long",	"他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，太阳穴高高鼓起，似乎身怀绝世武功。");
	
	set("title","少林罗汉堂座下贤善罗汉");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
set("foolid",73);
	set("age", 60);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_facotr", 100);
	set("combat_exp", 100000);
	set("score", 5000);

	set_skill("force", 85);
	set_skill("hunyuan_yiqi", 85);
	set_skill("dodge", 85);
	set_skill("shaolin_shenfa", 85);
	set_skill("blade", 90);
	set_skill("cibei_dao", 95);
	set_skill("parry", 85);
	set_skill("buddhism", 85);
	set_skill("literate", 85);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("blade", "cibei_dao");
	map_skill("parry", "cibei_dao");

	create_family("少林派", 37, "弟子");

	carry_object("jiedao")->wield();
	carry_object("xuan_cloth")->wear();
	set("no_huan",1);
};

SHAOLINCHENG_END;
