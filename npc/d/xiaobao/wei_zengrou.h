// wei_zengrou.h 曾雪
// 秦波	2002、12、25

NPC_BEGIN(CNwei_zengrou);

virtual void create()
{
	set_name("曾雪", "zeng rou" );
	set("gender", "女性");
	set("icon", young_woman2);
	set("long",  "她长的极美，其容色晶莹如玉，娇媚不可方物。");
	set("age", 17);
	set("per",30);

	set("str", 25);
	set("dex", 16);
	set("combat_exp", 80000);

	set_skill("unarmed", 70);
	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);
	
	set("max_hp",5000);
	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);
	add_money((1+random(5))*1000);
	call_out(do_die, 900);	
	set("no_kill",1);
	set("no_huan",1);
}

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query_temp("wei/renwu6_3") && !me->query_temp("wei/renwu6_4") )
	{
		say("你看到曾雪颈间挂着一块褐色的玉佩。", me);
		me->set_temp("wei/renwu6_5",1);//看到曾雪颈间的玉佩
	}
	SendMenu(me);
	return 1;
}

void init(CChar *me)
{
	CNpc::init(me);
	if(userp(me) && me->query("wei/renwu1") && !me->query("wei/renwu7") && !query("ok") && !querystr("owner")[0])
	{
		if(me->query_temp("wei/renwu7_8"))
		{
			CContainer * env = load_room("长安押签房");
			CContainer * wei=env->present("yi lian");
			if(wei)
			{
				if(EQUALSTR(wei->querystr("owner"),me->id(1)))
				{
					tell_object(me, "\n$HIC曾雪对着依恋惊讶地「啊！」了一声。");
					tell_object(me, "$HIC曾雪越想越伤心，终于忍不住趴在依恋的肩膀上放声大哭起来。");
					tell_object(me, "$HIC依恋拍了拍曾雪的头。\n");
					me->set_temp("wei/renwu7_9",1);//曾雪见到了依恋
					me->set_temp("wei/renwu6_5",1);
				}
			}
		}
		else if(!me->query_temp("wei/renwu7_1"))
		{
			tell_object(me, "\n$YEL曾雪正与一群小流浪小混混押签赌钱。");
			tell_object(me, "$YEL看到你的到来，曾雪笑着说道：“一看这位朋友就是位贵人，要不要也来玩一把呀！”");
		}
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(!querystr("owner")[0] && !query("ok"))
	{
		char msg[255];
		if(me->query("wei/renwu1") && !me->query("wei/renwu7") )
		{
			if(me->query_temp("wei/renwu7_2_count")>0 && me->query_temp("wei/renwu7_3"))
			{
				if(! strlen(ask))
				{
					say(snprintf(msg, 255, "你细细一数桌面上的金币，发现还有%d枚。",me->query_temp("wei/renwu7_2_count")),me);
					AddMenuItem("拿走一枚","one",me);
					if(me->query_temp("wei/renwu7_2_count")>=2)
						AddMenuItem("拿走二枚","two",me);
					if(me->query_temp("wei/renwu7_2_count")>=3)
						AddMenuItem("拿走三枚","three",me);
					SendMenu(me);
				}
				else if(!strcmp(ask, "one") )
				{
					me->add_temp("wei/renwu7_2_count",-1);
					tell_object(me,snprintf(msg, 255,"\n$HIC你从桌面上拿走了1枚金币，桌面还剩%d枚金币。",me->query_temp("wei/renwu7_2_count")));
					do_play(me);
				}
				else if(!strcmp(ask, "two") && me->query_temp("wei/renwu7_2_count")>=2)
				{
					me->add_temp("wei/renwu7_2_count",-2);
					tell_object(me,snprintf(msg, 255,"\n$HIC你从桌面上拿走了2枚金币，桌面还剩%d枚金币。",me->query_temp("wei/renwu7_2_count")));
					do_play(me);
				}
				else if(!strcmp(ask, "three") && me->query_temp("wei/renwu7_2_count")>=3)
				{
					me->add_temp("wei/renwu7_2_count",-3);
					tell_object(me,snprintf(msg, 255,"\n$HIC你从桌面上拿走了3枚金币，桌面还剩%d枚金币。",me->query_temp("wei/renwu7_2_count")));
					do_play(me);
				}
			}
			else
			{
				if(! strlen(ask))
				{
					if(!me->query_temp("wei/renwu7_4"))
					{
						AddMenuItem("向曾雪询问游戏规则","gueize",me);
						if(me->query_temp("wei/renwu7_1"))
							AddMenuItem("与曾雪开始游戏","game",me);
					}
					else if(!me->query_temp("wei/renwu7_9"))
					{
						AddMenuItem("询问关于小宝","xiao_bao",me);
						if(me->query_temp("wei/renwu7_5") )
							AddMenuItem("询问心愿","xinyuan",me);
					}
					else
					{
						AddMenuItem("询问关于小宝","xiaobao",me);
						if(me->query_temp("wei/renwu6_5") && !me->query_temp("wei/renwu6_4") && !me->query_temp("wei/renwu6_6"))
							AddMenuItem("询问关于玉佩","yupei",me);
						if(me->query_temp("wei/renwu6_6") && !me->query_temp("wei/renwu6_4") && !me->query_temp("wei/renwu6_7"))
							AddMenuItem("询问关于方瑜","fang",me);
					}
					SendMenu(me);
				}
				else if(!strcmp(ask, "xiaobao")  && me->query_temp("wei/renwu7_9"))
				{
					if(me->query_temp("wei/renwu6_8"))
					{
						me->set_temp("wei/renwu7_10",1);//曾雪答应和你回家
						//CContainer * env = load_room("杭州六和塔");
						CContainer * env = me->environment();
						CContainer * wei1=env->present("yi lian");
						if(wei1)
						{
							tell_object(me,snprintf(msg, 255,"\n$HIC曾雪梨花带露，道：多谢%s帮我找到了依恋姐姐，了结了我的一份心愿。离家这么久了，整天和这些混混在一起戏耍也挺无聊，真的很想相公。。",query_respect(me)));
							tell_object(me,"$HIC依恋擦了擦曾雪脸上的眼泪，泯然一笑：那你还不快点回去找你的小老公去呀！小心那个花心大萝卜又给你多找了几个好姐妹哟！");
							tell_object(me,"$HIC曾雪破涕一笑：他要是再敢的话，苏姐姐不会饶他的。");
							tell_object(me,"$HIC仿佛曾雪想起了什么事情，不由笑了起来。\n");
							tell_object(me,"$HIC依恋拍了拍曾雪红起来的脸蛋，道：姐姐不耽误你回去见你相公了，有空的话我会去扬州去看看你的。");
							tell_object(me,"$HIC\n说罢，转身飘然离去。");
							destruct(wei1);
						}
						tell_object(me,"$HIC曾雪道：谢谢你化解了我们姐妹间的误会，我这就跟你去找小宝。。");
						tell_object(me,"$HIC曾雪决定跟随你行动。\n");
						set("owner",me->id(1));
					}
					else if(EQUALSTR(environment()->querystr("base_name"),"长安押签房" ))
					{
						CContainer * env = load_room("长安押签房");
						CContainer * wei1=env->present("yi lian");
						if(wei1)
						{
							me->set_temp("wei/renwu7_10",1);//曾雪答应和你回家
							tell_object(me,snprintf(msg, 255,"\n$HIC曾雪梨花带露，道：多谢%s帮我找到了依恋姐姐，了结了我的一份心愿。离家这么久了，整天和这些混混在一起戏耍也挺无聊，真的很想相公。。",query_respect(me)));
							tell_object(me,"$HIC依恋擦了擦曾雪脸上的眼泪，泯然一笑：那你还不快点回去找你的小老公去呀！小心那个花心大萝卜又给你多找了几个好姐妹哟！");
							tell_object(me,"$HIC曾雪破涕一笑：他要是再敢的话，苏姐姐不会饶他的。");
							tell_object(me,"$HIC仿佛曾雪想起了什么事情，不由笑了起来。\n");
							tell_object(me,"$HIC依恋拍了拍曾雪红起来的脸蛋，道：姐姐不耽误你回去见你相公了，有空的话我会去扬州去看看你的。");
							tell_object(me,"$HIC\n说罢，转身飘然离去。");
							tell_object(me,"$HIC曾雪决定跟随你行动。\n");
							
							destruct(wei1);
							
							CChar * wei = load_npc("wei_zengrou");
							wei->move(load_room("长安押签房"));
							wei->set("owner",me->id(1));
							wei->set_leader(me);
							move(load_room("temp_zr"));
						}
					}
				}
				else if(!strcmp(ask, "yupei")  && me->query_temp("wei/renwu6_5") && !me->query_temp("wei/renwu6_4"))
				{
					me->set_temp("wei/renwu6_6",1);//曾雪说明玉佩的来历
					say("曾雪道：离开小桂子后，我四处与人赌钱为乐，期间有输有赢，倒也没有出什么事。",me);
					say("曾雪道：未曾想有一日不慎输给了关外四恶，而我身边又无长物可抵输银，关外四恶正欲对我下毒手，正好依恋路过，她不知从何处找来找来了这块玉佩交给关外四恶抵了我的输银。",me);
					say("曾雪道：后来，我又想办法从关外四恶手里偷回了这块玉佩，并一直保留在身边。",me);
					SendMenu(me);
				}
				else if(!strcmp(ask, "fang")  && me->query_temp("wei/renwu6_6") && !me->query_temp("wei/renwu6_4"))
				{
					me->set_temp("wei/renwu6_7",1);//曾雪去和方瑜解释
					tell_object(me,"\n$HIR曾雪大吃一惊：啊！！原来这块玉佩是方姐姐的，为了我，还害得依恋姐姐和方瑜姐姐结仇！");
					tell_object(me,"$HIR曾雪没做犹豫，说道：都怪我不好，我和方姐姐去解释！");
					tell_object(me,"$HIC曾雪决定跟随你行动。\n");

					CChar * wei = load_npc("wei_zengrou");
					wei->move(load_room("长安押签房"));
					//wei->set("owner",me->id(1));
					wei->set_leader(me);
					move(load_room("temp_zr"));
					
				}
				else if(!strcmp(ask, "xiao_bao")  && me->query_temp("wei/renwu7_4"))
				{
					me->set_temp("wei/renwu7_5",1);//曾雪说有心愿未了
					say("曾雪叹道：既然我已经输给你了，本应该立即跟你走的。只不过我有一件未了的心愿，如果你能帮我达成，我自然没有二话。",me);
					SendMenu(me);
				}
				else if(!strcmp(ask, "xinyuan")  && me->query_temp("wei/renwu7_5"))
				{
					me->set_temp("wei/renwu7_6",1);//帮曾雪寻找依恋
					say("曾雪叹道：依恋曾救我一命，如今想要一偿救命之恩，却无处可寻侠女踪迹！",me);
					say("曾雪道：只是平时和这些混混在赌钱的时候，听说岳廊附近她可能出现过。",me);
					SendMenu(me);
				}
				else if(!strcmp(ask, "gueize") )
				{
					me->set_temp("wei/renwu7_1",1);//向曾雪询问游戏规则
					tell_object(me,"\n$HIC“我们来个新玩法，”曾雪从腰间钱袋里取出一把金币。");
					tell_object(me,"$HIC“这儿是三十五币金币，我把它们丢到桌上，然后随机取走其中一半以下的金币。”");
					tell_object(me,"$HIC“如果随机取走的这一部份钱是单数，就由你开始拾钱，反之则由我开始拾钱。”");
					tell_object(me,"$HIC“每个人一次最多只允许拾三枚金币，最少也必须拾一枚金币。”");
					tell_object(me,"$HIC“最后一枚金币由谁拾起，就算谁赢。”");
					tell_object(me,"$HIC“如果我赢了，你要付我20000金币，如果我输了，我将为你做一件事情！”");
				}
				else if(!strcmp(ask, "game") )
				{
					if(!me->query_temp("wei/renwu7_2"))
					{
						char msg[255];
						say(snprintf(msg, 255, "曾雪笑道：不是我不相信%s您，不过钱您还是先拿出来放在我这里比较合适。",query_respect(me)),me);
						SendMenu(me);
					}
					else
					{
						say("曾雪笑道：那我们就开始吧！",me);
						SendMenu(me);
						do_play(me);
					}
				}
			}
			return 1;
		}
	}
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(!querystr("owner")[0] && !query("ok"))
	{
		if(me->query("wei/renwu1") && !me->query("wei/renwu7") 
			&& me->query_temp("wei/renwu7_1") && !me->query_temp("wei/renwu7_2"))
		{
			if ( EQUALSTR(ob->querystr("id"), "coin") && ob->query("value") ==20000 )
			{
				me->set_temp("wei/renwu7_2",1);//预付曾雪20000
				destruct(ob);
				return 1;
			}
		}
	}
	return 0;
}

void do_play(CChar * me)
{
	char msg[255];
	int index,count;
	if(!me->query_temp("wei/renwu7_3"))
	{
		tell_object(me,"\n$HIR曾雪将手中的金币往桌面上一仍，随手从桌旁拿起一根细长的签，从金币堆中一划，轻轻一拨，顿时，金币堆一分为二。");
		tell_object(me,"$HIR曾雪笑道：“我们就以左边这堆来赌一回吧！");
		count=random(7)+20;
		me->set_temp("wei/renwu7_2_count",count);//本局游戏桌面还剩的金币数
		me->set_temp("wei/renwu7_3",1);//游戏开始
		tell_object(me,snprintf(msg, 255, "$HIR你凑过去细细一数，左边这堆的金币还有%d枚。",count));
		if(int(count/2)*2!=count)
			tell_object(me,snprintf(msg, 255, "$HIR曾雪笑道：“%s，是单数，你先请！”\n",query_respect(me)));
		else
		{
			tell_object(me,snprintf(msg, 255, "$HIR曾雪笑道：“%s，是双数，我先拿了！”\n",query_respect(me)));
			index=random(3)+1;
			tell_object(me,snprintf(msg, 255,"\n$HIC曾雪从桌面上拿走了%d枚金币。",index));
			me->add_temp("wei/renwu7_2_count",-index);
		}
	}
	else
	{
		//判断胜负
		if(!me->query_temp("wei/renwu7_2_count"))//你赢了
		{
			me->delete_temp("wei/renwu7_2_count");
			me->delete_temp("wei/renwu7_2");
			me->delete_temp("wei/renwu7_3");
			me->set_temp("wei/renwu7_4",1);//游戏胜利
			tell_object(me,"\n$HIR曾雪长叹了一声：“唉，看来这就是命运，说吧，你要我做什么？”\n");
		}
		//如没决出胜负的话，曾雪开始拿，并遵循四倍减一的规则正确取金币
		else
		{
			count=me->query_temp("wei/renwu7_2_count");
			for(int i=7;i>=1;i--)
			{
				if(count>4*i)
				{
					index=count-4*i;
					break;
				}
				else if(count==4*i)
				{
					index=random(3)+1;
					me->set_temp("wei/renwu7_2_error",1);
					break;
				}
				else
				{
					if(i==1)
						index=count;
					else
						continue;
				}
					
			}
			me->add_temp("wei/renwu7_2_count",-index);
			if(!me->query_temp("wei/renwu7_2_error"))
				tell_object(me,snprintf(msg, 255,"\n$HIC曾雪想了想，微微一笑，从桌面上拿走了%d枚金币。",index));
			else
			{
				tell_object(me,snprintf(msg, 255,"\n$HIC曾雪皱了皱眉头，沉思许久，叹了一口气，从桌面上拿走了%d枚金币。",index));
				me->delete_temp("wei/renwu7_2_error");
			}
			if(!me->query_temp("wei/renwu7_2_count"))//你输了
			{
				me->delete_temp("wei/renwu7_2_count");
				me->delete_temp("wei/renwu7_2");
				me->delete_temp("wei/renwu7_3");
				tell_object(me,snprintf(msg, 255, "\n$HIR曾雪笑道：“%s，你输了，钱我就不客气的收下了！”\n",query_respect(me)));
			}
		}
	}
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->query("ok"))
		destruct(npc);
	else
		npc->call_out(do_die, 900);
}

NPC_END;