//monster_searcher2.h
//NPC 棕横天下

NPC_BEGIN(CNmonster_searcher2);

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
	set_name( "棕横天下", "zongheng tianxia");
	
	set("max_hp", 30000000+random(10000000));
	set("hp",query("max_hp"));
	set("max_mp", 20000);
	set("mp",20000);
	set("mp_factor", 160);
	set("combat_exp", 35000000+random(10000000));
	set("no_duo",1);
			
	set("chat_chance", 30);
	set("chat_chance_combat", 20);

	set("no_kill",1);
	set("no_缠字决",1);
	set_temp("apply/no_连字诀",1);
	set_temp("apply/no_千环套狗",1);
	set_temp("apply/no_相思无用",1);
	set_temp("apply/no_势合形离",1);
	set_temp("apply/no_点字决",1);
	set_temp("apply/no_天外飞龙",1);
	set_temp("apply/no_拼命",1);
	set_temp("apply/no_祭血神刀",1);
	
	set("bigboss",1);
	set("kkk",1);

	set("apply/armor", 380);
    set("apply/damage", 200);
	
};

//他一生所要做的事情就是不停的走路！
virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		switch(random(10))
		{
		case 1:
			command("chat 0 $HIR真是凄凄惨惨，今年还是无处藏身！");
			break;
		case 3:
			command("chat 0 $HIR哈哈哈，你们是找不着我的！");
			break;
		case 5:
			command("chat 0 $HIR唉，今年也真的不好意思，偷来的宝贝也太太太多了！");
			break;
		case 7:
			command("chat 0 $HIR今天见识到了不少所谓的高手，看来他们的功夫也真的是一般般嘛！");
			break;
		}
		break;
	case 1:
        if(search())
		{
			do_die();		//搜索完毕，自动毁灭！
			return 0;
		}
		break;
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
		
		//command("chat 0 已经搜索过了！");
		//找个退路！
		command(snprintf(msg, 80, "go 0 %s", node->enter_door.c_str()));
		
		switch(random(10))
		{
		case 1:
			command("chat 0 $HIR真是凄凄惨惨，今年还是无处藏身！");
			break;
		case 3:
			command("chat 0 $HIR哈哈哈，你们是找不着我的！");
			break;
		case 5:
			command("chat 0 $HIR唉，今年也真的不好意思，偷来的宝贝也太太太多了！");
			break;
		case 7:
			command("chat 0 $HIR今天见识到了不少所谓的高手，看来他们的功夫也真的是一般般嘛！");
			break;
		}
		
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
			//command(snprintf(msg, 80, "chat 0 我在%s找不到正确的门%s！", room->querystr("base_name"), node->enter_door.c_str()));
		}
		
		return 0;
	}
	
	//command("chat 0 我进入失败的房间了！");
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
	set("mp",20000);
	set("gender", "男性");
	set("age", 30+random(80));
	
	CContainer * weapon = query_weapon();
	if(weapon)
	{
		destruct(weapon);
	}
	
	switch(random(17))
	{
	case 1:
		set_skill("force", 200+random(200));
		set_skill("taiji_shengong", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("tiyunzong", 200+random(200));
		set_skill("unarmed", 200+random(200));
		set_skill("taiji_quan", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("sword", 200+random(200));
		set_skill("taiji_jian", 200+random(200));
		set_skill("blade", 200+random(200));
		set_skill("taiji_dao", 200+random(200));
		set_skill("taoism", 200+random(200));
		set_skill("literate", 200+random(200));
		
		map_skill("force", "taiji_shengong");
		map_skill("dodge", "tiyunzong");
		map_skill("unarmed", "taiji_quan");
		map_skill("parry", "taiji_jian");
		map_skill("sword", "taiji_jian");
		map_skill("blade", "taiji_dao");
		message_vision("\n\n$HIR$N微一凝神，运起太极神功，全身灌满真气，衣裳无风自舞，气势迫人。\n\n", this);
		break;
	case 2:
		set_skill("force", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("cuff", 200+random(200));
		set_skill("strike", 200+random(200));
		set_skill("sword", 200+random(200));
		set_skill("staff", 200+random(200));
		set_skill("finger", 200+random(200));
		set_skill("kurong_changong", 200+random(200));
		set_skill("tiannan_step", 200+random(200));
		set_skill("jinyu_quan", 200+random(200));
		set_skill("wuluo_zhang", 200+random(200));
		set_skill("duanjia_sword", 200+random(200));
		set_skill("sun_finger", 200+random(200));
		set_skill("lm_shangyang", 200+random(200));	
		set_skill("literate", 200+random(200));
		
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
		message_vision( "\n\n$HIR$N暗自凝神，运起枯荣禅功，真气游遍全身。\n\n" ,this);
		break;
	case 3:
		set_skill("persuading", 200+random(200));
		set_skill("throwing", 200+random(200));
		set_skill("force", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("finger", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("strike", 200+random(200));
		set_skill("sword", 200+random(200));
		set_skill("blade", 200+random(200));
		set_skill("literate", 200+random(200));
		set_skill("mahayana", 200+random(200));
		set_skill("buddhism", 200+random(200));
		set_skill("jinding_zhang", 200+random(200));
		set_skill("tiangang_zhi", 200+random(200));
		set_skill("huifeng_jian", 200+random(200));
		set_skill("yanxing_dao", 200+random(200));
		set_skill("zhutian_bu", 200+random(200));
		set_skill("linji_zhuang", 200+random(200));
		
		map_skill("force","linji_zhuang");
		map_skill("finger","tiangang_zhi");
		map_skill("dodge","zhutian_bu");
		map_skill("strike","jinding_zhang");
		map_skill("sword","huifeng_jian");
		map_skill("blade","yanxing_dao");
		map_skill("parry","huifeng_jian");
		if(random(2))
			carry_object("sword_2")->wield();
		else
			carry_object("blade_2")->wield();
		set("gender", "女性");
		message_vision("\n\n$HIR$N微一凝神，运起临济庄，一声娇喝！\n\n" , this);
		break;
	case 4:
		set_skill("persuading", 200+random(200));
		set_skill("force", 200+random(200));
		set_skill("unarmed", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("hand",200+random(200));
		set_skill("staff", 200+random(200));
		set_skill("hamagong", 200+random(200));
		set_skill("chanchu_bufa", 200+random(200));
		set_skill("shexing_diaoshou", 200+random(200));
		set_skill("lingshe_zhangfa", 200+random(200));
		set_skill("xunshou_shu",200+random(200));
		
		map_skill("force", "hamagong");
		map_skill("dodge", "chanchu_bufa");
		map_skill("unarmed", "shexing_diaoshou");
		map_skill("hand", "shexing_diaoshou");
		map_skill("parry", "lingshe_zhangfa");
		map_skill("staff", "lingshe_zhangfa");
		carry_object("zijin_staff")->wield();
		message_vision("\n\n$HIR$N忽地双手撑地倒立，逆运经脉，顿时内息暗生，防御力大增。\n\n", this);
		break;
	case 5:
		set_skill("force", 200+random(200));           
		set_skill("huntian_qigong", 200+random(200));    
		set_skill("unarmed", 200+random(200));           
		set_skill("xianglong_zhang", 200+random(200));   
		set_skill("dodge", 200+random(200));      	     
		set_skill("xiaoyaoyou", 200+random(200));      
		set_skill("parry", 200+random(200));           
		set_skill("staff", 200+random(200));            
		set_skill("dagou_bang", 200+random(200));        
		set_skill("begging", 200+random(200));           
		set_skill("xunshou_shu", 200+random(200));
		
		map_skill("force", "huntian_qigong");
		map_skill("unarmed", "xianglong_zhang");
		map_skill("dodge", "xiaoyaoyou");
		map_skill("parry", "xianglong_zhang");
		map_skill("staff", "dagou_bang");
		
		prepare_skill("unarmed", "xianglong_zhang");
		carry_object("zijin_staff")->wield();
		message_vision("\n\n$N微一凝神，运起混天气功，全身骨节发出一阵爆豆般的声响。\n\n" , this);	
		break;
	case 6:
		set_skill("force", 200+random(200));
		set_skill("yunv_xinfa", 200+random(200));	
		set_skill("seaforce", 200+random(200));		
		set_skill("sword", 200+random(200));
		set_skill("yunv_jian", 200+random(200));
		set_skill("smithsword",200+random(200));	
		set_skill("dodge", 200+random(200));
		set_skill("xianyun_bufa", 200+random(200));	
		set_skill("parry", 200+random(200));
		set_skill("unarmed", 200+random(200));
		set_skill("meinv_quan", 200+random(200));    
		set_skill("anranxiaohun_zhang", 200+random(200));
		set_skill("tianluo_diwang", 200+random(200));
		set_skill("literate", 200+random(200));
		
		map_skill("force", "seaforce");
		map_skill("sword", "smithsword");
		map_skill("dodge", "xianyun_bufa");
		map_skill("parry", "anranxiaohun_zhang");
		map_skill("unarmed", "anranxiaohun_zhang");
		carry_object("sword_2")->wield();
		message_vision( "\n\n$HIR$N运起狂潮心法，身形微展．行云流水般的滑出，化作一片人影，处处留情！\n\n" ,this );
		break;
	case 7:
		set_skill("cuff", 200+random(200));
		set_skill("force", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("sword", 200+random(200));
		set_skill("strike",200+random(200));
		set_skill("unarmed", 200+random(200));
		set_skill("zixia_shengong", 200+random(200));
		set_skill("poyu_quan", 200+random(200));
		set_skill("huashan_sword", 200+random(200));
		set_skill("hunyuan_zhang", 200+random(200));
		set_skill("lonely_sword", 200+random(200));
		set_skill("huashan_shenfa",200+random(200));
		set_skill("literate", 200+random(200));
		set_skill("zhengqijue", 200+random(200));
		
		map_skill("cuff", "poyu_quan");
		map_skill("force", "zixia_shengong");
		map_skill("dodge", "huashan_shenfa");
		map_skill("parry", "lonely_sword");
		map_skill("sword", "lonely_sword");
		map_skill("strike", "hunyuan_zhang");
		message_vision("\n\n$HIR$N微一凝神，运起紫霞神功，背转身去，脸上突然紫气大盛！只是那紫气一现即隐，转过身来，脸上又回复如常。\n\n" , this);
		carry_object("sword_2")->wield();
		break;
	case 8:
		set_skill("force", 200+random(200));
		set_skill("unarmed", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("hand",200+random(200));
		set_skill("strike", 200+random(200));
		set_skill("sword",200+random(200));
		
		set_skill("zhemei_shou",200+random(200));
		set_skill("liuyang_zhang",200+random(200));
		set_skill("tianyu_qijian",200+random(200));
		set_skill("yueying_wubu",200+random(200));
		set_skill("bahuang_gong", 200+random(200));
		
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
		message_vision("\n\n$HIR$N凝神息气，运起八荒六合唯我独尊功，只见一股轻烟缭绕周身。\n\n", this);
		break;
	case 9:
		set_skill("force", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("unarmed", 200+random(200));
		set_skill("jiuyang_shengong", 200+random(200));
		set_skill("lingfa", 200+random(200));
		set_skill("shenghuo_lingfa", 200+random(200));
		set_skill("qiankun_danuoyi", 200+random(200));
		set_skill("shenghuo_xinfa", 200+random(200));
		
		map_skill("parry", "qiankun_danuoyi");
		map_skill("force", "jiuyang_shengong");
		map_skill("dodge", "qiankun_danuoyi");
		map_skill("lingfa", "shenghuo_lingfa");
		message_vision(	"\n\n$HIR$N微一凝神，运起九阳神功，全身骨节发出一阵爆豆般的声响, 将全身潜能尽数提起。\n\n "  , this);
		break;
	case 10:
		set_skill("force", 200+random(200));
		set_skill("sword", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("unarmed",200+random(200));
		set_skill("strike",200+random(200));
		set_skill("finger",200+random(200));
		set_skill("literate",200+random(200));
		set_skill("taoism",200+random(200));
		set_skill("xiantian_qigong", 200+random(200));
		set_skill("xiantian_gong", 200+random(200));
		set_skill("quanzhen_jianfa",200+random(200));  
		set_skill("quanzhen_jian",200+random(200));  
		set_skill("jinyan_gong", 200+random(200));   
		set_skill("haotian_zhang", 200+random(200));   
		set_skill("sun_finger",200+random(200)); 
		
		map_skill("force", "xiantian_qigong");
		map_skill("sword", "quanzhen_jianfa");
		map_skill("dodge", "jinyan_gong");
		map_skill("parry", "quanzhen_jianfa");
		map_skill("strike", "haotian_zhang");
		map_skill("finger","sun_finger");
		
		prepare_skill("finger","sun_finger");
		prepare_skill("strike","haotian_zhang");
		carry_object("sword_2")->wield();
		message_vision("\n\n$HIR$N微一凝神，运起先天气功，足底尘土泛起，全身真气冲关欲出。\n\n"  ,this);
		break;
	case 11:
		set_skill("buddhism", 200+random(200));
		set_skill("literate", 200+random(200));
		set_skill("blade", 200+random(200));
		set_skill("claw", 200+random(200));
		set_skill("club", 200+random(200));
		set_skill("cuff", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("finger", 200+random(200));
		set_skill("force", 200+random(200));
		set_skill("hand", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("staff", 200+random(200));
		set_skill("strike", 200+random(200));
		set_skill("sword", 200+random(200));
		set_skill("whip", 200+random(200));
		
		set_skill("banruo_zhang", 200+random(200));
		set_skill("cibei_dao", 200+random(200));
		set_skill("damo_jian", 200+random(200));
		set_skill("fengyun_shou", 200+random(200));
		set_skill("fumo_jian", 200+random(200));
		set_skill("hunyuan_yiqi", 200+random(200));
		set_skill("jingang_quan", 200+random(200));
		set_skill("longzhua_gong", 200+random(200));
		set_skill("luohan_quan", 200+random(200));
		set_skill("nianhua_zhi", 200+random(200));
		set_skill("pudu_zhang", 200+random(200));
		set_skill("qianye_shou", 200+random(200));
		set_skill("sanhua_zhang", 200+random(200));
		set_skill("riyue_bian", 200+random(200));
		set_skill("shaolin_shenfa", 200+random(200));
		set_skill("weituo_gun", 200+random(200));
		set_skill("wuchang_zhang", 200+random(200));
		set_skill("xiuluo_dao", 200+random(200));
		set_skill("yingzhua_gong", 200+random(200));
		set_skill("yijinjing", 200+random(200));
		set_skill("yizhi_chan", 200+random(200));
		set_skill("zui_gun", 200+random(200));
		
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
		message_vision("\n\n$HIR$N舌尖一咬，喷出一口鲜血，运起易筋经神功已将全身潜力尽数提起！\n\n", this);

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
		set_skill("force", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("unarmed", 200+random(200));
		set_skill("strike", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("staff", 200+random(200));
		set_skill("sword", 200+random(200));
		set_skill("literate", 200+random(200));
		
		set_skill("shenlong_xinfa", 200+random(200));
		set_skill("yixingbu", 200+random(200));
		set_skill("shenlong_bashi", 200+random(200));
		set_skill("huagu_mianzhang", 200+random(200));
		set_skill("shedao_qigong", 200+random(200));
		
		map_skill("force", "shenlong_xinfa");
		map_skill("dodge", "yixingbu");
		map_skill("unarmed", "shenlong_bashi");
		map_skill("strike", "huagu_mianzhang");
		map_skill("parry", "shedao_qigong");
		map_skill("sword", "shedao_qigong");
		
		prepare_skill("strike", "huagu_mianzhang");
		prepare_skill("unarmed", "shenlong_bashi");
		message_vision( "\n\n$HIR$N深深地吸一囗气，忽然仰天长啸，高声狂叫：我真他妈的是个天才！！！\n\n"  , this);

		break;
	case 13:
		set_skill("force", 200+random(200));            
		set_skill("claw", 200+random(200));              
		set_skill("hand", 200+random(200));            
		set_skill("finger", 200+random(200));          
		set_skill("unarmed", 200+random(200));         
		set_skill("strike", 200+random(200));          
		set_skill("leg",200+random(200));	           
		set_skill("dodge", 200+random(200));           
		set_skill("parry", 200+random(200));            
		set_skill("sword", 200+random(200));           
		
		set_skill("anying_fuxiang", 200+random(200));    
		set_skill("tanzhi_shentong", 200+random(200));   
		set_skill("xuanfeng_leg", 200+random(200));      
		set_skill("luoying_shenzhang", 200+random(200));     
		set_skill("bibo_shengong", 200+random(200));     
		set_skill("luoying_shenjian", 200+random(200));  
		set_skill("yuxiao_jianfa", 200+random(200));       
		set_skill("lanhua_shou", 200+random(200));       
		set_skill("qimen_wuxing",200+random(200));       
		set_skill("literate", 200+random(200));           
		
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
		message_vision("\n\n$HIR$N舌尖一咬，喷出一口鲜血，运起碧波神功已将全身潜力尽数提起！\n\n"  , this);

		carry_object("sword_2")->wield();
		break;
	case 14:
		set_skill("force", 200+random(200));
		set_skill("beiming_shengong", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("lingboweibu", 200+random(200));
		set_skill("unarmed", 200+random(200));
		set_skill("liuyang_zhang", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("blade", 200+random(200));
		set_skill("xiaoyao_dao", 200+random(200));
		set_skill("zhemei_shou", 200+random(200));
		set_skill("hand", 200+random(200));
		set_skill("literate", 200+random(200));
		
		map_skill("force", "beiming_shengong");
		map_skill("dodge", "lingboweibu");      
		map_skill("hand", "zhemei_shou");
		map_skill("unarmed", "liuyang_zhang");
		map_skill("parry", "xiaoyao_dao");
		map_skill("blade", "xiaoyao_dao");
		
		prepare_skill("hand","zhemei_shou");
		prepare_skill("unarmed","liuyang_zhang");
		message_vision("\n\n$HIR$N双手平举过顶，运起北冥神功，全身笼罩在劲气之中！\n\n", this);

		carry_object("blade_2")->wield();
		break;
	case 15:
		set_skill("throwing", 200+random(200));
		set_skill("feixing_shu", 200+random(200));        
		set_skill("force", 200+random(200));
		set_skill("huagong_dafa", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("zhaixinggong", 200+random(200));
		set_skill("strike",200+random(200));
		set_skill("xingxiu_duzhang", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("staff", 200+random(200));
		set_skill("tianshan_zhang", 200+random(200));
		set_skill("literate", 200+random(200));
		set_skill("sanyin_wugongzhao", 200+random(200));
		set_skill("claw", 200+random(200));
		set_skill("poison", 200+random(200));
		
		map_skill("force", "huagong_dafa");
		map_skill("dodge", "zhaixinggong");
		map_skill("strike", "xingxiu_duzhang");
		map_skill("parry", "feixing_shu");
		map_skill("staff", "tianshan_zhang");
		map_skill("unarmed", "xingxiu_duzhang");
		map_skill("claw", "sanyin_wugongzhao");
		
		prepare_skill("unarmed", "xingxiu_duzhang");
		prepare_skill("claw", "sanyin_wugongzhao");
		message_vision("\n\n$HIR$N舌尖一咬，喷出一口毒血，运起化功大法已将全身潜力尽数提起！\n\n", this);

		carry_object("zijin_staff")->wield();
		break;	
	case 16:
		set_skill("force", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("claw",200+random(200));
		
		set_skill("wuwen_zhua",200+random(200));
		set_skill("guimei_shenfa",200+random(200));
		set_skill("wudu_shengong", 200+random(200));
		set_skill("tangshoudao", 200+random(200));
		
		map_skill("force", "wudu_shengong");
		map_skill("dodge", "guimei_shenfa");
		map_skill("parry", "tangshoudao");
		map_skill("claw", "wuwen_zhua");
		prepare_skill("claw", "wuwen_zhua");

		if(random(2))
			message_vision("\n\n$HIR$N双手合十，面露虔诚之色。只见一片雪花飘过……\n\n", this);
		else
			message_vision("\n\n$HIR$N将手一划，一道乌烟自地下升起……\n\n", this);
		break;
	}
	return 0;
}

virtual void die()
{
	CContainer * obj = environment();
	CContainer * bot;
	char msg[255];
	set("grant", 99);
	set_name( "快乐使者", "kuaile shizhe");
	g_Channel.do_channel(this, NULL, "news",  "$HIR在大家的合力围攻下，终于抢回了我们的节日礼物！");
	g_Channel.do_channel(this, NULL, "news",  "$HIR快乐将与大家同在！");
	g_Channel.do_channel(this, NULL, "news",  "$HIR《重出江湖》所有工作人员祝大家节日快乐！");
	set_name( "棕横天下", "zongheng tianxia");
	g_player();

	static char baowu[37][20]={"taibaizao","38huoqiang","diaojiandai","jinhuantoushi","btzheng",
		"xuantiebishou","bolanxie","haoseshan","xiantianyu","poliquan","fannaomao","shajiezhi","tiancanbaojia",
		"newyear","newyear1","zidiaopifeng","liaochengpao","dagoubang","yinguozhu","dulonglian","shenshe_staff",
		"ruanweijia","zhangmenhuan","yinmopao","conglinjian",
		"kuihuaao","jinlianxie","fengyizhen","xuanwupao","yunshenglv","zijianhun","qinjianhun","luoshenjin","linboxie",
		"zueiyupao","hanyuzhi","lantiandai"};

	for(int i=0;i<random(5)+3;i++)
	{
		if(random(5)>2)
			bot = load_item(baowu[random(37)]);
		bot = load_item("dazongzi");
		if(random(100)>85)
			bot->set("宝贝",1);
		bot->move(obj);
	}
	for(int i=0;i<random(5)+325;i++)
	{
		int index=random(MAX_ROOM_NUM);
		//bot = load_item(baowu[random(37)]);
		bot = load_item("dazongzi");
		if(random(100)>85)
			bot->set("宝贝",1);
		obj = load_room(global_room_name[index]);
		g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s移动到了%s。",bot->name(1),obj->querystr("base_name")));
		bot->move(obj);
	}
	CNpc::die();
}

int g_player()
{
	MAP2USER * user;
	iterator_user p;
	CUser * obj;
	CContainer * bot;

	user = users();
    for ( p=user->begin(); p!=user->end(); p++)
    {
		obj = p->second;
	
		if(obj->query("level")>10 && obj->query("age")>16 && obj->query("combat_exp")>5000)
		{
			char msg[255];
			
			snprintf(msg, 255, "$HIR\n天上飘扬着落下一个红包，不偏不倚落在你的怀中……\n你打开一看，原来是一个香喷喷的肉粽子，包它的粽子叶泛出一股清香。\n\n");
			
			tell_object(obj,msg);
			bot = load_item("dazongzi");
			if(random(100)>50)
				bot->set("宝贝",1);
			bot->move(obj);
			//load_item("dazongzi")->move(obj);
		}
    }
    
	return 1;
}

NPC_END;