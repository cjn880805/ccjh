//wenhui.h
//Lanwood 2000-01-06

NPC_BEGIN(CNemei_wenhui);

virtual void create()
{
	set_name("理晖小师太", "lihui");
	set("long",  "她是峨嵋派的第五代弟子。");
	set("gender", "女性");
	set("icon", girl2);
	
	set("age", 15);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "bonze");
		set("foolid",10);
	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	set("per", 30);
	
	set("max_hp", 450);
	
	set("mp", 150);
	set("max_mp", 150);
	
	set("combat_exp", 2000);
	set("score", 1000);
	
	set_skill("force", 30);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);
	
	create_family("峨嵋派", 5, "弟子");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
};

virtual void init(CChar * me)
{
	if(userp(me) && !is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1);
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;

	me->say("这位施主请先入座，我这就给您上茶点。");
}

NPC_END;
