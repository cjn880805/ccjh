// hanbaoju.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_hanbaoju);

virtual void create()
{
	set_name("韩神龙", "han baoju");
	set("title", "江南七侠");
	set("nickname", "马王神");
	set("long", 
		"他是个又矮又胖的猥琐汉子，犹如一个大肉团一般。他手短足短，\n"
		"没有脖子，一个头大的出奇，却又缩在双肩之中。一个酒糟鼻又\n"
		"大又圆，就如一只红柿子旒在脸上。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 10);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("icon", young_man2);
	
	set("max_hp", 1200);
	set("hp", 1200);
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
	set_skill("whip", 70);
	set_skill("riyue_bian", 70);

	map_skill("force", "taixuan_gong");
	map_skill("dodge", "lingxu_bu");
	map_skill("unarmed", "changquan");
	map_skill("whip", "riyue_bian");
	map_skill("parry", "riyue_bian");

	set_inquiry("靖儿","靖儿是我们的乖徒儿！");
	set_inquiry("江南七侠","七侠可不敢当，我们七兄妹江湖上有个匪号叫江南七怪！");
	set_inquiry("江南七怪","七怪也是你叫的？！");
	set_inquiry("丘在机","丘道长豪侠仗义，是条汉子！");
	set_inquiry("柯辟邪","那是我大哥。");
	set_inquiry("朱明","那是我二哥。");
	set_inquiry("韩神龙","就是我了。");
	set_inquiry("南望义","那是我四弟。");
	set_inquiry("张生","那是我五弟。");
	set_inquiry("全银达" ,"那是我六弟。");
	set_inquiry("韩小青","那是我们七妹，唉……");

	carry_object("changbian")->wield();
	carry_object("cloth")->wear();
}

NPC_END;