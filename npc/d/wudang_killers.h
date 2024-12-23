// wudang_killers.c ,No greeting, 武当功夫, 南门
//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNwudang_killers);

virtual void create()
{
	set_name("杀手", "killer");
	set("long","这是一个身材高大的江湖人，两臂粗壮，膀阔腰圆，看起来似乎不怀好意。 ");
	
	set("gender", "男性");
	set("attitude", "aggressive");
	set("class", "taoist");
	
	set("age", 20+random(30));
        set("icon",young_man1);

	set("shen_type", 1);
	
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("int", 25+random(10));
	set("con", 25+random(10));
	
	set("hp", 1500);
	set("max_hp", 4500);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 50+random(100));
	
	set("combat_exp", 10000+random(100000));
	set("score", 1);
	
	set("startroom","/d/city/nanmen");
	
	set_skill("force", 20+random(80));
	set_skill("taiji_shengong",20+random(80));
	set_skill("dodge", 20+random(60));
	set_skill("tiyunzong", 20+random(60));
	set_skill("unarmed", 20+random(100));
	set_skill("taiji_quan",10+random(110));
	set_skill("parry", 20+random(80));
	set_skill("sword", 20+random(100));
	set_skill("taiji_jian", 10+random(110));
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	map_skill("unarmed", "taiji_quan");
	
	set("chat_chance", 20);
	
	carry_object("gangjian")->wield();
}

virtual char * chat_msg()
{
	switch (random(2))
	{
	case 0:
		return "杀手说：这次看那些玩家们往哪儿跑。 ";
	case 1:
		return "杀手说：杀! 杀! 杀!!!。 ";
	}
	return 0;
}

NPC_END;