// shen.c
//sound 2001-07-16

NPC_BEGIN(CNhuanghe_shen);

virtual void create()
{
	set_name("沈刚青", "shen qinggang");
	set("gender", "男性");
	set("title", "黄河四鬼老大");
	set("nickname", "断魂刀");
	set("age", 32);
	set("str", 25);
	set("dex", 16);
	set("per", 16);
	set("icon",cateran);
	
	set("long", "沈刚青是黄河四鬼的老大，是鬼门龙王沙遁地通天的大弟子，擅使单刀。");
	set("combat_exp", 20000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 30);
	set_skill("force", 30);
	set_skill("blade", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);
	
	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
}

NPC_END;