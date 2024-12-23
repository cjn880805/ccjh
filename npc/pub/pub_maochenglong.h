//pub_maochenglong.h
//秦波 2002-11-20

NPC_BEGIN(CNpub_maochenglong);

virtual void create()
{	
	set_name("毛成龙", "mao chenglong");
	set("title", "御史");
	set("gender", "男性");
	set("icon", officer);
	set("age", 58);
	set("per", 20);

	set("combat_exp", 7000000);
	set("shen_type", 1);
	
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 15);
	
	set("hp",100000);
	set("max_hp", 100000);
	set("mp", 15000);
	set("max_mp", 15000);
	set("mp_force", 100);

	set_skill("force", 250);
	set_skill("taiji_shengong", 250);
	set_skill("dodge", 250);
	set_skill("tiyunzong", 250);
	set_skill("unarmed", 250);
	set_skill("taiji_quan", 250);
	set_skill("parry", 250);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_quan");

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 100);

	set_temp("apply/no_黯然消魂", 1);
	set("no_chan",1);
	set("bigboss",1);

	set("env/wimpy", 100); 
	set("task_open", 1);	//任务开放
	set("long", "他是朝廷御史，有向皇上进谏官吏贪污不法及朝廷弊病之责。");

	call_out(do_die, 1800);

	set("no_kill",1);
	set("no_huan",1);
}

void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting() )
	{
		if(!me->query("zhang/renwu5"))//闲人一律赶走
		{
			message_vision("$n对$N大怒说道：你是何人，竟然深夜只身硬闯本府？来人呀，于我打将出去！", me, this);
			me->move(load_room("佛山北帝庙"));
		}
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(query("task_open") && me->query("zhang/renwu5"))
	{
		switch(me->query("zhang/renwu5"))
		{
		case 1://说降毛成龙
			if(!me->query("zhang/renwu5_ok"))
			{
				switch(me->query_temp("zhang/毛成龙"))
				{
				case 0:
					AddMenuItem("毛大人好", "$0ask_renwu50 $1", me);
					break;
				case 1:
					AddMenuItem("在下是谁不重要", "$0ask_renwu51 $1", me);
					break;
				case 2:
					AddMenuItem("在下岂敢以说客自居", "$0ask_renwu52 $1", me);
					break;
				case 3:
					AddMenuItem("毛大人此言不差", "$0ask_renwu53 $1", me);
					break;
				case 4:
					AddMenuItem("毛大人又错了", "$0ask_renwu54 $1", me);
					break;
				}
				AddMenuItem("和他没什么好说的", "$0ask_end $1", me);
			}
			else if(me->query("zhang/renwu5_ok")==1)
			{
				say("毛成龙大泣叩首道：先生之言，如醍醐灌顶！成龙受教了！成龙险些作了千古罪人！张相！今后毛成龙这条命就是您的了！！！",  me);
			}
			else
			{
				say("毛成龙道：......",  me);
			}
			break;
		case 2:
			break;
		case 3://前来威胁毛成龙
			if(!me->query("zhang/renwu5_ok"))
			{
				AddMenuItem("毛大人,令公子现在可好？", "$0ask_renwu56 $1", me);
				AddMenuItem("和他没什么好说的", "$0ask_end $1", me);
			}
			else
			{
				say("毛成龙含泪说：告诉张居中，毛某认栽了，明日早朝，老夫就会递上奏章，告老还乡。",  me);
			}
			break;
		case 4://前来暗杀毛成龙
			break;
		}
		SendMenu(me);	
		return 1;
	}
	else
	{
		message_vision("$n对$N大怒说道：你是何人，竟然深夜只身硬闯本府？来人呀，于我打将出去！", me, this);
		me->move(load_room("佛山北帝庙"));
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

virtual int do_look(CChar * me)
{
	if(query("task_open") )
	{
		say("御史 毛成龙(mao chenglong) 他是朝廷御史，有向皇上进谏官吏贪污不法及朝廷弊病之责。",me);
		if(!me->query("zhang/renwu5_ok") && me->query("zhang/renwu5")==4)//前来暗杀毛成龙
		{
			AddMenuItem("暗杀毛成龙", "$0ask_renwu58 $1", me);
		}
		SendMenu(me);
	}
	return 1;
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(query("task_open") && me->query("zhang/renwu5"))
	{
		if(!strcmp(comm, "ask_end") )
			return 1;
		if(!strcmp(comm, "kill") )
		{
			if(me->query("zhang/renwu5")==4)
				return do_kill(me);
			else
				return 1;
		}
		switch(me->query("zhang/renwu5"))
		{
		case 1://说降毛成龙
			if(!me->query("zhang/renwu5_ok"))
			{
				if(!strcmp(comm, "ask_renwu50") )
				{
					me->set_temp("zhang/毛成龙",1);
					say("你向毛成龙行了一个礼：毛大人好。",  me);
					say("毛成龙道：阁下是何人竟然深夜只身硬闯本府？",  me);
					SendMenu(me);
					return 1;
				}
				else if(!strcmp(comm, "ask_renwu51") )
				{
					me->set_temp("zhang/毛成龙",2);
					say("你道：在下是谁不重要，大人只要知道在下是为大人的前程而来便可。",  me);
					say("毛成龙道：那你便是张居中的说客咯？",  me);
					SendMenu(me);
					return 1;
				}
				else if(!strcmp(comm, "ask_renwu52") )
				{
					me->set_temp("zhang/毛成龙",3);
					say("你道：在下岂敢以说客自居，只是常在张相身旁，看张相肩挑九州山河，心系亿兆民众，分皇上之忧解百姓之难。数十年如一日，五更起，三更息。批阅奏折上千万，处理事务难以数计。",  me);
					say("你道：吾常劝张相爱惜身体，张相却往往以诸葛武侯自比，谓‘不能及孔明之材，但求鞠躬尽力，死而后已八字而已。如有一时一刻之松懈，老臣有何面目见先帝于九泉之下。’",  me);
					say("你道：如此恒臣，毛大人何故联党参之？",  me);
					say("毛成龙冷笑道：自古权臣，那位不是能吏？窃汉之曹操，乱唐之李林甫，弱宋之蔡京。那位不是能力出众之辈。非有过人之才，不能行夺国之事！",  me);
					SendMenu(me);
					return 1;
				}
				else if(!strcmp(comm, "ask_renwu53"))
				{
					me->set_temp("zhang/毛成龙",4);
					say("你道：毛大人此言不差，然而权臣却并非奸臣！曹操欺献帝，李林甫进谗唐玄宗，蔡京卖宋土。此皆奸臣！",  me);
					say("你道：而张大人统群臣，扶幼主，虽然权倾天下却不以之谋私，家中余财仅二十两。大人亦无一房姬妾，原配罗氏尚穿麻衣，所着都由自己织出！",  me);
					say("你道：大人忍心参之乎？",  me);
					say("毛成龙沉吟半晌道：那朝中净是张相一党作和解释，作臣子私下结党必有祸心。",  me);
					SendMenu(me);
					return 1;
				}
				else if(!strcmp(comm, "ask_renwu54"))
				{
					me->delete_temp("zhang/毛成龙");
					if(!me->query("zhang/renwu5_ok"))
						me->set("zhang/renwu5_ok",1);
					say("你道：毛大人又错了，张相当政数十年，又有伯乐之才，识人无数，用人无数。不结党而自成党啊！",  me);
					say("你道：张相数次想归隐田园，但奈何幼主尚弱，朝中若无亲信逼遭奸臣欺压。张相又往往念及先皇重托与天下苍生。才仅以身代。",  me);
					say("你道：张相实是护主卫国之权臣，而非欺主夺国之奸臣啊！张相之权，无一无不是皇上之权！！！",  me);
					say("毛成龙大泣叩首道：先生之言，如醍醐灌顶！成龙受教了！成龙险些作了千古罪人！张相！今后毛成龙这条命就是您的了！！！",  me);
					SendMenu(me);
					return 1;
				}
			}
			break;
		case 2:
			break;
		case 3://前来威胁毛成龙
			if(!me->query("zhang/renwu5_ok"))
			{
				if(!strcmp(comm, "ask_renwu56") )
				{
					say("毛成龙怒道：你们竟然绑架老夫孩子！太卑鄙了！也罢，告诉张居中，算毛某认栽了，把孩子还给我吧！",  me);
					me->set_temp("zhang/绑架",1);
					SendMenu(me);
					return 1;
				}
			}
			break;
		case 4://前来暗杀毛成龙
			if(!me->query("zhang/renwu5_ok"))
			{
				if(!strcmp(comm, "ask_renwu58")  )
				{
					if(!me->query_temp("zhang/暗杀"))
					{
						tell_object(me,"\n$HIC借着昏暗的灯火，你只见书房的桌案前一个仪观威严的老者正在持笔疾书，似乎正在写着一本奏折。");
						tell_object(me,"$HIC你缓缓从隐身之处走了出来，阴恻恻的冷哼：毛大人，这么晚了，你也该休息休息了。");
						tell_object(me,"$HIC老者大惊，连声呼到：你是何人，竟然深夜只身硬闯本府？来人呀，有刺客！\n");
						me->set_temp("zhang/暗杀",1);
					}
					return do_kill(me);
				}
			}
			break;
		}
		return CNpc::handle_action(comm, me, arg);
	}
	return 1;
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	if(who->is_busy())
		return notify_fail("你上一个动作还没有完成");

	if (EQUALSTR(ob->querystr("name"), "毛成龙幼子") && ob->query("zhang"))
	{	
		if(who->query_temp("zhang/绑架") && who->query("zhang/renwu5")==3 && !who->query("zhang/renwu5_ok"))
		{
			tell_object(who,"\n$HIC毛成龙含泪说：告诉张居中，毛某认栽了，明日早朝，老夫就会递上奏章，告老还乡。");
			tell_object(who,"$HIC你哈哈大笑：大人此话言重了，不过回乡安享天伦之乐对大人而言也不失为明智之策。小人告辞了！\n");
			who->delete_temp("zhang/绑架");
			who->set("zhang/renwu5_ok",3);
			destruct(ob);
			return 1;
		}
	}
	return 0;
}

int do_kill(CChar * me)
{
	if(me->query_temp("zhang/暗杀"))
	{
		CFightRoom * obj;
		CChar * baobiao;
		CContainer * env = environment();

		obj = (CFightRoom *)load_item("fight_room");		
		
		obj->set_name( "暗杀毛成龙的战斗", "fight_room");		
		obj->move(env);
		
		me->move(obj);
		obj->Join_Team(me, CFightRoom::FIGHT_TEAM_A);

		for(int i=0;i<3;i++)
		{
			baobiao = load_npc("pub_mao_huyuan");
			baobiao->move(obj);
			obj->Join_Team(baobiao, CFightRoom::FIGHT_TEAM_B);				
		}
		move(obj);
		obj->Join_Team(this, CFightRoom::FIGHT_TEAM_B);
		obj->Begin_Fight(0);
	}
	return 1;
}

void die()
{
	CChar *	me = (CChar *)find_object(query_temp("last_damage_from"), 1);
	if(me)
	{
		if(me->query("zhang/renwu5")==4 && me->query_temp("zhang/暗杀"))
		{
			me->set("zhang/renwu5_ok",4);
			me->delete_temp("zhang/暗杀");
			tell_object(me,"\n$HIR毛成龙嘴角流出一缕鲜血，含恨道：你这恶贼，回去告诉你的主子，老夫就算死后也不会放过他的，让他睡觉的时候小心！哈哈。。。\n");
		}
	}
	CNpc::die();
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	destruct(me);
}

NPC_END;




