//qqzhang.c 裘千丈
//sound 2001-07-11

NPC_BEGIN(CNtiezhang_qqzhang);

virtual void create()
{
	set_name("裘千尺", "qiu qianzhang");
	set("long", 
		"他是一个白须老头，身穿黄葛短衫，足穿麻鞋，右手挥着一把大蒲扇。\n"
		"他满脸的油滑无赖的表情。\n");
	set("gender", "男性");
	set("age", 60);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 23);
	set("int", 30);
	set("con", 26);
	set("dex", 25);
//	set("env/wimpy", 70);
	set("icon",old_man1);
	
	set("max_hp", 1000);
	set("hp", 1000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 80);
	set("combat_exp", 100000);
	
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("strike", 60);
	set_skill("parry", 60);
	set_skill("literate", 60);
	set_skill("tiezhang_zhangfa", 60);
	set_skill("guiyuan_tunafa", 60);
	set_skill("shuishangpiao", 60);
	
	map_skill("force", "guiyuan_tunafa");
	map_skill("strike", "tiezhang_zhangfa");
	map_skill("parry", "tiezhang_zhangfa");
	map_skill("dodge", "shuishangpiao");
	prepare_skill("strike", "tiezhang_zhangfa");
	
	create_family("铁掌帮", 14, "弟子");
/*	
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		"$YEL裘千仞正色道：你身上已受内伤，快回去密室中休养七七四十九日，不可见风，否则小命不保！$COM\n",
			"$YEL裘千仞急道：你再不住手，爷爷可就要不客气了！！！$COM\n",
			(: random_move :)
	}) );
*/	
	set_inquiry("名字", "记得先父曾给我起过一个名，叫甚么‘千尺’。我念着不好听，也就难得用它。");
	set_inquiry("这里", "这里就是铁掌帮的总坛所在，你如没事，不要四处乱走，免招杀身之祸！！！");
	
    set("chat_chance", 10);
}

virtual char * chat_msg()				//NPC自动聊天
{
	switch(random(4))
	{
	case 0:
		return 	"裘千尺大大咧咧的说道：“铁掌帮上上下下的事情，没有爷爷不知道的！”";
	case 1:
		return 	"裘千尺神秘的说道：“无名峰上有一座坟墓，听说那里经常闹鬼！”";
	case 2:
		return 	"裘千尺神秘的说道：“一旦内功基础有成，就可以从花草树木中采气来提高了！”";
	case 3:
		return 	"裘千尺说道：“中指峰第二指节处，有一个神秘的所在，听说是已故帮主的埋骨之处！”";
	}	
	return 0;
}
/*
void attempt_apprentice(object me)
{
	if ((int)me->query("shen") > 0) {
		command("hehe");
		command("say 他妈的！爷爷我最恨你这样心慈手软的小王八蛋！。");
		return;
	}
	command("haha");
	command("say 爷爷我武功盖世，你这娃娃好好跟着我学，准没错！");
	command("recruit " + me->query("id"));
}
int ask_qiubai()
{
	say("他是铁掌帮的第十三代帮主。听说十年前遭了暗算，死在湖北，不知是真是假！\n");
	return 1;
}
int ask_naogui()
{
	say("听一些帮众说，经常听见无名峰上的坟墓中，传出响声！嘿嘿！一定有什么蹊跷在里面！\n");
	this_player()->set_temp("marks/闹1", 1);
	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + 
		"怕是活腻了，来来来，让爷爷教训教训你！！\n");
	command("say 啊哟，糟糕，糟糕，这会儿当真不凑巧！你等一会，我肚子痛，要出恭！\n");
	return 0;
}
*/
NPC_END;