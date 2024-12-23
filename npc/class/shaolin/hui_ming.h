//hui_ming.h
//Lanwood 2000-01-10

SHAOLINHUI_BEGIN(CNshaolin_hui_ming);

virtual void create()
{
	set_name("慧名尊者", "huiming zunzhe");
	set("long",	"他是一位两鬓斑白的老僧，身穿一袭青布镶边袈裟。他身材略高，太阳穴微凸，双目炯炯有神。");
	
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("foolid",88);	set("icon",old_monk);

	set("age", 50);
	set("shen_type", 1);
	set("str", 30);
	set("int", 20);
	set("con", 27);
	set("dex", 22);
	set("max_hp", 1450);
	
	set("mp", 600);
	set("max_mp", 600);
	set("mp_factor", 70);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("hunyuan_yiqi", 70);
	set_skill("dodge", 70);
	set_skill("shaolin_shenfa", 70);
	set_skill("strike", 74);
	set_skill("banruo_zhang", 74);
	set_skill("claw", 70);
	set_skill("yingzhua_gong", 70);
	set_skill("parry", 70);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("strike", "banruo_zhang");
	map_skill("claw", "yingzhua_gong");
	map_skill("parry", "yingzhua_gong");

	prepare_skill("claw", "yingzhua_gong");

	create_family("少林派", 38, "弟子");
	carry_object("xu_cloth")->wear();
	set("no_huan",1);
};

SHAOLINHUI_END;
