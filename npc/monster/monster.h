#define MONSTER_BEGIN(npc_name)	class npc_name : public CNmonster	{	public:	npc_name(){};	virtual ~npc_name(){};
#define MONSTER_END		};	

NPC_BEGIN(CNmonster);

void die()
{
	CChar * killer = (CChar *)find_object(query_temp("last_damage_from"), 1);

	CContainer * baowu = generate_baowu();
	if(baowu) baowu->move(environment());		

	if(killer)
	{
		reward_exp(killer);	
	}

	message_vision("$N化作一股轻烟消失了。", this);
	DESTRUCT_OB(this, "monster::die");
}

void reward_exp(CChar * me)
{
	g_Combatd.Killer_Reward(me, this);
}

char * chat_msg()
{
	//检查是否该逃走了。
	if(random(10))
	{
		//检查场景内是否有玩家
		DTItemList search;

		CopyList(&search, environment()->Get_ItemList());

		POSITION p;
		p = search.GetHeadPosition();
		while(p)
		{
			char msg[40];
			CContainer * obj = search.GetNext(p);
			if(userp(obj))
			{
				if(! random(5) 
					&& query("level") > obj->query_temp("apply/protect")
					&& command(snprintf(msg, 40, "kill %ld", obj->object_id())))
					return 0;
			}
			else if(obj->Query(CAN_GET) && ! random(3) && !obj->query("lost"))
			{
				message_vision("$N慌慌张张的拾起$n。", this, obj);
				DESTRUCT_OB(obj, "monster::chat_msg");
				return 0;
			}
		}
		
		return 0;
	}

	message_vision("$N左右看看，然后纵身一跃，跳入草丛消失了！", this);
	DESTRUCT_OB(this, "monster::chat_msg");
	return 0;
}

CContainer * generate_baowu()
{
	CContainer * baowu = NULL;
	int level = query("monster_lvl");

	//产生随机宝物
	switch(random(30))
	{
	case 0:
	case 1:
		if(level > 10)
		{
			if(! random(3))
				baowu = load_item("blade_2");
			else if(! random(2))
				baowu = load_item("blade_1");			
		}
		
		if(! baowu)
		{
			if(! random(10))
			{
				static char baowu_1[3][20] = {
					"shenghuo_ling",
					"zijin_staff",
					"plumsword",
				};

				baowu = load_item(baowu_1[random(3)]);
			}
			else
				baowu = load_item("yuchandan");
		}

		break;

	case 2:
	case 3:
		if(! random(2))
			baowu = load_item("readingbot");
		else if(! random(2))
			baowu = load_item("practicebot");
		else if(! random(2))
			baowu = load_item("exercisebot");

		break;
	
	case 4:
		baowu = load_item("coin");
		baowu->set_amount(50 + random(100));
		break;
	case 5:
		//随机物品
		if(! random(15) && query("monster_lvl") >= 5)
		{
			static char item[19][20] = {				
				"dodgebook",
				"strike_book",
				"quanpu",
				"book_silk",
				"zhangfapu",
				"musicbook1",
				"musicbook2",
				"parry_book",
				"hand_book",
				"sword_book1",
				"sword_book2",
				"force_book",
				"book2",
				"staff_book",
				"kao_book",
				"wumu_book1",
				"club_book",
				"kill_hammer_book",
				"hammer_book",
			};

			baowu = load_item(item[random(14)]);
			break;
		}

	case 6:
	case 7:
		//随机书本
		if(! random(10) && query("monster_lvl") >= 10 )	//10 级以上的怪物才有书
		{
			static char book[140][20] = {
				"yicai_book1",
				"yicai_book2",
				"18niou", 
				"bagua0",
				"zhengqi_book", 
				"zhengqi_book", 
				"zhengqi_book", 
				"zhengqi_book", 
				"zhengqi_book", 
				"zhengqi_book", 				
				"zhangfapu",
				"yunvjing1",
				"yunvjing2",
				"yunv_swordb",
				"yijinjing",
				"yijing3",
				"yijing2",
				"yijing1",
				"yijing0",
				"xuanfeng_book",
				"xisuijing",
				"musicbook1",
				"musicbook2",
				"wuji3",
				"wuji2",
				"wuji1",
				"wuji3",
				"wuji2",
				"wuji1",
				"wuji3",
				"wuji2",
				"wuji1",
				"wuji3",
				"wuji2",
				"wuji1",
				"wuji3",
				"wuji2",
				"wuji1",
				"wuji3",
				"wuji2",
				"wuji1",
				"throw_book",
				"sword_book2",
				"sun_book",
				"strike_book",
				"staff_book",
				"shoufa",
				"quanpu",
				"quanpu",
				"quanpu",
				"qinpu",
				"qijianpu",
				"skin",
				"parry_book",
				"mizong_book",
				"liuyang_book2",
				"liuyang_book1",
				"six_book",
				"literateb4",
				"lbook3",
				"lbook2",
				"lbook1",
				"laozi8",
				"laozi2",
				"laozi18",
				"laozi16",
				"laozi13",
				"laozi1",
				"kuihua",
				"jiuyin1",
				"jiuyin2",
				"jiuyang4",
				"jiuyang3",
				"jiuyang2",
				"jiuyang1",
				"jinyantu",
				"jinshe3",
				"jinshe2",
				"jinshe1",
				"hand_book",
				"force_book",
				"dujing_2",
				"dujing_1",
				"dodgebook",
				"daodejing_ii",
				"daodejing_i",
				"daodejing",
				"book2",
				"book_stone",
				"book_silk",
				"book_paper",
				"book_iron",
				"book2",
				"book_stone",
				"book_silk",
				"book_paper",
				"book_iron",
				"book2",
				"book_stone",
				"book_silk",
				"book_paper",
				"book_iron",
				"book2",
				"book_stone",
				"book_silk",
				"book_paper",
				"book_iron",
				"book2",
				"book_stone",
				"book_silk",
				"book_paper",
				"book_iron",
				"book2",
				"book_stone",
				"book_silk",
				"book_paper",
				"book_iron",
				"bojuan",
				"blade_book",
				"bagua",
				"bagua0",
				"zhifapu",
				"bufa",
				"chanhe_book1",
				"chanhe_book2",
				"chanhe_book3",
				"chanhe_book4",
				"jixiao_book1",
				"jixiao_book2",
				"jixiao_book3",
				"jixiao_book4",
				"hejianjing",
				"tangshoumichuan",
				"miaoshou",
				"miaoshou",
				"miaoshou",
				"miaoshou",
				"miaoshou",
				"miaoshou",
				"miaoshou",
			};

			baowu = load_item(book[random(140)]);
			break;
		}

	case 8:
		if(! random(3))
			baowu = load_item("transfer_tie");
		break;

	case 9:
		{
			if(level > 3)
			{
				level = random(level) + 1;
				baowu = load_item("hushenfu");
				baowu->create(level);
			}
		}
		break;
	case 10:
		if(random(level) > 3 && random(100)>80)
		{
			baowu = load_item("shangshan_tie");
		}
		break;
	case 11:
	case 12:
		baowu = load_item("yaopin_1");
		break;
	case 13:
	case 14:
		baowu = load_item("yaopin_2");
		break;
	case 15:
		baowu = load_item("armor_1");
		break;
	case 16:
		baowu = load_item("sword_2");
		break;
	case 17:
		if(random(level) > 3)
		{
			baowu = load_item("sword_3");
		}
		break;
	case 18:
		baowu = load_item("yueping");
		break;
	case 19:
		baowu = load_item("fengyin");
		break;
	}
	
	return baowu;
}

NPC_END;