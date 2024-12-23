//randomnpc.h  随机事件NPC
//秦波 2002、6、17

NPC_BEGIN(CNrandomnpc);

typedef struct{
	int	search_id;
	int has_search;
	string enter_door;		
}path_t;

typedef map<string, path_t *, less<string> > MAP2PATH;
typedef MAP2PATH::iterator iterator_path;

MAP2PATH m_search;

virtual void create()
{
	set_name( "采花大盗", "caihua dao");
	
	set("max_hp", 150000+random(20000));
	set("hp",150000+random(20000));
	set("max_mp", 20000);
	set("mp",20000);
	set("mp_factor", 160);
	set("combat_exp", 10000000+random(5000000));
	set("no_duo",1);
	set("mp",20000);
	set("gender", "男性");
	set("age", 30+random(80));
	set("str",35);
	set("dex",35);
	set("int",35);
	set("con",35);
	set_weight(50000000);
			
	set("chat_chance", 30);
	set("chat_chance_combat", 30);
	reset();
};

void reset()
{
	switch(random(16))
	{
	case 1:
		set_skill("force", 200+random(150));
		set_skill("taiji_shengong", 200+random(150));
		set_skill("dodge", 200+random(150));
		set_skill("tiyunzong", 200+random(150));
		set_skill("unarmed", 200+random(150));
		set_skill("taiji_quan", 200+random(150));
		set_skill("parry", 200+random(150));
		set_skill("sword", 200+random(150));
		set_skill("taiji_jian", 200+random(150));
		set_skill("blade", 200+random(150));
		set_skill("taiji_dao", 200+random(150));
		set_skill("taoism", 200+random(150));
		set_skill("literate", 200+random(150));
		
		map_skill("force", "taiji_shengong");
		map_skill("dodge", "tiyunzong");
		map_skill("unarmed", "taiji_quan");
		map_skill("parry", "taiji_jian");
		map_skill("sword", "taiji_jian");
		map_skill("blade", "taiji_dao");
		break;
	case 2:
		set_skill("force", 200+random(150));
		set_skill("dodge", 200+random(150));
		set_skill("parry", 200+random(150));
		set_skill("cuff", 200+random(150));
		set_skill("strike", 200+random(150));
		set_skill("sword", 200+random(150));
		set_skill("staff", 200+random(150));
		set_skill("finger", 200+random(150));
		set_skill("kurong_changong", 200+random(150));
		set_skill("tiannan_step", 200+random(150));
		set_skill("jinyu_quan", 200+random(150));
		set_skill("wuluo_zhang", 200+random(150));
		set_skill("duanjia_sword", 200+random(150));
		set_skill("sun_finger", 200+random(150));
		set_skill("lm_shangyang", 200+random(150));	
		set_skill("literate", 200+random(150));
		
		map_skill("force", "kurong_changong");
		map_skill("dodge", "tiannan_step");
		map_skill("finger", "sun_finger");
		map_skill("cuff", "jinyu_quan");
		map_skill("strike", "wuluo_zhang");
		map_skill("parry", "sun_finger");
		map_skill("sword", "duanjia_sword");
		map_skill("staff", "duanjia_sword");
		
		prepare_skill("cuff", "jinyu_quan");
		prepare_skill("strike", "wuluo_zhang");
		carry_object("sword_2")->wield();
		break;
	case 3:
		set_skill("force", 200+random(150));
		set_skill("dodge", 200+random(150));
		set_skill("parry", 200+random(150));
		set_skill("claw",200+random(150));
		
		set_skill("wuwen_zhua",200+random(150));
		set_skill("guimei_shenfa",200+random(150));
		set_skill("wudu_shengong", 200+random(150));
		set_skill("tangshoudao", 200+random(150));
		
		map_skill("force", "wudu_shengong");
		map_skill("dodge", "guimei_shenfa");
		map_skill("parry", "tangshoudao");
		map_skill("claw", "wuwen_zhua");
		prepare_skill("claw", "wuwen_zhua");

		break;
	case 4:
		set_skill("persuading", 200+random(150));
		set_skill("force", 200+random(150));
		set_skill("unarmed", 200+random(150));
		set_skill("dodge", 200+random(150));
		set_skill("parry", 200+random(150));
		set_skill("hand",200+random(150));
		set_skill("staff", 200+random(150));
		set_skill("hamagong", 200+random(150));
		set_skill("chanchu_bufa", 200+random(150));
		set_skill("shexing_diaoshou", 200+random(150));
		set_skill("lingshe_zhangfa", 200+random(150));
		set_skill("xunshou_shu",200+random(150));
		
		map_skill("force", "hamagong");
		map_skill("dodge", "chanchu_bufa");
		map_skill("unarmed", "shexing_diaoshou");
		map_skill("hand", "shexing_diaoshou");
		map_skill("parry", "lingshe_zhangfa");
		map_skill("staff", "lingshe_zhangfa");
		carry_object("zijin_staff")->wield();
		break;
	case 5:
		set_skill("force", 200+random(150));           
		set_skill("huntian_qigong", 200+random(150));    
		set_skill("unarmed", 200+random(150));           
		set_skill("xianglong_zhang", 200+random(150));   
		set_skill("dodge", 200+random(150));      	     
		set_skill("xiaoyaoyou", 200+random(150));      
		set_skill("parry", 200+random(150));           
		set_skill("staff", 200+random(150));            
		set_skill("dagou_bang", 200+random(150));        
		set_skill("begging", 200+random(150));           
		set_skill("xunshou_shu", 200+random(150));
		
		map_skill("force", "huntian_qigong");
		map_skill("unarmed", "xianglong_zhang");
		map_skill("dodge", "xiaoyaoyou");
		map_skill("parry", "xianglong_zhang");
		map_skill("staff", "dagou_bang");
		
		prepare_skill("unarmed", "xianglong_zhang");
		carry_object("zijin_staff")->wield();
		break;
	case 6:
		set_skill("force", 200+random(150));
		set_skill("yunv_xinfa", 200+random(150));	
		set_skill("seaforce", 200+random(150));		
		set_skill("sword", 200+random(150));
		set_skill("yunv_jian", 200+random(150));
		set_skill("smithsword",200+random(150));	
		set_skill("dodge", 200+random(150));
		set_skill("xianyun_bufa", 200+random(150));	
		set_skill("parry", 200+random(150));
		set_skill("unarmed", 200+random(150));
		set_skill("meinv_quan", 200+random(150));    
		set_skill("anranxiaohun_zhang", 200+random(150));
		set_skill("tianluo_diwang", 200+random(150));
		set_skill("literate", 200+random(150));
		
		map_skill("force", "seaforce");
		map_skill("sword", "smithsword");
		map_skill("dodge", "xianyun_bufa");
		map_skill("parry", "anranxiaohun_zhang");
		map_skill("unarmed", "anranxiaohun_zhang");
		carry_object("sword_2")->wield();
		break;
	case 7:
		set_skill("cuff", 200+random(150));
		set_skill("force", 200+random(150));
		set_skill("dodge", 200+random(150));
		set_skill("parry", 200+random(150));
		set_skill("sword", 200+random(150));
		set_skill("strike",200+random(150));
		set_skill("unarmed", 200+random(150));
		set_skill("zixia_shengong", 200+random(150));
		set_skill("poyu_quan", 200+random(150));
		set_skill("huashan_sword", 200+random(150));
		set_skill("hunyuan_zhang", 200+random(150));
		set_skill("lonely_sword", 200+random(150));
		set_skill("huashan_shenfa",200+random(150));
		set_skill("literate", 200+random(150));
		set_skill("zhengqijue", 200+random(150));
		
		map_skill("cuff", "poyu_quan");
		map_skill("force", "zixia_shengong");
		map_skill("dodge", "huashan_shenfa");
		map_skill("parry", "lonely_sword");
		map_skill("sword", "lonely_sword");
		map_skill("strike", "hunyuan_zhang");
		carry_object("sword_2")->wield();
		break;
	case 8:
		set_skill("force", 200+random(150));
		set_skill("unarmed", 200+random(150));
		set_skill("dodge", 200+random(150));
		set_skill("parry", 200+random(150));
		set_skill("hand",200+random(150));
		set_skill("strike", 200+random(150));
		set_skill("sword",200+random(150));
		
		set_skill("zhemei_shou",200+random(150));
		set_skill("liuyang_zhang",200+random(150));
		set_skill("tianyu_qijian",200+random(150));
		set_skill("yueying_wubu",200+random(150));
		set_skill("bahuang_gong", 200+random(150));
		
		map_skill("force", "bahuang_gong");
		map_skill("strike","liuyang_zhang");
		map_skill("dodge", "yueying_wubu");
		map_skill("unarmed", "liuyang_zhang");
		map_skill("strike","liuyang_zhang");
		map_skill("hand", "zhemei_shou");
		map_skill("parry", "liuyang_zhang");
		map_skill("sword","tianyu_qijian");
		
		prepare_skill("strike","liuyang_zhang");
		prepare_skill("hand","zhemei_shou");
		carry_object("sword_2")->wield();
		break;
	case 9:
		set_skill("force", 200+random(150));
		set_skill("dodge", 200+random(150));
		set_skill("parry", 200+random(150));
		set_skill("unarmed", 200+random(150));
		set_skill("jiuyang_shengong", 200+random(150));
		set_skill("lingfa", 200+random(150));
		set_skill("shenghuo_lingfa", 200+random(150));
		set_skill("qiankun_danuoyi", 200+random(150));
		set_skill("shenghuo_xinfa", 200+random(150));
		
		map_skill("parry", "qiankun_danuoyi");
		map_skill("force", "jiuyang_shengong");
		map_skill("dodge", "qiankun_danuoyi");
		map_skill("lingfa", "shenghuo_lingfa");
		break;
	case 10:
		set_skill("force", 200+random(150));
		set_skill("sword", 200+random(150));
		set_skill("dodge", 200+random(150));
		set_skill("parry", 200+random(150));
		set_skill("unarmed",200+random(150));
		set_skill("strike",200+random(150));
		set_skill("finger",200+random(150));
		set_skill("literate",200+random(150));
		set_skill("taoism",200+random(150));
		set_skill("xiantian_qigong", 200+random(150));
		set_skill("xiantian_gong", 200+random(150));
		set_skill("quanzhen_jianfa",200+random(150));  
		set_skill("quanzhen_jian",200+random(150));  
		set_skill("jinyan_gong", 200+random(150));   
		set_skill("haotian_zhang", 200+random(150));   
		set_skill("sun_finger",200+random(150)); 
		
		map_skill("force", "xiantian_qigong");
		map_skill("sword", "quanzhen_jianfa");
		map_skill("dodge", "jinyan_gong");
		map_skill("parry", "quanzhen_jianfa");
		map_skill("strike", "haotian_zhang");
		map_skill("finger","sun_finger");
		
		prepare_skill("finger","sun_finger");
		prepare_skill("strike","haotian_zhang");
		carry_object("sword_2")->wield();
		break;
	case 11:
		set_skill("buddhism", 200+random(150));
		set_skill("literate", 200+random(150));
		set_skill("blade", 200+random(150));
		set_skill("claw", 200+random(150));
		set_skill("club", 200+random(150));
		set_skill("cuff", 200+random(150));
		set_skill("dodge", 200+random(150));
		set_skill("finger", 200+random(150));
		set_skill("force", 200+random(150));
		set_skill("hand", 200+random(150));
		set_skill("parry", 200+random(150));
		set_skill("staff", 200+random(150));
		set_skill("strike", 200+random(150));
		set_skill("sword", 200+random(150));
		set_skill("whip", 200+random(150));
		
		set_skill("banruo_zhang", 200+random(150));
		set_skill("cibei_dao", 200+random(150));
		set_skill("damo_jian", 200+random(150));
		set_skill("fengyun_shou", 200+random(150));
		set_skill("fumo_jian", 200+random(150));
		set_skill("hunyuan_yiqi", 200+random(150));
		set_skill("jingang_quan", 200+random(150));
		set_skill("longzhua_gong", 200+random(150));
		set_skill("luohan_quan", 200+random(150));
		set_skill("nianhua_zhi", 200+random(150));
		set_skill("pudu_zhang", 200+random(150));
		set_skill("qianye_shou", 200+random(150));
		set_skill("sanhua_zhang", 200+random(150));
		set_skill("riyue_bian", 200+random(150));
		set_skill("shaolin_shenfa", 200+random(150));
		set_skill("weituo_gun", 200+random(150));
		set_skill("wuchang_zhang", 200+random(150));
		set_skill("xiuluo_dao", 200+random(150));
		set_skill("yingzhua_gong", 200+random(150));
		set_skill("yijinjing", 200+random(150));
		set_skill("yizhi_chan", 200+random(150));
		set_skill("zui_gun", 200+random(150));
		
		map_skill("blade", "cibei_dao");
		map_skill("claw", "longzhua_gong");
		map_skill("club", "wuchang_zhang");
		map_skill("cuff", "luohan_quan");
		map_skill("dodge", "shaolin_shenfa");
		map_skill("finger", "yizhi_chan");
		map_skill("force", "yijinjing");
		map_skill("hand", "fengyun_shou");
		map_skill("parry", "nianhua_zhi");
		map_skill("staff", "weituo_gun");
		map_skill("strike", "banruo_zhang");
		map_skill("sword", "fumo_jian");
		map_skill("whip", "riyue_bian");
		
		prepare_skill("finger", "yizhi_chan");
		prepare_skill("strike", "banruo_zhang");

		switch(random(4))
		{
		case 0:
			carry_object("sword_2")->wield();
			break;
		case 1:
			carry_object("blade_2")->wield();
			break;
		case 2:
			carry_object("changbian")->wield();
			break;
		case 3:
			carry_object("zijin_staff")->wield();
			break;
		}
		break;
	case 12:
		set_skill("force", 200+random(150));
		set_skill("dodge", 200+random(150));
		set_skill("unarmed", 200+random(150));
		set_skill("strike", 200+random(150));
		set_skill("parry", 200+random(150));
		set_skill("staff", 200+random(150));
		set_skill("sword", 200+random(150));
		set_skill("literate", 200+random(150));
		
		set_skill("shenlong_xinfa", 200+random(150));
		set_skill("yixingbu", 200+random(150));
		set_skill("shenlong_bashi", 200+random(150));
		set_skill("huagu_mianzhang", 200+random(150));
		set_skill("shedao_qigong", 200+random(150));
		
		map_skill("force", "shenlong_xinfa");
		map_skill("dodge", "yixingbu");
		map_skill("unarmed", "shenlong_bashi");
		map_skill("strike", "huagu_mianzhang");
		map_skill("parry", "shedao_qigong");
		map_skill("sword", "shedao_qigong");
		
		prepare_skill("strike", "huagu_mianzhang");
		prepare_skill("unarmed", "shenlong_bashi");

		break;
	case 13:
		set_skill("force", 200+random(150));            
		set_skill("claw", 200+random(150));              
		set_skill("hand", 200+random(150));            
		set_skill("finger", 200+random(150));          
		set_skill("unarmed", 200+random(150));         
		set_skill("strike", 200+random(150));          
		set_skill("leg",200+random(150));	           
		set_skill("dodge", 200+random(150));           
		set_skill("parry", 200+random(150));            
		set_skill("sword", 200+random(150));           
		
		set_skill("anying_fuxiang", 200+random(150));    
		set_skill("tanzhi_shentong", 200+random(150));   
		set_skill("xuanfeng_leg", 200+random(150));      
		set_skill("luoying_shenzhang", 200+random(150));     
		set_skill("bibo_shengong", 200+random(150));     
		set_skill("luoying_shenjian", 200+random(150));  
		set_skill("yuxiao_jianfa", 200+random(150));       
		set_skill("lanhua_shou", 200+random(150));       
		set_skill("qimen_wuxing",200+random(150));       
		set_skill("literate", 200+random(150));           
		
		map_skill("force"  , "bibo_shengong");
		map_skill("finger" , "tanzhi_shentong");
		map_skill("hand"   , "lanhua_shou");
		map_skill("unarmed", "luoying_shenzhang");
		map_skill("strike", "luoying_shenzhang");
		map_skill("leg", "xuanfeng_leg");
		map_skill("dodge"  , "anying_fuxiang");
		map_skill("parry"  , "tanzhi_shentong");
		map_skill("sword"  , "tanzhi_shentong");
		
		prepare_skill("finger", "tanzhi_shentong");
		prepare_skill("hand", "lanhua_shou");

		carry_object("sword_2")->wield();
		break;
	case 14:
		set_skill("force", 200+random(150));
		set_skill("beiming_shengong", 200+random(150));
		set_skill("dodge", 200+random(150));
		set_skill("lingboweibu", 200+random(150));
		set_skill("unarmed", 200+random(150));
		set_skill("liuyang_zhang", 200+random(150));
		set_skill("parry", 200+random(150));
		set_skill("blade", 200+random(150));
		set_skill("xiaoyao_dao", 200+random(150));
		set_skill("zhemei_shou", 200+random(150));
		set_skill("hand", 200+random(150));
		set_skill("literate", 200+random(150));
		
		map_skill("force", "beiming_shengong");
		map_skill("dodge", "lingboweibu");      
		map_skill("hand", "zhemei_shou");
		map_skill("unarmed", "liuyang_zhang");
		map_skill("parry", "xiaoyao_dao");
		map_skill("blade", "xiaoyao_dao");
		
		prepare_skill("hand","zhemei_shou");
		prepare_skill("unarmed","liuyang_zhang");

		carry_object("blade_2")->wield();
		break;
	case 15:
		set_skill("throwing", 200+random(150));
		set_skill("feixing_shu", 200+random(150));        
		set_skill("force", 200+random(150));
		set_skill("huagong_dafa", 200+random(150));
		set_skill("dodge", 200+random(150));
		set_skill("zhaixinggong", 200+random(150));
		set_skill("strike",200+random(150));
		set_skill("xingxiu_duzhang", 200+random(150));
		set_skill("parry", 200+random(150));
		set_skill("staff", 200+random(150));
		set_skill("tianshan_zhang", 200+random(150));
		set_skill("literate", 200+random(150));
		set_skill("sanyin_wugongzhao", 200+random(150));
		set_skill("claw", 200+random(150));
		set_skill("poison", 200+random(150));
		
		map_skill("force", "huagong_dafa");
		map_skill("dodge", "zhaixinggong");
		map_skill("strike", "xingxiu_duzhang");
		map_skill("parry", "feixing_shu");
		map_skill("staff", "tianshan_zhang");
		map_skill("unarmed", "xingxiu_duzhang");
		map_skill("claw", "sanyin_wugongzhao");
		
		prepare_skill("unarmed", "xingxiu_duzhang");
		prepare_skill("claw", "sanyin_wugongzhao");

		carry_object("zijin_staff")->wield();
		break;	
	}
	
};

virtual char * chat_msg()
{
	if(random(2))
	{
		if(search())
		{
			do_die();		//搜索完毕，自动毁灭！
			return 0;
		}
	}
	
	return 0;
}

int search()
{
	char msg[80];
	
	if(! m_pEnvironment->Query(IS_ROOM)) return 0;
	
	CRoom * room = (CRoom *)m_pEnvironment;
	DTEXITLIST * list = room->query_exits();
	
	path_t * node;
	
	node = get_path(room->querystr("base_name"));
	
	int doors = list->GetCount();
	
	if(! querystr("start_point")[0])
		set("start_point", room->querystr("base_name"));
	
	if(node->has_search)
	{
		//判断是否起点
		if(EQUALSTR(room->querystr("base_name"), querystr("start_point")))
		{
			command("chat 0 $HIR哈哈哈，纵横江湖数十载，居然没有遇上过对手！");
			return 1;
		}
		
		//找个退路！
		command(snprintf(msg, 80, "go 0 %s", node->enter_door.c_str()));
		
		return 0;
	}
	
	if(doors)
	{
		
		node->search_id++;
		
		if(node->search_id >= doors)
			node->search_id = 0;
		
		POSITION p = list->FindIndex(node->search_id);
		CDoor * dir = list->GetAt(p); 
		
		if(dir->querystr("id") == node->enter_door)
		{
			node->has_search = 1;
		}
		
		command(snprintf(msg, 80, "go 0 %s", dir->querystr("id")));
		
		room = (CRoom *)environment();
		
		node = get_path(room->querystr("base_name"));
		
		if(! node->enter_door.length())
		{
			node->enter_door = dir->querystr("next_door");
			list = room->query_exits();
			for(int i=0; i<list->GetCount(); i++)
			{
				p = list->FindIndex(i);
				dir = list->GetAt(p);
				if(dir->querystr("id") == node->enter_door)
				{
					node->search_id = i;

					return 0;
				}
			}
		}
		
		return 0;
	}
	
	return 0;
}

path_t * get_path(string room_name)
{
	if(m_search.find(room_name) == m_search.end())
	{
		path_t * node = new path_t;
		
		node->search_id = 0;
		node->has_search = 0;
		node->enter_door = "";
		
		m_search[room_name] = node;
		return node;
	}
	
	return m_search[room_name];
}

void clear_path()
{
	iterator_path p;
	
	for(p = m_search.begin(); p!=m_search.end(); p++)
		delete p->second;
	
	m_search.clear();
}

virtual void do_die()
{
	clear_path();
	CNpc::die();
}

virtual char * chat_msg_combat()
{
	if(query("hp")<10000 && !query("怒"))
	{
		set("mp_factor", 320);
		set("mp",20000);
		add("str",10);
		add("dex",10);
		set("怒",1);
		message_vision("\n\n$HIR$N舌尖一咬，喷出一鲜血，倾尽全力将全身潜力尽数提起，进行最后一搏！\n\n", this);
	}
	return 0;
}

virtual void die()
{
	CContainer * obj = environment();
	CContainer * bot;
	if(query("index")==1)
		g_Channel.do_channel(this, 0, "chat", "$HIR“没想到这个世界上竟然有为窑姐出头的人！”");
	else if(query("index")==2)
		g_Channel.do_channel(this, 0, "chat", "$HIR“哈哈哈，我就算死了，这辈子也值了！”");
	else if(query("index")==3)
		g_Channel.do_channel(this, 0, "chat", "$HIR“你居然杀了我？难道你不想知道哪些孩子的下落了么？”");
	else if(query("index")==4)
		g_Channel.do_channel(this, 0, "chat", "$HIR“不拍马屁就要被开除就要被追杀，这是什么世道啊！我死得好冤！”");
	else 
		g_Channel.do_channel(this, 0, "chat", "$HIR“我可没偷什么手稿，那是灭尽老尼的陷害之计，她……怕她门派里那些不干不净的事……曝光……”");


	for(int j=0;j<random(4)+1;j++)
	{
		int money=random(20000)+random(20000)+random(20000)+20000;
		bot = load_item("coin");
		bot->set_amount(money);
		bot->move(obj);
	}

	DTItemList * list = obj->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	CChar * me;
	char msg[255];
	while(p) 
	{ 
		CContainer * env = list->GetNext(p);
		if(! env->is_character()) continue; 
		me = (CChar *)env;  
		if(!userp(me))	continue;
		if(me->query_temp("fight/is_fighting")  && is_fighting(me)!=is_fighting(this) )
		{
			int repute=random(10000)+10000;
			if(query("index")==1 || query("index")==3|| query("index")==4)
				repute=-repute;
			me->add("repute",repute);
			int exp=50*me->query("level")+random(50*me->query("level"));
			me->add("combat_exp", exp);
			me->add("威望", 1);
			tell_object(me, snprintf(msg, 255, "$HIY你获得了$HIR%ld$HIY点的实战经验、提高了$HIR%ld$HIY点的声望、提高了1点江湖威望。", exp,repute));

		}
	}

	CContainer * obj1 = load_room("pk");
	if(obj1->query("yw/thing"))	obj1->del("yw/thing");

	CNpc::die();
}

NPC_END;