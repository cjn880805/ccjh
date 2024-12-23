//gongnv.h
//秦波 2002-08-01

NPC_BEGIN(CNlj_gongnv);

virtual void create()
{
	set_name("宫女", "gong nv");
	set("gender", "女性");
	set("icon", 4);
	
	set("title", "西夏皇宫");
	set("age", 15);
	set("attitude", "friendly");

	set("per",23);
	set("no_kill",1);
	
};

void init(CChar * me)
{
	CNpc::init(me);
	CContainer * r = load_room("灵州皇宫大门");

	if(r->query("start") && r->query("start")==atoi(me->id(1)) && !me->query_temp("lj/renwu114"))
	{
		message_vision("\n$HIR$N一进书房，只见书房两侧挂着诸多名家真迹的画册。",me);
		message_vision("$HIR青年周不通不识画册珍贵竟然探手将画册取下玩耍，诸人突然发现画册所掩盖的石壁上竟然刻着诸多武功典籍，端得是无比珍贵，奥妙无穷。",me);
		message_vision("$HIR大喜之下众人竟忘了此行的目的，将画册一一撕下，开始参悟石壁上的武功。",me);
		message_vision("\n$HIR$N也忍不住好奇，也凑了过去，仔细观看着石壁上的图画。。。",me);
		me->set_temp("lj/renwu114",1);
		me->disable_player("参悟中");
		set("player",atoi(me->id(1)));
		call_out(do_shibi, 10);	
	}
}

static void do_shibi(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	CContainer * env=(CChar *)(ob->environment());
	DTItemList * list = env->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		CChar * target = (CChar *)obj;  
		if(userp(target))	continue;
		if(DIFFERSTR(target->querystr("name"), "宫女") )
		{
			if(EQUALSTR(target->querystr("name"), "狗杂种")|| EQUALSTR(target->querystr("name"), "胡飞")||
				EQUALSTR(target->querystr("name"), "苗人凰")|| EQUALSTR(target->querystr("name"), "狄雨")||
				EQUALSTR(target->querystr("name"), "袁成志"))
			{
				message_vision("\n$N研究武功走火入魔，暂时昏迷，失去了比武招亲的资格。", target);
				message_vision("$HIR书房内的几个太监走了过来，小心翼翼的将$N搀扶到书房旁的卧室中。", target);
				//target->move(load_room("灵州皇宫内书房卧室"));
				destruct(target);
			}
		}
	}
	if(npc->query("player"))
	{
		char msg[255];
		CUser * me;
		snprintf(msg,255,"%d",npc->query("player"));
		me=find_online(msg);
		if(me)
		{
			me->add("combat_exp",5000);
			me->UpdateMe();
			message_vision("\n$HIR$N看的兴起，似乎有点心得。。。",me);
		}
	}
	npc->call_out(do_shibi1, 10);	
}

static void do_shibi1(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	CContainer * env;
	if(npc->query("player"))
	{
		char msg[255];
		CUser * me;
		snprintf(msg,255,"%d",npc->query("player"));
		me=find_online(msg);
		if(me)
		{
			if(EQUALSTR(me->querystr("gender"), "女性") )
			{
				if(DIFFERSTR(me->querystr_temp("apply/name"),"竹虚"))
				{
					message_vision("$HIR皇宫卫士伸手拦住了你，“姑娘，你是女人，何必来参加比武招亲呢？！”", me);
				}
				else if(!me->query_temp("lj/renwu111"))
				{
					message_vision("$HIR皇宫卫士伸手拦住了你，“姑娘，你的易容术未免有点浅薄了……”", me);
				}
				else
				{
					int lvl=me->query_skill("force",1);
					int jump;
					if(lvl>=300)
						jump=1;
					else if(lvl>=200 )
					{
						if(random(100)>20)	jump=1;
					}
					else if(lvl>=100 )
					{
						if(random(100)>30)	jump=1;
					}
					else if(lvl>=50 )
					{
						if(random(100)>50)	jump=1;
					}
					if(jump==1)
					{
						message_vision( "\n$HIR你看着墙上凹凹凸凸，千奇百怪的图形，隐约觉得这是一门高深的武学。但一想起此行的目的，你强行将目光从石壁上移开。",me); 
						npc->call_out(do_shibi2, 10);
					}
					else
					{
						message_vision("\n$HIR你看着墙上凹凹凸凸，千奇百怪的图形，突然感觉头痛欲裂，恶心异常，身躯缓缓软倒在地。 ",me); 
						message_vision("$HIR你失去了招亲资格！",me); 
						message_vision("\n$HIR你参加比武招亲失败，无缘见得西夏公主，亦无法求证梦姑在宫内何处，长叹之下只有放弃 ！\n\n",me); 
						me->del("lj");
						me->delete_temp("lj");
						me->enable_player();
						env = load_room("灵州皇宫大门");
						if(env->query("start"))env->del("start");
						env = load_room("灵州皇宫大厅");
						if(env->query("start"))env->del("start");
						me->move(load_room("灵州皇宫大门"));
					}
				}
			}
			else
				message_vision("$HIR我昏！你是怎么混到这里来的呢？有人出老千呀！",me);
		}
	}
}

static void do_shibi2(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->query("player"))
	{
		char msg[255];
		CUser * me;
		snprintf(msg,255,"%d",npc->query("player"));
		me=find_online(msg);
		if(me)
		{
			CContainer * env=me->environment();
			me->enable_player();
			message_vision("\n$HIR宫女笑着对在场的人说道：“恭喜各位公子顺利通过了前两关的考验！”。",me);
			message_vision("$HIR说罢，伸手揭开书房南侧的一席卷帘，说道：“请各位公子移步青凤阁，稍做休息后再进行下一轮的比试”。",me);
			DTItemList * list = env->Get_ItemList();  
			POSITION p = list->GetHeadPosition(); 
			while(p) 
			{ 
				CContainer * obj = list->GetNext(p);
				if(! obj->is_character()) continue; 
				CChar * target = (CChar *)obj;  
				if(userp(target))	continue;
				if(DIFFERSTR(target->querystr("name"), "宫女") )
				{
					target->set("lj",1);
					target->move(load_room("灵州皇宫青凤阁"));
				}
			}
			env->set("start",1);
			me->add("combat_exp",5000);
			me->UpdateMe();
			tell_object(me, "\n$HIR你通过了“西夏皇宫比武招亲中内功项目”的考验，获得了5000点的经验奖励。\n");
			npc->del("player");
		}
	}
}

NPC_END;

