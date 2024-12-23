//pub_shizhe3.c

// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_shizhe3);

virtual void create()
{
	set_name("侍者",  "shi zhe");

	set("icon", waiter);
	set("title", "侠客岛打杂弟子");
	set("gender", "男性" );
	set("age", 30);
	set("long","这是个身着黄衣的三十几岁汉子，垂手站立，面无表情。");
	set("attitude", "friendly");
	set("shen_type", 1);
	
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_hp", 990);
	set("mp", 300);
	set("max_mp", 300);
	
	set("combat_exp", 10000);
	set("score", 10000);
	
	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 40);
	set_temp("apply/armor", 40);
	
	create_family("侠客岛", 2, "弟子");
	
	set_inquiry("here","这里就是侠客行的中心了，小人在这服侍了这么久，对其中的秘密也不大清楚。");
	set_inquiry("cha","请你稍待，岛主严令小人现在不得离开此地！");
	set_inquiry("yezi","请你稍待，岛主严令小人现在不得离开此地！");
	
	carry_object("cloth")->wear();
//	carry_object("key1")->wear();
	set("no_huan",1);
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	return snprintf(msg,255,"这位%s想必你也是来参悟武林秘密的吧。这里就是侠客行的正中心，你可随意来去观看。但一切要小心在意，千万不可莽撞行事。本室可供应饮食，不过还是尽早离去为好。",query_respect(ob) );
	
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	command("smile");
	
	if( EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 5000  )
	{
		say(snprintf(msg,255," %s如此古道热肠，兼又身怀绝艺，本来岛主不让我说的，但我实在不忍心见死不救。你从西北门进去，把墙壁上的那把木刀取下，拿在手上，对你有好处。但你千万别告诉别人，否则你我都有杀身之祸，切记切记！！！" ,query_respect(who) ), who);
		SendMenu(who);
	}
	destruct(ob);
	return 1;
	
}

virtual void die()
{
	say("你敢杀我，老子到阴间也不会放过你。");
		
	//message_vision("由于侍者死了摔倒在一旁，这时你才发现刚才他站的地方有点奇怪。地板由两块石板组成，似乎是个门.上面还有一钥匙孔(kong) ", this);
	
	CNpc::die();
}

NPC_END;