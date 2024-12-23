// murongbo.c  慕容博
//sound 2001-07-16

NPC_BEGIN(CNmurong_bo);

virtual void create()
{
	set_name("慕容渊博", "murong bo");
	set("title","姑苏慕容老爷子");
	set("nick","以彼之道 还施彼身");
	set("long", 
		"他就是天下号称以彼之道，还彼之身的姑苏慕容渊博。\n"
		"他脸上带着不可一世的笑容。\n");
	set("age", 57);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("icon",old_man1);
	
	set("hp", 4500);
	set("max_hp", 4500);
	set("mp", 4500);
	set("max_mp", 4500);
	set("mp_factor", 200);
	set("combat_exp", 4000000);
	set("score", 50000);                
	set("chat_chance_combat",40);
	
	set_skill("xingyi_zhang",200);
	set_skill("strike",200);
	set_skill("finger",200);
	set_skill("dodge",200);
	set_skill("force", 200);
	set_skill("canhe_zhi", 300);
	set_skill("murong_jianfa",300);       
	set_skill("shenyuan_gong", 300);
	set_skill("yanling_shenfa", 300);
	set_skill("douzhuan_xingyi", 300);
	set_skill("parry", 210);
	set_skill("sword", 200);
	set_skill("literate", 200);
	set_skill("murong_daofa", 300);
	set_skill("blade",200);
	
	map_skill("blade", "murong_daofa");
	map_skill("finger", "canhe_zhi");
	map_skill("force", "shenyuan_gong");
	map_skill("dodge", "yanling_shenfa");
	map_skill("parry", "douzhuan_xingyi");
	map_skill("sword", "murong_jianfa");
	
	prepare_skill("finger","canhe_zhi");
	
	create_family("姑苏慕容",1,"弟子");
	
	set_inquiry("名字", "我就是以彼之道，还施彼身的姑苏慕容渊博。");
	set_inquiry("这里", "这里是少林寺的藏经楼。");
	set_inquiry("传闻",  "我那慕容重复儿在武林之中闯出了名头，老爷子我是真高兴呀！");
	
}

virtual char * chat_msg_combat()
{
//	perform_action("parry xingyi", 1);

	return 0;
}
/*
void attempt_apprentice(object ob)
{
	object me  = this_player();
	
	string name, new_name;
	name = ob->query("name");
	
	if (present("jiaxin", me))
	{  destruct(present("jiaxin",me));
	
	command("say 好吧，既然" + RANK_D->query_respect(ob) + "有我儿的信件，难为你" +
		"如此辛苦跑来，我就收下你吧。");
	
	new_name = "慕容" + name[2..3];
	ob->set("name", new_name);
	command("say 从今以后你就叫做" + new_name + "，希望你能把慕容功夫发扬光大！");
	command("recruit " + ob->query("id"));
	command("chat 淡淡一笑，谁言 以彼之道 还施彼身 绝迹江湖！");
	command("chat* haha"); 
	}
	else
		command("say 我慕容博岂能随便收徒!");
	return;	   
}
*/
NPC_END;
