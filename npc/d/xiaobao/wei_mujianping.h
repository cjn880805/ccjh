// wei_mujianping.h 沐剑屏
// 秦波	2002、12、25

NPC_BEGIN(CNwei_mujianping);

virtual void create()
{
	set_name("沐剑屏","mujian ping");
	set("title","沐王府小郡主");
	set("icon", young_woman3);
	set("long",  "她长的很美，可是看起来带着淡淡的一点忧伤。");
	set("age", 17);
	set("per",32);
	
	set("gender","女性");
	
	set("str", 25);
	set("dex", 16);
	set("combat_exp", 80000);
	
	set("hp",30000);
	set("eff_hp",30000);
	set("max_hp",30000);
	
	set("max_mp",300);
	set("mp",300);
	
	call_out(do_die, 900);
	set("no_kill",1);
	set("no_huan",1);
}

void init(CChar * me)
{
	CNpc::init(me);
	if(!query("ok") && me->query_temp("wei/renwu5_8") && EQUALSTR(environment()->querystr("base_name"),"杭州忘情阁" )
		&& !me->query_temp("wei/renwu5_16") )
	{
		tell_object(me,"\n$YEL沐剑萍自言自语道：“用了这么多药，怎么还是练不成，唉，我还缺什么呢！”\n");
	}
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(!querystr("owner")[0] && !query("ok"))
	{
		CContainer * mianjue=me->present("mian ju");
		if(mianjue && EQUALSTR(me->querystr_temp("apply/name"),"江湖郎中"))
		{
			if(me->query_temp("wei/renwu5_17"))
			{
				if(! strlen(ask))
				{
					AddMenuItem("询问关于小宝","xiaobao",me);
					SendMenu(me);
				}
				else if(!strcmp(ask, "xiaobao") )
				{
					me->set_temp("wei/renwu5_18",1);//沐剑萍可以回家了
					tell_object(me,"\n$HIC沐剑萍一把扯下了你脸上的鱼皮面具。");
					tell_object(me,"$HIC沐剑萍看着你陌生的脸，愣了一下！");
					tell_object(me,"$HIC沐剑萍“哇！”地一声，吐出一大口鲜血，摔倒在地，昏了过去！");
					
					//销毁面具
					destruct(mianjue);
					me->delete_temp("apply/name");
					//me->delete_temp("apply/id");
					me->delete_temp("apply/icon");
					me->delete_temp("apply/short");
					me->delete_temp("apply/long");
					me->delete_temp("apply/title");
					me->UpdateMe();
					
					CChar * wei = load_npc("wei_mujianping");
					wei->move(environment());
					wei->set("owner",me->id(1));
					wei->disable_player("昏迷中");
					destruct(this);
				}
				return 1;
			}
		}
	}
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(!querystr("owner")[0] && !query("ok"))
	{
		if(me->query("wei/renwu1") && !me->query("wei/renwu5"))
		{
			CContainer * mianjue=me->present("mian ju");
			if(mianjue && EQUALSTR(me->querystr_temp("apply/name"),"江湖郎中"))
			{
				if(EQUALSTR(ob->querystr("name"), "断肠花") && EQUALSTR(ob->querystr("id"), "duanchang") 
					&& me->query_temp("wei/renwu5_10"))
				{
					me->set_temp("wei/renwu5_14",1);//收到断肠花
					destruct(ob);
					return 1;
				}
				else if(EQUALSTR(ob->querystr("name"), "牛皮酒袋") && EQUALSTR(ob->querystr("owner1"), me->id(1)) 
					&& me->query_temp("wei/renwu5_12"))
				{
					me->set_temp("wei/renwu5_15",1);//收到天池之水
					destruct(ob);
					return 1;
				}
				if(me->query_temp("wei/renwu5_14") && me->query_temp("wei/renwu5_15"))
				{
					tell_object(me,"\n$HIC沐剑萍将断肠花其他一些不知名的药材一起放进一个药罐中，和了些小天池之水，放到火炉上细细地煨了起来。");
					tell_object(me,"$HIC一旁的江湖郎中说道：“大概熬上一刻钟就可以了！”\n");
					me->set_temp("wei/renwu5_16",1);//开始熬制忘情散，需要等待15分钟
					set("owner",me->id(1));
					call_out(do_jiagong, 360);
				}
			}
		}
	}
	return 0;
}

static void do_jiagong(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->querystr("owner")[0])
	{
		CContainer * me;
		CContainer * env=npc->environment();
		me=env->present(npc->querystr("owner"));
		if(me)
		{
			tell_object(me,"\n$HIC沐剑萍将熬好的药汁倒入一个小碗内，一边流泪，一边一口一口的咽了下去！");
			tell_object(me,"$HIC沐剑萍神色突然恍忽起来！\n");
			me->set_temp("wei/renwu5_17",1);//喝过忘情散
		}
		npc->del("owner");
	}
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->query("ok"))
		destruct(npc);
	else
		npc->call_out(do_die, 900);
}

NPC_END;