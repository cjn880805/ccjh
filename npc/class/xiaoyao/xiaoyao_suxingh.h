// xiaoyao_suxingh.c

//code by Fisho
//date:2000-12-22
//inherit F_MASTER;

NPC_BEGIN(CNxiaoyao_suxingh);

virtual void create()
{
	set_name("苏悬河","su xinghe");
	set("gender", "男性" );
	set("nickname", "一休老人");
	set("title","逍遥派第二代大弟子");
	set("long","此人就是号称一休老人的苏悬河，他极度能言善辩，是一个武林中的著名智者，而他的武功也是无人能知。 ");
	
	set("class", "scholar");
	set("age",60);
	set("str", 30);
	set("con", 30);
	set("int", 45);
	set("dex", 35);
	set("per", 30);
 	set("icon",old_man1);
	
	set("no_clean_up",1);
	set("combat_exp", 500000);
	set("attitude", "peaceful");
	set("book_count", 1);
	set("chat_chance", 1);
	
	set("max_hp", 10400);
	set("mp", 3500);
	set("max_mp",3500);
	set("mp_factor", 60);
	set("env/wimpy", 60);
	
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("unarmed", 180);
	set_skill("parry", 180);
	set_skill("blade", 180);
	set_skill("hand", 180);
	set_skill("lingboweibu", 180);
	set_skill("beiming_shengong", 180);
	set_skill("xiaoyao_dao", 180);
	set_skill("liuyang_zhang", 180);
	set_skill("zhemei_shou", 180);
	set_skill("literate", 180);
	
	map_skill("unarmed", "liuyang_zhang");
	map_skill("blade", "xiaoyao_dao");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming_shengong");
	map_skill("hand","zhemei_shou");
	
	prepare_skill("hand","zhemei_shou");
	prepare_skill("unarmed","liuyang_zhang");	
	
	create_family("逍遥派", 2, "弟子");
	
	carry_object("cloth")->wear();
	carry_object("gangdao")->wield();
	
	set_inquiry("秘密地道",ask_me);
	set_inquiry("凌霄十三剑",ask_book);
	set_inquiry("刀神一笑",ask_jl);
	set_inquiry("福地",ask_fd);
}

static char * ask_book(CNpc *who,CChar *me)
{
	if ( DIFFERSTR(me->querystr("family/family_name"), "逍遥派"))
	{
		return "想要知道凌霄快剑的秘密就得加入逍遥派。";
	}

	return "本派的武功精华——凌霄十三剑乃上代师祖所创，只有海棠之虎方得真传，但据说连他都未能修至凌霄快剑十三连招的境界。";
}

static char * ask_fd(CNpc *who,CChar *me)
{
	if ( me->query("xy/renwu1"))
	{
		if(!me->query_temp("xy/renwu1_1"))
			me->set_temp("xy/renwu1_1",1);//可以前往燕子坞晓寒厅询问王夫人关于福地的消息
		return "福地只听师傅提过，却不知具体坐落何处，不过听说姑苏王家王夫人与我逍遥派颇有渊源，若你前往相询，或会告知一二。";
	}

	return "什么？";
}

static char * ask_me(CNpc *who,CChar *me)
{
	if ( DIFFERSTR(me->querystr("family/family_name"), "逍遥派"))
	{
		return"想要知道密道就得加入逍遥派。";
	}

	me->set_temp("mask/舍身崖", 1);
	return "本派的密道在武当山之上，很是艰险。你若不怕死可以去看看。";
}

virtual void attempt_apprentice(CChar * ob)
{
	
	char msg[255];
	if (ob->query_int() < 30) 
	{
		command(snprintf(msg,255,"shake %ld", ob->object_id() )); 
		say(snprintf(msg,255,"%s是否还应该在学问上多下点功夫？",query_respect(ob) ), ob);
		SendMenu(ob);
		return;
	}
	
	say(" 好吧，我就收下你了，今后要多加努力啊！");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
	ob->set("class", "scholar");
	ob->FlushMyInfo();
}

static char * ask_jl(CNpc *who,CChar *me)
{
	if ( DIFFERSTR(me->querystr("family/family_name"), "逍遥派"))
	{
		return"你不是我们逍遥派的门人，打听这些做什么？";
	}
	if(me->query_temp("xiaoyao/禁令")==4)
	{
		me->add_temp("xiaoyao/禁令",1);
		return "「刀神一笑」我只见过师傅使用过一次，那绚丽夺目、宛如流星飞坠的场面，我至今都还记得清清楚楚。";
	}
	me->set_temp("xiaoyao/禁令",0l);
    return "自从丁春秋这个逆贼打伤了师傅逃走之后，我就再也没有见到师傅开心过了，也再也没有见过师傅出过手了。";
}


NPC_END;





