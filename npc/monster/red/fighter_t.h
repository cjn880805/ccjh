
NPC_BEGIN(CNfighter_t);

void create()
{
	set_name("比武大会登记员", "chao feng");

//	set("title", "比武大会登记员");
	set("icon", girl2);
	set("gender", "女性" );
	set("age", 25);

	set("chname", "现场直播");
	set("channel", "wldh");

	set("grant", 80);
	
	set("combat_exp", 150);
	set("attitude", "friendly");
	
	set("biwu/name", "重出江湖比武大会");
	set("biwu/register/0", "空缺");
	set("biwu/turn0/0", "0");

	set("file_name", querystr("base_name"));

	Load();
};

int Save()
{
	char msg[255];
	return SaveToLocal(snprintf(msg, 255, "data/npc/%s.o", querystr("file_name")), &_M);
}
int Load()
{
	char msg[255];
	return LoadFromLocal(snprintf(msg, 255, "data/npc/%s.o", querystr("file_name")), &_M);	
}


//报名程序
int register_me(CChar * me)
{
	if(me->query("combat_exp") < 5000)
	{
		say("就您这水平，一边歇会儿，成不？", me);
	}
	else
	{		
		if(has_register(me))
		{			
			say("您已登记。请耐心等待比武大会开始。", me);
		}
		else
		{
			register_join(me, querymap("biwu/register"));
			say("记下了，等侯比武大会开始。", me);			
		}
	}

	SendMenu(me);
	return 1;
}


int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];

	int state = query("state");

	if(state == 0)		//报名阶段
	{
		if(! strlen(ask))
		{
			AddMenuItem("查看报名情况", "1", me);
			AddMenuItem("询问比赛条件", "tiaojian", me);

			if(! has_register(me))
				AddMenuItem("我要报名", "register", me);
			else
				AddMenuItem("取消报名", "cancel", me);

			if(me->query("grant") > 80)
			{
				AddMenuItem("开始抽签", "chouqian", me);				
			}

		}
		else if(strcmp(ask, "1") == 0)
		{
			say(snprintf(msg, 255, "已有%ld人报名。", query_count(querymap("biwu/register"))), me);
		}		
		else if(strcmp(ask, "chouqian") == 0 && wizardp(me))
		{
			chouqian();			
			set("state", 1);	//抽签结束
			return 1;
		}
		else if(strcmp(ask, "tiaojian") == 0)
		{
			say("本届比赛采取统一报名，赛前半小时按总经验分组的方式。", me);
		}
		else if(strcmp(ask, "register") == 0)
			return register_me(me);		//我要报名
		else 
		{
			del(snprintf(msg, 255, "biwu/register/%s", me->id(1)));
			Save();
			say("取消了报名", me);
		}
	}
	else
	{
		say("比赛分组已经结束", me);
	}
	SendMenu(me);
	return 1;
}

//抽签程序 
int chouqian()
{		
	char msg[255];
	del("biwu/register/0");
	CMapping * reg = querymap("biwu/register");
	CMapping * result = querymap("biwu/turn0");
	if(! result)
	{
		CMapping m;
		set(msg, m);
		result = querymap(msg);
	}
	if(! reg || ! result) return 0;
	CVector v;
	reg->keys(v);
	
	int count,load;
	
	while(( count = v.count()))
	{
		const char * key = v[random(count)];
		CUser * targetx;
		targetx=find_online(key);
		if (!targetx)
		{
			load=1;
			targetx = add_user();
			targetx->set("id", key);
			targetx->LoadFromServer();	
		}
		int exp=targetx->query("combat_exp");
		if(exp>=10000000)
			exp=4;
		else if(exp>=3000000)
			exp=3;
		else if(exp>=500000)
			exp=2;
		else 
			exp=1;
		switch(exp)
		{
		case 1:
			if(reg)
			{
				CNpc * fight1 = load_npc("wiz_fighter1");
				CMapping * reg1 =fight1->querymap("biwu/register");
				reg1->set(targetx->id(1), targetx->name(1));
				fight1->SaveToLocal("data/npc/wiz_fighter1.o", &fight1->_M);
				destruct(fight1);
			}
			break;
		case 2:
			if(reg)
			{
				CNpc * fight2 = load_npc("wiz_fighter2");
				CMapping * reg2 =fight2->querymap("biwu/register");
				reg2->set(targetx->id(1), targetx->name(1));
				fight2->SaveToLocal("data/npc/wiz_fighter2.o", &fight2->_M);
				destruct(fight2);
			}
			break;
		case 3:
			if(reg)
			{
				CNpc * fight3 = load_npc("wiz_fighter3");
				CMapping * reg3 =fight3->querymap("biwu/register");
				reg3->set(targetx->id(1), targetx->name(1));
				fight3->SaveToLocal("data/npc/wiz_fighter3.o", &fight3->_M);
				destruct(fight3);
			}
			break;
		case 4:
			if(reg)
			{
				CNpc * fight4 = load_npc("wiz_fighter4");
				CMapping * reg4 =fight4->querymap("biwu/register");
				reg4->set(targetx->id(1), targetx->name(1));
				fight4->SaveToLocal("data/npc/wiz_fighter4.o", &fight4->_M);
				destruct(fight4);
			}
			break;
		}
		v.remove(key);
		if(load)destruct(targetx);
	}
	return 1;
}


//加到注册表里
int do_register(CChar * me, const char * id)
{
	char msg[255];
	int load = 0;

	CUser * user = find_online(id);
	if(! user)
	{
		load = 1;
		user = add_user();
		user->set("id", id);

		if(! user->LoadFromServer())
			return notify_fail("没有这个人!");
	}

	set(snprintf(msg, 255, "biwu/register/%s", id), user->name(1));
	tell_object(me, snprintf(msg, 255, "将%s注册.", user->name(1)));

	if(load)
		destruct(user);

	Save();
	return 1;
}


//登记
void register_join(CChar * me, CMapping * team)
{
	if(team)
	{
		team->set(me->id(1), me->name(1));
		Save();
	}
}

int query_count(CMapping * team)
{
	if(! team) return 0;
	return team->GetCount();
}

int has_register(CChar * me)
{
	CMapping * team = querymap("biwu/register");
	if(! team) return 0;
	return team->querystr(me->querystr("id"))[0];
}

NPC_END;



