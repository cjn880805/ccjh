//tonglao.h
//Lanwood 2000-01-08

ZUSHI_BEGIN(CNlingjiu_tonglao);

virtual void create()
{
	set_name("天山铁姥",  "tie lao");
	set("long", "她就是「灵鹫宫」的开山祖师.乍一看似乎是个十七八岁的女子,可神情却是老气横秋.");
	set("title", "灵鹫宫主人");
	set("gender", "女性");
	set("per", 20);
	set("age", 96);
	set("nickname",  "唯我独尊");
	
	set("attitude", "peaceful");
	set("icon",young_woman1);

	set("str", 25);
	set("int", 35);
	set("con", 40);
	set("dex", 40);

	set("hp", 20000);
	set("max_hp", 20000);
	
	set("mp", 12000);
	set("max_mp", 12000);
	set("mp_factor", 200);

	set("combat_exp", 55000000);
	set("score", 200000);
	set_skill("force", 280);
	set_skill("unarmed", 280);
	set_skill("dodge", 280);
	set_skill("parry", 280);
//	set_skill("finger",280);
	set_skill("hand",400);
	set_skill("strike", 280);
    set_skill("sword",280);

	set_skill("zhemei_shou",280);
	set_skill("liuyang_zhang",280);
    set_skill("tianyu_qijian",300);
	set_skill("yueying_wubu",280);
	set_skill("bahuang_gong", 300);
	set_skill("rouqing_zhi",200);

	map_skill("force", "bahuang_gong");
	map_skill("strike","liuyang_zhang");
	map_skill("dodge", "yueying_wubu");
	map_skill("unarmed", "liuyang_zhang");
    map_skill("strike","liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");
    map_skill("sword","tianyu_qijian");
//	map_skill("finger","rouqing_zhi");

	prepare_skill("strike","liuyang_zhang");
	prepare_skill("hand","zhemei_shou");
	create_family("灵鹫宫",1,"主人");
	set("chat_chance_combat", 50);
	
 	carry_object("changjian")->wield();
 	carry_object("qingyi")->wear();
    carry_object("doupeng")->wear();
    carry_object("jiudai");

	set("apply/armor", 380);
    set("apply/damage", 200);
	set("no_chan",1);
	set("no_huan",1);

	set_inquiry("请求任务失败",ask_lost);
};

static char * ask_lost(CNpc * npc , CChar * player)
{
	char msg[255];
	if(player->querymap("lj") && !player->query("lj/renwu_lost"))
	{
		if(player->query("lj/renwu7"))
		{
			player->del("lj");
			player->delete_temp("lj");
			player->set("hp",100);
			player->set("eff_hp",100);
			player->set("mp",0l);
			player->add("combat_exp",-12000);
			player->UpdateMe();
			return snprintf(msg,255,"%s也比较辛苦了，姥姥我也就不指望你了吧！",player->name());
		}
		else if(player->query("lj/renwu6")||player->query("lj/renwu5"))
		{
			player->del("lj");
			player->delete_temp("lj");
			player->set("hp",100);
			player->set("eff_hp",100);
			player->set("mp",0l);
			player->add("combat_exp",-7000);
			player->UpdateMe();
			return snprintf(msg,255,"%s也尽力了，姥姥我也就不指望你了吧！",player->name());
		}
		else
			return snprintf(msg,255,"%s怎能半途而废呢？我可是全都依托着你了。",player->name());
	}
	else
		return "姥姥我和你没有什么关系，你请求什么任务失败呢？";
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

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];
	if (DIFFERSTR(me->querystr("gender"), "女性"))
    {
 		say("你找死啊!", me);
		SendMenu(me);
		return;
	}

	if ( me->query_skill("bahuang_gong", 1) < 230) 
    {
		say(snprintf(msg, 255, "%s是否还应该多练练八荒六合唯我独尊功？", query_respect(me)), me);
		SendMenu(me);
		return;
	}  

	if (me->query_con() < 30) 
    {
		say("本门功法极为难练,你的根骨似乎不够.", me);
		SendMenu(me);
		return;
	}

    command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	me->set("class", "officer");
	me->UpdateMe();
    
}
/*
virtual int accept_object(CChar * who, CContainer * ob)
{
	if (  DIFFERSTR(ob->querystr("name"), "十八泥偶"))
		return 0;

	destruct(ob);
	say("看起来好象他年轻时候的样子。唉，让我先静一下，你等会再来！", who);
	SendMenu(who);
	who->add_temp("tmark/rouqing", 8);
	return 1;
	
}
*/

virtual void init(CChar * me)
{
	CNpc::init(me);

	char msg[255];
	if(userp(me) && !is_fighting() && me->query("lj/renwu_ok"))
	{
		int time=int(me->query("lj/renwu_ok")*me->query("lj/renwu_level")*me->query("int")/10);
		tell_object(me, "\n$HIR天山铁姥，笑道：呵呵，姥姥当日说过天山铁姥生平不向人道谢，但你救了我性命，姥姥日后必有补报！");
		if(EQUALSTR(me->querystr("family/family_name"), "灵鹫宫") )
		{
			tell_object(me, "$HIR今日我就准你进入我灵鹫宫藏武之处参研武功！");
			me->set("lj/jiangli_time",time);
		}
		else
			tell_object(me, "$HIR今日我就抽个空，好好指点指点你的武功！");
		int exp=me->query("lj/renwu_ok")*(48000+me->query("level")*50);
		int repute=random(100000)+100000;
		if(me->query("repute")<0)
			repute=-repute;
		me->add("combat_exp",exp);
		me->add("repute",repute);
		me->set("xkd/lingjiu",1);
		me->UpdateMe();
		if(DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫") )
		{
			message_vision(snprintf(msg, 255, "\n$HIR$N完成灵柩任务“缥缈奇遇”，得到天山铁姥赏识，获得经验%d点奖励，江湖声望上升了%d点。",exp,repute),me);
			me->del("lj");
			me->delete_temp("lj");
		}
		else if(EQUALSTR(me->querystr("family/family_name"), "灵鹫宫") )
		{
			message_vision(snprintf(msg, 255, "\n$HIR$N完成灵柩任务“缥缈奇遇”，得到天山铁姥赏识，获得经验%d点奖励，江湖声望上升了%d点。",exp,repute),me);
			message_vision(snprintf(msg, 255, "$HIR并获得在灵鹫宫花园假山后的石室中参阅武功$YEL%d秒$HIR的奖励。\n",time),me);
			if(!me->query("lj/renwu10"))
			{
				me->del("lj/奇遇");	
			}
			me->del("lj/renwu_ok");
			me->del("lj/renwu_level");
		}
	}
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "灵鹫闭关室" ))
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



