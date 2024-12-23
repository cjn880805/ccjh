//cheng.h
//cat 2001-4-4

NPC_BEGIN(CNlingjiu_cheng);

virtual void create()
{
	set_name("程青雪", "cheng qingxue");
	set("long", "她是「灵鹫宫」九天九部中钧天部的副首领。负责守卫「灵鹫宫」。");
	set("gender", "女性");
	set("per", 23);
	set("age", 24);
	
	set("title", "钧天部副首领");
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

	set_inquiry("武器",ask_sword);
	set("have_sword", 1);
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
		if(me->query_temp("lj/dating") && !me->query_temp("lj/hm/程青雪"))
		{
			me->add_temp("lj/humang",1);
			me->add_temp("lj/hm/程青雪",1);
			tell_object(me, "程青雪惶惶茫茫的问道:主人失踪了！你看到主人了么?");
		}
		if(DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫") )
			message_vision ("程青雪对着$N笑了笑说：“你是来拜师的吧？拜我吧。”", me);
		else
			message_vision ("程青雪对着$N点了点头，轻轻一笑。", me);
	}
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if (DIFFERSTR(me->querystr("gender"), "女性"))
    {
 		say("程青雪瞪着你看了老关天才冒出一句话来：“本宫只收女弟子！”", me);
		SendMenu(me);
		return;
	}

	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	me->set("class", "dancer");
	me->UpdateMe();
	return;
}

static char * ask_sword(CNpc * npc , CChar * player)
{
	if(DIFFERSTR(player->querystr("family/family_name"), "灵鹫宫") )
		return "你与本宫素无来往，此话从何说起？";
	if(player->query_temp("mark/get_sword"))
		return "你不是刚拿过吗？不要那么贪心好不好？";
	if(npc->query("have_sword") <= 0)
		return "你来迟了，伤药已给了你其他同门了。";

	load_item("changjian")->move(player);

	player->set_temp("mark/get_sword",1);
	npc->add("have_sword", -1);

	message_vision("程青雪给了$N一把长剑。", player);
	return "";
}

NPC_END;
