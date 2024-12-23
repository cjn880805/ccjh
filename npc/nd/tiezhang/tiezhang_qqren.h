// qqren.c 裘千仞
//sound 2001-07-11

NPC_BEGIN(CNtiezhang_qqren);

virtual void create()
{
	set_name("裘百尺", "qiu qianren");
	set("nickname", "铁掌水上漂");
	set("long", 
		"他就是威震川湘的铁掌帮的帮主-铁掌水上漂裘百尺。\n"
		"他是一个白须老头，身穿黄葛短衫，右手挥着一把大蒲扇。\n");
	set("gender", "男性");
	set("age", 60);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 28);
	set("dex", 35);
	set("icon",old_man1);
	
	set("max_hp", 4000);
	set("hp", 4000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 200);
	set("combat_exp", 1000000);
	set("score", 400000);
	set_skill("hammer",100);
	set_skill("tiexue_hammer",180);
	set_skill("force", 160);
	set_skill("guiyuan_tunafa", 200);
	set_skill("dodge", 160);
	set_skill("shuishangpiao", 200);
	set_skill("strike", 180);
	set_skill("tiezhang_zhangfa", 200);
	set_skill("parry", 160);
	set_skill("literate", 100);
	set_skill("axe", 160);
	set_skill("duanyun_fu", 200);
	map_skill("hammer", "tiexue_hammer");
	
	map_skill("force", "guiyuan_tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("strike", "tiezhang_zhangfa");
	map_skill("parry", "tiezhang_zhangfa");
	prepare_skill("strike", "tiezhang_zhangfa");
	
	create_family("铁掌帮", 14, "帮主");

	set_inquiry("名字", "老夫便是“铁掌水上漂”裘百尺，你问老夫姓名有什么事么？");
	set_inquiry("这里", "这里就是铁掌帮的总坛所在，你如没事，不要四处乱走，免招杀身之祸！！！");
/*
	set("inquiry", ([
		"上官剑南" : (: ask_qiubai :),
		]));
*/	
	carry_object("cloth")->wear();
}
/*
void attempt_apprentice(object me)
{
	if ((int)me->query("shen") > -10000) {
		command("hehe");
		command("say 我裘千仞可不收心慈手软的人做徒弟。");
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
int ask_qiubai()
{
	say("他是我师父。我在十三岁那年曾救过他，之后他感恩图报，将全\n"
		"身武功倾囊相受。可惜十年前，他在湖北遭人围攻而死！唉！\n");
	return 1;
}
*/
NPC_END;