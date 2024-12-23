//hong.h
//Lanwood 2000-01-06

ZUSHI_BEGIN(CNgaibang_hong);

virtual void create()
{
	set_name("洪叫化", "hong qigong");
	set("nickname", "九指神丐");
	set("gender", "男性");
	set("age", 75);
	set("long", 
		"他就是丐帮第十七任帮主，号称“北丐”的洪叫化老爷子。");
	set("attitude", "peaceful");
	set("icon",begger);
	set("shen_type", 1);

	set("beggarlvl", 9);
	
	set("str", 35);
	set("int", 25);
	set("con", 33);
	set("dex", 24);

	set("chat_chance", 1);
	set("chat_chance_combat", 30);
	
	set_inquiry("青竹林", "那里空气充满宁静，那里湖面总是平静。");
	set_inquiry("丐帮", "长路漫漫独个闯，带一身肝胆与热肠，寻自我觅真情，停步处是我家乡。");
	set_inquiry("拜师", "你可以去东城门找我帮总舵的鲁有脚，拜他为师。");

	set("hp", 24500);
	set("max_hp", 24500);
	set("mp", 14000);
	set("max_mp", 14000);
	set("mp_factor", 300);
	
	set("combat_exp", 62500000);
	set("score", 400000);
	 
	set_skill("force", 270);             // 基本内功
	set_skill("huntian_qigong", 270);    // 混天气功
	set_skill("unarmed", 400);           // 基本拳脚
	set_skill("xianglong_zhang", 300);   // 降龙十八掌
	set_skill("dodge", 220);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 220);        // 逍遥游
	set_skill("parry", 230);             // 基本招架
	set_skill("staff", 300);             // 基本棍杖
	set_skill("dagou_bang", 250);        // 打狗棒法
	set_skill("begging", 250);           // 叫化绝活
	//set_skill("checking", 250);          // 道听途说
	set_skill("xunshou_shu", 180);
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong_zhang");
	map_skill("staff", "dagou_bang");
	
	create_family("丐帮", 17, "帮主");

	set("apply/armor", 380);
    set("apply/damage", 200);
	set("no_chan",1);

	carry_object("yuzhu_zhang");
	set("no_huan",1);
	
//	carry_object("jiaohuaji");		叫化鸡
}

virtual char * chat_msg()
{
	switch(random(3))
	{
	case 0:
		return 	"洪叫化叹了口气道：“唉……何时能再吃到蓉儿做的「叫化鸡」啊……”";
	case 1:
		return 	"洪叫化说道：“俗话说「吃在江南」，所以老叫化特地跑来扬州看看。”";
	case 2:
		return "洪叫化喃喃道：“我们丐帮的「降龙十八掌」是天下最霸道的掌法。”";
	}

	return 0;
}

virtual char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("staff zhuang", 1);
		break;
	case 1:
		perform_action("unarmed xianglong", 1);
		break;
	case 2:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];

	if (me->query_str() < 20 || me->query_con() < 20) 
	{
		say(snprintf(msg, 255, "当叫化子需要能吃苦耐劳，依我看%s的资质似乎不适合当叫化子？", query_respect(me)), me);
		SendMenu(me);
		return;
	}

	if (me->querymap("family/family_name") &&
	    DIFFERSTR(me->querystr("family/family_name"), "丐帮") && me->query("beggarlvl") > 8) 
	{
		say(snprintf(msg, 255, "%s既然已有名师指点，何必又来拜老叫化呢？", query_respect(me)), me);
		SendMenu(me);
		return;
	}

	command(snprintf(msg, 255, "recruit %ld", me->object_id()));
	me->set("class", "beggar");
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	if (DIFFERSTR((who->environment())->querystr("base_name"), "扬州密林10" ))
		return notify_fail("我这是在哪里？");
	if(EQUALSTR(ob->querystr("id"),"bao guo") && EQUALSTR(ob->querystr("obj"),id(1)) &&
		EQUALSTR(ob->querystr("owner1"),who->id(1)))
	{
		who->add_temp("lin/baoguo/count",1);
		int exp=ob->query("exp");
		int repute=ob->query("repute");
		
		tell_object(who, snprintf(msg, 255, "\n$YEL%s点了点头，收下了你送过来的包裹。",name(1)));
		tell_object(who, "\n$YEL你完成了替福威镖局押运暗镖的任务。");
		tell_object(who, snprintf(msg, 255, "$YEL获得了%d的经验奖励，江湖声望上升了%d点",exp,repute));
		g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s(%s)压运暗镖成功，获得了%d的经验奖励，江湖声望上升了%d点！", who->name(1), who->id(1),exp,repute));
		who->delete_temp("lin/baoguo/start");
		if(who->query_temp("no_fei"))who->delete_temp("no_fei");
		who->add("combat_exp",exp);
		who->add("repute",repute);
		who->UpdateMe();
		destruct(ob);
		return 1;
	}

	if (ob->query("food_supply") <= 0)
		return 0;
	
	if (DIFFERSTR(ob->querystr("name"), "叫化鸡")) 
	{
		say(snprintf(msg, 255, "老叫化对%s没什么兴趣……", ob->name()), who);
		SendMenu(who);
		return 0;
	}

	say("啊……这正是我想吃的叫化鸡呀！", who);
	command(snprintf(msg, 255, "use %ld", ob->object_id()));
	say("想不到你小小年纪，心思却很细，就跟当年的蓉儿一样！", who);

	if (who->querymap("family/family_name") &&
	    DIFFERSTR(who->querystr("family/family_name"), "丐帮")) 
	{
		say("你还呆在这里干什么？", who);
		SendMenu(who);
		return 1;
	}

	CContainer * ob_yzz;

	if( (ob_yzz = PresentName("yuzhu_zhang", IS_ITEM)) )
    {
		ob_yzz->move(who);
		say("这根竹杖跟随我多年了，就送给你作见面礼吧。", who);
	}
	else
	{
		say("不过你来得不是时候，玉竹杖已经给别人了。", who);
    }

	SendMenu(who);
	return 1;
}


ZUSHI_END;
