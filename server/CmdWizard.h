int ChangePassword(const char * id, const char * pass);
int ChangeVerifyPassword(const char * id, const char * pass);
int	SetInvalidAccount(const char * id, int freeze);
void DumpObject();
extern BOOL	g_bReboot;
void printf_all_mappings();

#define		MONSTER_NUM		313

class CCmdWizard
{
public:
	CCmdWizard()
	{
		m_Grant.set("goto", 50);
		m_Grant.set("summon", 50);
		m_Grant.set("promote", 50);
		m_Grant.set("kickout", 60);
		m_Grant.set("whois", 70);
		m_Grant.set("where", 70);
		m_Grant.set("clone", 80);
		m_Grant.set("clonenpc", 80);
		m_Grant.set("smash", 80);
		m_Grant.set("stop", 50);
		m_Grant.set("full", 70);
		m_Grant.set("call", 90);
		m_Grant.set("set_skill", 90);
		m_Grant.set("clear_skill", 100);
		m_Grant.set("restore_exp", 100);
		m_Grant.set("ban", 60);
		m_Grant.set("unban", 60);
		m_Grant.set("freeze", 70);
		m_Grant.set("unfreeze", 70);
		m_Grant.set("chpass", 80);
		m_Grant.set("chverifypass", 90);
		m_Grant.set("recover", 90);
		m_Grant.set("wholist", 50);
		m_Grant.set("snoop", 60);
		m_Grant.set("debug", 80);
		m_Grant.set("chblk", 50);

		m_Grant.set("reboot", 90);
		m_Grant.set("reward_exp", 80);
		m_Grant.set("sub_exp", 80);
		m_Grant.set("reward_money", 80);
		m_Grant.set("systemparam", 90);
		m_Grant.set("skillparam", 90);
		m_Grant.set("data", 70);

		m_Grant.set("tail", 90);
		m_Grant.set("update", 80);
		m_Grant.set("force_save", 80);
		m_Grant.set("freeip", 60);
		
		m_Cmd["goto"] = Goto;
		m_Cmd["summon"] = Summon;
		m_Cmd["promote"] = Promote;
		m_Cmd["kickout"] = Kick;
		m_Cmd["whois"] = Whois;
		m_Cmd["where"] = WhereMe;
		m_Cmd["clone"] = CloneObject;
		m_Cmd["clonenpc"] = CloneNpc;
		m_Cmd["smash"] = Smash;
		m_Cmd["stop"] = StopBattle;
		m_Cmd["full"] = Full;
		m_Cmd["call"] = Call;
		m_Cmd["set_skill"] = Set_Skill;
		m_Cmd["clear_skill"] = Clear_Skill;
		m_Cmd["restore_exp"] = Restore_Exp;
		m_Cmd["recruit_exp"] = recruit_exp;
		m_Cmd["ban"] = ban;
		m_Cmd["unban"] = unban;
		m_Cmd["freeze"] = freeze;
		m_Cmd["unfreeze"] = unfreeze;
		m_Cmd["chpass"] = chpass;
		m_Cmd["chverifypass"] = chverifypass;
				
		m_Cmd["recover"] = recover;
		m_Cmd["wholist"] = who;
		m_Cmd["snoop"] = snoop;

		m_Cmd["debug"] = debug;
		m_Cmd["reboot"] = reboot;

		m_Cmd["reward_exp"] = RewardExp;
		m_Cmd["sub_exp"] = SubExp;
		m_Cmd["reward_money"] = RewardMoney;

		m_Cmd["systemparam"] = SysParam;
		m_Cmd["skillparam"] = SkillParam;

		m_Cmd["data"] = Data;		//玩家数据
		m_Cmd["chblk"] = Chblk;

		m_Cmd["tail"] = Tail;
		//m_Cmd["makemonster"] = MakeMonster;

		m_Cmd["update"] = Update;
		m_Cmd["force_save"] = Save;

		m_Cmd["print_mapping"] = PrintMapping;
		m_Cmd["freeip"] = freeip;

	};

	~CCmdWizard(){};

	typedef int (* func)(CChar * me, LONG target, char * arg);
	typedef map<string, func, less<string> > CMDMAP;
	CMDMAP m_Cmd;
	CMapping m_Grant;

	int Handlecommand(char * cmd, CChar * me, LONG target, char * arg)
	{
		CMDMAP::iterator p;
		if((p = m_Cmd.find(cmd)) == m_Cmd.end()) return -1;
		//判断权限
		if(m_Grant.query(cmd) > me->query("grant")) return -1;
		return ((*p).second)(me, target, arg);
	}

	DEFINECMD(Promote)
	{
		int nGrant;
		char msg[255];
		CChar * who;

		if(! (who = find_player(target)) ) return 0;
	
		nGrant = atoi(arg);			//提升权限级别
		if(nGrant >= me->query("grant") || nGrant < CChar::GRANT_PLAYER)	//不可以低于PLAYER。[30~50)为玩家权限区间
			return notify_fail("你不能改变对方的权限到此级别！");
		
		if(me->query("grant") <= who->query("grant"))
			return notify_fail("你无权改变对方的权限！");
				
		who->set("grant", nGrant);	//授权
				
		snprintf(msg, 255, "%s提升%s的权限到%d级。", me->name(), who->name(), nGrant);
		tell_object(who, msg);
		who->Save();

		g_Channel.do_channel(&g_Channel, 0, "sys", msg);
		output_error(msg);

		return 1;
	}

	DEFINECMD(Full)
	{
		char msg[255];
		CChar * who;

		if(! (who = GetRoomChar(me, target)) 
			&& ! (who = find_player(target)) ) 
			return 0;			

		who->set("hp", who->query("max_hp"));
		who->set("eff_hp", who->query("max_hp"));
		who->set("mp", who->query("max_mp"));
		who->set("eff_mp", who->query("max_mp"));
		snprintf(msg, 255, "只见%s浑身金光乍现，散发无穷活力！", who->name());

		who->FlushMyInfo();
		MessageVision(who, "chat", msg);
		return 1;
	}

	//他是谁
	DEFINECMD(Whois)
	{
		char cmd[255];
		const char * msg;
		CUser * who;

		if(! (who = find_player(target))) return 0;

		CContainer * env = who->environment();
		if(! env) 
		{
			output_error("%s无环境中。", who->name());
			msg = "无环境";
		}
		else
			msg = env->name();
		
		tell_object(me, snprintf(cmd, 255, "【系统】%s(%s)：位于%s，在线%ld秒，发呆%ld秒。客户端：%s版", who->name(1), GetIP((CChar *)who), msg,
			current_time - who->query("login/time"), who->query_idle(),
			who->querystr_temp("client/version")));
		
		return 1;
	}

	//踢人
	DEFINECMD(Kick)
	{
		char cmd[255];
		CUser * who;
		
		if(! (who = find_online(arg)) ) return notify_fail("格式：kickout <ID>");

		//判断权限
		if(who != me && who->query_grant() >= me->query_grant())
			return notify_fail("你没有权力踢出对方。");

		snprintf(cmd, 255, "【系统】%s(%s)被%s请出了这个世界。", who->name(), GetIP((CChar *)who), me->name());	
		MessageVision(me, "notify", cmd);

		me->call_out(do_kick, 1, who->object_id());
		return 1;
	}

	//踢人容易当机! lanwood 2001-07-30 修改BUG 在User_Handle_Loop里.
	static void do_kick(CContainer * ob, LONG param1, LONG param2)
	{
		CUser * who;

		if(! (who = find_player(param1)) ) return;

		DropAll(who);
		who->SaveToServer();

		who->Offline();

		DESTRUCT_OB(who, "cmd:kickout");
	}

	//查找物件位置
	DEFINECMD(WhereMe)
	{
		CContainer * env, * obj;
		char msg[255];
		
		if(! target) target = atol(arg);
		if( ! (obj = find_object(target)) )
		{
			MessageVision(me, "tell", "【巫师】该物件不存在！");
			return 1;
		}

		if(! (env = obj->environment()) )
		{
			snprintf(msg, 255, "【巫师】物件%s无环境。", obj->name());
			MessageVision(me, "tell", msg);
			return 1;
		}

		snprintf(msg, 255, "【巫师】物件%s目前处于%s(%ld)中。", obj->name(), env->name(), env->object_id());
		MessageVision(me, "tell", msg);
		return 1;
	}

	//克隆NPC
	DEFINECMD(CloneNpc)
	{
		CNpc * obj;
		char msg[255];
			
		if( !(obj = load_npc(arg) ) ) return 0;	//克隆失败

		obj->move(me->environment());
		
		tell_object(me, snprintf(msg, 255, "你凌空一指，变出一个%s来。", obj->name()));
			
		return 1;
	}

	//克隆物品
	DEFINECMD(CloneObject)
	{
		CContainer * obj;
		char msg[255];
		LONG nNum;
			
		analyse_string(arg, msg, 40);
		nNum = atol(arg);
		
		if( !(obj = load_item(msg) ) ) return 0;	//克隆失败

		if(nNum) obj->set_amount(nNum);

		if( ! obj->move(me))
			obj->move(me->environment());

		tell_object(me, snprintf(msg, 255, "你凌空一指，变出一个%s来。", obj->name(1)));
			
		return 1;
	}

	//毁灭
	DEFINECMD(Smash)
	{
		char msg[255];
		CContainer * who;

		if(! (who = GetRoomObject(me, target)) &&
			! (who = GetSelfObject(me, target)) )
			return 0;

		snprintf(msg, 255, "%s从天上叫下一道闪电，劈在了%s身上。", me->name(), who->name());
		MessageVision(me, "chat", msg);

		if(who->Query(CChar::IS_FIGHTROOM))	//战斗
		{
			((CFightRoom * )who)->End_Fight();
//			destruct(who);
			return 1;
		}

		//生物
		if(who->is_character())
		{
			((CChar *)who)->die();		
		}
		else if(! who->Query(CChar::IS_BOX))
		{
			DESTRUCT_OB(who, "cmd::smash");			
		}

		return 1;
	}

	//summon
	DEFINECMD(Summon)
	{
		char msg[255];
		CChar * who;
		
		if(! (who = find_player(target)) )
			return notify_fail("你想抓谁过来？");

		//判断权限
		if(who->query_grant() >= me->query_grant())
			return notify_fail("你的等级不够抓对方过来。");

		message_vision("$HIB突然一道闪电掠过，$N的身影在烟雾中消失了。", who);
		who->move(me->environment());
		tell_object(who, snprintf(msg, 255, "你一阵头晕目眩，再睁眼时发现是%s把你弄过来的。", me->name()));

		tell_room(me->environment(), snprintf(msg, 255, "$HIG一朵莲花冉冉盛开，你看到%s从莲心上跳了下来。", who->name()), who);
		return 1;
	}

	//瞬间移动
	DEFINECMD(Goto)
	{
		char msg[255];
		CChar * sprite = FindSprite(me);
		CChar * who;
		CContainer * env;

		if(arg[0])
		{
			if(! (env = load_room(arg)) )
				return notify_fail("你想去哪？");
		}
		else
		{
			if(! (who = find_player(target)) )
				return notify_fail("你想去哪里？");

			env = who->environment();
		}

		if(! env)
			return notify_fail("你去不了外太空！");

		//客座巫师只能去jy
		if(me->query("grant") < 70 && ! env->query("wiz_room"))
			return notify_fail("你还是走着去吧。");

		message_vision("$BLK只见$N伸手在空中画了个门，矮身钻了进去。", me);
		
		me->move(env);
		if(sprite) sprite->move(env);

		tell_room(env, snprintf(msg, 255, "$BLK空中飘过一朵祥云，%s从云上跳了下来。", me->name()), me);
		
		return 1;
	}

	//停止战斗
	DEFINECMD(StopBattle)
	{
		char msg[255];
		CContainer * env = me->environment();

		if(! env->Query(CChar::IS_FIGHTROOM)) return 0;
		snprintf(msg, 255, "%s大喝一声：反了反了，上班时间玩游戏！都给我干活去！", me->name());
		MessageVision(me, "chat", msg);
	
		((CFightRoom *)env)->End_Fight();								//结束战斗
//		destruct(env);

		return 1;
	}

	//设置系统参数
	DEFINECMD(SysParam)
	{
		char arg1[255], arg2[255];

		analyse_string(arg, arg1, 255);
		analyse_string(arg1, arg2, 255);	

		if(strcmp(arg, "set") == 0 || strcmp(arg, "setstr") == 0)
		{
			if(strcmp(arg, "set") == 0 
				&& (arg2[0] == '-' || (arg2[0] >='0' && arg2[0] <='9')) )
				g_Combatd.set(arg1, atol(arg2));
			else 
				g_Combatd.set(arg1, arg2);
						
			tell_object(me, snprintf(arg, 255, "%s设定系统参数%s为%s。", me->name(1), arg1, arg2));
			g_Channel.do_channel(&g_Channel, 0, "sys", arg);			
			return 1;
		}

		if(strcmp(arg, "delete") == 0)
		{			
			g_Combatd.del(arg1);
			tell_object(me, snprintf(arg, 255, "删除系统参数%s。", arg1));
		
			return 1;
		}

		if(strcmp(arg, "query") == 0)
		{
			snprintf(arg, 255, "系统参数：%s=%ld", arg1, g_Combatd.query(arg1));
			tell_object(me, arg);
			return 1;
		}

		if(strcmp(arg, "querystr") == 0)
		{
			snprintf(arg, 255, "系统参数：%s=%s", arg1, g_Combatd.querystr(arg1));
			tell_object(me, arg);
			return 1;
		}

		return 0;
	}

	//设置技能参数 skillparam tianyu_qijian set valid_force bahuang_gong
	DEFINECMD(SkillParam)
	{
		char arg0[255], arg1[255], arg2[255];

		analyse_string(arg, arg0, 255);
		analyse_string(arg0, arg1, 255);
		analyse_string(arg1, arg2, 255);	

		CSkill * sk = load_skill(arg);
		strcpy(arg, sk->name(1));

		if(strcmp(arg0, "set") == 0 || strcmp(arg0, "setstr") == 0)
		{
			if(strcmp(arg0, "set") == 0 
				&& (arg2[0] == '-' || (arg2[0] >='0' && arg2[0] <='9')) )
				sk->set(arg1, atol(arg2));
			else 
				sk->set(arg1, arg2);
						
			tell_object(me, snprintf(arg0, 255, "%s设定技能%s参数%s为%s。", me->name(1), arg, arg1, arg2));
			g_Channel.do_channel(&g_Channel, 0, "sys", arg0);			
			return 1;
		}

		if(strcmp(arg0, "delete") == 0)
		{			
			sk->del(arg1);
			tell_object(me, snprintf(arg0, 255, "删除技能%s参数%s。", arg, arg1));
		
			return 1;
		}

		if(strcmp(arg0, "query") == 0)
		{
			snprintf(arg0, 255, "技能%s参数：%s=%ld", arg, arg1, sk->query(arg1));
			tell_object(me, arg0);
			return 1;
		}

		if(strcmp(arg0, "querystr") == 0)
		{
			snprintf(arg0, 255, "技能%s参数：%s=%s", arg, arg1, sk->querystr(arg1));
			tell_object(me, arg0);
			return 1;
		}

		return 0;
	}

	//呼叫函数 set_name( 20)
	DEFINECMD(Call)
	{
		char arg1[255], arg2[255];
		CContainer * who;

		if(! target) who = me->environment();
		else if(! (who = GetRoomObject(me, target))
			&& ! (who = GetSelfObject(me, target)) 
			&& !(who = find_player(target)))
			return notify_fail("请选中目标。");			
		
		analyse_string(arg, arg1, 255);
		analyse_string(arg1, arg2, 255);	

		if(strcmp(arg, "set") == 0 || strcmp(arg, "setstr") == 0)
		{
			if(strcmp(arg1, "grant") == 0)
				return notify_fail("请使用promote。");
			
			if(strcmp(arg, "set") == 0 
				&& (arg2[0] == '-' || (arg2[0] >='0' && arg2[0] <='9')) )
				who->set(arg1, atol(arg2));
			else 
			{
				if(strcmp(arg1, "name") == 0)
					who->set_name(arg2);
				else if(strcmp(arg1, "id") == 0)
					who->set_name(NULL, arg2);
				else
					who->set(arg1, arg2);
			}

			who->UpdateMe();
			
			tell_object(me, snprintf(arg, 255, "%s设定%s的%s为%s。", me->name(1), who->name(1), arg1, arg2));
			g_Channel.do_channel(&g_Channel, 0, "sys", arg);
			output_error(arg);
			return 1;
		}

		if(strcmp(arg, "delete") == 0)
		{
			if(strcmp(arg1, "grant") == 0)
				return notify_fail("请使用promote。");
			if(strcmp(arg1, "family") == 0 && userp(who))
				((CChar *)who)->release_master();

			who->del(arg1);
			who->UpdateMe();
			tell_object(me, snprintf(arg, 255, "删除%s。", arg1));
		
			return 1;
		}

		if(strcmp(arg, "query") == 0)
		{
			snprintf(arg, 255, "%s=%ld", arg1, who->query(arg1));
			tell_object(me, arg);
			return 1;
		}

		if(strcmp(arg, "querystr") == 0)
		{
			snprintf(arg, 255, "%s=%s", arg1, who->querystr(arg1));
			tell_object(me, arg);
			return 1;
		}

		//临时数据库	
		if(strcmp(arg, "set_temp") == 0)
		{
			if(arg2[0] == '-' || (arg2[0] >='0' && arg2[0] <='9'))
				who->set_temp(arg1, atol(arg2));
			else 
				who->set_temp(arg1, arg2);

			tell_object(me, snprintf(arg, 255, "设定临时%s为%s。", arg1, arg2));
			return 1;
		}

		if(strcmp(arg, "delete_temp") == 0)
		{
			who->delete_temp(arg1);
			who->UpdateMe();
			tell_object(me, snprintf(arg, 255, "删除临时%s。", arg1));
		
			return 1;
		}

		if(strcmp(arg, "query_temp") == 0)
		{
			snprintf(arg, 255, "临时%s=%ld", arg1, who->query_temp(arg1));
			tell_object(me, arg);
			return 1;
		}

		if(strcmp(arg, "querystr_temp") == 0)
		{
			snprintf(arg, 255, "临时%s=%s", arg1, who->querystr_temp(arg1));
			tell_object(me, arg);
			return 1;
		}
		return 0;
	}

	// set_skill sword 20
	DEFINECMD(Set_Skill)
	{
		CChar * who;
		char level[40], msg[255];

		if(! (who = GetRoomChar(me, target)) 
			&& ! (who = find_player(target)) )
			return notify_fail("没有这个人。");

		analyse_string(arg, level, 40);
		if(who->set_skill(arg, atol(level)))
		{
			me->FlushMySkill(me);
			tell_object(me, snprintf(msg, 255, "%s设置%s的技能%s为%d级。", me->name(1), who->name(1), arg, atol(level)) );
			g_Channel.do_channel(&g_Channel, 0, "sys", msg);
			output_error(msg);
			return 1;
		}

		return notify_fail("没有这项技能。");
	}

	//恢复技能经验1/3
	DEFINECMD(Restore_Exp)
	{
		CChar * who;

		if(! (who = find_player(target)) )
			return notify_fail("没有这个人。");

		LONG exp = who->query("sk_exp");
		LONG combat_exp = who->query("combat_exp");

		if(exp * 3 < combat_exp)
			return notify_fail("此人经验%ld，技能经验%ld，不能恢复。", combat_exp, exp);

		output_error("恢复%s(%s)的技能经验：%ld -> %ld", 
			who->name(1), who->querystr("id"), 
			exp, exp * 2 / 3);
		who->set("sk_exp", exp * 2 / 3);
		who->FlushMyInfo();
		tell_object(me, "OK!");
		return 1;
	}

	//清掉某人所有技能。
	DEFINECMD(Clear_Skill)
	{
		CChar * who;

		if(! (who = find_player(target)) )
			return notify_fail("没有这个人。");

		CMapping * skills = who->query_skills();
		skills->clear();

		skills = who->query_skill_prepare();
		skills->clear();

		skills = who->query_skill_map();
		skills->clear();

		skills = who->query_learned();
		skills->clear();

		who->del("sk_exp");
		who->SendState(who);
		
		tell_object(me, "OK!");
		return 1;
	}

	//查看更改recruit_exp表
	DEFINECMD(recruit_exp)
	{
		char arg1[80], arg2[80], arg3[80];

		analyse_string(arg, arg1, 80);
		analyse_string(arg1, arg2, 80);	
		analyse_string(arg2, arg3, 80);

		CMapping * ptr = g_Channel.query_recruit(arg1);
		if(! ptr)
			return notify_fail("没有该玩家的收徒记录！");

		if(strcmp(arg, "set") == 0)
		{
			if(arg3[0] == '-' || (arg3[0] >='0' && arg3[0] <='9'))
				ptr->set(arg2, atol(arg3));
			else 
				ptr->set(arg2, arg3);
				
			tell_object(me, snprintf(arg, 80, "设定玩家%s的徒弟%s为%s。", arg1, arg2, arg3));
			return 1;
		}

		if(strcmp(arg, "delete") == 0)
		{
			ptr->del(arg2);
			tell_object(me, snprintf(arg, 255, "删除玩家%s的徒弟%s。", arg1, arg2));
					
			return 1;
		}

		if(strcmp(arg, "query") == 0)
		{
			snprintf(arg, 255, "玩家%s徒弟：%s=%ld", arg1, arg2, ptr->query(arg2));
			tell_object(me, arg);
			return 1;
		}

		if(strcmp(arg, "querystr") == 0)
		{
			snprintf(arg, 255, "玩家%s徒弟：%s=%s", arg1, arg2, ptr->querystr(arg2));
			tell_object(me, arg);
			return 1;
		}

		return 0;
	}

	//BAN掉某人
	DEFINECMD(ban)
	{
		CChar * who;
		char msg[255];
		
		if(strcmp(arg, "all") == 0)
		{
			//列出所有黑名单
			CVector v;

			g_Channel.banlist.keys(v);
			for(int i=0; i<v.count(); i++)
				tell_object(me, snprintf(msg, 255, "地址：%s", v[i]));
			return 1;
		}

		if(target)
		{
			if(! (who = find_player(target)) )
				return notify_fail("没有这个人。");

			//判断权限
			if(who != me && who->query_grant() >= me->query_grant())
				return notify_fail("你的等级不够。");

			g_Channel.banlist.set(GetIP(who), 1);
			g_Channel.do_channel(&g_Channel, 0, "rumor", snprintf(msg, 255, "$WHT%s将%s(%s)加入黑名单。", me->name(1), who->name(1), GetIP(who)));
		}
		else
		{
			g_Channel.banlist.set(arg, 1);
			g_Channel.do_channel(&g_Channel, 0, "rumor", snprintf(msg, 255, "$WHT%s将地址(%s)加入黑名单。", me->name(1), arg));
		}
		
		return 1;
	}

	//UNBAN掉某人
	DEFINECMD(unban)
	{
		CChar * who;
		char msg[255];
				
		if(target)
		{
			if( ! (who = find_player(target)) )
				return notify_fail("没有这个人。");

			if(g_Channel.banlist.query(GetIP(who)))
				g_Channel.do_channel(&g_Channel, 0, "rumor", snprintf(msg, 255, "$WHT%s解除%s(%s)的黑名单。", me->name(1), who->name(1), GetIP(who)));
			else 
				return notify_fail("并没有加入黑名单。");
			g_Channel.banlist.del(GetIP(who));
		}
		else
		{
			if(g_Channel.banlist.query(arg))
				g_Channel.do_channel(&g_Channel, 0, "rumor", snprintf(msg, 255, "$WHT%s将地址(%s)从黑名单里删掉。", me->name(1), arg));
			else
				return notify_fail("并没有加入黑名单。");
			g_Channel.banlist.del(arg);
		}
		
		return 1;
	}

	//封掉某ID
	DEFINECMD(freeze)
	{
		char msg[255];
		
		if(SetInvalidAccount(arg, 1))
			g_Channel.do_channel(&g_Channel, 0, "rumor", snprintf(msg, 255, "%s的档案被封结了！", arg));
		else
			tell_object(me, "冻结失败!");

		output_error("%s(%s)封掉了帐号%s.", me->name(1), me->id(1), arg);
		return 1;
	}

	//解开某ID
	DEFINECMD(unfreeze)
	{
		char msg[255];
		SetInvalidAccount(arg, 0);
		tell_object(me, snprintf(msg, 255, "你解冻了帐号%s.", arg));
		output_error("%s(%s)解冻了帐号%s.", me->name(1), me->id(1), arg);

		return 1;
	}

	//改某ID的密码
	DEFINECMD(chpass)
	{
		char msg[255], tmp[80];
		const char * id, * pass;

		analyse_string(arg, tmp, 80);
		id = arg;
		pass = tmp;
			
		if(ChangePassword(id, pass))
			tell_object(me, snprintf(msg, 255, "修改帐号%s密码为%s！", id, pass));
		else
			tell_object(me, "修改密码失败！");
		return 1;
	}

	//改某ID的的身份验证密码
	DEFINECMD(chverifypass)
	{
		char msg[255], tmp[80];
		const char * id, * pass;

		analyse_string(arg, tmp, 80);
		
		id = arg;
		pass = tmp;
					
		if(ChangeVerifyPassword(id, pass))
			tell_object(me, snprintf(msg, 255, "修改帐号%s的身份校验密码为%s！", id, pass));
		else
			tell_object(me, "修改身份校验密码失败！");
		return 1;
	}

	DEFINECMD(dumpobject)
	{
		DumpObject();
		tell_object(me, "dump object complete!");
		return 1;
	}

	//查看在线玩家信息
	DEFINECMD(who)
	{
		iterator_user p;
		MAP2USER * list = users();
		CUser * who;
		char msg[255];

		typedef map<string, CUser *, less <string> > MYLIST;
		MYLIST list2;
		MYLIST::iterator p2;

		CMapping ip;
		int count1 = 0, count2 = 0;
		int count3 = 0, count4 = 0;
		
		for(p = list->begin(); p != list->end(); p++)
		{
			who = p->second;
			const char * myip = GetIP(who);
			snprintf(msg, 255, "%s %s", myip, who->id(1));
			list2[msg] = who;			

			if(! ip.query(myip))
			{
				count1++;			//IP计数
				if(! who->query_temp("net_dead"))	//连线
					count2++;
			}

			count3++;

			if(! who->query_temp("net_dead"))
				count4++;

			ip.add(myip, 1);			
		}

		tell_object(me, snprintf(msg, 255, "\n当前在线玩家%ld(%ld)人。连入机器%ld(%ld)台。\n---------------------------------------------------------------", count4, count3, count2, count1)); 

		//排序
		for(p2 = list2.begin(); p2 != list2.end(); p2++)
		{
			who = p2->second;
			tell_object(me, snprintf(msg, 255, "%s(%s) (%s)", who->name(1), who->id(1), GetIP(who)) );
		}

		return 1;
	}

	//死亡恢复
	DEFINECMD(recover)
	{
		CChar * who;
		
		if(! (who = find_player(target)) )
			return notify_fail("没有这个人。");

		LONG exp = who->query("death/combat_exp_loss");
		who->add("combat_exp", exp);

		output_error("%s恢复了%ld点死亡经验！", who->name(1), exp);

		if(who->query("death/skill_loss"))
		{
			who->skill_death_recover();	
		}

		who->del("death");

		tell_object(me, "恢复完成！");

		return 1;
	}

	//监听信息
	DEFINECMD(snoop)
	{
		CChar * who;
		char msg[255];
		
		if(strcmp(arg, "none") == 0)
		{
			who = g_Channel.query_snooping(me);

			if(who && who->query_grant() >= me->query_grant())
				tell_object(who, snprintf(msg, 255, "%s停止了对你的监听。", me->name(1)));

			g_Channel.snoop(me);
			tell_object(me, "解除监听。");
			return 1;
		}

		if(target == 0)
		{
			who = g_Channel.query_snooping(me);

			if(who)
				tell_object(me, snprintf(msg, 255, "你当前正在监听%s的信息。", who->name(1)));
			else
				tell_object(me, "你没有监听任何人。");

			return 1;
		}

		if( ! (who = find_player(target)) )
			return notify_fail("没有这个人。");

		if(who == me)
			return notify_fail("用snoop none解除监听。");

		if(who->query_grant() >= me->query_grant())
			tell_object(who, snprintf(msg, 255, "%s开始监听你接收到的信息。", me->name(1)));
		
		tell_object(me, snprintf(msg, 255, "你开始监听%s接收到的信息。", who->name(1)));
			
		g_Channel.snoop(me, who);

		return 1;
	}

	DEFINECMD(debug)
	{
		if(strcmp(arg, "on") == 0)
		{
			g_bDebug = 1;
			tell_object(me, "跟踪命令打开!");
		}
		else
		{
			g_bDebug = 0;
			tell_object(me, "跟踪命令关闭!");
		}

		return 1;
	}

	//重新生成场景！！
	DEFINECMD(reboot)
	{
		g_Channel.do_channel(me, NULL, "news", "世界已经毁灭……请各位好自为之……");
		me->call_out(do_reboot, 1);
		return 1;
	}

	static void do_reboot(CContainer * ob, LONG param1, LONG param2)
	{
		g_bReboot = TRUE;
	}

	//奖励玩家等级经验
	DEFINECMD(RewardExp)
	{
		char msg[255];
		CChar * who;
		
		if(! (who = find_player(target)) )
			return notify_fail("没有这个人。");

		int level = who->query("level");
		LONG exp = CChar::Level2Exp(level + 1) - CChar::Level2Exp(level);
		
		who->add("combat_exp", exp);
		who->FlushMyInfo();
		who->Save();

		tell_object(who, snprintf(msg, 255, "$HIY你被系统奖励一级经验了！+%ld EXP", exp));
		tell_object(me, snprintf(msg, 255, "%s(%s)被%s(%s)奖励了一级经验。(+%ld EXP)", 
			who->name(1), who->id(1), me->name(1), me->id(1), exp));

		output_error(msg);
		return 1;
	}

	//扣等级经验
	DEFINECMD(SubExp)
	{
		char msg[255];
		CChar * who;
		if(! (who = find_player(target)) )
			return notify_fail("没有这个人。");

		int level = who->query("level");
		LONG exp = CChar::Level2Exp(level) - CChar::Level2Exp(level - 1);

		who->add("combat_exp", - exp);
		who->add("level", -1);

		who->FlushMyInfo();
		who->Save();
		
		tell_object(who, snprintf(msg, 255, "$HIY你被系统罚掉一级经验了！-%ld EXP", exp));
		tell_object(me, snprintf(msg, 255, "%s(%s)被%s(%s)扣掉了一级经验。(-%ld EXP)", 
			who->name(1), who->id(1), me->name(1), me->id(1), exp));

		output_error(msg);
		return 1;
	}

	//奖励玩家等级金钱
	DEFINECMD(RewardMoney)
	{
		CChar * who;
		if(! (who = find_player(target)) )
			return notify_fail("没有这个人。");

		if(who->query("reward/money"))
			return notify_fail("此人已经接受过奖励");

		who->set("reward/money", 1);
		g_Combatd.Reward_Money(who, atol(arg) );
		return 1;
	}
	
	static void print_svalue(CChar * me, const char * key, CMapping::svalue_t * sv)
	{
		char msg[255];
		
		if(sv->type == T_NUMBER)
			tell_object(me, snprintf(msg, 255, "%s : %d", key, sv->u.number) );
		else if(sv->type == T_STRING)
			tell_object(me, snprintf(msg, 255, "%s : %s", key, sv->u.string) );
		else if(sv->type == T_ARRAY)
		{
			tell_object(me, snprintf(msg, 255, "%s : ({", key));
			CVector * v = sv->u.arr;
			for(int i = 0; i<v->count(); i++)
				tell_object(me, snprintf(msg, 255, "    %s,", (* v)[i]) );
			tell_object(me, "    })");
		}
		else if(sv->type == T_MAPPING)
		{
			tell_object(me, snprintf(msg, 255, "%s : ([", key));
			CMapping * m = sv->u.map;
			CVector v;
			
			m->keys(v);
			for(int i=0; i<v.count(); i++)
			{
				CMapping::svalue_t * sv1 = m->find_string_in_mapping(v[i]);
				print_svalue(me, v[i], sv1);
			}
			
			tell_object(me, "    ])");
		}		
	}

	//列出物件数据
	DEFINECMD(Data)
	{
		char msg[255];
		CContainer * who;

		if(! target) who = me->environment();
		else if(! (who = GetRoomObject(me, target))
			&& ! (who = GetSelfObject(me, target)) 
			&& !(who = find_player(target)))
			return notify_fail("请选中目标。");	

		CMapping * m = who->query_entire_dbase();
		tell_object(me, snprintf(msg, 255, "%s(%s):<%s>", who->name(1), who->id(1), who->querystr("base_name")) );

		CVector v;
		int i;

		m->keys(v);

		for(i = 0; i<v.count(); i++)
		{
			CMapping::svalue_t * sv = m->find_string_in_mapping(v[i]);
			print_svalue(me, v[i], sv);
		}

		m = who->query_entire_temp_dbase();
		
		tell_object(me, "临时数据:");
		v.clear();
		m->keys(v);

		for(i = 0; i<v.count(); i++)
		{
			CMapping::svalue_t * sv = m->find_string_in_mapping(v[i]);
			print_svalue(me, v[i], sv);
		}

		return 1;
	}

	DEFINECMD(Chblk)
	{
		CChar * who;
		char msg[255], arg1[40];

		analyse_string(arg, arg1, 40);
		
		if(! (who = find_online(arg)) ) return notify_fail("你要关谁的频道。");
		if(wizardp(who)) return notify_fail("不能关闭巫师的频道。");

		if(strcmp(arg1, "open") == 0)
		{
			who->del("chblk");
			tell_object(me, snprintf(msg, 255, "你打开了%s的交谈频道。", who->name(1)));
			tell_object(who, snprintf(msg, 255, "%s打开了你的交谈频道。", me->name(1)));
		}
		else
		{
			who->set("chblk/all", current_time + 1800);
			tell_object(me, snprintf(msg, 255, "你关闭了%s的交谈频道。", who->name(1)));
		}

		return 1;
	}

	//tail o07181.txt 分割文件 倒数100M分出小文件
	DEFINECMD(Tail)
	{
		char msg[255];
		char * pData;
		FILE * fp, * wp;
		int i;
			
		fp = fopen(arg, "rb");
		if(! fp)
			return notify_fail("tail <文件名>");
		
		fseek(fp, 0l, SEEK_END);
		LONG len = ftell(fp);

		tell_object(me, snprintf(msg, 255, "文件长度%ld字节.", len));

		if(len < 60000000)
			return notify_fail("没必要分割!");

		pData = new char[60000000];
		if(! pData)
		{
			fclose(fp);
			return notify_fail("内存不够。");
		}

		fseek(fp, 0l, SEEK_SET);
		for(i=0; i<len / 60000000; i++)
		{
			wp = fopen(snprintf(msg, 80, "c:/tail%ld.o", i), "wb");
			if(! wp)
			{
				fclose(fp);				
				return notify_fail("不能创建写文件。");
			}
			
			fread(pData, 60000000, 1, fp);
			fwrite(pData, 60000000, 1, wp);
			fclose(wp);
		}

		wp = fopen(snprintf(msg, 80, "c:/tail%ld.o", i), "wb");
		if(! wp)
		{
			fclose(fp);				
			return notify_fail("不能创建写文件。");
		}
			
		fread(pData, len%60000000, 1, fp);
		fwrite(pData, len%60000000, 1, wp);
		fclose(wp);

		fclose(fp);		
		delete []pData;

		tell_object(me, "OK");
		return 1;
	}

	DEFINECMD(PrintMapping)
	{
		printf_all_mappings();
		return 1;
	}

	//强制刷新
	DEFINECMD(Update)
	{
		CContainer * who;

		if(! target) who = me->environment();
		else if(! (who = GetRoomObject(me, target))
			&& ! (who = GetSelfObject(me, target)))
			return notify_fail("请选中目标。");	

		who->Load();

		if(who->Query(CChar::IS_ROOM))
			((CRoom *)who)->reset();

		tell_object(me, "OK.");

		return 1;
	}

	//强制存盘
	DEFINECMD(Save)
	{
		CContainer * who;

		if(strcmp(arg, "all") == 0)
		{
			MAP2USER * list = users();
			iterator_user p;			

			for(p = list->begin(); p != list->end(); p++)
			{
				(p->second)->SaveToServer();
			}

			tell_object(me, "All players save OK.");
			return 1;
		}

		if(! target) who = me->environment();
		else if(! (who = GetRoomObject(me, target))
			&& ! (who = GetSelfObject(me, target))
			&& ! (who = find_player(target)))
			return notify_fail("请选中目标。");	

		who->Save();
		tell_object(me, "OK.");
		return 1;
	}

	DEFINECMD(freeip)
	{
		char arg1[80], msg[255];
		analyse_string(arg, arg1, 80);
		if(strcmp(arg, "set") == 0)
		{
			if(! arg1[0]) return notify_fail("请输入正确的IP。");
			g_Channel.set(snprintf(msg, 255, "freeip/%s", arg1), 1);
			tell_object(me, "OK");
			return 1;
		}
		else if(strcmp(arg, "delete") == 0)
		{
			if(! arg1[0]) return notify_fail("请输入正确的IP。");
			g_Channel.del(snprintf(msg, 255, "freeip/%s", arg1));
			tell_object(me, "OK");
			return 1;
		}
		
		//列出全部free IP
		CVector v;
		CMapping * m = g_Channel.querymap("freeip");
		if(! m) return notify_fail("什么都没有。");

		m->keys(v);
		for(int i=0; i<v.count(); i++)
			tell_object(me, v[i]);

		return 1;
	}
	/*
	//制造18地狱怪物
	DEFINECMD(MakeMonster)
	{
		//技能类:
		//1层,无门派
		static struct{
			char attack_skill[20], attack_base[10];
			char attack_skill2[20], attack_base2[10];
			char dodge[20], force[20];
			char prepare[10], prepare2[10];
			char weapon[10];
			char perform[9][20];
		}skills[] = {
			{"changquan","cuff","","","guimei_shenfa","hunyuan_yiqi","cuff","","","","","","","","","","","",},
			{"hanxing_bada","throwing","changquan","cuff","shenxing_baibian","hunyuan_yiqi","cuff","","throwing","throwing lastrisk","","","","","","","","",},
			{"hujia_daofa","blade","changquan","cuff","guimei_shenfa","hunyuan_yiqi","cuff","","blade","","","","","","","","","",},
			{"jinwu_daofa","blade","changquan","cuff","guimei_shenfa","hunyuan_yiqi","cuff","","blade","","","","","","","","","",},
			{"juemen_gun","club","changquan","cuff","guimei_shenfa","hunyuan_yiqi","cuff","","club","","","","","","","","","",},
			{"kuangfeng_blade","blade","changquan","cuff","guimei_shenfa","hunyuan_yiqi","cuff","","blade","","","","","","","","","",},
			{"wudu_bian","whip","wudu_zhang","strike","guimei_shenfa","hunyuan_yiqi","strike","","whip","","","","","","","","","",},
			{"wuhuduanmendao","blade","changquan","cuff","guimei_shenfa","hunyuan_yiqi","cuff","","blade","","","","","","","","","",},
			{"zhongpingqiang","club","changquan","cuff","guimei_shenfa","hunyuan_yiqi","cuff","","club","","","","","","","","","",},
			{"zhanjiang_jue","club","changquan","cuff","guimei_shenfa","hunyuan_yiqi","cuff","","club","club killyou","","","","","","","","",},
			{"songshan_sword","sword","changquan","cuff","lingxu_bu","hunyuan_yiqi","cuff","","sword","","","","","","","","","",},
			{"hengshan_sword","sword","changquan","cuff","lingxu_bu","hunyuan_yiqi","cuff","","sword","","","","","","","","","",},
			{"hengshan_jian","sword","changquan","cuff","lingxu_bu","hunyuan_yiqi","cuff","","sword","","","","","","","","","",},
			{"taishan_sword","sword","changquan","cuff","lingxu_bu","hunyuan_yiqi","cuff","","sword","","","","","","","","","",},
			{"lingshe_zhangfa","staff","shexing_diaoshou","hand","chanchu_bufa","hamagong","hand","","staff","staff pili","hand wugu","force powerup","force reserver","","","","","",},
			{"shexing_diaoshou","hand","","","chanchu_bufa","hamagong","hand","","","hand wugu","force powerup","force reserver","","","","","","",},
			{"yanxing_dao","blade","jiuyin_zhua","claw","zhutian_bu","linji_zhuang","claw","","blade","blade huanying","force powerup","","","","","","","",},
			{"tiangang_zhi","finger","jinding_zhang","strike","zhutian_bu","linji_zhuang","finger","strike","","finger lingkong","strike bashi","force powerup","","","","","","",},
			{"jiuyin_zhua","claw","","","zhutian_bu","linji_zhuang","claw","","","claw zhua","force powerup","","","","","","","",},
			{"huifeng_qijue","sword","jiuyin_zhua","claw","zhutian_bu","linji_zhuang","claw","","sword","sword mixhit","force powerup","","","","","","","",},
			{"huifeng_jian","sword","jiuyin_zhua","claw","zhutian_bu","linji_zhuang","claw","","sword","sword mie","force powerup","","","","","","","",},
			{"duanjia_sword","sword","jinyu_quan","cuff","tiannan_step","kurong_changong","cuff","","sword","sword jingtian","sword fenglei","force powerup","","","","","","",},
			{"feifeng_whip","whip","jinyu_quan","cuff","qingdie_shenfa","kurong_changong","cuff","","whip","force powerup","","","","","","","","",},
			{"jinyu_quan","cuff","wuluo_zhang","strike","qingdie_shenfa","kurong_changong","cuff","strike","","force powerup","","","","","","","","",},
			{"liumai_shenjian","finger","","","tiannan_step","kurong_changong","finger","","","finger ci","finger feng","finger tan","force powerup","","","","","",},
			{"sun_finger","finger","","","tiannan_step","kurong_changong","finger","","","finger qiankun","force powerup","","","","","","","",},
			{"dagou_bang","staff","xianglong_zhang","strike","xiaoyaoyou","huntian_qigong","strike","","staff","staff zhuang","force poweruop","force shengang","","","","","","",},
			{"xianglong_zhang","strike","","","xiaoyaoyou","huntian_qigong","strike","","","strike leiting","force poweruop","force shengang","","","","","","",},
			{"meinv_quan","cuff","","","yunv_shenfa","yunv_xinjing","cuff","","","cuff you","force powerup","force roar","","","","","","",},
			{"wudu_shenzhang","strike","","","yunv_shenfa","yunv_xinjing","strike","","","force powerup","force roar","","","","","","","",},
			{"smithsword","sword","meinv_quan","cuff","xianyun_bufa","seaforce","cuff","","sword","sword flood","force flood","","","","","","","",},
			{"anranxiaohun_zhang","strike","","","xianyun_bufa","seaforce","strike","","","strike xiaohun","force flood","","","","","","","",},
			{"yunv_jian","sword","meinv_quan","cuff","yunv_shenfa","yunv_xinjing","cuff","","sword","sword he","force powerup","force roar","","","","","","",},
			{"yinsuo_jinling","whip","meinv_quan","cuff","yunv_shenfa","yunv_xinjing","cuff","","whip","whip dian","whip feng","force powerup","force roar","","","","","",},
			{"swsb_whip","whip","meinv_quan","cuff","yunv_shenfa","yunv_xinjing","cuff","","whip","force powerup","force roar","","","","","","","",},
			{"fanliangyi_dao","blade","huashan_ken","cuff","feiyan_huixiang","zixia_shengong","cuff","","blade","blade sanshen","force powerup","","","","","","","",},
			{"huashan_ken","cuff","huashan_zhangfa","strike","huashan_shenfa","zixia_shengong","cuff","strike","","force powerup","","","","","","","","",},
			{"huashan_sword","sword","huashan_ken","cuff","huashan_shenfa","zixia_shengong","cuff","","sword","sword jianzhang","force powerup","","","","","","","",},
			{"hunyuan_zhang","strike","poyu_quan","cuff","huashan_shenfa","zixia_shengong","strike","cuff","","strike wuji","cuff leidong","force powerup","","","","","","",},
			{"kuangfeng_jian","sword","huashan_ken","cuff","huashan_shenfa","zixia_shengong","cuff","","sword","sword feilong","force powerup","","","","","","","",},
			{"lonely_sword","sword","huashan_ken","cuff","feiyan_huixiang","zixia_shengong","cuff","","sword","sword pojian","sword poqi","sword poqiang","sword posuo","sword pozhang","sword poanqi","sword podao","sword pobian","force powerup",},
			{"yunv_swords","sword","huashan_ken","cuff","huashan_shenfa","zixia_shengong","cuff","","sword","sword wushuang","force powerup","","","","","","","",},
			{"liuyang_zhang","strike","zhemei_shou","hand","yueying_wubu","bahuang_gong","strike","hand","","strike zhong","hand duo","force powerup","","","","","","",},
			{"tianyu_qijian","sword","zhemei_shou","hand","yueying_wubu","bahuang_gong","hand","","sword","sword san","hand duo","force powerup","","","","","","",},
			{"duoming_yinhua","throwing","yingzhua_shou","hand","qiankun_danuoyi","jiuyang_shengong","hand","","throwing","throwing huayu","force powerup","","","","","","","",},
			{"fenglei_dao","blade","yingzhua_shou","hand","qiankun_danuoyi","jiuyang_shengong","hand","","blade","force powerup","","","","","","","","",},
			{"hanbing_mianzhang","strike","","","qingfu_shenfa","jiuyang_shengong","strike","","","force powerup","","","","","","","","",},
			{"hanbing_strike","strike","","","qiankun_danuoyi","jiuyang_shengong","strike","","","force powerup","","","","","","","","",},
			{"houquan","cuff","","","qiankun_danuoyi","jiuyang_shengong","cuff","","","cuff zhen","force powerup","","","","","","","",},
			{"qishang_quan","cuff","","","qiankun_danuoyi","jiuyang_shengong","cuff","","","cuff cangli","cuff sunxin","cuff shangfei","cuff sanjiao","cuff jingshi","cuff hunpo","cuff cuiganchang","cuff yihuanghu","force powerup",},
			{"shenghuo_lingfa","lingfa","yingzhua_shou","hand","qiankun_danuoyi","shenghuo_shengong","hand","","lingfa","lingfa duo","lingfa xiyanling","","","","","","","",},
			{"sougu","claw","","","qiankun_danuoyi","jiuyang_shengong","claw","","","claw sougu","force powerup","","","","","","","",},
			{"wuyue_blade","blade","yingzhua_shou","hand","qiankun_danuoyi","jiuyang_shengong","hand","","blade","blade jiao","force powerup","","","","","","","",},
			{"xuanyuan_arrow","throwing","yingzhua_shou","hand","qiankun_danuoyi","jiuyang_shengong","hand","","throwing","force powerup","","","","","","","","",},
			{"yingzhua_shou","hand","","","qiankun_danuoyi","jiuyang_shengong","hand","","","force powerup","","","","","","","","",},
			{"wuyun_jianfa","sword","xuantian_zhi","finger","piaoyibu","wuzheng_xinfa","finger","","sword","","","","","","","","","",},
			{"xuantian_zhi","finger","","","piaoyibu","xuantian_shengong","finger","","","force roar","","","","","","","","",},
			{"shigu_bifa","dagger","xuantian_zhi","finger","piaoyibu","wuzheng_xinfa","finger","","dagger","","","","","","","","","",},
		};
		
		//line = offset[dy - 1] + skclass - 1;
		static int offset[] = {0, 14, 16, 21, 26, 27, 34, 41, 43, 54, 57};
		static char fam[][9] = {"", "白驼山派", "峨嵋派", "大理段家", "丐帮", "古墓派", "华山派",
							"灵鹫宫", "明教", "梅庄", "全真教"};
		
		static struct{
			int dy;
			char name[20], base_name[20];
			char icon[20], gender[5];
			int age, lv, skclass;
		}mon[MONSTER_NUM] = {
			{1,"小张","dy1_xiaozhang","young_man2","男性",22,63,1,},
			{1,"美桑娘","dy1_meisn","young_woman3","女性",18,60,1,},
			{1,"李斯","dy1_lisi","old_man1","男性",50,64,1,},
			{1,"春申君","dy1_chun","old_man2","男性",66,62,1,},
			{1,"犀豹","dy1_xibao","young_man4","男性",24,64,1,},
			{1,"少原君","dy1_shaoyuan","young_man4","男性",23,60,1,},
			{1,"蛮牛","dy1_manniu","young_man5","男性",23,63,1,},
			{1,"异人","dy1_yiren","young_man5","男性",40,61,1,},
			{1,"小兔","dy1_tu","young_woman2","女性",18,60,1,},
			{1,"黑脸神","dy1_hei","young_man3","男性",25,66,1,},
			{1,"乌芳芳","dy1_wu","young_woman2","女性",22,60,2,},
			{1,"赵君","dy1_zhaojun","cateran","男性",17,67,2,},
			{1,"赵姬","dy1_zhaoji","young_woman7","女性",30,60,2,},
			{1,"乌应方","dy1_wuyf","old_man2","男性",50,65,3,},
			{1,"乌越","dy1_wuyue","general","男性",21,68,3,},
			{1,"小猫","dy1_xiaomao","young_woman2","女性",22,62,3,},
			{1,"乌氏客","dy1_wusk","old_man1","男性",65,64,3,},
			{1,"嚣牟倪","dy1_xiaomn","cateran","男性",27,69,4,},
			{1,"项小龙","dy1_xiang","young_man2","男性",24,65,4,},
			{1,"樵毒","dy1_qiaodu","young_man3","男性",34,66,4,},
			{1,"窦恶","dy1_doue","young_man5","男性",35,63,4,},
			{1,"连进","dy1_lian","young_man3","男性",24,68,5,},
			{1,"沙璇","dy1_shaoxuan","guarder","男性",28,64,5,},
			{1,"僚毐","dy1_liao","young_man6","男性",45,65,5,},
			{1,"黑胡","dy1_heihu","banditi","男性",39,66,6,},
			{1,"赵雅","dy1_zhaoya","young_woman4","女性",30,60,7,},
			{1,"秀彝","dy1_xiuyi","young_woman2","女性",19,62,7,},
			{1,"琴音","dy1_qinyin","young_woman2","女性",20,62,7,},
			{1,"周香梅","dy1_zhouxm","young_woman8","女性",20,60,7,},
			{1,"郑翠莲","dy1_zheng","young_woman7","女性",20,60,7,},
			{1,"成需","dy1_chengxu","general","男性",31,67,8,},
			{1,"陶元","dy1_taoyuan","young_man6","男性",40,63,8,},
			{1,"腾义","dy1_tengyi","general","男性",23,69,9,},
			{1,"笑嫣然","dy1_xiao","young_woman1","女性",20,68,9,},
			{1,"王翦","dy1_wangjian","general","男性",32,70,10,},
			{1,"廉颇","dy1_lianpo","general","男性",70,69,10,},
			{1,"管邪","dy1_guan","general","男性",26,70,10,},
			{1,"元祖","dy1_yuanzu","old_man1","男性",54,69,10,},
			{1,"李牧","dy1_limu","general","男性",45,70,10,},
			{1,"曹东道","dy1_cao","taoist_with_sword","男性",56,70,10,},
			{1,"珊柔","dy1_shanrou","masked_man","女性",19,66,11,},
			{1,"乌廷严","dy1_wuty","young_man3","男性",18,61,11,},
			{1,"吕不韦","dy1_lv","old_man2","男性",55,67,11,},
			{1,"吉明","dy1_jiming","general","男性",26,65,12,},
			{1,"龙阴客","dy1_long","young_woman3","男性",23,68,13,},
			{1,"赵幕","dy1_zhao","guarder","男性",26,70,13,},
			{1,"田单","dy1_tian","general","男性",50,66,13,},
			{1,"信陵君","dy1_xin","old_man1","男性",55,60,14,},
			{1,"严复","dy1_yanfu","old_man1","男性",49,68,14,},
			{2,"拓跋韩","dy2_tuobh","young_man3","男性",25,79,1,},
			{2,"石青宣","dy2_shiqx","young_woman1","男性",19,79,1,},
			{2,"李密","dy2_limi","general","男性",45,78,1,},
			{2,"毕炫","dy2_bixuan","old_man2","男性",65,80,1,},
			{2,"杨虚延","dy2_yagxy","young_man3","男性",24,79,1,},
			{2,"尚秀旬","dy2_shangxx","young_woman2","男性",20,70,1,},
			{2,"赵德岩","dy2_zhaody","taoist","男性",55,79,1,},
			{2,"左有闲","dy2_zhuoyx","taoist_with_sword","男性",51,76,1,},
			{2,"管管","dy2_guanguan","young_woman1","男性",19,79,1,},
			{2,"希应","dy2_xuying","cateran","男性",47,75,1,},
			{2,"海滨","dy2_haibing","young_woman3","女性",24,76,1,},
			{2,"宇文化古","dy2_yuwenhg","young_man6","男性",58,73,1,},
			{2,"刘黑达","dy2_liuhd","general","男性",26,76,1,},
			{2,"祝雨燕","dy2_zhuyy","young_woman3","男性",53,79,1,},
			{2,"宋玉枝","dy2_songyz","young_woman3","男性",18,70,1,},
			{2,"有鸟卷","dy2_younj","banditi","男性",56,74,1,},
			{2,"海盐","dy2_hanyan","young_woman3","女性",32,74,1,},
			{2,"独孤策","dy2_duguc","old_man1","男性",65,77,1,},
			{2,"海水","dy2_haishui","young_woman2","女性",22,77,1,},
			{2,"李靖","dy2_lijing","general","男性",26,76,1,},
			{2,"李神通","dy2_list","general","男性",33,73,1,},
			{2,"李渊","dy2_liyuan","old_man1","男性",57,74,1,},
			{2,"宁道其","dy2_ningdq","taoist","男性",73,80,1,},
			{2,"福难陀","dy2_funt","old_monk","男性",64,78,1,},
			{2,"李元吉","dy2_liyj","general","男性",22,75,1,},
			{2,"宋金刚","dy2_songjg","general","男性",49,74,2,},
			{2,"翟让","dy2_zhairang","general","男性",52,77,2,},
			{2,"海洋","dy2_haiyang","young_woman7","女性",22,79,2,},
			{2,"红拂","dy2_hongfu","young_woman4","男性",23,76,2,},
			{2,"李建城","dy2_lijc","general","男性",26,74,2,},
			{2,"徐子灵","dy2_xuzl","young_man1","男性",22,79,2,},
			{2,"杜福威","dy2_dufw","old_man2","男性",55,77,2,},
			{2,"可达至","dy2_kedz","general","男性",26,78,2,},
			{2,"鲁班","dy2_luban","old_man1","男性",64,78,2,},
			{2,"宋满","dy2_songman","general","男性",47,80,2,},
			{2,"海沙","dy2_hansh","young_woman2","女性",23,75,2,},
			{2,"云玉珍","dy2_yunyz","young_woman3","男性",21,70,2,},
			{2,"傅采临","dy2_fucl","taoist_with_sword","男性",80,80,2,},
			{2,"寇中","dy2_kouzhong","young_man2","男性",24,79,2,},
			{2,"海浪","dy2_hailian","young_woman5","女性",23,78,2,},
			{2,"维公公","dy2_weigg","old_man2","男性",66,75,2,},
			{2,"李世民","dy2_lism","general","男性",24,77,2,},
			{2,"神落雁","dy2_shenly","young_woman2","男性",24,71,2,},
			{2,"宋路","dy2_songlu","old_man2","男性",70,73,2,},
			{2,"尤楚鸿","dy2_youch","old_woman","男性",75,79,2,},
			{2,"石止轩","dy2_shizx","young_man6","男性",59,80,2,},
			{2,"师霏煊","dy2_shifx","young_woman1","男性",19,79,2,},
			{2,"侯希百","dy2_houxb","young_man2","男性",23,79,2,},
			{2,"安龙","dy2_anlong","old_man2","男性",54,77,2,},
			{3,"张清","dy3_zhangqing","young_man4","男性",35,81,1,},
			{3,"元小二","dy3_yuanxiaoer","young_man6","男性",38,80,1,},
			{3,"丁得损","dy3_dingdesun","young_man4","男性",39,83,1,},
			{3,"杨纯","dy3_angchun","young_man4","男性",38,86,1,},
			{3,"鲁直深","dy3_luozhishen","old_man1","男性",68,90,1,},
			{3,"李中","dy3_lizhong","young_man5","男性",36,85,1,},
			{3,"王定七","dy3_wangdingqi","triggerman1","男性",42,82,1,},
			{3,"李愧","dy3_likui","triggerman1","男性",32,89,1,},
			{3,"石用","dy3_shiyong","cateran","男性",65,84,1,},
			{3,"黄新","dy3_huangxin","taoist_with_sword","男性",47,87,1,},
			{3,"关神","dy3_guanshen","young_man3","男性",23,88,1,},
			{3,"杜行","dy3_duxing","young_man3","男性",36,83,3,},
			{3,"无用","dy3_wuyong","taoist","男性",55,80,3,},
			{3,"秦鸣","dy3_qingming","general","男性",46,89,3,},
			{3,"柴近","dy3_chaijin","general","男性",32,87,3,},
			{3,"史近","dy3_shijin","old_man1","男性",72,90,3,},
			{3,"元小七","dy3_yuanxiaoqi","young_man2","男性",35,81,3,},
			{3,"巴三娘","dy3_basannian","young_woman2","女性",20,88,3,},
			{3,"曹真","dy3_caozhen","young_man5","男性",32,85,3,},
			{3,"朱福","dy3_zhufu","young_man4","男性",28,82,3,},
			{3,"顾大娘","dy3_gudaniang","young_woman1","女性",40,81,3,},
			{3,"魏定过","dy3_weidingguo","general","男性",48,86,3,},
			{3,"李运","dy3_liyun","young_monk","男性",23,84,3,},
			{3,"花龙","dy3_hualong","young_man6","男性",25,90,4,},
			{3,"董评","dy3_dongping","young_man5","男性",24,88,4,},
			{3,"孔名","dy3_kongming","tipstaff","男性",31,85,4,},
			{3,"孙心","dy3_sunxin","tipstaff","男性",47,83,4,},
			{3,"时千","dy3_shiqian","begger","男性",34,85,4,},
			{3,"解饱","dy3_jiebao","young_man4","男性",19,87,4,},
			{3,"宋将","dy3_songjiang","taoist_with_sword","男性",61,80,4,},
			{3,"金大尖","dy3_jindajian","masked_man","男性",45,84,4,},
			{3,"朱五","dy3_zhuwu","taoist","男性",56,86,4,},
			{3,"武者","dy3_wuzhe","young_man2","男性",20,89,4,},
			{3,"公孙神","dy3_gongsunshen","taoist_with_sword","男性",88,90,4,},
			{3,"孙三娘","dy3_sunsanniang","young_woman4","女性",33,81,4,},
			{3,"元小五","dy3_yuanxiaowu","young_man3","男性",37,81,4,},
			{3,"解针","dy3_jiezhen","young_man3","男性",18,87,5,},
			{3,"杨凶","dy3_yangxiong","young_man2","男性",20,89,5,},
			{3,"泪痕","dy3_leihen","young_woman12","女性",20,88,5,},
			{3,"宋青","dy3_songqing","young_man2","男性",43,85,5,},
			{3,"马磷","dy3_malin","guarder","男性",45,84,5,},
			{3,"林充","dy3_linchon","old_man2","男性",78,90,5,},
			{3,"白盛","dy3_baisheng","young_man2","男性",38,82,5,},
			{3,"蒋惊","dy3_jiangjin","young_man3","男性",37,86,5,},
			{3,"曹盖","dy3_caodai","young_man4","男性",63,80,5,},
			{3,"乐呵","dy3_lehe","triggerman2","男性",41,83,5,},
			{4,"司马五","dy4_simawu","young_man6","男性",22,95,1,},
			{4,"公孙龙","dy4_gongsunlong","young_man5","男性",22,94,1,},
			{4,"刘云","dy4_liuyun","young_man4","男性",26,99,1,},
			{4,"马朝","dy4_machao","young_man3","男性",30,100,1,},
			{4,"张脚","dy4_zhangjiao","taoist_with_sword","男性",56,91,1,},
			{4,"董成","dy4_dongcheng","young_man3","男性",32,92,1,},
			{4,"曹凶","dy4_caoxiong","young_man2","男性",34,97,1,},
			{4,"袁谈","dy4_yuantan","young_man2","男性",28,93,1,},
			{4,"孙车","dy4_sunche","young_man3","男性",45,98,1,},
			{4,"诸葛盏","dy4_zhugezhan","young_man1","男性",23,96,1,},
			{4,"张拳","dy4_zhangquan","taoist_with_sword","男性",40,91,2,},
			{4,"诸葛封","dy4_zhugefeng","young_man3","男性",24,96,2,},
			{4,"袁言","dy4_yuanyan","young_woman11","女性",22,93,2,},
			{4,"司马三","dy4_simasan","young_nun","女性",44,95,2,},
			{4,"曹云","dy4_caoyun","young_woman2","女性",22,97,2,},
			{4,"孙善香","dy4_sunshangxiang","young_woman3","女性",20,98,2,},
			{4,"皇莆蛇","dy4_huangpushe","tipstaff","男性",35,92,2,},
			{4,"刘婵","dy4_liuchan","young_woman3","女性",23,99,2,},
			{4,"黄中","dy4_huangzhong","old_man1","男性",58,100,2,},
			{4,"公孙远","dy4_gongsunyuan","young_woman5","女性",21,94,2,},
			{4,"张凉","dy4_zhangliang","taoist_with_sword","男性",42,91,3,},
			{4,"司马四","dy4_simasi","young_man4","男性",23,95,3,},
			{4,"公孙凤","dy4_gongsunfeng","young_woman3","女性",22,94,3,},
			{4,"孙浩","dy4_sunhao","young_man1","男性",22,98,3,},
			{4,"张非","dy4_zhangfei","young_man3","男性",31,100,3,},
			{4,"诸葛烟","dy4_zhugeyan","young_man5","男性",22,96,3,},
			{4,"董冥","dy4_dongming","old_man2","男性",34,92,3,},
			{4,"袁语","dy4_yuanyu","young_man3","男性",27,93,3,},
			{4,"刘风","dy4_liufeng","young_man1","男性",25,99,3,},
			{4,"董啄","dy4_dongzhuo","old_man2","男性",68,92,4,},
			{4,"张爆","dy4_zhangbao","taoist_with_sword","男性",55,91,4,},
			{4,"司马一","dy4_simayi","old_monk","男性",56,95,4,},
			{4,"诸葛凉","dy4_zhugeliang","taoist_with_sword","男性",25,96,4,},
			{4,"赵运","dy4_zhaoyun","young_man1","男性",30,100,4,},
			{4,"曹槽","du4_caocao","old_man1","男性",45,97,4,},
			{4,"刘悲","dy4_liubei","young_man1","男性",30,99,4,},
			{4,"孙全","dy4_sunquan","young_man1","男性",40,98,4,},
			{4,"袁烧","dy4_yuanshao","general","男性",45,93,4,},
			{4,"公孙战","dy4_gongsunzhan","young_man6","男性",20,94,4,},
			{4,"孙剑","dy4_sunjian","old_man1","男性",68,98,5,},
			{4,"司马二","dy4_simaer","taoist","男性",45,95,5,},
			{4,"袁输","dy4_yuanshu","old_monk","男性",54,93,5,},
			{4,"曹配","du4_caopei","young_man4","男性",36,97,5,},
			{4,"诸葛晋","dy4_zhugejin","young_man3","男性",23,96,5,},
			{4,"关雨","dy4_guanyu","young_man1","男性",32,100,5,},
			{4,"华熊","dy4_huaxiong","old_monk","男性",60,92,5,},
			{4,"刘哀","dy4_liuai","young_man2","男性",23,99,5,},
			{4,"张乐","dy4_zhangle","taoist_with_sword","男性",43,91,5,},
			{4,"公孙虎","dy4_gongsunhu","young_man2","男性",23,94,5,},
			{4,"曹直","dy4_caozhi","young_man2","男性",30,97,5,},
			{5,"忍者","dy5_renzhe","masked_man","男性",16,107,1,},
			{5,"菊儿","dy5_juer","young_woman5","女性",18,109,1,},
			{5,"竹儿","dy5_zhuer","young_woman6","女性",18,109,1,},
			{5,"梅儿","dy5_meier","young_woman7","女性",18,109,1,},
			{5,"伍铝","dy5_wulv","young_man2","男性",35,101,1,},
			{5,"酒使","dy5_jiushi","young_man1","男性",34,103,1,},
			{5,"书童","dy5_shutong","young_man1","男性",17,106,1,},
			{5,"伍铁","dy5_wutien","young_man5","男性",42,101,1,},
			{5,"酒童","dy5_jiutong","young_man1","男性",18,107,1,},
			{5,"琴童","dy5_qintong","young_man1","男性",18,106,1,},
			{5,"凤素素","dy5_fengsusu","young_woman5","女性",20,102,1,},
			{5,"端木清","dy5_duamuqing","young_man1","男性",19,108,1,},
			{5,"财使","dy5_caishi","young_man1","男性",23,103,1,},
			{5,"独孤儿","dy5_duguer","young_man1","男性",22,108,1,},
			{5,"伍天亿","dy5_wutianyi","old_man1","男性",65,101,1,},
			{5,"中使","dy5_zhongshi","young_man2","男性",32,103,1,},
			{5,"诗童","dy5_shitong","young_man2","男性",16,106,1,},
			{5,"南宫望","dy5_nangongwang","young_man3","男性",16,108,1,},
			{5,"楚丁","dy5_chuding","young_man5","男性",25,102,1,},
			{5,"芳儿","dy5_fanger","young_woman4","女性",18,109,1,},
			{5,"电","dy5_dian","young_man1","男性",32,104,1,},
			{5,"东东","dy5_dongdong","young_man2","男性",21,105,1,},
			{5,"风","dy5_feng","young_woman4","女性",31,104,1,},
			{5,"南南","dy5_nannan","young_man2","男性",19,105,1,},
			{5,"画童","dy5_huatong","young_man1","男性",17,106,2,},
			{5,"伍铜","dy5_wutong","young_man1","男性",40,101,2,},
			{5,"李正","dy5_lizheng","young_man4","男性",24,102,2,},
			{5,"雷","dy5_lei","young_man1","男性",32,104,2,},
			{5,"棋童","dy5_qitong","young_man4","男性",19,106,2,},
			{5,"兰儿","dy5_laner","young_woman8","女性",18,109,2,},
			{5,"气使","dy5_qishi","young_man1","男性",23,103,2,},
			{5,"云","dy5_yun","young_woman4","女性",32,104,2,},
			{5,"茶女","dy5_chanv","young_woman5","女性",15,107,2,},
			{5,"无元","dy5_wuyuan","young_woman3","女性",20,102,2,},
			{5,"火","dy5_huo","young_man2","男性",19,104,2,},
			{5,"中中","dy5_zhongzhong","young_man2","男性",17,105,2,},
			{5,"舞姬","dy5_wuji","young_woman2","女性",15,107,2,},
			{5,"剑童","dy5_jiantong","young_man2","男性",15,107,2,},
			{5,"井望地","dy5_jingwangdi","young_man3","男性",20,102,2,},
			{5,"色使","dy5_shaishi","young_woman4","女性",21,103,2,},
			{5,"欧阳血","dy5_ouyangxue","young_woman4","女性",20,108,2,},
			{5,"北北","dy5_beibei","young_man2","男性",18,105,2,},
			{5,"西西","dy5_xixi","young_woman3","女性",21,105,2,},
			{5,"西门浮","dy5_ximenfu","young_man3","男性",18,108,2,},
			{5,"伍钢","dy5_wugang","young_man2","男性",44,101,2,},
			{6,"杜边","dy6_dubian","young_man2","男性",32,115,1,},
			{6,"天鹰","dy6_tianying","old_man2","男性",67,114,1,},
			{6,"雁飞飞","dy6_yanfefe","young_woman3","女性",23,118,1,},
			{6,"洛蒂","dy6_luodi","young_woman2","女性",23,111,1,},
			{6,"无师","dy6_wushi","general","男性",32,112,1,},
			{6,"战狠","dy6_zhanhen","young_man1","男性",28,115,2,},
			{6,"青野","dy6_qingye","old_man1","男性",72,114,2,},
			{6,"上消","dy6_shangxiao","triggerman1","男性",32,110,2,},
			{6,"林白","dy6_dylinbai","young_man2","男性",25,112,2,},
			{6,"天眼","dy6_tianyan","old_monk","男性",65,119,2,},
			{6,"左令全","dy6_zuolingquan","young_man3","男性",24,118,2,},
			{6,"席竹同","dy6_xizhutong","young_man1","男性",24,117,2,},
			{6,"呢雅","dy6_niya","young_woman2","女性",22,116,2,},
			{6,"马愿","dy6_mayuan","young_man2","男性",45,111,2,},
			{6,"飞血","dy6_faxue","young_man2","男性",31,113,2,},
			{6,"巨玲","dy6_julin","young_man5","男性",43,114,3,},
			{6,"龙灯","dy6_longzhou","young_man2","男性",22,116,3,},
			{6,"战浪","dy6_zhanlang","young_man1","男性",27,115,3,},
			{6,"冷工名","dy6_lenggongming","young_man2","男性",27,118,3,},
			{6,"祈悲","dy6_qibei","old_man2","男性",57,110,3,},
			{6,"武元神","dy6_wuyuanshen","young_man6","男性",27,112,3,},
			{6,"燕色","dy6_yanshai","young_man6","男性",48,119,3,},
			{6,"纳名","dy6_namin","banditi","男性",32,111,3,},
			{6,"丽青","dy6_liqing","young_woman3","女性",23,112,4,},
			{6,"灵智","dy6_lingzhi","old_monk","男性",56,117,4,},
			{6,"阿黑","dy6_ahai","young_woman10","女性",34,113,4,},
			{6,"龙藤","dy6_longteng","young_man5","男性",45,119,4,},
			{6,"田中","dy6_tianzhong","young_man1","男性",23,118,4,},
			{6,"龙衣","dy6_longyi","young_woman2","女性",19,116,4,},
			{6,"兰林","dy6_lanlin","old_man1","男性",58,110,4,},
			{6,"花云","dy6_hunyun","old_nun","男性",74,119,4,},
			{6,"华西","dy6_huaxi","young_woman4","女性",25,111,5,},
			{6,"高君","dy6_gaojun","young_man6","男性",26,113,5,},
			{6,"拉撒","dy6_lasa","young_man5","男性",55,117,5,},
			{6,"年佳","dy6_nianjia","young_man3","男性",32,115,5,},
			{6,"红情","dy6_hongqing","young_man1","男性",24,116,5,},
			{6,"宁素","dy6_ningsu","young_woman2","男性",25,119,6,},
			{6,"连丽军","dy6_lialijun","young_woman5","女性",26,113,6,},
			{6,"寒山妹","dy6_hanshanmei","young_woman3","女性",24,115,6,},
			{6,"西其","dy6_xiqi","young_woman2","女性",34,110,6,},
			{6,"择生","dy6_zeshen","young_man3","男性",23,117,6,},
			{6,"路易丝","dy6_luyisi","young_woman3","女性",22,111,6,},
			{6,"采佬","dy6_cailao","young_woman2","女性",23,114,6,},
			{6,"红跃","dy6_hongyue","young_woman3","女性",18,116,6,},
			{6,"红师","dy6_hongshi","young_man5","男性",34,118,6,},
			{6,"白蛋","dy6_baidan","young_man1","男性",25,113,7,},
			{6,"神力往","dy6_shenliwang","young_man1","男性",25,112,7,},
			{6,"嚎伸","dy6_haoshen","young_man2","男性",35,117,7,},
			{6,"山蛇","dy6_shanshe","old_man1","男性",65,114,7,},
			{6,"歌战","dy6_gezhan","young_man6","男性",43,110,7,},
			{7,"随云","dy7_suiyun","young_woman3","女性",23,120,1,},
			{7,"魏拨","dy7_weibo","young_monk","男性",22,121,1,},
			{7,"客横声","dy7_kehengsheng","young_man6","男性",25,121,2,},
			{7,"浪子","dy7_langzi","old_man2","男性",25,120,2,},
			{7,"谢问","dy7_xiewen","young_man1","男性",32,121,2,},
			{7,"谢石","dy7_xieshi","young_man1","男性",28,122,3,},
			{7,"直磨","dy7_zhimao","young_man4","男性",24,122,4,},
			{7,"谢云","dy7_xieyun","young_man4","男性",25,122,4,},
			{7,"谢绝","dy7_xiejun","young_man3","男性",26,122,5,},
			{7,"熊巨","dy7_xiongju","young_man4","男性",24,120,5,},
			{7,"悬浮","dy7_xuanfu","young_man3","男性",23,122,6,},
			{7,"李少杰","dy7_lishaojie","general","男性",23,121,6,},
			{7,"无心","dy7_wuxin","young_woman4","女性",26,120,6,},
			{7,"龙依","dy7_longyi","young_woman2","女性",22,121,7,},
			{7,"小蝶","dy7_xiaodie","young_woman5","女性",24,120,7,},
			{3,"段景住","dy3_duajingzhu","triggerman1","男性",42,82,2,},
			{3,"刘堂","dy3_liutan","cateran","男性",22,88,2,},
			{3,"燕清","dy3_yanqing","young_man3","男性",20,87,2,},
			{3,"卢君义","dy3_lujunyi","young_man5","男性",45,80,2,},
			{3,"杨淋","dy3_yanglin","triggerman1","男性",45,86,2,},
			{3,"李滚","dy3_ligun","young_man4","男性",37,84,2,},
			{3,"孔凉","dy3_konglian","taoist","男性",46,85,2,},
			{3,"周铜","dy3_zhoutong","banditi","男性",35,83,2,},
			{3,"杨直","dy3_yangzhi","young_man2","男性",23,89,2,},
		};

		char msg[255];
		int i;

		for(i=MONSTER_NUM; i<MONSTER_NUM; i++)
		{
			TRACE("#include \"../npc/18dy/c%d/%s.h\"\n", mon[i].dy, mon[i].base_name);			
		}

		TRACE("\n\nCNpc * LoadNPC_18dy(string npc_name)\n{\nCNpc * t = 0;\n\n");
		for(i=240; i<MONSTER_NUM; i++)
		{
			TRACE("\telse if(npc_name == \"%s\")\n\t\tt = new CN%s();\n",
				mon[i].base_name, mon[i].base_name);
		}

		for(i=0; i<MONSTER_NUM; i++)
		{			
			FILE * fp = fopen(snprintf(msg, 255, "monster/c%d/%s.h", mon[i].dy, mon[i].base_name), "wt");
			if(! fp) return notify_fail("valid filename %s!", msg);
				
			fprintf(fp, "//%s.h\n//lanwood 2001-11-04\n\n", mon[i].base_name);
			
			fprintf(fp, "MONSTER_BEGIN(CN%s);\n\n", mon[i].base_name);
			fprintf(fp, "void create()\n{\n");
			fprintf(fp, "\tset_name(\"%s\", \"%s\");\n\n\tset(\"icon\", %s);\n", mon[i].name, mon[i].base_name, mon[i].icon);

			fprintf(fp, "\tset(\"gender\", \"%s\");\n", mon[i].gender);			
			fprintf(fp, "\tset(\"level\", %ld);\n\n", mon[i].lv);			
						
			fprintf(fp, "\tset(\"max_hp\", %ld);\n", mon[i].lv * 200);
			fprintf(fp, "\tset(\"max_mp\", %ld);\n", mon[i].lv * 50);
			fprintf(fp, "\tset(\"mp_factor\", %ld);\n\n", mon[i].lv + 10);
			fprintf(fp, "\tset(\"combat_exp\", %ld);\n\n", CChar::Level2Exp(mon[i].lv));
			
			fprintf(fp, "\tset(\"cast_chance\", 20);\n");
			
			fprintf(fp, "\tset(\"nkgain\", 1);\n\n");
			
			fprintf(fp, "\tset(\"str\", %ld);\n", mon[i].lv / 3 + random(20));
			fprintf(fp, "\tset(\"con\", %ld);\n", mon[i].lv / 3 + random(20));
			fprintf(fp, "\tset(\"int\", %ld);\n", mon[i].lv / 3 + random(20));
			fprintf(fp, "\tset(\"dex\", %ld);\n\n", mon[i].lv / 3 + random(20));

			//计算技能等级
			int slevel = CChar::level2skill(mon[i].lv);
			int line = offset[mon[i].dy - 1] + mon[i].skclass - 1;
				
			fprintf(fp, "\tset_skill(\"%s\", %ld);\n", skills[line].attack_skill, slevel);
			fprintf(fp, "\tset_skill(\"%s\", %ld);\n", skills[line].attack_base, slevel);
			if(skills[line].attack_skill2[0])
			{
				fprintf(fp, "\tset_skill(\"%s\", %ld);\n", skills[line].attack_skill2, slevel);
				fprintf(fp, "\tset_skill(\"%s\", %ld);\n", skills[line].attack_base2, slevel);
			}

			fprintf(fp, "\tset_skill(\"%s\", %ld);\n", skills[line].dodge, slevel);
			fprintf(fp, "\tset_skill(\"dodge\", %ld);\n", slevel);
			fprintf(fp, "\tset_skill(\"%s\", %ld);\n", skills[line].force, slevel);
			fprintf(fp, "\tset_skill(\"force\", %ld);\n\n", slevel);

			fprintf(fp, "\tmap_skill(\"%s\", \"%s\");\n", skills[line].attack_base, skills[line].attack_skill);
			if(skills[line].attack_skill2[0])
				fprintf(fp, "\tmap_skill(\"%s\", \"%s\");\n", skills[line].attack_base2, skills[line].attack_skill2);
			fprintf(fp, "\tmap_skill(\"dodge\", \"%s\");\n", skills[line].dodge);
			fprintf(fp, "\tmap_skill(\"force\", \"%s\");\n", skills[line].force);

			char mapto[20], mapto2[20];
			strcpy(mapto, skills[line].attack_skill);
			strcpy(mapto2, skills[line].attack_skill2);
			if(strcmp(skills[line].prepare, skills[line].attack_base2) == 0)
			{
				strcpy(mapto, skills[line].attack_skill2);
				strcpy(mapto2, skills[line].attack_skill);
			}			
			
			fprintf(fp, "\n\tprepare_skill(\"%s\", \"%s\");\n", skills[line].prepare, mapto);
			if(skills[line].prepare2[0])
				fprintf(fp, "\tprepare_skill(\"%s\", \"%s\");\n", skills[line].prepare2, mapto2);

			fprintf(fp, "\n\tset(\"apply/armor\", %ld);\n", mon[i].lv * 2);
			fprintf(fp, "\tset(\"apply/damage\", %ld);\n\n", 30 + mon[i].lv * 2);

			if(fam[mon[i].dy - 1][0])
				fprintf(fp, "\tcreate_family(\"%s\", %ld, \"弟子\");\n\n", fam[mon[i].dy - 1], 2 + random(5));

			//携带武器
			if(skills[line].weapon[0])
			{
				CMapping m;
				m.set("sword", "mujian");
				m.set("blade", "caidao");
				m.set("throwing", "eluanshi");
				m.set("whip", "yangbian");
				m.set("axe", "futou");
				m.set("club", "tieqiao");
				m.set("dagger", "panguanbi");
				m.set("staff", "shuzhi2");
			
				fprintf(fp, "\tcarry_object(\"%s\")->wield();\n", m.querystr(skills[line].weapon));
			}

			fprintf(fp, "\n}\n\n");

			fprintf(fp, "char * chat_msg_combat()\n{\n\tswitch(random(9))\n\t{\n");
			
			for(int t = 0; t<9; t++)
			{
				if(skills[line].perform[t][0])
					fprintf(fp, "\tcase %ld:\n\t\tperform_action(\"%s\", 1);\n\t\tbreak;\n", t, skills[line].perform[t]);
				else
					fprintf(fp, "\tcase %ld:\n\t\tperform_action(\"force recover\", 0);\n\t\tbreak;\n", t);
			}

			fprintf(fp, "\t}\n\n\treturn 0;\n}\n\n");
			
			fprintf(fp, "MONSTER_END;");
			fclose(fp);
		}

		return 1;
	}

  */
};

#undef	MONSTER_NUM