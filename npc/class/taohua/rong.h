//rong.h
//Lanwood 2000-01-11

NPC_BEGIN(CNtaohua_rong);

virtual void create()
{
	set_name("蓉儿", "huang rong");
    set("title", "桃花岛主独生爱女");
    set("gender", "女性");
    set("age", 18);
    set("long", "这是桃花岛主的独生女儿。由于岛主夫人早死，岛主对这个女儿备加疼爱。她生性跳脱飞扬，喜欢四处乱跑。");
    set("icon",young_woman1);

    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 26);

    set("hp", 800);
    set("max_hp", 2400);
    
    set("mp", 1000);
    set("max_mp", 1000);
    set("mp_factor", 0l);
	
    set("combat_exp", 200000);
    
	
    set_skill("force", 60);
    set_skill("bibo_shengong", 80);
    set_skill("unarmed", 80);
    set_skill("xuanfeng_leg", 80);      // 旋风扫叶腿
    set_skill("strike", 80);            // 基本掌法
    set_skill("luoying_shenzhang", 80);
    set_skill("dodge", 150);
    set_skill("anying_fuxiang", 100);
    set_skill("parry", 85);
    set_skill("literate",150);           // 读书识字
    set_skill("sword", 80);
    set_skill("luoying_shenjian",80);
	
    map_skill("force"  , "bibo_shengong");
    map_skill("unarmed", "xuanfeng_leg");
    map_skill("strike" , "luoying_shenzhang");
    map_skill("dodge"  , "anying_fuxiang");
    map_skill("sword"  , "luoying_shenjian") ;
	
    create_family("桃花岛", 2, "弟子");

	set_inquiry("黄老怪", "爹爹呀, 不在厅里麽? ");
	set_inquiry("靖哥哥", "怎么? 你有我靖哥哥的消息吗? ");
	set_inquiry("洪叫化", "师父他老人家就喜欢吃叫化鸡! ");
	set_inquiry("叫化鸡", ask_chicken);
	set_inquiry("少林","少林寺老和我爹爹过不去。我得想办法弄点他们的东西才行……。");

	set_temp("can_cook", 5);
	
    carry_object("ruanwei")->wear();
    carry_object("shudai")->wear();
	set("no_huan",1);
};

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting())
	{
		if (DIFFERSTR(me->querystr("family/family_name"), "桃花岛") )			
		{
			remove_call_out(do_saying);
			call_out(do_saying, 2, me->object_id());
		}
	}
}

/*
int do_kiss ( string arg )
{
   if ( (string) ob -> query ("gender") == "男性" )
      command ("say 救命啊！救命啊！"+ ob->query("name") + "要非礼我！\n") ;
   else
      message_vision("\n蓉儿对$N笑道：“好姐姐不要这样，我怕痒！”\n", ob);
   return 1 ;
}
*/

static void do_saying(CContainer * ob, LONG param1, LONG param2)
{
    CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

    if (EQUALSTR(who->querystr("gender"), "男性"))
        message_vision("蓉儿面现惊奇之色，打量了$N一眼，说到：“你是什么人，竟敢乱闯我的闺房？再不滚出去，看我怎么整你！”", who);
    else
        message_vision("蓉儿看了看$N，说到：“好久没生人来过了，不知这位姐姐可有我靖哥哥的消息？", who);
}

virtual void attempt_apprentice(CChar * me)
{
   if (me->query_temp("marks/蓉儿") == 1)
   {
      load_item("ruanwei")->move(me);
      tell_object(me,"蓉儿从身上脱下一件软猥甲递给你。");
      me->set_temp("marks/蓉儿",2);

	  say("蓉儿一脸笑意：“多谢你带来靖哥哥的口信!”", me);
      say("蓉儿轻轻一笑：我不收徒的..可也不能让你白来，这软猥甲就送给你吧．", me);	  
   }
   else
		say("我年纪这么小就收徒弟，很不好玩的！", me);

   SendMenu(me);
}

static char * ask_chicken(CNpc * npc, CChar * me)
{
	if(me->query_temp("marks/鸡"))
		return "你这个人怎么这么烦？老说车轱辘话！";
	else
	{
		npc->say("蓉儿神往地说：叫化鸡可是杭州著名特产，我爹当年费了好大的劲才搞到了制作它的秘方，最重要的就是一定要用小母鸡。", me);
		me->set_temp("marks/鸡", 1);
		npc->say("你可以出去了。", me);
		npc->SendMenu(me);		
	}

	return 0;
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	if( EQUALSTR(ob->querystr("id"), "ji") || EQUALSTR(ob->querystr("name"), "小母鸡") )
	{
		if(this->query_temp("can_cook") > 0)
		{
			message_vision("$N说道：“想吃叫化鸡？反正我也很久没做了，做一只玩玩吧。”", this);
			destruct(ob);
			load_item("jiaohuaji")->move(who);
			this->add_temp("can_cook", -1);
			return 1;
		}
		else
		{
			message_vision("$N说道：“想吃叫化鸡？我太累了，过几天再说吧。”", this);
			return 0;
		}
	}
	if ( DIFFERSTR(ob->querystr("id"), "damo ling") || DIFFERSTR(ob->querystr("name"), "达摩令") )
	{	
		message_vision("$N冷冷的道：这是什么东西？", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("guyuepai");

	ob->set_name( "清月牌", "qingyue pai");

	message_vision("$N点点头，偷偷给$n一块东西。", this, who);
	ob->move(who);

	return 1;
}


NPC_END;
