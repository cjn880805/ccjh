//jian.h
//Lanwood 2000-01-06

NPC_BEGIN(CNgaibang_jian);

virtual void create()
{
	set_name("简有招", "jian youzhao");
	set("title", "丐帮九袋长老");
	set("nickname", "执法长老");
	set("gender", "男性");
	set("age", 50);
	set("long", 
		"简有招是丐邦的执法长老，代帮主执掌法刀以及青竹令等。");
		
	set("attitude", "peaceful");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);
	set("icon",begger);

	set("hp", 900);
	set("max_hp", 1800);
	
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 100);
	
	set("combat_exp", 150000);
	set("score", 20000);
	
	set_skill("force", 95); 			// 基本内功
	set_skill("huntian_qigong", 90); 	// 混天气功
	set_skill("unarmed", 100); 			// 基本拳脚
	set_skill("xianglong_zhang", 95); 	// 降龙十八掌
	set_skill("dodge", 90); 			// 基本躲闪
	set_skill("xiaoyaoyou", 90); 		// 逍遥游
	set_skill("parry", 85); 			// 基本招架
	set_skill("staff", 90); 			// 基本棍杖
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("parry", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("丐帮", 18, "九袋长老");

	set_inquiry("青竹令", ask_qingzhu_ling);
	set_inquiry("青竹杖", ask_qingzhu_zang);
	set("chat_chance_combat", 20);
	set("no_huan",1);
}

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("unarmed xianglong", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	say("老夫不收徒弟，还是请回吧。", me);	
	SendMenu(me);
}

virtual void init(CChar * me)
{
	CNpc::init(me);
        
    if(userp(me) && !is_fighting()) 
	{
		if( EQUALSTR( (me->environment())->querystr("base_name"), "扬州密林10") && DIFFERSTR(me->querystr("family/family_name"), "丐帮"))
		{
			remove_call_out(do_saying);
			call_out(do_saying, 1, me->object_id());
        }
	}
}

static void do_saying(CContainer * ob, LONG param1, LONG param2)
{
	char msg[255];
	CContainer * env = ob->environment();
	CChar * who = (CChar *)env->Present(param1);

    if (! who) return;
	if(DIFFERSTR(env->querystr("base_name"), "扬州密林10"))
		return;

	message_vision("简长老看了$N一眼，冷冷地说到：“洪帮主他老人家说我不该随意责打丐帮弟子，\n你又不属我丐帮，我打你总可以吧？”\n说完右腿一抬，$N顺势应了一招青城派的「屁股向后，平沙落雁式」－－叭叽", who);
	
	who->move(load_room("扬州密林9"));
	tell_room(who->environment(), 
		snprintf(msg, 255, "只听“嘭”地一声，紧接着%s从小门里飞了出来，屁股上有一个清楚的鞋印", who->name()), who);
}

//edit by wolfman
//2001-7-24
static char * ask_qingzhu_zang(CNpc * me, CChar * who)
{
	if (DIFFERSTR(me->querystr("family/family_name"), "丐帮"))
		return "你又不是本帮弟子，我为什么要帮你做青竹杖？";

	if (who->PresentName("qingzuzang",IS_ITEM))
		return "你已经有青竹杖了，年青人不要太贪心……";

	me->say("本帮弟子历来都是用青竹杖做武器的，如果你有竹子，我会帮你做一根青竹杖。",who);
	if (!who->PresentName("qingzugang",IS_ITEM))
	{
		return "等你有竹子的时候再来找我吧。";
	}
	me->say("好，好，即然你有了竹子，我就帮你做一根吧……",who);
	destruct(who->PresentName("qingzugang",IS_ITEM));
	load_item("qingzuzang")->move(who);
//	message_vision("$N从简长老手中接过一根玉竹杖。",who);
	me->say("简长老从你手中接过竹子，转过身去……",who);
	return "片刻，简长老递给你一根青竹杖，并叮嘱道：不要滥杀无辜。";
}

static char * ask_qingzhu_ling(CNpc * me, CChar * who)
{
	if(EQUALSTR(who->querystr("family/family_name"), "丐帮"))
	{
		if (who->PresentName("qingzhu_ling", IS_ITEM))
			return "你身上不是带着本门信物吗？！";
		load_item("qingzhu_ling")->move(who);
		return "拿好了，尽力而为吧。";
	}
	return "阁下与本帮素不相识，凭什么前来索要本帮信物？";
}

int accept_object(CChar * me, CContainer * obj)
{
	char msg[255];

	if( EQUALSTR(obj->querystr("base_name"), "po_bu")
		&& me->query_temp("have_cloth"))
	{
		me->set("party/party_name","丐帮");
		me->set("party/rank", me->querystr("newtitle"));
		me->del("newtitle");

		int level = me->query("beggarlvl");
		if(level == 0)
			me->set("beggarlvl", 1);
		else
		{
			level ++;
			me->set("beggarlvl", level);
		}
		message_vision(snprintf(msg, 255, "$N对着$n说：好，恭喜你荣升%s，今后多加努力必定前途无可限量。",  me->querystr("party/rank")), this, me);
		return 1;
	}
	else
	{
		say("你当我叫化子啊？什么垃圾都拿来塞给我，哼！");
		return 0;
	}
}

NPC_END;
