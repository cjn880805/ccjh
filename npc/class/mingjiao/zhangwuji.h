//zhangwuji.h
//Lanwood 2000-01-09
//修改：增加铁焰令

ZUSHI_BEGIN(CNmingjiao_zhangwuji);

virtual void create()
{
	set_name("张无敌",  "zhang wudi");
	set("long", "明教教主张无敌，统领天下十万教众，豪气干云，叱咤千秋，「九阳神功」、「乾坤大挪移」独步天下，是江湖中不世出的少年英雄。");
    set("title","明教第三十四代教主");
	set("gender", "男性");
    set("age", 20);
	set("shen_type",1);
//	set("attitude", "friendly");
	set("icon",young_man4);
	set_weight(50000000);

    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);

    set("hp", 12000);
    set("max_hp", 12000);
    
    set("mp", 10000);
    set("max_mp", 10000);
    set("mp_factor", 120);

    set("combat_exp", 17000000);
    set("score", 455000);
    
    set_skill("force", 330);
    set_skill("dodge", 280);
    set_skill("parry", 280);
	set_skill("unarmed", 300);
    set_skill("jiuyang_shengong", 330);
	set_skill("lingfa", 300);
	set_skill("shenghuo_lingfa", 300);
	set_skill("qiankun_danuoyi", 300);
	set_skill("shenghuo_xinfa", 280);
	map_skill("parry", "qiankun_danuoyi");
	map_skill("force", "jiuyang_shengong");
	map_skill("dodge", "qiankun_danuoyi");
	map_skill("lingfa", "shenghuo_lingfa");

    create_family("明教",34, "教主");
	set("chat_chance", 5);
	set("chat_chance_combat", 10);
//	prepare_skill("lingfa", "shenghuo_lingfa");

	set("chat_chance", 5);
	set("chat_chance_combat", 10);

	set("apply/armor", 100);
    set("apply/damage", 100);
	set("no_chan",1);
	set("shen_type", 1);

	carry_object("shenghuo_ling")->wield();
    carry_object("baipao")->wear();
	set("no_talk",1);
	set("no_huan",1);
	
};

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("was/renwu2_1") && !me->query_temp("was/renwu2_2") )
	{
		AddMenuItem("向张无敌询问有关营救六大门派", "$0liupai $1", me);
		SendMenu(me);
		me->set_temp("was/renwu2_11",1);
		return 1;
	}
	if(EQUALSTR(me->querystr("party/party_name"), "明教"))
	{
		if(strcmp(ask, "掌门") == 0)
		{
			const char * ptr = ask_zhangmen(this, me);
			if(ptr)
			{
				say(ptr, me);
				SendMenu(me);
			}			
			return 1;
		}

		me->set_temp("pending/jiaozhu", 1);
		AddMenuItem("向教主询问乾坤大挪移", "$0qiankun $1", me);
		AddMenuItem("向教主索要铁焰令", "$0tieyan $1", me);
		AddMenuItem("向教主请求掌门之位", "掌门", me);
		AddMenuItem("向教主领取护教任务奖励", "$0hujiao $1", me);
		SendMenu(me);
		return 1;
	}

	return CNpc::do_talk(me, ask);
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query_temp("was/renwu2_11"))
	{
		if(me->query_temp("was/renwu2_1") && !me->query_temp("was/renwu2_2") )
		{
			CContainer * linpai=me->present("lei ting lin");
			if(!strcmp(comm, "liupai") 
				&& linpai && EQUALSTR(linpai->querystr("owner"),me->id(1)))
			{
				say("张无敌：“据我所知六大门派的高手都中了十香软筋散的毒且被困于万安寺内。万安寺的所在十分隐秘，我已在山下准备了车马前往。”",me);
				me->set_temp("was/renwu2_2",1);//获取万安寺一日游观光套票
				CContainer * obj = load_item("baozi");
				obj->set_name("万安寺一日游观光套票","guan guang piao");
				obj->set("long","这是一张薄薄的纸片，上面写着“万安寺一日游观光套票”的字样。");
				obj->set("owner",me->id(1));
				obj->set("was/menpiao",1);
				obj -> move(me);
				tell_object(me, "张无敌给你数量1的$HIC「万安寺一日游观光套票」$COM。");
			}
			else
				say("张无敌：“你想问些什么？？”",me);
			SendMenu(me);
			return 1;
		}
	}
	if(me->query_temp("pending/jiaozhu"))
	{
		if(strcmp(comm, "qiankun") == 0)
			return do_qiankun(me);
		if(strcmp(comm, "tieyan") == 0)
			return do_tieyan(me);
		if(strcmp(comm, "hujiao") == 0)
			return do_hujiao(me);
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
	return CNzushi::handle_action(comm, me, arg);
}


virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		perform_action("force recover", 0);
		break;
	case 1:
		perform_action("force heal", 0);
		break;
	}

	return 0;
}

virtual char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
			perform_action("lingfa duo", 1);
			break;
	case 1:
			perform_action("lingfa xiyanling", 1);
			break;
	case 2:
			perform_action("force recover", 0);
			break;
	}

	return 0;
}

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) &&  !is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(!who ) return;

	if( who->query("repute")<-5000)
	{
		me->say("魔从心起，于武学不利，其道必诛，劝君放下屠刀，立地成佛.");
	}
	else if(who->query("repute")<-100)
	{
		me->say("这位朋友，人行江湖，言行当正，切务走进邪魔歪道.");
	}
	else if(who->query("repute")>=0)
	{
		me->say("光明正道任人走，劝君多加保重.");
	}
	else if(who->query("repute")>20000)
	{
		me->say("大侠在上，受无忌一礼，大侠它日必为武林翘楚.");
	}

	return;
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if(me->querymap("family") && DIFFERSTR(me->querystr("family/family_name"), "明教"))
	{
		say("你已经加入其他门派，请回吧。", me);
		SendMenu(me);
		return;
	}

	if(DIFFERSTR(me->querystr("party/party_name"), "明教"))//别帮的不收
	{
		say("阁下与本教素无来往，请回吧。", me);
		SendMenu(me);
		return;
	}

	if(me->query_int() < 30)
	{
		say("你的悟性太低了，不适合学习我的功夫。", me);
		SendMenu(me);
		return;
	}

	if(me->query_skill("force", 1) < 150)
	{
		say("你的基本内功太低了，学习我的功夫会伤及自身。", me);
		SendMenu(me);
		return;
	}

	if(me->query("repute") < 30000)
	{
		say("你应当多作些行侠仗义的事，以修身心。", me);
		SendMenu(me);
		return;
	}

	if(me->query("party/level") < 5)
	{
		say("你入教时间尚短，无甚建树，如果有紫衫龙王的同意，我会考虑收下你的。", me);
		SendMenu(me);
		return;
	}

	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
        
	me->set("party/level", 6);
	me->set("title", "明教教主亲传弟子");
	say("好，我就收下你这位好兄弟", me);
	say("再接再砺！", me);
	SendMenu(me);
	return;
}

/*
int accept_fight(object ob)
{
    if(((int)ob->query("combat_exp")<30000)&&((int)ob->query("shen")>0))
    {
        message_vision("武林中人最忌争强斗狠，你不是我的对手，回去吧。\n",ob);
        return 0;
    }
    message_vision("张无忌一拱手说道：这位"+RANK_D->query_respect(ob)+
	"，在下领教了。\n", ob);
    return 1;
}
*/

int do_qiankun(CChar * me)
{
	if(me->query_skill("shenghuo_xinfa",1)<100)
	{
		say("你圣火心法修为还不够。", me);
		SendMenu(me);
		return 1;
	}
	
	if(me->query_combat_exp() < 800000) 
	{
		say("你实战经验还不够。", me);
		SendMenu(me);
		return 1;
	}
	
	if(me->query_skill("force",1)<100) 
	{
		say("似乎基本内功修为还不够。", me);
		SendMenu(me);
		return 1;
	}
	
	if ( me->query_temp("marks/挪移") ) 
	{
	   say("你不是刚刚才问过吗？", me);
	   SendMenu(me);
	   return 1;
	}
	
	say("好吧，我就准许你进入秘室修炼乾坤大挪移。以后你要发扬光大明教。", me);
	say("秘道入口在总坛的青石大道8，仔细找一找就能看见了。", me);
	say(g_Channel.do_emote(me, me, "pat", 1), me);
	say(g_Channel.do_emote(me, me, "addoil", 1), me);
	SendMenu(me);
				
	me->set_temp("marks/挪移", 1);	
	return 1;
}

int do_tieyan(CChar * me)
{
	if(query("have_given"))
	{
		say("你来晚了，铁焰令已经送人了。", me);
		SendMenu(me);
		return 1;
	}

	load_item("tieyanling")->move(me);
	say("很好，拿上这块铁焰令去挑战吧。", me);
	SendMenu(me);
	set("have_given", 1);
	call_out(do_reset, 180);

	return 1;
}

static void do_reset(CContainer * ob, LONG param1, LONG param2)
{
	ob->del("have_given");
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
				snprintf(msg, 255, "$HIY%s$HIC新立奇功，斩获明教魔头$HIY%s%s$HIC！",me->name(1),this->querystr("title"),this->name(1)));
		}
	}
	CNpc::die();
}
/*
virtual int accept_object(CChar * who, CContainer * ob)
{
	char msg[255];
	if(DIFFERSTR(ob->querystr("name"), "菩提子") )	return 0;
	destruct(ob);
	if (EQUALSTR(who->querystr("party/party_name"), "明教")) 
	{
		int exp=(random(100)+10)*who->query("level");
		who->add("combat_exp", exp);
		tell_object(who, snprintf(msg, 255, "$HIY你护教有功，被授予了%ld点经验！", exp));
	}
	return 1;
}
*/

int do_hujiao(CChar * player)
{	
	char msg[255];
	CContainer * bot;
	CContainer * env = load_room("pk");
	if(env->query("mjok"))
	{
		if(player->query_temp("mj/exp"))
		{
			int exp=player->query_temp("mj/exp");
			if(exp>800)
			{
				player->set("xkd/mingjiao",1);
				CContainer * r = load_room("明教大殿");
				if(EQUALSTR(player->querystr("family/family_name"), "明教") && r->query_temp("lin_count"))
				{
					tell_object(player, "张无敌说道:你护教有功，这块圣火令就送给你吧！上面有我这些年来钻研出来的一些使用心得，希望你可以好好珍惜，");
					bot = load_item("shenghuo_lingpro");
					bot->set("skill/name","lingfa");	
					bot->set("skill/exp_required",  50000);	
					bot->set("skill/jing_cost",40);	
					bot->set("skill/difficulty", 50 );	
					bot->set("skill/max_skill",  400);	
					bot->set("skill/min_skill", 300 );
					if(player->query("威望")>=10 && !(player->query("威望")%10))
						bot->set("kill",player->query("威望")/10);
					bot->set("owner",player->id(1));  
					bot->move(player);
					player->set("mj/linfa",400);
					r->add_temp("lin_count",-1);
				}
				else
				{
					tell_object(player, "张无敌说道:你护教有功，救了不少教中的兄弟们，可惜我的东西已经全送完了。。");
					int exp=(random(40)+50)*player->query("level");
					player->add("combat_exp", exp);
					tell_object(player, snprintf(msg, 255, "$HIY张无敌传授了你%ld点的实战经验！", exp));
				}
				if(exp>900)
				{
					player->add("威望",1);
					message_vision("\n$HIR$N的江湖威望上升了一点！\n", player);
				}
			}
			else if(exp>700)
			{
				tell_object(player, "张无敌说道：$HIY你护教有功，到胡青牛那里去领奖励去吧！");
				player->set_temp("mj/胡青牛",1);
			}
			else if(exp>600)
			{
				if(random(3))
				{
					tell_object(player, "张无敌说道：$HIY你护教有功，到鹰王那里去领奖励去吧！");
					player->set_temp("mj/鹰王",1);
				}
				else
				{
					tell_object(player, "张无敌说道：$HIY你护教有功，到右使那里去领奖励去吧！");
					player->set_temp("mj/右使",1);
				}
			}
			else if(exp>400)
			{
				tell_object(player, "张无敌说道：$HIY你护教有功，到龙王那里去领奖励去吧！");
				player->set_temp("mj/龙王",1);
			}
			else if(exp>200)
			{
				if(random(3))
				{
					tell_object(player, "张无敌说道：$HIY你护教有功，到左使那里去领奖励去吧！");
					player->set_temp("mj/左使",1);
				}
				else
				{
					tell_object(player, "张无敌说道：$HIY你护教有功，到狮王那里去领奖励去吧！");
					player->set_temp("mj/狮王",1);					
				}
			}
			else if(exp>100)
			{
				tell_object(player, "张无敌说道：$HIY你护教有功，到蝠王那里去领奖励去吧！");
				player->set_temp("mj/蝠王",1);
			}
			exp=exp*(random(6)+5)*(1+random(10)/10);
			player->add("combat_exp", exp);
			int repute=random(int(exp/2))+exp;
			if(player->query("repute")<0)
				repute=-repute;
			player->add("repute",repute);
			tell_object(player, snprintf(msg, 255, "$HIY你护教有功，被教主传授了%ld点实战经验，同时获得了%d点的江湖声望！", exp,repute));
			player->delete_temp("mj/exp");
		}
		else
			tell_object(player, "张无敌皱了皱眉头，说道：大敌当前之时，你去做什么去了？？");
	}
	else
		tell_object(player, "张无敌说道：什么？？");
    return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (DIFFERSTR((who->environment())->querystr("base_name"), "明教大殿" ))
		return notify_fail("我这是在哪里？");
	char msg[255];
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
	return 0;
}
ZUSHI_END;




