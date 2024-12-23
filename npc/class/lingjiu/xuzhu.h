//xuzhu.h
//Lanwood 2000-01-08

NPC_BEGIN(CNlingjiu_xuzhu);

virtual void create()
{
	set_name("竹虚", "zhu xu");
	set("long",	    "这是一个二十五六岁的年轻人, 浓眉大眼,大大的鼻子扁平下塌, 容貌颇为丑陋. ");
	set("title", "灵鹫宫尊主");
	set("gender", "男性");
	set("per", 16);
	set("age", 26);
	set("nickname", "梦郎");
	set("shen_type",1);
	set("attitude", "peaceful");
	set("icon",young_man1);

	set("str", 30);
	set("int", 25);
	set("con", 40);
	set("dex", 30);

	set("max_hp", 12000);
	
	set("mp", 8000);
	set("max_mp", 8000);
	set("mp_factor", 160);

	set("combat_exp", 2500000);
	set_skill("force", 220);
	set_skill("unarmed", 250);
	set_skill("dodge", 220);
	set_skill("parry", 220);
	set_skill("hand",220);
	set_skill("strike", 220);

	set_skill("zhemei_shou",220);
	set_skill("liuyang_zhang",220);
	set_skill("yueying_wubu",200);
	set_skill("bahuang_gong", 230);
    set_skill("tianyu_qijian", 220);

	map_skill("force", "bahuang_gong");
	map_skill("strike","liuyang_zhang");
	map_skill("dodge", "yueying_wubu");
	map_skill("unarmed", "liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");
    map_skill("sword", "tianyu_qijian");

//	set_inquiry("灵鹫令", ask_me);
	
	set("ling_count", 1);

	prepare_skill("strike", "liuyang_zhang");
	prepare_skill("hand", "zhemei_shou");
	create_family("灵鹫宫",2,"尊主");
	set("chat_chance_combat", 50);
	
	carry_object("changjian")->wield();
 	carry_object("changpao")->wear();
    carry_object("jiudai");
    add_money(5000);
	set("no_talk",1);
};

virtual void init(CChar * me)
{
	CNpc::init(me);

	char msg[255];
	if(userp(me) && !is_fighting() && me->query("lj/renwu13") && EQUALSTR(me->querystr_temp("apply/name"),"竹虚"))
	{
		CContainer * env=me->environment();
		DTItemList * list = env->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		while(p) 
		{ 
			CContainer * obj = list->GetNext(p);
			if(! obj->is_character()) continue; 
			CChar * target = (CChar *)obj;  
			if(userp(target))	continue;
			if(EQUALSTR(target->querystr("name"), "银川公主")  && EQUALSTR(target->querystr("owner"),me->id(1)))
			{
				target->set_leader(0);
				message_vision("\n$HIR银川公主看着面前两个竹虚，惊讶得说不出话来！",me);
				me->set_temp("lj/end",1);
				break;
			}
		}
		if(me->query_temp("lj/end"))
		{
			//销毁面具
			DTItemList * list = me->Get_ItemList();  
			POSITION p = list->GetHeadPosition(); 
			while(p) 
			{ 
				CContainer * obj = list->GetNext(p);
				if(obj->is_character()) continue; 
				CChar * target = (CChar *)obj;  
				if(userp(target))	continue;
				if(EQUALSTR(target->querystr("apply/name"),"竹虚") && EQUALSTR(target->name(1),"秘制人皮面具")
					&& EQUALSTR(target->querystr("主人"),me->id(1)) && EQUALSTR(target->querystr("id"),"killermask"))
				{
					me->delete_temp("apply/name");
					me->delete_temp("apply/id");
					me->delete_temp("apply/long");
					me->delete_temp("apply/short");
					me->delete_temp("apply/icon");
					me->delete_temp("apply/title");

					destruct(target);
					me->UpdateMe();
					break;
				}
			}
			message_vision("\n$HIR你褪下人皮面具，露出原本属于女性的清秀脸庞，对公主歉然一笑道：“多有冒犯了，公主。",me);
			message_vision("$HIR其实梦郎是我们灵鹫宫的尊主竹虚先生，不过我却不是竹虚，我不过是机缘巧合下冒充了他，那些答案的话也是他告诉我的哩！",me);
			message_vision("$HIR看来你们俩还真是有段缥缈奇缘，这样也能重聚在一起！”",me);
			message_vision("\n$HIR公主对着竹虚痴喃道：“这是真的么，梦郎？”",me);
			message_vision("\n$HIR竹虚看着公主的双眸，深情道：",me);
			message_vision("$HIR“你那日说--我怕你一出口，我这场梦便醒了。你是我的梦中情郎，我叫你‘梦郎’，梦郎，梦郎，你说这名字好不好？",me);
			message_vision("$HIR如今这梦却成真了，你的梦郎活生生站在你眼前……”",me);
			message_vision("$HIR说罢，便将公主拥入怀中。公主嘤呤一声，也将头靠在了竹虚胸前……",me);
			message_vision("\n$HIR你看着二人如此恩爱，不忍心打扰，默默走开了，但心中对“柔情”更是理解得深了一层……\n",me);
			
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "$HIC%s弟子%s(%s)$HIY乔装打扮，千里迢迢前往西夏皇宫参加比武招亲，历尽重重考验，终于成全一段“缥缈奇缘”的佳话。$COM",  me->querystr("family/family_name"),me->name(1),me->id(1)));
			//完成“缥缈奇缘”任务，奖励10级柔情指
			if(me->query_skill("rouqing_zhi",1)<600)
				me->set_skill("rouqing_zhi",me->query_skill("rouqing_zhi", 1)+10);
			me->del("lj");
			me->delete_temp("lj");
			me->FlushMySkill(me);
		}
		
	}
}

virtual char * chat_msg_combat()
{
	char msg[40];
	CContainer * jian = PresentName("changjian", IS_ITEM);

	switch(random(8))
	{
	case 0:
			perform_action("strike zhong", 1);
			break;
	case 1:
			perform_action("hand duo", 1);
			break;
	case 2:
			perform_action("sword san", 1);
			break;
	case 3:
	case 4:
			if(query_weapon() == jian && jian)
				command(snprintf(msg, 40, "unwield %ld", jian->object_id()));
			break;
	case 5:
	case 6:
			if(jian && ! query_weapon())
				command(snprintf(msg, 40, "wield %ld", jian->object_id()));
			break;
	case 7:
	case 8:
			perform_action("force recover", 0);
			break;
	}
	
	return 0;
}

static char * ask_me(CNpc * me, CChar * who)
{
	if (DIFFERSTR(who->querystr("family/family_name"), "灵鹫宫"))
			return "你与本派素无来往，不知此话从何谈起？";

	if (me->query("ling_count") < 1)
		return "你来得不是时候，已经有人在练功了。";

	CContainer * ob = load_item("lingjiu");
	ob->move(who);
	me->add("ling_count", -1);

	message_vision("竹虚给$N一个$n", who, ob);
	return "拿去吧。";
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];

	if ( me->query_skill("bahuang_gong", 1) < 150) 
    {
		say(snprintf(msg, 255, "%s是否还应该多练练八荒六合唯我独尊功？", query_respect(me)), me);
		SendMenu(me);
		return;
	}  

    if (EQUALSTR(me->querystr("gender"), "女性"))
    {
		message_vision("竹虚垂目沉思片刻, 说道：“好吧, 我就收下你了。”", me);
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
		me->set("class", "officer");
		me->UpdateMe();
        return;
	}
   
	say("竹虚瞪着你看了半天,说道：“阁下不会是想来抢我的MM吧?”", me);
	SendMenu(me);
}


virtual int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(me->query("lj/renwu_ok") && !me->query_temp("lj/renwu_ok_xz"))
	{
		tell_object(me, "\n$HIR竹虚叹了口气，说道：“哎……还是我太笨了，无力劝解师叔和师伯，导致她们俩人两败俱伤。");
		tell_object(me, "$HIR我已把师伯送回来了，她们俩直到伤的都不能动了，还说“若想化解恩怨，除非做梦！");
		tell_object(me, "$HIR哎……");
		tell_object(me, "$HIR师伯现在正在闭关室养伤吧！她说过一定会感谢你的，请你去见她一面。”\n");
		me->set_temp("lj/renwu_ok_xz",1);
		
		if(EQUALSTR(me->querystr("gender"), "女性") && EQUALSTR(me->querystr("family/family_name"), "灵鹫宫") )
		{
			tell_object(me, "\n$YEL你正欲离去，忽然竹虚又将叫住，有些扭捏的问道：");
			tell_object(me, snprintf(msg, 255,"$YEL“%s……你在护送师伯去西夏的路上……有没有听师伯提到个叫……梦姑……的女子？”",me->name(1)));
			tell_object(me, "$YEL你回头答道：“哦！那到没有，那时被李秋痕追迫得甚紧，几乎没和外人说过话的。”");
			tell_object(me, "$YEL只见竹虚脸上毫不掩饰失望的神情，痴痴道：“那梦姑……是我喜欢的女子……如果你知道她的下落的话，请务必告知。”");
			tell_object(me, "$YEL你不由得奇怪起来，难道竹虚在西夏呆的这几天就还爱上她了？口中却说到：“义不容辞！”");
			tell_object(me, "$YEL竹虚面露欣慰之色，道：“那我便不耽搁你去见铁姥了！”\n");
			me->set("lj/renwu10",1);
		}
	}
	else if(me->query("lj/renwu_lost"))
	{
		if(me->query("lj/renwu_lost")==1)
		{
			tell_object(me, "$HIW竹虚痛苦的说道：“什么！那女童就是铁姥师伯啊！你竟然不将她救出，算我看错你了！”");
			me->del("lj");
			me->delete_temp("lj");
			me->set("hp",100);
			me->set("eff_hp",100);
			me->set("mp",0l);
			if(me->query("level")<80)
			{
				me->add("combat_exp",-me->query("level")*200);
				message_vision(snprintf(msg, 255, "$HIR$N执行灵柩任务“缥缈奇缘”中，护主无力，导致任务失败。\n$N江湖经验下降%d点。",me->query("level")*200),me);
			}
			else
			{
				me->add("combat_exp",-me->query("level")*500);
				message_vision(snprintf(msg, 255, "$HIR$N执行灵柩任务“缥缈奇缘”中，护主无力，导致任务失败。\n$N江湖经验下降%d点。",me->query("level")*500),me);
			}
		}
		else
		{
			tell_object(me, "$HIW竹虚痛苦的说道：“你竟然没能保护好师伯！你令我太失望了！”");
			
			me->set("hp",100);
			me->set("eff_hp",100);
			me->set("mp",0l);
			if(me->query("level")<80)
			{
				me->add("combat_exp",-me->query("level")*200);
				message_vision(snprintf(msg, 255, "$HIR$N执行灵柩任务“缥缈奇缘”中，护主无力，导致任务失败。\n$N江湖经验下降%d点。",me->query("level")*200),me);
			}
			else
			{
				me->add("combat_exp",-me->query("level")*500);
				message_vision(snprintf(msg, 255, "$HIR$N执行灵柩任务“缥缈奇缘”中，护主无力，导致任务失败。\n$N江湖经验下降%d点。",me->query("level")*500),me);
			}
		}
		if(me->query("pro/skill/bahuang_gong"))
		{
			me->set_skill("bahuang_gong",me->query_skill("bahuang_gong",1)-1);
			me->add("pro/skill/bahuang_gong",-1);
			me->FlushMySkill(me);
		}
		if(me->query("lj/pro/skill/liuyang_zhang"))
		{
			me->set_skill("liuyang_zhang",me->query_skill("liuyang_zhang",1)-me->query("lj/pro/skill/liuyang_zhang"));
			me->add("pro/skill/liuyang_zhang",-me->query("lj/pro/skill/liuyang_zhang"));
			me->FlushMySkill(me);
		}
		if(me->query("lj/pro/skill/musci"))
		{
			me->set_skill("musci",me->query_skill("musci",1)-me->query("lj/pro/skill/musci"));
			me->add("pro/skill/musci",-me->query("lj/pro/skill/musci"));
			me->FlushMySkill(me);
		}
		if(me->query("lj/pro/skill/strike"))
		{
			me->set_skill("strike",me->query_skill("strike",1)-me->query("lj/pro/skill/strike"));
			me->add("pro/skill/strike",-me->query("lj/pro/skill/strike"));
			me->FlushMySkill(me);
		}
		if(me->query("pro/lj/int"))
		{
			me->add("int",-1);
			me->add("pro/lj/int",-1);
			me->UpdateMe();
		}
		me->del("lj");
		me->delete_temp("lj");
	}
	else if(me->query_temp("lj/dating") &&me->query_temp("lj/humang")>10)
	{
		tell_object(me, "$HIW竹虚焦虑的说道：铁姥师伯失踪，我心急如焚，但宫内变乱不定无记分身，请你务必代我寻找铁姥下落，本人一待宫内诸事料理完毕，即刻下山与你会合！");
		me->set_temp("lj/shizhong",1);
		me->delete_temp("li/hm");
		me->delete_temp("li/humang");
		me->delete_temp("lj/dating");
	}
	
	return CNpc::do_talk(me,ask);
}
NPC_END;

