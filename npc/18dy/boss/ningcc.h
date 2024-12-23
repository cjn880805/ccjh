//ningcc 宁CC 
//地狱第十二层BOSS

BOSS_BEGIN(CNningcc);

virtual void create()
{	
	set_name("宁CC", "ning cc");
	set("title", "百变神尼");
	set("gender", "女性");
	set("icon", old_nun);
	set("class", "bonze");
	set("age", 68);
	set("long",  "她羽衣飘飘，潇然出尘，神情看来说不出的和平宁静。");
		
	set("str", 119);
	set("int", 119);
	set("con", 119);
	set("dex", 95);
	set("per",35);
	set("level",220);
	set("repute",50000000);

	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
	
	set_inquiry("峨眉", "峨眉的要绝在于快狠准。");
	set_inquiry("情天难补", "悟了三十年,终于悟出此招,你明白了吗？");
	set_inquiry("月庭", "月庭是江湖上最神秘的帮派之一，随着风和雪儿的退隐，月庭满华不在。");

	set("hp", 162000);
	set("max_hp",162000);
	set("max_mp", 82000);
	set("mp", 82000);
	set("mp_factor", 500);
	
	set("combat_exp", 260000000);
	set("score", 500000);
	
	set_skill("persuading", 830);
	set_skill("force", 830);
	set_skill("dodge", 830);
	set_skill("finger", 830);
	set_skill("parry", 830);
	set_skill("strike", 830);
	set_skill("sword", 830);
	set_skill("literate", 830);
	set_skill("mahayana", 830);
	set_skill("buddhism", 830);
	set_skill("jinding_zhang", 830);
	set_skill("tiangang_zhi", 830);
	set_skill("huifeng_qijue", 830);
	set_skill("yanxing_dao", 830);
	set_skill("zhutian_bu", 830);
	set_skill("linji_zhuang", 830);
	set_skill("huifeng_jian", 830);

	map_skill("force","linji_zhuang");
	map_skill("finger","tiangang_zhi");
	map_skill("dodge","zhutian_bu");
	map_skill("strike","jinding_zhang");
	map_skill("sword","huifeng_qijue");
	map_skill("blade","yanxing_dao");
	map_skill("parry","huifeng_jian");
	
	prepare_skill("finger","tiangang_zhi");
	prepare_skill("strike","jinding_zhang");
	
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

	set("apply/armor", 1150);
    set("apply/damage", 1000);

	set("chat_chance", 5);
    carry_object("changjian")->wield();

	set("family/family_name","峨嵋派");
	
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
		return "宁月幽幽的吟起：“问世间，情之何物，伤断肠。”";
	case 1:
		return "宁CC轻叹道：“子陵哥哥不知道可好？” ";
	case 2:
		return "宁CC无限伤感道：“月华满庭”";
	case 3:
		return "宁月仰望着夜空，长叹道：“回风七绝差不多都快成绝响了。”";
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * item = PresentName("changjian", IS_ITEM);
	if(query_weapon() == item && item)
	{
		switch(random(5))
		{
		case 0:
			perform_action("sword mixhit", 1);
			break;
		case 1:
			perform_action("strike bashi", 1);
			break;
		case 2:
			perform_action("force recover", 0);
			break;
		case 3:
			perform_action("finger lingkong", 1);	
			break;
		case 4:
			perform_action("sword mie", 1);
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
			perform_action("finger lingkong", 1);	
			break;
		case 2:
			perform_action("strike bashi", 1);
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>163 )
		{
			message_vision("$HIR$N道：“既然$n过了贫尼这关,那就任由你到下一层去吧！”", this,me);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			if(me->query("18dy/level15"))
				me->set("18dy/level16",1);
			me->move(load_room("高昌刀兵地狱"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
