//longnv.h
//code by zwb
//12-23

ZUSHI_BEGIN(CNGuMu_longnv);

virtual void create()
{
	set_name("龙儿","long er");
	
	set("gender", "女性");
	set("age", 18);
	set("long","一个清纯美丽的少女，犹如天仙一般。实当得起“冷浸溶溶月”的形容。");
	set("attitude", "friendly");
	set("icon", young_woman1);
	
	set("per", 30);
	set("str", 30);
	set("int", 37);
	set("con", 36);
	set("dex", 38);
	set("foolid",59);	
	set("chat_chance_combat", 9);
	
	set("chat_chance", 20);
	
	set("hp", 9500);
	set("max_hp", 10500);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 100);
	
	set("combat_exp", 1500000);
	
	set_skill("force", 250);
	set_skill("yunv_xinfa", 250);    //玉女心法
	set_skill("yunv_xinjing", 280);	 //玉女心经
	set_skill("yinsuo_jinling", 200);	//银索金铃
	set_skill("sword", 250);
	set_skill("whip", 230);
	set_skill("yunv_jian", 250);     //玉女剑
	set_skill("quanzhen_jian",140);  //全真剑
	set_skill("dodge", 260);
	set_skill("yunv_shenfa", 260);   //玉女身法
	set_skill("parry", 180);
	set_skill("hubo", 180);          //双手互搏
	set_skill("unarmed",220);
	set_skill("meinv_quan", 220);    //美女拳法
	set_skill("literate",220);
	set_skill("qufeng",350);         //驱蜂之术
	set_skill("tianluo_diwang", 250);
	
	map_skill("force", "yunv_xinjing");
	map_skill("sword", "yunv_jian");
	map_skill("dodge", "yunv_shenfa");
	map_skill("parry", "meinv_quan");
	map_skill("unarmed", "meinv_quan");
	
	create_family("古墓派", 3, "弟子");
	
	set("book_count", 1);
	set("count",1);
	set_temp("have_zhen", 5);
	set_temp("have_suo", 1);
	
	set_inquiry("过儿",ask_me);
	set_inquiry("玉女剑法","玉女剑法和全真剑法合壁，天下无敌！");
	set_inquiry("古墓派","我的林祖师婆婆本来和重阳先师是一对璧人，可是...");
	set_inquiry("玉女心经",ask_yunv);
	set_inquiry("玉蜂针",ask_zhen);
	set_inquiry("金铃索", ask_suo);
	
	set("env/wimpy", 40);
	
	carry_object("shunvjian")->wield();
	carry_object("baipao")->wear();
	set("no_huan",1);
}

virtual char * chat_msg_combat()
{
	switch(random(4))
	{
	case 0:
		perform_action("force recover", 0);
		break;
	case 1:
		perform_action("sword he", 1);
		break;
	case 2:
		perform_action("unarmed you", 1);
		break;
	case 3:
		perform_action("force roar", 1);
		break;
	}
	return "";
}

virtual char * chat_msg(CChar * player)
{
	switch(random(3))
	{
	case 0:
		return "过儿那个负心薄幸的人，我当年实在看错他了";
	case 1:
		return "玉女剑与全真剑合壁，是可天下无敌。可是那个人已经不在了……";
	case 2:
		return "龙儿深深地叹了口气，转过头去。";
	}
	return "";
}

virtual void attempt_apprentice(CChar  * player)
{
	if(DIFFERSTR(player->querystr("family/family_name"), "古墓派"))
	{
		say(" 对不起，我不和外人打交道。",player);
		SendMenu(player);
		return;
	}
	if(EQUALSTR(player->querystr("class"), "taoist"))
	{
		say(" 你是我师姐门人，来找我干什么？",player);
		SendMenu(player);
		return;
	}
	if(player->query("repute") < 50000)
	{
		say(" 古墓派有我师姐一个就够了，我可不想再有人败坏古墓名声。",player);
		SendMenu(player);
		return;
	}
	if(player->query_dex() < 30)
	{
		say(" 你这么笨拙学不了我古墓的功夫。",player);
		SendMenu(player);
		return;
	}
	if(player->query_int() < 40)
	{
		say(" 收你这么蠢的弟子，一定会给气得吐血的，不要不要。",player);
		SendMenu(player);
		return;
	}
	if(player->query_skill("yunv_xinfa", 1) < 100)
	{
		say(" 你对本门心法的认识还浅，回去找孙奶奶认真学学吧。",player);
		SendMenu(player);
		return;
	}
	if(player->query_skill("tianluo_diwang", 1) < 100)
	{
		say(" 你对天罗地网势的认识还浅，回去找孙奶奶认真学学吧。",player);
		SendMenu(player);
		return;
	}
	if(player->query("max_mp") < 1000)
	{
		say(" 你的内力修为不浅，学不了这么高深的功夫。",player);
		SendMenu(player);
		return;
	}
	
	else
	{
		say(" 好吧，我就收下你这个徒弟了。");
		recruit_apprentice(player);
	}
}


static char * ask_yunv(CNpc * npc , CChar * player)
{
	CContainer * ob;
	static char msg[255];
	
	if(DIFFERSTR(player->querystr("family/family_name"), "古墓派"))
		return snprintf(msg,255,"%s与本派毫无瓜葛，何以问起本派的心经？",player->name());
	
	if(EQUALSTR(player->querystr("class"), "taoist"))
		return "笑话，会给你才怪。";
	
	if (npc->query("book_count") < 1)
		return "你来晚了，本派的玉女心经已经被人取走了。";
	
	npc->add("book_count", -1);
	ob = load_item("yunvjing1");
	ob->move(player);
	return "好吧，这本「玉女心经」你拿回去好好研读。";
}

static char * ask_me(CNpc * npc , CChar * player)
{	
	CContainer  * obj;
	
    if(npc->query("count") < 1)
		return "你知道过儿的下落？刚才已经有人告诉我了，谢谢你。";
	
	player->set_temp("marks/ask_long", 1);
    npc->add("count", -1);
    obj=load_item("junzijian");
    obj->move(player);
    return "这柄君子剑送给你做个信物，见到过儿的时候请交给他。";
}

static char * ask_zhen(CNpc * npc , CChar * player)
{
	if(DIFFERSTR(player->querystr("family/family_name"), "古墓派"))
		return "你不是我古墓派的弟子，不能给你。";	
	if(EQUALSTR(player->querystr("class"), "taoist"))
		return "你找我师姐要冰魄银针去吧，玉蜂针可不能给你。";
	if(player->query_temp("mark/get_yufeng_zhen"))
		return "你不是刚拿过吗？不要那么贪心好不好？";
	if(npc->query("have_zhen") < 0)
		return "你来迟了，玉蜂针已给了你其他同门了。";
	
	load_item("yufeng_zhen")->move(player);
	
	player->set_temp("mark/get_yufeng_zhen",1);
	npc->add_temp("have_zhen", -1);
	
	message_vision("龙儿给了$N一把玉蜂针。", player);
	return "";
}

static char * ask_suo(CNpc * npc , CChar * player)
{
	if(DIFFERSTR(player->querystr("family/family_name"), "古墓派"))
		return "你不是我古墓派的弟子，不能给你。";		
	if(EQUALSTR(player->querystr("class"), "taoist"))
		return "你学的不是三无三不手吗？要金铃索干什么？";
	if(npc->query_temp("have_suo") != 1)
		return "你来迟了，金铃索已给了你其他同门了。";
	
	load_item("ring_whip")->move(player);
	
	npc->delete_temp("have_suo");
	
	message_vision("龙儿给了$N一条金铃索。", player);
	return "";
}

virtual int prevent_learn(CChar * me, const char * arg)
{
	if (EQUALSTR(me->querystr("family/family_name"), "古墓派")) return 0;
	
	me->add_temp("tmark/龙", -1);
	
    if(! me->query_temp("tmark/龙"))
	{
        say("龙儿叹了口气，看看你，说道：咱们的缘分已经尽了,我也没什么东西可教你的了,来世再见吧。", me);
		SendMenu(me);
		
		DownLoad(me);
		return 1;
	}
	
	return 0;
}

virtual int recognize_apprentice(CChar * me)
{
	if(me->query_temp("tmark/龙"))
        return 1;
	
	return 0;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "古墓正厅" ))
		return notify_fail("我这是在哪里？");
	char msg[255];
	int exp;
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
	else if(EQUALSTR(ob->querystr("id"), "jue qing dan")&& who->query_temp("gumu/jq_dan_nv") && !who->query("gumu/完成"))
	{
		say("过儿。。。。");
		say("真的太感谢你了，这是我的一点心意，请收下。");
		who->set("gumu/完成",1);
		SendMenu(who);
		destruct(ob);
		g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "$HIC%s弟子%s(%s)$HIY勇闯绝情谷，大败公孙指替龙儿找回绝情丹。$COM",  who->querystr("family/family_name"),who->name(1),who->id(1)));
		exp=who->query("age")*who->query("level");
		if(exp<3000)
			exp=2000+random(3000);
		int repute=random(int(exp/2))+exp;
		if(who->query("repute")<0)
			repute=-repute;
		who->add("repute",repute);
		who->set("xkd/gumu",1);
		if(DIFFERSTR(who->querystr("family/family_name"), "古墓派"))
		{
			who->add("combat_exp",exp);
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "$HIC%s获得$HIY%d$HIC点的任务经验奖励，同时获得了%d点的江湖声望。\n\n$COM",who->name(1), exp,repute));
			message_vision (snprintf(msg, 255, "$HIR$N获得了%d的任务经验奖励，同时获得了%d点的江湖声望。",exp,repute),who);
		}
		else
		{
			CContainer * bot = load_item("skybook");
			bot->move(who);
			who->add("combat_exp",exp);
			message_vision (snprintf(msg, 255, "$HIR$N获得了%d的任务经验奖励，同时获得了%d点的江湖声望",exp,repute),who);
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "$HIC%s获得$HIY%d$HIC点的任务经验奖励、一本$HIY“无字天书”，同时获得了%d点的江湖声望。\n\n$COM",  who->name(1),exp,repute));
			g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s(%s)获得了无字天书。", who->name(1),who->id(1)));
		}
		who->delete_temp("gumu/jq_dan_nv");
		who->set("gumu/jq",who->query("age"));
		return 1;
	}
	else if (EQUALSTR(ob->querystr("id"), "skybook")&& who->query("gumu/jq")==who->query("age") && EQUALSTR(who->querystr("family/family_name"), "古墓派"))
	{
		destruct(ob);
		say("你不想要这个？",who);
		say("那好吧，我告诉你一个秘密。",who);
		say("是关于祖师婆婆的秘密。",who);
		say("祖师婆婆现在住在一个很清净的地方。",who);
		say("如果你有恒心的话，可以潜水进去找到她。",who);
		who->set_temp("gumu/lin",1);
		SendMenu(who);
		return 1;
	}
	else
		return 0;
}


ZUSHI_END;




