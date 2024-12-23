//tuoboseng.h
//Lanwood 2000-01-10

NPC_BEGIN(CNshaolin_tuoboseng);

virtual void create()
{
	set_name("托钵僧", "tuobo seng");
	set("title", "少林弟子");
	set("long",	"他是一位未通世故的青年和尚，脸上挂着孩儿般的微笑。");

	set("gender", "男性");
	set("attitude", "heroism");
	set("class", "bonze");
	set("icon",young_monk);
	set("foolid",111);
	set("age", 20);
	set("shen_type", 1);
	set("str", 15);
	set("int", 30);
	set("con", 30);
	set("dex", 18);
	set("max_hp", 900);
	
	set("mp", 380);
	set("max_mp", 380);
	set("mp_factor", 27);
	set("combat_exp", 10000);
	set("shen_type", 1);
	set("chat_chance", 10);

	set_skill("force", 41);
	set_skill("unarmed", 41);
	set_skill("dodge", 41);
	set_skill("parry", 41);
	set_skill("shaolin_shenfa", 42);
	set_skill("jingang_quan", 41);
	set_skill("hunyuan_yiqi", 41);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("unarmed", "jingang_quan");
	map_skill("parry", "jingang_quan");

	carry_object("cloth")->wear();
};

virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		return "托钵僧说道: 请这位施主化几两银子给贫僧，积点阴德，造福众生。";
	case 1:
		random_move();
		break;
	}

	return 0;
}

NPC_END;
