NPC_BEGIN(CNwiz_skill);

virtual void create()
{
	set_name("技能检查官","jineng ");

	set("icon", young_man6);
	set("gender", "男性" );
	set("age", 19);
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 21);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
	
	set("max_hp", 1200);
	set("mp", 100);
	set("max_mp", 100);
	set("combat_exp", 30000+random(10000));
	set("score", 10000);

	set("no_kill",1);//不被列入万劫谷的任务中

};

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(wizardp(me)&& !me->query_temp("skill/kill"))
	{
		me->set_temp("skill/kill",1);
		call_out(do_skill, 1);	
	}
	return 1;
}

static void do_skill(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	CContainer * env=npc->environment();
	CUser * targetx;
	char msg[255];

	for(int i=env->query("count_start");i<env->query("count_start")+500;i++)
	{
		if(i>=100 && i <=110 || i==203) continue;
		targetx=find_online(snprintf(msg,255,"%d",i));
		if (!targetx)
		{
			targetx = add_user();
			targetx->set("id", snprintf(msg,255,"%d",i));
			targetx->LoadFromServer();
		}
		if(targetx->query_skill("buddhism",1)>281)
		{
			if(targetx->query_skill("buddhism",1)>300)
			{
				tell_room(env,snprintf(msg,255,"set(“%d/buddhism”，300); ",i));
			}
			else
			{
				tell_room(env,snprintf(msg,255,"set(“%d/buddhism”，%d);",i,targetx->query_skill("buddhism",1)));
			}
		}
		if(targetx->query_skill("bahuang_gong",1)>300 && targetx->query("pro/skill/bahuang_gong"))
		{
			int lvl=300+targetx->query("pro/skill/bahuang_gong");
			if(targetx->query_skill("bahuang_gong",1)>lvl)
			{
				tell_room(env,snprintf(msg,255,"set(“%d/bahuang_gong”，%d);",i,lvl));
			}
			else
			{
				tell_room(env,snprintf(msg,255,"set(“%d/bahuang_gong”，%d); ",i,targetx->query_skill("bahuang_gong",1)));
			}
		}
		if(targetx->query_skill("jinyan_gong",1)>240)
		{
			if(targetx->query_skill("jinyan_gong",1)>415)
			{
				tell_room(env,snprintf(msg,255,"set(“%d/jinyan_gong”，415); ",i));
			}
			else
			{
				tell_room(env,snprintf(msg,255,"set(“%d/jinyan_gong”，%d) ;",i,targetx->query_skill("jinyan_gong",1)));
			}
		}
		
		destruct(targetx);
	}
	env->add("count_start",500);
	npc->call_out(do_skill, 1);	
}

NPC_END;




