//  azhu.c 阿珠
//sound 2001-07-16

NPC_BEGIN(CNmurong_azhu);

virtual void create()
{
	set_name("阿红", "a zhu");
	set("gender", "女性");
	set("age", 20);              
	set("title","贴身丫鬟");
	set("str", 25);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	set("per", 30);
	set("icon",young_woman10);
	set("combat_exp", 14000);
	set("shen_type", 0l);
	set("attitude", "peaceful");
	set("max_hp",1000);
	set("hp",1000);
	set("mp",1000);
	set("max_mp",1000);
	set("mp_factor",30);
	set("score", 8000);
	
	set_skill("cuff", 50);
	set_skill("parry",50);
	set_skill("yanling_shenfa",50);
	set_skill("dodge", 50);
	set_skill("force",50);
	set_skill("shenyuan_gong",50);
	
	map_skill("force","shenyuan_gong");
	map_skill("dodge","yanling_shenfa");      
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	
	carry_object("shoe")->wear();
//	carry_object("red_silk")->wear();
	carry_object("skirt")->wear();
	
	set_inquiry("名字", "我就是慕容公子的贴身丫鬟阿珠，好久不见公子不知出事没有。");
	set_inquiry("这里", "这里是听香水榭，是慕容老爷为了照顾我给我安排的住处。");
	set_inquiry("传闻",  "最近有一个大和尚来燕子坞，要去还施水阁看武功秘籍，他好厉害呀。");
	set_inquiry("慕容重复",  "慕容重复是我们燕子坞的主人，以以彼之道，还施彼身而天下闻名。");
	set_inquiry("还施水阁",  "我只知道还施水阁是公子藏书的地方，可不知具体在什么地方。");
	set_inquiry("阿绿", "阿绿是我的好美眉，她住在琴韵小筑，和我一样是公子的贴身丫鬟。");
	set_inquiry("后厅", "后厅在燕子坞的南面那里供奉着老爷子的灵位和生前的事物。");
	set_inquiry("供奉", "后厅供奉着老爷子的灵位和一把生前的宝剑，名为碧玉剑，江湖人事都携带俸品来供奉在灵位前。");
//	set_inquiry("碧玉剑" : (: ask_sword :));
}
/*
string ask_sword()
{
	mapping fam; 
//	object ob;
	if (!(fam = this_player()->query("family"))
		|| fam["family_name"] != "姑苏慕容")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	return "碧玉剑是老爷子仙逝后的遗物，公子让我收起来好好保管，我把它放到后厅供起来了！\n";
}
*/

NPC_END;