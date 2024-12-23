// hanxiaoyin.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_hanxiaoyin);

virtual void create()
{
	set_name("韩小青", "han xiaoyin");
	set("title", "江南七侠");
	set("nickname", "越女剑");
	set("long", 
		"她大约十八九岁年纪，身形苗条，大眼睛，皮肤如雪，露出一头乌云般的秀发。正是江南水乡的人物。");
	set("gender", "女性");
	set("age", 18);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 18);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("icon", young_woman5);
	
	set("max_hp", 1000);
	set("hp", 1000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 20);
	set("combat_exp", 200000);
	set("score", 6000);

	set_skill("force", 60);
	set_skill("taixuan_gong", 60);
	set_skill("dodge", 60);
	set_skill("lingxu_bu", 60);
	set_skill("unarmed", 60);
	set_skill("changquan", 60);
	set_skill("sword", 60);
	set_skill("yunv_jian", 60);

	map_skill("force", "taixuan_gong");
	map_skill("dodge", "lingxu_bu");
	map_skill("unarmed", "changquan");
	map_skill("sword", "yunv_jian");
	map_skill("parry", "yunv_jian");

	set_inquiry("靖儿","靖儿是我们的乖徒儿！");
	set_inquiry("江南七侠","七侠可不敢当，我们七兄妹江湖上有个匪号叫江南七怪！");
	set_inquiry("江南七怪","七怪也是你叫的？！");
	set_inquiry("丘在机","丘道长豪侠仗义，是条汉子！");
	set_inquiry("柯辟邪","那是我大哥。");
	set_inquiry("朱明","那是我二哥。");
	set_inquiry("韩神龙","那是我三哥。");
	set_inquiry("南望义","那是我四哥。");
	set_inquiry("张生","那是我五弟。");
	set_inquiry("全银达" ,"那是我六弟。");
	set_inquiry("韩小青","就是我了。");

	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
}

NPC_END;