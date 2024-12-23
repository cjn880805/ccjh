// yinchang_dunan.c

//code by Fisho
//date:2000-12-23
//inherit F_MASTER;

NPC_BEGIN(CNyinchang_dunan);

virtual void create()
{
	set_name("释难",  "du nan");
	set("title", "少林长老");
	set("gender", "男性");
	set("age", 90);
        set("icon",old_man2);

	set("long","这是一个面颊深陷，瘦骨零丁的老僧，他脸色漆黑，象是生铁铸成。");
	
	set("attitude", "peaceful");
	set("class", "bonze");
	set("combat_exp", 1500000);
	set("score", 200000);
	
	set("str", 30);
	set("int", 30);
	set("cor", 30);
	set("cps", 30);
	set("con", 30);
	
	set("hp", 4000);
	set("max_hp", 6000);
	set("mp", 4000);
	set("max_mp", 2000);
	set("mp_factor", 80);
	
	create_family("少林派", 35, "弟子");
	assign_apprentice("弟子", 0);
	
	set_skill("force", 150);
	set_skill("whip", 160);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	
	set_skill("hunyuan_yiqi", 150);
	set_skill("riyue_bian", 200);
	set_skill("shaolin_shenfa", 180);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("whip",  "riyue_bian");
	map_skill("parry", "riyue_bian");
	map_skill("dodge", "shaolin_shenfa");
	
	carry_object("changbian")->wield();
}

NPC_END;