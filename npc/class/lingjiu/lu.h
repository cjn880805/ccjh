//lu.h
//cat 2001-4-4

NPC_BEGIN(CNlingjiu_lu);

virtual void create()
{
	set_name("陆姐", "lu jie");
	set("long", "她是「灵鹫宫」九天九部中成天部的首领。她跟随童姥多年, 出生入死,饱经风霜。");
	set("gender", "女性");
	set("per", 23);
	set("age", 30);
	
	set("title", "成天部首领");
	set("attitude", "peaceful");
	set("icon",young_woman1);

	set("class", "officer");
	set("str", 20);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("hp", 2000);
	set("max_hp", 4000);
	
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 100);

	set("combat_exp", 800000);
	set("score", 10000);
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);
	set_skill("sword",100);

	set_skill("zhemei_shou",80);
	set_skill("liuyang_zhang",80);
	set_skill("tianyu_qijian",80);
	set_skill("yueying_wubu",80);
	set_skill("bahuang_gong", 80);

	map_skill("force", "bahuang_gong");
	map_skill("strike","liuyang_zhang");
	map_skill("dodge", "yueying_wubu");
	map_skill("unarmed", "liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");
	map_skill("sword", "tianyu_qijian");

	prepare_skill("strike","liuyang_zhang");
	prepare_skill("hand","zhemei_shou");
	create_family("灵鹫宫",4,"弟子");
	set("chat_chance_combat", 50);
	
	carry_object("changjian")->wield();
	carry_object("qingyi")->wear();
    carry_object("doupeng")->wear();
	carry_object("jiudai");
	add_money(1500);

	set_inquiry("食物",ask_food);
	set_temp("have_food", 30);
};

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

virtual void init(CChar * me)
{
	CNpc::init(me);
	
	if(userp(me) && !is_fighting())
	{
		if(me->query_temp("lj/dating")&&!me->query_temp("lj/hm/陆姐") )
		{
			me->add_temp("lj/humang",1);
			me->add_temp("lj/hm/陆姐",1);
			tell_object(me, "陆姐惶惶茫茫的问道:主人失踪了！你看到主人了么?");
		}
		if(DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫") )
			message_vision ("陆姐对着$N笑了笑说：“你是来拜师的吧？拜我吧。”", me);
		else
			message_vision ("陆姐对着$N点了点头，轻轻一笑。", me);
	}
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if (DIFFERSTR(me->querystr("gender"), "女性"))
    {
 		say("陆姐瞪着你看了老半天才冒出一句话来：“本宫只收女弟子！”", me);
		SendMenu(me);
		return;
	}

	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	me->set("class", "dancer");
	me->UpdateMe();
	return;
}

static char * ask_food(CNpc * npc , CChar * player)
{
	if(DIFFERSTR(player->querystr("family/family_name"), "灵鹫宫") )
		return "你与本宫素无来往，此话从何说起？";
	if(player->query_temp("mark/get_food") >= 3)
		return "你不是刚拿过吗？不要那么贪心好不好？";
	if(npc->query("have_food") < 0)
		return "你来迟了，伤药已给了你其他同门了。";

	player->add_temp("mark/get_food", 1);
	npc->add_temp("have_food", -1);

    npc->say("你想要些什么？");
	npc->AddMenuItem("冰雪翡翠糕", "$0gao $1", player);
	npc->AddMenuItem("酸梅汤", "$0suanmei $1", player);
	npc->SendMenu(player);

	return "";
}

virtual int handle_action(char *comm, CChar *player, char * arg)
{
	if(strcmp(comm, "gao") == 0)
		return give_gao(player);

	if(strcmp(comm, "suanmei") == 0)
		return give_suanmei(player);

	return 0;
}

int give_suanmei(CChar * player)
{
	load_item("suanmei")->move(player);
	message_vision("陆姐给了$N一碗酸梅汤。", player);
	return finish(player);
}

int give_gao(CChar * player)
{
	load_item("gao")->move(player);
	message_vision("陆姐给了$N一块冰雪翡翠糕。", player);
	return finish(player);
}

int finish(CChar * player)
{
	AddMenuItem("请慢用。", "", player);
	SendMenu(player);
	return 1;
}
NPC_END;
