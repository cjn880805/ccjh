// pub_nanxiren.c
//code by Fisho
//date : 2000-12-14
//inherit F_MASTER;

NPC_BEGIN(CNpub_nanxiren);

virtual void create()
{
	set_name("南望义", "nan wangyi" );

	set("icon", young_man2);
	set("title", "江南七侠");
	set("nickname", "南山樵子");
	set("long", "他是个挑柴模样的汉子，三十岁上下年纪，一身青布衣裤，腰里束了根粗草绳，足穿草鞋，粗手大脚，神请木讷。");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 15);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("max_hp", 3600);
	set("mp", 1200);
	set("max_mp", 1200);
	set("mp_factor", 20);
	set("combat_exp", 300000);
	set("score", 6000);
	set_skill("force", 70);
	set_skill("taixuan_gong", 70);
	set_skill("dodge", 70);
	set_skill("lingxu_bu", 70);
	set_skill("unarmed", 70);
	set_skill("changquan", 70);
	set_skill("staff", 70);
	set_skill("juemen_gun", 70);
	set_skill("axe", 70);
	set_skill("duanyun_fu", 70);
	map_skill("force", "taixuan_gong");
	map_skill("dodge", "lingxu_bu");
	map_skill("unarmed", "changquan");
	map_skill("staff", "juemen_gun");
	map_skill("parry", "juemen_gun");
	map_skill("axe", "duanyun_fu");
	
	carry_object("biandan");
	carry_object("axe")->wield();
	carry_object("green_cloth")->wear();

	set_inquiry("靖哥哥","靖儿是我们的乖徒儿！");
	set_inquiry("江南七侠","七侠可不敢当，我们七兄妹江湖上有个匪号叫江南七怪！");
	set_inquiry("江南七怪","七怪也是你叫的？！");
	set_inquiry("丘处机","丘道长豪侠仗义，是条汉子！");
	set_inquiry("柯辟邪","那是我大哥。");
	set_inquiry("朱明","那是我二哥。");
	set_inquiry("韩神龙","那是我三哥。");
	set_inquiry("南望义","就是我了。");
	set_inquiry("张生","那是我五弟。");
	set_inquiry("全银达" ,"那是我六弟。");
	set_inquiry("韩小青","那是我们七妹，唉……");
	
}
NPC_END;