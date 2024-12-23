//shi.h
//cat 2001-4-4

NPC_BEGIN(CNlingjiu_shi);

virtual void create()
{
	set_name("石姐", "shi jie");
	set("long", "她是「灵鹫宫」九天九部中朱天部的首领。她跟随童姥多年, 出生入死,饱经风霜。");
	set("gender", "女性");
	set("per", 23);
	set("age", 30);
	
	set("title", "朱天部首领");
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

	set_inquiry("生死符", "你今年的贡金交了没有？");

	carry_object("changjian")->wield();
	carry_object("qingyi")->wear();
    carry_object("doupeng")->wear();
	carry_object("jiudai");
	add_money(1500);
	set("no_huan",1);
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
		if(me->query_temp("lj/dating") &&!me->query_temp("lj/hm/石姐"))
		{
			me->add_temp("lj/humang",1);
			me->add_temp("lj/hm/石姐",1);
			tell_object(me, "石姐惶惶茫茫的问道:主人失踪了！你看到主人了么?");
		}
		if(DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫") )
			message_vision ("石姐对着$N笑了笑说：“你是来拜师的吧？拜我吧。”", me);
		else
			message_vision ("石姐对着$N点了点头，轻轻一笑。", me);
	}
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if (DIFFERSTR(me->querystr("gender"), "女性"))
    {
 		say("石姐瞪着你看了老关天才冒出一句话来：“本宫只收女弟子！”", me);
		SendMenu(me);
		return;
	}

	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	me->set("class", "dancer");
	me->UpdateMe();
	return;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if( EQUALSTR(ob->querystr("base_name"), "coin"))
	{
		if(ob->query("value") >= 50000)
		{
	        command("nod");
			say ("嗯，今年的生死符我就给你解了吧，记得下回要准时交贡金。");
			me->apply_condition("ss_poison", 0);
			destruct(ob);
			return 1;
		}
		else
			say ("这么点钱？打发叫化子啊？滚！");
	}
	return 0;
}


NPC_END;
