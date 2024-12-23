//qigai.h 任务乞丐
//玩家仆人

NPC_BEGIN(CNmonster_qigai);

void create()
{
	set_name("落魄乞丐", "luo po qigai");
    set("gender", "男性");
	set("icon", begger);

    set("age", 20+random(20));
    
	set("per", 18 + random(15));
    set("combat_exp", 20000);
	set("str", 40);
	set("no_kill", 1);

	set("infinity", 1);		//不受容量限制

	set("is_user", 1);
	
	set("index",random(4)+1);
}

int do_talk(CChar *me, char * ask)
{
	switch(query("index"))
	{
	case 1:
		say("可怜可怜我这个孤苦无依的人吧，我已经很多天没有吃的饱穿的暖了。。。",me);
		AddMenuItem("查看追杀令", "$0lookenemy $1", me);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	}
	//只能在自己的家里设定仆人的	
	AddMenuItem("查看追杀令", "$0lookenemy $1", me);
	AddMenuItem("查看本帮成员", "$0wholook $1", me);

	if(me->querymap("corps"))
	{
		if(me->query("corps/level") <= environment()->query("caiwu"))
		{
			AddMenuItem("存款", "$1dep $1 $2", me);
			AddMenuItem("取款", "$1wit $1 $2", me);
			AddMenuItem("查看帐户", "$0bal $1", me);
		}

		if(me->query("corps/level") < 7)
		{
			AddMenuItem("索取接引令", "$0getling1 $1", me);
			AddMenuItem("索取开除令", "$0getling2 $1", me);
		}

		if(me->query("corps/level") < 3)
		{			
			AddMenuItem("设置留言", "$2welcome $1 $2", me);				
					
			AddMenuItem("发布追杀令", "$0enemy $1", me);
			AddMenuItem("撤消追杀令", "$0remenemy $1", me);	
			
			if(me->query("corps/level") == 1)
			{
				AddMenuItem("索取禅让令", "$0getling3 $1", me);
				AddMenuItem("本派等级制定", "$0setting $1", me);
				AddMenuItem("本派财务权限设定", "$0caiwu $1", me);
			}
		}

		if(me->query("corps/level") != 1)
		{
			AddMenuItem("退教", "$0leave $1", me);
		}
	}

	SendMenu(me);
		
	return 1;
}

int do_getling1(CChar * me)
{
	say("这支令牌用于招收新人。");	
	load_item("jieyinling")->move(me);
	return 1;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "welcome") == 0)
		return do_welcome(me, arg);
	else if(strcmp(comm, "getling1") == 0)
		return do_getling1(me);
	else if(strcmp(comm, "getling2") == 0)
		return do_getling2(me);
	
	else if(strcmp(comm, "leave") == 0)
		return do_leave(me, arg);
	else if(strcmp(comm, "enemy") == 0)
	{
		CContainer * env = environment();
		if(! env->LockData(1)) return 0;
		env->Load();
		int ret = do_enemy(me, arg);
		env->LockData(0);
		return ret;
	}
	else if(strcmp(comm, "remenemy") == 0)
	{
		CContainer * env = environment();
		if(! env->LockData(1)) return 0;
		env->Load();
		int ret = do_remenemy(me, arg);
		env->LockData(0);
		return ret;
	}
	else if(strcmp(comm, "lookenemy") == 0)
		return do_lookenemy(me);
	else if(strcmp(comm, "wholook") == 0)
		return do_who(me);

	if(me->query("corps/level") <= environment()->query("caiwu") && ! g_Combatd.query("disable_corps_balance"))
	{
		if(strcmp(comm, "dep") == 0)
		{
			return do_balance(1, me, atol(arg));
		}
		else if(strcmp(comm, "wit") == 0)
		{
			return do_balance(2, me, atol(arg));
		}
		else if(strcmp(comm, "bal") == 0)
		{
			return do_balance(3, me, atol(arg));
		}
	}
	
	if(me->query("corps/level") == 1)
	{
		if(strcmp(comm, "getling3") == 0)
			return do_getling3(me);
		else if(strcmp(comm, "setting") == 0)
		{
			CContainer * env = environment();
			if(! env->LockData(1)) return 0;
			env->Load();
			int ret = do_setting(me, arg);
			env->LockData(0);
			return ret;
		}
		else if(strcmp(comm, "chset") == 0)
		{
			CContainer * env = environment();
			if(! env->LockData(1)) return 0;
			env->Load();
			int ret = do_chset(me, arg);
			env->LockData(0);
			return ret;
		}
		else if(strcmp(comm, "caiwu") == 0)
		{
			CContainer * env = environment();
			if(! env->LockData(1)) return 0;
			env->Load();
			int ret = do_caiwu(me, arg);
			env->LockData(0);
			return ret;
		}
	}

	return CNpc::handle_action(comm, me, arg);
}


NPC_END;




