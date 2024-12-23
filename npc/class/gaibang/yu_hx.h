//yu_hx.h
//Lanwood 2000-01-06

NPCGAIBANG_BEGIN(CNgaibang_yu_hx);

virtual void create()
{
	set_name("余洪旺", "yu hongwang");
	set("title", "丐帮八袋弟子");
	set("gender", "男性");
	set("age", 30);
	set("long", "这是位笑眯眯的丐帮八袋弟子，生性多智，外号小吴用。");
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 30);
	set("con", 22);
	set("dex", 20);
	set("icon",begger);

	set("beggarlvl", 8);

	set("hp", 420);
	set("max_hp", 1500);
	set("mp", 780);
	set("max_mp", 780);
	set("mp_factor", 42);
	set("combat_exp", 82000);
	
	set_skill("force", 108); 
	set_skill("huntian_qigong", 106); 
	set_skill("unarmed", 108); 
	set_skill("xianglong_zhang", 110); 
	set_skill("dodge", 90); 
	set_skill("xiaoyaoyou", 88); 
	set_skill("parry", 81); 
	set_skill("begging", 80); 
	set_skill("stealing", 90); 
//	set_skill("checking", 70); 
	set_skill("xunshou_shu", 70);
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("丐帮", 19, "弟子");
	set("no_huan",1);
	
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if( me->query_int() < 25 )
	{
		say("唉，本帮诚信为本，只有七公他老人家和我才特别收些聪明徒儿，大家都要为长远着想啊！你看来，唉。。");
		return;
	}
	if( me->query("combat_exp") < 50000 )
	{
		say("以你的阅历，差得远啦。");
		return;
	}
	if( me->query("repute") < 0 )
	{
			say("本帮以行侠仗义为宗旨，你？");
		return;
	}
	else
	{
		say ("好吧，希望你能好好学习本门武功，将来为丐帮争一口气！。");
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
		me->set("class", "beggar");
		return;
	}
	return;
}


NPC_END;
