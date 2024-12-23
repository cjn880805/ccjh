// shaolin_aobai.c
//code by Fisho
//date:2000-12-21
//inherit F_UNIQUE;

NPC_BEGIN(CNshaolin_aobai);

virtual void create()
{
	set_name("鳌拜","ao bai");
	set("long","他就是满洲第一勇士，身穿一袭金边锦缎。他身材魁梧，相貌狰狞，太阳穴高高鼓起，似乎身怀绝世武功。");
	
	set("nickname", "满洲第一勇士");
	set("gender", "男性");
	set("attitude", "aggressive");
 	set("icon",old_man1);
	
	set("age", 50);
	set("shen_type", -1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_hp", 4500);
	set("hp", 1500);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 150);
	set("combat_exp", 150000);
	set("score", 50000);
	
	set_skill("force", 90);
	set_skill("hunyuan_yiqi", 90);
	set_skill("dodge", 90);
	set_skill("shaolin_shenfa", 95);
	set_skill("hand", 100);
	set_skill("parry", 100);
	set_skill("literate", 55);
	set_skill("fengyun_shou", 90);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("hand", "fengyun_shou");
	map_skill("parry", "fengyun_shou");
	
	prepare_skill("hand", "fengyun_shou");
	
	set("chat_chance_combat", 10);  
	
	carry_object("anmenkey")->wield();
	carry_object("jinduan")->wear();
	carry_object("yaodai")->wear();
	carry_object("yaoshi")->wield();
	add_money(2000);
}

virtual char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		return "鳌拜怒道：你敢不让我睡觉，老子宰了你 ！";
	case 1:
		return "老子宰了你!";
	case 2:
		command("pain");
		return "";
		break;
	}

	return "";
}

virtual void die()
{
	message_vision("鳌拜狂叫道：想不到我一世威名竟然毁于你手！\n鳌拜顿了一顿，叹道：唉，只可惜我的那么多宝贝啊！\n$N哀嚎一声，死了！", this);
	CNpc::die();
}

NPC_END;