//xuan_ku.h
//Lanwood 2000-01-09

char shaolin_xuan_ku_names[9][20] = {
	"chengguan luohan",
	"chengzhi luohan",
	"chengming luohan",
	"chengjing luohan",
	"chengjian luohan",
	"chengxing luohan",
	"chengji luohan",
	"chengmie luohan",
	"chenghe luohan",
};

NPC_BEGIN(CNshaolin_xuan_ku);

virtual void create()
{
	set_name("玄苦大师", "xuanku dashi");
	set("long",	"他是一位白须白眉的老僧，身穿一袭银丝棕黄袈裟。他身材瘦高，脸上满布皱纹，手臂处青筋绽露，似乎久经风霜。");
	
	set("foolid",105);	set("title", "少林罗汉堂主持");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
	set_weight(5000000);

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("hp", 3500);
	set("max_hp", 10500);
	
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 150);
	set("combat_exp", 800000);
	set("score", 1000000);

// before the modification, all the skills are 120
	set_skill("force", 120);
	set_skill("hunyuan_yiqi", 120);
	set_skill("dodge", 180);
	set_skill("shaolin_shenfa", 180);
	set_skill("parry", 120);
	set_skill("cuff", 185);
	set_skill("staff", 120);
	set_skill("blade", 120);
	set_skill("sword", 120);
	set_skill("luohan_quan", 180);
	set_skill("weituo_gun", 120);
	set_skill("xiuluo_dao", 120);
	set_skill("fumo_jian", 120);
	set_skill("buddhism", 120);
	set_skill("literate", 120);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("parry", "luohan_quan");
	map_skill("cuff", "luohan_quan");
	map_skill("staff", "weituo_gun");
	map_skill("blade", "xiuluo_dao");
	map_skill("sword", "fumo_jian");

	prepare_skill("cuff", "luohan_quan");

	create_family("少林派", 36, "弟子");

	set_inquiry("十八罗汉阵", ask_me);
	set("chat_chance_combat", 45);

	carry_object("jiedao")->wield();
	carry_object("jiasha")->wear();
}

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
		perform_action("force roar", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

static char * ask_me(CNpc * me, CChar * fighter)
{
	if( fighter->mini_skill() < 80) 
		return "你功力不够，不够资格闯罗汉大阵。";
	
	if( fighter->query("luohan_winner") )
		return 	"你已然闯过罗汉大阵，可不要拿老衲开这等玩笑。";

	if ( EQUALSTR(fighter->querystr("family/family_name"), "少林派")
		&& fighter->query("family/generation") != me->query("family/generation") + 2)
			return "你辈份不合，不够资格闯罗汉大阵。";

    if ( fighter->query("guilty") > 0 )
		return "你累犯数戒，身带重罪，我如何能准许你闯罗汉大阵！";

	if ( me->querystr("assigned_fighter")[0] )
		return "今日已有人挑战罗汉大阵，你过一段时间再来吧。";

	fighter->set_temp("xuanku_asked", 1);
	me->say("好吧，我来召集罗汉堂长老们于东练武场集合，我稍候在中央练武场上等你。");
	me->set("assigned_fighter", fighter->querystr("id")); 		
	
	if( !fighter->query_temp("xuannan_asked") )
		me->say("请你速去告知般若堂玄难大师，请他即刻招集般若堂诸罗汉于西练武场集合。");

    message_vision("玄苦大师往南离开。", fighter);

	me->move(load_room("room_void"));
	me->call_out(do_jihe, 5, fighter->object_id(), 1);	//5秒1步

	return 0;
}

//召集9位罗汉
static void do_jihe(CContainer * me, LONG param1, LONG step)
{
	CRoom * wuchang = load_room("少林寺练武场");
	char room_name[40];
	char msg[255];
	CRoom * r;
	CChar * monk;

	if(step == 10)
	{
		//全部召集完毕
		me->move(wuchang);
		tell_room(wuchang, "玄苦大师走了过来。");
        me->call_out(do_waiting, 1, 1);
		return;
	}
    
	snprintf(room_name, 40, "少林寺罗汉堂%s部", chinese_number(step, msg));
    r = load_room(room_name);
  		
	if(! (monk = (CChar *)r->present(shaolin_xuan_ku_names[step - 1])) )
	{
		CContainer * env = load_room("少林寺罗汉堂五部");
		me->move(env);
        tell_room(env, "玄苦大师走了过来。");
		tell_room(env, "玄苦大师说道：真是对不起，罗汉堂中有人不在，无法举行罗汉大阵。");
		return;
	}

    tell_room(r, snprintf(msg, 255, "玄苦大师走了过来，跟%s俯耳轻声说了几句。", monk->name()));
    monk->move(wuchang);
    tell_room(r, snprintf(msg, 255, "%s罗汉点了点头，快步走了出去。", monk->name()));
	tell_room(wuchang, snprintf(msg, 255, "%s走了过来。", monk->name()));

	me->call_out(do_jihe, 1, param1, step + 1);	
}

static void do_waiting(CContainer * me, LONG wait_time, LONG param2)
{
	CContainer * r = me->environment();
	CChar * fighter;

	if( wait_time == 300 )
	{
		tell_room(r, "玄苦说道：看来他不会来了，我们回去罢！");
		me->call_out(do_back, 1, 0);
		return;
	}

	if( ! (fighter = (CChar *)r->present(me->querystr("assigned_fighter")) ) )
	{
		me->call_out(do_waiting, 1, wait_time + 1);
		return;
	}

	if( ! r->present("xuannan dashi") || ! fighter->query_temp("xuannan_asked"))
	{
		if( random(10) == 0 ) 
			tell_room(r, "玄苦说道：去请了玄难大师没有？ 照理他现在该到了罢？");

		me->call_out(do_waiting, 1, wait_time + 1);
		return;
	}

	me->call_out(do_preparing, 1, fighter->object_id());
}
      
static void do_preparing(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env = ob->environment();
	CChar * me = (CChar *)ob;
	CFightRoom * obj;
	CChar * fighter;
	CChar * monk;
	char msg[255];		

	//检查房间内是否有战斗
	while( (obj = (CFightRoom *)env->present("fight_room")) )
		obj->End_Fight();

	tell_room(env, "玄苦大师大声宣布：东罗汉大阵合围！");
	tell_room(env, "只听四周响起沙沙的脚步声，东西十八位罗汉们个个神情肃杀，或赤手空拳，或手持兵器，慢慢地围了上来，堵住了通路。");
	tell_room(env, "准备，罗汉大阵即刻发动！");

	obj = (CFightRoom *)env->present("fight_room_18luohanzhen");
	if(! obj) 
	{
		fighter = (CChar *)env->Present(param1);
		if(! fighter)		//玩家已经转移场景
		{
			me->call_out(do_back, 10);
			return;
		}
		
		me->command(snprintf(msg, 255, "chat 0 %s%s于今日挑战少林十八罗汉大阵！", fighter->querystr("title"), fighter->name()));

		fighter->delete_temp("xuanku_asked");
		fighter->delete_temp("beat_count");
		
		obj = (CFightRoom *)load_item("fight_room");			//载入战斗精灵
		
		obj->set("room_locked", FIGHT_LOCKED);
		obj->set_name( "十八罗汉阵", "fight_room_18luohanzhen");
		obj->move(env);
		fighter->move(obj);
		obj->Join_Team(fighter, CFightRoom::FIGHT_TEAM_B);
	}

	me->move(obj);
	for(int i=0; i<9; i++)
	{
		monk = (CChar *)env->present(shaolin_xuan_ku_names[i]);
		if(! monk)	//有罗汉不在
		{
			me->call_out(do_back, 10, 0);
			return;
		}
		monk->move(obj);
	}

	//前个罗汉加入战队
	monk = (CChar *)obj->present(shaolin_xuan_ku_names[0]);
	obj->Join_Team(monk, CFightRoom::FIGHT_TEAM_A);

	obj->Begin_Fight(0);	//战斗
	me->call_out(do_fighting, 1, 1);	
}

static void do_back(CContainer * me, LONG step, LONG param2)
{
	char room_name[40];
	char msg[255];
	CRoom * r;
	CChar * monk;
	CContainer * env = me->environment();

	if(step == 10)
	{
		me->del("assigned_fighter");
		r = load_room("少林寺罗汉堂五部");
		me->move(r);
		tell_room(r, "玄苦大师走了过来。");
		return;
	}

	if(! step)
		tell_room(env, "玄苦大师挥了挥手， 罗汉堂长老们随即鱼贯离开练武场。");
	else
	{
       	snprintf(room_name, 40, "少林寺罗汉堂%s部", chinese_number(step, msg));
	    r = load_room(room_name);

        if( (monk = (CChar *)env->present(shaolin_xuan_ku_names[step - 1]) ))
		{
	         monk->move(r);
			 tell_room(r, snprintf(msg, 255, "%s走了过来。", monk->name()));
		}
	}
	
	me->call_out(do_back, 1, step + 1);
}

static void do_fighting(CContainer * ob, LONG step, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env = me->environment();
	CFightRoom * obj = NULL;

	if(EQUALSTR(env->querystr("base_name"), "fight_room") && EQUALSTR(env->querystr("name"), "十八罗汉阵"))
		obj = (CFightRoom *)env;

	if(! obj)
	{
		//检查玩家是否已经闯过罗汉大阵。
		CChar * fighter = (CChar *)env->present(me->querystr("assigned_fighter"));

		//如果玩家切换场景慢，可能找不到。
		if(! fighter && step < 20)
		{
			me->call_out(do_fighting, 2, step + 1);
			return ;
		}

		if(! fighter || !living(fighter) || fighter->query_temp("beat_count") < 18)
		{
			if(fighter) 
				fighter->delete_temp("beat_count");

			me->say("想不到 ... 唉！");
			g_Channel.do_emote(me, 0, "sigh", 0);
			me->call_out(do_back, 5);
			return;
		}
				
		me->call_out(do_recruit, 1, fighter->object_id());
		return;
	}

	if(step < 9)
	{
		CChar * monk = (CChar *)obj->present(shaolin_xuan_ku_names[step]);
		if(! monk || obj->Join_Team(monk, CFightRoom::FIGHT_TEAM_A))
		{
			//monk->set_temp("fight/wait_point", 1);	//让和尚马上出手

			step++;
			tell_room(obj, "罗汉大阵急速地旋转着，一层层地向内收紧！");
		}
	}

	me->call_out(do_fighting, 1, step);	
}

static void do_recruit(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * fighter = (CChar *)(me->environment())->Present(param1);

	if(! fighter)
	{
		me->call_out(do_back, 5);
		return;
	}

	fighter->delete_temp("beat_count");
	fighter->add("combat_exp", 7500);
	fighter->set("luohan_winner", 1);

	if (DIFFERSTR(fighter->querystr("family/family_name"), "少林派"))
	{
		g_Channel.do_emote(me, 0, "smile", 0);
		me->say("此番过阵，当对本身修行大有助益，百尺竿头，更进一步，老衲就此别过！");
		me->call_out(do_back, 5);
	}
	else
	{
        me->say("恭喜你闯过了十八罗汉大阵！ 本寺有此等杰出弟子，届时必当为武林放一异彩！");
		me->call_out(do_back, 30);
	}
}


virtual void attempt_apprentice(CChar * me)
{   
	char msg[255];
	static char titles[9][10] = {
		"金身罗汉",
		"妙音罗汉",
		"智慧罗汉",
		"贤善罗汉",
		"旃檀罗汉",
		"精进罗汉",
        "归真罗汉",
        "清净罗汉",
        "降龙罗汉",	
	};

	if ( DIFFERSTR(me->querystr("family/family_name"), "少林派"))
	{
		say("你与本派素无来往，不知此话从何谈起？", me);
		SendMenu(me);
		return;
	}

	if ( DIFFERSTR(me->querystr("class"), "bonze") && EQUALSTR(me->querystr("family/family_name"), "少林派")) 
	{
		say("你是俗家弟子，不能在寺内学艺。", me);
		SendMenu(me);
		return;
	}

	if ( me->query("family/generation") <= query("family/generation") )
	{
		say("这，贫僧哪里敢当 !", me);
		SendMenu(me);
		return;
	}

	char myname[5], prename[3];
	strncpy(myname, me->name(), 4)[4] = 0;
	strncpy(prename, myname, 2)[2] = 0;
	
	if ( ( me->query("family/generation") == query("family/generation") + 1) 
		&& strcmp(prename, "澄") == 0)
	{
		say(snprintf(msg, 255, "%s的徒弟怎麽跑到我这儿来了，哈哈哈 !", me->querystr("family/master_name")));
		command(snprintf(msg, 80, "recruit %ld", me->object_id()));
		me->set("title", snprintf(msg, 255, "少林罗汉堂座下 %s", titles[random(9)]));
		me->UpdateMe();
	}

	if ( me->query("family/generation") == query("family/generation") + 2 )
	{
		if ( me->query("luohan_winner") )
		{
			say("老衲垂死之年，又得一可塑之才，真是可喜可贺 !", me);

			char new_name[5];

			strcpy(new_name, "澄");
			new_name[2] = myname[2];
			new_name[3] = myname[3];
			new_name[4] = 0;

			me->set_name( new_name);
			say(snprintf(msg, 255, "从今以后你的法名叫做%s，恭喜你荣升为少林派澄字辈罗汉之一 !", new_name));
			command(snprintf(msg, 80, "recruit %ld", me->object_id()));
			me->set("title", snprintf(msg, 255, "少林罗汉堂座下 %s", titles[random(9)]));
			me->UpdateMe();
		}
		else
		{
			say("你没有闯过十八罗汉大阵，不能越级拜师。", me);
			SendMenu(me);
			return;
		}
	}
}

NPC_END;