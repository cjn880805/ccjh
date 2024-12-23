//yinwushou.h
//Lanwood
//2001-01-09

NPC_BEGIN(CNmingjiao_yinwushou);

virtual void create()
{
	set_name("殷有寿", "yin youshou");
	set("long", "他是一位老者，身穿一件白布长袍。他是白眉鹰王殷天罡的仆从。整天眉开眼笑的，一副福寿双全相。");
	
	set("title",  "明教紫微堂属下");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "fighter");
	set("icon",old_man2);
	
	set("age", 57);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_hp", 3000);
	set("hp", 1000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 100000);
	set("score", 5000);
	
	set_skill("force", 85);
	set_skill("hunyuan_yiqi", 85);
	set_skill("dodge", 85);
	set_skill("shaolin_shenfa", 85);
	set_skill("cuff", 95);
	set_skill("jingang_quan", 95);
	set_skill("parry", 85);
	set_skill("buddhism", 85);
	set_skill("literate", 85);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("cuff", "jingang_quan");
	map_skill("parry", "jingang_quan");
	
	prepare_skill("cuff", "jingang_quan");
	create_family("明教", 4, "紫微堂属下");
	
	carry_object("baipao")->wear();
}

NPC_END;