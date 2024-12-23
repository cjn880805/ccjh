// huashan_wugen.c

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNhuashan_wugen);

virtual void create()
{
	set_name("天雨道长", "wugen daozhang");
	set("title", "神龙教赤龙使");
	set("gender", "男性" );
	set("age", 55);
	set("long","这是个五十来岁的黑须道长,相貌威武,眼中略带杀气。");
	set("icon",old_man2);

	set("int", 30);
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	
	set("hp", 3000);
	set("max_hp", 9000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 500000);
	set("score", 15000);
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 40);
	
	set_skill("unarmed",90);
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("parry", 90);
	set_skill("sword", 100);
	set_skill("staff", 100);
	set_skill("literate", 80);
	set_skill("huashan_zhangfa", 60);
	set_skill("huashan_shenfa",80);
	set_skill("huashan_sword", 90);
	set_skill("zixia_shengong", 80);
	set_skill("shenlong_xinfa", 90);
	set_skill("shedao_qigong", 90);
	
	map_skill("force", "zixia_shengong");
	map_skill("unarmed", "huashan_zhangfa");
	map_skill("dodge", "huashan_shenfa");
	map_skill("parry", "huashan_sword");
	map_skill("sword", "huashan_sword");
	
	set_inquiry("洪安通","他是我们的教主。");
	set_inquiry("教主","教主脾气不好,要讨他欢心才好。");
	set_inquiry("入教",do_joinshenlong);
	set_inquiry("口号","万年不老!永享仙福!寿与天齐!文武仁圣!");
	
	carry_object("duanjian")->wield();
	add_money(1000);
}

virtual int do_talk(CChar *me, char * ask = NULL)
{
	if(! ask) return 0;
	if (me->query_temp("shenlong/join") && strcmp(ask, "join") == 0)
		return do_join(me);

	return CNpc::do_talk(me, ask);
}

static char * do_joinshenlong(CNpc * npc, CChar * me)
{
	me->set_temp("shenlong/join", 1);
	npc->say("你想加入我们神龙教么？", me);
	npc->AddMenuItem("我决定加入神龙教", "join", me);
	npc->AddMenuItem("算了，我还没想好呢。", "", me);
	npc->SendMenu(me);
	return "";
}

int do_join(CChar * me)
{
	if(me->query("shenlongjiao")) 
	{
		say("你已经是神龙教弟子了。" , me);
		SendMenu(me);
		return 1;
	}

	if ( me->query("repute")>-1000)
	{
		message_vision( "无根道长对$N大怒道：还想入教?一看你就不是好人!" , me);
		kill_ob(me); 
		return 1;
	}

	if (me->query_combat_exp()<20000)
	{
		say( "你的等级太低了，我们不要你。" , me);
		SendMenu(me);
		return 1;
	}

	if ( me->query_skill("bibo_shengong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1))
	{
		me->set("shenlongjiao",1);
		say("从今而后，你就是我神龙教弟子了！", me);
		SendMenu(me);
		return 1;	
	}
	else 
	{
		message_vision( "无根道长对$N大怒道：还想入教?一看你就不是好人!" , me);
		kill_ob(me); 
		return 1;
	}
}

virtual void init(CChar * me)
{
	if (userp(me))
	{
		if ( me->present("usedgao") )
			set("combat_exp", 100000);
		set("hp",100);
	}
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
    if ( ob->query_skill("shenlong_xinfa",1) < 40 ) 
	{
        say("你的本门内功心法太低了,还是努努力先提高一下吧!", ob);
		SendMenu(ob);
		return;
    }
    if ( ob->query_skill("shedao_qigong",1) < 40 ) 
	{
        say("你的本门杖法太低了,还是努努力先提高一下吧!", ob);
		SendMenu(ob);
		return;
    }
    if ( ob->query("repute") > -5000  )
	{
        say("我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！", ob);
		SendMenu(ob);
		return;
	}
    
    command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

NPC_END;