// huashan_shuidai.c

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNhuashan_shuidai);

virtual void create()
{
	set_name("水岳", "shui dai");
	set("long", "他就是南四奇“落花流水”中的老四。南四奇横行江南，行侠仗义，水岳虽富甲东南，现在却深有忧色。");
	set("gender", "男性");
	set("nickname", "冷月剑");
	set("age", 39);
	set("attitude", "peaceful");
	
	set("str", 35);
	set("int", 38);
	set("con", 35);
	set("dex", 35);
 	set("icon",young_man3);
	
	set("max_hp", 6000);
	set("hp",  2000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 30);
	set("combat_exp", 800000);
	set("shen_type", 1);
	
	set_skill("force", 100);
	set_skill("zixia_shengong", 100);
	set_skill("dodge", 100);
	set_skill("huashan_shenfa", 100);
	set_skill("strike", 100);
	set_skill("huashan_sword", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("huashan_sword", 100);
	set_skill("literate", 80);
	
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "huashan_shenfa");
	map_skill("strike", "huashan_zhangfa");
	map_skill("parry", "huashan_sword");
	map_skill("sword", "huashan_sword");
	set("chat_chance", 20);
	
	carry_object("changjian")->wield();
}

virtual char * chat_msg()
{
	return "水岳急提中气，啸声如虹：“落花流水～～……”声势劲急，远远传开。";
}

NPC_END;