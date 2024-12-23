//zheng__ma.c 马钰

NPC_BEGIN(CNzheng_ma);

virtual void create()
{
	set_name("马玉", "ma yu");
	set("gender", "男性");
	set("age", 42);
	set("class", "taoist");
	set("nickname","丹阳子");
	set("long","他就是王重阳的大弟子，全真七子之首，丹阳子马玉马真人。他慈眉善目，和蔼可亲，正笑着看着你。");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 28);
	set("foolid",54);
	set("int", 32);
	set("con", 31);
	set("dex", 30);
	set("icon",taoist);
	set_weight(50000000);
	
	set("title","全真七子之首");
	
	set("chat_chance_combat", 60);
	set("hp", 4000);
	set("max_hp", 12000);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 100);
	
	set("combat_exp", 500000);
	set("score", 300000);
	
	set_skill("force", 220);
	set_skill("sword", 220);
	set_skill("dodge", 200);
	set_skill("parry", 220);
	set_skill("unarmed",220);
	set_skill("strike",180);

	set_skill("xiantian_qigong", 220);    //先天气功
	set_skill("quanzhen_jian",220);  //全真剑
	set_skill("jinyan_gong", 200);   //金雁功
	set_skill("haotian_zhang", 220);    //昊天掌

	set_skill("literate",160);
	set_skill("taoism",150);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	prepare_skill("strike", "haotian_zhang");
	
	create_family("全真教", 2, "弟子");
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();

	set("chat_chance_combat", 20);  

	set_inquiry("天罡北斗阵",ask_tiangang);
}

//死亡
void die()
{
	CFightRoom * obj=(CFightRoom *)environment();
	obj->add("zheng/zhengzu",1);
	if(obj->query("zheng/zhengzu")<=6)
	{
		revive(1);
		message_vision("\n$YEL只见全真六子每人递出一掌，另一掌却搭在身旁之人肩上，为首的$N顿时精神大震，双掌向前平堆，一声大吼：开！", this);
		set("max_hp",30000);
		set("eff_hp",30000);
		set("hp",30000);
	}
	else
	{
		message_vision("\n$N含笑道：恭喜你们破了天罡北斗阵！", this);
		DTItemList * list = obj->Get_ItemList();  
//		char msg[255];
		POSITION p = list->GetHeadPosition(); 
		while(p) 
		{ 
			CContainer * obj = list->GetNext(p);
			if(! obj->is_character()) continue; 
			CChar * target = (CChar *)obj;  
			if(is_fighting(target)==0 && !userp(target) && !EQUALSTR(target->querystr("nickname"), "丹阳子"))
			{
//				message_vision(snprintf(msg, 255, "$HIR%s是什么%d？",target->name(1),is_fighting(target)), this);
				destruct(target);
				continue;
			}
		}
		obj->End_Fight();
	}
}

//战斗中
void attack(CChar *me)
{
	CFightRoom * obj=(CFightRoom *)environment();
	int idx;
	CChar * robber;
	static char qiangdao[6][20]={"zheng_hao","zheng_liu","zheng_qiu","zheng_sun","zheng_tan","zheng_wangchuyi"};

	if(obj->query("zheng/count")<3)
	{
		for(idx=random(6)+1;idx<6;idx++)
		{
			robber = load_npc(qiangdao[idx-1]);
			if(idx!=obj->query("zheng/friend1_idx")&& idx!=obj->query("zheng/friend2_idx")&&idx!=obj->query("zheng/friend3_idx"))
			{
				if(obj->query("zheng/friend1_idx")==0)
				{
					obj->set("zheng/friend1_idx",idx);
					obj->set("zheng/friend1_name",robber->name(1));
				}
				else if(obj->query("zheng/friend2_idx")==0)
				{
					obj->set("zheng/friend2_idx",idx);
					obj->set("zheng/friend2_name",robber->name(1));
				}
				else
				{
					obj->set("zheng/friend3_idx",idx);
					obj->set("zheng/friend3_name",robber->name(1));
				}
				robber->move(obj);
				obj->Join_Team(robber,CFightRoom::FIGHT_TEAM_A);
				obj->add("zheng/count",1);
				message_vision("\n$HIW马玉一声长喝：师弟们，变阵型！", this);
				message_vision("阵型顿时一变！\n", this);
				switch(random(9))
				{
				case 0:
					message_vision("$HIR你只见阵型一变，身体不由的靠进了天璇星位，忽起一阵狂风刮来，卷杂着地上树叶，直向你飞来。",this);
					if(random(2))
						message_vision("$YEL你不慌不忙跳到安全的地方。",this);
					else
						message_vision("$HIR你来不及闪避，已经被纵多叶片割伤。",this);
					break;
				case 1:
					message_vision("$HIR阵型一变，你进入了天玑星位，天空远处飞来一颗流星，直向你冲来。",this);
					if(random(2))
						message_vision("$YEL只见你深深吸了一口气，发出一声惊天动地的巨吼, 流星给你震的粉碎了。",this);
					else
						message_vision("$HIR刹那间，流星由一颗变成了无数颗，击中在你的身上。",this);
					break;
				case 2:
					message_vision("$HIR你的眼前一花，天权星位转到你的面前，空中传来数声雷响，声浪一浪接一浪，直向你涌来。",this);
					if(random(2))
						message_vision("$YEL你运起神功，真气游遍全身，轻易避开了声浪。",this);
					else
						message_vision("$HIR只见你被声浪打个措手不及，口喷鲜血。",this);
					break;
				case 3:
					message_vision("$HIR你直接朝玉衡星位攻去，但你眼前电光四起，刹时间，啥也看不见了。",this);
					if(random(2))
						message_vision("$YEL你双手紧按太阳穴，终于看到了周围的情景。",this);
					else
						message_vision("$HIR只听你大声一叫，双眼流出了鲜血。",this);
					break;
				case 4:
					message_vision("$HIR突然下起冰雹，阵法一转你直接面对了天权星位，一瞬间，无数冰雹直向你飞来。",this);
					if(random(2))
						message_vision("$YEL只见你一招天外飞仙直向冰雹劈去，将冰雹劈碎。",this);
					else
						message_vision("$HIR可你毫无防备，被击出数丈外。",this);
					break;
				case 5:
					message_vision("$HIR你进入了开阳星位，地上冒起了八个石像，把你团团围住。",this);
					if(random(2))
						message_vision("$YEL只见你攻向后方的石像，瞬间八个石像消失的无影踪，原来是幻觉。",this);
					else
						message_vision("$HIR忽见后方的石像砸向你的天灵盖，你觉得头晕脑涨，跌倒在地。",this);
					break;
				case 6:
					message_vision("$HIR你身体一闪，逼近了瑶光星位，地上的杂草突然变长变粗，死死地把你缠住。",this);
					if(random(2))
						message_vision("$YEL你使出了一招金蝉脱壳，摆脱了杂草的缠绕。",this);
					else
						message_vision("$HIR你不留神已被杂草缠得喘不过气来，元气大伤。",this);
					break;
				case 7:
					message_vision("$HIR你进入了天枢星位，忽见空中数个火球朝你飞过来。",this);
					if(random(2))
						message_vision("$YEL你不慌不忙运起了神功，只见你身旁形成一个很大的防护罩，火球对你毫无无影响。",this);
					else
						message_vision("$HIR你向旁边一跃企图躲过火球，哪知旁边也有火球，你被火球撞个正着。",this);
					break;
				case 8:
					message_vision("$HIR忽然眼前模糊不清，原来进入了天枢星位，遍地都是沼泽地。",this);
					if(random(2))
						message_vision("$YEL只见你轻盈的跳了几下，跳出了沼泽地到了安全地方。",this);
					else
						message_vision("$HIR你一不小心踏进沼泽，很快的陷了下去，你捉住旁边的树支好不容易才脱离了沼泽地。",this);
					break;
				}
				break;
			}
		}
	}
}

static char * ask_tiangang(CNpc *me,CChar *who)
{
	CContainer * env = (CChar *)me->environment();
	CChar * robber;
	CFightRoom * obj;

	message_vision("$HIR师弟们，布天罡北斗大阵！", me,who);

	obj = (CFightRoom *)env->present("fight_room_tiangang");
	if(! obj)
	{
		obj = (CFightRoom *)load_item("fight_room");		
	
		obj->set("room_locked", FIGHT_NO_JOIN);
		obj->set_name( "天罡北斗阵", "fight_room_tiangang");
		obj->set("zheng/count",3);
		obj->move(env);

		static char qiangdao[6][20]={"zheng_hao","zheng_liu","zheng_qiu","zheng_sun","zheng_tan","zheng_wangchuyi"};
		me->move(obj);
		obj->Join_Team(me, CFightRoom::FIGHT_TEAM_A);
		for(int i=0;i<3;i++)
		{
			robber = load_npc(qiangdao[i]);
			robber->move(obj);
			switch(i)
			{
			case 0:
				obj->set("zheng/friend1_idx",i+1);
				obj->set("zheng/friend1_name",robber->name(1));
				break;
			case 1:
				obj->set("zheng/friend2_idx",i+1);
				obj->set("zheng/friend2_name",robber->name(1));
				break;
			case 2:
				obj->set("zheng/friend3_idx",i+1);
				obj->set("zheng/friend3_name",robber->name(1));
				break;
			}
			obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);	
		}
	}
	if(who) 
	{
		who->move(obj);
		obj->Join_Team(who, CFightRoom::FIGHT_TEAM_B);
		obj->Begin_Fight(0);
	}
	else
		return "";
	return "";
}

//战斗中的信息
virtual char * chat_msg_combat()
{
	char msg[255];
	CFightRoom * obj=(CFightRoom *)environment();
	CChar * me = NULL;
	CChar * who = NULL;
	CChar * robber;
	int idx;
	static char qiangdao[6][20]={"zheng_hao","zheng_liu","zheng_qiu","zheng_sun","zheng_tan","zheng_wangchuyi"};

	if(environment()->Query(IS_FIGHTROOM))
	{
		me = obj->Select_Member(1 - query_team());
		who = obj->Select_Member(query_team());
	}

	if(! me) return 0;
	if(! who) return 0;
	switch(random(4))
	{
	case 0:
	case 1:
	case 2:
		message_vision(snprintf(msg, 255, "\n$HIW$N一声长喝：师弟们，变阵型！",me->name(1)), this);
		message_vision("人影穿梭中，眼前的阵型顿时一变！\n", this);
		switch(random(9))
		{
		case 0:
			message_vision("$HIR你只见阵型一变，身体不由的靠进了天璇星位，忽起一阵狂风刮来，卷杂着地上树叶，直向你飞来。",this);
			if(random(2))
				message_vision("$YEL你不慌不忙跳到安全的地方.",this);
			else
				message_vision("$HIR你来不及闪避，已经被纵多叶片割伤。",this);
			break;
		case 1:
			message_vision("$HIR阵型一变，你进入了天玑星位，天空远处飞来一颗流星，直向你冲来。",this);
			if(random(2))
				message_vision("$HIR只见你深深吸了一口气，发出一声惊天动地的巨吼, 流星给你震的粉碎了。",this);
			else
				message_vision("$HIR刹那间，流星由一颗变成了无数颗，击中在你的身上。",this);
			break;
		case 2:
			message_vision("$HIR你的眼前一花，天权星位转到你的面前，空中传来数声雷响，声浪一浪接一浪，直向你涌来。",this);
			if(random(2))
				message_vision("$YEL你运起神功，真气游遍全身，轻易避开了声浪。",this);
			else
				message_vision("$HIR只见你被声浪打个措手不及，口喷鲜血。",this);
			break;			
		case 3:
			message_vision("$HIR你直接朝玉衡星位攻去，但你眼前电光四起，刹时间，啥也看不见了。",this);
			if(random(2))
				message_vision("$YEL你双手紧按太阳穴，终于看到了周围的情景。",this);
			else
				message_vision("$HIR只听你大声一叫，双眼流出了鲜血。",this);
			break;
		case 4:
			message_vision("$HIR突然下起冰雹，阵法一转你直接面对了天权星位，一瞬间，无数冰雹直向你飞来。",this);
			if(random(2))
				message_vision("$YEL只见你一招天外飞仙直向冰雹劈去，将冰雹劈碎。",this);
			else
				message_vision("$HIR可你毫无防备，被击出数丈外。",this);
			break;
		case 5:
			message_vision("$HIR你进入了开阳星位，地上冒起了八个石像，把你团团围住。",this);
			if(random(2))
				message_vision("$YEL只见你攻向后方的石像，瞬间八个石像消失的无影踪，原来是幻觉。",this);
			else
				message_vision("$HIR忽见后方的石像砸向你的天灵盖，你觉得头晕脑涨，跌倒在地。",this);
			break;
		case 6:
			message_vision("$HIR你身体一闪，逼近了瑶光星位，地上的杂草突然变长变粗，死死地把你缠住。",this);
			if(random(2))
				message_vision("$YEL你使出了一招金蝉脱壳，摆脱了杂草的缠绕。",this);
			else
				message_vision("$HIR你不留神已被杂草缠得喘不过气来，元气大伤。",this);
			break;
		case 7:
			message_vision("$HIR你进入了天枢星位，忽见空中数个火球朝你飞过来。",this);
			if(random(2))
				message_vision("$YEL你不慌不忙运起了神功，只见你身旁形成一个很大的防护罩，火球对你毫无无影响。",this);
			else
				message_vision("$HIR你向旁边一跃企图躲过火球，哪知旁边也有火球，你被火球撞个正着。",this);
			break;
		case 8:
			message_vision("$HIR忽然眼前模糊不清，原来进入了天枢星位，遍地都是沼泽地。",this);
			if(random(2))
				message_vision("$YEL只见你轻盈的跳了几下，跳出了沼泽地到了安全地方。",this);
			else
				message_vision("$HIR你一不小心踏进沼泽，很快的陷了下去，你捉住旁边的树支好不容易才脱离了沼泽地。",this);
			break;
		}
		break;
	case 3:
		if(EQUALSTR(who->querystr("nickname"), "丹阳子"))
			message_vision(snprintf(msg, 255, "\n$HIW%s乘这空隙，站定“天枢”之位挥掌发招，接着谭刘诸人也各占定方位。",who->name(1)), this);
		else
		{
			message_vision(snprintf(msg, 255, "$HIR$N急呼：%s师弟，不要贪攻，速退回你的阵位。",who->name(1)), this);
	
			for(idx=random(6)+1;idx<6;idx++)
			{
				if(idx!=obj->query("zheng/friend1_idx")&& idx!=obj->query("zheng/friend2_idx")&&idx!=obj->query("zheng/friend3_idx"))
				{
					if(EQUALSTR(obj->querystr("zheng/friend1_name"), who->name(1)))
					{
						destruct(who);
						robber = load_npc(qiangdao[idx-1]);
						obj->set("zheng/friend1_idx",idx);
						obj->set("zheng/friend1_name",robber->name(1));
					}
					else if(EQUALSTR(obj->querystr("zheng/friend2_name"), who->name(1)))
					{
						destruct(who);
						robber = load_npc(qiangdao[idx-1]);
						obj->set("zheng/friend2_idx",idx);
						obj->set("zheng/friend2_name",robber->name(1));
					}
					else
					{
						destruct(who);
						robber = load_npc(qiangdao[idx-1]);
						obj->set("zheng/friend3_idx",idx);
						obj->set("zheng/friend3_name",robber->name(1));
					}
					robber->move(obj);
					message_vision(snprintf(msg, 255, "$HIR$N转身向%s说道：师弟，你来压住阵脚。",robber->name(1)), this);
					obj->Join_Team(robber,CFightRoom::FIGHT_TEAM_A);
					break;
				}
			}
		}
		break;
	}
	return 0;
}

NPC_END;




