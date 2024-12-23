// pub_huo.c

// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_huo);

virtual void create()
{
	set_name("霍先生", "huo xiansheng");

	set("icon", old_man1);
	set("long","他一身邋遢，形容委琐，整天迷迷糊糊的睡不醒模样。可是他的账务十几年来无可挑剔。原来他就是伏牛派的崔千流，为避仇祸隐居于此。");
	
	set("gender", "男性");
	set("attitude", "heroism");
	
	set("age", 51);
	
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_hp", 1500);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 100);
	set("combat_exp", 100000);
	set("score", 100);
	set("apply/attack",  30);
	set("apply/defense", 30);
	
	set_skill("force", 50);
	set_skill("unarmed", 50);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	add_money(5000);
	
	set_inquiry("工资",ask_for_gongzi);
}

static char * ask_for_gongzi(CNpc *who,CChar *me)
{
	int paytimes;
	const char * oldtitle = me->querystr("title");

	if (strstr(oldtitle, "大理镇南王府武将"))  
	{
		paytimes =  me->query("mud_age") / 7200;
		if (me->query("dlpaytimes") < paytimes)
		{
			CMoney::Pay_Player(me,10000);
			me->add("dlpaytimes", 1);
			return "这是你本月的份额，收好吧。";
		}
		else 
			return "霍先生道：欺负我老糊涂？你本月工资已经领取过了！";
	}
	
	return "霍先生道：欺负我老糊涂？等你升到“大理镇南王府武将”再来领工资！";
}

NPC_END;