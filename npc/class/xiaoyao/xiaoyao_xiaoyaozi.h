// xiaoyao_xiaoyaozi.c 逍遥子

//code by Fisho
//date:2000-12-22
//inherit F_MASTER;

ZUSHI_BEGIN(CNxiaoyao_xiaoyaozi);

virtual void create()
{
	set_name("逍遥女", "xiaoyao nv");
	set("title", "逍遥派祖师");
	set("long","她就是逍遥派祖师、曾经是江湖上的绝世英雌，尽管因为岁月如流 她在江湖中已经不是很多人知道，但她的功夫却还是深不可测。。。。。 ");
	set("gender", "女性");
	set("age", 75);
	set("class", "scholar");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("per", 40);
 	set("icon",old_woman);
	
	set("max_hp", 15500);
	set("mp", 12000);
	set("max_mp", 12000);
	set("mp_factor", 100);
	set("combat_exp", 10000000);
	set("score", 200000);
	
	set_skill("force", 300);
	set_skill("beiming_shengong", 300);
	set_skill("dodge", 400);
	set_skill("lingboweibu", 280);
	set_skill("unarmed", 280);
	set_skill("liuyang_zhang", 150);
	set_skill("parry", 250);
	set_skill("blade", 250);
	set_skill("xiaoyao_dao", 250);
	set_skill("zhemei_shou", 250);
	set_skill("hand", 250);
	set_skill("strike", 250);
	set_skill("literate", 320);
	
	map_skill("force", "beiming_shengong");
	map_skill("dodge", "lingboweibu");
	map_skill("hand", "zhemei_shou");
	map_skill("strike", "liuyang_zhang");
	map_skill("parry", "xiaoyao_dao");
	map_skill("blade", "xiaoyao_dao");
	
	prepare_skill("hand","zhemei_shou");
	prepare_skill("strike","liuyang_zhang");
	
	create_family("逍遥派", 1, "开山祖师");
	set("class", "taoist");

	set("no_chan",1);
	
	carry_object("gangdao")->wield();
	set("no_huan",1);
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	if (ob->query_skill("beiming_shengong", 1) < 80) 
	{
		say("我逍遥派内功的源泉来自于北冥神功的心法。", ob); 
		say(snprintf(msg,255,"%s的北冥神功是否还应该有所提高啊？",query_respect(ob) ), ob);
		SendMenu(ob);
		return;
	}
	
	if (ob->query_int() < 35) 
	{
		say(" 我逍遥派武功最重视“逍遥”二字。", ob);
		say(" 而何谓“逍遥”，这只能靠你自己去领悟。", ob);
		say(snprintf(msg,255," 但是%s的悟性似乎还有待提高啊。",query_respect(ob) ), ob);
		SendMenu(ob);
		return;
	}
	command("smile");
	say(" 想不到在这世上竟然还有人可以继承我的逍遥心法！");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
//	ob->set("xiaoyao/xiaoyaozi", 1);
	ob->set("title","逍遥派护法使者");
	ob->UpdateMe();
}
/*
virtual int accept_object(CChar * who, CContainer * ob)
{
	if(who->query("xiaoyao/xiaoyaodao")>=9)		return 0;
	if(who->query("xiaoyao/禁用绝招")==1)		return 0;
	if(DIFFERSTR(ob->querystr("name"), "帛卷") )		return 0;
	destruct(ob);
	say("你这个逆徒，让你不得擅自泄露本门绝招，你偏偏总是忍不住要出去卖弄一番！", who);
	say("还把我留你防身的宝刀弄损，真是暴轼天物！", who);
	say("要不是这次看在你拿回我逍遥派镇山至宝［帛卷］的份上，我才不会再饶过你！", who);
	say("给我滚出去，去你师兄那里去找把破刀用着。下次要是再违禁令，看我是怎样的收拾你！", who);
	SendMenu(who);
	who->add("hp",-200);
	who->add("xiaoyao/挨骂", 1);
	who->add("xiaoyao/xiaoyaodao", 1);
	return 1;
}
*/

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "逍遥林石屋" ))
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
	else if(EQUALSTR(ob->querystr("name"),"帛卷"))
	{
		if(who->query("xiaoyao/xiaoyaodao")>=9)		return 0;
		if(who->query("xiaoyao/禁用绝招")==1)		return 0;
		say("你这个逆徒，让你不得擅自泄露本门绝招，你偏偏总是忍不住要出去卖弄一番！", who);
		say("还把我留你防身的宝刀弄损，真是暴轼天物！", who);
		say("要不是这次看在你拿回我逍遥派镇山至宝［帛卷］的份上，我才不会再饶过你！", who);
		say("给我滚出去，去你师兄那里去找把破刀用着。下次要是再违禁令，看我是怎样的收拾你！", who);
		SendMenu(who);
		who->add("hp",-200);
		who->add("xiaoyao/挨骂", 1);
		who->add("xiaoyao/xiaoyaodao", 1);
		destruct(ob);
		return 1;
	}
	return 0;
}

static char * ask_me(CNpc *who,CChar *me)
{
	char msg[255];
	if(DIFFERSTR(me->querystr("family/family_name"), "逍遥派"))
	{
		message_vision("你非我逍遥门人，问这些做什么？",me,who);
		return 0;
	}
	if (me->query("xiaoyao/xiaoyaozi") !=1)
	{
		me->set("xiaoyao/xiaoyaozi",1);
		me->set("xiaoyao/xiaoyaodao", 9);
		CContainer * ob = load_item("blade_2");
	    ob->move(me);
		message_vision(snprintf(msg, 255, "$n说道：徒儿，第一次闯荡江湖，你万事都要小心，\n师父现在就把自己使用多年的刀送给你，多多珍惜！\n$n给$N数量1的%s。",  ob->name()), me, who);
		return 0;   
	}
	else 
		return "出门在外，事事都要自己小心。";
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(me->query_temp("xy/逍遥令") )
	{
		if(!me->query("xy/renwu1"))
		{
			if(EQUALSTR(me->querystr("family/family_name"), "逍遥派"))//逍遥弟子
			{
				switch(me->query_temp("xy/lingting"))
				{
				case 0:
					say("你见到逍遥女便跪了下去：“不俏弟子拜见师傅。”",me);
					say("逍遥女素手一摆，微笑道：“你我虽份属师徒，却也不必拘礼，否则就有违逍遥之意了。”",me);
					say("说话间，一股柔和的气劲已将你缓缓托起。",me);
					me->add_temp("xy/lingting",1);
					break;
				case 1:
					say("逍遥女续道：“你可知为师此次急召尔等回来，所为何事？”",me);
					say("你面向逍遥女，两手抱拳：“弟子洗耳恭聆。”",me);
					me->add_temp("xy/lingting",1);
					break;
				case 2:
					say("逍遥女肃颜道：“月前，我前往西夏王宫拜访秋痕师姐途中，意外遇到多年未见的李沧海师姐，方得知兄长逍遥子并未死去。”",me);
					say("逍遥女肃颜道：“只是沧海小师妹话未说完，便匆匆走了，我听她似乎说了「琅擐」二字。”",me);
					say("你惊讶地问道：“「琅擐」为何意？”",me);
					me->add_temp("xy/lingting",1);
					break;
				case 3:
					say("逍遥女叹了口气：“我依稀记得年少时兄长曾提起过「琅擐福地」，究竟在何处，就不得而知了。为师需镇守逍遥，以防丁老仙趁机作恶，寻找福地的事，就拜托你们了。”",me);
					say("逍遥女续道：“尔等须当尽力而又不可强求，一切随缘，且自逍遥，你这就去吧。”",me);
					me->add_temp("xy/lingting",1);
					break;
				case 4:
					say("逍遥女又道：“你大师兄博闻强记，诸事不明，可与相询，定能得益，为师言尽于此，你好自为之吧。”",me);
					say("你伏身叩跪：“弟子谨尊教诲””",me);
					me->delete_temp("xy/lingting");
					me->delete_temp("xy/逍遥令");
					me->set("xy/renwu1",1);//启动逍遥任务第一部分：寻找福地。可以去苏悬河处打听福地的消息
					break;
				}
			}
			else//非逍遥弟子
			{
				if(! strlen(ask))
				{
					say("你见到逍遥女，双手做辑，恭敬地询问道：“不知前辈广发逍遥令，所为何事？”",me);
					say(snprintf(msg, 255, "逍遥女素手一摆，微笑道：“这位%s不必多礼，我请各位前来，只因为敝派掌门兄长失踪数十年，杳无音信，近期得到消息言其并未死去。”",query_respect(me)),me);
					say("逍遥女微笑道：“因老身需提防本派大对头丁老仙骚扰本门，抽不开身，故请诸位同道相助，以寻访掌门兄长下落！”",me);
					say(snprintf(msg, 255, "逍遥女用期待的眼神看着你：“不知这位%s可否愿意相助？”",query_respect(me)),me);
					AddMenuItem("愿意", "yes", me);
					AddMenuItem("在下俗务繁忙，恐无暇相助", "no", me);
				}
				else if(!strcmp(ask, "yes") )
				{
					say(snprintf(msg, 255, "逍遥女叹了口气：“其实此事还茫茫无头绪，仅一丝线索显示此事与本派福地有关，然福地究竟在何处，就不得而知了。我兄长的大徒弟博闻强记，诸事不明，可与相询，定能得益。寻找福地的事，就拜托%s了！”",query_respect(me)),me);
					me->set("xy/renwu1",1);//启动逍遥任务第一部分：寻找福地。可以去苏悬河处打听福地的消息
					me->delete_temp("xy/逍遥令");
				}
				else if(!strcmp(ask, "no") )
				{
					say(snprintf(msg, 255,"逍遥女一脸失望的看了一眼，道：“如此，就不敢有劳%s了。”",query_respect(me)),me);
					me->delete_temp("xy/逍遥令");
				}
			}
		}
	}
	else
	{
		set_inquiry("出山",ask_me);
		set_inquiry("禁令","本门至上绝招未经许可，严禁使用。");
		if(me->query("xy/renwu1") && !me->query("xy/renwu2"))
			set_inquiry("请求任务失败",ask_lin);
		return CNpc::do_talk(me,ask);
	}
	SendMenu(me);
	return 1;
}

static char * ask_lin(CNpc *who,CChar *me)
{
	me->del("xy");
	me->delete_temp("xy");

	CContainer * yinyue_si;
	yinyue_si=me->present("yingyue si");
	if(yinyue_si)
		destruct(yinyue_si);

	return "既然如此，那我也不勉强你了。";
}
ZUSHI_END;




