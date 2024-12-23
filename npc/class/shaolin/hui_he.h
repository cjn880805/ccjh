//hui_he.h
//Lanwood 2000-01-10

SHAOLINHUI_BEGIN(CNshaolin_hui_he);

virtual void create()
{
	set_name("慧合尊者", "huihe zunzhe");
	set("long",	"他是一位两鬓斑白的老僧，身穿一袭青布镶边袈裟。他身材略高，太阳穴微凸，双目炯炯有神。");
	
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
	set("foolid",84);
	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_hp", 1450);
	
	set("mp", 600);
	set("max_mp", 600);
	set("mp_factor", 50);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("hunyuan_yiqi", 70);
	set_skill("dodge", 70);
	set_skill("shaolin_shenfa", 70);
	set_skill("finger", 68);
	set_skill("nianhua_zhi", 68);
	set_skill("parry", 70);
	set_skill("sword", 80);
	set_skill("damo_jian", 80);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("finger", "nianhua_zhi");
	map_skill("parry", "damo_jian");
	map_skill("sword", "damo_jian");

	prepare_skill("finger", "nianhua_zhi");

	create_family("少林派", 38, "弟子");
	set_inquiry("买铁", "买铁？ 他现在又不缺铁！ 前天老乔不是刚送来一堆铁块，铁手掌什麽的给他吗？！");

    carry_object("changjian")->wield();
    carry_object("xu_cloth")->wear();
	set("no_huan",1);
};

SHAOLINHUI_END;
