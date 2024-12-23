// liuchengfeng.c

//code by sound
//date:2001-07-11

NPC_BEGIN(CNxuedao_liuchengfeng);

virtual void create()
{
	set_name("刘承火", "liu chengfeng");
	set("long", 
		"他就是南四奇“落花流水”中的老三。\n"
		"南四奇横行江南，行侠仗义，一手太极剑，更是声震大江南北。\n");
	set("gender", "男性");
	set("nickname", "柔云剑");
	set("age", 41);
	set("attitude", "peaceful");
	set("shen_type", 0l);
	set("str", 35);
	set("int", 38);
	set("con", 35);
	set("dex", 35);
	set("icon",young_man5);
	
	set("max_hp", 2000);
	set("hp", 2000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 30);
	set("combat_exp", 800000);
	set("shen_type", 1);
	
	set_skill("force", 100);
	set_skill("taiji_shengong", 100);
	set_skill("dodge", 100);
	set_skill("tiyunzong", 100);
	set_skill("unarmed", 100);
	set_skill("taiji_quan", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("taiji_jian", 100);
	set_skill("literate", 70);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	set("chat_chance", 20);

	carry_object("changjian")->wield();
}

virtual char * chat_msg()
{
	return "刘承火急提中气，啸声如虹：“落花流水～～……”声势劲急，远远传开。";
}

NPC_END;