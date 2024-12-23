//mo.h
//code by zwb
//1-15

NPC_BEGIN(CNwudang_mo);

virtual void create()
{
	set_name("莫声谷", "mo shenggu");
	set("nickname", "武当七侠");
	set("long","他就是张三丰的七弟子莫声谷。他看起来二十多岁，显得稚气未脱。但也是江湖中行侠仗义，声明远播的侠客。");
	set("gender", "男性");
	set("age", 40);
	set("foolid",124);	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("dex", 27);
	set("icon",taoist_with_sword);	
	
	set("max_hp", 7500);
	set("mp", 3500);
	set("max_", 3500);
	set("mp_force", 100);
	set("combat_exp", 1000000);
	set("score", 300000);

	set_skill("force", 120);
	set_skill("taiji_shengong", 120);
	set_skill("dodge", 120);
	set_skill("tiyunzong", 120);
	set_skill("unarmed", 120);
	set_skill("taiji_quan", 120);
	set_skill("parry", 120);
	set_skill("sword", 120);
	set_skill("taiji_jian", 120);
	set_skill("taoism", 120);
	set_skill("literate", 120);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");

	create_family("武当派", 2, "弟子");

	set("chat_chance_combat", 30);

	carry_object("changjian")->wield();
	carry_object("white_robe")->wear();
}

virtual char * chat_msg_combat()
{

	switch(random(4))
	{
	case 0:
		perform_action("sword chan",1);
		break;
	case 1:
		perform_action("sword lian",1);
		break;
	case 2:
		perform_action("sword sui",1);
		break;
	case 3:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * player)
{
	char msg[255];

	if (player->query("repute") < 10000 )
	 {
		say("我武当乃是堂堂名门正派，对弟子要求极严。",player);
		say("你在德行方面是否还做得不够？",player);
		SendMenu(player);
		return;
	 }
	if (player->query_skill("taiji_shengong",1) < 60 || player->query_skill("force",1) < 60 )
	{
		say(" 我武当派最注重内功心法,你应该在内功上多下点功夫啊?");
		SendMenu(player);
		return;
	}
	if (player->query_skill("sword") < 60)
	{
		say("我派太极剑精奥博大,要学好他,需得打好基本功,我看你还是不够用功",player); 
		SendMenu(player);
		return;
	}
	say("好吧，我就收下你了。");
	say("希望你能好好用功,发扬我武当精神!");
	
	command(snprintf(msg,255,"recruit %ld",player->object_id()));
	if(DIFFERSTR(player->querystr("class"), "taoist"))
		player->set("class", "taoist");
}

NPC_END;