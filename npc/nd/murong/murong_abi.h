// abi.c 阿碧
//sound 2001-07-16

NPC_BEGIN(CNmurong_abi);

virtual void create()
{
	set_name("阿绿", "a bi");
	set("gender", "女性");
	set("age", 20);      
	set("title","贴身丫鬟");
	set("str", 25);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	set("per", 30);
	set("icon",young_woman9);

	set("combat_exp", 13000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("hp",1000);
	set("max_hp",1000);
	set("mp",1000);
	set("max_mp",1000);
	set("mp_factor",30);
	set("score", 8000);
	
	set_skill("cuff", 50);
	set_skill("parry",40);
	set_skill("yanling_shenfa",70);
	set_skill("dodge", 70);
	set_skill("force",70);
	set_skill("shenyuan_gong",70);
	
	map_skill("force","shenyuan_gong");
	map_skill("dodge","yanling_shenfa");
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	
	carry_object("shoe")->wear();
//	carry_object("red_silk")->wear();
//	carry_object("skirt1")->wear();
	
	set_inquiry("名字", "我是慕容公子的贴身丫鬟，叫做阿绿，好久没有见到慕容公子了。");
	set_inquiry("这里", "这里是听香水榭，是慕容老爷为了照顾我给我安排的住处。");
	set_inquiry("传闻",  "曼佗罗山庄的王姑母这一阵子不让外人去她的山庄，连我们都不敢。");
	set_inquiry("曼佗罗山庄",  "离这里不远，有一小筑名为听雨居，只要弹动琴弦，就可乘船前往。");
	set_inquiry("慕容复", "慕容重复是我们燕子坞的主人，以以彼之道，还施彼身而天下闻名。");
	set_inquiry("听雨居", "顺着小径一直往西走，就是听雨居了。");	
}

NPC_END;