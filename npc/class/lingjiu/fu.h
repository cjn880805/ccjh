//fu.h
//cat 2001-4-4

NPC_BEGIN(CNlingjiu_fu);

virtual void create()
{
	set_name("符敏儿", "fu minger");
	set("long", "她是「灵鹫宫」九天九部中阳天部的首领。她精于女红有“针神”的称号。");
	set("gender", "女性");
	set("per", 28);
	set("age", 24);
	
	set("title", "阳天部首领");
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
	set_skill("finger",100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);
	set_skill("sword",100);

	set_skill("zhemei_shou",80);
	set_skill("liuyang_zhang",80);
	set_skill("tianyu_qijian",80);
	set_skill("yueying_wubu",80);
	set_skill("bahuang_gong", 80);
	set_skill("rouqing_zhi",80);

	map_skill("force", "bahuang_gong");
	map_skill("strike","liuyang_zhang");
	map_skill("dodge", "yueying_wubu");
	map_skill("unarmed", "liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");
	map_skill("sword", "tianyu_qijian");
	map_skill("finger","rouqing_zhi");

	prepare_skill("strike","liuyang_zhang");
	prepare_skill("hand","zhemei_shou");
	create_family("灵鹫宫",4,"弟子");
	set("chat_chance_combat", 50);
	
	carry_object("changjian")->wield();
	carry_object("qingyi")->wear();
    carry_object("doupeng")->wear();
	carry_object("jiudai");
	add_money(1500);

//	set_inquiry("防具",ask_armor);
//	set("have_armor", 1);
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
		if(me->query_temp("lj/dating")&&!me->query_temp("lj/hm/符敏儿") )
		{
			me->add_temp("lj/humang",1);
			me->add_temp("lj/hm/符敏儿",1);
			tell_object(me, "符敏儿惶惶茫茫的问道:主人失踪了！你看到主人了么?");
		}
		if(DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫") )
			message_vision ("符敏儿对着$N笑了笑说：“你是来拜师的吧？拜我吧。”", me);
		else
			message_vision ("符敏儿对着$N点了点头，轻轻一笑。", me);
	}
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if (DIFFERSTR(me->querystr("gender"), "女性"))
    {
 		say("符敏儿瞪着你看了老半天才冒出一句话来：“本宫只收女弟子！”", me);
		SendMenu(me);
		return;
	}

	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	me->set("class", "dancer");
	me->UpdateMe();
	return;
}
/*
static char * ask_armor(CNpc * npc , CChar * player)
{
	if(DIFFERSTR(player->querystr("family/family_name"), "灵鹫宫") )
		return "你与本宫素无来往，此话从何说起？";
	if(player->query_temp("mark/get_armor") >= 3)
		return "你不是刚拿过吗？不要那么贪心好不好？";
	if(npc->query("have_armor") <= 0)
		return "你来迟了，伤药已给了你其他同门了。";

	player->add_temp("mark/get_armor", 1);
	npc->add("have_armor", -1);

    npc->say("你想些什么护具呢？");
	npc->AddMenuItem("护腕", "$0wrist $1", player);
	npc->AddMenuItem("护腰", "$0waist $1", player);
	npc->AddMenuItem("手套", "$0hand $1", player);
	npc->AddMenuItem("指套", "$0finger $1", player);
	npc->AddMenuItem("皮靴", "$0shoe $1", player);
	npc->SendMenu(player);

	return "";
}

virtual int handle_action(char *comm, CChar *player, char * arg)
{
	if(strcmp(comm, "wrist") == 0)
		return give_wrist(player);

	if(strcmp(comm, "waist") == 0)
		return give_waist(player);

	if(strcmp(comm, "hand") == 0)
		return give_hand(player);

	if(strcmp(comm, "finger") == 0)
		return give_finger(player);

	if(strcmp(comm, "shoe") == 0)
		return give_shoe(player);

	return 0;
}

int give_wrist(CChar * player)
{
	load_item("huwan")->move(player);
	message_vision("符敏儿给了$N一个护腕。", player);
	return finish(player);
}

int give_waist(CChar * player)
{
	load_item("huyao")->move(player);
	message_vision("符敏儿给了$N一个护腰。", player);
	return finish(player);
}

int give_hand(CChar * player)
{
	load_item("shoutao")->move(player);
	message_vision("符敏儿给了$N一个手套。", player);
	return finish(player);
}

int give_finger(CChar * player)
{
	load_item("zhitao")->move(player);
	message_vision("符敏儿给了$N一个指套。", player);
	return finish(player);
}

int give_shoe(CChar * player)
{
	load_item("pixue")->move(player);
	message_vision("符敏儿给了$N一双皮靴。", player);
	return finish(player);
}

int finish(CChar * player)
{
	AddMenuItem("拿着，好好保护灵鹫宫", "", player);
	SendMenu(player);
	return 1;
}

  */

NPC_END;




