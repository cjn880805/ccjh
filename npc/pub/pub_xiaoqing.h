//pub_xiaoqing.c
// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_xiaoqing);

virtual void create()
{
	set_name("小青", "xiao qing");

	set("icon", young_woman2);
	set("title", "药剂师");
	set("gender", "女性" );
	set("age", 16);
	set("long","这是个聪明乖巧的小姑娘，打扮的很朴素，一袭青衣，却也显得落落有致。小青对人非常热情。你要是跟她打过交道就会理解这一点！");
	set("attitude", "friendly");
	set("shen_type", -1);
	
	set("str", 20);
	set("int", 29);
	set("con", 23);
	set("dex", 22);
	
	set("max_hp", 420);
	set("mp", 120);
	set("max_mp", 120);
	
	set("combat_exp", 60000);
	set("score", 1000);
	
	set_skill("force", 26);
	set_skill("dodge", 23);
	set_skill("unarmed", 24);
	set_skill("parry", 22);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 17);
	set_temp("apply/armor", 10);
	
	set_temp("dan",0l);
	set_temp("times",5);
	create_family("白驼山派", 5, "弟子");
	
	set_inquiry("海口大碗","已经摔破了。");
	set_inquiry("旺财" ,"他是我小时候的朋友！");
	set_inquiry("蛇胆膏",inquiry_gao);
	
	carry_object("qingpao")->wear();
	set("no_huan",1);
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];

	if(random(2)==1)
		return snprintf(msg,255,"这位%s请进，见到你真高兴。",query_respect(ob) );
	
	
	return snprintf(msg,255,"这位%s快请进吧。 ",query_respect(ob) );	
}

static char * inquiry_gao(CNpc *me,CChar *who)
{
	char msg[255];

	if(me->query_temp("dan")==3) 
		return "你没见我已经作好了嘛！";

	if(me->query_temp("times")==0) 
		return "师傅现在已经不叫我做『蛇胆膏』了！";

	snprintf(msg,255,"这位%s不瞒您说。师傅让我作『蛇胆膏』，可我", query_respect(who));

	switch (me->query_temp("dan"))
	{
	case 0:
		strcat(msg, "差一只青蛇胆，一只金蛇胆。"  );
		break;
	case 1: 
		strcat(msg, "还差一只金蛇胆。");
		break;
	case 2: 
		strcat(msg,  "还差一只青蛇胆。");
		break;
	}
	me->say(msg, who);
	me->say("不知哪位好心人能帮帮我呢？", who);
	me->SendMenu(who);
	return "";
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("base_name"), "qingdan")
		&&  DIFFERSTR(ob->querystr("base_name"), "jindan" ))
		return notify_fail("小青不需要这件东西。");

	if ( query_temp("times")==0 )
		return notify_fail("小青现在已经不做『蛇胆膏』了。");

	if ( EQUALSTR(ob->querystr("base_name"), "jindan" ))
	{
		if (query_temp("dan")==2)
		{
			say("我还差青蛇胆，不缺金蛇胆。", who);
			SendMenu(who);
			return 0;
		}

		add_temp("dan", 2);

		if (query_temp("dan")==2)
		{ 
			say("小青看到金蛇胆，高兴得跳了起来搂着你的脖子说：还差青蛇胆就大功告成了！", who);
			SendMenu(who);
			return 1;
		}
	}

	if (  EQUALSTR(ob->querystr("base_name"), "qingdan" ))
	{
		if (query_temp("dan")==1)
		{
			say("小青一看是，满脸遗憾地对你说：我还差金蛇胆，不缺青蛇胆。",who);
			SendMenu(who);
			return 0;
		}

		add_temp("dan",1);
		if (query_temp("dan")==1)
		{ 
			say("小青看到青蛇胆，高兴得跳了起来。搂着你的脖子说：还差就金蛇胆大功告成了！",who);
			SendMenu(who);
			return 1;
		}
	}

	message_vision("小青轻轻的吻了$N一下。\n小青手脚麻利地把两只蛇胆投入药罐中，又加入一些不知是什么的药粉，然后把稀里哗啦一摇，嘿！『蛇胆膏』做成了。\n小青很神秘地凑近$N悄悄说了些什么。\n小青深情地望了$N一眼，脸红了。", who);
	say("我偷偷拿了一点『蛇胆膏』送给你，师傅不会发现的。", who);
	SendMenu(who);

	//蛇胆膏
	load_item("shedangao")->move(who);
	set_temp("dan",0l);
	add_temp("times",-1);
	return 1;
}

NPC_END;