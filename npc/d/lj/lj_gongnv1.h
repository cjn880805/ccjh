//gongnv1.h
//秦波 2002-08-01
#define FIGHTER_BEGIN(npc_name) class npc_name : public CNwiz_fighter	{	public:	npc_name(){};	virtual ~npc_name(){};
#define FIGHTER_END		};	

NPC_BEGIN(CNlj_gongnv1);

virtual void create()
{
	set_name("贴身宫女", "gong nv");
	set("gender", "女性");
	set("icon", 4);
	
	set("title", "西夏皇宫");
	set("age", 15);
	set("attitude", "friendly");

	set("per",29);
	set("no_kill",1);

	set("channel", "f1");
	set("chname", "比武招亲");
	set("grant", 80);
	set("chat_chance", 80);
	set("no_talk",1);
	set("no_kill",1);
};

void init(CChar * me)
{
	CNpc::init(me);
	char msg[255];
	CContainer * r = load_room("灵州皇宫大门");

	if(r->query("start") && r->query("start")==atoi(me->id(1)) && !me->query_temp("lj/renwu116") && EQUALSTR(me->querystr_temp("apply/name"),"竹虚"))
	{
		me->set_temp("lj/renwu116",1);
		message_vision("\n$HIR贴身宫女含笑说道：剩下几位公子，请先以比武决出胜负，胜者再请回答公主的三个问题！",me);
		set("player",atoi(me->id(1)));
		call_out(do_biwu, 10);	
	}
	if(me->query_temp("lj/biwu/win") && me->query_temp("lj/biwu/win") !=3 
		&& !query(snprintf(msg,255,"biwu%d",me->query_temp("lj/biwu/win"))) )
	{
		char msg[255];
		message_vision("\n$HIR贴身宫女说道：恭喜这位公子胜出此局，请公子稍做休息，马上将要开始下一轮比试了！",me);
		set(snprintf(msg,255,"biwu%d",me->query_temp("lj/biwu/win")) ,1);
	}
	if(me->query_temp("lj/biwu/win") ==3)
	{
		//比武胜利
		tell_object(me, "\n$HIR你通过三轮的较量，获得了“西夏皇宫比武招亲”第一名，获得了5000点的经验奖励。\n");
	
		message_vision("$HIR贴身宫女缓缓说道：“公主殿下请众位来到西夏，原是要会见佳客。公主现有三个问题，敬请这位公子回答。",me);
		message_vision("$HIR若是合了公主心意，自当请见。”",me);
		me->add("combat_exp",5000);
		me->UpdateMe();
		del("npc_count");
		del("quiz");
		del("player");
		del("npc");
	}
}


virtual char * chat_msg()
{
	if(query("biwu1")||query("biwu2"))
	{
		CContainer * env=(CChar *)environment();
		if(query("npc_count"))
			del("npc_count");
		DTItemList * list = env->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		while(p) 
		{ 
			CContainer * obj = list->GetNext(p);
			if(! obj->is_character()) continue; 
			CChar * target = (CChar *)obj;  
			if(userp(target))	continue;
			if(DIFFERSTR(target->querystr("name"), "贴身宫女") )
			{
				add("npc_count",1);
			}
		}
		if(query("biwu1") && query("npc_count")>=3)
		{
			del("biwu1");
			call_out(do_biwu, 10);
		}
		if(query("biwu2") && query("npc_count")>=1)
		{
			del("biwu2");
			call_out(do_biwu, 10);
		}
	}
	return 0;
}

static void do_biwu(CContainer * ob, LONG param1, LONG param2)
{
	CNlj_gongnv1 * npc = (CNlj_gongnv1 *)ob;
	CContainer * env=(CChar *)(ob->environment());
	if(npc->query("player"))
	{
		char msg[255];
		CUser * me;
		snprintf(msg,255,"%d",npc->query("player"));
		me=find_online(msg);
		if(me)
		{
			CChar * target1;
			CChar * target2;
			CChar * target3;
			CChar * target4;
			CChar * target5;
			CChar * target6;
			CChar * target7;
			DTItemList * list = env->Get_ItemList();  
			POSITION p = list->GetHeadPosition(); 
			while(p) 
			{ 
				CContainer * obj = list->GetNext(p);
				if(! obj->is_character()) continue; 
				CChar * target = (CChar *)obj;  
				if(userp(target))	continue;
				if(DIFFERSTR(target->querystr("name"), "贴身宫女") )
				{
					switch(npc->query("npc"))
					{
					case 0:
						if(target->query("lj"))
						{
							target1= (CChar *)obj;
							npc->add("npc",1);
						}
						break;
					case 1:
						if(target->query("lj"))
						{
							target2= (CChar *)obj;
							npc->add("npc",1);
						}
						break;
					case 2:
						if(target->query("lj"))
						{
							target3= (CChar *)obj;
							npc->add("npc",1);
						}
						break;
					case 3:
						if(target->query("lj"))
						{
							target4= (CChar *)obj;
							npc->add("npc",1);
						}
						break;
					case 4:
						if(target->query("lj"))
						{
							target5= (CChar *)obj;
							npc->add("npc",1);
						}
						break;
					case 5:
						if(target->query("lj"))
						{
							target6= (CChar *)obj;
							npc->add("npc",1);
						}
						break;
					case 6:
						if(target->query("lj"))
						{
							target7= (CChar *)obj;
							npc->add("npc",1);
						}
						break;
					}
				}
			}
			int man_num=1;
			for(int num=0;num<3-me->query_temp("lj/biwu/win");num++)
			{
				man_num=2*man_num;
			}
			if(npc->query("npc")>=man_num-1)
			{
				npc->del("npc");
				CContainer * oldenv;
				if(me->query_temp("lj/biwu/win")<2)
				{
					message_vision("\n$HIY$N向$n抱拳行了一个礼：既然如此，$n兄，请了。",target2,target3);
					message_vision("$HIY$n笑道：难得有这个机会向$N兄请教，呵呵，请。",target2,target3);
					target2->set_temp("biwu/team", 0l);		
					target3->set_temp("biwu/team", 1);
					CContainer * env_biwu1 = Do_BiShi(target2,target3, "比武招亲", 0);
					npc->set_biwu(env_biwu1);
					oldenv = find_object(npc->query_temp("is_boardcast"));
					if(! oldenv) npc->do_snoop(env_biwu1);
				}
				if(me->query_temp("lj/biwu/win")<1)
				{
					message_vision("\n$HIY$N向$n抱拳行了一个礼：既然如此，$n兄，请了。",target4,target5);
					message_vision("$HIY$n笑道：难得有这个机会向$N兄请教，呵呵，请。",target4,target5);
					target4->set_temp("biwu/team", 0l);		
					target5->set_temp("biwu/team", 1);
					CContainer * env_biwu2 = Do_BiShi(target4,target5, "比武招亲", 0);
					npc->set_biwu(env_biwu2);
					oldenv = find_object(npc->query_temp("is_boardcast"));
					if(! oldenv) npc->do_snoop(env_biwu2);
					
					message_vision("\n$HIY$N向$n抱拳行了一个礼：既然如此，$n兄，请了。",target6,target7);
					message_vision("$HIY$n笑道：难得有这个机会向$N兄请教，呵呵，请。",target6,target7);
					target6->set_temp("biwu/team", 0l);		
					target7->set_temp("biwu/team", 1);
					CContainer * env_biwu3 = Do_BiShi(target6,target7, "比武招亲", 0);
					npc->set_biwu(env_biwu3);
					oldenv = find_object(npc->query_temp("is_boardcast"));
					if(! oldenv) npc->do_snoop(env_biwu3);
				}

				message_vision("\n$HIY$N看见$n笑嘻嘻的望着自己，硬着头皮走了过去，伸手一个抱拳：$n兄，请手下留情。",me,target1);
				me->set_temp("biwu/team", 0l);
				me->set_temp("no_fei",1);
				target1->set_temp("biwu/team", 1);
				CContainer * env_biwu4 = Do_BiShi(me,target1, "比武招亲", 0);
				env_biwu4->set("room_locked", FIGHT_LOCKED);
				npc->set_biwu(env_biwu4);
				oldenv = find_object(npc->query_temp("is_boardcast"));
				if(! oldenv) npc->do_snoop(env_biwu4);
			}
		}
	}
}

void set_biwu(CContainer * ob)
{
	char msg[40];

	snprintf(msg, 40, snprintf(msg, 40, "%ld", ob->object_id()));

	if( m_biwulist.find(msg) == m_biwulist.end() )
		m_biwulist.append(msg);
}

void is_defeated(CChar * winner, CChar * failer)
{
	if(winner == this || failer == this) return;

	//下面是比武得胜者的处理
	winner->add_temp("lj/biwu/win",1);
	winner->delete_temp("biwu");
	if(winner->query("no_fei"))
		winner->delete_temp("no_fei");
	failer->delete_temp("biwu");
	if(failer->query("no_fei"))
		failer->delete_temp("no_fei");

	winner->revive(1);
	failer->revive(1);

	CContainer * env = winner->environment();
	remove_biwu(env);
}

void remove_biwu(CContainer *ob)
{
	char msg[80];
	m_biwulist.remove(snprintf(msg, 40, "%ld", ob->object_id()));
}

void do_snoop(CContainer * env)
{
	const char * ch = querystr("channel");
	if(! ch[0])	return;
		
	env->set("channel_cast", ch);
	env->set("channel_id", querystr("chname"));
	set_temp("is_boardcast", env->object_id());			
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("lj/biwu/win")==3 && !me->query_temp("lj/quiz"))
	{
		say("贴身宫女问道：公主殿下有三个问题请教。", me);
		switch(query("quiz"))
		{
		case 0:
			say("贴身宫女问道：第一问，公子一生之中，在什么地方最是快乐逍遥？", me);
			break;
		case 1:
			say("贴身宫女问道：第二问，公子平生最爱之人，叫什么名字？", me);
			break;
		case 2:
			say("贴身宫女问道：第三问，公子最爱的这个人相貌如何？", me);
			break;
		}
		AddMenuItem("回答", "$2flatter $1 $2", me);
		SendMenu(me);
		return 1;
	}
	
	return CNpc::do_talk(me,ask);
}  

virtual int handle_action(char *comm,CChar *me,char *arg)
{
	if (strcmp(comm,"flatter") == 0)
		return do_flatter(me,arg);

	return 0;
}

int do_flatter(CChar *me,char * arg)
{
	char msg[255];
	if( !strlen(arg)) 
		return notify_fail("你什么？ ");

	if(!query("quiz"))
	{
		message_vision(snprintf(msg,255,"$N轻叹一声，说道：%s", arg), me);
		if(strstr(arg, "在一个黑暗的冰窖之中。"))
		{
			message_vision("\n$HIR忽听得一个女子声音“啊”的一声低呼，跟着呛啷一声响，一只瓷杯掉到地下，打得粉碎。",me);
			set("quiz",1);
			me->set_temp("lj/quiz_y",1);
		} 
		else
		{
			message_vision("\n$HIY那宫女道：“是否中式，婢子不知，由公主殿下决定。",me);
			set("quiz",1);
		}
	}
	else if(query("quiz")==1)
	{
		message_vision(snprintf(msg,255,"$N道：%s", arg), me);
		if(strstr(arg, "唉！我……我不知道那位姑娘叫什么名字。") )
		{
			message_vision("\n$HIR那宫女道：“不知那位姑娘的姓名，那也不是奇事，当年孝子董永见到天上仙女下凡，并不知她的姓名底细，就爱上了她。”",me);
			set("quiz",2);
			me->add_temp("lj/quiz_y",1);
		} 
		else
		{
			message_vision("\n$HIY那宫女道：“是否中式，婢子不知，由公主殿下决定。",me);
			set("quiz",2);
		}
	}
	else if(query("quiz")==2)
	{
		message_vision(snprintf(msg,255,"$N道：%s", arg), me);
		if(strstr(arg, "她容貌如何")
		&& strstr(arg, "这也是从来没看见过") )
		{
			set("quiz",3);
			me->add_temp("lj/quiz_y",1);
			
		} 
		else
		{
			set("quiz",3);
		}
		if(me->query_temp("lj/quiz_y")==3)
		{
			CNpc * yinchuan = load_npc("lj_yinchuan");
			yinchuan->set("owner",me->id(1));
			yinchuan->move(load_room("灵州皇宫青凤阁内堂"));
			message_vision("\n$HIR忽听得一个女子声音低低问：“你……你可是‘梦郎’么？”",me);
			message_vision("\n$HIY你心随念转，想到：刚才只想一意扮好竹虚，因而将竹虚常挂念在嘴边的爱好说了出去。",me);
			message_vision("$HIY没想到，竟然有一位女子叫自己“梦郎”，难道她就是“梦姑”么？！真是踏破铁鞋无觅处，得来全不费功夫。",me);
			message_vision("\n$HIR于是你做大吃一惊状，颤声道：“你……你……你可是‘梦姑’么？这可想死我了。”",me);
			message_vision("$HIR你不自由主的向前跨了几步，只闻到一阵馨香，一只温软柔滑的手掌已握住了你的手。",me);
			message_vision("$HIR一个温柔的声音在他耳边悄声道：“梦郎，我便是找你不到，这才请父皇贴下榜文，邀你到来。",me);
			message_vision("$HIR咱们到里面说话去，梦郎，我日日夜夜，就盼有此时此刻……”",me);
			message_vision("$HIR一面细声低语，一面握着你的手，悄没声的穿过帷幕，踏着厚厚的地毯，走向内堂。\n",me);
			
			me->set_temp("lj/quiz",1);//对话完成
			me->move(load_room("灵州皇宫青凤阁内堂"));
		}
		else
		{
			message_vision("\n$HIY贴身宫女对$N行了个礼：这位公子请稍后，我这就去将您的答案告诉公主。",me);
			message_vision("\n$HIR片刻后，只听内堂中传来一声幽幽的叹息声，似乎是位女子的声音。",me);
			message_vision("\n$HIY过了一会，贴身宫女从内堂走出，对$N行了个礼，满面歉意的说道：",me);
			message_vision("$HIY“这位公子，今天公主身体有些乏了，不能和公子您见面了，特托婢子向公子表示歉意。",me);
			message_vision("$HIY并送公子一些小小的意思，还请公子笑纳。”",me);
			CContainer * RMB=load_item("coin");
			RMB->set_amount(500000);
			RMB->move(me);
			
			message_vision("\n$HIR你失去了招亲资格！",me); 
			message_vision("$HIR你参加比武招亲失败，无缘见得西夏公主，亦无法求证梦姑在宫内何处，长叹之下只有放弃 ！\n\n",me); 
			me->del("lj");
			me->delete_temp("lj");
			me->enable_player();
			CContainer * env = load_room("灵州皇宫大门");
			if(env->query("start"))env->del("start");
			env = load_room("灵州皇宫大厅");
			if(env->query("start"))env->del("start");
			env = load_room("灵州皇宫内书房");
			if(env->query("start"))env->del("start");
			me->move(load_room("灵州皇宫大门"));
		}
		
	}
	return 1;
}


protected:
	CVector		m_biwulist;

NPC_END;

