NPC_BEGIN(CNxiakedao_dizi);

virtual void create()
{
	set_name("弟子","dizi");

	set("icon", triggerman2);
	set("long", "这是三十多岁的壮汉，膀大腰圆，是岛主从中原招募来的。");
	
	set("gender", "男性");
	set("age", 30);
	set("shen_type",1);
	set("attitude", "peaceful");
	
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("hp", 500);
	set("max_hp", 1500);
	set("hp", 200);
	set("max_hp", 600);
	set("mp", 300);
	set("max_mp", 300);
	set("mp_factor", 30);
	
	set("combat_exp", 30000);
	set("score", 10);
	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("hand", 70);
	set_skill("staff", 50);
	create_family("侠客岛", 2, "弟子");
//	carry_object("cloth")->wear();
			
};

NPC_END;
