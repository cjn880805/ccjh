//dy_master.h
//lanwood 2001-11-04

NPC_BEGIN(CNdy_master);

void create()
{
	set_name("丝路飘渺", "piao miao");
	
	set("gender", "女性");
	
	set("icon", young_woman1);
	set("level", 20);
	
	set("max_hp", 12000);
	set("max_mp", 3000);
	set("mp_factor", 70);
	
	set("combat_exp", 952800);
	
	set("cast_chance", 20);
	set("nkgain", 1);
	
	set("str", 34);
	set("con", 35);
	set("int", 35);
	set("dex", 22);
	
	set_skill("changquan", 206);
	set_skill("cuff", 206);
	set_skill("guimei_shenfa", 206);
	set_skill("dodge", 206);
	set_skill("hunyuan_yiqi", 206);
	set_skill("force", 206);
	
	map_skill("cuff", "changquan");
	map_skill("dodge", "guimei_shenfa");
	map_skill("force", "hunyuan_yiqi");
	
	prepare_skill("cuff", "changquan");
	
	set("apply/armor", 120);
	set("apply/damage", 150);
	
	set("task_open", 1);	//任务开放
	set("no_kill", 1);
}

char * chat_msg_combat()
{
	perform_action("force recover", 0);
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(query("task_open"))
	{
		AddMenuItem("慕容紫莹", "$0getinfo $1", me);
		AddMenuItem("杀人放火", "$0askquest $1", me);
		AddMenuItem("幸不辱命", "$0report $1", me);
		AddMenuItem("不幸失败", "$0fail $1", me);
		SendMenu(me);	
	}
	else
	{
		say("看来大侠忍心看到中原武林如此沉沦不成？罢了罢了。", me);
		SendMenu(me);
	}	
	return 1;
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(query("task_open"))
	{
		if(strcmp(comm, "getinfo") == 0)
			return do_18dy(me);
		if(strcmp(comm, "askquest") == 0)
			return do_kill(me);	
		if(strcmp(comm, "report") == 0)
			return do_r(me);
		if(strcmp(comm, "fail") == 0)
			return do_f(me);
	}
	
	return CNpc::handle_action(comm, me, arg);
}

int do_18dy(CChar * me)
{
	
	say("关外慕容世家以搜集天下武林秘籍而闻名于世已逾百年。"
		"他们的第十六代传人慕容紫莹突然发出英雄贴，邀请天下英雄"
		"聚会关外英雄楼，解读慕容世家的各种武学秘籍。", me);
	say("据说慕容世家保留有各派早已失传多年的武学珍本，"
		"有机会去慕容世家参解秘籍，对江湖中的所有人而言都有极大的诱惑力。", me);
	say("英雄楼是建设在地下的一座庞大的机关，据说有十八层。"
		"每一层都存放着江湖中颇具名望的各派武学秘籍。", me);
	say("每天都有很多人被送进英雄楼。"
		"人们一进到里面，就变得癫狂起来。他们象疯子一样如痴如醉的修习绝学，"
		"也经常为争夺一本秘籍而发生杀戮。", me);
	say("先来的人不愿更多的人拥有学习秘籍的机会，"
		"而对后来者进行肆意的屠杀。现在的英雄楼已变成了人间地狱。"
		"但是，每天进入英雄楼的人仍然有增无减。", me);
	say("英雄楼里剩下的人已经魔性大发失去了理智，其精神已"
		"被慕容紫莹完全控制了。慕容紫莹正是利用人性的贪婪"
		"在一步步的毁灭中原武林，以达到她契丹复国的梦想。", me);
	say("必须阻止慕容紫莹的阴谋。", me);
	SendMenu(me);
	
	if(!me->query("18dy/task"))
	{	
		say("关外慕容世家以搜集天下武林秘籍而闻名于世已逾百年。"
			"他们的第十六代传人慕容紫莹突然发出英雄贴，邀请天下英雄"
			"聚会关外英雄楼，解读慕容世家的各种武学秘籍。", me);
		say("据说慕容世家保留有各派早已失传多年的武学珍本，"
			"有机会去慕容世家参解秘籍，对江湖中的所有人而言都有极大的诱惑力。", me);
		say("英雄楼是建设在地下的一座庞大的机关，据说有十八层。"
			"每一层都存放着江湖中颇具名望的各派武学秘籍。", me);
		say("每天都有很多人被送进英雄楼。"
			"人们一进到里面，就变得癫狂起来。他们象疯子一样如痴如醉的修习绝学，"
			"也经常为争夺一本秘籍而发生杀戮。", me);
		say("先来的人不愿更多的人拥有学习秘籍的机会，"
			"而对后来者进行肆意的屠杀。现在的英雄楼已变成了人间地狱。"
			"但是，每天进入英雄楼的人仍然有增无减。", me);
		say("英雄楼里剩下的人已经魔性大发失去了理智，其精神已"
			"被慕容紫莹完全控制了。慕容紫莹正是利用人性的贪婪"
			"在一步步的毁灭中原武林，以达到她契丹复国的梦想。", me);
		say("必须阻止慕容紫莹的阴谋。", me);
		SendMenu(me);
		
		me->set("18dy/level", 1);		//丢了石头，重新来吧。
		me->set("18dy/task", 1);		//第一层任务
	}
	return 1;
}

//18地狱
int do_kill(CChar * me)
{
	if(!me->query("18dy/task"))
	{	
		me->set("18dy/level", 1);	//第一层
		me->set("18dy/task", 1);	//第一层任务
	}
	
	if (me->query("18dy/level") != me->query("18dy/task") 
		&& me->query("18dy/task") > 0)
		return notify_fail("丝路飘渺说：你不能在这个层次完成任务。");	
	
	if (me->query_temp("18dy/finish") )
		return notify_fail("丝路飘渺说：你完成了我的任务，应该向我报告的。");
	
	if (me->is_busy())
		return notify_fail("你现在很忙。。。");
	
	if (me->query_temp("18dy/master"))			//若有任务则重复任务介绍。
	{
		char msg[255];
		message_vision(snprintf(msg, 255, "$RED我不是让你潜入%s，杀掉%s，听明白了还不快去？$COM",me->querystr_temp("18dy/env"),me->querystr_temp("18dy/kill_name")), me);
		return 1;
	}
	
	char msg[255];
	CNpc * tn;
	
	switch(me->query("18dy/task"))
	{
	case 1:
		tn = load_npc("dy2_monster");
		me->set_temp("18dy/env", "黄泉之路");
		break;
	case 2:
		tn = load_npc("dy3_monster");
		me->set_temp("18dy/env", "奈何桥");
		break;
	case 3:
		tn = load_npc("dy4_monster");
		me->set_temp("18dy/env", "鬼门关");
		break;
	case 4:
		tn = load_npc("dy5_monster");
		me->set_temp("18dy/env", "泥犁地狱");
		break;
	case 5:
		tn = load_npc("dy6_monster");
		me->set_temp("18dy/env", "刀山地狱");
		break;
	case 6:
		tn = load_npc("dy7_monster");
		me->set_temp("18dy/env", "沸沙地狱");
		break;
	case 7:
		tn = load_npc("dy8_monster");
		me->set_temp("18dy/env", "沸屎地狱");
		break;
	case 8:
		tn = load_npc("dy9_monster");
		me->set_temp("18dy/env", "黑身地狱");
		break;
	case 9:
		tn = load_npc("dy10_monster");
		me->set_temp("18dy/env", "火海地狱");
		break;
	case 10:
		tn = load_npc("dy11_monster");
		me->set_temp("18dy/env", "镬汤地狱");
		break;
	case 11:
		tn = load_npc("dy12_monster");
		me->set_temp("18dy/env", "铁床地狱");
		break;
	case 12:
		tn = load_npc("dy13_monster");
		me->set_temp("18dy/env", "嵯山地狱");
		break;
	case 13:
		tn = load_npc("dy14_monster");
		me->set_temp("18dy/env", "寒冰地狱");
		break;
	case 14:
		tn = load_npc("dy15_monster");
		me->set_temp("18dy/env", "剥皮地狱");
		break;
	case 15:
		tn = load_npc("dy16_monster");
		me->set_temp("18dy/env", "畜性地狱");
		break;
	case 16:
		tn = load_npc("dy17_monster");
		me->set_temp("18dy/env", "刀兵地狱");
		break;
	case 17:
		tn = load_npc("dy18_monster");
		me->set_temp("18dy/env", "铁磨地狱");
		break;
	case 18:
		tn = load_npc("dy19_monster");
		me->set_temp("18dy/env", "冰地狱");
		break;
	case 19:
		tn = load_npc("dy20_monster");
		me->set_temp("18dy/env", "蛆虫地狱");
		break;
	case 20:
		tn = load_npc("dy21_monster");
		me->set_temp("18dy/env", "烊铜地狱");
		break;
	case 21:
		tn = load_npc("dy22_monster");
		me->set_temp("18dy/env", "阿鼻地狱");
		break;
	}
	message_vision(snprintf(msg, 255, "$HIG请大侠潜入$HIR%s$HIG，杀掉%s。$COM", me->querystr_temp("18dy/env"),tn->name()), me);
	me->set_temp("18dy/kill", tn->querystr("id"));		//任务NPC的id。
	me->set_temp("18dy/kill_name", tn->querystr("name"));		//任务NPC的中文名字。
	me->set_temp("18dy/master", 1);							//接任务的标记。
	destruct(tn);
	
	return 1;
}

int do_r(CChar * me)
{
	
	if (me->query("18dy/boss") == 1)
	{
		me->del("18dy/boss");			//去掉杀死BOSS的纪录。
		me->add("18dy/task", 1);		//你可以去下一关杀敌了。
		
		me->delete_temp("18dy");				//清除上一关的信息。
		
		reward_exp(me);					//奖励3次经验。	
		reward_exp(me);	
		reward_exp(me);	
		
		return notify_fail("丝路飘渺说：你杀了BOSS，好，好，好，你可以去下一关历险了。");
	}
	
	if (!me->query_temp("18dy/finish") )
		return notify_fail("丝路飘渺说：你杀了我要你杀的人了么？");
	
	message_vision("$HIG丝路飘渺道：好，好！$N，你完成了这次艰巨的任务，请再接再厉！",me);
	
	reward_exp(me);	
	
	me->delete_temp("18dy/finish");
	
	if (me->query_temp("18dy/run") >= (5+me->query("18dy/level")) )
	{
		me->set_temp("18dy/run", 0l);
	}
	
	me->add_temp("18dy/run", 1);							//连续完成任务的次数。
	me->delete_temp("18dy/master");							//清空任务纪录。
	me->delete_temp("18dy/kill_name");	
	me->delete_temp("18dy/kill");	
	me->delete_temp("18dy/env");	
	me->add("18dy/num", 1);								//增加完成任务的次数。
	
	me->start_busy(6);
	
	if (me->query("18dy/num") >= (81+me->query("18dy/level")*9))						//完成任务的次数。
	{
		me->add("18dy/level", 1);
		return notify_fail("丝路飘渺说：你可以去下一层了。");
	}
	
	return 1;
}

void reward_exp(CChar * me)
{
	char msg[255], tmp[80];
	LONG exp = me->query("18dy/task");		
	
	exp = 300 + exp * 50;
	
	exp = exp + random(me->query_temp("18dy/run") * exp / 30);	//难度系数
	
	exp = (random(exp) + exp) / 2;
	
	me->add("combat_exp", exp);
	tell_object(me, snprintf(msg, 255, "$HIC你获得了%s点经验！", chinese_number(exp, tmp)));
	
	g_Channel.do_channel(&g_Channel, 0, "sys", 
		snprintf(msg, 255, "%s完成了在%s杀%s的任务，获得%d经验。", me->name(1), me->querystr_temp("18dy/env"),me->querystr_temp("18dy/kill_name"),  exp));
	
	me->FlushMyInfo();
}

int do_f(CChar * me)
{
	
	if (me->query_temp("18dy/master") == 0)
		return notify_fail("$HIR丝路飘渺大怒：你根本没领任务，是我脑袋有纹还是你脑袋有坑。$COM");
	
	if (me->query_temp("18dy/finish") == 1)
		return notify_fail("$GRN丝路飘渺不解：任务完成却不要回报，难道嫌弃小女子么？$COM");
	
	if (me->query_temp("18dy/master") == 1)
	{
		me->delete_temp("18dy/finish");		//设置玩家处于任务未完成状态。
		me->delete_temp("18dy/master");		//清空任务纪录。
		me->delete_temp("18dy/run");		//清空连续完成任务的次数。
		
		me->delete_temp("18dy/kill");		//清空任务NPC的名称。
		me->delete_temp("18dy/kill_name");	//清空任务NPC的中文名字。
		
		if (me->query("18dy/num") < 1)
		{
			me->set("18dy/num", 1);
		}
		
		me->add("18dy/num", -1);			//完成任务的次数。
		
		me->start_busy(30);					//玩家开始忙乱30秒。
		
		return notify_fail("丝路飘渺幽幽叹道：大侠既然能力不够，小女也不在加勉强。");
	}
	return 1;
}


NPC_END;