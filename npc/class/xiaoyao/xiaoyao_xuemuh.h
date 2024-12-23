//xiaoyao_xuemuh.c 薛慕华

//code by Fisho
//date:2000-12-22
//inherit F_MASTER;

NPC_BEGIN(CNxiaoyao_xuemuh);

virtual void create()
{
	set_name("薛仰陀", "xue muhua");
	set("long", "他就是号称药到命除的神医——薛仰陀，据说他精通医理，可以起死回生，但成功率不高。 ");
	set("gender", "男性");
	set("title","逍遥派“函谷八友”");
	set("nickname","药到命除");
	set("age", 50);
	set("class", "shaman");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 27);
	set("con", 25);
	set("dex", 25);
 	set("icon",old_man1);
	
	set("max_hp", 4500);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 60);
	set("combat_exp", 150000);
	set("score", 80000);
	
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("unarmed",90);
	set_skill("parry", 90);
	set_skill("lingboweibu",80);
	set_skill("beiming_shengong", 80);
	set_skill("zhemei_shou", 80);
	
	map_skill("unarmed", "zhemei_shou");
	map_skill("dodge", "lingboweibu");
	map_skill("parry", "zhemei_shou");
	map_skill("force", "beiming_shengong");
	
	create_family("逍遥派", 3, "弟子");
	
	carry_object("cloth")->wear();
	set("no_talk",1);

}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	say(" 好吧，我就收下你了，以后要多为逍遥派出力啊。");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

static void recover(CContainer * ob,LONG param1,LONG param2)
{
	CChar *me=(CChar *)(ob->environment())->Present(param1);

	if (!me)  return ;

	me->set("eff_hp", me->query("max_hp"));
	me->SendState(me);
	message_vision("大约过了一盅茶的时份，薛仰陀慢慢地站了起来。 ",me);
	message_vision("薛仰陀说道：你的伤势已经全好了,可以走啦。 ", me);
	return ;
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(! strlen(ask))
	{
		AddMenuItem("向薛仰陀请教关于疗伤的问题", "liaoshang",me);	
		AddMenuItem("向薛仰陀请教关于禁令的问题", "jingling",me);

		if(me->query_temp("xy/renwu1_4") && !me->query_temp("xy/renwu1_41"))
		{
			AddMenuItem("向薛仰陀请教关于毒伤的问题","dushang",me);
		}
		if(me->query_temp("xy/renwu1_5") && !me->query_temp("xy/renwu1_6"))
		{
			AddMenuItem("告知薛仰陀关于解毒之事","jiedu",me);
		}
		if(me->query_temp("xy/renwu1_61") && !me->query_temp("xy/renwu1_62"))
		{
			AddMenuItem("转告薛仰陀关于七夕相聚之事","qixi",me);
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "liaoshang") )
	{
		if (DIFFERSTR(me->querystr("family/family_name"), "逍遥派"))
		{
			say( "你不是我派弟子，我不可以为你疗伤。 ",me);
			SendMenu(me);
		}
		else if (me->query("eff_hp") == me->query("max_hp"))
		{
			command(snprintf(msg,255,"? %ld",me->object_id() ));     
			say("你没有受任何伤啊？ ", me);
			SendMenu(me);
		}
		else
		{
			message_vision("薛仰陀喂$N服下一颗摇头丸,然后盘膝坐下，双掌贴着$N的背心。 ", me);
			me->start_busy(5);
			remove_call_out(recover);
			call_out(recover,5,me->object_id());
		}
		return 1;
	}
	else if(!strcmp(ask, "jingling") )
	{
		if ( DIFFERSTR(me->querystr("family/family_name"), "逍遥派"))
		{
			say("你不是我们逍遥派的门人，打听这些做什么？",me);
		}
		me->set_temp("xiaoyao/禁令",1);
		say("师祖虽然传下来了「逍遥刀法」，但不知为何，始终不允许我们使用最后的绝招。",me);
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "dushang") )
	{
		if (me->query_temp("xy/renwu1_4") && !me->query_temp("xy/renwu1_41"))
		{
			//逍遥任务 可以获得 解毒清心丸
			CContainer * bot = load_item("jieduwan");
			bot->move(me);
			me->set_temp("xy/renwu1_41",1);//拿到给石甘露解毒的解毒清心丸
			say(snprintf(msg, 255,"原来是这么回事呀！%s正在为我逍遥劳累奔波，这里有颗「解毒清心丸」，%s就拿去救人吧！",query_respect(me),query_respect(me)),me);
		}
		else
			say("什么？",me);
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "jiedu") )
	{
		if (me->query_temp("xy/renwu1_5") && !me->query_temp("xy/renwu1_6"))
		{
			me->set_temp("xy/renwu1_6",1);//告之薛仰陀解救的是石甘露，启动七夕相聚
			say(snprintf(msg, 255,"薛仰陀听后不胜唏嘘：“想不到无意中竟然碰到了石师妹，%s快去把这消息告诉我大师兄康流水吧。",query_respect(me)),me);
		}
		else
			say("什么？",me);
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "qixi") )
	{
		if (me->query_temp("xy/renwu1_61") )
		{
			if(!me->query_temp("xy/renwu1_62") )
				me->set_temp("xy/renwu1_62",1);//通知薛仰陀参加七夕相聚
			say("薛仰陀略一沉吟道：“八弟李木偶，一生沉迷扮演戏文，疯疯颠颠，此刻也不知在哪个戏院里徘徊；而二师兄范千岁则沉迷对弈，只知他与一个叫霜天晓角的人交好。一时半会儿之间，我也无法同时通知！”",me);
			say(snprintf(msg, 255,"薛仰陀略一沉吟道：“这样吧，我去找吴四师兄，其他师兄弟就拜托%s转告了！”",query_respect(me)),me);
		}
		else
			say("什么？",me);
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

NPC_END;




