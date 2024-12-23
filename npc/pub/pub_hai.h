// pub_hai.c 海公公
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_hai);

virtual void create()
{
	set_name("海老龟", "hai gonggong");

	set("icon", tipstaff);
	set("title", "东厂千户");
	set("long",	"他是东厂大太监海老乌龟，乔装改扮成商人模样出京寻欢作乐，长得既像老头又像老太太。");
 	set("gender", "无性");
	set("rank_info/respect", "公公");
 	set("attitude", "heroism");
	set("class", "eunach");
	
	set("age", 60);
	set("shen_type", -1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 40);
	set("max_hp", 3500);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 100);
	set("combat_exp", 15000);
	set("score", 100);
	set("apply/attack",  30);
	set("apply/defense", 30);
	
	set_skill("force", 50);
	set_skill("unarmed", 50);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("pixie_jian", 50);
	map_skill("dodge", "pixie_jian");
	map_skill("parry", "pixie_jian");
	map_skill("sword", "pixie_jian");
	set("chat_chance", 15);
	
	set_inquiry("自宫", ask_for_zigong);
	set_inquiry("工资", ask_for_gongzi);

	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	add_money(4000);
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("pending/zigong"))
	{
		if(strcmp(ask, "ok") == 0)
		{
			me->delete_temp("pending/zigong");
			return do_decide(me);
		}

		AddMenuItem("好……吧。", "ok", me);
		AddMenuItem("再让我考虑考虑……吧。", "", me);
		SendMenu(me);
		return 1;
	}

	return CNpc::do_talk(me, ask);
}

static char * ask_for_zigong(CNpc *who, CChar *me)
{
 	if(  EQUALSTR(me->querystr("gender"), "无性") )
		return "你我同是阉人，何必开如此无聊的玩笑？";
	
	if(  EQUALSTR(me->querystr("gender"), "女性") )
		return "我虽已废，但一样可以给你这个小美人带来快乐，要不要试试？";

	if ( me->query_str() > 28 )
		return "这位好汉过于粗壮，自宫有碍观瞻，不妥，不妥。";
	
	me->set_temp("pending/zigong", 1);
	return "自宫？这位公子相貌堂堂，何必... 我真希望能有你的那个。自宫之后，不可后悔，你若决心已定，告诉我。";
}

int do_decide(CChar *me)
{
	message_vision("$N一咬牙，褪下中衣。（女玩家闭眼！）$n伸出长剑插到$N两腿之间，飞速一剜，……$N顿时惨叫一声昏了过去……",me, this);
	say("嗨……");
	command("hehe");
	me->set("gender","无性");
	me->set("class", "eunach");
//	me->add("combat_exp", 1000);
	me->unconcious();
	return 1;
}

static char * ask_for_gongzi(CNpc *who, CChar *me)
{
	int paytimes;
	
	if(  DIFFERSTR(me->querystr("gender"), "无性") ) return "哼，先自宫再来谈工资吧！";
	paytimes =  (me->query("mud_age")/7200);
	if (me->query("paytimes") < paytimes)
	{
		CMoney::Pay_Player(me, 1000);
		me->add("paytimes", 1);
		return "这是你本月的份额，收好吧。";
	}

	return "欺负我老糊涂？你本月工资已经领取过了！";
}

NPC_END;