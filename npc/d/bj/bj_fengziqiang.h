//bj_fengziqiang.h	冯力强
//秦波 2003、6、9

NPC_BEGIN(CNbj_fengziqiang);

void create()
{
	set_name("冯力强","feng zi qiang");
	set("long", "冯力强有一张那种你再怎么看也记不住他相貌的大众脸，他的能力似乎也毫不出众，传说他能升到的位置也只是靠着十数年累计的军功和不错的运气罢了--因为和他同龄的军士不是战死便是退役或高升了。");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 10000);
	set("max_jing", 10000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 500000);
	
	set_skill("literate", 100);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("whip", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);
	set_skill("houquan", 200);
	set_skill("yunlong-xinfa", 200);
	set_skill("yunlong-shengong", 200);
	set_skill("wuhu-duanmendao", 200);
	set_skill("yunlong-jian", 200);
	set_skill("yunlong-shenfa", 200);
	set_skill("yunlong-bian", 200);
	set_skill("yunlong-shou", 200);
	set_skill("yunlong-zhua", 200);
	
	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");
	
	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");

	set("chat_chance_combat", 30);
	set("chat_chance", 30);

	carry_object("jinduan")->wear();
	carry_object("yaodai")->wear();
	carry_object("changjian")->wield();
	
	call_out(do_die, 3600);
	set("no_talk",1);
	
};

int do_talk(CChar * me, char * ask = NULL)
{
	if( me->query_temp("zhang/renwu6_1") && !me->query_temp("zhang/冯力强_jion")
		&& EQUALSTR(querystr("owner"), me->id(1)))
	{
		tell_object(me, "$HIR\n冯力强笑道：呵呵，你终于来了，张大人早已飞鸽传书通知过我。");
		tell_object(me, "$HIR不过你这么硬闯入军营，指挥大人早已躲起来藏身军营深处，准备纠集军士围剿你，还是我带路你一起去吧。");
		tell_object(me, "$HIR事到如今，即使我这密探的身份暴露也无所谓了。\n");
		me->set_temp("zhang/冯力强_jion",1);
		tell_object(me,"$HIC冯力强决定跟随你行动。\n");
		set_leader(me);
		set("jion",1);
		set_temp("zhang/冯力强_jion",1);
		return 1;
	}
	return CNpc::do_talk(me, ask);
}

virtual char * chat_msg_combat()
{
	switch(random(5))
	{
	case 0:
		perform_action("sword xian", 1);
		break;
	case 1:
		perform_action("force powerup", 0);
		break;
	}
	return 0;
}

virtual char * chat_msg()
{
	if(querystr("owner")[0])
	{
		CUser * me;
		me=find_online(querystr("owner"));
		if(me->query_temp("fight/is_fighting") && EQUALSTR(((me->environment())->environment())->name(1),(environment())->name(1)))
		{
			int team;
			CFightRoom * obj=(CFightRoom *)me->environment();
			if(me->query_temp("fight/fight_team"))		//加入A队
				team = 1;
			else
				team = 0;
			move(obj);
			obj->Join_Team(this, team);
		}
		else if(me->query("zhang/问题6"))
		{
			destruct(this);
		}
	}
	return 0;
}

virtual void die()
{
	if(querystr("owner")[0])
	{
		CUser * me;
		me=find_online(querystr("owner"));
		if(me)
		{
			me->delete_temp("zhang");
			me->set("zhang/renwu6_end",2);//2---任务失败
			tell_object(me,"\n$HIC冯力强缓缓的倒了下去，你的心中不禁一阵凄凉。");
			tell_object(me,"$HIR你刺杀王都指挥的任务失败。\n");
		}
	}
	CNpc::die();
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	destruct(me);
}

NPC_END;




