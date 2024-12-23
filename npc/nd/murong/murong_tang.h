// tang.c 唐光雄
//sound 2001-07-16

NPC_BEGIN(CNmurong_tang);

virtual void create()
{
	set_name("唐光英", "tang guangxiong");
	set("gender", "男性");
	set("age", 20);      
	set("str", 25);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	set("icon",young_man4);

	set("combat_exp", 30000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("max_hp",2000);
	set("hp",2000);
	set("mp",2000);
	set("max_mp",2000);
	set("mp_factor",100);
	set("score", 8000);
	
	set_skill("cuff", 60);
	set_skill("parry",60);
	set_skill("dodge", 70);
	set_skill("force",70);
	set_skill("shenyuan_gong",70);
	
	map_skill("force","shenyuan_gong");
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	
//	set("inquiry", 
//		([
//		"秘密" : (: ask_1 :)
//		]));
	set("chat_chance",20);
       
	carry_object("cloth")->wear();
}

virtual char *chat_msg()
{
	return "唐光英道：“快救我出去，我告诉你一个秘密！！！";
}

/*                       
string ask_1()
{
	mapping fam; 
//	object ob;
	if (!(fam = this_player()->query("family")) 
		|| fam["family_name"] != "姑苏慕容")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	return "后花园的树藤里面有古怪！\n";
}
*/
NPC_END;