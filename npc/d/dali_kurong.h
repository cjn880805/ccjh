//kurong.h
//code by zwb
//12-16
//inherit F_DEALER;

DALIBEN_BEGIN(CNDaLi_kurong);

virtual void create()
{
	set_name("苦容大师","ku rong");

	set("gender", "男性" );
	set("title", "天龙寺第十六代僧人");
	set("class", "bonze");
	set("long","他的面容奇特之极，看上去满是忧伤，仿佛人世间的悲哀都集中在他身上，这是修练苦容神功的后果");
	set("age", 100);
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
 	set("icon",old_monk);

	set("hp", 4000);
	set("max_hp", 12000);
	set("mp", 5000);
	set("max_mp", 5000);
	set("mp_factor", 50);
	set("combat_exp", 1000000);
	set("score", 1000000);
	set("book_count", 1);

	set_skill("force", 280);
	set_skill("dodge", 280);
	set_skill("parry", 280);
	set_skill("finger", 400);
	set_skill("sword", 280);
	set_skill("tianlong_shengong", 280);
	set_skill("tiannan_step", 280);
	set_skill("kurong_changong", 280);
	set_skill("duanjia_sword", 280);
	set_skill("liumai_shenjian", 280);
	set_skill("sun_finger", 280);
	set_skill("buddhism", 160);
	set_skill("literate", 160);
	set_skill("lm_shaoze", 160);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("parry", "liumai_shenjian");
	map_skill("finger", "liumai_shenjian");
	map_skill("sword", "duanjia_sword");
	prepare_skill("finger","liumai_shenjian");	

	set_inquiry("剃度", ask_join );
	set_inquiry("六脉剑阵", ask_six);
	set_inquiry("六脉神剑", ask_me );
	set_inquiry("六脉合一", ask_pot );
	create_family("大理段家",16,"高僧");

	carry_object("cheng_cloth")->wear();
};

static char * ask_pot(CNpc * this_object ,CChar * me)
{
	char msg[255];

	if(me->query_skill("liumai_shenjian") > 0)
		return "你都已经六脉合一了。";

	if (me->query_skill("lm_shaochong",1)>79 && me->query_skill("lm_zhongchong",1)>79 && me->query_skill("lm_shaoze",1)>79 && me->query_skill("lm_guanchong",1)>79 && me->query_skill("lm_shangyang",1)>79 && me->query_skill("lm_shaoshang",1)>79)
	{
		me->set_skill("liumai_shenjian",1);

	g_Channel.do_channel(&g_Channel, 0, "sys", 
		snprintf(msg, 255, "%s修习六脉剑气有成，六脉合一了。", me->name(1) ));

        return "既然六脉剑气都已修成，今日起便可六脉合一了！";
	}

	return "六脉剑气都未修全，谈什么六脉合一！";
}

static char * ask_me(CNpc * this_object ,CChar * this_player)
{
	
	this_player->add_temp("marks/ask_tempyyz", 1);

    if (this_player->query_temp("marks/ask_tempyyz") > 3 ) 
	{
		this_player->set_temp("pending/ask_ok", 1);
		this_player->delete_temp("marks/ask_tempyyz");
		return "这位施主果然聪明，施主若能胜过老衲就可得到六脉神剑谱。";        
	}
	this_player->set_temp("pending/ask_temp",0l);
	return "你说的我不清楚。";	
}

virtual int accept_fight(CChar * me)
{
    if(me->query_temp("pending/ask_ok") == 1) 
	{
		say("好吧，那我就同你切搓几招吧，点到为止。");
		me->delete_temp("pengding/ask_ok");
		SendMenu(me);
		
		remove_call_out(checking);
		call_out(checking, 1, me->object_id());
        return 1;
	}
	
	say("老朽已入空门，不作世俗之争。", me);
	SendMenu(me);
	
	return 0;
}

static void checking(CContainer * ob, LONG param1, LONG param2)
{

	CContainer * r = load_room("天龙寺牟尼堂");

	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);
//	char msg[255];

	if(! who) return;
	
    CChar obj;
    int my_max_hp, his_max_hp;
    my_max_hp  = me->query("max_hp");
    his_max_hp = who->query("max_hp");

    if (me->is_fighting()) 
    {
            me->call_out(checking, 2, param1);
            return;
    }

    if (( me->query("hp") * 100 / my_max_hp) <= 50 ) 
    {
        if (r->query_temp("about_yyz")==1)
		{
			me->say("施主身手果然不凡，老衲佩服。六脉神剑谱是没有的了，这本一阳指诀你先拿去吧。");
			CContainer * obj = load_item("sun_book"); 
			obj->move(who);
			r->set_temp("about_yyz",0l);
			//g_Channel.do_channel(me, NULL, "rumor", snprintf(msg, 255, "%s获得了一阳指诀啦。", who->name()));
			message_vision("$N交给$n一本书。", me, who);
		}
		else
			me->say("施主身手果然不凡，老衲佩服。不过书已经给人拿走了，让你白打一场，真过意不去。");
		return;
    }

    if (( who->query("hp") * 100 / his_max_hp) < 50 ) 
    {
        me->say("尘缘一切自心起，施主请回吧。");
        
        message_vision("$N对苦容大师恭恭敬敬地磕了一个头，离开牟尼堂。", who);
        who->move(load_room("天龙寺牟尼堂"));
        return;
    }

    return;
}

static char * ask_six(CNpc * me ,CChar * fighter)
{
	struct{
		char id[20];
		char name[20];
	}monks[] = {
		{"ben yin", "本阴"},
		{"ben can", "本残"},
		{"ben chen", "本尘"},
		{"ben guan", "本观"},
		{"ben xiang", "本相"},
		{"ku rong", "苦容大师"}};

	CMapping * skl = fighter->query_skills();
	static char msg[255];
	
	if ( skl->GetCount() <= 1)
		return snprintf(msg, 255, "%s功力不够，不够资格闯六脉剑阵。", query_respect(fighter));
		
	if( fighter->mini_skill() < 80)
		return snprintf(msg, 255, "%s，你这点本事也想闯六脉剑阵。", query_respect(fighter));
	
	if ( me->querystr("assigned_fighter")[0] )
		return snprintf(msg, 255, "%s，今日已有人挑战六脉剑阵，你过一段时间再来吧。", query_respect(fighter));

	me->say("好吧，你一会来般若台找我吧。");
	me->set("assigned_fighter", fighter->querystr("id"));
	
	message_vision("苦容大师往北离开。", fighter);

	CRoom * room = load_room("天龙寺般若台");
	CRoom * munitang = load_room("天龙寺牟尼堂");

	me->move(room);
	
	CChar * monk;

	if( ! (monk = (CChar *)munitang->present("ben yin")) )
	{
		me->move(munitang);
		message_vision("苦容大师走了过来。", fighter);
		return "真是对不起，本阴方丈不在，无法举行六脉剑阵。";
	}

	monk->move(room);
	message_vision("$N走了过来，跟$n俯耳轻声说了几句。", me, monk);
	message_vision("$N点了点头，快步走了出去。", monk);
	me->move(munitang);

	for(int j=2; j<6; j++) 
	{
		//me->move(room);

		if( ! (monk = (CChar *)munitang->present(monks[j - 1].id)) )
		{
	       // me->move(room);
        	//message_vision("苦容大师走了过来。", fighter);
			return snprintf(msg, 255, "真是对不起，%s不在，无法举行六脉剑阵。", monks[j - 1].name);	
		}
		monk->move(room);
		message_vision("$N走了过来，跟$n俯耳轻声说了几句。", me, monk);
		message_vision("$N点了点头，快步走了出去。", monk);
	}

	me->move(room);
	fighter->move(room);
	me->call_out(waiting, 1, 1);
	return "好！大家都出来了。";
}

static void waiting(CContainer * ob, LONG wait_time, LONG param2)
{
	CChar * me = (CChar * )ob;
	CChar * fighter;
	
	if( wait_time == 300 )
	{
		me->say( "苦容大师说道：看来他不会来了，我们回去罢！");
		me->call_out(do_back, 1);		
		return;
	}

	if( ! ( fighter = (CChar *)(me->environment())->present( me->querystr("assigned_fighter")) ) )
	{
		wait_time++;
		me->call_out(waiting, 1, wait_time);
		return;
	}

	me->call_out(preparing, 1, fighter->object_id());

	return;
}

static void preparing(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar * )ob;
	CChar * fighter = (CChar *)(ob->environment())->Present(param1);
	CFightRoom * obj;
	CChar * monk;
	CContainer * env = ob->environment();
	char msg[255];		

	struct{
		char id[20];
		char name[20];
	}monks[] = {
		{"ben yin", "本阴"},
		{"ben can", "本缺"},
		{"ben chen", "本谶"},
		{"ben guan", "本看"},
		{"ben xiang", "本香"},
		{"ku rong", "苦容大师"}}; 
	
	//检查房间内是否有战斗
	while( (obj = (CFightRoom *)env->present("fight_room")) )
		obj->End_Fight();

	tell_room(env, "苦容大师大声宣布：六脉剑阵合围！");
	tell_room(env, "只听四周声声佛号，天龙寺高僧们个个神情肃杀，慢慢地从摩尼堂中鱼贯步出，围住了通路。");
	if(! fighter)		//可能玩家在这时候离开，出现谈话对象失败的错误
	{
		me->call_out(do_back, 10);
		return;
	}
	else //秦波修改 2002、3、18
		tell_object(fighter, "苦容又道：准备，六脉剑阵即刻发动！");

	fighter->delete_temp("beat_count");
	fighter->set_temp("fighting", 1);

	obj = (CFightRoom *)env->present("fight_room_six");
	if(! obj) 
	{
		fighter = (CChar *)env->Present(param1);
		if(! fighter)		//玩家已经转移场景
		{
			me->call_out(do_back, 10);
			return;
		}
		
		me->command(snprintf(msg, 255, "chat 0 %s%s于今日挑战六脉剑阵！", fighter->querystr("title"), fighter->name()));

		obj = (CFightRoom *)load_item("fight_room");			//载入战斗精灵
		
		obj->set("room_locked", FIGHT_LOCKED);
		obj->set_name( "六脉剑阵", "fight_room_six");
		obj->move(env);
		fighter->move(obj);
		obj->Join_Team(fighter, CFightRoom::FIGHT_TEAM_B);
	}

	me->move(obj);
	CRoom * room = load_room("天龙寺般若台");
	for(int i=0; i<5; i++)
	{
		monk = (CChar *)room->present(monks[i].id);
		if(! monk)	//有罗汉不在
		{
			me->call_out(do_back, 10, 0);
			return;
		}
		
		monk->move(obj);
		//obj->Join_Team(monk, CFightRoom::FIGHT_TEAM_A);
	}
	
	monk = (CChar *)obj->present(monks[0].id);
	obj->Join_Team(monk, CFightRoom::FIGHT_TEAM_A);

	obj->Begin_Fight(0);	//战斗
	me->call_out(fighting, 1, 1);
}

static void fighting(CContainer * ob, LONG step, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env = me->environment();
	CFightRoom * obj = NULL;

	struct{
		char id[20];
		char name[20];
	}monks[] = {
		{"ben yin", "本阴"},
		{"ben can", "本缺"},
		{"ben chen", "本谶"},
		{"ben guan", "本看"},
		{"ben xiang", "本香"},
		{"ku rong", "苦容大师"}}; 

	if(EQUALSTR(env->querystr("base_name"), "fight_room") && EQUALSTR(env->querystr("name"), "六脉剑阵"))
		obj = (CFightRoom *)env;

	if(! obj)
	{
		//检查玩家是否已经闯过罗汉大阵。
		CChar * fighter = (CChar *)env->present(me->querystr("assigned_fighter"));
		if(! fighter || !living(fighter) || fighter->query_temp("beat_count") < 6)
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

	if(step < 6)
	{
		CChar * monk = (CChar *)obj->present(monks[step].id);
		if(! monk || obj->Join_Team(monk, CFightRoom::FIGHT_TEAM_A))
		{
			//monk->set_temp("fight/wait_point", 1);	//让和尚马上出手

			step++;
			tell_room(obj, "六脉剑阵急速地旋转着，一层层地向内收紧！");
		}
	}

	me->call_out(fighting, 1, step);	
////////////////////////////////////////////////////////////	

}

static void do_recruit(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *) ob;
	CChar * fighter = (CChar *)(me->environment())->Present(param1);
//	char msg[255];

	if(! fighter) return;

	fighter->delete_temp("beat_count");
	fighter->delete_temp("fighting");
	me->say("再接我一招！ ");
	g_Combatd.Do_Attack(me, fighter, CCombatd::TYPE_QUICK);

	if( !living(fighter) || fighter->query("hp") <= 1 )
		me->say("还是不行！");
	else
	{
		me->say("苦容大师说道：恭喜你闯过了六脉剑阵！ ");
		if (me->query("book_count") > 0)
			me->add("book_count", -1);
		CContainer * book = load_item("six_book");
		book->move(fighter);
		//g_Channel.do_channel(me, NULL, "rumor", snprintf(msg, 255, "%s拿到六脉神剑谱啦。", fighter->name()) );
		me->say("好吧，这本「六脉神剑谱」你就拿去吧。说着惨然一笑。");
	}

	me->call_out(do_back, 5);
}

static void do_back(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;

	tell_room(me->environment(), "苦容大师挥了挥手，回身步入牟尼堂。");

	//CRoom * room1 = load_room("/d/tianlongsi/banruotai");
	
	//room1->set("exits/north", "/d/tianlongsi/doushuai" );
	//room1->set("exits/south", "/d/tianlongsi/munitang");

	CRoom * room1 = load_room("天龙寺般若台");
	CRoom * room2 = load_room("天龙寺牟尼堂");
	CChar * monk;
	if( ( monk = (CChar *)room1->present("ben yin")) )
		monk->move(room2);
	if( ( monk = (CChar *)room1->present("ben can")) )
		monk->move(room2);
	if( ( monk = (CChar *)room1->present("ben chen")) )
		monk->move(room2);
	if( ( monk = (CChar *)room1->present("ben guan")) )
		monk->move(room2);
	if( ( monk = (CChar *)room1->present("ben xiang")) )
		monk->move(room2);

	me->del("assigned_fighter");
	me->move(room2);
}

static char * ask_join(CNpc * npc , CChar * player)
{
	if( EQUALSTR(player->querystr("class"), "bonze" ))
		return "阿弥陀佛！你我同是出家人，何故跟贫僧开这等玩笑？";

	if( DIFFERSTR(player->querystr("gender"), "男性") )
		return "阿弥陀佛！善哉！善哉！女施主若真心皈依我佛，可去后山庵里受戒。";

	player->set_temp("pending/join_bonze", 1);
	
	npc->say("阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请跪下受戒。",player);
	npc->AddMenuItem("下跪", "kneel", player);
	npc->AddMenuItem("离开", "", player);
	npc->SendMenu(player);

	return "";
}


virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(! ask) return 0;

	if(me->query_temp("pending/join_bonze"))
	{
		if(strcmp(ask, "kneel") == 0)
		{
			return do_kneel(me);
		}
		return 1;
	}

	return CNpc::do_talk(me, ask);
}



int do_kneel(CChar * me)
{
	char name[40], newname[40], msg[255];

	message_vision("$N双手合十，恭恭敬敬地跪了下来。$n说偈道：一微尘中入三昧，成就一切微尘定，而彼微尘亦不增，于一普现难思刹。”手掌提起，$N满头乌发尽数落下，头顶光秃秃地更无一根头发，便是用剃刀来剃亦无这等干净。",me, this);
	strncpy(name, me->name(1), 40);
	name[2] = 0;
	snprintf(newname, 40, "本%s", name);

	say(snprintf(msg, 255, "从今以后你的法名叫做%s。", newname), me);
	SendMenu(me);

	me->delete_temp("pending/join_bonze");
	me->set_name( newname);
	me->set("class", "bonze");
	me->set("K_record", me->query("pks") + me->query("mks"));
	me->set("shen_record", me->query("repute"));
    	me->set("repute", 0l);

	return 1;
}

virtual void attempt_apprentice(CChar * me)
{
	if( DIFFERSTR(me->querystr("gender"), "男性") )
	{
		say("阿弥陀佛！女施主呀，贫僧可不敢开这等玩笑啊。", me);
	}else if( DIFFERSTR(me->querystr("class"), "bonze") )
	{
		say("阿弥陀佛！贫僧不收『俗家弟子』。", me);
	}else if (me->query_skill("kurong_changong", 1) < 200)
	{
        say("你内功修为还不到火候，进天龙寺也是徒劳。", me);
    }else
	{
		say("阿弥陀佛，善哉！善哉！", me);
		recruit_apprentice(me);
	}

	SendMenu(me);
}

DALIBEN_END;




