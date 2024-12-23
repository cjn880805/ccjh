#include <mysql/mysql.h>
#include <mysql/mysqld_error.h>

extern MYSQL mysql;
char * check_legal_name(const char * name);
int valid_string(const char * msg);

NPC_BEGIN(CNcorps_xinyunhun);

void create()
{
	set_name("星月之魂","xinyue hun");
    set("gender", "女性");
	set("icon", girl1);

    set("age", 20);
	set("long","她看起来二八年华，生得妖艳照人，万种风情，行动如细柳迎风，柔情无限。");
    
	set("per", 18 + random(15));
    set("combat_exp", 1);
	set("no_kill", 1);
	set("infinity", 1);		//不受容量限制
	set("is_user", 1);
	set_weight(50000000);//不可被拾取
	call_out(do_save, 60); //定时存盘
	call_out(do_consume, 50); //定时消耗帮派资源
	set("no_talk",1);
}

void init(CChar * me)
{
	CNpc::init(me);

	char msg[255];

	if(me->query("tongji")||me->query("kill/红名时间"))
	{
		tell_object(me,"你的总舵已经被查封，现在无法进入。");
		tell_room(me->environment(),snprintf(msg,255,"只听“乒”地一声，%s被人从房里一脚踢了出来，狼狈万状的逃开了。",me->name()),me);
		me->move(load_room(global_room_name[random(MAX_ROOM_NUM)]));
		me->add("hp",-100);
	}

	else if(! is_fighting() && userp(me))
	{
		if(querystr("welcome")[0])
		{
			remove_call_out(do_greeting);
			call_out(do_greeting, 2, me->object_id());
		}		
	}	
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;	
	me->say(me->querystr("welcome"));		
}

int do_talk(CChar *me, char * ask)
{
	CNpc::do_talk(me, ask);
	if(me->querymap("corps") && ! me->is_fighting() && EQUALSTR(me->querystr("corps/id"),querystr("corps_id")))
	{
		AddMenuItem("查看本宫资料", "$0ask_gong $1", me);
		if(me->query("corps/level") < 3)
		{
			AddMenuItem("查看星月之魂个人资料", "$0ask_sh $1", me);
		}
		AddMenuItem("兑换帮会声望", "$0change_c $1", me);
		AddMenuItem("兑换帮会财富", "$0change_m $1", me);
		if(me->query("corps/level") ==1)
		{
			AddMenuItem("查看宫众声望贡献度", "$0look_c $1", me);
			AddMenuItem("查看宫众财富贡献度", "$0look_m $1", me);
			CContainer * env = load_room(querystr("corps_id"));
			if(env->query("level") < 3 && !env->query("no_renwu"))
				AddMenuItem("聘请行商使者", "$0pq_sz $1", me);
			if(env->query("level") < 4 && !env->query("no_renwu"))
				AddMenuItem("聘请长老", "$0pq_zl $1", me);
		}
		AddMenuItem("查看自身声望贡献度", "$0look_u $1", me);
		AddMenuItem("查看追杀令", "$0lookenemy $1", me);
		if(me->query("corps/level") < 3)
		{
			AddMenuItem("设置留言", "$2welcome $1 $2", me);				
			AddMenuItem("发布追杀令", "$0enemy $1", me);
			AddMenuItem("撤消追杀令", "$0remenemy $1", me);	
			AddMenuItem("索取接引令", "$0getling1 $1", me);
			AddMenuItem("索取开除令", "$0getling2 $1", me);
		}
		if(me->query("corps/level") != 1)
		{
			AddMenuItem("退出本宫", "$0leave $1", me);
		}
		if(me->query("corps/level") ==1)
		{
			AddMenuItem("解散本宫", "$0js_gong $1", me);
		}
		SendMenu(me);
	}
	return 1;
}

int do_getling1(CChar * me)
{
	CContainer * jieyinling=me->present("jie yin ling");
	if(jieyinling)
		say("你不是已经有了一块令牌了吗？",me);
	else
	{
		say("这支令牌用于招收新人。",me);
		load_item("jieyinling1")->move(me);
	}
	SendMenu(me);
	return 1;
}

int do_getling2(CChar * me)
{
	CContainer * bangzhuling=me->present("kaichu ling");
	if(bangzhuling)
	{
		say("你不是已经有了一块令牌了吗？",me);
		SendMenu(me);
	}
	else
	{
		if(me->query("corps/level") > 2)
			return notify_fail("你没有资格索要。");
		say("这支令牌用于开除弟子。",me);
		load_item("bangzhuling1")->move(me);
		SendMenu(me);
	}
	return 1;
}

//退出本宫
int do_leave(CChar * me, char * arg)
{
	if(! strlen(arg))
	{
		say("退出本宫需要缴纳10万。你考虑好了吗？", me);
		AddMenuItem("我考虑好了。", "$0leave $1 1", me);
		AddMenuItem("我再考虑考虑！", "", me);
		SendMenu(me);
		return 1;
	}

	if(! CMoney::Player_Pay(me, 100000))
		return notify_fail("你的现金不足！");

	const char * corps_id = me->querystr("corps/id");
	if(! corps_id[0]) return 0;

	if(me->query("corps/level") == 1)
		return notify_fail("你是本宫宫主，不能主动退出！");

	char msg[255];
	CRoom * r = load_room(corps_id);
	r->add("corps/member_count",-1);
	if(me->query("corps/level")<7)
		r->add(snprintf(msg, 255, "corps/rank%ld", me->query("corps/level")),-1);
	r->del(snprintf(msg, 255,"repute/%s",me->id(1)));
	r->del(snprintf(msg, 255,"money/%s",me->id(1)));
	r->del(snprintf(msg, 255,"list/%s",me->id(1)));

	g_Channel.do_channel(me, NULL, "corps", 
		snprintf(msg, 255, "我宣布：今天起与你们%s再无任何瓜葛！", r->name()));
	if(me->query("corps/quest_exp")>0)
		me->add("combat_exp",-me->query("corps/quest_exp"));
	me->del("corps");
	me->setup();
	me->move(load_room(r->querystr("door")));
	me->set("start_city", START_ROOM);
	me->Save();
	me->UpdateMe();

	return 1;
}

//发布追杀令
int do_enemy(CChar * me, char * arg)
{
	char msg[255];

	if(! strlen(arg))
	{
		say("可向本宫宫众发布对其他玩家的追杀令。发布追杀令后，被追杀者如被本宫宫众所杀，不记录罪行，且PK奖励加倍。", me);
		AddMenuItem("指定被追杀对象", "$2enemy $1 $2", me);
		SendMenu(me);
		return 1;
	}

	CContainer * env = load_room(querystr("corps_id"));
	if(EQUALSTR(me->querystr("corps/id"), env->querystr("base_name"))
		&& me->query("corps/level") < 3)
	{
		CMapping * enemy = env->querymap("enemy");
		if(enemy && enemy->GetCount() >= 10)
			return notify_fail("同时追杀太多人了，请撤消几个追杀令。");

		CChar * who = find_online(arg);
		if(! who)
			return notify_fail("没有这个人。。。");

		if(! CMoney::Player_Pay(me, 50000) )
			return notify_fail("发布追杀令需要经费5万。");

		if(! env->LockData(1)) return 0;
//		env->Load();

		int times = env->add(snprintf(msg, 80, "enemy/%s", who->id(1)), 1);

		env->Save();
		env->LockData(0);

		g_Channel.do_channel(me, NULL, "corps", 
			snprintf(msg, 255, "我宣布%s开始追杀%s(%s)！追杀%ld次！", env->querystr("area"), who->name(1), who->id(1), times));

		tell_object(who, snprintf(msg, 255, "$HIR你被%s追杀了。", env->querystr("area")));

		output_error(snprintf(msg, 255, "%s(%s)被%s(%s)追杀了.", who->name(1), who->id(1), me->name(1), me->id(1)));
		return 1;
	}

	return 0;
}

//查看追杀令
int do_lookenemy(CChar * me)
{
	char msg[255];
	CContainer * env = load_room(querystr("corps_id"));
	CMapping * enemy = env->querymap("enemy");

	if(! enemy) return notify_fail("没有追杀令发布。");	

	CVector v;
	enemy->keys(v);

	for(int i=0; i<v.count(); i++)
		AddMenuItem(snprintf(msg, 255, "追杀(%s)%ld次", v[i], enemy->query(v[i])), "", me);

	SendMenu(me);
	return 1;	
}

//撤消追杀令
int do_remenemy(CChar * me, char * arg)
{
	char msg[255], cmd[40];
	CContainer * env = load_room(querystr("corps_id"));
	CMapping * enemy = env->querymap("enemy");

	if(! enemy) return notify_fail("没有追杀令发布。");

	if(! strlen(arg))
	{			
		CVector v;
		enemy->keys(v);

		for(int i=0; i<v.count(); i++)
			AddMenuItem(snprintf(msg, 255, "撤消追杀(%s)", v[i]),
					snprintf(cmd, 40, "$0remenemy $1 %s", v[i]), me);

		SendMenu(me);
		return 1;
	}
	
	if(EQUALSTR(me->querystr("corps/id"), env->querystr("base_name"))
		&& me->query("corps/level") < 3)
	{
		if(! env->LockData(1)) return 0;
//		env->Load();

		enemy = env->querymap("enemy");
		if(! enemy)
		{
			env->LockData(0);
			return 0;
		}

		enemy->del(arg);		
		if(! enemy->GetCount())
			env->del("enemy");
		env->Save();
		env->LockData(0);

		g_Channel.do_channel(me, NULL, "corps", 
			snprintf(msg, 255, "我宣布%s停止追杀%s！", env->querystr("area"), arg));
		return 1;
	}

	return 0;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(me->querymap("corps") && EQUALSTR(me->querystr("corps/id"),querystr("corps_id")))
	{
		if(strcmp(comm, "welcome") == 0 && me->query("corps/level") < 3)	//设置欢迎词
			return do_welcome(me, arg);
		else if(strcmp(comm, "getling1") == 0 && me->query("corps/level") < 5)	//索取接引令
			return do_getling1(me);
		else if(strcmp(comm, "getling2") == 0 && me->query("corps/level") < 5)	//索取开除令
			return do_getling2(me);
		else if(strcmp(comm, "leave") == 0 && me->query("corps/level") !=1)	//退出
			return do_leave(me, arg);
		
		else if(strcmp(comm, "change_c") == 0 )	//兑换帮派声望贡献度
		{
			say("你可以用你的帮派贡献度来兑换成帮派声望，兑换比例为100：1。",me);
			AddMenuItem("我要兑换帮会声望", "$2change_cy $1 $2", me);
			AddMenuItem("算了还是下次吧", "", me);
			SendMenu(me);
			return 1;
		}
		else if(strcmp(comm, "change_cy") == 0 )
			return do_change_c(me, arg);

		else if(strcmp(comm, "change_m") == 0 )	//兑换帮派财富
		{
			say("你可以用你的江湖货币来兑换成帮派财富，兑换比例为100：1。",me);
			AddMenuItem("我要兑换帮会财富", "$2change_my $1 $2", me);
			AddMenuItem("算了还是下次吧", "", me);
			SendMenu(me);
			return 1;
		}
		else if(strcmp(comm, "change_my") == 0 )
			return do_change_m(me, arg);

		else if(strcmp(comm, "look_u") == 0 )	//查看自身声望贡献度
			return do_look_me_contribute(me);	
		else if(strcmp(comm, "enemy") == 0 && me->query("corps/level") < 3)	//发布追杀令
		{
			CContainer * env = load_room(querystr("corps_id"));
			if(! env->LockData(1)) return 0;
			int ret = do_enemy(me, arg);
			env->LockData(0);
			return ret;
		}
		else if(strcmp(comm, "remenemy") == 0 && me->query("corps/level") < 3)	//取消追杀令
		{
			CContainer * env = load_room(querystr("corps_id"));
			if(! env->LockData(1)) return 0;
			int ret = do_remenemy(me, arg);
			env->LockData(0);
			return ret;
		}
		else if(strcmp(comm, "lookenemy") == 0)	//查看追杀名单
			return do_lookenemy(me);
		else if(strcmp(comm, "ask_gong") == 0)	//查看帮派资料
		{
			char msg[255];
			char tmp[25];
			CContainer * env = load_room(querystr("corps_id"));
			LONG lost_reputep,lost_money;
			switch(env->query("level"))
			{
			case 1:
				lost_reputep=env->query("corps/member_count")*3;
				lost_money=env->query("corps/member_count")*500;
				break;
			case 2:
				lost_reputep=env->query("corps/member_count")*(3+2);
				lost_money=env->query("corps/member_count")*(500+500);
				break;
			case 3:
				lost_reputep=env->query("corps/member_count")*(3+2+2);
				lost_money=env->query("corps/member_count")*(500+500+600);
				break;
			case 4:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2);
				lost_money=env->query("corps/member_count")*(500+500+600+600);
				break;
			case 5:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2+2);
				lost_money=env->query("corps/member_count")*(500+500+600+600+650);
				break;
			case 6:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2+2+3);
				lost_money=env->query("corps/member_count")*(500+500+600+600+650+1000);
				break;
			case 7:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2+2+3+2);
				lost_money=env->query("corps/member_count")*(500+500+600+600+650+1000+1000);
				break;
			case 8:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2+2+3+2+3);
				lost_money=env->query("corps/member_count")*(500+500+600+600+650+1000+1000+1500);
				break;
			case 9:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2+2+3+2+3+3);
				lost_money=env->query("corps/member_count")*(500+500+600+600+650+1000+1000+1500+1500);
				break;
			}
			tell_object(me, snprintf(msg, 255,"\n$HIR----------------------------------%s资料----------------------------------",querystr("corps_name")));
			sprintf(msg, "        $HIR帮 派 名 称： %-14s          宫主：%s(%s)",querystr("corps_name"),env->querystr("corps/owner_name"),env->querystr("corps/owner_id"));
			tell_object(me, msg);
			tell_object(me, snprintf(msg, 255,"        $HIR帮 派 等 级： %d 级",env->query("level")));
			tell_object(me, snprintf(msg, 255,"        $HIR帮 派 成 员： %d 名",env->query("corps/member_count")));
			sprintf(msg, "        $HIR帮 派 声 望： %-14s          日消耗帮派声望： %ld",snprintf(tmp, 25,"%ld",env->query("corps/repute")),lost_reputep);
			tell_object(me, msg);
			sprintf(msg, "        $HIR帮 派 财 富： %-14s          日消耗帮派财富： %ld",snprintf(tmp, 25,"%ld",env->query("corps/money")),lost_money);
			tell_object(me, msg);
			tell_object(me, "$HIR--------------------------------------------------------------------------------");
			int count=env->query("corps/member_count");
			sprintf(msg, "        $HIR副宫主人数 ： %-14s          最多可提升副宫主数： %d 名",snprintf(tmp, 25,"%d 名",env->query("corps/rank2")),2+count/100);
			tell_object(me, msg);
			sprintf(msg, "        $HIR长 老 人 数： %-14s          最多可提升  长老数： %d 名",snprintf(tmp, 25,"%d 名",env->query("corps/rank3")),4+count/70);
			tell_object(me, msg);
			sprintf(msg, "        $HIR阁 主 人 数： %-14s          最多可提升  阁主数： %d 名",snprintf(tmp, 25,"%d 名",env->query("corps/rank4")),8+count/50);
			tell_object(me, msg);
			sprintf(msg, "        $HIR护 法 人 数： %-14s          最多可提升  护法数： %d 名",snprintf(tmp, 25,"%d 名",env->query("corps/rank5")),16+count/30);
			tell_object(me, msg);
			sprintf(msg, "        $HIR使 者 人 数： %-14s          最多可提升  使者数： %d 名",snprintf(tmp, 25,"%d 名",env->query("corps/rank6")),32+count/15);
			tell_object(me, msg);
			tell_object(me, "$HIR--------------------------------------------------------------------------------\n");
			return 1;
		}
		
		if(me->query("corps/level") < 3)
		{
			if(strcmp(comm, "ask_sh") == 0 )	//查看星月之魂资料
			{
				char msg[255];
				LONG valid_exp = query_valid_exp();	
				LONG need_exp = CChar::Level2Exp(query("level") + 1) - CChar::Level2Exp(query("level"));
				tell_object(me, "\n$HIR----------------------------------星月之魂属性----------------------------------");
				tell_object(me, snprintf(msg, 255,"        $HIR力量：%d     智慧：%d     敏捷：%d     体质：%d",query("str"),query("int"),query("dex"),query("con")));
				tell_object(me, snprintf(msg, 255,"        $HIR魅力：%d     等级：%d",query("per"),query("level")));
				tell_object(me, snprintf(msg, 255,"        $HIRHP  ：%ld / %ld (%ld)",query("hp"),query("eff_hp"),query("max_hp")));
				tell_object(me, snprintf(msg, 255,"        $HIRMP  ：%ld / %ld (+%d)",query("mp"),query("max_mp"),query("mp_factor")));
				tell_object(me, snprintf(msg, 255,"        $HIR经验：%ld / %ld     总经验：%ld",valid_exp,need_exp,query("combat_exp")));
				tell_object(me, "$HIR--------------------------------------------------------------------------------\n");
				return 1;
			}
		}
		if(me->query("corps/level") == 1)
		{
			CContainer * env = load_room(querystr("corps_id"));
			if(strcmp(comm, "look_c") == 0 )	//查看宫众声望贡献度
			{
				return do_look_contribute(me);	
			}
			else if(strcmp(comm, "look_m") == 0 )	//查看宫众财富贡献度
			{
				return do_look_money(me);	
			}

			else if(strcmp(comm, "js_gong") == 0 )	//解散本宫
			{
				say("你是否已经确定你要解散本宫？",me);
				AddMenuItem("我已经想清楚了要解散本宫！", "$0y_e_s $1", me);
				AddMenuItem("算了还是下次吧", "", me);
				SendMenu(me);
				return 1;
			}
			else if(strcmp(comm, "y_e_s") == 0)
			{
				char msg[255];
				g_Channel.do_channel(this, NULL, "news", snprintf(msg, 255,"$HIW「%s」$HIC被%s(%s)解散，从此在江湖史册上消失无踪……",env->name(),env->querystr("corps/owner_name"),env->querystr("corps/owner_id")));
				env->set("end",1);
				CRoom * room = (CRoom *)(load_room(env->querystr("door")));
				room->remove_doors(querystr("corps_id"));
				return g_player();	
			}
			else if(strcmp(comm, "pq_sz") == 0 )	//聘请行商使者
			{
				if(env->query("corps/repute")>30 && env->query("corps/money")>400)
				{
					CContainer * env1=environment();
					CContainer * Npc=env1->present("xinshang zhizhe");
					if(Npc)
					{
						say("你不是已经聘请了一位行商使者了吗？",me);
						SendMenu(me);
						return 1;
					}
					else
					{
						env->add("corps/repute",-30);
						env->add("corps/money",-400);
						say("已经为你聘请来了一位行商使者，她将会为你服务24小时，本宫宫众将可以在行商使者处接取商人任务。", me);
						SendMenu(me);
						return do_pqsz(me);
					}
				}
				else
				{
					say("你的帮派声望不足30点或帮派财富不足400点，不能聘请行商使者。", me);
					SendMenu(me);
					return 1;
				}
			}
			else if(strcmp(comm, "pq_zl") == 0 )	//聘请长老
			{
				if(env->query("corps/repute")>30 && env->query("corps/money")>400)
				{
					CContainer * env1=environment();
					CContainer * Npc=env1->present("zhang lao");
					if(Npc)
					{
						say("你不是已经聘请了一位长老了吗？",me);
						SendMenu(me);
						return 1;
					}
					{
						env->add("corps/repute",-30);
						env->add("corps/money",-400);
						say("已经为你聘请来了一位长老，她将会为你服务24小时，本宫宫众将可以在长老处每天接取20个帮派任务。", me);
						SendMenu(me);
						return do_pqzl(me);
					}
				}
				else
				{
					say("你的帮派声望不足30点或帮派财富不足400点，不能聘请行商使者。", me);
					SendMenu(me);
					return 1;
				}
			}
		}
	}
	return CNpc::handle_action(comm, me, arg);
}

//设置欢迎词
int do_welcome(CChar * me, char * arg)
{
	int len = strlen(arg);
	if(len < 1 || len > 250)
	{
		say("请把留言写得简洁漂亮点。", me);
		SendMenu(me);
		return 1;
	}

	if(! valid_string(arg) )
		return 0;
	
	set("welcome", arg);
	CContainer * where = load_room(querystr("corps_id"));

	if(! where->LockData(1)) return 0;

	where->set("shizhe/welcome", arg);
	where->Save();

	where->LockData(0);

	tell_object(me, "OK.");
	return 1;
}

//定时存盘
static void do_save(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(! me->is_fighting())
	{
		int level = me->query("level");
		LONG valid_exp = me->query_valid_exp();	
		LONG need_exp = CChar::Level2Exp(level + 1) - CChar::Level2Exp(level);
		if(valid_exp >=need_exp)
		{
			me->set("level", level + 1);
			int imp_hp=3000+me->query("con")*100+random(1000);
			me->add("max_hp",imp_hp);
			me->add("eff_hp",imp_hp);
			me->add("hp",imp_hp);
			int imp_mp=10+me->query("int")+random(10);
			me->add("max_mp",imp_mp);
			me->add("mp",imp_mp);
			me->set("mp_factor",2*me->query("level"));
			tell_room(me->environment(), "$HIW星月之魂眼中精光一闪,功力提升了!");
			me->FlushMyInfo();
		}
		
		CContainer * where = load_room(me->querystr("corps_id"));
		
		where->set("新月大殿/sh_level",me->query("level"));
		where->set("新月大殿/sh_hp",me->query("max_hp"));
		where->set("新月大殿/sh_mp",me->query("max_mp"));
		where->set("新月大殿/sh_combat_exp",me->query("combat_exp"));
		
		where->set("新月大殿/sh_str",me->query("str"));
		where->set("新月大殿/sh_dex",me->query("dex"));
		where->set("新月大殿/sh_con",me->query("con"));
		where->set("新月大殿/sh_int",me->query("int"));
		
		if(!where->query("end"))
			where->Save();
	}

	if(me->query("wait_time"))
		me->call_out(do_save, me->query("wait_time"));
	else
		me->call_out(do_save, 600);
}

//聘请行商使者
int do_pqsz(CChar * me)
{
	CNpc * sz = load_npc("corps_qingxia");
	sz->set_name("行商使者","xinshang zhizhe");
	sz->set("title",querystr("corps_name"));
	sz->set("leave_time",24);
	sz->set("corps_id",querystr("corps_id"));
	sz->set("pq",1);
	sz->move(environment());
	return 1;
}

//聘请长老
int do_pqzl(CChar * me)
{
	CNpc * sz = load_npc("corps_xiaoyaosanren");
	sz->set_name("长老","zhang lao");
	sz->set("title",querystr("corps_name"));
	sz->set("leave_time",24);
	sz->set("corps_id",querystr("corps_id"));
	sz->set("pq",1);
	sz->move(environment());
	return 1;
}

//兑换帮派声望
int do_change_c(CChar * me, char * arg)
{
	int len = strlen(arg);
	char msg[255];
	if(len < 1 || len > 10)
	{
		say("你想兑换掉多少你的帮派贡献度？", me);
		SendMenu(me);
		return 1;
	}
	CContainer * env = load_room(querystr("corps_id"));
	int imp_rp=atoi(arg);
	if(imp_rp>0 && imp_rp<100000000 )
	{
		if(me->query("corps/contribute")>=imp_rp)
		{
			say(snprintf(msg, 255,"你已经兑换了%d点的帮派贡献度，%s的帮派声望增加了%d点。",
				imp_rp,querystr("corps_name"),imp_rp/100), me);
			SendMenu(me);
			env->add("corps/repute",imp_rp/100);
			env->add(snprintf(msg, 255,"repute/%s",me->id(1)),imp_rp/100);
			me->add("corps/contribute",-imp_rp);
		}
		else
		{
			say(snprintf(msg, 255,"你目前的帮派贡献度只有%d,不能支付你所输入的%d点。",me->query("corps/contribute"),imp_rp), me);
			SendMenu(me);
		}
		env->Save();
	}

	return 1;
}

//兑换帮派财富
int do_change_m(CChar * me, char * arg)
{
	int len = strlen(arg);
	char msg[255];
	if(len < 1 || len > 10)
	{
		say("你想兑换掉多少", me);
		SendMenu(me);
		return 1;
	}
	CContainer * env = load_room(querystr("corps_id"));
	int imp_money=atoi(arg);
	if(imp_money>0 && imp_money<100000000 )
	{
		if(! CMoney::Player_Pay(me, imp_money))
			say(snprintf(msg, 255,"你目前所携带的江湖货币不足,无法支付你所输入的%d。",imp_money), me);
		else
		{
			say(snprintf(msg, 255,"你已经兑换了%d的江湖货币，%s的帮派财富增加了%d点。",
				imp_money,querystr("corps_name"),imp_money/100), me);
			env->add("corps/money",imp_money/100);
			env->add(snprintf(msg, 255,"money/%s",me->id(1)),imp_money/100);
		}
		env->Save();
	}
	else
		say("每次最多可以一次兑换100000000的江湖货币，请你重新确认后再输入。", me);

	SendMenu(me);
	return 1;
}

//查看宫众声望贡献度
int do_look_contribute(CChar * me)
{
	char msg[255];
	CContainer * env = load_room(querystr("corps_id"));
	CMapping * repute = env->querymap("repute");

	if(! repute) return notify_fail("没有宫众为本宫贡献过帮派声望。");	

	CVector v;
	repute->keys(v);
	if(! v.count()) return notify_fail("没有宫众为本宫贡献过帮派声望。");	

	for(int i=0; i<v.count(); i++)
	{
		sprintf(msg, "%s：贡献了%ld点帮派声望", v[i], repute->query(v[i]));
		AddMenuItem(msg, "", me);
	}

	SendMenu(me);
	return 1;	
}

//查看自身声望贡献度
int do_look_me_contribute(CChar * me)
{
	char msg[255];
	snprintf(msg, 255,"你的帮派贡献度是：%ld 点",me->query("corps/contribute"));
	AddMenuItem(msg, "", me);	
	SendMenu(me);
	return 1;	
}

//查看宫众财富贡献度
int do_look_money(CChar * me)
{
	char msg[255];
	CContainer * env = load_room(querystr("corps_id"));
	CMapping * money = env->querymap("money");

	if(! money) return notify_fail("没有宫众为本宫贡献过帮派财富。");	

	CVector v;
	money->keys(v);
	if(! v.count()) return notify_fail("没有宫众为本宫贡献过帮派财富。");	

	for(int i=0; i<v.count(); i++)
	{
		sprintf(msg, "%s：贡献了%ld点帮派财富", v[i], money->query(v[i]));
		AddMenuItem(msg, "", me);
	}

	SendMenu(me);
	return 1;	
}

//守护使者死了
virtual void die()
{
	char msg[255];
	CContainer * env = load_room(querystr("corps_id"));
	env->set("end",1);
	tell_room(environment(), "$HIR星月之魂凄婉一笑，化做一缕青烟，随风飘散。顷刻间，天河倾斜，大地动容，新月大殿已是一片废墟。");
	
	CChar * killer = (CChar *)find_object(query_temp("last_damage_from"), 1);
//	if(killer &&  killer->querymap("corps") && DIFFERSTR(killer->querystr("corps/id"),querystr("corps_id")))
	if(killer &&  killer->querymap("corps"))
	{
		g_Channel.do_channel(this, NULL, "news", snprintf(msg, 255,"$HIW「%s」$HIC被$HIW「%s」%s(%s)$HIC所灭，从此在江湖史册上消失无踪……",load_room(querystr("corps_id"))->name(),load_room(killer->querystr("corps/id"))->name(),killer->name(1),killer->id(1)));
		CRoom * room = (CRoom *)(load_room(env->querystr("door")));
		room->remove_doors(querystr("corps_id"));
		//战斗中的所有人移出宫
		CContainer * obj = environment();
		DTItemList * list = obj->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		while(p) 
		{ 
			CContainer * obj = list->GetNext(p);
			if(! obj->is_character()) continue; 
			CChar * target = (CChar *)obj;  
			if(!userp(target))	continue;
			target->move(load_room(env->querystr("door")));
		}
		g_player();//清除所有在线帮众的帮会资料
	}
	CNpc::die();
}

//删除数据库帮派记录
int corps_end(CChar * me)
{
	if(me->querystr("corps_id"))
	{
		char msg[255];
		int nResult = 0;
		CContainer * env = load_room(me->querystr("corps_id"));
		env->set("fail_ob",1);
		
		snprintf(msg, 255, "delete from t_corp where obj_id = '%s'",me->querystr("corps_id"));
		nResult = mysql_real_query(&mysql, msg, strlen(msg));
		if( nResult == 0)
		{
			g_Channel.do_channel(&g_Channel, 0, "sys",snprintf(msg, 255," %s 被灭，从此在江湖史册上消失无踪……",env->name()));
		}
		load_room("pk")->add(snprintf(msg, 255,"corps/%s",load_room(env->querystr("door"))->querystr("area")),-1);
		destruct(env);
	}
	return 1;
}

//将所有帮派成员的帮派资料清除并将在帮派中的玩家移出宫派
int g_player()
{
	MAP2USER * user;
	iterator_user p;
	CUser * obj;
	CContainer * env;
	CContainer * env1;

	user = users();
    for ( p=user->begin(); p!=user->end(); p++)
    {
		obj = p->second;
		if( DIFFERSTR(obj->querystr("corps/id"),querystr("corps_id")))
			continue;

		env1=load_room(querystr("corps_id"));
		env=obj->environment();
		
		if(EQUALSTR(env->querystr("area"),env1->querystr("area")))
			obj->move(load_room(env1->querystr("door")));
		obj->set("start_city", START_ROOM);
		obj->del("corps");
		obj->delete_temp("c_title");
		obj->setup();
		obj->UpdateMe();
    }
	return corps_end(this);
}

//定时扣除资源消耗
static void do_consume(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env = load_room(me->querystr("corps_id"));

	time_t t;	
	struct tm * newtime;
	time(&t);
	newtime = localtime(&t); 

	if(!me->query("tm_day"))
	{
		me->set("tm_day",newtime->tm_mday);
		env->set("day",me->query("tm_day"));
		if(!env->query("end"))
			env->Save();
		me->call_out(do_consume, 3600);
	}
	else
	{
		if(newtime->tm_mday!=me->query("tm_day"))
		{
			int lost_reputep,lost_money;
			switch(env->query("level"))
			{
			case 1:
				lost_reputep=env->query("corps/member_count")*3;
				lost_money=env->query("corps/member_count")*500;
				break;
			case 2:
				lost_reputep=env->query("corps/member_count")*(3+2);
				lost_money=env->query("corps/member_count")*(500+500);
				break;
			case 3:
				lost_reputep=env->query("corps/member_count")*(3+2+2);
				lost_money=env->query("corps/member_count")*(500+500+600);
				break;
			case 4:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2);
				lost_money=env->query("corps/member_count")*(500+500+600+600);
				break;
			case 5:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2+2);
				lost_money=env->query("corps/member_count")*(500+500+600+600+650);
				break;
			case 6:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2+2+3);
				lost_money=env->query("corps/member_count")*(500+500+600+600+650+1000);
				break;
			case 7:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2+2+3+2);
				lost_money=env->query("corps/member_count")*(500+500+600+600+650+1000+1000);
				break;
			case 8:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2+2+3+2+3);
				lost_money=env->query("corps/member_count")*(500+500+600+600+650+1000+1000+1500);
				break;
			case 9:
				lost_reputep=env->query("corps/member_count")*(3+2+2+2+2+3+2+3+3);
				lost_money=env->query("corps/member_count")*(500+500+600+600+650+1000+1000+1500+1500);
				break;
			}
			me->set("tm_day",newtime->tm_mday);
			env->set("day",me->query("tm_day"));
			env->add("corps/repute",-lost_reputep);
			env->add("corps/money",-lost_money);
			if(!env->query("end"))
				env->Save();
			if(env->query("corps/repute")<0 || env->query("corps/money")<0)
			{
				char msg[255];
				env->set("end",1);
				g_Channel.do_channel(me, NULL, "news", snprintf(msg, 255,"$HIW「%s」$HIC由于管理不善而倒闭，从此在江湖史册上消失无踪……",env->name()));
				CRoom * room = (CRoom *)(load_room(env->querystr("door")));
				room->remove_doors(me->querystr("corps_id"));
				//清除所有在线帮众的帮会资料
				MAP2USER * user;
				iterator_user p;
				CUser * obj;
				CContainer * env1;
				
				user = users();
				for ( p=user->begin(); p!=user->end(); p++)
				{
					obj = p->second;
					if( DIFFERSTR(obj->querystr("corps/id"),me->querystr("corps_id")))
						continue;
					env1=load_room(me->querystr("corps_id"));
					env=obj->environment();
					
					if(EQUALSTR(env->querystr("area"),env1->querystr("area")))
						obj->move(load_room(env1->querystr("door")));
					obj->set("start_city", START_ROOM);
					obj->del("corps");
					obj->delete_temp("c_title");
					obj->setup();
					obj->UpdateMe();
				}
				if(me->querystr("corps_id"))
				{
					int nResult = 0;
					env = load_room(me->querystr("corps_id"));
					env->set("fail_ob",1);
					
					snprintf(msg, 255, "delete from t_corp where obj_id = '%s'",me->querystr("corps_id"));
					nResult = mysql_real_query(&mysql, msg, strlen(msg));
					if( nResult == 0)
					{
						g_Channel.do_channel(&g_Channel, 0, "sys",snprintf(msg, 255," %s 被灭，从此在江湖史册上消失无踪……",env->name()));
					}
					load_room("pk")->add(snprintf(msg, 255,"corps/%s",load_room(env->querystr("door"))->querystr("area")),-1);
				}
				destruct(env);
			}
			else
				me->call_out(do_consume, 3600);
		}
		else
			me->call_out(do_consume, 3600);
	}
}

NPC_END;



