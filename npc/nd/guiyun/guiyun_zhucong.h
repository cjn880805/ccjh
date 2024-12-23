// zhucong.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_zhucong);

virtual void create()
{
	set_name("朱明", "zhu cong");
	set("title", "江南七侠");
	set("nickname", "妙手书生");
	set("long", 
		"他看起来象一个中年士人，拖着鞋皮，踢踏踢踏的直响，一路打着哈欠。拿着一柄破烂的油纸黑扇，边摇边行。突听干笑数声，声音甚是刺耳。");
	set("gender", "男性");
	set("age", 38);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 19);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("icon", young_man5);
	
	set("hp", 1200);
	set("max_hp", 1200);
	set("mp", 1200);
	set("max_mp", 1200);
	set("mp_factor", 20);
	set("combat_exp", 350000);
	set("score", 6000);

	set_skill("force", 75);
	set_skill("taixuan_gong", 75);
	set_skill("dodge", 75);
	set_skill("lingxu_bu", 75);
	set_skill("unarmed", 75);
	set_skill("changquan", 75);
	set_skill("dagger", 75);
	set_skill("shigu_bifa", 75);
	set_skill("parry", 75);
	set_skill("stealing", 75);

	map_skill("force", "taixuan_gong");
	map_skill("dodge", "lingxu_bu");
	map_skill("dagger", "shigu_bifa");
	map_skill("parry", "shigu_bifa");

	set_inquiry("靖儿","靖儿是我们的乖徒儿！");
	set_inquiry("江南七侠","七侠可不敢当，我们七兄妹江湖上有个匪号叫江南七怪！");
	set_inquiry("江南七怪","七怪也是你叫的？！");
	set_inquiry("丘在机","丘道长豪侠仗义，是条汉子！");
	set_inquiry("柯辟邪","那是我大哥。");
	set_inquiry("朱明","就是我了。");
	set_inquiry("韩神龙","那是我三哥。");
	set_inquiry("南望义","那是我四哥。");
	set_inquiry("张生","那是我五弟。");
	set_inquiry("全银达" ,"那是我六弟。");
	set_inquiry("韩小青","那是我七妹。");

	carry_object("zheshan")->wield();
	carry_object("cloth")->wear();
}

NPC_END;