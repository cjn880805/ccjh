//yifei 易飞 
//地狱第五层BOSS

BOSS_BEGIN(CNyifei);

virtual void create()
{
	set_name("易飞", "yi fei");
	set("title", "一剑断情");
	set("gender", "男性");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "他长的高大威猛,混身充满了阳刚之气,让江湖里的侠女们一见倾倒。");
   
	set("str", 95);
	set("int", 95);
	set("con", 95);
	set("dex", 95);
	set("per",24);
	set("level",200);
	set("repute",50000000);

	set("chat_chance_combat", 20);		//设置NPC使用绝招的几率
	
	set_inquiry("伊人", "唯有断情,方明剑心。");
	set_inquiry("耶律齐", "江湖里还有谁认识他吗？");
	set_inquiry("沧澜一剑", "耗几十年的功夫终于悟透这一招。");

	set("hp", 102000);
	set("max_hp", 102000);
	set("mp", 57000);
	set("max_mp", 57000);
	set("mp_factor", 500);
	
	set("combat_exp", 180000000);
	set("score", 500000);
	
	set_skill("force", 720);
	set_skill("sword", 720);
	set_skill("dodge", 720);
	set_skill("parry", 720);
	set_skill("unarmed",720);
	set_skill("strike",720);
	set_skill("finger",720);
	set_skill("literate",720);
	set_skill("taoism",720);

	set_skill("xiantian_qigong", 720);
	set_skill("xiantian_gong", 720);
	set_skill("quanzhen_jianfa",720);  //全真剑
	set_skill("quanzhen_jian",720);  //全真剑
	set_skill("jinyan_gong", 720);   //金雁功
	set_skill("haotian_zhang", 720);    //昊天掌
	set_skill("sun_finger",720);  //一阳指

	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jianfa");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jianfa");
	map_skill("strike", "haotian_zhang");
	map_skill("finger","sun_finger");

	prepare_skill("finger","sun_finger");
	prepare_skill("strike","haotian_zhang");
	
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

	set("apply/armor", 900);
    set("apply/damage", 770);

	set("chat_chance", 5);
    carry_object("changjian")->wield();

	set("family/family_name","全真教");
	
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
	switch(random(4))
	{
	case 0:
		return "易飞满怀愧疚的叹道：“余生平只亏欠伊人”。";
	case 1:
		return "易飞眼中精光猛然一闪，沉吟道：“全真一剑化三清的精髓在于断情。”";
	case 2:
		return "易飞哈哈一笑，朗声喝道：“全真的北斗七星阵法施展开来,无人能破。”";
	case 3:
		return "易飞哈哈一笑，放声喝道：“幸好我年少时遇到了那个和尚酸性大发，否则我也不会领悟出我全真无上的绝学。”";
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * ling = PresentName("changjian", IS_ITEM);
	if(query_weapon() == ling && ling)
	{
		switch(random(3))
		{
		case 0:
			perform_action("sword ding", 1);
			break;
		case 1:
			perform_action("strike ju", 1);
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
			perform_action("strike ju", 1);
			break;
		case 2:
			perform_action("finger qiankun", 1);
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>140 )
		{
			message_vision("$HIR$N心灰意冷道：“吾已斩情练至剑心通明,依旧打不过$n,$n可以去下一层了！”", this,me);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			if(me->query("18dy/level8"))
				me->set("18dy/level9",1);
			me->move(load_room("高昌火海地狱"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
