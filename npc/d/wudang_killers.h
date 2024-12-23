// wudang_killers.c ,No greeting, �䵱����, ����
//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNwudang_killers);

virtual void create()
{
	set_name("ɱ��", "killer");
	set("long","����һ����ĸߴ�Ľ����ˣ����۴�׳��������Բ���������ƺ��������⡣ ");
	
	set("gender", "����");
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
		return "ɱ��˵����ο���Щ��������Ķ��ܡ� ";
	case 1:
		return "ɱ��˵��ɱ! ɱ! ɱ!!!�� ";
	}
	return 0;
}

NPC_END;