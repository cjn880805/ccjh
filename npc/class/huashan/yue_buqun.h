//yue_buqun.h
//Lanwood 2000-01-08

ZUSHI_BEGIN(CNhuashan_yue_buqun);

virtual void create()
{
	set_name("岳不凡",  "yue bufan");
	set("title", "华山派掌门");
	set("nickname", "君子剑");
	set("gender", "男性");
	set("class", "swordsman");
	set("age", 55);
	set("long",
		"岳不凡自幼执掌华山派，乃当今武林中一等一的高手。");
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);
	set("icon",old_man1);
	
	set("mp", 2400);
	set("max_mp", 2400);
	set("mp_factor", 30);
	set("max_hp",6000);
	
	set("combat_exp", 1000000);
	set("repute", -200000);
//	set("xunshan", 1);
	set("apprentice_available", 3);
	
	set("chat_chance_combat", 20);
	
	set_skill("unarmed", 200);
	set_skill("sword", 220);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("literate", 180);
	set_skill("huashan_shenfa", 200);
	set_skill("huashan_sword", 220);
	set_skill("zixia_shengong", 220);
	set_skill("hunyuan_zhang", 200);
	set_skill("pixie_sword",250);
	set_skill("zhengqijue",200);
	
	map_skill("sword", "pixie_sword");
	map_skill("parry", "pixie_sword");
	map_skill("force", "zixia_shengong");
	map_skill("unarmed", "hunyuan_zhang");
	map_skill("dodge", "huashan_shenfa");
	
	create_family("华山派", 13, "掌门");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	carry_object("zixia_book");
	carry_object("allow_letter");
	
	remove_call_out(do_reset);
	call_out(do_reset, 900, 0);	
	set("no_huan",1);
};

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("force powerup", 0);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];

    if( query("apprentice_available") ) 
	{
        if( me->query_int() < 20 )
                say(snprintf(msg, 255, "我华山派以剑法为主，依我看不适合于学剑法。", query_respect(me)), me);
        else 
		{
			say("好，好，好，很好。");
			command(snprintf(msg, 80, "recruit %ld", me->object_id()) );
			
            //me->set("class", "swordsman");
			add("apprentice_availavble", -1);
			return;
        } 
	}
	else
        say("老夫今天已经收了三个弟子，不想再收徒了。", me);
      
	SendMenu(me);
}

static void do_reset(CContainer * ob, LONG param1, LONG param2)
{
	ob->set("apprentice_available", 3);
}

/*
virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(me->querystr("family/family_name") == "华山派")
	{
		ask_for_xunshan(me);
		return 1;
	}

	return CNpc::do_talk(me, ask);
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "xunshan") == 0 && me->query_temp("pending/xunshan"))
	{
		me->delete_temp("pending/xunshan");
		return do_xunshan(me);
	}

	return 0;
}

void ask_for_xunshan(CChar * me)
{
	if (! me->query_tempmap("xunshan"))
    {
		AddMenuItem(
	}

        if (! me->query_temp("xunshan/chaoyang"))
        {
              message_vision("$N对着$n说：你朝阳峰没去看看？这算巡的什么山？\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/lianhua"))
               {
                      message_vision("$N对着$n说：你莲花峰没去看看？这算巡的什么山？\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/yuntai"))
               {
                      message_vision("$N对着$n说：你云台峰没去看看？这算巡的什么山？\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/sheshen"))
               {
                      message_vision("$N对着$n说：你怎么没去舍身崖？这算巡的什么山？\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/siguo"))
               {
                      message_vision("$N对着$n说：你到了思过崖去了？这算巡的什么山？\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/yunu"))
               {
                      message_vision("$N对着$n说：你到玉女峰后面华山小筑去看过了？这算巡的什么山？\n", this_object(), me);
                      return 1;
               }
               message_vision("$N对着$n说：不错，辛苦了。你这就去休息去吧。\n", this_object(), me);
               me->delete_temp("xunshan");                      
               me->add("combat_exp", random(100));
               return 1;
        }
        else
        {
               if ( query("xunshan") < 1)
               {
                      message_vision("$N对着$n说：今天已经有人巡山去了。你明天再来吧。\n", this_object(), me);
                      return 1;
               }
               if( me->query("family/family_name") != "华山派")
               {
                      message_vision("$N对着$n大喝一声：本派弟子才能巡山。你是哪来的奸细？休怪我剑下不留情！\n", this_object(), me);
                      this_object()->kill_ob(me);
                      return 1;
               }
               else
               {
                      add("xunshan", -1);
                      message_vision("$N对着$n说：本派弟子例当巡山。你，很好，很好！这就去吧。\n", this_object(), me);
                      me->set_temp("xunshan/start", 1);
                      me->set_temp("xunshan/time", time());
                      return 1;
               }
        }
}
*/
virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "华山群仙观" ))
		return notify_fail("我这是在哪里？");
	char msg[255];
	if(EQUALSTR(ob->querystr("id"),"bao guo") && EQUALSTR(ob->querystr("obj"),id(1)) &&
		EQUALSTR(ob->querystr("owner1"),who->id(1)))
	{
		who->add_temp("lin/baoguo/count",1);
		int exp=ob->query("exp");
		int repute=ob->query("repute");
		
		tell_object(who, snprintf(msg, 255, "\n$YEL%s点了点头，收下了你送过来的包裹。",name(1)));
		tell_object(who, "\n$YEL你完成了替福威镖局押运暗镖的任务。");
		tell_object(who, snprintf(msg, 255, "$YEL获得了%d的经验奖励，江湖声望上升了%d点",exp,repute));
		g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s(%s)压运暗镖成功，获得了%d的经验奖励，江湖声望上升了%d点！", who->name(1), who->id(1),exp,repute));
		who->delete_temp("lin/baoguo/start");
		if(who->query_temp("no_fei"))who->delete_temp("no_fei");
		who->add("combat_exp",exp);
		who->add("repute",repute);
		who->UpdateMe();
		destruct(ob);
		return 1;
	}
	return 0;
}
ZUSHI_END;
