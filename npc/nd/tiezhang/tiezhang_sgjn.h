// sgjn.c 上官剑南
//sound 2001-07-11

NPC_BEGIN(CNtiezhang_sgjn);

virtual void create()
{
	set_name("上官南剑", "shangguan jiannan");
	set("nickname", "铁掌水上漂");
	set("long", 
		"这位上官帮主乃是一位侠义之士，铁掌帮自他接任后，力加整顿，多行侠义\n"
		"之事，不过数年声势大振，在江湖上侵寻已可以与北方的丐帮分庭抗礼了。\n"
		"只是后来忽然消声匿迹，不知所踪了。\n");
	set("gender", "男性");
	set("age", 80);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 45);
	set("int", 40);
	set("con", 48);
	set("dex", 44);
	set("icon",old_man1);
	
	set("max_hp", 6000);
	set("hp", 6000);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 200);
	set("combat_exp", 2000000);
	set("score", 500000);
	
	set_skill("force", 250);
	set_skill("guiyuan_tunafa", 250);
	set_skill("dodge", 200);
	set_skill("shuishangpiao", 250);
	set_skill("strike", 250);
	set_skill("tiezhang_zhangfa", 300);
	set_skill("parry", 200);
	set_skill("literate", 100);
	set_skill("tiexue_hammer",250);
	set_skill("duanyun_fu", 250);
	
	map_skill("force", "guiyuan_tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("strike", "tiezhang_zhangfa");
	map_skill("parry", "tiezhang_zhangfa");
	prepare_skill("strike", "tiezhang_zhangfa");
	
	create_family("铁掌帮", 13, "帮主");
	
	carry_object("cloth")->wear();
}
/*
void attempt_apprentice(object me)
{
	if ((int)me->query("shen") < 50000) 
	{
		command("hehe");
		command("say 我上官剑南可不收心地不纯的人做徒弟。");
		return;
	}
	command("say 好吧，我就收下你了。希望你苦练铁掌神功，将之发扬光大。");
	command("recruit " + me->query("id"));
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		add("apprentice_available", -1);
}
*/
NPC_END;