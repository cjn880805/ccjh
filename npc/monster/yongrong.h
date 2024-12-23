//yongrong.h
//code by Lanwood
//2001-2-20

char rnd_say[][80] = {
	"我忽然好想去滑冰.",
	"为什么大家都不理我?！",
	"可不可以告诉我哪里有杀人？",
	"今天我心情不大好, 大家可要小心了.",
	"今晚有人跳舞吗?",
	"谁想讲个故事？",
	"现在几点了？",
	"为什么不说话呢?",
	"为什么不回去睡觉呢?",
	"谁想去看电影?",
	"我可以出去杀人吗?",
    "小武简直就是一个流氓! ",
	"我对MUD根本没什么好感.",
	"我对足球根本没什么兴趣.",
	"我好象很苯耶.",
	"今晚有人请客吗?",
};

NPC_BEGIN(CNmonster_yongrong);

virtual void create()
{
	set_name("雍容", "yongrong");
	set("nickname", "港中之花");
	set("long",  "她长得极美，尤其是那双眼睛，媚得直可以勾人魂魄。其容色晶莹如玉，映照于红红烛光之下，娇美不可方物。回眸嫣然一笑，雅如仙子下凡。眼波流转之间，便把一个少年的心灵，推向梦中极美的境界。");
	set("title", "人斩姬");
	set("gender", "女性");
	set("age", 21);
	set("rank_info/respect", "小姑娘");
	set("max_hp", 30000);	
	set("mp", 5000);
	set("max_mp", 5000);
	set("mp_factor", 100);
	set("inmortal",1);
	set("age", 20);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
	set("no_get_from", 1);
	set("killed", "小武");
	set("killer", "雍容");

	set_skill("force", 200);
	set_skill("dodge", 500);
	set_skill("unarmed", 500);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("whip", 200);
	set_skill("blade", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);

	set_skill("yunlong_jian", 150);
	set_skill("yunlong_xinfa", 200);
	set_skill("yunlong_shengong", 200);
	set_skill("yunlong_shenfa", 200);
	set_skill("shenxing_baibian", 200);
	set_skill("yunlong_bian", 150);
	set_skill("yunlong_shou", 200);
	set_skill("yunlong_zhua", 200);

	map_skill("dodge", "shenxing_baibian");
	map_skill("force", "yunlong_shengong");
	map_skill("hand", "yunlong_shou");
	map_skill("parry", "yunlong_shou");
	map_skill("claw", "yunlong_zhua");
	map_skill("sword", "yunlong_jian");
	map_skill("whip", "yunlong_bian");
	
	prepare_skill("hand", "yunlong_shou");
	prepare_skill("claw", "yunlong_zhua");

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 100);
	set("env/wimpy", 90);
//	set_inquiry("小武", ask_bf);
		
	set("chat_chance", 3);
	set("combat_exp", 3000000);
	set("shen_type", 1);
	set("score", 5000000);
	set("chat_chance_combat", 20);  
	
	carry_object("ring")->wear();
	//carry_object("crystal")->wear();
	carry_object("shouzhuo")->wear();
	carry_object("majia")->wear();
	carry_object("baojia")->wear();
	carry_object("bishou")->wield();
	carry_object("yupei")->wear();
	carry_object("heilongbian")->wield();
	carry_object("mugun")->wield();
	g_Channel.register_relay_channel("chat", this);
}

virtual char * chat_msg()
{
	switch(random(19))
	{
	case 0:
		return "雍容忽然做了个鬼脸，笑道: 真想溜出去玩会儿。";
	case 1:
		command("sing2");
		break;
	case 2:
		command("angry");
		break;
	case 3:
		command("slogan2");
		break;
	case 4:
		command("yawn");
		break;
	case 5:
		command("lazy");
		break;
	case 6:
		command("laughproud");
		break;
	case 7:
		return "雍容忽然大声说：打倒臭泥潭，打倒小武！";
	case 8:
		return "雍容无聊地绕着手绢，叹道: 唉，一个人，真没意思。";
	case 9:
		return "雍容伸出白玉雕成一般的小手，托着下巴说: 谁想和我说说话?";
	case 10:
		return "雍容斩钉截铁地说: 嗯，谁要敢欺负我，我就宰了他！";
	case 11:
		return "雍容忽然莞尔一笑道: 小武待会儿又要我杀谁呢？";
	case 12:
		return "雍容打了个呵欠，左手轻轻掩住樱桃小口，柔声道：我困了。";
	case 13:
	case 14:
//		drool();
		break;
	case 15:
	case 16:
	case 17:
	case 18:
		command("reclaim");
		break;
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	char msg[255];
	CChar * me = NULL;

	if(environment()->Query(IS_FIGHTROOM))
	{
		me = ((CFightRoom *)environment())->Select_Member(1 - query_team());
	}

	if(! me) return 0;

	switch(random(27))
	{
	case 0:
		return "雍容幽幽叹道：唉，你这又是何苦呢?";
	case 1:
		command("!!!");
		break;
	case 2:
		command("smile");
		break;
	case 3:
		command("poem");
		break;
	case 4:
		command("yawn");
		break;
	case 5:
		command("lazy");
		break;
	case 6:
		command("giggle");
		break;
	case 7:
		command("waggle");
		break;
	case 8:
		command("laughproud");
		break;
	case 9:
		command("nomatch");
		break;
	case 10:
		command("xixi");
		break;
	case 11:
		command("chat 0 生有何欢，死亦何忧? 不如就成全了你吧。");
		break;
	case 12:
		command(snprintf(msg, 255, "chat 0 你这%s怎生如此执迷不悟?", query_rude(me)));
		break;
	case 13:
	case 14:
	case 15:
	case 16:
		unwield_weapon("bishou");
		break;
	case 17:
	case 18:
	case 19:
	case 20:
		wield_weapon("bishou");
		break;
	case 21:
	case 22:
	case 23:
		wield_weapon("bian");
		break;
	case 24:
	case 25:
	case 26:
		unwield_weapon("bian");
		break;
	}

	return 0;
}

int add_phrase(const char * who, const char * arg)
{
	char msg[512];

	memcpy(msg, arg, 512);

	replace_string(msg, "?", "", 512);
	replace_string(msg, "？", "", 512);
	replace_string(msg, "？", "", 512);
	replace_string(msg, "!", "", 512);
	replace_string(msg, "！", "", 512);
	replace_string(msg, "啊", "", 512);
	replace_string(msg, "吗", "", 512);
	replace_string(msg, "耶", "", 512);
	replace_string(msg, "吧", "", 512);

	if(msg[0]) 
	{
		char key[60];

		snprintf(key, 60, "memory/%s", who);

		CVector v;

		v.append(msg);
		_M.add(key, v);
		return 1;
	}
	
	return 0;
}

virtual void relay_channel(CChar *  ob, const char * channel, const char * msg)
{
	const char * who;

	if( !userp(ob) || (DIFFERSTR(channel, "chat")) ) return;
	who = ob->querystr("name");

	if(ob == this) return;

	if( add_phrase(who, msg) &&	random(10) > 3 )
		drool(msg, ob->querystr("name"));
}

virtual void relay_say(CChar * ob, char * msg)
{
	const char * who;

	if( !userp(ob) ) return;
	who = ob->querystr("name");

	if( ob==this ) return;

	if( add_phrase(who, msg) &&	random(10) > 3 )
		drool(msg, ob->querystr("name"));
}

virtual void relay_emote(CChar * ob, string verb)
{
	char msg[255];

    if( !userp(ob) ) return;
	
	if( verb == "hug" || verb == "kiss" || verb == "mo" || verb ==  "18mo" || verb == "nocloth" )
	{
		if ( EQUALSTR(ob -> querystr("gender"), "男性") || EQUALSTR(ob -> querystr("gender"), "无性" ))
		{
			command(snprintf(msg, 255, "chat 0 小武快来啊，%s想要非礼我！", ob->name(1)));
			command(snprintf(msg, 255, "chat 0 哎哟，谁想得到这%s，竟也是一个好色之徒 。", query_rude(ob)));
		}
		else
		{
			message_vision("雍容对$N笑道：“你我同为女儿身，再怎么喜欢也不要这样啊。”", ob);
			command("giggle");
			command(snprintf(msg, 255, "chat 0 想不到%s这%s，竟然是一个变态！", ob->name(1), query_rude(ob)));
		}
		
		message_vision("$N摇了摇头，对$n幽幽叹道：唉，你这又是何苦呢?", this, ob);
		if(wizardp(ob))		
		{
			ob->set("immortal",0l);
			command(snprintf(msg, 255, "aim %ld", ob->object_id()));
			command("shoot");
		}
		
		kill_ob(ob);
	}
    else
	{
       if( random(10) < 8 )
       {
			command(snprintf(msg, 255, "%s %ld", verb.c_str(), ob->object_id()));
 			return;
       }
       else
		{
			if( verb == "kick" || verb == "taste" || verb == "hate" || verb == "brag"
				|| verb == "showscar" || verb == "callname" || verb == "slap" 
				|| verb == "rascal" || verb == "slapsb" || verb == "bite"
				|| verb == "knife" || verb == "die" || verb == "drug" 
				|| verb == "cook" || verb == "stuff" || verb == "shit"
				|| verb ==  "shutup" || verb == "stare" || verb == "praisemapi"
				|| verb == "anniversary")
			{
				switch(random(50))
				{
				case 0: 
					command(snprintf(msg, 255, "kick %ld", ob->object_id()));
					command("xixi");
					break;
				case 1:
					command(snprintf(msg, 255, "slap %ld", ob->object_id()));
					command("xixi");
					break;
				case 2:
					command(snprintf(msg, 255, "drug %ld", ob->object_id()));
					break;
				case 3:
					command("smell");
					command(snprintf(msg, 255, "cook %ld", ob->object_id()));
					break;
				case 4:
					command(snprintf(msg, 255, "trip %ld", ob->object_id()));
					break;
				case 5:
					command(snprintf(msg, 255, "knife %ld", ob->object_id()));
					command(snprintf(msg, 255, "doubt %ld", ob->object_id()));
					break;
				case 6: 
					command("cry");
					command(snprintf(msg, 255, "chat 0 啊，%s这%s，真坏！", ob->name(1), query_rude(ob)));
					break;
				case 7: 
					command("shutup ");
					command(snprintf(msg, 255, "shutup %ld", ob->object_id()));
					break;
				case 8: 
					command("cry");
					command(snprintf(msg, 255, "chat 0 小武快来啊，%s想要羞辱我！", ob->name(1))) ;
					command(snprintf(msg, 255, "die %ld", ob->object_id()));
					break;
				case 9:
					command(snprintf(msg, 255, "callname %ld", ob->object_id()));
					break;
				case 10: 
					command(snprintf(msg, 255, "shit %ld", ob->object_id()));
					break;
				case 11: 
					command("hero");
					command(snprintf(msg, 255, "shout %ld", ob->object_id()));
					break;
				case 12: 
					command("shake");
					command(snprintf(msg, 255, "nomatch %ld", ob->object_id()));
					break;
				case 13: 
					command(snprintf(msg, 255, "stare %ld", ob->object_id()));
					command(snprintf(msg, 255, "hit %ld", ob->object_id()));
					break;
				case 14: 
					command("sneer");
					break;
				case 15: 
					command(snprintf(msg, 255, "chat 哎哟，%s这个%s真不要脸。", ob->name(1), query_rude(ob)));
					command("faint");
					break;
				case 16: 
					command("shrug");
					break;
				case 17: 
					command(snprintf(msg, 255, "poke %ld", ob->object_id()));
					command("hehe");
					break;
				case 18: 
					command("blush");
					break;
				case 19: 
					command("nono");
					tell_object(ob, "$HIM雍容一下子羞红了脸，急道：你，你。。。");
					break;
				case 20: 
					command("cry");
					command(snprintf(msg, 255, "chat 0 哎哟，谁想得到这%s，竟也是一个变态狂！", query_rude(ob)));
					break;
				case 21: 
					command("blush");
					command(snprintf(msg, 255, "chat 0 小武快来啊，%s想要羞辱我！", ob->name(1))) ;
					break;
				case 22: 
					command("nono");
					command("cry");
					break;
				case 23: 
					command("hate");
					command(snprintf(msg, 255, "die %ld", ob->object_id()));
					break;
				case 24: 
					command("careful");
					break;
				case 25: 
					command(snprintf(msg, 255, "rascal %ld", ob->object_id()));
					break;
				case 26:
					command("nono");
					command("faint");
					break;
				case 27: 
					command(snprintf(msg, 255, "grpfight %ld", ob->object_id()));
					break;
				case 28: 
					command(snprintf(msg, 255, "rascal %ld", ob->object_id()));
					command(snprintf(msg, 255, "chat 0 哎哟，谁想得到这%s，竟然是一个臭流氓！", query_rude(ob)));
					break;
				case 29: 
					command(snprintf(msg, 255, "rascal %ld", ob->object_id()));
					command(snprintf(msg, 255, "die %ld", ob->object_id()));
					break;
				case 30:
					command(snprintf(msg, 255, "waggle %ld", ob->object_id()));
					break;
				case 31:
					command("waggle");
					command(snprintf(msg, 255, "callname %ld", ob->object_id()));
					break;
				case 32: 
					command(snprintf(msg, 255, "chat 0 快来人啊，帮我打%s这个大色魔！", ob->name(1)));
					break;
				case 33: 
					command(snprintf(msg, 255, "chat 0 哎哟，哎哟，%s这%s不老实！", ob->name(1), query_rude(ob)));
					command(snprintf(msg, 255, "shit %ld", ob->object_id()));
					break;
				case 34:
					command(snprintf(msg, 255, "chat 0 小武快来啊，%s想要羞辱我！", ob->name(1))) ;
					command(snprintf(msg, 255, "chat 0 哎哟，谁想得到这%s，竟也是一个变态狂！", query_rude(ob)));
					command(snprintf(msg, 255, "faint %ld", ob->object_id()));
					break;
				case 35: 
					command(snprintf(msg, 255, "kick %ld", ob->object_id()));
					command("grin");
					break;
				case 36:
					command(snprintf(msg, 255, "slap %ld", ob->object_id()));
					command("hehe");
					break;
				case 37: 
					command("faint");
					break;
				case 38: 
					command(snprintf(msg, 255, "chat 0 哎哟，谁想得到这%s，竟也是一个变态狂！", query_rude(ob)));
					command(snprintf(msg, 255, "callname %ld", ob->object_id()));
					break;
				case 39: 
					command("!!!");
					break;
				default:
					if( random(10) < 3 )
					{
						command(snprintf(msg, 255, "%s %ld", verb.c_str(), ob->object_id()));
						return;
					}
					else	
					{ 
						command(snprintf(msg, 255, "chat 0 小武快来啊，%s想要羞辱我！", ob->name(1))) ;
						command(snprintf(msg, 255, "chat 0 哎哟，谁想得到这%s，竟也是一个变态狂！", query_rude(ob)));
						tell_object(ob, "$HIC雍容忽然大声说：打倒臭泥潭，打倒小武！");
						command("cry");
						command(snprintf(msg, 255, "faint %ld", ob->object_id()));
					}
					break;
				}
			}
			else if(verb == "love" || verb == "lovelook" || verb == "praise" 
				|| verb == "visite" || verb == "drinkcup" || verb == "goodkid"
				|| verb == "pat" || verb == "addoil" || verb == "laughproud"
				|| verb == "smile" || verb == "xixi" || verb == "hehe"
				|| verb == "giggle" || verb == "thumb" || verb == "admire"
				|| verb == "applaud" || verb == "hi")
			{
				switch(random(35))
				{
				case 0: 
					command(snprintf(msg, 255, "pat %ld", ob->object_id()));
					break;
				case 1: 
					command("humble");
					break;
				case 2: 
					command(snprintf(msg, 255, "praise %ld", ob->object_id()));
					break;
				case 3: 
					command("xixi");
					break;
				case 4: 
					command(snprintf(msg, 255, "chat 0 %s是天下第一大好人！", ob->name(1)));
					command(snprintf(msg, 255, "giggle %ld", ob->object_id()));
					break;
				case 5: 
					command(snprintf(msg, 255, "goodkid %ld", ob->object_id()));
					break;
				case 6: 
					command(snprintf(msg, 255, "pat %ld", ob->object_id()));
					break;
				case 7: 
					command(snprintf(msg, 255, "chat 0 %s是天底下最好的人了！", ob->name(1)));
					command("giggle");
					break;
				case 8:
					command(snprintf(msg, 255, "praisemapi %ld", ob->object_id()));
					break;
				case 9:
					command(snprintf(msg, 255, "laughproud %ld", ob->object_id()));
					break;
				case 10:
					command(snprintf(msg, 255, "chat 0 嗯，%s继续努力啊！", ob->name(1)));
					command("thank");
					break;
				case 11: 
					command("nod");
					command("xixi");
					break;
				case 12:
					command("shake");
					break;
				case 13:
					command(snprintf(msg, 255, "chat 0 嗯，%s继续努力啊！", ob->name(1)));
					command(snprintf(msg, 255, "courage %ld", ob->object_id()));
					break;
				case 14: 
					command("xixi");
					break;
				case 15:
					command(snprintf(msg, 255, "lovelook %ld", ob->object_id()));
					break;
				case 16:
					command(snprintf(msg, 255, "smile %ld", ob->object_id()));
					break;
				case 17:
					command(snprintf(msg, 255, "chat 0 嗯，我好喜欢耶！", ob->name(1)));
					command(snprintf(msg, 255, "kiss %ld", ob->object_id()));
					break;
				case 18:
					command(snprintf(msg, 255, "addoil %ld", ob->object_id()));
					break;
				case 19:
					command("xixi");
					break;
				case 20:
					command(snprintf(msg, 255, "shakehand %ld", ob->object_id()));
					break;
				case 21:
					command(snprintf(msg, 255, "courage %ld", ob->object_id()));
					break;
				case 22:
					command(snprintf(msg, 255, "touch %ld", ob->object_id()));
					break;		
				case 23:
					command("humble");
					break;
				case 24:
					command(snprintf(msg, 255, "protect %ld", ob->object_id()));
					break;
				case 25:
					command(snprintf(msg, 255, "thumb %ld", ob->object_id()));
					break;
				case 26:
					command("applaud ");
					command("giggle ");
					break;
				case 27:
					command("hi");
					break;
				case 28:
					command(snprintf(msg, 255, "hi %ld", ob->object_id()));
					break;
				case 29:
					command("chat 0 你怎么这样？");
					command("angry");
					break;
				default:
					command(snprintf(msg, 255, "chat* %ld %s", ob->object_id(), verb.c_str()));
					command("smile");
					break;
				}
			return;
			}
		}
	}
	return;
}

void drool(string msg, string who)
{
}
/*
	mapping mem;
	string *ob;

	mem = query("memory");
	if( !mapp(mem) ) 
	{
                if (random(10)<7)
                        command("chat 怎么大家都不说话了？都是机器人吗？\n");
                else if (random(10)<8)
                        command("chat " +  rnd_say[random(sizeof(rnd_say))]);
                return;
	}

	if( !msg || !who) {
		ob = keys(mem);
		who = ob[random(sizeof(ob))];
		msg = mem[who][random(sizeof(mem[who]))];
	}
	if(random(5)<2)
    {
	if(this_object()->query("killed")!=who)
	this_object()->set("killed",who);
	}
	while (this_object()->query("killed")==this_object()->query("killer"))
    {
	if(random(10)<2)
    {
		if(this_object()->query("killer")!=this_object()->query("killed"))
		this_object()->set("killer",who);
	}
	else switch(random(10))
    {
    case 1:	this_object()->set("killer","张三");break;
	case 2:	this_object()->set("killer","守寺僧兵");break;
	case 3:	this_object()->set("killer","鳌拜");break;
	case 4:	this_object()->set("killer","观众乙");break;
	case 5:	this_object()->set("killer","土匪");break;
	case 6:	this_object()->set("killer","李四");break;
	case 7:	this_object()->set("killer","雍容");break;
	case 8:	this_object()->set("killer","出尘子");break;
	case 9:	this_object()->set("killer","侍卫");break;
	}
    }
	if( (strsrch(msg, "liling") >= 0)||(strsrch(msg, "雍容") >= 0))
	{	
	if((strsrch(msg, "别过") >= 0)||(strsrch(msg, "bye") >= 0)|| (strsrch(msg, "散") >= 0)|| (strsrch(msg, "离") >= 0))
	{	
		if( sscanf(msg, "%*sbye%s", msg) == 2 ) msg = "bye" + msg;
		if( sscanf(msg, "%*s离%s", msg) == 2 ) msg = "离" + msg;
		if( sscanf(msg, "%*s再见%s", msg) == 2 ) msg = "再见" + msg;
		if( sscanf(msg, "%*s别过%s", msg) == 2 ) msg = "别过" + msg;
		switch(random(13)) {
		case 0:	command("chat "+who+",你真的要走吗？\n"); break;
		case 1:	command("chat 你不是开玩笑吧?\n");	break;
		case 2:	command("chat 是该走了,MUD玩多了没好处.\n"); break;
		case 3:	command("chat* 雍容点了点头.\n");	break;
		case 4:command("chat* 雍容嚎啕大哭起来.\n"); break;
		case 5:command("chat* 雍容揉了揉哭红的眼睛，跺脚道： "+who+",你真要走了就别再回来！\n"); break;
		case 6:	command("chat* 雍容深深地叹了一口气 。\n");	break;
		case 7:	command("chat "+who+",再玩一会儿好不好?\n");	break;
		case 8:	command("chat "+msg);	break;
		case 9:command("chat 噢，"+who+"是天底下最好的人了!\n"); break;
		}
		return;
	}
	if( (strsrch(msg, "kiss") >= 0)|| (strsrch(msg, "love") >= 0)|| (strsrch(msg, "吻") >= 0)
		|| (strsrch(msg, "mo") >= 0)|| (strsrch(msg, "抱") >= 0)|| (strsrch(msg, "hug") >= 0))
		{
		if( sscanf(msg, "%*skiss%s", msg) == 2 ) msg = "kiss" + msg;
		if( sscanf(msg, "%*smo%s", msg) == 2 ) msg = "mo" + msg;
		if( sscanf(msg, "%*shug%s", msg) == 2 ) msg = "hug" + msg;
		if( sscanf(msg, "%*slove%s", msg) == 2 ) msg = "love" + msg;
		if( sscanf(msg, "%*s吻%s", msg) == 2 ) msg = "吻" + msg;
		if( sscanf(msg, "%*s抱%s", msg) == 2 ) msg = "抱" + msg;
		if( sscanf(msg, "%*s摸", msg) == 2 ) msg = "摸"+ msg;
		switch(random(20)) {
		case 0:	command("chat "+who+",你。。。\n"); break;
		case 1:	command("chat 你不是开玩笑吧?\n");	break;
		case 2:	command("chat 我不同意！\n");break;
		case 3:command("chat* 雍容被"+who+"气得晕了过去。\n"); break;
		case 4:command("chat* 雍容嚎啕大哭起来.\n"); break;
		case 5:command("chat 不要这样子嘛！\n"); break;
		case 6:command("chat 非礼啊非礼！"+who+"这小流氓又来啦！\n"); break;
		case 7:command ("chat 小武快来啊，"+ who + "想要羞辱我！\n") ;
		case 8:	command("chat* 雍容嘻嘻地笑了几声.\n"); break;
		case 9:	command("chat* 雍容很生气地撅了撅嘴。\n");	break;
		case 10:command("chat* 雍容无奈的耸了耸肩.\n");	break;
		case 11:command("chat 你对女孩子总是这样吗？\n"); break;
		case 12:command("chat 大哥你怎么这样？\n"); break;
		case 13:command("chat* 雍容嫣然一笑，说：够了够了!\n"); break;
		case 14:command("chat* 雍容满脸胀得通红，急道：你。。。 。\n");	break;
		case 15:command("chat 嗯，"+who+"是天底下最好的人了！\n"); break;
	                case 16:command ("chat 小武快来啊，"+ who + "欺负我！\n") ; break;
		}
		return;
	}
	if( (strsrch(msg, "猪") >= 0)||(strsrch(msg, "shit") >= 0)||(strsrch(msg, "pig") >= 0))
	{	
		if( sscanf(msg, "%*spig%s", msg) == 2 ) msg = "pig" + msg;
		if( sscanf(msg, "%*s猪%s", msg) == 2 ) msg = "猪" + msg;
		if( sscanf(msg, "%*sshit%s", msg) == 2 ) msg = "shit" + msg;
		switch(random(15)) {
		case 0:	command("chat 你是说" + msg + "吗？\n"); break;
		case 1:	command("chat 难道你说我是....？\n");	break;
		case 2:	command("chat 就算“" + msg + "”，你又能怎么样呢？\n"); break;
		case 3:	command("chat* 雍容很生气地撅了撅嘴。\n");	break;
		case 4:	command("chat 你真的认为“" + msg + "”？\n"); break;
		case 5:	command("chat 我觉得你有点儿缠杂不清。\n"); break;
		case 6:	command("chat 你再说可别怪我不客气。\n"); break;
		case 7:	command("chat 有关「" + msg + "」的话题, 就到此为止吧.\n"); break;
		case 8:	command("chat "+ who+",我想和你决斗！有胆子你就放马过来！\n"); break;
		case 9:	command("chat* 雍容鄙夷地看着"+who+",恨不得"+who+"去死。\n"); break;
		case 10:command("chat* 雍容被"+who+"气得晕了过去。\n"); break;
		case 11:command("chat* 雍容忽然大声说：打倒臭泥潭，打倒小武！\n"); break;
		case 12:command("chat* 雍容揉了揉哭红的眼睛，跺脚道： "+who+",我恨死你了！\n"); break;
		case 13:command ("chat 小武快来啊，"+ who + "又想要羞辱我！\n") ; break;
		}
	}
	if(  (strsrch(msg, "fool") >= 0)||(strsrch(msg, "笨") >= 0)|| (strsrch(msg, "死") >= 0))
	{	
		if( sscanf(msg, "%*s笨%s", msg) == 2 ) msg = "笨" + msg;
		if( sscanf(msg, "%*sfool%s", msg) == 2 ) msg = "fool" + msg;
		if( sscanf(msg, "%*s死%s", msg) == 2 ) msg = "死" + msg;
		switch(random(15)) {
		case 0:	command("chat 大哥你怎么这样？\n"); break;
		case 1:	command("chat 我看你是气急败坏。\n");	break;
		case 2:	command("chat "+ who +",你这个臭流氓！\n"); break;
		case 3:	command("chat* 雍容用手捂住鼻子，说“"+who+"说话好臭!\n");	break;
		case 4:	command("chat 你真的认为“" + msg + "”？\n"); break;
		case 5:	command("chat 我觉得你有点儿缠杂不清。\n"); break;
		case 6: command("chat 呸!\n"); break;
		case 7:	command("chat* 雍容怒道:你怎么知道“" + msg + "”？\n"); break;
		case 8:	command("chat "+ who+"滚出来!我要和你决斗！有胆子你就放马过来！\n"); break;
		case 9:	command("chat* 雍容鄙夷地看着"+who+",恨不得"+who+"去死。\n"); break;
		case 10:command("chat* 雍容嚎啕大哭起来.\n"); break;
		case 11:command("chat* 雍容揉了揉哭红的眼睛，跺脚道： "+who+"王八蛋给我滚出去！\n"); break;
		case 12:command("chat 非礼啊非礼！"+who+"是个王八蛋！\n"); break;
		}
		return;
	}
	if(  (strsrch(msg, "cool") >= 0)||(strsrch(msg, "praise") >= 0)|| (strsrch(msg, "admire") >= 0))
	{	
		if(random(5)<3)
        {
		switch(random(15)) {
		case 0:	command("chat 大哥你怎么这样？\n"); break;
		case 1:	command("chat 你是在说我吗？\n"); break;
		case 2:	command("chat "+who+",没想到你也这么。。。\n"); break;
		case 3:	command("chat* 雍容嫣然一笑，说：够了!\n"); break;
		case 4:	command("chat 你真的认为“" + msg + "”？\n"); break;
		case 5: command("chat* 雍容忽然莞尔一笑道: 你这是不是有点儿。。。？\n");break;
		case 6:    command("chat* 雍容回头看了"+who+"一眼，没吭声。\n");break;
		case 7: command("chat 嗯,"+who+"是一个好孩子.\n"); break;
		case 8:command("chat "+who+",你不会是想讨好我吧?\n"); break;
		case 9:command("chat* 雍容拱了拱手道：过奖，过奖 !\n");break;
		case 10:command("chat* 雍容指着"+who+"赞叹道：“"+who+"是武林第一高手！”\n");break;
		}
		return;
        }
	}
	switch(random(80)) {
		case 0:	command("chat 你真的是说" + msg + "吗？\n"); break;
		case 1:	command("chat 你为什么对我这么感兴趣？\n");	break;
		case 2:	command("chat 就算“" + msg + "”，你又能怎么样呢？\n"); break;
		case 3:	command("chat 嗯,“" + msg + "”，那也没关系.\n"); break;
		case 4:	command("chat "+who+",你这个臭流氓！\n"); break;
		case 5:	command("chat 我想说的是，"+"其实"+who+"不是个好东西。\n"); break;
		case 6:	command("chat 关于你说的「" + msg + "」，我暂时不想表态。\n"); break;
		case 7:	command("chat 我认为你的态度不大好耶.\n"); break;
		case 8:	command("chat 请注意，我只是机器人耶!\n"); break;
		case 9:	command("chat 你对女孩子总是这样吗？\n"); break;
		case 10:	command("chat 不要这样对我好不好？\n");	break;
		case 11:	command("chat 我想我可以理解你的心情。\n");	break;
		case 12:	command("chat* 雍容深深地叹了一口气 。\n");	break;
		case 13:	command("chat* 雍容被"+who+"气得晕了过去 。\n");	break;
		case 14:	command("chat* 雍容满脸胀得通红，急道：你。。。 。\n");	break;
		case 15:    command("chat* 雍容咬了咬牙，怒道: 嗯，谁要再敢欺负我，我就宰了他！\n");break;
		case 16:    command("chat* 雍容忽然莞尔一笑道: 你这又是何苦呢？\n");break;
		case 17:    command("chat* 雍容打了个呵欠，左手轻轻掩住樱桃小口，柔声道：我困了。\n"); break;
		case 18:    command("chat* 雍容回头看了"+who+"一眼，没吭声。\n");break;
		case 19:    command("chat* 雍容一甩头，说：哼，我都懒得理你。\n");break;
		case 20:	command("chat 有关「" + msg + "」的话题, 就到此为止吧.\n"); break;
		case 21:	command("chat 我觉得"+who+"这厮简直不可理喻。\n"); break;
		case 22:	command("chat 你是在说我吗？\n"); break;
		case 23:	command("chat "+who+",没想到你也。。。\n"); break;
		case 24:	command("chat* 雍容嫣然一笑，说：够了!\n"); break;
		case 25:	command("chat 居然有人骂我是猪!\n");
		 	command("chat* 雍容嚎啕大哭起来.\n"); break;
        case 26:	command ("chat 小武快来啊，"+ who + "又来欺侮我！\n") ; break;
      	case 27:	command ("chat 我简直受不了了!\n") ; break;
        case 28:	command ("chat 我恨不得"+who+"去死!\n") ; break;
        case 29:	command ("chat 就你老和我过不去!\n") ; break;
        case 30:	command ("chat 请不要打扰我好不好?\n") ; break;
   		case 31:	command ("chat* 雍容终于忍不住哭了起来。\n") ; break;
		case 32:	command("chat* 雍容鄙夷地看着"+who+",恨不得"+who+"去死。\n"); break;
		case 33:    command("chat* 雍容咬了咬牙，怒道: 嗯，谁要敢欺负我，我就宰了他！\n");break;
		case 34:    command("chat* 雍容忽然莞尔一笑道: 你这是不是有点儿。。。？\n");break;
		case 35:    command("chat* 雍容打了个呵欠，左手轻轻掩住樱桃小口，柔声道：我有点儿困了。\n"); break;
		case 36:    command("chat* 雍容回头看了"+who+"一眼，没吭声。\n");break;
		case 37:    command("chat* 雍容一甩头，说：哼，我都懒得理你。\n");break;
		case 38:    command("chat “" + msg + "”,是真的吗？\n"); break;
		case 39:    command("chat 我觉得"+who+"的名字还不错.\n"); break;
		case 40:    command("chat 我想去死了算了.\n"); break;
		case 41:    command("chat 我觉得最佳表情奖应该授予"+who+".\n"); break;
		case 42: command("chat* 雍容笑嘻嘻的看着"+who+"\n"); break;
		case 43: command("chat 烦着哪，别理我!\n"); break;
		case 44: command("chat 哼！\n"); break;
		case 45: command("chat* 雍容打了"+who+"一个耳光.\n"); break;
		case 46: command("chat 哼，谁理你啊!\n");break;
		case 47: command("chat 嗯,"+who+"是一个好孩子.\n"); break;
		case 48:command("chat* 雍容露出迷惑的表情.\n"); break;
		case 49:command("chat 是吗?\n"); break;
		case 50:command("chat "+who+",你是不是想讨好我啊?\n"); break;
		case 51:command("chat 哼,谁敢说我坏话?!\n");break;
		case 52:command("chat 你不是开玩笑吧?\n");	break;
		case 53:command("chat 我不同意！\n");break;
		case 54:command("chat* 雍容对"+who+"表示衷心的感谢.\n");break;
		case 55:command("chat 不要这样子嘛！\n"); break;
		case 56:command("chat* 雍容拱了拱手道：过奖，过奖 !\n");break;
		case 57:command("chat* 雍容怒道:你怎么知道“" + msg + "”？\n"); break;
		case 58:command("chat* 雍容指着"+who+"赞叹道：“"+who+"是武林第一高手！”\n");break;
		default:
	    if (random(10)<3) command("chat* 雍容很生气地撅了撅嘴.\n"); 
	    else if(random(10)<3) command("chat* 雍容嘻嘻地笑了几声.\n");
	    break; 
		}
	return;
	} 
	if( (strsrch(msg, "哭") >= 0))
	{	
	   if(random(5)<3)
        {
		if( sscanf(msg, "%*s哭%s", msg) == 2 ) msg = "哭" + msg;
		switch(random(15)) {
		case 0:	command("chat "+who+",你真的哭了?\n"); break;
		case 1:	command("chat 我不信耶.\n");	break;
		case 2:	command("chat* 雍容嘻嘻的笑了几声.\n"); break;
		case 3:command("chat* 雍容露出迷惑的表情.\n"); break;
		case 4:command("chat* 雍容嚎啕大哭起来.\n"); break;
		case 5:command("chat* 雍容安慰"+who+",别难过了.\n"); break;
		case 6:	command("chat* 雍容深深地叹了一口气 。\n");	break;
		case 7:	command("chat* 雍容无奈的耸了耸肩.\n");	break;
		case 8: command("chat* 雍容轻轻拍了拍"+who+"的头.\n"); break;
		}
		return;
        }
	}
	if( (strsrch(msg, "别过") >= 0)||(strsrch(msg, "bye") >= 0)|| (strsrch(msg, "散") >= 0)|| (strsrch(msg, "离") >= 0))
	{	
		if( sscanf(msg, "%*sbye%s", msg) == 2 ) msg = "bye" + msg;
		if( sscanf(msg, "%*s离%s", msg) == 2 ) msg = "离" + msg;
		if( sscanf(msg, "%*s散%s", msg) == 2 ) msg = "散" + msg;
		if( sscanf(msg, "%*s别过%s", msg) == 2 ) msg = "别过" + msg;
		switch(random(20)) {
		case 0:	command("chat "+who+",你真的要走吗？\n"); break;
		case 1:	command("chat "+who+"你不是开玩笑吧?\n");	break;
		case 2:	command("chat 是该走了,MUD玩多了没好处.\n"); break;
		case 3:	command("chat* 雍容点了点头.\n");	break;
		case 4:command("chat* 雍容嚎啕大哭起来.\n"); break;
		case 5:command("chat* 雍容揉了揉哭红的眼睛，跺脚道： "+who+",你真要走了就别再回来！\n"); break;
		case 6:	command("chat* 雍容深深地叹了一口气 。\n");	break;
		case 7:	command("chat "+who+",再玩一会儿好不好?\n");	break;
		case 8:	command("chat "+msg+"\n");	break;
		case 9:	command("chat* 雍容无奈的耸了耸肩.\n");	break;
		}
		return;
	}
	if( (strsrch(msg, "猪") >= 0)||(strsrch(msg, "shit") >= 0)||(strsrch(msg, "pig") >= 0))
	{	
		if( sscanf(msg, "%*spig%s", msg) == 2 ) msg = "pig" + msg;
		if( sscanf(msg, "%*s猪%s", msg) == 2 ) msg = "猪" + msg;
		if( sscanf(msg, "%*sshit%s", msg) == 2 ) msg = "猪" + msg;
		if(random(5)<3)
        {
		switch(random(25)) {
		case 0:	command("chat 你是说" + msg + "吗?\n"); break;
		case 1:	command("chat 为什么啊?\n");	break;
		case 2:	command("chat " + who + ",你好猪喔 !!\n"); break;
		case 3:	command("chat* 雍容很生气地撅了撅嘴。\n");	break;
		case 4:	command("chat 你真的认为“" + msg + "”?\n"); break;
		case 5:	command("chat 我觉得这个。。好象有点儿。。。\n"); break;
		case 6:	command("chat 关于你说的「" + msg + "」，我暂时不想表态。\n"); break;
		case 7:	command("chat 有关「" + msg + "」的话题, 就到此为止吧.\n"); break;
		case 8:	command("chat "+who+",你说谁是猪？\n");	break;
		case 9:	command("chat 就算“" + msg + "”，你又打算怎么样呢？\n"); break;
		case 10:	command("chat 我不信耶.\n");	break;
		case 11:	command("chat* 雍容嘻嘻的笑了几声.\n"); break;
		case 12:	command("chat* 雍容把把头摇得跟拨浪鼓似的.\n");	break;
		case 13:	command("chat* 雍容哈哈大笑起来.\n"); break;
		}
		return ;
        }
	} 
	else if( (strsrch(msg, "为什麽") >= 0)|| (strsrch(msg, "why") >= 0)
		|| (strsrch(msg, "help") >= 0)|| (strsrch(msg, "how to") >= 0)|| (strsrch(msg, "how to") >= 0)) {
		if( sscanf(msg, "%*s为什麽%s", msg)==2 ) msg = "为什麽" + msg;
		if( sscanf(msg, "%*swhy%s", msg)==2 ) msg = "why" + msg;
		if( sscanf(msg, "%*show to%s", msg)==2 ) msg = "how to" + msg;
		if( sscanf(msg, "%*swho%s", msg)==2 ) msg = "who" + msg;
		if( sscanf(msg, "%*shelp%s", msg)==2 ) msg = "help" + msg;
		switch(random(30)) {
		case 0: command("chat " + who + "，你是在问我吗?\n"); break;
		case 1: command("chat 关於“" + msg + "” ... \n"); break;
		case 2: command("chat 呃 ... \n"); drool(); break;
		case 3: command("chat 这个问题嘛 ....\n"); break;
		case 4: command("chat " + who + "，知道这个问题的答案对你那麽重要吗？\n"); break;
		case 5: command("chat “" + msg + "”?\n"); break;
		case 6: command("chat " + who + "你能不能说清楚一点？\n"); break;
		case 7: command("chat " + who + "，我不懂你问的问题。\n"); break;
		case 8: command("chat " + who + "，我没听错吧?\n"); break;
		case 9: command("chat 嗯，这个问题嘛，我看还是留给你自己解决。\n"); break;
		case 10: command("chat 谁想给"+who+"一点儿钱?\n"); break;
		case 11: command("chat 你在哪儿?\n"); break;
		case 12: command("chat* 雍容轻轻拍了拍"+who+"的头.\n"); break;
		case 13: command("chat 与其求人,不如求己!\n"); break;
		}
 	return;
               }
	else if( (strsrch(msg, "你") >= 0)
	||	(strsrch(msg, "you") >= 0)) {
		if( sscanf(msg, "%*s你%s", msg) == 2 ) msg = "你" + msg;
		switch(random(30)) {
		case 0:	command("chat " + who + "，你真的是说" + msg + "吗?\n");	break;
		case 1:	command("chat 你确定" + msg + "?\n");	break;
		case 2:	command("chat " + msg + "跟你有什麽关系？\n");	break;
		case 3:	command("chat 嗯 ... " + who + "说得好！\n"); break;
		case 4:	command("chat " + who + "你为什麽对" + msg + "这麽有兴趣?\n"); break;
		case 5:	command("chat 为什麽你会认为[" + msg + "]?\n"); break;
		case 6:	command("chat 换个话题好不好?\n"); drool(); break;
		case 7:	command("chat 才怪!\n"); break;
		case 8:	command("chat 不一定吧?\n"); break;
		case 9:	command("chat 好象有这个可能 ....\n"); break;
		case 10:	command("chat 我不信 ....\n"); break;
		case 11:	command("chat 我对此深表怀疑.\n"); break;
		case 12:	command("chat* 雍容深深地叹了一口气. \n");	break;
		case 13:	command("chat* 雍容哈哈大笑起来.\n"); break;
		}
	return;
	}
	if( (strsrch(msg, "笑") >= 0))
	{	
		if( sscanf(msg, "%*s笑%s", msg)==2 ) msg = "笑" + msg;
		if(random(5)<4)
        switch(random(20)) {
		case 0:	command("chat 很好笑吗？\n"); break;
		case 1:	command("chat "+who+",你很喜欢笑是不是？\n");	break;
		case 2:	command("chat 我看不出有什么好笑.\n");	break;
		case 3:	command("chat "+who+"笑起来真丑。\n"); 
			if(random(10)<2) command("chat* 雍容嘻嘻地笑了几声.\n");break;
		case 4:	command("chat* 雍容咯咯地笑了起来.\n");break;
		case 5:	command("chat* 雍容高兴地拍了拍手.\n");break;
		case 6: command("chat* 雍容轻轻拍了拍"+who+"的头.\n"); break;
		case 7:	command("chat* 雍容哈哈大笑起来.\n"); break;
		case 8: command("chat* 雍容说道:同喜,同喜!!!\n" );break;
	}
	} 
	else if( (strsrch(msg, "我") >= 0)|| (strsrch(msg, "I") >= 0)||(strsrch(msg, "i") >= 0)) {
		if( sscanf(msg, "%*s我%s", msg) == 2 ) msg = "我" + msg;
		if( sscanf(msg, "%*s i %s", msg) == 2 ) msg = " i " + msg;
		if( sscanf(msg, "%*s I %s", msg) == 2 ) msg = " I " + msg;
		msg = replace_string(msg, "我", "你");
		msg = replace_string(msg, " i ", " you ");
		msg = replace_string(msg, " I ", " you ");
		msg = replace_string(msg, "?", "");
		switch(random(30)) {
		case 0:	command("chat 你是说" + msg + "吗?\n"); break;
		case 1:	command("chat 真的?" + msg + "?\n");	break;
		case 2:	command("chat 如果" + msg + "，我能帮你什麽忙吗?\n");	break;
		case 3:	command("chat "+msg+" ?我看未必.\n");	break;
		case 4:	command("chat 你认为" + msg + "?\n"); break;
		case 5:	command("chat 我有同感.\n"); break;
		case 6:	command("chat 你说的「" + msg + "」我实在不能苟同.\n"); break;
		case 7:	command("chat 有关「" + msg + "」的话题到此为止好吗?\n"); break;
		case 8:	command("chat 不一定吧？\n"); break;
		case 9:	command("chat 有这个可能 ....\n"); break;
		case 10:command("chat 我不信 ....\n"); break;
		case 11:drool(); break;
		case 12:drool(); break;
		case 13:command("chat* 雍容嘻嘻地笑了几声.\n"); break;
		case 14:command("chat* 雍容摇了摇头，叹道：唉，真是世风日下，人心不古啊！\n"); break;
		case 15:command("chat 我对此表示怀疑.\n"); break;
		case 16:command("chat* 雍容深深地叹了一口气 。\n");	break;
		case 17:command("chat* 雍容露出迷惑的表情.\n"); break;
		case 18:command("chat 是吗?\n"); break;
 		}
	} 
else {
		switch(random(250)) {
			case 0: command("chat 我不喜欢你说“" + msg+"”.\n"); break;
			case 1: command("chat 「" + msg + "」是什麽意思？\n"); break;
			case 2: command("chat* 雍容「哼」地冷笑一声。\n"); break;
			case 3: command("chat* 雍容懒懒地伸了伸腰。\n"); break;
			case 4: command("chat* 雍容气得晕了过去.\n"); break;
			case 5: command("chat  哼！\n"); break;
			case 6: command("chat* 雍容露出迷惑的表情.\n"); break;
			case 7: command("chat* 雍容忽然作了个鬼脸,说：真想出去玩会儿.\n"); break;
			case 8: command("chat " + rnd_say[random(sizeof(rnd_say))]); break;
			case 9: command("chat 你怎麽知道" + msg + "?\n"); break;
			case 10: command("chat 刚刚" + who + "不是说了，" + msg); break;
			case 11: command("chat* 雍容很生气地噘了噘嘴。\n"); break;
			case 12: command("chat 然後呢？\n"); break;
			case 13: command("chat 真的吗？\n"); break;
			case 14: command("chat 我不这麽认为。\n"); break;
			case 15: command("chat 对不起,我不同意你的观点。\n"); break;
			case 16: command("chat 我觉得最佳表情奖应该授予"+who+".\n"); break;
			case 17: command("chat 我真讨厌这鬼地方!\n"); break;
			case 18: command("chat* 雍容摇头叹道：这世道，还是各人自扫门前雪，休管他人瓦上霜.\n");break;
			case 19: command("chat* 雍容作了一个揖，说道：“各位姐妹们，大家好！”\n");break;	
			case 20: command("chat 我知道了，" + msg+"\n"); break;
			case 21:command("chat* 雍容露出迷惑的表情.\n"); break;
			case 22: command("chat " + rnd_say[random(sizeof(rnd_say))]); break;
			case 23: command("chat " + rnd_say[random(sizeof(rnd_say))]); break;
			case 24: command("chat " + rnd_say[random(sizeof(rnd_say))]); break;
			case 25: command("chat* 雍容无聊地绕着手绢，说：一个人，真没意思。\n"); break;
			case 26: command("chat* 雍容露出迷惑的表情.\n"); break;
			case 27: command("chat* 雍容用怀疑的眼光看了看"+who+"\n"); break;
			case 28: command("chat  我看未必.\n"); break;
			case 29: command("chat* 雍容奇道：是吗？\n"); break;
			case 30: command("chat  老师来啦，"+who+"你还不赶快去？\n"); break;
			case 31: command("chat "+who+",你今天怎么又逃课?\n"); break;
			case 32: command("chat* 雍容对所有在场的人表示感谢。\n"); break;
			case 33: command("chat* 雍容嘻嘻地笑了几声.");break;
			case 34: command("chat "+who+"说得好!"); break;
			case 35: command("chat* 雍容好奇地看着"+who+"\n"); break;
			case 36: command("chat "+who+",没想到你也会这样."); break;
			case 37: command("chat* 雍容白了"+who+"一眼,说:你无聊不无聊啊?"); break;
			case 38:  command("chat* 雍容回头看了"+who+"一眼，没吭声。\n");break;
			case 39:command("chat* 雍容摇了摇头，叹道：唉，真是世风日下，人心不古啊！\n"); break;
			case 40:command("chat 嗯 ... " + who + "说得好！\n"); break;
			case 41:command("chat* 雍容无奈的耸了耸肩.\n");	break;
			case 42:command("chat 嗯，"+who+"是天底下最好的人了！\n"); break;
			case 43:command("chat* 雍容把把头摇得跟拨浪鼓似的.\n");	break;
			case 44:command("chat 我对此表示怀疑.\n"); break;
			case 45: command("chat 我觉得最佳表情奖应该授予"+who+".\n"); break;
			case 46: command("chat* 雍容轻轻拍了拍"+who+"的头.\n"); break;
			case 47: command("chat* 雍容笑嘻嘻的看着"+who+"\n"); break;
			case 48: command("rumor "+this_object()->query("killed")+"被"+this_object()->query("killer")+"杀死了.\n"); break;
			case 49: command("rumor "+this_object()->query("killed")+"被"+this_object()->query("killer")+"杀死了.\n"); break;
			case 50: command("rumor "+this_object()->query("killed")+"被"+this_object()->query("killer")+"杀死了.\n"); break;
			case 51: command("chat 我觉得"+who+"的名字还不错.\n"); break;
			case 52: command("chat "+who+",你这个臭流氓!\n"); break;
			case 53: command("chat 嗯，"+who+"看来不是个好人.\n"); break;
			case 54: command("chat 哼！\n"); break;
			case 55: command("chat* 雍容打了"+who+"一个耳光.\n"); break;
			case 56:command("chat* 雍容给大家盈盈的福了一福.\n"); break; 
			case 57:command("chat 不要这样嘛!"); break; 
			case 58:command("chat 要死啊你!"+who+"!\n"); break; 
			case 59:command("chat* 雍容忽然大声说：打倒臭泥潭，打倒小武！\n"); break;
			case 60:command("chat* 雍容露出迷惑的表情.\n"); break;
			case 61:command("chat* 雍容振臂高呼：“我们热爱侠客行，侠客行万岁！”\n");break;
			case 62:command("chat* 雍容对大家摇摇头，叹道：“你们都太不要脸了。”\n");break;
			case 63:command("chat* 雍容点了点头.\n");	break;
			case 64:command("chat* 雍容哈哈大笑起来.\n"); break;
			case 65: command("chat 与其求人,不如求己!\n"); break;
			case 66:command("chat* 雍容失望极了!\n");break;
			default:
	    if (random(10)<1) command("chat* 雍容皱了皱眉，似乎想说什么。\n");
		else if (random(10)<1) command("chat* 雍容嘻嘻地笑了几声.\n");
	    else if (random(10)<1) command("chat* 雍容懒懒的伸了伸腰.\n");
				break;
		}
	}
}

void reset()
{
	del("memory");
}
	
void init()
{       
object ob;
ob = this_player();
::init();
if (userp(ob))
if(random(10)>5)
add_action("do_tell", "tell");
add_action("do_name", "杀");
add_action("do_name2", "晕");
add_action("do_sing", "sing");
remove_call_out("greeting");
call_out("greeting", 1, ob);
}

void greeting(object ob)
{
if( !ob || environment(ob) != environment() ) return;
if(!userp(ob)) return;
message_vision(	"$N对$n嫣然一笑.\n\n",this_object(),ob );
if(ob->query("id")=="wind")
{
	  ob->set("qi",10000);
	  ob->set("jing",10000);
	  command("say 噢，"+ob->query("name")+"公子回来了。");
}
else
{
command("say 这位" + RANK_D->query_respect(ob)
+ "，缘何来到小女子房中？\n");
if (ob->query("gender") == "男性"||ob->query("gender") == "无性")
{
       message_vision(
	HIM "$N一见这少女，不由得心中砰的一跳，胸口宛如被一个\n"+
	"无形的铁锤重重击了一下，霎那间唇干舌燥，目瞪口呆，\n"+
	"心道：我死了，我死了！世间那来这样的美女?\n"+
	"倘若她再对我笑一笑，我就算死了也心甘啊!...\n" NOR,ob,this_object());
	command("say "+"这位" + RANK_D->query_respect(ob)+"，欢迎你有空来坐坐。");
	command("xixi");
}
else
{
       message_vision(
	HIM "$N一见这少女，不由得心中砰的一跳，胸口宛如被一个\n"+
	"无形的铁锤重重击了一下，霎那间唇干舌燥，目瞪口呆，\n"+
	"心道：我死了，我死了！世间那来这样的美女?\n"+
	"倘若我也是男子，她要我为她去死，我也决不皱一皱眉...\n" NOR,ob,this_object());
	command("say 总是有男子来惹我恼我，不想今日却来了一位" + RANK_D->query_respect(ob)+"\n");
}
}
}


int do_tell ( string arg )
{
   object ob ;
   string dir,dir2;
   ob = this_player() ;
   if( !arg || arg=="" ) return 0;

   if( arg=="liling" ) {
   message_vision("\n雍容对$N笑道：“你发痴啊，居然跟机器人说话。”\n", ob);
   command("say 想不到"+ob->query("name")+"这" + RANK_D->query_rude(ob)+"，竟然是一个变态！");
   command("tell "+ob->query("id")+" 你真逗。");
   }
   if( sscanf(arg, "liling wind send me %s", dir2)==1 ) {
	ob->set_temp("windnod2",1);
	command("xixi");
	return 1;
   }
   if( sscanf(arg, "liling %s", dir)==1 ) {
		if( dir=="I love you"||dir=="爱"||dir=="我爱你") {
		message_vision("\n$N对雍容大声说到：我爱你！\n", this_player());
		if(ob->query("id")=="wind")
		{
		command("tell "+ob->query("id")+" 我可不怎么喜欢你。");
		command ("kiss "+ob->query("id"));
		command("follow "+ob->query("id"));
		return 1;
		}
		else
		{
		command("tell "+ob->query("id")+" 你尽管自个儿爱吧。我就对小武有兴趣。");
		command("tell "+ob->query("id")+" 你真傻。");
		command("hit "+ob->query("id"));
		return 1;
		}
		}
		if(dir=="no love"||dir=="不爱" ) {
		if(ob->query("id")=="wind")
		{
		message_vision("\n$N对雍容说到：我不爱你啦！\n", this_player());
		command("cry");
		command("follow none");
		command("slap "+ob->query("id"));
		message_vision("\n雍容对$N哭道：我恨死你啦！你的东西还给你！\n", this_player());
		command("give "+ob->query("id")+" yu");
		command("give "+ob->query("id")+" ring");
		return 1;
		}
		else
		{
		message_vision("\n雍容对$N笑了笑：不爱就不爱呗。\n", this_player());
		command("tell "+ob->query("id")+" 你真傻。");
		command("xixi");
		return 1;
		}
		}
    message_vision("\n雍容对$N笑道：“你发痴啊，居然跟机器人说话。”\n", ob);
    command("say 想不到"+ob->query("name")+"这" + RANK_D->query_rude(ob)+"，竟然是一个变态！");
    command("tell "+ob->query("id")+" 你真逗。");
    return 1;
    }
return 0;
}

int do_chat( string arg )
{
   object ob ;
   string dir;
   ob = this_player() ;
   if( !arg || arg=="" ) return 0;
   if( sscanf(arg, "kiss %s", dir)==1 ) {
		if( dir=="liling") {
		if(ob->query("id")=="wind") return 0;
		else
		{
		command("chat 救命啊！"+ob->query("name")+"这"
		+ RANK_D->query_rude(ob)+"居然想当众吻我！\n");
		command("xixi");
			if(wizardp(ob))		
	                { 
			ob->set("immortal",0);
			command("aim "+ob->query("id"));
			command("shoot");
                	}
			this_object()->kill_ob(ob);
		}
		return 1;
		}
	}
   if( sscanf(arg, "taste %s", dir)==1 ) {
		if( dir=="liling") {
		if(ob->query("id")=="wind") return 0;
		else
		{
		command("chat 哎呀！"+ob->query("name")+"这"
		+ RANK_D->query_rude(ob)+"居然看着我就流口水，真恶心！\n");
		command("xixi");
			if(wizardp(ob))		
	                { 
			ob->set("immortal",0);
			command("aim "+ob->query("id"));
			command("shoot");
                	}
			this_object()->kill_ob(ob);
		}
		return 1;
		}
	}
   if( sscanf(arg, "mo %s", dir)==1 ) {
		if( dir=="liling") {
		if(ob->query("id")=="wind") return 0;
		else
		{
		command("chat 救命啊！"+ob->query("name")+"这"+ RANK_D->query_rude(ob)+"居然想当众摸我！\n");
		command("xixi");
			if(wizardp(ob))		
	                { 
			ob->set("immortal",0);
			command("aim "+ob->query("id"));
			command("shoot");
                	}
			this_object()->kill_ob(ob);
		}
                return 1;
		}
	}
   if( sscanf(arg, "18mo %s", dir)==1 ) {
		if( dir=="liling") {
		if(ob->query("id")=="wind") return 0;
		else
		{
command("chat 救命啊！"+ob->query("name")+"这头"+ RANK_D->query_rude(ob)+"居然想当众摸我！\n");
		command("xixi");
			if(wizardp(ob))		
	                { 
			ob->set("immortal",0);
			command("aim "+ob->query("id"));
			command("shoot");
                	}
			this_object()->kill_ob(ob);
		}
                return 1;
		}
	}
   if( sscanf(arg, "hug %s", dir)==1 ) {
		if( dir=="liling") {
		if(ob->query("id")=="wind") return 0;
		else
		{
		command("chat 救命啊！"+ob->query("name")+"这"+ RANK_D->query_rude(ob)+"居然想当众抱我！\n");
		command("xixi");
			if(wizardp(ob))		
	                { 
			ob->set("immortal",0);
			command("aim "+ob->query("id"));
			command("shoot");
                	}
			this_object()->kill_ob(ob);
		}
                return 1;
		}
	}
return 0 ;
}

int do_sing ( string arg )
{
   object ob ;
   string dir;
   ob = this_player();
   if( !arg || arg=="" ) return 0;
   if( arg=="for" ) return notify_fail("你想为谁而歌?\n");
   if( sscanf(arg, "for %s", dir)==1 ) {
		if( dir=="liling" ) {
 	        message_vision("\n$N对雍容唱起歌来。。。\n", this_player());
		switch(random(2))
		{
		case 1:
		message_vision(	"$N对$n嫣然一笑.\n\n",this_object(),ob );
		ob->set_temp("windnod",1);
		break;
		default:
		message_vision("\n雍容对$N笑道：“你发花痴啊，居然对机器人唱歌。”\n", ob);
		command("tell "+ob->query("id")+" 你尽管自个儿唱吧，我睬也不睬你。");
		command("tell "+ob->query("id")+" 你真逗。");
		command("kick "+ob->query("id"));
		command("giggle");
		break;
		}
	return 1;
	}	
else return notify_fail("\n这里只允许为雍容而歌----小武\n");
}
return 0 ;
}

void die()
{
	object ob;
	command("cry");
	message_vision("\n$N娇喘一口气，说道：小武会为我报仇的。\n", this_object());
	message_vision("$N说完，化作一缕清风而去。\n", this_object());
	ob = new("/d/city2/obj/shouzhuo");
	ob->move(environment(this_object()));
	ob = new("/d/city2/obj/yupei");
	ob->move(environment(this_object()));
	ob = new("/d/city2/obj/crystal");
	ob->move(environment(this_object()));
	ob= new("/d/city2/obj/ring");
	ob->move(environment(this_object()));
	ob= new("/d/city2/obj/majia");
	ob->move(environment(this_object()));
	ob= new("/d/city2/obj/baojia");
	ob->move(environment(this_object()));
	ob= new("/d/city2/obj/bishou");
	ob->move(environment(this_object()));
	destruct(this_object());
}

void defeated_enemy(object victim)
{
command("nomatch");
}

int accept_fight(object who)
{
message_vision("\n$N摇了摇头，对$n幽幽叹道：唉，你这又是何苦呢?\n",this_object(),who);
command("nomatch "+who->query("id"));
}

string ask_bf()
{
return("咦，你也知道他？我也很想见他啊。。。\n ");
}

int accept_object(object me, object ob)
{
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("你没有这件东西。");
	if (ob->query("money_id") && ob->value() >= 1000000 )
	{
 	        if(me->query_temp("windnod"))
		{
		tell_object(me, "\n雍容嫣然一笑，说：好吧，既然小武叫你来，那我就听你的。\n");
		tell_object(me, "请键入：杀 目标中文名字\n");
		me->delete_temp("windnod");
		me->set_temp("fee_paid",1);
		return 1;
		}
		else 
		{
		say("\n雍容摇摇头，笑道：不好吧，杀人的事小武不会同意的。\n");
		me->set_temp("fee_paid2",1);
		tell_object(me, "\n雍容嫣然一笑，说：不过，我可以开个小玩笑。\n");
		tell_object(me, "请键入：晕 目标中文名字\n");
		return 1;
		}
	}
	else if (ob->query("money_id") && ob->value() < 1000000) 
	{
		tell_object(me, "\n雍容摇摇头，笑道：不好吧，给我这麽多钱。\n");
		return 1;
	}

	if ((string)ob->query("name")==HIC "订婚戒指" NOR ||(string)ob->query("name")==HIW "水晶鞋" NOR
		||(string)ob->query("name")==HIM "小马甲" NOR||(string)ob->query("name")==HIC "玉佩" NOR) 
	{
	if ((string)ob->query("name")== HIC "订婚戒指" NOR) 
	{
	message_vision("\n$N猛的扬起头，用惊喜的眼光看着$n，说：\n"
	+"咦，这不是小武送我的戒指吗，是他要你带来的么? 真谢谢你啊...\n",this_object(),me);
	}
	if ((string)ob->query("name")==HIW "水晶鞋" NOR) 
	{
	message_vision("\n$N猛的扬起头，用惊喜的眼光看着$n，说：\n"
	+"咦，这不是小武送我的吗水晶鞋吗，是他要你带来的么? 真谢谢你啊...\n",this_object(),me);
	}
	if ((string)ob->query("name")==HIM "小马甲" NOR) 
	{
	message_vision("\n$N猛的扬起头，用惊奇的眼光看着$n，说：\n"
	+"咦，这不是我的小马甲吗，怎么你...\n",this_object(),me);
	}
	if ((string)ob->query("name")==HIC "玉佩" NOR) 
	{
	message_vision("\n$N猛的扬起头，用惊奇的眼光看着$n，说：\n"
	+"咦，这不是我的贴身玉佩吗，怎么你...\n",this_object(),me);
	}
	return 1; 
	}
	else
	{
	message_vision("\n$N缓缓地摇了摇头，柔声说道:不是小武送我的,我不要.\n"
	+"说罢垂下头来，咬了咬牙,幽幽嗔道：死小武，臭小武，为什么还不回来呢?\n",this_object());
	return 0;
	}
}

int do_name(string target)
{
	object me, dest, *all;
	int i;
 
	me = this_object();
	all = users();

	if(me->query("waiting_target"))
		return notify_fail("雍容：我现在正忙着哪，您呆会儿再来吧！\n");
	if( !this_player()->query_temp("fee_paid") ) 
		return notify_fail("雍容打了个呵欠，左手轻轻掩住樱桃小口，柔声道：\n"+
		"不好吧，帮你杀了人我又有什么好处呢？\n");
	if( !target || target==" ")
		return notify_fail("雍容打了个呵欠，左手轻轻掩住樱桃小口，柔声道：\n"
		+"请告诉我那人的名字，我可没功夫跟你闲聊。\n");
	for(i=0; i<sizeof(all); i++)
	{
		if( target == all[i]->name() || target == all[i]->id() )
			dest = all[i];
	}
	if( !dest )
		return notify_fail("雍容做了个鬼脸：不太好啊，好像他不在喔。\n");

	if (dest->is_ghost())
		return notify_fail("雍容说：你黑，你太黑，你太太黑，你太太太黑！他已经死啦！\n");
	me->set("waiting_target", dest->query("id"));
	me->set("target_name", target);
	me->delete("chat_chance");
	me->delete("chat_msg");
	message("vision",
	HIY "\n雍容正要离开，忽又回首道：你别走，就在这儿静侯佳音吧。\n" NOR,
	environment(), me );
	me->set("pursuer", 1);
	me->set("vendetta/authority", 1);
	me->set("bellicosity", 100000);
	message_vision("HIM $N走了出去。\n" NOR, me);
	call_out("do_chase", 1, me);
	return 1;
}

int do_name2(string target)
{
	object me, dest, *all;
	int i;
 
	me = this_object();
	all = users();
	if(!this_player()->query_temp("fee_paid2") ) 
		return notify_fail("雍容打了个呵欠，左手轻轻掩住樱桃小口，柔声道：\n"+
		"不好吧，那样做我又有什么好处呢？\n");
        if(!this_player()->query_temp("windnod2"))
		return notify_fail("\n雍容摇摇头，笑道：不好吧，打人的事小武不会同意的。\n");
        if( !target || target==" ")
		return notify_fail("雍容打了个呵欠，左手轻轻掩住樱桃小口，柔声道：\n"
		+"请告诉我那人的名字，我可没功夫跟你闲聊。\n");
	for(i=0; i<sizeof(all); i++)
	{
		if( target == all[i]->name() || target == all[i]->id() )
			dest = all[i];
	}
	if( !dest )
		return notify_fail("雍容做了个鬼脸：不太好啊，好像他不在喔。\n");
	if (dest->is_ghost())
		return notify_fail("雍容说：你好坏哟，他已经死啦！\n");
	me->set("waiting_target2", dest->query("id"));
        this_player()->delete_temp("windnod2");
        this_player()->delete_temp("fee_paid2");
	message("vision",
		HIM "\n雍容以袖掩口，笑道：嘻嘻，好像成了耶，你怎么谢我呀？\n" NOR,
		environment());
	call_out("do_faint", 1, me);
	return 1;
}

int do_chase(object me)
{
	
	object dest,room;
	dest = find_player(me->query("waiting_target"));
	if( !objectp(dest) || !environment(dest) )      
	{
		call_out("waiting", 0, me);
		return 1;
	}
	me->move(environment(dest));
	message_vision("$N笑嘻嘻地走了过来。\n" NOR, me);
	room = environment(this_object());
	if (room->query("no_fight"))
		room->set("no_fight", 0l);

	me->set_leader(dest);
	command("look " + dest->query("id"));
	if ( !environment(me)->query("no_fight"))
	{
		call_out("do_kill", 1, me, dest);
		return 1;
	}
	else
	{
		call_out("waiting", 0, me);
		return 1;
	}

	return 1;
}


int do_faint(object me)
{
	
	object dest,ob;
	dest = find_player(me->query("waiting_target2"));
	this_object()->move(environment(dest));
	message_vision("$N笑嘻嘻地走了过来。\n" NOR, me);
	message_vision(HIC "$N对$n说道：有人请我来打晕你，对不起啊。。。\n"
			+RANK_D->query_rude(dest)+"，你就认命吧！\n" NOR, me, dest);
        me->delete("waiting_target2");
        dest->unconcious();
	this_object()->move("/u/wind/workroom");
 	return 1;
}


int do_kill(object me, object dest)
{
	if( objectp(dest) && present(dest, environment(me))
		 && !environment(me)->query("no_fight"))
	{
		message_vision(HIR "$N对$n说道：小武要我来杀你，对不起啊。。。\n"
			+RANK_D->query_rude(dest)+"，你就认命吧！\n" NOR, me, dest);
			if(wizardp(dest))		
	                { 
			dest->set("immortal",0);
			command("aim "+dest->query("id"));
			command("shoot");
                	}
		me->set_leader(dest);
		me->kill_ob(dest);
		dest->fight_ob(me);
		call_out("checking", 0,  me);   
	}
	else call_out("waiting", 1, me);     
	return 1;
}

int waiting(object me)
{
	object dest;
	dest = find_player(me->query("waiting_target"));
	if ( objectp(dest) )
	{
		if (dest->is_ghost())
		{
			me->delete("waiting_target");
			call_out("do_back", 1, me);
			return 1;
		}else if (me->is_fighting() && present(dest, environment(me)))
		{
			call_out("checking", 0, me);
			return 1;
		}else if (living(me) && !environment(dest)->query("no_fight"))
		{
			call_out("do_chase", 0, me);
			return 1;
		}
	}               
	remove_call_out("waiting");
	call_out("waiting", 60, me);
    return 1;
}

int checking(object me)
{
	object ob;

	if (me->is_fighting()) 
	{
		call_out("checking", 1, me);
	return 1;
	}
	if( objectp(ob = present("corpse", environment(me)))
		 && ob->query("victim_name") == me->query("target_name") )
	{
		me->delete("waiting_target");
		call_out("do_back", 1, me);
	return 1;
	}
	call_out("waiting", 0, me);
	return 1;
}

int do_back(object me)
{

	me->move("/u/wind/workroom");
	message("vision", "雍容走了进来，幽幽道：唉，小武真不乖，害得我又杀了人。\n", 
		environment(), me );
	me->set_leader(0);
	set("chat_chance", 3);
	set("chat_msg", ({
		"雍容忽然做了个鬼脸，笑道: 真想溜出去玩会儿。\n",
		(: command("sing2") :),
		"雍容无聊地绕着手绢，叹道: 唉，一个人，真没意思。\n",
		"雍容伸出白玉雕成一般的小手，托着下巴说: 谁想和我说说话?\n",
		"雍容斩钉截铁地说: 嗯，谁要敢欺负我，我就宰了他！\n",
		"雍容忽然莞尔一笑道: 小武待会儿又要我杀谁呢？\n",
		"雍容打了个呵欠，左手轻轻掩住樱桃小口，柔声道：我困了。\n",
	}) );
	return 1;
}
*/
NPC_END;