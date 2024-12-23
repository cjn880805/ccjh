//xiaozhao.h
//Lanwood 2000-01-09

NPC_BEGIN(CNmingjiao_xiaozhao);

virtual void create()
{
	set_name("小仪",  "xiao yi");
	set("nickname",  "天涯思君不可忘");
	set("long",  "她双目湛湛有神，修眉端鼻，颊边微现梨涡，真是秀美无伦，只是年纪幼小，身材尚未长成，虽然容貌绝丽，却掩不住容颜中的稚气。");
	set("gender", "女性");
	set("age", 15);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 30);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	set("icon",girl1);
	set_weight(50000000);
	
	set("max_hp", 500);
	
	set("max_mp", 500);
	set("mp_factor", 50);
	set("combat_exp", 50000 + random(10000));
	set("score", 20000);
	
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("sword", 80);
	set_skill("taiji_jian", 70);
	set_skill("taiji_quan", 70);
	set_skill("tiyunzong",50);
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	map_skill("unarmed", "taiji_quan");
	
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 15);
	
	set("party/party_name", "明教");
	set("party/rank", "波斯圣教主");
	set("party/level", 1);
	set("mj",1);
		
	set_inquiry("退教", ask_tuijiao);
	set_inquiry("张无敌", ask_wuji);
	set_inquiry("倚天剑", ask_jian);
	set_inquiry("黄金", ask_gold);
	set_inquiry("食物", "自当年张GG离开我，我已经十七年没吃过草莓了……");
	set_inquiry("歌", ask_ge);
	//        set_inquiry("九阳真经", ask_jiuyang);
	set_inquiry("乾坤大挪移", ask_qiankun);
	
	set("chat_chance", 3);
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	add_money(10000);
	set("no_huan",1);
};

virtual char * chat_msg()
{
	static char msg[20][80]={
					"小仪低声吟道：天涯思君不可忘 武当山顶松柏长",
                    "小仪低声吟道：宝刀百炼生玄光 字作丧乱意彷徨",
                    "小仪低声吟道：皓臂似玉梅花妆 浮槎北溟海茫茫",
                    "小仪低声吟道：谁送冰舸来仙乡 穷发十载泛归航",
                    "小仪低声吟道：七侠聚会乐未央 百岁寿宴摧肝肠",
                    "小仪低声吟道：有女长舌如利枪 针其膏兮药其肓",
                    "小仪低声吟道：不悔仲子逾我墙 当道时见中山狼",
                    "小仪低声吟道：奇谋妙计梦一场 剥极而复参九阳",
                    "小仪低声吟道：青翼出没一笑扬 倚天长剑飞寒芒",
                    "小仪低声吟道：祸起萧墙破金汤 与子共穴相扶将",
                    "小仪低声吟道：排难解纷当六强 群雄归心约三章",
                    "小仪低声吟道：灵芙醉客绿柳庄 太极初传柔克刚",
                    "小仪低声吟道：举火燎天何煌煌 俊貌玉面甘损伤",
                    "小仪低声吟道：百尺高塔任回翔 恩断义绝紫衫王",
                    "小仪低声吟道：四女同舟何所望 东西永隔如参商",
                    "小仪低声吟道：刀剑齐失人云亡 冤蒙不白愁欲狂",
                    "小仪低声吟道：箫长琴短衣流黄 新妇素手裂红裳",
                    "小仪低声吟道：屠狮有会孰为殃 夭矫三松郁青苍",
                    "小仪低声吟道：天下英雄莫能当 君子可欺之以方",
                    "小仪低声吟道：秘笈兵书此中藏 不识张郎是张郎",
	};

	return msg[random(20)];
}

static char * ask_tuijiao(CNpc * me, CChar * who)
{
        if(DIFFERSTR(who->querystr("party/party_name"), "明教"))
            return "小仪莞尔一笑，对你说道：你还没加入我明教呢，就想退教？";
            
        if(EQUALSTR(who->querystr("family/family_name"), "明教") )
        	return "小仪抬起俏脸对$N说道：你已经是我圣教弟子，如何能退教？";
        
        me->say(g_Channel.do_emote(me, who, "sigh", 1), who);
        me->say(g_Channel.do_emote(me, who, "shake", 1), who);
		me->SendMenu(who);
        who->del("party");
        who->del("rank");
        who->del("mjlevel");
        return 0;
}

static char * ask_wuji(CNpc * me, CChar * who)
{
        me->say(g_Channel.do_emote(me, who, "sigh", 1), who);
        me->say("小仪幽幽地说：天涯思君不可忘，东西永隔如参商。", who);
		me->SendMenu(who);
        return 0;
}

static char * ask_jian(CNpc * me, CChar * who)
{
        me->say(g_Channel.do_emote(me, who, ":P", 1), who);
        me->say("不行啊，这是张公子托我保管的，不能随便给人。", who);
		me->SendMenu(who);
        return 0;
}

static char * ask_gold(CNpc * me, CChar * who)
{
        me->say(g_Channel.do_emote(me, who, ":P", 1), who);
        me->say("不行啊，这不能随便给人。", who);
		me->SendMenu(who);
        return 0;
}

static char * ask_ge(CNpc * me, CChar * who)
{
        me->say(g_Channel.do_emote(me, who, "nod", 1), who);
        me->say("小仪曼声唱道：世情推物理  人生贵适意", who);
        me->say("小仪曼声唱道：想人间造物搬兴废  吉藏凶 凶藏吉  富贵那能长富贵", who);
        me->say("小仪曼声唱道：日盈昃  月满亏蚀  地下东南  天高西北  天地尚无完体", who);
        me->say("小仪曼声唱道：展放愁眉  休争闲气  今日容颜  老于昨日  古往今来  尽须如此", who);
        me->say("小仪曼声唱道：管他贤的愚的  贫的和富的  到头这一身  难逃那一日", who);
        me->say("小仪曼声唱道：受用了一朝  一朝便宜", who);
        me->say("小仪曼声唱道：百岁光阴  七十者稀  急急流年  滔滔逝水", who);
		me->SendMenu(who);
        return 0;
}

static char * ask_qiankun(CNpc * me, CChar * who)
{
        if (who->query_temp("mark/qiankun") &&
				EQUALSTR(who->querystr("party/party_name"), "明教"))
        {
            who->delete_temp("mark/qiankun");
			return "小仪莞尔一笑，对你说道：乾坤大挪移心法在本教密道里，有缘的话就能找到。";
        }
        		
		who->set_temp("mark/qiankun", 1);
        return "自上代教主阳顶天离奇失踪，乾坤大挪移心法已经失落很久了。";
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("id"), "qiankun_fake"))
	{
		who->set_temp("qiankun_fake", 1);
		message_vision("$N低声惊呼：你从哪里找到的？", this);
		AddMenuItem("这张羊皮有什么特别？", "$0surprise $1", who);
		SendMenu(who);

		destruct(ob);
		return 1;
	}
	else if ( DIFFERSTR(ob->querystr("id"), "caomei") || DIFFERSTR(ob->querystr("name"), "草莓") )
	{	
		message_vision("$N微笑的道：这是什么东西？", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("guyuepai");

	ob->set_name( "怜月牌", "lianyue pai");

	message_vision("$N点点头，偷偷给$n一块东西。", this, who);
	ob->move(who);

	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "surprise") == 0)
	{
		return do_surprise(me);
	}
	CContainer * env = load_room("pk");
	if((strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0 )&& env->query("mj/start") && userp(me))
	{
		message_vision("$n横眉怒视$N，恨道：“在这大敌当前之际，你到底想做什么！！”", me, this);
		me->delete_temp("mf/exp");
		me->add("hp",-me->query("hp")/2);
		me->UpdateMe();
		me->start_busy(3);
		return 1;
	}
	return CNpc::handle_action(comm, me, arg);
}

int do_surprise(CChar * me)
{
	if(! me->query_temp("qiankun_fake")) return 0;

	me->delete_temp("qiankun_fake");

	message_vision("$N掏出一把小刀划破你的手指，把血抹在羊皮上面。", this);
	if(random(10) < 6)
	{
		me->receive_damage("hp", me->query("hp")/10);
		message_vision ("$N痛得眼泪直流，看看那张羊皮却什么反应都没有。", me);
		return 0;
	}
	else
	{
		me->receive_damage("hp", me->query("hp")/10);
        load_item("qiankun_xinfa")->move(me);
		SendMenu(me);
		message_vision ("$N的鲜血在羊皮上化开，慢慢地显出一些字迹来。", me);
		return 0;
	}
}

void die()
{
	char msg[255];
	CContainer * env = load_room("pk");
	if(env->query("mj/start"))
	{
		CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
		if(me && !env->query(snprintf(msg, 255,"mj/kill_%s",this->name(1))))
		{
			env->add(snprintf(msg, 255,"mj/kill_%s",this->name(1)),1);
			env->add("mj/count",1);
			g_Channel.do_channel(&g_Channel, 0, "chat", 
				snprintf(msg, 255, "$HIY%s$HIC新立奇功，斩获明教$HIY波斯总教主%s$HIC！",me->name(1),this->name(1)));

		}
	}
	CNpc::die();
}
NPC_END;




