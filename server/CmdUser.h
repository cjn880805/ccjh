BOOL VerifyUser(const char * userid, char * passwd);
int ChangePassword(const char * id, const char * pass);
int VerifyPassword(const char * id, const char * pass);
int ChangeVerifyPassword(const char * id, const char * pass);
void setup_char(CChar * me);
char * check_legal_name(const char * name);

#define  MAX_ENV_VARS		10
#define	 VOTE_AGE_LIMIT		15
#define	 VOTE_LEVEL_LIMIT	5

class CCmdUser
{
public:
	CCmdUser()
	{
		//m_Cmd["info"] = Info;
		//m_Cmd["item"] = Item;
		m_Cmd["skill"] = Skill;
		m_Cmd["downloadskill"] = DownLoadSkill;
		m_Cmd["downloadobject"] = DownLoadObject;
		m_Cmd["downloaduser"] = downloaduser;
	
		m_Cmd["quit"] = Quit;
		m_Cmd["save"] = Save;
		m_Cmd["wakeup"] = Wakeup;
		m_Cmd["nick"] = Nick;
		m_Cmd["talk"] = Talk;
		m_Cmd["ask"] = Talk;
		m_Cmd["set"] = SetParam;
		m_Cmd["unset"] = Unset;

		m_Cmd["refuse"] = refuse;

		m_Cmd["mudage"] = Mudage;
		m_Cmd["password"] = Passwd;
		m_Cmd["verifypass"] = VerifyPass;
		m_Cmd["upgrade"] = Upgrade;
		m_Cmd["tune"] = Tune;
		m_Cmd["vote"] = Vote;
	
		m_Cmd["refusetell"] = RefuseTell;
		m_Cmd["wantlisten"] = Listen;

		m_Cmd["nickname"] = NickName;
		m_Cmd["rexp"] = RecruitExp;

		m_Cmd["invite"] = invite;
		m_Cmd["accept"] = accept;
		m_Cmd["mv"] = mv;
		m_Cmd["loc"] = loc;

		m_Cmd["addfriend"] = addfriend;
		m_Cmd["remfriend"] = remfriend;
		m_Cmd["who"] = who;		

		m_Cmd["listgoods"] = ListGoods;
		m_Cmd["pary"] = Pary;
		m_Cmd["accept_pary"] = Accept_pary;
		m_Cmd["paryleave"] = Paryleave;
		m_Cmd["parykick"] = Parykick;
		//m_Cmd["parylist"] = Parylist;尚未完成
		m_Cmd["buy"] = Buy;
		m_Cmd["validate"] = Validate;
		
	};

	~CCmdUser(){};

	typedef int (* func)(CChar * me, LONG target, char * arg);
	typedef map<string, func, less<string> > CMDMAP;
	CMDMAP m_Cmd;

	int Handlecommand(char * cmd, CChar * me, LONG target, char * arg)
	{
		CMDMAP::iterator p;
		if((p = m_Cmd.find(cmd)) == m_Cmd.end()) return -1;
		return ((*p).second)(me, target, arg);
	}

	DEFINECMD(Info)
	{
		me->FlushMyInfo();
		return 1;
	}

	//得到某物的物品列表 item #obj
	DEFINECMD(Item)
	{
		me->FlushMyEquip();
		return 1;
	}
	

	//skill
	//查看who的技能。
	DEFINECMD(Skill)
	{
		CChar * who = GetRoomChar(me, target);
		if(!who) who = me;

		//判断me是否有权限看who的技能。
		if( ! wizardp(me) && me != who && ! Is_Relative(me, who)
			&& ! who->recognize_apprentice(me) ) 
		return notify_fail("你无权查看对方技能。");

		who->FlushMySkill(me);
		return 1;
	}

	//下载技能
	DEFINECMD(DownLoadSkill)
	{
		CSkill * skill;
		
		if( ! (skill = load_skill(arg)) ) return 0;
		skill->DownLoad(me);
		return 1;
	}

	//下载物件
	DEFINECMD(DownLoadObject)
	{
		CContainer * obj;
		
		if( (obj = find_object(target)) )
			obj->DownLoad(me);
		return 1;
	}
		

	//退出游戏
	DEFINECMD(Quit)
	{
		char cmd[255];

		if(me->is_fighting() && !me->query_temp("net_dead"))
			return notify_fail("战斗中不能退出。");

		if(me->is_busy())
			return notify_fail("( 你上一个动作还没有完成，不能退出。)");
		DropAll(me);
		me->SaveToServer();

		//离线
		((CUser *)me)->Offline();
		tell_room(me->environment(), snprintf(cmd, 255, "%s离开游戏。", me->name()), me);

		g_Channel.do_channel(&g_Channel, 0, "sys", cmd);

		DESTRUCT_OB(me, "cmd::quit");
		return 1;
	}

	DEFINECMD(Wakeup)
	{
		char msg[512];
		char info[400];
		CChar * who;

		if(! (who = find_player(target)))
			return 0;

		if(! strlen(arg)) strcpy(info, "猪！起来了！");
		else strncpy(info, arg, 400);

		snprintf(msg, 512, "【动作】%s对着%s的耳朵大喊：%s", me->name(), who->name(), info);
		MessageVision(me, "chat", msg);
		snprintf(msg, 512, "&C=%d&T=%ld&M=%s&", WAKEUP, me->object_id(), arg);
		who->SendCommand(msg);			//弹出
		return 1;
	}

	DEFINECMD(Save)
	{
		if(current_time < me->query_temp("last_save_time"))
		{
			MessageVision(me, "tell", "您在三十秒内刚存过盘。");
			return 1;
		}

		me->set_temp("last_save_time", current_time + 30);

		CContainer * where = me->environment();
		if( where->query("valid_startroom") 
			|| EQUALSTR(where->querystr("owner"), me->querystr("id"))
			|| EQUALSTR(where->querystr("second_owner"), me->querystr("id")))
		{
			me->set("start_city", where->querystr("base_name"));
			tell_object(me, "当你下次连线进来时，会从这里开始。");
		}

		if(me->Save())
			tell_object(me, "档案储存完毕。");
		else
			tell_object(me, "储存失败。");
		
		return 1;
	}

	//为宠物起名
	DEFINECMD(Nick)
	{
		int len = strlen(arg);
		char msg[80];
		CChar * who;

		if(! (who = FindSprite(me))) return 0;

		if(! len || len > 10)
		{
			MessageVision(me, "tell", "名字长度不合法。");
			return 0;
		}
	
		//检查名字中有否非法字符
		if(! CheckValidChar(arg))
			return notify_fail("名字中含有非法字符！");
	
		snprintf(msg, 80, "[宠物]%s", arg);
		who->set_name( msg);

		who->UpdateMe();
	
		tell_object(me, snprintf(msg, 80, "你将宠物命名为%s。", arg));
		
		return 1;
	}

	DEFINECMD(Talk)
	{
		//禁止在设置为no_talk的场景使用Talk命令 秦波 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_talk")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("这里禁止和人说话。");
		
		CChar * who;
		char msg[80], tmp[40];

		if(! (who = GetRoomChar(me, target)) ) return notify_fail("你要和谁讲话，看清楚点！");
		if(! living(who) || who == me) return notify_fail("对方显然无法和你讲话。");

		notify_fail("对方并不愿意理你。");
		if(me->is_fighting() || who->is_fighting() )
		{
			if( who->Query(CChar::IS_NPC) && EQUALSTR(who->querystr("name"), "霜儿"))
				return ((CNpc *)who)->do_talk(me, arg);
			else
				return 0;
		}

		if(who->Query(CChar::IS_NPC))
		{		
			return ((CNpc *)who)->do_talk(me, arg);
		}

		CContainer * where = me->environment();

		//与玩家的交互
		
		//与玩家交易
		who->AddMenuItem(snprintf(msg, 80, "查看%s的货品", who->name()), "$0listgoods $1", me);
		//与玩家组队
		if(EQUALSTR(me->querystr_temp("pary/master"),who->querystr("id")))
			who->AddMenuItem(snprintf(msg, 80, "解除与%s的组队", who->name()), "$0paryleave $1", me);
		else if(me->query_temp(snprintf(msg, 80,"pary/friend_%s",who->querystr("id"))))
		{
			who->AddMenuItem(snprintf(msg, 80, "踢除%s出队", who->name()), "$0parykick $1", me);
//			who->AddMenuItem("查看在线队员", "$0parylist $1", me);
		}
		else
			who->AddMenuItem(snprintf(msg, 80, "与%s组队", who->name()), "$0pary $1", me);

		
		if(me->querystr("resident")[0])	//有自己的房子
		{
			//如果在家外
			if(DIFFERSTR(where->querystr("owner"), me->querystr("id"))
				&& DIFFERSTR(where->querystr("second_owner"), me->querystr("id")))
			{
				who->AddMenuItem(snprintf(msg, 80, "邀请%s做客", who->name()),	"$0invite $1",me);
			}
			else	//在家里 不能赶房主
			{
				if(DIFFERSTR(where->querystr("owner"), who->querystr("id")))
					who->AddMenuItem(snprintf(msg, 80, "把%s赶出家门", who->name()), snprintf(tmp, 40, "$0kickout 0 %s", who->id(1)), me);
			}
		}

		if( where->query("sleep_room") 
			&& DIFFERSTR(who->querystr("gender"), me->querystr("gender")) )	//可以睡觉
			who->AddMenuItem(snprintf(msg, 80, "想和%s睡觉", who->name()), "$0sleep $1", me);

		if( EQUALSTR(who->querystr("couple/id"), me->querystr("id"))	//夫妻可以传授
			&& EQUALSTR(who->querystr("id"), me->querystr("couple/id")))
		{
			who->AddMenuItem(snprintf(msg, 80, "查看%s的技能", me->querystr("couple/gender")), "$0skill $1", me);
			who->AddMenuItem(snprintf(msg, 80, "教%s武艺", me->querystr("couple/gender")), "$0teach $1", me);
		}

		if( me->query("recruit_exp") / 50 > me->recruit_num())
			who->AddMenuItem(snprintf(msg, 80, "收%s为徒", who->name()), "$0recruit $1", me);

		if( who->query("recruit_exp") / 50 > who->recruit_num())
			who->AddMenuItem(snprintf(msg, 80, "拜%s为师", who->name()), "$0apprentice $1", me);
			
		if( who->query_condition("prostitute") && where->query("wench_room"))
			who->AddMenuItem("嫖妓", "$0wench $1", me);

		who->AddMenuItem(snprintf(msg, 80, "和%s没什么好说的", who->name()), "", me);
		who->SendMenu(me);
		return 1;
	}

	//设置环境变量
	DEFINECMD(SetParam)
	{
		char str_wiz_only[] = "({\"invisibility\",\"immortal\"})";
		CVector wiz_only;
		char val[40], msg[255];
		CMapping * env;
		char key[40];
				
		env = me->querymap("env");
		if( ! strlen(arg))
		{
			tell_object(me, "你目前设定的环境变数有：");
			if(! env)
				tell_object(me, "没有设定任何环境变数。");
			else
			{
				CVector v;
				int i;

				env->keys(v);

				for(i = 0; i < v.count(); i++)
				{
					CMapping::svalue_t * sv = env->find_string_in_mapping(v[i]);
					if(sv->type == T_NUMBER)
						tell_object(me, snprintf(msg, 80, "%s = %d", v[i], sv->u.number) );
					else if(sv->type == T_STRING)
						tell_object(me, snprintf(msg, 80, "%s = %s", v[i], sv->u.string) );
				}
			}
			return 1;
		}
 
		if( env && env->GetCount() >= MAX_ENV_VARS )
			return notify_fail("你设的环境变数太多了，请先用 unset 删掉几个吧。");

		analyse_string(arg, val, 40);
		me = FindMaster(me);

		wiz_only.LoadBuffer(str_wiz_only);
		//allowed.LoadBuffer(str_allowed);
		//if(! wizardp(me) && allowed.find(arg) == allowed.end())
		//	return notify_fail("你只能设定settings中定义过的环境变数。");
        if(! wizardp(me) && wiz_only.find(arg) != wiz_only.end() )
            return notify_fail("只有巫师能用这个设定。");

		if(strcmp(arg, "wimpy") == 0 && ( atol(val) < 0 || atol(val) > 80) )
			return notify_fail("wimpy [<逃跑时「气」的百分比>]");
		
		if(! CheckValidChar(arg))
			return notify_fail("你设置环境变量名非法！");
			
			snprintf(key, 40, "env/%s", arg);

		if(val[0] == '-' || (val[0] >='0' && val[0] <='9'))
			{
				me->set(key, atol(val));
				snprintf(msg, 255, "你设置环境变量：%s 为 %s。", arg, val);
				MessageVision(me, "tell", msg);
			}
//		else 
//				me->set(key, val);
		else 
			{
				snprintf(msg, 255, "你设置环境变量：%s 为 %s 非法。", arg, val);
				MessageVision(me, "tell", msg);
			}
		return 1;
	}

	DEFINECMD(Unset)
	{
		char key[80];
		if(! strlen(arg)) return 0;
		
		snprintf(key, 80, "env/%s", arg);
		me->del(key);
		tell_object(me, "Ok.");
		return 1;
	}

	DEFINECMD(Mudage)
	{
		int sec, min, hrs, day, mon, age;
		char msg[80], tmp[255], str[255];
   
		if( me->query("hp") < 10 )
			return notify_fail("你的精神不能集中来算自己的年岁。");
     
		age = me->query("mud_age");

		sec = age % 60;
		age /= 60;
		min = age % 60;
		age /= 60;
		hrs = age % 24;
		age /= 24;
		day = age % 30;
		mon = age / 30;
   
		msg[0] = 0;
		if(mon)
			snprintf(msg, 80, "%s月",  chinese_number(mon, str));
		
		if(day)
		{
			snprintf(tmp, 80, "%s天", chinese_number(day, str));
			strcat(msg, tmp);
		}
		
		if(hrs)
		{
			snprintf(tmp, 80, "%s小时", chinese_number(hrs, str));
			strcat(msg, tmp);
		}

		me->add("hp", -5);

		tell_object(me, snprintf(tmp, 255, "你已经为%s奋斗%s了。", MUD_NAME, msg));
		return 1;
	}

	//修改密码
	DEFINECMD(Passwd)
	{		
		char msg[40];

		analyse_string(arg, msg, 40);

		//检测旧密码
		if(! me->query_temp("pending/modify_pass"))
		{			
			if(! VerifyUser(me->querystr("id"), arg))
				return notify_fail("与原密码不符，不能设置新密码！");
			
			if(! VerifyPassword(me->id(1), msg))
				return notify_fail("身份验证未通过!");

			me->set_temp("pending/modify_pass", 1);
			tell_object(me, "旧密码检测通过，请继续输入新密码！");
			return 1;
		}

		if(strlen(arg) < 5) return notify_fail("密码不能少于5个字元！");
		if(strlen(arg) > 20) return notify_fail("您的密码也太长了！");

		if(! ChangePassword(me->querystr("id"), arg))
			return notify_fail("修改密码失败！");

		me->delete_temp("pending/modify_pass");
		tell_object(me, "修改密码成功！");
		return 1;
	}

	//验证玩家身份
	DEFINECMD(Validate)
	{		
		char msg[40];
		
		analyse_string(arg, msg, 40);
		
		if(!me->query_temp("validate"))
		{			
			if(! VerifyUser(me->querystr("id"), arg))
				return notify_fail("密码不符，不能进行进一步的命令操作！");
			
			if(! VerifyPassword(me->id(1), msg))
				return notify_fail("暗码不符，不能进行进一步的命令操作！");
			
			me->set_temp("validate", 1);
			tell_object(me, "身份验证通过，你现在可以继续进行你的操作！");
		}
		return 1;
	}

	//修改暗码
	DEFINECMD(VerifyPass)
	{		
		char msg[40];

		analyse_string(arg, msg, 40);
		if(! msg[0])
		{
			strncpy(msg, arg, 40)[39] = 0;	
			arg[0] = 0;			
		}
		
		if(! VerifyPassword(me->id(1), arg))
			return notify_fail("身份验证未通过!");
			
		if(strlen(msg) < 5) return notify_fail("暗码不能少于5个字元！");
		if(strlen(msg) > 20) return notify_fail("您的暗码也太长了！");

		if(! ChangeVerifyPassword(me->querystr("id"), msg))
			return notify_fail("修改暗码失败！");

		tell_object(me, "修改暗码成功！");
		return 1;
	}

	//升级系统
	DEFINECMD(Upgrade)
	{
		int level = me->query("level");
		LONG valid_exp = me->query_valid_exp();	//可用来升级的经验
		LONG need_exp = CChar::Level2Exp(level + 1) - CChar::Level2Exp(level);
	
		if(valid_exp < need_exp)
			return notify_fail("你当前的经验不够升一级！");

		me->set("level", level + 1);
		setup_char(me);
		tell_object(me, "升级成功！");
		me->FlushMyInfo();
		return 1;
	}

	//关闭频道
	DEFINECMD(Tune)
	{
		CVector * v;
		char msg[80];
		
		v = me->queryvec("channels");

		if(arg) 
		{
			if(v && v->find(arg) != v->end() )
			{
				tell_object(me, snprintf(msg, 80, "关闭%s频道。", arg));
				v->remove(arg);			 	
				return 1;
			}
		}     
        
		tell_object(me, "要打开某个频道只要用该频道说话即可。");
		return 1;
   	}

	

	//投票
	DEFINECMD(Vote)
	{
		char channel[20];
		CMapping voted_player;
		char msg[255];
				
		static LONG vote_id = 100;

		analyse_string(arg, channel, 20);
		if(strcmp(arg, "open")!=0 && strcmp(arg, "close")!=0 ||! strlen(channel))
			return notify_fail("用指令/vote <close|open> <频道>");

		if (me->query("age") < VOTE_AGE_LIMIT || me->query("level") < VOTE_LEVEL_LIMIT) 
		{
			if (me->query("age") < VOTE_AGE_LIMIT) 
				return notify_fail("你年龄不满%d岁，没有投票权。", VOTE_AGE_LIMIT);

			if (me->query("level") < VOTE_LEVEL_LIMIT) 
				return notify_fail("你等级不到%d级，没有投票权。", VOTE_LEVEL_LIMIT);
		}

		const char * choicename = (strcmp(arg, "open")== 0 ? "打开":"关闭");
    
		if(strcmp(channel, "chat") != 0 && strcmp(channel, "party") != 0
			&& strcmp(channel, "new") != 0)
			return notify_fail("不能%s%s这个频道。", choicename, channel);

		CUser * player;
		if (! (player = find_player(target))) 
			return notify_fail("目前找不到这个人。");

		char myvariable[80];
		const char * myid = me->id(1);

		snprintf(myvariable, 80, "%s_%s_%s", arg, channel, player->id(1)); // for checking double votes.
    
		char block_key[20];
		
		snprintf(block_key, 20, "chblk/%s", channel);

		if( strcmp(arg, "close") == 0)
		{			
		   if (current_time < player->query(block_key))
				return notify_fail("%s的交谈频道已经被关闭了。", player->name());
		}
		else 
		{
			if (current_time > player->query(block_key))
				return notify_fail("%s的交谈频道已经被打开了。", player->name());
		}
		
		voted_player.copyMapping(g_Channel.voted_players.querymap(myvariable));

		if (! voted_player.undefinedp(myid)) 
			return notify_fail("你已经投过相同的票了。");
		else 
		{
			CMapping m;

			m.set("obj", me->object_id());
			m.set("ip", GetIP(me));
			voted_player.set(myid, m);
		}

		int total_votes_required = determine_total();
		int votes_count = counting(&voted_player, myvariable);

		g_Channel.voted_players.set(myvariable, voted_player);

        // remove vote in 5 min if not enough people respond
		
        if( g_Channel.votes_casted.undefinedp(myvariable))
        {
            g_Channel.votes_casted.set(myvariable, 1);

			//取消动议
			vote_id++;
			g_Channel.set(snprintf(msg, 80, "cancel_vote%ld/myvariable", vote_id), myvariable);
			g_Channel.set(snprintf(msg, 80, "cancel_vote%ld/choicename", vote_id), choicename);
			g_Channel.set(snprintf(msg, 80, "cancel_vote%ld/playername", vote_id), player->name(1));
			g_Channel.call_out(nullify_vote, 600, vote_id);
        }

        int diff = total_votes_required - votes_count;
		
        // announce to mu
		MAP2USER * ulist = users();
		const char * ch_channel = "闲聊";

		if(strcmp(channel, "new") == 0)
			ch_channel = "新手";
		if(strcmp(channel, "party") == 0)
			ch_channel = "门派";

        if (diff>0)
		{
			Message("vote", snprintf(msg, 255, "$BLK【表决】%s(%s)投票%s%s(%s)的%s频道，需要%d票通过，还差%d票！$COM",
				me->name(1), me->id(1), choicename, player->name(1), player->id(1),
				ch_channel,
				total_votes_required, diff), ulist);
		}
        else
        {
			if (strcmp(arg, "open") == 0) 
				player->del(block_key);
			else 
				player->set(block_key, current_time + 86400);
       
			// block for 1 day.
			g_Channel.voted_players.del(myvariable);
			g_Channel.votes_casted.del(myvariable);
			Message("vote", snprintf(msg, 255, "$HIW【表决】%s(%s)投票%s%s(%s)的%s频道，%s的交谈频道被%s了！$COM", 
				me->name(1), me->id(1), choicename, player->name(1), player->id(1),
				ch_channel,				
				player->name(1), choicename), ulist);
		}

		return 1;
	}

	static int determine_total()
	{
		int total_required = 0;
		CMapping site;
		const char * ip;

		// to determine how many votes necessary to block channel

		MAP2USER * ulist = users();
		iterator_user p;

		for(p = ulist->begin(); p != ulist->end(); p++)
		{
			if ((p->second)->query("age") > VOTE_AGE_LIMIT && 
				(p->second)->query("level") > VOTE_LEVEL_LIMIT ) 
			{
				ip = GetIP(p->second);
				site.add(ip, 1);
			
    			//每个IP只计一票
				if(site.query(ip) <= 1) 
					total_required++;
			}
		}

		total_required = total_required / 3;
		if (total_required < 3) total_required=3;
		if (total_required > 20) total_required = 20;
		return total_required;
	}

	static int counting(CMapping * players, const char * myvariable) 
	{
		CMapping site;
		const char * ip;
		int count = 0;
    
		CVector v;

		players->keys(v);

		for(int i=0; i<v.count(); i++)
		{
			CMapping * m = players->querymap(v[i]);
			if(! m) continue;

			CUser * obj = find_player(m->query("obj"));

			if(! obj)// this player has logged out.
			{ 
				players->del(v[i]);
				continue;
			}
   
			ip = GetIP(obj);
			site.add(ip, 1);			
	
			// each site can count to max_voter.
			if(site.query(ip) <= 1) 
				count++;
		}    
		
		return count;
	}

	static void nullify_vote(CContainer * ob, LONG vote_id, LONG param2)
	{
		char msg[80];
		const char * myvariable = g_Channel.querystr(snprintf(msg, 80, "cancel_vote%ld/myvariable", vote_id));
		const char * choice = g_Channel.querystr(snprintf(msg, 80, "cancel_vote%ld/choicename", vote_id));
		const char * playername = g_Channel.querystr(snprintf(msg, 80, "cancel_vote%ld/playername", vote_id));

		if (! g_Channel.voted_players.undefinedp(myvariable)) 
		{
			Message("vote", snprintf(msg, 255, "$HIW【表决】因为没有足够的人响应%s%s的交谈频道，投票取消了！$COM", 
				choice, playername), users());

			g_Channel.voted_players.del(myvariable);
			g_Channel.votes_casted.del(myvariable);
		}
	}	

	//查询某玩家是否在线
	DEFINECMD(IfOnline)
	{
		CUser * obj;
		char msg[255];
		
		obj = find_online(snprintf(msg, 40, "%ld", target)); 
					
		if(obj && ! obj->query_temp("net_dead"))
		{
			snprintf(msg, 255, "&C=%d&O=1&U=%ld&N=%s&I=%s&L=%ld&R=%ld&rank=%s&", 
				SENDUSER, obj->object_id(), obj->name(), 
				obj->querystr("id"),
				obj->query("level"), obj->query("repute"),
				query_rank(obj));			
		}
		else
		{
			snprintf(msg, 80, "&C=%d&O=0&U=%ld&I=%ld&", 
				SENDUSER, 0, target);
		}

		me->SendCommand(msg, 1);
		return 1;
	}

	DEFINECMD(RefuseTell)
	{
		char key[80]; 
		CUser * player;

		if(target)
		{
			char msg[80];
			if (! (player = find_player(target))) 
				return notify_fail("目前找不到这个人。");
				
		
			snprintf(key, 80, "notell/%s", player->querystr("id"));			
			tell_object(me, snprintf(msg, 80, "你拒绝收听%s的悄悄话。", player->name()));
		}
		else
		{
			strcpy(key, "notell/all");
			tell_object(me, "你拒绝收听所有人的悄悄话。");
		}
		 
		me->set_temp(key, 1);
		return 1;
	}

	//收听
	DEFINECMD(Listen)
	{
		char key[80];
		CUser * player;

		if(target)
		{
			char msg[80];
			if (! (player = find_player(target))) 
				return notify_fail("目前找不到这个人。");
				
			snprintf(key, 80, "notell/%s", player->querystr("id"));
			me->delete_temp(key);
			me->delete_temp("notell/all");
			tell_object(me, snprintf(msg, 80, "你开始收听%s的悄悄话。", player->name()));
		}
		else
		{
			me->delete_temp("notell");
			tell_object(me, "你开始收听所有人的悄悄话。");
		}

		return 1;
	}

	//其起绰号
	DEFINECMD(NickName)
	{
		char msg[80];
		int len = strlen(arg);
		if(len < 1 || len > 20)
			return notify_fail("起个响亮点的绰号！");

		const char * ptr;

		ptr = check_legal_name(arg);
		if(ptr[0])
			return notify_fail(ptr);
		
		me->set("nickname", arg);
		tell_object(me, snprintf(msg, 80, "你改变绰号为“%s”。", arg));
		return 1;
	}

	//与玩家组队
	DEFINECMD(Pary)
	{
		//禁止在设置为no_invite的场景使用Talk命令 秦波 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_invite")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("这里禁止邀请他人。");

		CChar * who;
		char msg[80];

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("你要邀请谁加入你的队伍？");

		if(who == me)
			return notify_fail("你对自己说：算了还是自己邀请自己吧。");

		if(me->querystr_temp("pary/master")[0])
			return notify_fail("你现在正在与别人队伍中，要想自己组建队伍需要先行离队。");

		if(me->query_temp("pary/number")>4)
			return notify_fail("已经邀请了这么多的队友，足够闯荡江湖了吧？");

		if(EQUALSTR(who->querystr_temp("pary/master"), me->querystr("id")))
			return notify_fail("对方已经接受了你的邀请。");

		message_vision("$HIC$N热情的对$n说：朋友，一起组队行走江湖吗？", me, who);
		me->set_temp("pary/pary", who->querystr("id"));

		//增加菜单指令 lanwood 2001-03-23 注意，此处不能用$1代替自己。因为对方未必选中的是你。
		char tmp[40];

		me->AddMenuItem(snprintf(msg, 80, "接受%s的组队邀请", me->name()), 
			snprintf(tmp, 40, "$0accept_pary %ld", me->object_id()), who);

		me->AddMenuItem("拒绝组队邀请", "", who);
		me->SendMenu(who);

		return 1;
	}

	//接受组队邀请
	DEFINECMD(Accept_pary)
	{
		CChar * who;
		char msg[40];

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("你要接受谁的邀请？");
		
		if(who == me)
			return notify_fail("你对自己说：算了还是自己邀请自己吧。");

		if(me->querystr_temp("pary/master")[0])
			return notify_fail("你现在已经和别人组队过了。");

		if(DIFFERSTR(who->querystr_temp("pary/pary"), me->querystr("id")))
			return notify_fail("对方并没有邀请你。");

		if(me->querystr_temp("pary/pary")[0])
			return notify_fail("你已经对其他人发出了组队邀请，暂时不能接受别人的组队邀请。");

		message_vision("$HIC$N接受了$n的组队邀请。", me, who);
		me->set_temp("pary/master", who->querystr("id"));
		me->set_leader(who);
		who->delete_temp("pary/pary");
		who->add_temp("pary/number",1);
		who->set_temp(snprintf(msg, 40,"pary/friend_%s",me->querystr("id")),1);

		who->say("你接受了组队邀请。", me);
		who->SendMenu(me);

		return 1;
	}

	//离开队伍
	DEFINECMD(Paryleave)
	{
		CChar * who;
		char msg[255];

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("你要解除与谁的组队关系？");
		
		if(who == me)
			return notify_fail("这样做好象不合适吧？");

		if(DIFFERSTR(me->querystr_temp("pary/master"), who->querystr("id")))
			return notify_fail("你并没有和对方组队。");

		if(!who->query_temp(snprintf(msg, 255,"pary/friend_%s",me->querystr("id"))))
		{
			me->delete_temp("pary/master");
			return notify_fail("对方并没有与你组队，或已经将你赶出了队伍。");
		}

		message_vision("$HIC$N取消与$n的组队。", me, who);
		tell_object(who, snprintf(msg, 255, "$HIR%s(%s)取消了与你的组队。",me->name(),me->id()));
		me->delete_temp("pary/master");
		me->set_leader(me);
		who->add_temp("pary/number",-1);
		who->delete_temp(snprintf(msg, 255,"pary/friend_%s",me->querystr("id")));

		me->say(snprintf(msg, 255,"你取消了与%s的组队。",who->name()),me);
		who->SendMenu(me);

		return 1;
	}

	//踢除出队
	DEFINECMD(Parykick)
	{
		CChar * who;
		char msg[255];

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("你要解除与谁的组队关系？");
		
		if(who == me)
			return notify_fail("这样做好象不合适吧？");

		if(DIFFERSTR(who->querystr_temp("pary/master"), me->querystr("id")))
		{
			me->add_temp("pary/number",-1);
			me->delete_temp(snprintf(msg, 255,"pary/friend_%s",who->querystr("id")));
			return notify_fail("对方并没有与你组队，或已经自己离开了队伍。");
		}

		if(who->query_temp(snprintf(msg, 255,"pary/friend_%s",who->querystr("id"))))
			return notify_fail("你并没有和对方组队。");

		message_vision("$HIC$N取消与$n的组队。", me, who);
		tell_object(who, snprintf(msg, 255, "$HIR%s(%s)取消了与你的组队。",me->name(),me->id()));
		who->delete_temp("pary/master");
		who->set_leader(who);
		me->add_temp("pary/number",-1);
		me->delete_temp(snprintf(msg, 255,"pary/friend_%s",who->querystr("id")));

		who->say(snprintf(msg, 255,"你取消了与%s的组队。",who->name()),me);
		who->SendMenu(me);

		return 1;
	}

	//查看对方货物
	DEFINECMD(ListGoods)
	{
		CChar * who;
		char msg[255], cmd[40];

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("你要查看谁的货物？");
		
		if(who == me)
			return notify_fail("请用红顶商人道具查看。");

		DTItemList * list = who->Get_ItemList();
		POSITION p = list->GetHeadPosition();
		int i = 0;
		
		while(p)
		{
			CContainer * obj = list->GetNext(p);
			LONG val = obj->query_temp("trade/value");

			if(! val) continue;
			if(DIFFERSTR(obj->querystr_temp("trade/owner"), who->id(1)) ) continue;

			snprintf(msg, 255, "%s ：%ld", obj->name(), val);
			who->AddMenuItem(msg, snprintf(cmd, 40, "$0buy $1 %ld", obj->object_id()), me);
			i++;
		}

		if(! i)
			who->say(snprintf(msg, 255, "你对%s的商品似乎不感兴趣。", who->name()), me);

		who->SendMenu(me);
		return 1;
	}

	//购买对方的货物
	DEFINECMD(Buy)
	{
		CChar * who;
		char msg[255];
		LONG val = 0;

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("你要买看谁的货物？");
		
		if(who == me)
			return notify_fail("那还用买吗。");

		CContainer * obj = who->Present(atol(arg));

		if(! obj || obj->querystr("owner")[0] || DIFFERSTR(obj->querystr_temp("trade/owner"), who->id(1))
			|| ! (val = obj->query_temp("trade/value")) )
			return notify_fail("对方不打算卖给你。");

		if(! CMoney::Player_Pay(me, val))
			return notify_fail("你很想买%s，可是摸摸口袋，只好脸红的离开了。", obj->name());

		message_vision(snprintf(msg, 255, "$N从$n那里买下了%s，付给$n数量%ld的金币。", obj->name(), val), me, who);		

		if(! obj->move(me))
		{
			obj->move(me->environment());
			tell_object(me, snprintf(msg, 255, "你买下了%s，但你拿不动，只好把它放在地上。", obj->name()));
		}
		
		CMoney::Pay_Player(who, val);

		return 1;
	}

	//邀请其他人来自己家
	DEFINECMD(invite)
	{
		//禁止在设置为no_invite的场景使用Talk命令 秦波 2002-10-09
		CContainer * env = me->environment();
		if((env->query("no_invite")||env->query("no_all"))&&!wizardp(me))
			return notify_fail("这里禁止邀请他人。");

		CChar * who;
		char msg[80];

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("你要邀请谁去你的家做客？");

		if(! me->querystr("resident")[0])
			return notify_fail("你还没有定居，怎么邀请人家？");

		if(who == me)
			return notify_fail("你对自己说：算了还是自己邀请自己吧。");

		if(EQUALSTR(who->querystr_temp("invite"), me->querystr("id")))
			return notify_fail("对方已经接受了你的邀请。");

		message_vision("$HIC$N热情的对$n说：请到我家来玩吧！", me, who);
		me->set_temp("pending/invite", who->querystr("id"));

		//增加菜单指令 lanwood 2001-03-23 注意，此处不能用$1代替自己。因为对方未必选中的是你。
		char tmp[40];

		me->AddMenuItem(snprintf(msg, 80, "接受%s的邀请", me->name()), 
			snprintf(tmp, 40, "$0accept %ld", me->object_id()), who);

		me->AddMenuItem("拒绝邀请", "", who);
		me->SendMenu(who);

		return 1;
	}

	//接受邀请
	DEFINECMD(accept)
	{
		CChar * who;

		if(! (who = GetRoomChar(me, target)) )
			return notify_fail("你要接受谁的邀请？");
		
		if(who == me)
			return notify_fail("你对自己说：算了还是自己邀请自己吧。");

		if(EQUALSTR(me->querystr_temp("invite"), who->querystr("id")))
			return notify_fail("你已经接受了对方的邀请。");

		if(DIFFERSTR(who->querystr_temp("pending/invite"), me->querystr("id")))
			return notify_fail("对方并没有邀请你。");

		message_vision("$HIC$N接受了$n的邀请。", me, who);
		me->set_temp("invite", who->querystr("id"));
		who->delete_temp("pending/invite");

		who->say("你接受了邀请。", me);
		who->SendMenu(me);

		return 1;
	}

	//刷新玩家收徒经验
	DEFINECMD(RecruitExp)
	{
		LONG recruit_exp = 0;
		char msg[255];

		const char * master = me->id(1);

		if(wizardp(me))
		{
			CChar * who;

			if(! (who = GetRoomChar(me, target)) 
				&& ! (who = find_player(target)) )
					who = me;
						
			if(strlen(arg)) 
				master =arg;
			else 
				master = who->id(1);
		}
		
		CMapping * ptr = g_Channel.query_recruit(master);

		if(! ptr || ! ptr->GetCount())
			return notify_fail("你还没有收徒经验！");

		tell_object(me, snprintf(msg, 255, "当前你有徒弟%ld个：", ptr->GetCount()));

		CVector v;

		ptr->keys(v);

		for(int i=0; i<v.count(); i++)
		{
			CMapping * p = ptr->querymap(v[i]);
			tell_object(me, 
				snprintf(msg, 255, "徒弟%s(%s)贡献经验：%ld。(%s)",
					p->querystr("name"),
					v[i], 					
					p->query("exp") / 100,
					p->query("apprentice") ? "弟子" : "----"));

			recruit_exp += (p->query("exp") / 100);
		}
		
		if(recruit_exp > 50)
			me->set("recruit_exp", recruit_exp);
		else
			me->set("recruit_exp", 50);

		me->FlushMyInfo();

		tell_object(me, snprintf(msg, 255, "你的收徒经验共计%ld。", recruit_exp));
		return 1;
	}	

	//同步
	DEFINECMD(mv)
	{
		LONG bx, by, ex, ey, ac;
		sscanf(arg, "%ld %ld %ld %ld %ld", &bx, &by, &ex, &ey, &ac);

		//玩家定位
		me->set_temp("map/bx", bx);
		me->set_temp("map/by", by);
		me->set_temp("map/ex", ex);
		me->set_temp("map/ey", ey);
		me->set_temp("map/ac", ac);

		//向房间内其他玩家发送信息
		DTItemList * t = (me->environment())->Get_ItemList();
		POSITION p = t->GetHeadPosition();
		CContainer * obj;

		while(p)
		{
			obj = t->GetNext(p);
			if(obj == me) continue;
			if(userp(obj))		//是玩家
				((CUser *)obj)->LocationObject(me);
		}

		return 1;	
	}

	//Loading 结束，初始定位 loc 0 x y
	DEFINECMD(loc)
	{
		LONG x, y;
		
		if(! userp(me)) return 0;

		//if(! me->is_loading())
		//	return notify_fail("你并没有装载地图。");

		sscanf(arg, "%ld %ld", &x, &y);
		me->set_temp("map/bx", x);
		me->set_temp("map/by", y);
		me->set_temp("map/ex", x);
		me->set_temp("map/ey", y);
		me->set_temp("map/ac", 0l);
		
		me->delete_temp("client/loading");

		(me->environment())->OnEnter(me);			//正式进入地图
		
		((CUser * )me)->LocationObject(me);

		return 1;
	}	

	//----------------------1.71版-------lanwood 2001-03-25 --------------------------
	//增加好友
	DEFINECMD(addfriend)
	{
		CChar * who;
		
		notify_fail("目标不存在！");

		if(! strlen(arg))
		{
			if( ! (who = find_player(target)) )
				return 0;
		}
		else if( !(who = find_online(arg)) )
				return 0;

		if(((CUser *)me)->SetFriend(who->id(1), 1))
		{
			//通知客户端
			((CUser *)me)->notify_online(who);
			return 1;
		}

		return 0;
	}

	//删除好友
	DEFINECMD(remfriend)
	{
		notify_fail("此目标已不在你的名单中。");
		return ((CUser *)me)->SetFriend(arg, 0);
	}

	//显示在线玩家列表 who 0 1 1带页码 从0开始 类似于商品信息
	//每页显示10人
	DEFINECMD(who)
	{
		char type[20];
		analyse_string(arg, type, 20);
		int nBegin = atol(arg) * 12;		
		((CUser *)me)->SendUserOnline(nBegin, nBegin + 12, atol(type));
		return 1;
	}

	//下载用户详细资料
	DEFINECMD(downloaduser)
	{
		CUser * who = find_player(target);
		if(! who) return 0;

		((CUser *)me)->ReceiveUserInfo(who);
		return 1;
	}

	//拒绝收听某频道信息
	DEFINECMD(refuse)
	{
		CMapping m;
		char msg[80];

		m.set("practice", 1);
		m.set("study", 1);
		m.set("exercise", 1);
		m.set("combat", 1);

		if(! strlen(arg))
		{
			CMapping * ch = me->querymap_temp("refuse");
			if(! ch) return notify_fail("你目前没有设置任何信息通道。");	

			tell_object(me, "你目前已经关闭的信息通道有：");

			CVector v;

			ch->keys(v);
			for(int i=0; i<v.count(); i++)
				tell_object(me, snprintf(msg, 80, "%s通道", v[i]));
			
			return 1;
		}

		//打开所有通道
		if(strcmp(arg, "none") == 0)
		{
			me->delete_temp("refuse");
			tell_object(me, "信息通道恢复正常。");
			return 1;
		}

		if(! m.query(arg))
			return notify_fail("不允许关闭该信息通道。");

		me->set_temp(snprintf(msg, 80, "refuse/%s", arg), 1);
		tell_object(me, snprintf(msg, 80, "OK，关闭了%s的信息通道！", arg));
		return 1;
	}
	
};
