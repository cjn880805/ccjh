//benxiong 笨熊 
//地狱第七层BOSS

BOSS_BEGIN(CNbenxiong);

virtual void create()
{
	set_name("笨熊", "ben xiong");
	set("title", "刺目熊");
	set("gender", "男性");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "他不修边幅,憨头憨脑的样子,但整个江湖都知道他聪明绝顶。");

	set("per",28);
	set("str", 105);
	set("int", 105);
	set("con", 105);
	set("dex", 95);
	set("level",210);
	set("repute",50000000);

	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
	
	set_inquiry("机器人", "没货了,停止发售了。");
	set_inquiry("十八地狱", "退休了,我就成了这里的守护者");
	set_inquiry("红花会", "红花遍地的日子已经过去了。");

	set("hp", 122000);
	set("max_hp", 122000);
	set("mp", 67000);
	set("max_mp", 67000);
	set("mp_factor", 500);
	
	set("combat_exp", 200000000);
	set("score", 500000);
	
	set_skill("cuff", 760);
	set_skill("force", 760);
	set_skill("dodge", 760);
	set_skill("parry", 760);
	set_skill("blade", 760);
	set_skill("strike",760);
	set_skill("unarmed", 760);
	set_skill("zixia_shengong", 760);
	set_skill("poyu_quan", 760);
	set_skill("fanliangyi_dao", 760);
	set_skill("hunyuan_zhang", 760);
	set_skill("lonely_sword", 760);
	set_skill("huashan_shenfa",760);
	set_skill("literate", 760);
	set_skill("zhengqijue", 760);

	map_skill("cuff", "poyu_quan");
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "huashan_shenfa");
	map_skill("parry", "lonely_sword");
	map_skill("blade", "fanliangyi_dao");
	map_skill("strike", "hunyuan_zhang");
	
	prepare_skill("strike","hunyuan_zhang");
	prepare_skill("cuff","poyu_quan");
	
	set("no_kill",1);
	set("no_缠字决",1);
	set_temp("apply/no_连字诀",1);
	set_temp("apply/no_千环套狗",1);
	set_temp("apply/no_相思无用",1);
	set_temp("apply/no_势合形离",1);
	set_temp("apply/no_点字决",1);
	set_temp("apply/no_天外飞龙",1);
	set_temp("apply/no_拼命",1);
	set_temp("apply/no_祭血神刀",1);
	set_temp("apply/no_封字决",1);
	
	set("bigboss",1);
	set_weight(50000000);

	set("apply/armor", 1000);
    set("apply/damage", 870);

	set("chat_chance", 5);

    carry_object("gangdao")->wield();

	set("family/family_name","华山派");
	call_out(do_full, 7200);
	
}

static void do_full(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(!me->query_temp("fight/is_fighting"))
	{
		message_vision("\n$HIR$N缓缓坐下，运功调息。", me);
		me->set("mp",me->query("max_mp"));
		me->set("hp",me->query("max_hp"));
	}
	me->call_out(do_full, 7200);
}

virtual char * chat_msg()				
{
	switch(random(3))
	{
	case 0:
		return "笨熊面色忧郁，惆怅不已，叹道：“阎罗殿一战,双方精英死伤惨重。”";
	case 1:
		return "笨熊说道：“红花会有五剑。” ";
	case 2:
		return "笨熊似乎想起了什么，怅然说道：“天下风云出我辈,一入江湖岁月催。”";
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * ling = PresentName("gangdao", IS_ITEM);
	if(query_weapon() == ling && ling)
	{
		switch(random(3))
		{
		case 0:
			perform_action("blade sanshen", 1);
			break;
		case 1:
			perform_action("cuff leidong", 1);
			break;
		case 2:
			perform_action("force recover", 0);
			break;
		}
	}
	else
	{
		switch(random(3))
		{
		case 0:
			perform_action("force recover", 0);
			break;
		case 1:
			perform_action("cuff leidong", 1);
			break;
		case 2:
			perform_action("strike wuji", 1);
			break;
		}
	}
	return 0;
}

void die()
{
	CContainer * obj = environment();
	DTItemList * list = obj->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	CChar * me;
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		me = (CChar *)obj;  
		if(!userp(me))	continue;
		//最后一个打倒的人将获得进入下一层的资格
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>150 )
		{
			message_vision("$HIR$N道：“$n你竟然杀了我？红花会的兄弟姐妹不会放过你的！”", this,me);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			if(me->query("18dy/level10"))
				me->set("18dy/level11",1);
			me->move(load_room("高昌铁床地狱"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
