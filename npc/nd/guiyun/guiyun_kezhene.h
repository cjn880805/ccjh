// kezhene.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_kezhene);

virtual void create()
{
	set_name("柯辟邪", "ke zhene");
	set("title", "江南七侠");
	set("nickname", "飞天蝙蝠");
	set("long", 
		"他是一个衣衫褴褛的瞎子，右手握着一根粗大的铁杖。只见他\n"
		"尖嘴削腮，脸色灰扑扑地，颇有凶恶之态。\n");
	set("gender", "男性");
	set("age", 44);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 12);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("icon", old_man1);
	
	set("max_hp", 1500);
	set("hp", 1500);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 20);
	set("combat_exp", 400000);
	set("score", 6000);

	set_skill("force", 80);
	set_skill("taixuan_gong", 80);
	set_skill("dodge", 80);
	set_skill("lingxu_bu", 80);
	set_skill("unarmed", 80);
	set_skill("changquan", 80);
	set_skill("staff", 80);
	set_skill("juemen_gun", 80);
	set_skill("parry", 80);
	set_skill("throwing", 80);
	set_skill("feixing_shu", 80);

	map_skill("force", "taixuan_gong");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "lingxu_bu");
	map_skill("staff", "juemen_gun");
	map_skill("parry", "juemen_gun");
	map_skill("blade", "feixing_shu");

	set_inquiry("靖儿","靖儿是我们的乖徒儿！");
	set_inquiry("江南七侠","七侠可不敢当，我们七兄妹江湖上有个匪号叫江南七怪！");
	set_inquiry("江南七怪","七怪也是你叫的？！");
	set_inquiry("丘在机","丘道长豪侠仗义，是条汉子！");
	set_inquiry("柯辟邪","就是瞎子我，你要怎的？！");
	set_inquiry("朱明","那是我二哥。");
	set_inquiry("韩神龙","那是我三哥。");
	set_inquiry("南望义","那是我四哥。");
	set_inquiry("张生","那是我五弟。");
	set_inquiry("全银达" ,"那是我六弟。");
	set_inquiry("韩小青","那是我七妹。");
	set_inquiry("梅如花","这个铁尸害死我大哥，此仇一定要报。");

	carry_object("gangzhang")->wield();
	carry_object("cloth")->wear();
}

NPC_END;