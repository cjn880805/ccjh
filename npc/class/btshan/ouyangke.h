//ouyangke.h
//Lanwood 2000-01-05

NPC_BEGIN(CNbtshan_ouyangke);

virtual void create()
{
	set_name("白少庄主", "ouyang ke");
	set("long", "他一身飘逸的白色长衫，手摇折扇，风流儒雅。");
	set("title", "白驼山少庄主");
	set("nickname", "多情误");
	set("gender", "男性");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("icon", young_man3);
        set("per", 30);
	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);

	set("hp", 6500);
	set("max_hp", 6500);
	
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 10);

	set("combat_exp", 400000);
	set("score", 40000);
        set_inquiry("蓉儿","我对她是真心的，但是她总是觉得我不可信任，这其实也怪不得她。");
        set_inquiry("白老庄主","我父亲对我期望很大，但是我现在也许会辜负他了，我不敢回去见他。");
	set_skill("unarmed", 100);
	set_skill("hand", 100);
	set_skill("dodge", 120);
	set_skill("parry", 100);
	set_skill("force", 100);
	set_skill("staff", 100);
	set_skill("hamagong",100);
	set_skill("xunshou_shu",100);
	set_skill("chanchu_bufa", 100);
	set_skill("shexing_diaoshou", 110);
	set_skill("lingshe_zhangfa", 110);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu_bufa");
	map_skill("unarmed", "shexing_diaoshou");
	map_skill("hand", "shexing_diaoshou");
	map_skill("parry", "lingshe_zhangfa");
	map_skill("staff", "lingshe_zhangfa");
	carry_object("zheshan", 1);
	carry_object("yaoqin", 1);

	//set("startroom","/d/city/beidajie1");

    create_family("白驼山派",2,"弟子");

	set("chat_chance", 10);
	
	carry_object("baipao")->wear();
	add_money(1000);
	set("no_huan",1);
};

virtual char * chat_msg()
{
	switch(random(4))
	{
	case 0:
		return "白少庄主唱道: 今宵酒醒何处？杨柳岸，晓风残月。￣￣";
	case 1:
		return "白少庄主静静地看着街边的女孩子们。";
	case 2:
		return "白少庄主把纸扇一展，转过身去，轻轻叹道：空将酒晕一衫清，人间何处问多情￣";
	case 3:
		random_move();
		return 0;
	}

	return 0;
}

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
	char msg[255];

	if(! who) return;

	if ( EQUALSTR(who->querystr("gender"), "女性"))
	{
	   switch(random(3))
	   {
		case 0:
			g_Channel.do_emote(me, who, "rose", 0);
			break;
	  	case 1:
			g_Channel.do_emote(me, who, "kiss", 0);
			break;
	   	case 2:
			g_Channel.do_emote(me, who, "love", 0);
			break;
	   }
     
	}
	else
       message_vision(snprintf(msg, 255, "$N对着$n叹了一口气说：这位%s, 你要是能送我一个女孩子就好了。", query_respect(who)), me, who);

	return;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];
	
	if ( EQUALSTR(me->querystr("family/family_name"), "白驼山派"))
	{
	     if(me->query("combat_exp")<10000)
		 {
	          say("你的经验太低，我还不能收你。继续努力吧。", me);
			  SendMenu(me);
		 }
	     else
         {
			say("你跟着我要好好学。");             
			command(snprintf(msg, 80, "recruit %ld", me->object_id()));
         }

		 return;
	}

	if (EQUALSTR(me->querystr("gender"), "女性"))
			message_vision(snprintf(msg, 255, "白少庄主动情地说道：这位%s真乃我的红颜知己，我现在还不能收你，只能送你上白驼山。", query_respect(me)), this);
	else
		message_vision(snprintf(msg, 255, "白少庄主笑笑说：这位%s，我现在还不能收你，只能送你上白驼山。", query_respect(me)), this);
     
	tell_object(me, "只见白少庄主把纸扇往你眼前一晃，\n你觉得眼前一闪，身体轻飘飘地飞了出去￣￣");
    me->move(load_room("白驼山练功场"));
}

virtual int accept_fight(CChar * me)
{
	char msg[255];

	if (EQUALSTR(me->querystr("gender"), "女性"))
	{
		say(snprintf(msg, 255, "白少庄主摆摆手说道：这位%s，我怎能欺负女孩子呢！", query_respect(me)), me);
		SendMenu(me);
		return 0;
    }
          
	if (EQUALSTR(me->querystr("family/family_name"), "白驼山派"))
	{
		if(me->query_combat_exp() < 100000 )
		{
			say("白少庄主笑道：你的经验太低了,再练几年吧。！", me);
			SendMenu(me);
			return 0;
		}
	}
	
	message_vision(snprintf(msg, 255, "白少庄主一拱手说道：这位%s，在下领教了。", query_respect(me)), me);
	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{

	if( EQUALSTR(environment()->querystr("base_name"), "扬州丽春院"))
		return notify_fail("白少庄主正忙着泡妞，没空理你。");

	if( ob->query_temp("白少庄主"))
	{
		say("这个已经没意思了。", who);
		SendMenu(who);
		return 0;
	}

	if(query("sum") > 10)
	{
		say("我今天太累了，改天再说吧。", who);
		SendMenu(who);
		return 0;
	}

	if ( DIFFERSTR(ob->querystr("gender"), "女性"))
	{	
		return notify_fail("白少庄主不需要这件东西。");
	}
	
	if ( ob->query("age") <18 )
	{	
		say("白少庄主摇摇头道：我并不是什么好人，但是她还未成年，我还是下不了手。", who); 
		SendMenu(who);
		return 0;
	}
    
	if ( ob->query("age") >40 )
	{	 
		say("白少庄主微微地苦笑道：我不忍心让这位阿姨晚节不保！", who);
		SendMenu(who);
		return 0;
	}

	int per = ob->query("per");
	if( per < 18)
	{
		say("我虽然好色，但还是会选择女孩的！", who);
		SendMenu(who);
		return 0;
	}
	
	ob->set_temp("白少庄主", 1);

	add("sum", 1);
	if(query("sum") > 10)
	{
		remove_call_out(do_reset);
		call_out(do_reset, 900);
	}

	CMoney::Pay_Player(who, 80 * per);
	 
    message_vision("白少庄主一把把$n揽在怀里，对$N说这点银子是你的辛苦费，咱回头见。\n说完，就携着$n往丽春院奔去...", who, ob);
    move(load_room("扬州丽春院"));
    return 1;
}

static void do_reset(CContainer * ob, LONG param1, LONG param2)
{
	ob->del("sum");
}

NPC_END;
