//pub_mjdizi.h 明教护教弟子
//秦波 2002、4、25

NPC_BEGIN(CNpub_mjdizi);

virtual void create()
{
	set_name("明教护教弟子",  "mingjiao dizi" );

	set("gender", "男性");
	set("attitude", "friendly");
	set("icon",young_man1);
	
	set("age", 30);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_hp", 3000);
	set("hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 100000);
	set("score", 5000);
	set("no_kill",1);
	
	set_skill("force", 85);
	set_skill("hunyuan_yiqi", 85);
	set_skill("dodge", 85);
	set_skill("shaolin_shenfa", 85);
	set_skill("cuff", 95);
	set_skill("jingang_quan", 95);
	set_skill("parry", 85);
	set_skill("buddhism", 85);
	set_skill("literate", 85);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("cuff", "jingang_quan");
	map_skill("parry", "jingang_quan");
	
	prepare_skill("cuff", "jingang_quan");
	
};

void die()
{
	message_vision("$N死了。", this);
	destruct(this);
}

NPC_END;




