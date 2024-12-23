//jujian.h
//cat 2001-4-4

NPC_BEGIN(CNlingjiu_jujian);

virtual void create()
{
	set_name("剑菊", "jian ju");
	set("long", "这是个容貌姣好的女子, 瓜子脸蛋, 眼如点漆, 清秀绝俗。你总觉得在哪见过她。");
	set("gender", "女性");
	set("per", 28);
	set("title", "尊主待女");
	set("age", 18);
	
	set("attitude", "peaceful");
	set("icon",young_woman1);

	set("per", 32);
	set("class", "officer");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("hp", 1000);
	set("max_hp", 3000);
	
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 100);

	set("combat_exp", 1200000);
	set("score", 10000);
	set_skill("force", 150);
	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("hand",150);
	set_skill("strike", 150);
	set_skill("sword",200);

	set_skill("zhemei_shou",150);
	set_skill("liuyang_zhang",150);
	set_skill("tianyu_qijian",150);
	set_skill("yueying_wubu",150);
	set_skill("bahuang_gong", 150);

	map_skill("force", "bahuang_gong");
	map_skill("strike","liuyang_zhang");
	map_skill("dodge", "yueying_wubu");
	map_skill("unarmed", "liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");
	map_skill("sword", "tianyu_qijian");

	prepare_skill("strike","liuyang_zhang");
	prepare_skill("hand","zhemei_shou");
	create_family("灵鹫宫",3,"弟子");
	set("chat_chance_combat", 50);
	
	carry_object("changjian")->wield();
	carry_object("qingyi")->wear();
    carry_object("doupeng")->wear();
	carry_object("jiudai");
	add_money(1500);
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
		if(me->query_temp("lj/dating")&&!me->query_temp("lj/hm/剑菊") )
		{
			me->add_temp("lj/humang",1);
			me->add_temp("lj/hm/剑菊",1);
			tell_object(me, "剑菊惶惶茫茫的问道:主人失踪了！你看到主人了么?");
		}
		if(DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫") )
		{
			if( !me->query_temp("warned") ) 
			{
				say("尊主有令：外人不得进入灵鹫宫，速速离开！");
				me->set_temp("warned", 1);
			}
			else
			{
				if( me->query_temp("stay") < 5 ) me->add_temp("stay",1);
				else 
				{
					say("大胆狂徒，竟敢擅闯灵鹫宫！！！");
					kill_ob(me);
				}
			}
		}
	}
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if (DIFFERSTR(me->querystr("gender"), "女性"))
    {
 		say("臭男人，你找死啊!", me);
		SendMenu(me);
		return;
	}
	
	if (me->query_skill("bahuang_gong", 1) < 50) 
    {
		say("你是否还应该多练练八荒六合唯我独尊功？", me);
		SendMenu(me);
		return;
	}

	if (me->query_con() < 20) 
    {
		say("本门功法极为难练,你的根骨似乎不够.", me);
		SendMenu(me);
		return;
	 }
	
	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
	me->set("class", "scholar");
	me->UpdateMe();
	return;
}

NPC_END;
