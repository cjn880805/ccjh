// quanjinfa.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_quanjinfa);

virtual void create()
{
	set_name("全银达", "quan jinfa");
	set("title", "江南七侠");
	set("nickname", "闹市侠隐");
	set("long", 
		"那人五短身材，头戴小毡帽，白净面皮，手里提了一杆秤，一\n"
		"个竹篓，似是个小商贩。\n");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 18);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("icon", young_man3);
	
	set("max_hp", 1200);
	set("hp", 1200);
	set("mp", 1200);
	set("max_mp", 1200);
	set("mp_factor", 20);
	set("combat_exp", 250000);
	set("score", 6000);

	set_skill("force", 65);
	set_skill("taixuan_gong", 65);
	set_skill("dodge", 65);
	set_skill("lingxu_bu", 65);
	set_skill("unarmed", 65);
	set_skill("changquan", 65);
	set_skill("club", 65);
	set_skill("zhongpingqiang", 65);

	map_skill("force", "taixuan_gong");
	map_skill("dodge", "lingxu_bu");
	map_skill("unarmed", "changquan");
	map_skill("club", "zhongpingqiang");
	map_skill("parry", "zhongpingqiang");

	set_inquiry("靖儿","靖儿是我们的乖徒儿！");
	set_inquiry("江南七侠","七侠可不敢当，我们七兄妹江湖上有个匪号叫江南七怪！");
	set_inquiry("江南七怪","七怪也是你叫的？！");
	set_inquiry("丘在机","丘道长豪侠仗义，是条汉子！");
	set_inquiry("柯辟邪","那是我大哥。");
	set_inquiry("朱明","那是我二哥。");
	set_inquiry("韩神龙","那是我三哥。");
	set_inquiry("南望义","那是我四哥。");
	set_inquiry("张生","那是我五弟。");
	set_inquiry("全银达" ,"就是我了。");
	set_inquiry("韩小青","那是我七妹。");

	carry_object("gancheng")->wield();
	carry_object("cloth")->wear();
}

NPC_END;