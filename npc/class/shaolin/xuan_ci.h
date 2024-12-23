//xuan_ci.h
//Lanwood 2000-01-09

NPC_BEGIN(CNshaolin_xuan_ci);

virtual void create()
{
	set_name("玄赐大师", "xuanci dashi");
	set("long",	"他是一位白须白眉的老僧，身穿一袭金丝绣红袈裟。他身材略显佝偻，但却满面红光，目蕴慈笑，显得神完气足。");
	
	set("title", "少林寺主持方丈");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
	set("foolid",104);
	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_hp", 10500);
	
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 150);
	set("combat_exp", 3000000);
	set("score", 800000);

    set_skill("force", 250);
	set_skill("hunyuan_yiqi", 180);
	set_skill("dodge", 150);
	set_skill("shaolin_shenfa", 180);
	set_skill("finger", 190);
	set_skill("strike", 180);
	set_skill("hand", 110);
	set_skill("claw", 200);
	set_skill("parry", 200);
	set_skill("nianhua_zhi", 200);
	set_skill("sanhua_zhang", 200);
	set_skill("fengyun_shou", 200);
	set_skill("longzhua_gong", 200);
	set_skill("buddhism", 200);
	set_skill("literate", 250);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("finger", "nianhua_zhi");
	map_skill("strike", "sanhua_zhang");
	map_skill("hand", "fengyun_shou");
	map_skill("claw", "longzhua_gong");
	map_skill("parry", "nianhua_zhi");

	prepare_skill("finger", "nianhua_zhi");
	prepare_skill("strike", "sanhua_zhang");

	create_family("少林派", 36, "弟子");

	set("chat_chance_combat", 45);
	set_inquiry("还俗", ask_me);

    carry_object("jiasha")->wear();
	set("no_huan",1);
};

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("finger fuxue", 1);
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
	if (DIFFERSTR(me->querystr("family/family_name"), "少林派"))
	{
		say("你与本派素无来往，不知此话从何谈起？", me);
		SendMenu(me);
		return;
	}

	if ( DIFFERSTR(me->querystr("class"), "bonze") && EQUALSTR(me->querystr("family/family_name"), "少林派")) 
	{
		say("你是俗家弟子，不能在寺内学艺。", me);
		SendMenu(me);
		return;
	}

	if ( me->query("family/generation") <= query("family/generation") )
	{
		say("这，贫僧哪里敢当 !", me);
		SendMenu(me);
		return;
	}

	char prename[3];

	strncpy(prename, me->name(1), 2)[2] = 0;

	if ( (me->query("family/generation") == query("family/generation") + 1)
		&& strcmp(prename, "澄") == 0)
	{
		say(snprintf(msg, 255, "%s的徒弟怎麽跑到我这儿来了，哈哈哈 !", me->querystr("family/master_name")));
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
		me->set("title", "少林主持亲传弟子");
		me->UpdateMe();
	}
	else
	{
		say("你辈份不合，不能越级拜师。", me);
		SendMenu(me);
	}
}

static char * ask_me(CNpc * npc, CChar * me)
{
	//if ( DIFFERSTR(me->querystr("family/family_name"), "少林派"))
    if( DIFFERSTR(me->querystr("class"), "bonze") )
	{
		npc->say("阿弥陀佛！出家人不打诳语。你是俗家人，如何问此还俗之事？", me);
		npc->SendMenu(me);
		return 0;
	}
/*
	if ( DIFFERSTR(me->querystr("family/family_name"), "少林派")) 
	{
		npc->say("阿弥陀佛！你不是我寺弟子，我怎知你该如何还俗呢？", me);
		npc->SendMenu(me);
		return 0;
	}
*/	
	npc->say(g_Channel.do_emote(npc, 0, "sigh", 1), me); 
    me->set_temp("pending/huansu", 1); 
    npc->say("你既然决意离开老衲也不强留", me);
    npc->say("不过根据少林历代规矩出寺都必须闯木人巷，你可愿意?", me);
	npc->AddMenuItem("我愿意", "$0decide $1", me);
	npc->AddMenuItem("打消此念", "", me);
	npc->SendMenu(me);
		
    return 0; 
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "decide") == 0 && me->query_temp("pending/huansu"))
	{
		me->delete_temp("pending_huansu");
		return do_decide(me);
	}

	return CNpc::handle_action(comm, me, arg);
}

int do_decide(CChar * me)
{
	load_item("lingpai")->move(me);
	me->say("弟子心意已决。", this);
	me->set_temp("teapot/passtest",1);
    say("好吧！看来少林真留不住你了，不过你记住出寺以后要多行善事，不得乱杀无辜，拿我的令牌闯木人巷去吧!", me);
    SendMenu(me);
	
    return 1;        
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "少林寺方丈室" ))
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
NPC_END;




