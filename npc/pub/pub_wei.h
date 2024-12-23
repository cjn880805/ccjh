// pub_wei.c
// code by Fisho
// date:2000-12-17

VENDOR_BEGIN(CNpub_wei);

virtual void create()
{
	set_name("何芳芳",  "he fangfang");

	set("icon", young_man1);
	set("gender", "女性" );
	set("title", "丽春院老板娘");
//  set("nickname", "鹿鼎公");
	set("age", 42);
	set("long","她是当今六鼎公何小宝他娘虽是徐娘半老，但风韵犹存。");
	set("str", 25);
	set("dex", 25);
	set("con", 25);
	set("int", 25);
	set("shen_type", 1);
	set("combat_exp", 25000);
	set("attitude", "friendly");
	set("chat_chance", 5);
	
	set_skill("unarmed", 20);
	set_skill("force", 20);
	set_skill("dodge", 35);
	
	set("max_hp", 900);
	set("mp", 500);
	set("max_mp", 500);
	
	carry_object("flower_shoe")->wear();
	carry_object("pink_cloth")->wear();
	set("no_talk",1);
	set("no_huan",1);
}


int do_talk(CChar * me, char * ask = NULL)
{
	if(! strlen(ask))
	{
		AddMenuItem("向何芳芳请教关于何小宝的问题", "xiaobao",me);	
		AddMenuItem("向何芳芳请教关于丽春院的问题", "licuhn",me);

		if(me->query_temp("wei/renwu1") && !me->query("wei/renwu1"))
		{
			AddMenuItem("向何芳芳请教打听何小宝之事","renwu",me);
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "xiaobao") )
	{
		say( "那是我的乖儿子，长得就像你。",me);   
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "licuhn") )
	{
		if(me->query("age") < 16)
		{
			say("年纪这么小也敢逛窑子。",me);
		}
		else if(EQUALSTR(me->querystr("gender"), "女性"))
		{
			if(me->query_condition("prostitute") > 1)
			{
				say("跟老娘做事，亏不了你的！", me);
				AddMenuItem("赎身", "$0shushen $1", me);
			}
			else if(me->query("per") < 20)
			{
				say( "这年头，大姑娘也来逛窑子。可惜我儿子不在。",me);
			}
			else
			{
				say("看你也有几分姿色，愿意跟着老娘做事吗？", me);
				me->set_temp("pending/prostitute", 1);
				
				AddMenuItem("我愿意", "$0yes $1", me);
				AddMenuItem("不愿意", "", me);
			}
		}
		say( "我们丽春院可是扬州城里头一份的找乐子去处。",me);
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "renwu") )
	{
		if(me->query_temp("wei/renwu1") && !me->query("wei/renwu1"))
		{
			say("我那仔呀，自从七个老婆跑了以后，就没有过过安稳日子。一天到晚东奔西走的，到处找老婆，好不容易找到了，却一个个都不见他。",me);
			say("看到我的仔憔悴不堪的样子，我真是心疼呀！要是有谁能帮我的仔把老婆都找回来就好了！",me);
			me->set("wei/renwu1",1);
			CContainer * env = load_room("扬州丽春院");
			if(!env->query("小宝") )
			{
				env->set("小宝",1);
				CNpc * xiaobao = load_npc("pub_xiaogueizi");
				if(random(2))
					xiaobao->command("chat 0 $HIR“冻风有信，秋月无边，亏我思娇的情绪好比度日如年......”");
				else
					xiaobao->command("chat 0 $HIR“虽则我不是玉树临风，潇洒倜傥，但是我有广阔的胸襟和强劲的臂弯！”");
				destruct(xiaobao);
			}
		}
		else
			say("什么？",me);
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

char *chat_msg()
{
	switch(random(3))
	{
	case 0:
		return "何芳芳得意地说道：当年老娘我标致得很，每天有好几个客人。";
	case 1:
		return "何芳芳怒骂道：辣块妈妈，要是罗刹鬼、红毛鬼子到丽春院来，老娘用大扫帚拍了出去。";
	case 2:
		return "何芳芳对你说道：你一双眼睛贼忒嘻嘻的，真像那个喇嘛！";
	}
	return 0;
}

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && !is_fighting())
	{
		if(me->query("level")>30  && me->query("max_hp")>2500 && !me->query_temp("wei/renwu1") && !me->query("wei/renwu1"))
		{
			tell_object(me,"\n何芳芳自言自语道：“唉，我那可怜的仔，也不晓得上哪儿找他的七个老婆去了！”");
			me->set_temp("wei/renwu1",1);
		}
		remove_call_out(do_greeting);
		call_out(do_greeting, 3, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar * )ob;
	CChar * me = (CChar *)(npc->environment())->Present(param1);

	char msg[255];

	if(! me) return;
 	
    if (EQUALSTR(me->querystr("gender"), "无性") && EQUALSTR(( npc->environment())->querystr("base_name"), "扬州丽春院" )) 
	{
		message_vision("$N骂对着$n道：你当老娘是烂婊子吗？辣块妈妈，老娘满汉蒙藏回都接，就是不伺太监！", npc, me);
		
		tell_room(me->environment(),snprintf(msg,255,"%s被何芳芳一脚踢出门外。",me->name() ), me);
		me->move(load_room("扬州城"));
		tell_room(me->environment(),snprintf(msg,255,"%s被人从丽春院里踢了出来，栽倒在地上，磕掉两颗门牙。",me->name() ), me);
    }
    else 
	{
		if (EQUALSTR(me->querystr("class"), "bonze") )
		{
			message_vision(snprintf(msg,255,"$N笑道：呦，%s也来光顾我们丽春院啊。", query_respect(me)), npc);
		}

		if (EQUALSTR(me->querystr("gender"), "女性")) 
		{
			message_vision("$N说：哎呀，这年月大姑娘也逛窑子，成何体同。", npc);
		}

		npc->say("楼上楼下的姑娘们，客人来了！");

    }
}

int handle_action(char * comm, CChar * me, char *arg)
{
	char msg[255];

	if(is_fighting()) return 0;

	if(strcmp(comm, "sell") == 0)
	{
		CContainer * obj;

		obj = me->Present(atol(arg));
		if(! obj || !userp(obj) ) 
			return notify_fail("老娘只买「人」。你这是要给我什么东东？");

		return do_sell(me, (CChar *)obj);
	}

	if(strcmp(comm, "yes") == 0)
	{
		//卖身
		if(! me->query_temp("pending/prostitute"))
			return 0;
			
		me->set("value", me->query("per") * 40);
		g_Channel.do_channel(me, NULL, "rumor", snprintf(msg, 255, "%s自愿到丽春院卖春，身价%ld金币。", me->name(), me->query("value") ));
	
		message_vision("$N把决定跟着何芳芳做事。\n何芳芳开心大笑：老娘要发财了。", me);

		CMoney::Pay_Player(me, (me->query("value") ) * 50 / 100);
		make_prostitute(me);

		return 1;
	}

	if(strcmp(comm, "shushen") == 0)
	{
		LONG value = me->query_condition("prostitute") * 10 + me->query("value") * 10;
			
		say(snprintf(msg, 255, "加上我这些日子养你，培训你的费用，你得给我%ld金！", value), me);
		if(! CMoney::Player_Pay(me, value))
		{
			say("有客人来了，还是给我乖乖听话去！", me);
			SendMenu(me);
			return 1;
		}

		say("好了，你自由了！日后妈妈会想你的！", me);
		SendMenu(me);

		//赎身
		me->del("value");
		me->apply_condition("prostitute", 0);
		return 1;
	}

	return 0;
}

static void make_prostitute(CChar * me)
{
	me->move(load_room("扬州丽春院二楼") );//没有该场景
	me->set("start_city","扬州丽春院二楼");
	me->apply_condition("prostitute", 1200);
}

int do_sell(CChar * me, CChar * ob)
{
	char msg[255];

	if (ob->query_condition("prostitute") > 1)
		return notify_fail("这人已经是老娘的人了。你还敢来骗钱？");
	
	if(ob->query("age") < 16)
		return notify_fail("年纪太小身材还没成型，我不要。");

	if(DIFFERSTR(ob->querystr("gender"), "女性"))
		return notify_fail("老娘只买姑娘。");

	ob->set("value", ob->query("per") * 40);
	g_Channel.do_channel(me, ob, "rumor", snprintf(msg, 255, "%s被拐卖到丽春院了，不多不少，正好%ld金币。",ob->name(),ob->query("value") ));
	
	message_vision("$N把$n卖给何芳芳。\n何芳芳开心大笑：老娘要发财了。", me, ob);

	CMoney::Pay_Player(me, (ob->query("value") ) * 70 / 100);
	make_prostitute(ob);

	ob->set_temp("selled", 1);
	return 1;
}

int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	int i;
	int o;

	if (ob->query("is_task")==3)
	{
		i=ob->query("valued");
		o=random(i)+1;
		o=random(i)+1;

		if (who->query("repute")==0)
			o=0;
		if (who->query("repute")<0)
			o=-o;
		

		snprintf(msg, 255, "%s完成了阴阳合和散的任务，获得%d点经验，%d点声望！", who->name(1),i,o);

		g_Channel.do_channel(&g_Channel, 0, "sys",msg);

		tell_object(who,msg);

		who->add("combat_exp",i);
		who->add("repute", o);

		destruct(ob);
		return 1;
	}

	return 0;
}



VENDOR_END;



