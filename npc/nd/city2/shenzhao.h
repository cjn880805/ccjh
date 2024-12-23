// shenzhao.h
//zhangdongni 2001-07-18

NPC_BEGIN(CNcity2_shenzhao);

virtual void create()
{
	
	set_name("天照上人", "shen zhao");
	set("long","他是一位秃顶老僧，身穿一袭红色镶边袈裟。他身材略高，太阳穴微凸，双目炯炯有神。");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon", old_man2);

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 24);
	
        set("max_hp", 1450);
        set("hp", 1450);
        set("mp", 1000);
        set("max_mp", 1000);
        set("mp_factor", 50);
        set("combat_exp", 50000);
        set("score", 100);
	
	set_skill("force", 70);
	set_skill("hunyuan_yiqi", 70);
	set_skill("dodge", 70);
	set_skill("shaolin_shenfa", 70);
	set_skill("cuff", 75);
	set_skill("jingang_quan", 75);
	set_skill("staff", 76);
	set_skill("parry", 70);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("cuff", "jingang_quan");

	prepare_skill("cuff", "jingang_quan");
	
	carry_object("cloth")->wear();

	
}
NPC_END;

