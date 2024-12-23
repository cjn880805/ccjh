//pub_mao_huyuan.h
//秦波 2002-11-20

NPC_BEGIN(CNpub_mao_huyuan);

virtual void create()
{	
	set_name("护院", "hu yuan");
	set("title", "毛府");
	set("gender", "男性");
	set("icon", triggerman2);
	set("attitude", "friendly");
	
	set("age", 30);
	set("shen_type", 1);
	set("str", 17);
	set("int", 24);
	set("con", 20);
	set("dex", 22);
	set("max_hp", 10050);
	set("mp", 1350);
	set("max_mp", 1350);
	set("mp_factor", 100);
	set("combat_exp", 300000);
	set("score", 100);
	
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("sword", 120);
	set_skill("parry", 100);
	
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();

	call_out(do_die, 300);
	set("chat_chance", 100);
}

virtual void die()
{
	message_vision("护院死了。", this);
	destruct(this);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	destruct(me);
}

virtual char * chat_msg()
{
	if(!query_temp("fight/is_fighting"))
		destruct(this);

	return 0;
}

NPC_END;




