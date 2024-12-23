//monster_rebooter.h
//NPC 重起机器
//Lanwood 2001-04-03

NPC_BEGIN(CNmonster_rebooter);

void create()
{
	set_name( "末世冥王", "ming wang");
		
	set("age", 40);
	set("gender", "男性");

	set("max_hp", 200000);
	set("max_mp", 200000);
	set("mp_factor", 150);
	set("combat_exp", 2000000);

    set_skill("force",   250);
	set_skill("unarmed", 250);
	set_skill("sword",   250);
	set_skill("changquan",  250);
	set_skill("magic", 250);
	set_skill("jinshe_jian", 250);
	set("nkgain", 1500);
	
	set("grant", 99);

	map_skill("unarmed", "changquan");
	map_skill("force", "magic");
	map_skill("sword", "jinshe_jian");

	set_inquiry("世界毁灭", do_doom);
	//set_inquiry("洗礼", do_xi);

	set("wait_time", 10);	//10分钟

	carry_object("sword_3")->wield();	
};

//清技能
static char * do_xi(CNpc * npc, CChar * me)
{
	//列出玩家的技能,选择清洗
	npc->say("接受忘记的技能可恢复为技能经验，代价是永世不得再学习，请一定考虑清楚。", me);
	npc->say("恢复的技能经验按你当前学习效率计算。\n请选择要清洗的技能。", me);
	
	CMapping * skills = me->query_skills();
	CVector v;
	CSkill * sk;
	char msg[80],cmd[80];
	int bns = me->learn_bonus();
	LONG sk_exp = me->query("sk_exp");

	skills->keys(v);

	for(int i=0; i<v.count(); i++)
	{
		const char * skname = v[i];
		sk = load_skill(skname);

		long exp = need_exp(me->query_skill(skname, 1)) / bns + 1;

		npc->AddMenuItem(snprintf(msg, 80, "%s:%ld", sk->name(), exp < sk_exp ? exp : sk_exp), 
			snprintf(cmd, 80, "$0clrsk $1 %s", skname), me); 
	}

	npc->SendMenu(me);
	return 0;
}

int handle_action(char * comm, CChar * me, char * arg)
{
	char msg[80];
	if(strcmp(comm, "clrsk") == 0)
	{
		CSkill * sk = load_skill(arg);
		say(snprintf(msg, 80, "是否清洗%s？", sk->name()), me);
		AddMenuItem("是", snprintf(msg, 80, "$0clrsk2 $1 %s", arg), me);
		AddMenuItem("否", "", me);
		SendMenu(me);
		return 1;
	}
	else if(strcmp(comm, "clrsk2") == 0)
	{
	//	clear_skill(me, arg);
		return 1;
	}

	return CNpc::handle_action(comm, me, arg);
}

static long need_exp(int lv)
{
	register long sum = 0;

	for(int i=lv; i>0; i--)
	{
		sum = sum + i*i;
	}

	return sum;
}

void clear_skill(CChar * me, char * skillname)
{				
	CSkill * sk = load_skill(skillname);
	char msg[255];

	//现在计算所需的经验	
	LONG need_points =  need_exp(me->query_skill(skillname, 1));
	LONG need_exp = need_points / me->learn_bonus() + 1;		
		
	CMapping * m = me->query_skill_map();
	m->clear();
	m = me->query_skill_prepare();
	m->clear();

	m = me->querymap("forget");
	if(m && m->GetCount() >= 20)
	{
		tell_object(me, "你忘记了太多技能，无法再清洗了。");
		return;
	}

	if(m && ! m->undefinedp(skillname))
	{
		tell_object(me, "这项技能你已经忘记了，不能继续清洗。");
		return;
	}

	long sk_exp = me->query("sk_exp");
	
	if(sk_exp - need_exp < 0)
		need_exp = sk_exp;

	me->add("sk_exp", -need_exp);	
	me->delete_skill(skillname);

	if(need_exp)
		me->add(snprintf(msg, 255, "forget/%s", skillname), need_exp);
		
	me->FlushMyInfo();
	me->FlushMySkill(me);

	tell_object(me, snprintf(msg, 255, "$HIC你忘记了%s，获得%ld点经验！", sk->name(1), need_exp));
	g_Channel.do_channel(&g_Channel, 0, "sys", 
		snprintf(msg, 255, "%s忘记了%s，获得了%ld点经验。", me->name(1), sk->name(1), need_exp));

}

static char * do_doom(CNpc * me, CChar * who)
{
	if(! wizardp(who)) return "靠！就凭你！！！";

	if(me->query("rebooting")) return "靠！你烦不烦！！";

	me->set("rebooting", 1);
	g_Channel.do_channel(me, NULL, "wiz", "$HIR\n\n\n              天下众生都给我听着！！！\n\n\n              快把你们的人头交上来！\n\n\n              否则！！\n\n              休怪我不客气了！\n\n\n\n");
	me->call_out(do_reboot, 6);

	me->command("force_save 0 all");
	return 0;
}

static void do_reboot(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
		
	if(me->query("wait_time") <= 0)
	{
		g_Channel.do_channel(me, NULL, "wiz", "$HIR\n\n\n              不交！！！！\n\n              你们的命都是我的了！！！\n\n\n              一切都给我毁灭吧！！！\n\n\n\n\n              哈哈哈！！！！！！！！！\n\n\n");
		me->command("reboot");
		return;
	}

	char msg[255], tmp[40];

	g_Channel.do_channel(me, NULL, "wiz", snprintf(msg, 255, "$HIR\n\n\n            还有%s分钟！你们交是不交！！！\n\n\n", chinese_number(me->query("wait_time"), tmp)));
	me->add("wait_time", -1);

	me->call_out(do_reboot, 60);
}

NPC_END;