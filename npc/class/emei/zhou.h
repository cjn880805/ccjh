//zhou.h
//Lanwood 2000-01-05

NPC_BEGIN(CNemei_zhou);

virtual void create()
{
	set_name("周采薇", "zhou caiwei");
	set("long", "一张脸秀丽绝俗。身着一身淡黄衣裳。略显清减的巧笑中带了些许无奈。");
	set("icon", young_woman2);
	
	set("gender", "女性");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");
	
	set_inquiry("剃度", "找我剃度？不对吧。");
	set_inquiry("出家", "要出家找我的师姐们去。");
	set_inquiry("还俗", "无聊。还俗也找我！");
    set_inquiry("灭尽师太", "师父难得收徒。你先巴结我吧。");
	set_inquiry("狗", "你怎么知道我喜欢养狗？");
	

	set("foolid",14);	

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	
	set("max_hp", 3500);
	set("mp", 3500);
	set("max_mp", 3500);
	set("mp_factor", 1000);
	
	set("combat_exp", 1500000);
	set("score", 1000);
	set_skill("persuading", 80);
	set_skill("force", 100);
	set_skill("throwing", 100);
	set_skill("dodge", 100);
	set_skill("finger", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
	set_skill("strike", 100);
	set_skill("sword", 100);
	set_skill("claw", 400);
	set_skill("literate", 100);
	set_skill("mahayana", 100);
	set_skill("jinding_zhang", 100);
	set_skill("jiuyin_zhua", 200);
	set_skill("tiangang_zhi", 100);
	set_skill("huifeng_qijue", 351);
	set_skill("zhutian_bu", 100);
	set_skill("linji_zhuang", 100);
	map_skill("force","linji_zhuang");
	map_skill("claw","jiuyin_zhua");
	map_skill("dodge","zhutian_bu");
	map_skill("strike","jinding_zhang");

	prepare_skill("claw", "jiuyin_zhua");
	map_skill("sword","huifeng_qijue");
	create_family("峨嵋派", 4, "掌门弟子");
	
	carry_object("changjian")->wield();
	carry_object("ycloth")->wear();
	set("no_huan",1);
};

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];
	
    if (me->query("repute")<100)
    {
       g_Channel.do_emote(this, 0, "heng", 0);
       say(snprintf(msg, 255, "%s！你是什么东西？偷睹我面容，打扰我清修！", me->name()));
       g_Channel.do_emote(this, me, "!!!", 0);
       kill_ob(me);
	   return;
    }
   
   // if ( me->query_temp("marks/宋夫人") )
    {
		if ( me->query("betrayer") > 1)
		{
			 say(g_Channel.do_emote(this, me, "heng", 1), me);
			 say("象你这样不守门规，三心二意。我怎能再收你为徒。", me);
			 SendMenu(me);
			 return;
		}

		if (me->query("per") < 22 )
		{
			say(g_Channel.do_emote(this, 0, "giggle", 1), me);
			say(snprintf(msg, 255, "这位%s容貌太也...，哎！还是请回吧！", query_respect(me)), me);
			SendMenu(me);
			return;
		}

		if (me->query_dex() < 26  || me->query_int() < 28 )
		{
		   say(snprintf(msg, 255, "这位%s恐怕资质差了一点。", query_respect(me)), me);
		   say("不过尚大有潜力，还是先回去磨练磨练。", me);
		   SendMenu(me);
		   return ;
		}

		if (me->query_skill("linji_zhuang",1)<200)
		{
		   say(snprintf(msg, 255, "这位%s对我娥眉心法似乎领悟的不够。", query_respect(me)), me);
		   say("不过尚大有潜力，还是先回去磨练磨练。", me);
		   SendMenu(me);
		}
    
		say("看你这么可怜，勉为其难收下你吧。");
		command(snprintf(msg, 255, "recruit %ld", me->object_id()));
		me->delete_temp("marks/宋夫人");
		return;
	} 

    say("你没事就可以走了。", me);
    SendMenu(me);
    return;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "doggie") || DIFFERSTR(ob->querystr("name"), "旺财" ))
	{	
		message_vision("$N冷冷的道：这是什么东西？", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("guyuepai");

	ob->set_name( "泉月牌", "quanyue pai");

	message_vision("$N点点头，偷偷给$n一块东西。", this, who);
	ob->move(who);

	return 1;
}


NPC_END;




